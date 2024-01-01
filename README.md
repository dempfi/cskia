# Skia C API

Based on Skia version: `m117-26ce945`

## Building

- `python3 script/checkout.py --version m117-26ce945`
- `python3 script/build.py --build-type Release --target macos --machine arm64`
- `python3 script/build.py --build-type Release --target macos --machine x64`
- `script/pack.sh`
- `cp -r skia.xcframework/ ../skia/skia.xcframework/`
- `cp -r skparagraph.xcframework/ ../skia/skparagraph.xcframework/`
- `cp -r skshaper.xcframework/ ../skia/skshaper.xcframework/`
- `cp -r skunicode.xcframework/ ../skia/skunicode.xcframework/`
- `cp -r api/include ../skia/Sources/cskia`

_Forked from https://github.com/richardwilkes/cskia_
_Reference https://github.com/flutter/engine/blob/main/lib/ui/painting.dart_
_Building https://github.com/JetBrains/skia-pack_
_https://github.com/skia4delphi/skia_
