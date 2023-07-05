#!/bin/bash
lipo_skiasharp() {
  local folder_name="$1"
  local arch="$2"
  local path=$folder_name/libskia.framework/libskia

  lipo -extract $arch $path -output $path
}

pack_macos() {
  local lib_name="$1"
  rm -rf ${lib_name}.xcframework
  mkdir -p build/lib${lib_name}.framework

  lipo skia/out/Release-macos-arm64/lib${lib_name}.a skia/out/Release-macos-x64/lib${lib_name}.a -output build/lib${lib_name}.framework/lib${lib_name} -create
  xcodebuild -create-xcframework \
            -framework build/lib${lib_name}.framework \
            -output ${lib_name}.xcframework
}

pack_macos skia;
pack_macos skparagraph;
pack_macos skunicode;
pack_macos skshaper;
rm -rf build
