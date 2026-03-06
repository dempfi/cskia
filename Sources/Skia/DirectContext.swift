import CSkia
import MetalKit

public class DirectContext {
  var handle: OpaquePointer

  public init?(device: MTLDevice, queue: MTLCommandQueue) {
    let device = Unmanaged.passUnretained(device).toOpaque()
    let queue = Unmanaged.passUnretained(queue).toOpaque()
    var backendContext = gr_mtl_backendcontext_t(device: device, queue: queue, binary_archive: nil)
    if let h = gr_directcontext_make_metal(&backendContext, nil) {
      handle = h
    } else {
      return nil
    }
  }

  deinit {
    gr_directcontext_release_resources_and_abandon_context(handle)
//    gr_directcontext_delete(handle)
  }

  public func flushAndSubmit(synchronous: Bool = false) {
    gr_directcontext_flush_and_submit(handle, synchronous ? YES_GR_SYNC_CPU : NO_GR_SYNC_CPU)
  }

  public func flushAndSubmit(_ surface: Surface, synchronous: Bool = false) {
    gr_directcontext_flush_and_submit_with_surface(handle, surface.handle, synchronous ? YES_GR_SYNC_CPU : NO_GR_SYNC_CPU)
  }

  public func abandon(releaseResources: Bool = false) {
    if releaseResources {
      gr_directcontext_release_resources_and_abandon_context(handle)
    } else {
      gr_directcontext_abandon_context(handle)
    }
  }
}
