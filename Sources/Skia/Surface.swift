
import CSkia
import MetalKit

/**
 * `Surface` is responsible for managing the pixels that a canvas draws into. The pixels can be
 * allocated either in CPU memory (a raster surface) or on the GPU (a GrRenderTarget surface).
 *
 * `Surface` takes care of allocating a `Canvas` that will draw into the surface. Call
 * surface->getCanvas() to use that canvas (but don't delete it, it is owned by the surface).
 *
 * `Surface` always has non-zero dimensions. If there is a request for a new surface, and either
 * of the requested dimensions are zero, then `nil` will be returned.
 *
 * Use one of the static `make` methods to create instances of `Surface`
 */
public final class Surface {
  var handle: OpaquePointer

  init(handle: OpaquePointer) {
    self.handle = handle
  }

  public init?(using context: DirectContext, in target: BackendRenderTarget, origin: Origin = .topLeft, colorType: ColorType = .rgba8888, colorSpace: ColorSpace) {
    if let handle = sk_surface_make_from_render_target(context.handle, target.handle, origin.native(), colorType.native(), colorSpace.handle, nil) {
      self.handle = handle
    } else {
      return nil
    }
  }

  public init?(using context: DirectContext, in view: MTKView, origin: Origin = .topLeft, colorType: ColorType = .rgba8888, colorSpace: ColorSpace) {
    let viewPointer = UnsafeMutableRawPointer(Unmanaged.passUnretained(view).toOpaque())
    if let handle = sk_surface_make_from_mtk_view(context.handle, viewPointer, origin.native(), Int32(view.sampleCount), colorType.native(), colorSpace.handle, nil) {
      self.handle = handle
    } else {
      return nil
    }
  }

  public init?(info: ImageInfo) {
    let surfacehandle = withUnsafePointer(to: info) {
      sk_surface_make_raster($0, 0, nil)
    }

    guard let surfacehandle else { return nil }
    handle = surfacehandle
  }

  deinit {
    sk_surface_unref(handle)
  }

  /**
   * Returns `Canvas` that draws into `Surface`. Subsequent calls return the same `Canvas`.
   * `Canvas` returned is managed and owned by `Surface`, and is deleted when `Surface`
   * is deleted.
   * - Returns: drawing `Canvas` for `Surface`
   */
  public var canvas: Canvas {
    Canvas(handle: sk_surface_get_canvas(handle))
  }

  public var width: Float {
    sk_surface_get_width(handle)
  }

  public var height: Float {
    sk_surface_get_height(handle)
  }

  public func snapshot() -> Image {
    Image(handle: sk_surface_make_image_snapshot(handle))
  }
}

public extension Surface {
  enum Origin: UInt32 {
    case topLeft = 0
    case bottomLeft = 1

    func native() -> gr_surfaceorigin_t {
      gr_surfaceorigin_t(rawValue: rawValue)
    }

    init(_ x: gr_surfaceorigin_t) {
      self.init(rawValue: x.rawValue)!
    }
  }
}
