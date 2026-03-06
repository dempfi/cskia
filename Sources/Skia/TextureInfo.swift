import CSkia
import MetalKit

public struct TextureInfo {
  var texture: MTLTexture

  public init(texture: MTLTexture) {
    self.texture = texture
  }

  func native() -> gr_mtl_textureinfo_t {
    gr_mtl_textureinfo_t(texture: Unmanaged.passUnretained(texture).toOpaque())
  }
}
