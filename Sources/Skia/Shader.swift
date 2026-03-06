import CSkia

public class Shader {
  var handle: OpaquePointer

  init(handle: OpaquePointer) {
    self.handle = handle
  }

  init(linearGradient colors: [SkColor], start: SkPoint, end: SkPoint, tiling: Image.TileMode = .clamp) {
    handle = [start, end].withUnsafeBufferPointer { pointsPtr in
      colors.withUnsafeBufferPointer { colorsPtr in
        sk_shader_make_gradient_linear(pointsPtr.baseAddress!, colorsPtr.baseAddress, nil, Int32(colors.count), tiling.native(), nil)
      }
    }
  }

  deinit {
    sk_shader_unref(handle)
  }
}
