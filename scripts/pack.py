#! /usr/bin/env python3
"""
Create XCFrameworks from built static libraries for all Apple platforms.

Usage:
  python3 scripts/pack.py                  # pack all available builds
  python3 scripts/pack.py --platforms macos # pack only macOS

Expected build artifacts layout (under skia/out/):
  Release-macos-arm64/libskia.a
  Release-macos-x64/libskia.a
  Release-ios-arm64/libskia.a
  Release-iosSim-arm64/libskia.a
  Release-iosSim-x64/libskia.a
  Release-tvos-arm64/libskia.a
  Release-tvosSim-arm64/libskia.a
"""

import argparse, hashlib, json, os, shutil, subprocess, sys

REPO_ROOT = os.path.join(os.path.dirname(__file__), os.pardir)
SKIA_OUT = os.path.join(REPO_ROOT, 'skia', 'out')
BUILD_DIR = os.path.join(REPO_ROOT, 'build')

LIBRARIES = ['skia', 'skparagraph', 'skshaper', 'skunicode']

# Each platform maps to (device_targets, simulator_targets) where each target is (target_name, machine)
APPLE_PLATFORMS = {
  'macos': {
    'slices': [('macos', 'arm64'), ('macos', 'x64')],
    'simulator': False,
  },
  'ios': {
    'device': [('ios', 'arm64')],
    'simulator': [('iosSim', 'arm64'), ('iosSim', 'x64')],
  },
  'tvos': {
    'device': [('tvos', 'arm64')],
    'simulator': [('tvosSim', 'arm64')],
  },
}

def lib_path(target, machine, lib_name, build_type='Release'):
  return os.path.join(SKIA_OUT, f'{build_type}-{target}-{machine}', f'lib{lib_name}.a')

def lipo_merge(inputs, output):
  os.makedirs(os.path.dirname(output), exist_ok=True)
  if len(inputs) == 1:
    shutil.copy2(inputs[0], output)
  else:
    subprocess.check_call(['lipo'] + inputs + ['-output', output, '-create'])

def create_xcframework(lib_name, platform, build_type='Release'):
  """Create an XCFramework for a single library on a single platform."""
  config = APPLE_PLATFORMS[platform]
  xcf_args = ['xcodebuild', '-create-xcframework']

  if 'slices' in config:
    # Non-simulator platform (macOS) — merge all slices into one universal
    inputs = [lib_path(t, m, lib_name, build_type) for t, m in config['slices']]
    available = [p for p in inputs if os.path.exists(p)]
    if not available:
      return None
    merged = os.path.join(BUILD_DIR, platform, f'lib{lib_name}.a')
    lipo_merge(available, merged)
    xcf_args += ['-library', merged]
  else:
    # Device + simulator platform (iOS, tvOS)
    device_inputs = [lib_path(t, m, lib_name, build_type) for t, m in config['device']]
    sim_inputs = [lib_path(t, m, lib_name, build_type) for t, m in config['simulator']]

    device_available = [p for p in device_inputs if os.path.exists(p)]
    sim_available = [p for p in sim_inputs if os.path.exists(p)]

    if not device_available and not sim_available:
      return None

    if device_available:
      device_merged = os.path.join(BUILD_DIR, f'{platform}-device', f'lib{lib_name}.a')
      lipo_merge(device_available, device_merged)
      xcf_args += ['-library', device_merged]

    if sim_available:
      sim_merged = os.path.join(BUILD_DIR, f'{platform}-sim', f'lib{lib_name}.a')
      lipo_merge(sim_available, sim_merged)
      xcf_args += ['-library', sim_merged]

  output = os.path.join(BUILD_DIR, f'{lib_name}-{platform}.xcframework')
  if os.path.exists(output):
    shutil.rmtree(output)
  xcf_args += ['-output', output]

  subprocess.check_call(xcf_args)
  return output

def zip_xcframework(xcf_path):
  """Zip an XCFramework and return (zip_path, sha256)."""
  base = os.path.basename(xcf_path)  # e.g., skia-macos.xcframework
  name = base.replace('.xcframework', '')
  zip_path = os.path.join(BUILD_DIR, f'{name}.xcframework.zip')

  # Use ditto for macOS-compatible zip (preserves symlinks, extended attrs)
  subprocess.check_call(['ditto', '-c', '-k', '--sequesterRsrc', '--keepParent', xcf_path, zip_path])

  sha = hashlib.sha256()
  with open(zip_path, 'rb') as f:
    for chunk in iter(lambda: f.read(8192), b''):
      sha.update(chunk)

  return zip_path, sha.hexdigest()

def main():
  parser = argparse.ArgumentParser(description='Create XCFrameworks from built Skia libraries')
  parser.add_argument('--platforms', nargs='+', choices=list(APPLE_PLATFORMS.keys()),
                      default=list(APPLE_PLATFORMS.keys()),
                      help='Platforms to pack (default: all)')
  parser.add_argument('--build-type', default='Release')
  args = parser.parse_args()

  if os.path.exists(BUILD_DIR):
    shutil.rmtree(BUILD_DIR)
  os.makedirs(BUILD_DIR)

  manifest = {}

  for platform in args.platforms:
    for lib_name in LIBRARIES:
      print(f'> Packing {lib_name} for {platform}...')
      xcf = create_xcframework(lib_name, platform, args.build_type)
      if xcf is None:
        print(f'  Skipped (no built artifacts found)')
        continue

      zip_path, checksum = zip_xcframework(xcf)
      key = f'{lib_name}-{platform}'
      manifest[key] = {
        'zip': os.path.basename(zip_path),
        'checksum': checksum,
      }
      print(f'  {os.path.basename(zip_path)} ({checksum[:12]}...)')

  # Write manifest
  manifest_path = os.path.join(BUILD_DIR, 'manifest.json')
  with open(manifest_path, 'w') as f:
    json.dump(manifest, f, indent=2)
  print(f'\n> Manifest written to {manifest_path}')

  return 0

if __name__ == '__main__':
  sys.exit(main())
