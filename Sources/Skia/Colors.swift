import CSkia

public typealias SkColor = sk_color_t

/// Describes how pixel bits encode color. A pixel may be an alpha mask, a grayscale, Red Green and Blue (RGB), or
/// Alpha, Red, Green and Blue (ARGB)
public enum ColorType: UInt32 {
  /// encoding format and size is unknown.
  case unknown = 0
  /// alpha in 8-bit byte
  case alpha8
  /// 5 bits red, 6 bits green, 5 bits blue, in 16-bit word
  case rgb565
  /// 4 bits for alpha, red, green, blue; in 16-bit word
  case argb4444
  /// 8 bits for red, green, blue, alpha; in 32-bit word
  case rgba8888
  /// 8 bits each for red, green, blue; last 8 bits are unused; in 32-bit word
  case rgb888x
  /// 8 bits for blue, green, red, alpha; in 32-bit word
  case bgra8888
  /// 10 bits for red, green, blue; 2 bits for alpha; in 32-bit word
  case rgba1010102
  /// 10 bits for blue, green, red; 2 bits for alpha; in 32-bit word
  case bgra1010102
  /// 10 bits each for red, green, blue, 2 bits are unused; in 32-bit word
  case rgb101010x
  /// 10 bits each for blue, green, red, 2 bits are unused; in 32-bit word
  case bgr101010x
  /// 10 bits each for blue, green, red, 2 bits are unused; in 32-bit word, extended range
  case bgr101010xXR
  case rgba10x6
  /// grayscale level in 8-bit byte
  case gray8
  /// half floats in [0,1] for red, green, blue, alpha
  case rgbaF16norm
  /// half floats in [0,1] for red, green, blue, alpha; in 64-bit word
  case rgbaF16
  /// C float for red, green, blue, alpha; in 128-bit word
  case rgbaF32
  /// `uint8_t` for red and green
  case r8g8unorm
  /// half float for alpha
  case a16float
  /// half float for red and green
  case r16g16float
  /// little endian `uint16_t` for alpha
  case a16unorm
  /// little endian `uint16_t` for red and green
  case r16g16unorm
  /// little endian `uint16_t` for red, green, blue
  case r16g16b16a16unorm
  case srgba8888
  case r8unorm

  func native() -> sk_colortype_t {
    sk_colortype_t.init(rawValue)
  }

  init(_ x: sk_colortype_t) {
    self.init(rawValue: x.rawValue)!
  }
}

public enum AlphaType: UInt32 {
  case unknown
  case opaque
  case premul
  case unpremul

  func native() -> sk_alphatype_t {
    sk_alphatype_t(rawValue)
  }

  init(_ x: sk_alphatype_t) {
    self.init(rawValue: x.rawValue)!
  }
}

public final class ColorSpace {
  var handle: OpaquePointer

  init(_ handle: OpaquePointer) {
    self.handle = handle
  }

  public static func p3() -> ColorSpace {
    ColorSpace(sk_colorspace_make_p3())
  }

  public static func srgb() -> ColorSpace {
    ColorSpace(sk_colorspace_make_srgb())
  }

  deinit {
    sk_colorspace_unref(handle)
  }
}
