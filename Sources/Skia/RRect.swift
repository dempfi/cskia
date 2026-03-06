import CSkia

public final class RRect {
  var handle: OpaquePointer

  init(handle: OpaquePointer) {
    self.handle = handle
  }

  public init() {
    handle = sk_rrect_create()
    sk_rrect_set_empty(handle)
  }

  public init(rect: SkRect) {
    handle = sk_rrect_create()
    set(rect: rect)
  }

  public init(rect: SkRect, xradius: Float, yradius: Float) {
    handle = sk_rrect_create()
    set(rect: rect, xradius: xradius, yradius: yradius)
  }

  public init(rrect: RRect) {
    handle = sk_rrect_create2(rrect.handle)
  }

  public var rect: SkRect {
    let ptr = UnsafeMutablePointer<sk_rect_t>.allocate(capacity: 1)

    sk_rrect_get_rect(handle, ptr)
    return ptr.pointee
  }

  public func setEmpty() {
    sk_rrect_set_empty(handle)
  }

  public func set(rect: SkRect) {
    withUnsafePointer(to: rect) {
      sk_rrect_set_rect(handle, $0)
    }
  }

  public func set(rect: SkRect, xradius: Float, yradius: Float) {
    withUnsafePointer(to: rect) {
      sk_rrect_set_rect3(handle, $0, xradius, yradius)
    }
  }

  deinit {
    sk_rrect_destroy(handle)
  }
}
