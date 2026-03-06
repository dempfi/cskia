import CSkia

public typealias ImageInfo = sk_imageinfo_t

public extension ImageInfo {
  init(width: Int32, height: Int32, color: ColorType, alpha: AlphaType) {
    self.init(width: width, height: height, color_type: color.native(), alpha_type: alpha.native(), color_space: nil)
  }
}
