import CSkia

public class Image {
  public typealias Sampling = sk_samplingoptions_t

  var handle: OpaquePointer

  init(handle: OpaquePointer) {
    self.handle = handle
  }

  public init?(file: String) {
    guard let h = sk_image_make_from_encoded_file(file) else { return nil }
    handle = h
  }

  public var width: Int32 {
    sk_image_get_width(handle)
  }

  public var height: Int32 {
    sk_image_get_height(handle)
  }

  public func shader(x: TileMode, y: TileMode, sampling: Sampling = .nearest(), matrix: Matrix = .identity) -> Shader {
    withUnsafePointer(to: sampling) { s in
      withUnsafePointer(to: matrix) { m in
        Shader(handle: sk_image_make_shader(handle, x.native(), y.native(), s, m))
      }
    }
  }
}

public extension Image {
  enum FilterMode: UInt32 {
    case nearest = 0
    case linear = 1

    func native() -> sk_filtermode_t {
      sk_filtermode_t(rawValue)
    }

    init(_ native: sk_filtermode_t) {
      self.init(rawValue: native.rawValue)!
    }
  }
}

public extension Image.Sampling {
  static func mipmap() -> Image.Sampling {
    Image.Sampling(
      max_anisotropic: 0,
      use_cubic: false,
      cubic: sk_cubicresampler_t(b: 0, c: 0),
      filter: LINEAR_SK_FILTERMODE,
      mipmap: LINEAR_SK_MIPMAPMODE
    )
  }

  static func linear() -> Image.Sampling {
    Image.Sampling(
      max_anisotropic: 0,
      use_cubic: false,
      cubic: sk_cubicresampler_t(b: 0, c: 0),
      filter: LINEAR_SK_FILTERMODE,
      mipmap: NONE_SK_MIPMAPMODE
    )
  }

  static func nearest() -> Image.Sampling {
    Image.Sampling(
      max_anisotropic: 0,
      use_cubic: false,
      cubic: sk_cubicresampler_t(b: 0, c: 0),
      filter: NEAREST_SK_FILTERMODE,
      mipmap: NONE_SK_MIPMAPMODE
    )
  }

  static func cubic() -> Image.Sampling {
    Image.Sampling(
      max_anisotropic: 0,
      use_cubic: true,
      cubic: sk_cubicresampler_t(b: 1 / 3, c: 1 / 3),
      filter: NEAREST_SK_FILTERMODE,
      mipmap: NONE_SK_MIPMAPMODE
    )
  }
}

public extension Image {
  enum TileMode: UInt32 {
    case clamp
    case `repeat`
    case mirror
    case decal

    func native() -> sk_tilemode_t {
      sk_tilemode_t(rawValue)
    }

    init(_ native: sk_tilemode_t) {
      self.init(rawValue: native.rawValue)!
    }
  }
}
