import CSkia

/**
 * `PathEffect` is the base class for objects in the `Paint` that affect
 * the geometry of a drawing primitive before it is transformed by the
 * canvas' matrix and drawn.
 * Dashing is implemented as a subclass of `PathEffect`.
 */
public final class PathEffect {
  var handle: OpaquePointer

  init(handle: OpaquePointer) {
    self.handle = handle
  }

  deinit {
    sk_patheffect_unref(handle)
  }

  /**
   * Stamp the specified path to fill the shape, using the matrix to define the latice.
   * - Parameter matrix: matrix description
   * - Parameter path: path description
   */
  public static func path2d(matrix: Matrix, path: Path) -> PathEffect {
    withUnsafePointer(to: matrix) {
      PathEffect(handle: sk_patheffect_make_2dpath($0, path.handle))
    }
  }

  public static func line2d(width: Float, matrix: Matrix) -> PathEffect {
    withUnsafePointer(to: matrix) {
      PathEffect(handle: sk_patheffect_make_2dline(width, $0))
    }
  }

  public static func dash(intervals: [Float], count: Int, phase: Float) -> PathEffect {
    PathEffect(handle: sk_patheffect_make_dash(intervals, Int32(count), phase))
  }
}
