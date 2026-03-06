import CSkia

public class Paragraph {
  let handle: OpaquePointer!

  init(handle: OpaquePointer!) {
    self.handle = handle
  }

  public init(text: String, style: Style, textStyle: TextStyle) {
    handle = Builder(style).push(textStyle).add(text).build()
  }

  deinit {
    sk_paragraph_destroy(handle)
  }

  public var maxWidth: Float {
    sk_paragraph_get_max_width(handle)
  }

  public var minIntrinsicWidth: Float {
    sk_paragraph_get_min_intrinsic_width(handle)
  }

  public var maxIntrinsicWidth: Float {
    sk_paragraph_get_max_intrinsic_width(handle)
  }

  public var height: Float {
    sk_paragraph_get_height(handle)
  }

  public var lines: Int {
    sk_paragraph_get_line_number(handle)
  }

  public func lineMetrics() -> [LineMetrics] {
    let count = sk_paragraph_get_line_metrics(handle, nil)
    guard count > 0 else { return [] }

    let resultArray = UnsafeMutablePointer<sk_metrics_t>.allocate(capacity: Int(count))
    defer { resultArray.deallocate() }

    _ = sk_paragraph_get_line_metrics(handle, resultArray)
    let natives = Array(UnsafeBufferPointer(start: resultArray, count: Int(count)))
    return natives.reduce(into: [LineMetrics]()) { $0.append(LineMetrics($1, $0.last?.rect.bottom ?? 0)) }
  }

  @discardableResult public func layout(to width: Float) -> Self {
    sk_paragraph_layout(handle, width)
    return self
  }

  @discardableResult public func paint(in canvas: Canvas, x: Float, y: Float) -> Self {
    sk_paragraph_paint(handle, canvas.handle, x, y)
    return self
  }

  public func placeholders() -> [TextBox] {
    let count = sk_paragraph_get_rects_for_placeholders(handle, nil)
    guard count > 0 else { return [] }

    let resultArray = UnsafeMutablePointer<sk_textbox_t>.allocate(capacity: Int(count))
    defer { resultArray.deallocate() }

    _ = sk_paragraph_get_rects_for_placeholders(handle, resultArray)
    return Array(UnsafeBufferPointer(start: resultArray, count: Int(count))).map(TextBox.init(_:))
  }

  /// Get text boxes of the glyphs in the given range, range is inclusive
  public func rects(range: ClosedRange<Int>, heightStyle: RectHeightStyle = .tight, widthStyle: RectWidthStyle = .tight) -> [TextBox] {
    let count = sk_paragraph_get_rects_for_range(handle, UInt32(range.lowerBound), UInt32(range.upperBound + 1), heightStyle.native(), widthStyle.native(), nil)
    guard count > 0 else { return [] }

    let resultArray = UnsafeMutablePointer<sk_textbox_t>.allocate(capacity: Int(count))
    defer { resultArray.deallocate() }

    _ = sk_paragraph_get_rects_for_range(handle, UInt32(range.lowerBound), UInt32(range.upperBound + 1), heightStyle.native(), widthStyle.native(), resultArray)
    return Array(UnsafeBufferPointer(start: resultArray, count: Int(count))).map(TextBox.init(_:))
  }
}

public extension Paragraph {
  enum RectHeightStyle: UInt32 {
    case tight,
         max,
         withMiddleLineSpacing,
         withTopLineSpacing,
         withBottomLineSpacing,
         strut

    func native() -> sk_rectheightstyle_t {
      sk_rectheightstyle_t(rawValue)
    }

    init(_ native: sk_rectheightstyle_t) {
      self.init(rawValue: native.rawValue)!
    }
  }

  enum RectWidthStyle: UInt32 {
    case tight,
         max

    func native() -> sk_rectwidthstyle_t {
      sk_rectwidthstyle_t(rawValue)
    }

    init(_ native: sk_rectwidthstyle_t) {
      self.init(rawValue: native.rawValue)!
    }
  }
}
