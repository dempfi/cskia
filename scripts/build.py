#! /usr/bin/env python3

import common, os, subprocess, sys, shutil
from pathlib import Path

def embed_api():
  """Copy C API headers and sources into the Skia source tree and register them in the GN build."""
  api_dir = Path(common.REPO_ROOT) / 'api'
  skia_dir = Path(common.REPO_ROOT) / 'skia'
  include_src = api_dir / 'include'
  include_dst = skia_dir / 'include'
  src_src = api_dir / 'src'
  src_dst = skia_dir / 'src'
  gni_file = skia_dir / 'gn' / 'core.gni'

  # Copy header and source files
  shutil.copytree(include_src, include_dst, dirs_exist_ok=True)
  shutil.copytree(src_src, src_dst, dirs_exist_ok=True)

  # Register source files in GN build
  with gni_file.open() as f:
    lines = f.readlines()

  start_index = next(
    (i for i, line in enumerate(lines) if line.strip().startswith('skia_core_sources = [')),
    None
  )
  if start_index is None:
    raise ValueError("Could not find 'skia_core_sources = [' in gn/core.gni")

  src_files = [f.name for f in src_src.glob('*')]

  # Check if already embedded
  for line in lines[start_index + 1:]:
    if any(f in line for f in src_files):
      print('> C API sources already embedded in gn/core.gni')
      return

  for f in src_files:
    lines.insert(start_index + 1, f'  "$_src/{f}",\n')

  with gni_file.open('w') as f:
    f.writelines(lines)

  print('> Embedded C API into Skia source tree')

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
    'skia_use_sfntly=false',

    # Text layout
    'skia_enable_skparagraph=true',
    'skia_enable_skshaper=true',
    'skia_use_icu=true',
    'skia_use_system_icu=false',
    'skia_use_harfbuzz=true',
    'skia_pdf_subset_harfbuzz=true',
    'skia_use_system_harfbuzz=false',
    'skia_use_system_freetype2=false',
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

  embed_api()

  out = os.path.join('out', build_type + '-' + target + '-' + machine)
  gn = 'gn.exe' if 'windows' == host else 'gn'
  print('> GN args:', ' '.join(args))
  subprocess.check_call([os.path.join('bin', gn), 'gen', out, '--args=' + ' '.join(args)])
  subprocess.check_call([os.path.join('..', tools_dir, ninja), '-C', out, 'skia', 'modules'])

  return 0

if __name__ == '__main__':
  sys.exit(main())
