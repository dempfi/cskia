# cskia

Swift package providing C bindings to [Google's Skia](https://skia.org) graphics library. Ships prebuilt XCFrameworks for Apple platforms so consumers don't need to compile Skia from source.

## Platforms

| Platform | Architectures | Minimum Version |
|----------|--------------|-----------------|
| macOS    | arm64, x64   | 13.0            |
| iOS      | arm64        | 15.0            |
| tvOS     | arm64        | 15.0            |

Linux (x64) and Windows (x64) static libraries are also built and published as release artifacts but are not included in the Swift package.

## Installation

Add cskia to your `Package.swift`:

```swift
dependencies: [
    .package(url: "https://github.com/dempfi/cskia", from: "m145-fba326b")
]
```

Then add `"cskia"` to your target's dependencies:

```swift
.target(name: "MyApp", dependencies: [
    .product(name: "cskia", package: "cskia")
])
```

The package automatically downloads prebuilt XCFrameworks from GitHub releases.

## Usage

Import the module and use the C API directly:

```swift
import cskia

// Create a raster surface
var info = sk_imageinfo_t(
    colorspace: nil,
    width: 200, height: 200,
    colorType: RGBA_8888_SK_COLORTYPE,
    alphaType: PREMUL_SK_ALPHATYPE
)
let surface = sk_surface_make_raster(&info, 0, nil)
let canvas = sk_surface_get_canvas(surface)

// Draw a red circle
let paint = sk_paint_create()
sk_paint_set_color(paint, 0xFFFF0000)
sk_paint_set_antialias(paint, true)
sk_canvas_draw_circle(canvas, 100, 100, 50, paint)

// Clean up
sk_paint_destroy(paint)
sk_surface_unref(surface)
```

### GPU rendering (Metal)

```swift
import cskia
import Metal

let device = MTLCreateSystemDefaultDevice()!
let queue = device.makeCommandQueue()!

var ctx = gr_mtl_backendcontext_t()
ctx.fDevice = Unmanaged.passRetained(device).toOpaque()
ctx.fQueue = Unmanaged.passRetained(queue).toOpaque()

let gpuContext = gr_directcontext_make_metal(&ctx, nil)
// Create GPU-accelerated surfaces with sk_surface_make_render_target(...)
```

## API Surface

The C API is organized into these modules:

**Core drawing** -- `sk_canvas`, `sk_surface`, `sk_paint`, `sk_path`, `sk_image`, `sk_pixmap`

**Text & typography** -- `sk_font`, `sk_typeface`, `sk_textblob`, `sk_paragraph`, `sk_paragraphbuilder`, `sk_paragraphstyle`, `sk_textstyle`

**Effects** -- `sk_shader`, `sk_colorfilter`, `sk_imagefilter`, `sk_maskfilter`, `sk_patheffect`, `sk_blender`

**GPU** -- `gr_directcontext`, `gr_backendsurface`, `gr_backendsemaphore`, `gr_gl_interface`, `gr_vk_extensions`

**Utilities** -- `sk_region`, `sk_rrect`, `sk_codec`, `sk_colorspace`, `sk_document`, `sk_data`, `sk_string`, `sk_picture`, `sk_vertices`, `sk_svgcanvas`

All headers are in [`api/include/`](api/include/).

## Building from Source

Prerequisites: Python 3, Xcode command line tools, and ~10 GB disk space for Skia checkout.

```bash
# Full local build (checkout, build macOS, pack XCFrameworks, sync headers)
make local

# Or step by step:
make checkout          # Clone Skia at the pinned version
make build-macos       # Build for macOS (arm64 + x64)
make build-ios         # Build for iOS (device + simulator)
make build-tvos        # Build for tvOS (device + simulator)
make pack              # Create XCFrameworks from all builds
make pack-macos        # Create XCFrameworks from macOS builds only
make sync-headers      # Copy API headers into Sources/cskia/include
make clean             # Remove all build artifacts
```

The Skia version is pinned in the [`skia-version`](skia-version) file.

## Project Structure

```
api/
  include/          C API headers (sk_*.h, gr_*.h)
  src/              C++ implementations wrapping Skia internals
Sources/cskia/     Swift package target (modulemap + synced headers)
scripts/           Build automation (checkout, build, pack, release)
.github/workflows/ CI: builds all platforms and publishes GitHub releases
```

## How It Works

1. **Checkout** -- clones Skia and its dependencies at the pinned commit
2. **Build** -- injects the C API sources into Skia's GN build, then compiles with ninja for each platform/architecture
3. **Pack** -- merges per-architecture static libraries with `libtool` and bundles them into XCFrameworks
4. **Release** -- CI uploads XCFrameworks to GitHub releases; `Package.swift` references them by checksum

The C API is compiled as part of Skia itself (not a separate library), with GPU (Metal/Ganesh), text shaping (HarfBuzz), paragraph layout, and Unicode (ICU) support enabled.

## License

Skia is licensed under the [BSD 3-Clause License](https://skia.org/docs/user/license/).
