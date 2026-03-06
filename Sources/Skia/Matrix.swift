import CSkia

public typealias Matrix = sk_matrix_t

public extension Matrix {
  static let identity = Matrix(scaleX: 1, skewX: 0, transX: 0, skewY: 0, scaleY: 1, transY: 0, persp0: 0, persp1: 0, persp2: 1)
}
