#! /usr/bin/env python3

import common, os, re, subprocess, sys, shutil
from pathlib import Path

def patch_sources():
  """Apply patches to Skia source for SDK compatibility."""
  skia_dir = Path(common.REPO_ROOT) / 'skia'

  # Fix zlib fdopen macro conflict with modern macOS SDKs
  zutil = skia_dir / 'third_party' / 'externals' / 'zlib' / 'zutil.h'
  if zutil.exists():
    text = zutil.read_text()
    # Remove the problematic fdopen→NULL macro block for macOS
    patched = re.sub(
      r'#if defined\(MACOS\) \|\| defined\(TARGET_OS_MAC\)\n'
      r'#  define OS_CODE  7\n'
      r'#  ifndef Z_SOLO\n'
      r'.*?#  endif\n'
      r'#endif',
      '#if defined(MACOS) || defined(TARGET_OS_MAC)\n'
      '#  define OS_CODE  7\n'
      '#endif',
      text, flags=re.DOTALL
    )
    if patched != text:
      zutil.write_text(patched)
      print('> Patched zlib zutil.h (fdopen macro fix)')

def embed_api():
  """Copy C API headers and sources into the Skia source tree and register them in the GN build."""
  api_dir = Path(common.REPO_ROOT) / 'api'
  skia_dir = Path(common.REPO_ROOT) / 'skia'
  include_src = api_dir / 'include'
  include_dst = skia_dir / 'include'
  src_src = api_dir / 'src'
  src_dst = skia_dir / 'src'

  # Copy header and source files
  shutil.copytree(include_src, include_dst, dirs_exist_ok=True)
  shutil.copytree(src_src, src_dst, dirs_exist_ok=True)

  src_files = [f.name for f in src_src.glob('*')]

  # Remove any stale entries from core.gni (from previous builds)
  core_gni = skia_dir / 'gn' / 'core.gni'
  with core_gni.open() as f:
    core_lines = f.readlines()
  cleaned = [l for l in core_lines if not any(f in l for f in src_files)]
  if len(cleaned) != len(core_lines):
    with core_gni.open('w') as f:
      f.writelines(cleaned)
    print('> Removed stale C API entries from gn/core.gni')

  # Register in gpu.gni (skia_ganesh_private) so files get SK_GANESH + SK_METAL defines
  gpu_gni = skia_dir / 'gn' / 'gpu.gni'
  with gpu_gni.open() as f:
    lines = f.readlines()

  start_index = next(
    (i for i, line in enumerate(lines) if line.strip().startswith('skia_ganesh_private = [')),
    None
  )
  if start_index is None:
    raise ValueError("Could not find 'skia_ganesh_private = [' in gn/gpu.gni")

  # Check if already embedded
  for line in lines[start_index + 1:]:
    if any(f in line for f in src_files):
      print('> C API sources already embedded in gn/gpu.gni')
      return

  for f in src_files:
    lines.insert(start_index + 1, f'  "$_src/{f}",\n')

  with gpu_gni.open('w') as f:
    f.writelines(lines)

  print('> Embedded C API into Skia source tree (gpu.gni)')

def main():
  os.chdir(os.path.join(common.REPO_ROOT, 'skia'))

  build_type = common.build_type()
  machine = common.machine()
  host = common.host()
  host_machine = common.host_machine()
  target = common.target()
  ndk = common.ndk()

  tools_dir = 'depot_tools'
  ninja = 'ninja.bat' if 'windows' == host else 'ninja'
  isIos = target in ('ios', 'iosSim')
  isTvos = target in ('tvos', 'tvosSim')
  isIosSim = target == 'iosSim'
  isTvosSim = target == 'tvosSim'

  if build_type == 'Debug':
    args = ['is_debug=true']
  else:
    args = ['is_official_build=true']

  args += [
    'target_cpu="' + machine + '"',
    'skia_use_system_expat=false',
    'skia_use_system_libjpeg_turbo=false',
    'skia_use_system_libpng=false',
    'skia_use_system_libwebp=false',
    'skia_use_system_zlib=false',

    # Text layout
    'skia_enable_skparagraph=true',
    'skia_enable_skshaper=true',
    'skia_use_icu=true',
    'skia_use_system_icu=false',
    'skia_use_harfbuzz=true',
    'skia_pdf_subset_harfbuzz=true',
    'skia_use_system_harfbuzz=false',
  ]

  if 'macos' == target or isIos or isTvos:
    args += [
      'extra_cflags_cc=["-frtti"]',
      'skia_use_metal=true',
    ]
    if isIos:
      args += ['target_os="ios"']
      if isIosSim:
        args += ['ios_use_simulator=true']
      else:
        args += ['ios_min_target="12.0"']
    elif isTvos:
      args += ['target_os="tvos"']
      if isTvosSim:
        args += ['ios_use_simulator=true']
        args += ['extra_cflags=["-mtvos-simulator-version-min=14", "-DSK_BUILD_FOR_TVOS"]']
      else:
        args += ['extra_cflags=["-mtvos-version-min=14", "-DSK_BUILD_FOR_TVOS"]']
    else:
      if 'arm64' == machine:
        args += ['extra_cflags=["-stdlib=libc++"]']
      else:
        args += ['extra_cflags=["-stdlib=libc++", "-mmacosx-version-min=10.13"]']
  elif 'linux' == target:
    if 'arm64' == machine:
      args += [
        'skia_gl_standard="gles"',
        'extra_cflags_cc=["-fno-exceptions", "-fno-rtti", "-flax-vector-conversions=all", "-D_GLIBCXX_USE_CXX11_ABI=0"]',
        'cc="clang"',
        'cxx="clang++"',
      ]
    else:
      args += [
        'extra_cflags_cc=["-fno-exceptions", "-fno-rtti", "-D_GLIBCXX_USE_CXX11_ABI=0"]',
        'cc="gcc-9"',
        'cxx="g++-9"',
      ]
  elif 'windows' == target:
    args += [
      'skia_use_direct3d=true',
      'extra_cflags=["-DSK_FONT_HOST_USE_SYSTEM_SETTINGS"]',
    ]
  elif 'android' == target:
    args += [
      'ndk="' + ndk + '"',
    ]
  elif 'wasm' == target:
    args += [
      'skia_use_dng_sdk=false',
      'skia_use_libjpeg_turbo_decode=true',
      'skia_use_libjpeg_turbo_encode=true',
      'skia_use_libpng_decode=true',
      'skia_use_libpng_encode=true',
      'skia_use_libwebp_decode=true',
      'skia_use_libwebp_encode=true',
      'skia_use_wuffs=true',
      'skia_use_lua=false',
      'skia_use_webgl=true',
      'skia_use_piex=false',
      'skia_enable_tools=false',
      'skia_enable_fontmgr_custom_directory=false',
      'skia_enable_fontmgr_custom_embedded=true',
      'skia_enable_fontmgr_custom_empty=false',
      'skia_gl_standard="webgl"',
      'skia_use_gl=true',
      'skia_enable_gpu=true',
      'skia_enable_svg=true',
      'skia_use_expat=true',
      'extra_cflags=["-DSK_SUPPORT_GPU=1", "-DSK_GL", "-DSK_DISABLE_LEGACY_SHADERCONTEXT"]',
    ]

  if 'linux' == host and 'arm64' == host_machine:
    tools_dir = 'tools'
    ninja = 'ninja-linux-arm64'

  patch_sources()
  embed_api()

  out = os.path.join('out', build_type + '-' + target + '-' + machine)
  gn = 'gn.exe' if 'windows' == host else 'gn'
  print('> GN args:', ' '.join(args))
  subprocess.check_call([os.path.join('bin', gn), 'gen', out, '--args=' + ' '.join(args)])
  subprocess.check_call([os.path.join('..', tools_dir, ninja), '-C', out, 'skia', 'modules'])

  return 0

if __name__ == '__main__':
  sys.exit(main())
