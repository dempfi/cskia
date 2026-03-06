import CSkia

public typealias SkPoint = sk_point_t

public extension SkPoint {
  static prefix func - (pt: SkPoint) -> SkPoint {
    SkPoint(x: -pt.x, y: -pt.y)
  }
}

public typealias SkPoint3 = sk_point3_t

public typealias SkVector = sk_vector_t

public typealias SkRect = sk_rect_t

public typealias SkIRect = sk_irect_t

public typealias SkSize = sk_size_t

public extension SkRect {
  init(x: Float, y: Float, width: Float, height: Float) {
    self.init(left: x, top: y, right: x + width, bottom: y + height)
  }
}

public extension SkIRect {
  init(x: Int32, y: Int32, width: Int32, height: Int32) {
    self.init(left: x, top: y, right: x + width, bottom: y + height)
  }
}
