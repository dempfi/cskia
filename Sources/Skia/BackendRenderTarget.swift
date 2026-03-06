import CSkia
import MetalKit

public class BackendRenderTarget {
  var handle: OpaquePointer

  init(handle: OpaquePointer) {
    self.handle = handle
  }

  public init(width: Int, height: Int, info: TextureInfo) {
    var info = info.native()
    handle = gr_backendrendertarget_create_mtl(Int32(width), Int32(height), &info)
  }

  deinit {
    gr_backendrendertarget_destroy(handle)
  }
}
