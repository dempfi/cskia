import CSkia

/// `Path` contain geometry. `Path` may be empty, or contain one or more verbs that
/// outline a figure. `Path` always starts with a move verb to a Cartesian coordinate,
/// and may be followed by additional verbs that add lines or curves.
/// Adding a close verb makes the geometry into a continuous loop, a closed contour.
/// `Path` may contain any number of contours, each beginning with a move verb.
///
/// `Path` contours may contain only a move verb, or may also contain lines,
/// quadratic beziers, conics, and cubic beziers. `Path` contours may be open or
/// closed.
///
/// When used to draw a filled area, `Path` describes whether the fill is inside or
/// outside the geometry. `Path` also describes the winding rule used to fill
/// overlapping contours.
///
/// The various commands that add to the path provide a fluid interface, meaning that
/// calling the methods return the instance on which it was invoked, easily allowing
/// the drawing operations to be concatenated.

public final class Path {
  public final class Builder {
    let handle: OpaquePointer

    public init() {
      handle = sk_pathbuilder_create()
    }

    deinit {
      sk_pathbuilder_destroy(handle)
    }
  }

  /// FillType selects the rule used to fill `Path`. `Path` set to `.winding`
  /// fills if the sum of contour edges is not zero, where clockwise edges add one, and
  /// counterclockwise edges subtract one. `Path` set to `.evenOdd` fills if the
  /// number of contour edges is odd. Each FillType has an inverse variant that
  /// reverses the rule:
  ///
  /// `.inverseWinding` fills where the sum of contour edges is zero;
  /// `.inverseEvenOdd` fills where the number of contour edges is even.
  public enum FillType: UInt32 {
    /// Specifies fill as area is enclosed by a non-zero sum of contour directions
    case winding = 0
    /// Specifies fill as area enclosed by an odd number of contours.
    case evenOdd = 1
    /// Specifies fill as area is enclosed by a zero sum of contour directions.
    case inverseWinding = 2
    /// Specifies fill as area enclosed by an even number of contours.
    case inverseEvenOdd = 3

    func native() -> sk_pathfilltype_t {
      sk_pathfilltype_t(rawValue)
    }

    init(_ native: sk_pathfilltype_t) {
      self.init(rawValue: native.rawValue)!
    }
  }

  /// SegmentMask constants correspond to each drawing Verb type in Path; for
  /// instance, if Path only contains lines, only the `.line` bit is set.
  public enum SegmentMask: UInt32 {
    ///  Set if verb array contains a `.line` verb
    case line = 1
    /// Set if verb array contains `.quad`. Note that `conicTo()` may add a quad.
    case quad = 2
    ///  Set if verb array contains a `.conic` verb
    case conic = 4
    /// Set if verb array contains `.cubic` verb
    case cubic = 8
  }

  /// The logical operations that can be performed when combining two paths
  public enum Op: UInt32 {
    /// subtract the op path from the first path
    case difference = 0
    /// intersect the two paths
    case intersect = 1
    /// union (inclusive-or) the two paths
    case union = 2
    /// exclusive-or the two paths
    case xor = 3
    /// subtract the first path from the op path
    case reverseDifference = 4

    func native() -> sk_pathop_t {
      sk_pathop_t.init(rawValue)
    }

    init(_ native: sk_pathop_t) {
      self.init(rawValue: native.rawValue)!
    }
  }

  public enum PathAddMode {
    case append
    case extend
  }

  var handle: OpaquePointer

  init(handle: OpaquePointer) {
    self.handle = handle
  }

  deinit {
    sk_path_destroy(handle)
  }

  public var generationId: UInt32 {
    sk_path_get_generation_id(handle)
  }

  public init(svg: String) {
    handle = sk_path_create(svg.cString(using: .utf8))
  }

  public var svg: String? {
    guard let skString = sk_path_to_svg(handle) else { return nil }
    guard let cString = sk_string_get_text(skString) else { return nil }
    return String(cString: cString)
  }

  /// Returns FillType, the rule used to fill Path. FillType of a new Path is .winding
  public var fillType: FillType {
    FillType(sk_path_get_fill_type(handle))
  }

  public var isConvex: Bool { sk_path_is_convex(handle) }
  public var isConcave: Bool { !isConvex }
  public var isEmpty: Bool { sk_path_is_empty(handle) }
  public var isOval: Bool { sk_path_is_oval(handle, nil) }
  public var isRRect: Bool { sk_path_is_rrect(handle, nil) }
  public var isLine: Bool { sk_path_is_line(handle, nil) }
  public var isRect: Bool { sk_path_is_rect(handle, nil) }

  /// Returns a mask, where each set bit corresponds to a SegmentMask constant
  /// if `Path` contains one or more verbs of that type.
  /// Returns zero if `Path` contains no lines, or curves: quads, conics, or cubics.
  /// `egmentMasks` returns a cached result; it is very fast.
  public var segmentMasks: SegmentMask {
    SegmentMask(rawValue: sk_path_get_segment_masks(handle))!
  }

  public var lastPoint: SkPoint {
    var pp = sk_point_t()

    sk_path_get_last_point(handle, &pp)
    return SkPoint(x: pp.x, y: pp.y)
  }

  /// Returns minimum and maximum axes values of `SkPoint` array.
  /// Returns (0, 0, 0, 0) if `Path` contains no points. Returned bounds width and height may
  /// be larger or smaller than area affected when `Path` is drawn.
  /// `SkRect` returned includes all `SkPoint` added to `Path`, including `SkPoint` associated with
  /// `.move` that define empty contours.
  /// - Returns: bounds of all `SkPoint` in `SkPoint` array
  public var bounds: SkRect {
    var rect = sk_rect_t()
    sk_path_get_bounds(handle, &rect)
    return rect
  }

  /// Returns minimum and maximum axes values of the lines and curves in `Path`.
  /// Returns (0, 0, 0, 0) if `Path` contains no points.
  /// Returned bounds width and height may be larger or smaller than area affected
  /// when `Path` is drawn.
  /// Includes `SkPoint` associated with `.move` that define empty
  /// contours.
  /// Behaves identically to `bounds` when `Path` contains
  /// only lines. If `Path` contains curves, computed bounds includes
  /// the maximum extent of the quad, conic, or cubic; is slower than `bounds`
  /// and unlike `bounds`, does not cache the result.
  ///
  /// - Returns: tight bounds of curves in `Path`
  public var tightBounds: SkRect {
    var rect = sk_rect_t()
    sk_path_get_tight_bounds(handle, &rect)
    return rect
  }

  public func getOvalBounds() -> SkRect? {
    var ret = sk_rect_t()
    if sk_path_is_oval(handle, &ret) {
      return ret
    }
    return nil
  }

  public func getRoundRect() -> RRect? {
    let rrect = RRect()
    if sk_path_is_rrect(handle, rrect.handle) {
      return rrect
    }
    return nil
  }

  public func getLine() -> [SkPoint]? {
    var tmp = [sk_point_t(), sk_point_t()]
    if sk_path_is_line(handle, &tmp) {
      return [SkPoint(x: tmp[0].x, y: tmp[0].y), SkPoint(x: tmp[1].x, y: tmp[1].y)]
    }
    return nil
  }

  public func getRect() -> SkRect {
    var rect = sk_rect_t()
    sk_path_is_rect(handle, &rect)
    return rect
  }

  /// Returns true if the point (x, y) is contained by `Path`, taking into
  /// account FillType.
  /// - Parameter x: x-axis value of containment test
  /// - Parameter y: y-axis value of containment test
  /// - Returns: true if `SkPoint` is in `Path`
  public func contains(x: Float, y: Float) -> Bool {
    sk_path_contains(handle, x, y)
  }

  /// Transform verb array, SkPoint array, and weight by matrix.
  /// transform may change verbs and increase their number.
  /// Path is replaced by transformed data.
  public func transformed(matrix: Matrix) -> Path {
    withUnsafePointer(to: matrix) {
      Path(handle: sk_path_transform(handle, $0))
    }
  }

  /// Add another path to this path
  public func add(_ other: Path, op: Op) -> Path? {
    guard let handle = sk_path_op(handle, other.handle, op.native()) else { return nil }
    return Path(handle: handle)
  }

//  func addPath(_ other: Path, dx: Float, dy: Float, mode: PathAddMode = .append) {
//    sk_path_add_path_offset(handle, other.handle, dx, dy, sk_path_add_mode_t(mode == .append ? 0 : 1))
//  }
//
//  func addPath(_ other: Path, mode: PathAddMode = .append) {
//    sk_path_add_path(handle, other.handle, sk_path_add_mode_t(mode == .append ? 0 : 1))
//  }
//
//  func addPath(_ other: Path, matrix: Matrix, mode: PathAddMode = .append) {
//    withUnsafePointer(to: matrix) {
//      sk_path_add_path_matrix(handle, other.handle, $0, sk_path_add_mode_t(mode == .append ? 0 : 1))
//    }
//  }
//
//  func addPathReverse(_ other: Path) {
//    sk_path_add_path_reverse(handle, other.handle)
//  }
//
//  func simplify(result: Path) {
//    sk_pathop_simplify(handle, result.handle)
//  }
//
//  func simplify() -> Path {
//    let result = Path()
//    simplify(result: result)
//    return result
//  }
}
