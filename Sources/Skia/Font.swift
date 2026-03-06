import CSkia

public final class Font {
  public typealias Edging = sk_fontedging_t
  public typealias Hinting = sk_fonthinting_t

  var handle: OpaquePointer
  var owns: Bool

  init(handle: OpaquePointer, owns: Bool) {
    self.handle = handle
    self.owns = owns
  }

  public init(typeface: Typeface, size: Float, scaleX: Float, skewX: Float) {
    handle = sk_font_create(typeface.handle, size, scaleX, skewX)
    owns = true
  }

  deinit {
    sk_font_destroy(handle)
  }

  public var subpixel: Bool {
    get { sk_font_get_subpixel(handle) }
    set { sk_font_set_subpixel(handle, newValue) }
  }

  public var forceAutoHinting: Bool {
    get { sk_font_get_force_auto_hinting(handle) }
    set { sk_font_set_force_auto_hinting(handle, newValue) }
  }

  public var embeddedBitmaps: Bool {
    get { sk_font_get_embedded_bitmaps(handle) }
    set { sk_font_set_embedded_bitmaps(handle, newValue) }
  }

  public var isLinearMetrics: Bool {
    get { sk_font_get_linear_metrics(handle) }
    set { sk_font_set_linear_metrics(handle, newValue) }
  }

  public var embolden: Bool {
    get { sk_font_get_embolden(handle) }
    set { sk_font_set_embolden(handle, newValue) }
  }

  public var baselineSnap: Bool {
    get { sk_font_get_baseline_snap(handle) }
    set { sk_font_set_baseline_snap(handle, newValue) }
  }

  public var edging: Edging {
    get { sk_font_get_edging(handle) }
    set { sk_font_set_edging(handle, newValue) }
  }

  public var fontHinting: Hinting {
    get { sk_font_get_hinting(handle) }
    set { sk_font_set_hinting(handle, newValue) }
  }

  public var typeface: Typeface {
    get { Typeface(handle: sk_font_get_typeface(handle), owns: true) }
    set { sk_font_set_typeface(handle, newValue.handle) }
  }

  public var size: Float {
    get { sk_font_get_size(handle) }
    set { sk_font_set_size(handle, newValue) }
  }

  public var scaleX: Float {
    get { sk_font_get_scale_x(handle) }
    set { sk_font_set_scale_x(handle, newValue) }
  }

  public var skewX: Float {
    get { sk_font_get_skew_x(handle) }
    set { sk_font_set_skew_x(handle, newValue) }
  }

  /// Retrieve the corresponding glyph IDs of a string of characters.
  /// - Returns: the array of glyphs, or nil if there is an error
  public func getGlyphs(str: String) -> [UInt16]? {
    let utflen = str.utf8.count
    let nglyphs = sk_font_get_glyphs(handle, str, utflen, UTF8_SK_TEXTENCODING, nil, Int32(utflen))
    if nglyphs <= 0 {
      return nil
    }
    var glyphs = [UInt16](repeating: 0, count: Int(nglyphs))
    sk_font_get_glyphs(handle, str, utflen, UTF8_SK_TEXTENCODING, &glyphs, nglyphs)
    return glyphs
  }

  /// The number of glyphs necessary to render this string with this font
  public func countGlyphs(str: String) -> Int32 {
    let utflen = str.utf8.count
    return sk_font_get_glyphs(handle, str, utflen, UTF8_SK_TEXTENCODING, nil, Int32(utflen))
  }

  public func getGlyphPositions(glyphs: inout [UInt16], origin: SkPoint = SkPoint(x: 0, y: 0)) -> [SkPoint] {
    var positions: [SkPoint] = Array(repeating: SkPoint(x: 0, y: 0), count: glyphs.count)
    var o = origin
    sk_font_get_positions(handle, &glyphs, Int32(glyphs.count), &positions, &o)
    return positions
  }

  public func measure(width string: String, paint: Paint? = nil) -> Float {
    sk_font_measure_text(handle, string, string.utf8.count, UTF8_SK_TEXTENCODING, nil, paint?.handle)
  }

  public func measure(bounds string: String, paint: Paint? = nil) -> SkRect {
    var rect = SkRect()
    sk_font_measure_text(handle, string, string.utf8.count, UTF8_SK_TEXTENCODING, &rect, paint?.handle)
    return rect
  }
}
