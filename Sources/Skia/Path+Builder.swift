import CSkia

public extension Path.Builder {
  /// Return the built `Path` and reset to empty the internal state
  func detach() -> Path {
    Path(handle: sk_pathbuilder_detach(handle))
  }

  /// Return the built `Path`
  func snapshot() -> Path {
    Path(handle: sk_pathbuilder_snapshot(handle))
  }

  @discardableResult func reset() -> Self {
    sk_pathbuilder_reset(handle)
    return self
  }

  @discardableResult func close() -> Self {
    sk_pathbuilder_close(handle)
    return self
  }

  @discardableResult func offset(dx: Float, dy: Float) -> Self {
    sk_pathbuilder_offset(handle, dx, dy)
    return self
  }
}

// -MARK: Line builder
public extension Path.Builder {
  /// Four oval parts with radii (rx, ry) start at last `Path` point and ends at (x, y).
  /// Size and Direction select one of the four oval parts.
  enum ArcSize: UInt32 {
    case small = 0 // smaller of arc pair
    case large // larger of arc pair

    func native() -> sk_patharcsize_t {
      sk_patharcsize_t(rawValue)
    }

    init(_ native: sk_patharcsize_t) {
      self.init(rawValue: native.rawValue)!
    }
  }

  /// `Direction` describes whether contour is clockwise or counterclockwise.
  /// When `Path` contains multiple overlapping contours, `Direction` together with
  /// `FillType` determines whether overlaps are filled or form holes.
  ///
  /// `Direction` also determines how contour is measured. For instance, dashing
  /// measures along `Path` to determine where to start and stop stroke; `Direction`
  /// will change dashed results as it steps clockwise or counterclockwise.
  ///
  /// Closed contours like `SkRect`, `RRect`, circle, and oval added with
  /// `.clockwise` travel clockwise; the same added with `.counterclockwise`
  /// travel counterclockwise.
  enum Direction: UInt32 {
    case clockwise = 0
    case counterClockwise = 1

    func native() -> sk_pathdirection_t {
      sk_pathdirection_t(rawValue)
    }

    init(_ native: sk_pathdirection_t) {
      self.init(rawValue: native.rawValue)!
    }
  }

  @discardableResult func moveTo(x: Float, y: Float) -> Self {
    sk_pathbuilder_move_to(handle, x, y)
    return self
  }

  @discardableResult func lineTo(x: Float, y: Float) -> Self {
    sk_pathbuilder_line_to(handle, x, y)
    return self
  }

  @discardableResult func rlineTo(x: Float, y: Float) -> Self {
    sk_pathbuilder_r_line_to(handle, x, y)
    return self
  }

  @discardableResult func polylineTo(_ points: [SkPoint]) -> Self {
    var p = points
    sk_pathbuilder_polyline_to(handle, &p, Int32(points.count))
    return self
  }

  /**
   * Adds quad from last point towards point `x,y`, through `cx,cy`
   * If `Path` is empty, or last `Path.verb` is `.close`, last point is set to (0, 0)
   * before adding quad.
   * Appends `.move` verb to verb array and (0, 0) to `SkPoint` array, if needed;
   * then appends `.quad` to verb array; and `SkPoint` p1, p2 to `SkPoint` array.
   * - Parameter x: end point `x` coordinate
   * - Parameter y: end point `y` coordinate
   * - Parameter cx: control point `x` coordinate
   * - Parameter cy: control point `y` coordinate
   */
  @discardableResult func quadTo(x: Float, y: Float, cx: Float, cy: Float) -> Self {
    sk_pathbuilder_quad_to(handle, cx, cy, x, y)
    return self
  }

  /**
   * - Parameter x: end point `x` coordinate
   * - Parameter y: end point `y` coordinate
   * - Parameter cx: control point `x` coordinate
   * - Parameter cy: control point `y` coordinate
   */
  @discardableResult func rquadTo(x: Float, y: Float, cx: Float, cy: Float) -> Self {
    sk_pathbuilder_r_quad_to(handle, cx, cy, x, y)
    return self
  }

  // TODO: Wrong order of points
  @discardableResult func conicTo(x1: Float, y1: Float, x2: Float, y2: Float, weight: Float) -> Self {
    sk_pathbuilder_conic_to(handle, x1, y1, x2, y2, weight)
    return self
  }

  @discardableResult func rconicTo(x1: Float, y1: Float, x2: Float, y2: Float, weight: Float) -> Self {
    sk_pathbuilder_r_conic_to(handle, x1, y1, x2, y2, weight)
    return self
  }

  /**
   * - Parameter x: end point `x` coordinate
   * - Parameter y: end point `y` coordinate
   * - Parameter c1x: first control point `x` coordinate
   * - Parameter c1y: first control point `y` coordinate
   * - Parameter c2x: second control point `x` coordinate
   * - Parameter c2y: second control point `y` coordinate
   */
  @discardableResult func cubicTo(x: Float, y: Float, c1x: Float, c1y: Float, c2x: Float, c2y: Float) -> Self {
    sk_pathbuilder_cubic_to(handle, c1x, c1y, c2x, c2y, x, y)
    return self
  }

  @discardableResult func rcubicTo(x: Float, y: Float, c1x: Float, c1y: Float, c2x: Float, c2y: Float) -> Self {
    sk_pathbuilder_r_cubic_to(handle, c1x, c1y, c2x, c2y, x, y)
    return self
  }

  /**
   * Appends arc to `Path`. Arc is implemented by one or more conics weighted to
   * describe part of oval with radii (rx, ry) rotated by xAxisRotate degrees. Arc
   * curves from last `Path` `SkPoint` to (x, y), choosing one of four possible routes:
   * clockwise or counterclockwise, and smaller or larger.
   * Arc sweep is always less than 360 degrees. arcTo() appends line to (x, y) if
   * either radii are zero, or if last `Path` `SkPoint` equals (x, y). arcTo() scales radii
   * (rx, ry) to fit last `Path` `SkPoint` and (x, y) if both are greater than zero but
   * too small.
   * arcTo() appends up to four conic curves.
   * arcTo() implements the functionality of SVG arc, although SVG sweep-flag value
   * is opposite the integer value of sweep; SVG sweep-flag uses 1 for clockwise,
   * while kCW_Direction cast to int is zero.
   * - Parameter radius: radius on x-axis and y-aix before x-axis, y-axis rotation
   * - Parameter xAxisRotate: x-axis rotation in degrees; positive values are clockwise
   * - Parameter largeArc: chooses smaller or larger arc
   * - Parameter sweep: chooses clockwise or counterclockwise arc
   * - Parameter end: end of arc
   */
  @discardableResult func arcTo(rx: Float, ry: Float, xAxisRotate: Float, largeArc: ArcSize, sweep: Direction, x: Float, y: Float) -> Self {
    sk_pathbuilder_arc_to(handle, rx, ry, xAxisRotate, largeArc.native(), sweep.native(), x, y)
    return self
  }

  /**
   * Appends arc to `Path`. Arc added is part of ellipse
   * bounded by oval, from startAngle through sweepAngle. Both startAngle and
   * sweepAngle are measured in degrees, where zero degrees is aligned with the
   * positive x-axis, and positive sweeps extends arc clockwise.
   * arcTo() adds line connecting `Path` last `SkPoint` to initial arc `SkPoint` if forceMoveTo
   * is false and `Path` is not empty. Otherwise, added contour begins with first point
   * of arc. Angles greater than -360 and less than 360 are treated modulo 360.
   * - Parameter oval: bounds of ellipse containing arc
   * - Parameter startAngle: starting angle of arc in degrees
   * - Parameter sweepAngle: sweep, in degrees. Positive is clockwise; treated modulo 360
   * - Parameter forceMoveTo: true to start a new contour with arc
   */
  @discardableResult func arcTo(oval: SkRect, startAngle: Float, sweepAngle: Float, forceMoveTo: Bool) -> Self {
    withUnsafePointer(to: oval) {
      sk_pathbuilder_arc_to2(handle, $0, startAngle, sweepAngle, forceMoveTo)
    }
    return self
  }

  /**
   * Appends arc to `Path`, after appending line if needed. Arc is implemented by conic
   * weighted to describe part of circle. Arc is contained by tangent from
   * last `Path` point to (x1, y1), and tangent from (x1, y1) to (x2, y2). Arc
   * is part of circle sized to radius, positioned so it touches both tangent lines.
   * If last Path SkPoint does not start Arc, arcTo appends connecting Line to Path.
   * The length of Vector from (x1, y1) to (x2, y2) does not affect Arc.
   * Arc sweep is always less than 180 degrees. If radius is zero, or if
   * tangents are nearly parallel, arcTo appends Line from last Path SkPoint to (x1, y1).
   * arcTo appends at most one Line and one conic.
   * arcTo implements the functionality of PostScript arct and HTML Canvas arcTo.
   * - Parameter x1: x-axis value common to pair of tangents
   * - Parameter y1: y-axis value common to pair of tangents
   * - Parameter x2: x-axis value end of second tangent
   * - Parameter y2: y-axis value end of second tangent
   * - Parameter radius: distance from arc to circle center
   */
  @discardableResult func arcTo(x1: Float, y1: Float, x2: Float, y2: Float, radius: Float) -> Self {
    sk_pathbuilder_arc_to3(handle, x1, y1, x2, y2, radius)
    return self
  }
}

// - MARK: Add elements to Path
public extension Path.Builder {
  /**
   * Add SkRect to the path, appending kMove_Verb, three kLine_Verb, and kClose_Verb,
   * starting with top-left corner of SkRect; followed by top-right, bottom-right,
   * and bottom-left if dir is .clockwise direction; or followed by bottom-left,
   * bottom-right, and top-right if dir is .counterClockwise direction
   *
   * - Parameter rect: SkRect to add as a closed contour
   * - Parameter dir: Direction to wind added contour
   * - Parameter start: index of initial point of SkRect
   */
  @discardableResult func addRect(_ rect: SkRect, direction: Direction = .clockwise, start: UInt32 = 0) -> Self {
    withUnsafePointer(to: rect) {
      sk_pathbuilder_add_rect(handle, $0, direction.native(), start)
    }
    return self
  }

  @discardableResult func addRRect(_ rect: SkRect, radiusX: Float, radiusY: Float, direction: Direction = .clockwise, start: UInt32? = nil) -> Self {
    addRRect(RRect(rect: rect, xradius: radiusX, yradius: radiusY), direction: direction, start: start)
  }

  /**
   * Append RoundedRect to the path, creating a new closed contour. RRect has bounds
   * equal to rect; each corner is 90 degrees of an ellipse with radii (rx, ry). If
   * dir is .clockwise, RRect starts at top-left of the lower-left corner and
   * winds clockwise. If dir is .counterClockwise, RRect starts at the bottom-left
   * of the upper-left corner and winds counterclockwise.
   *
   * If either rx or ry is too large, rx and ry are scaled uniformly until the
   * corners fit. If rx or ry is less than or equal to zero, the method appends
   * the SkRect rect to the path.
   * After appending, Path may be empty, or may contain: SkRect, Oval, or RRect.
   * - Parameter roundedRect: bounds of the rectangle
   * - Parameter Directon to wind the the rectangle
   * - Parameter start: index of initial point of SkRect
   */
  @discardableResult func addRRect(_ rect: RRect, direction: Direction = .clockwise, start: UInt32? = nil) -> Self {
    sk_pathbuilder_add_rrect(handle, rect.handle, direction.native(), start ?? (direction == .clockwise ? 6 : 7))
    return self
  }

  /**
   * Adds oval to path, appending kMove_Verb, four kConic_Verb, and kClose_Verb.
   * Oval is upright ellipse bounded by `SkRect` oval with radii equal to half oval width
   * and half oval height. Oval begins at (oval.fRight, oval.centerY()) and continues
   * clockwise if dir is kCW_Direction, counterclockwise if dir is kCCW_Direction.
   * - Parameter rect: bounds of ellipse added
   * - Parameter direction: `Path`::Direction to wind ellipse
   */
  @discardableResult func addOval(_ rect: SkRect, direction: Direction = .clockwise, start: UInt32 = 0) -> Self {
    withUnsafePointer(to: rect) {
      sk_pathbuilder_add_oval(handle, $0, direction.native(), start)
    }
    return self
  }

  /**
   * Append arc to the path, as the start of new contour. Arc added is part of ellipse
   * bounded by oval, from startAngle through sweepAngle. Both startAngle and
   * sweepAngle are measured in degrees, where zero degrees is aligned with the
   * positive x-axis, and positive sweeps extends arc clockwise.
   *
   * If sweepAngle is less than -360, or sweepAngle is larger than 360; and startAngle modulo 90 is nearly
   * zero, append oval instead of arc. Otherwise, sweepAngle values are treated
   * modulo 360, and arc may or may not draw depending on numeric rounding.
   * - Parameter oval:        bounds of ellipse containing arc
   * - Parameter startAngle:  starting angle of arc in degrees
   * - Parameter sweepAngle  sweep, in degrees. Positive is clockwise; treated modulo 360
   */
  @discardableResult func addArc(_ rect: SkRect, startAngle: Float, sweepAngle: Float) -> Self {
    withUnsafePointer(to: rect) {
      sk_pathbuilder_add_arc(handle, $0, startAngle, sweepAngle)
    }
    return self
  }

  @discardableResult func addCircle(x: Float, y: Float, radius: Float, direction: Direction = .clockwise) -> Self {
    sk_pathbuilder_add_circle(handle, x, y, radius, direction.native())
    return self
  }

  @discardableResult func add(polygon points: [SkPoint], close: Bool = true) -> Self {
    var p = points
    sk_pathbuilder_add_polygon(handle, &p, Int32(p.count), close)
    return self
  }

  @discardableResult func add(path: Path) -> Self {
    sk_pathbuilder_add_path(handle, path.handle)
    return self
  }
}
