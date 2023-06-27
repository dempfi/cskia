# Skia C API

Based on Skia version: `m115-3e827ba`

## Building

- `python3 script/checkout.py --version m115-3e827ba`
- `python3 script/build.py --build-type Release --target macos --machine arm64`
- `python3 script/build.py --build-type Release --target macos --machine x64`
- `script/pack.sh`

_Forked from https://github.com/richardwilkes/cskia_
_Reference https://github.com/flutter/engine/blob/main/lib/ui/painting.dart_
_Building https://github.com/JetBrains/skia-pack_
