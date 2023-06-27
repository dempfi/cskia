#!/bin/bash
lipo_skiasharp() {
  local folder_name="$1"
  local arch="$2"
  local path=$folder_name/libskia.framework/libskia

  lipo -extract $arch $path -output $path
}

pack_macos() {
  mkdir -p build/libskia.framework

  lipo skia/out/Release-macos-arm64/libskia.a skia/out/Release-macos-x64/libskia.a -output build/libskia.framework/libskia -create
  xcodebuild -create-xcframework \
            -framework build/libskia.framework \
            -output skia.xcframework
}

rm -rf skia.xcframework
pack_macos;
rm -rf build
