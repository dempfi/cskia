import CSkia

public class TextStyle {
  let handle: OpaquePointer

  public init() {
    handle = sk_textstyle_create()
  }

  public convenience init(
    color: SkColor? = nil,
    decoration: TextDecoration? = nil,
    decorationColor: SkColor? = nil,
    decorationStyle: TextDecoration.Style? = nil,
    decorationThickness: Float? = nil,
    fontStyle: FontStyle? = nil,
    fontFamily: String? = nil,
    fontFamilyFallback: [String]? = nil,
    fontSize: Float? = nil,
    letterSpacing: Float? = nil,
    wordSpacing: Float? = nil,
    height: Float? = nil,
    locale: String? = nil,
    background: Paint? = nil,
    foreground: Paint? = nil,
    shadows: [TextShadow]? = nil
  ) {
    self.init()
    if let color {
      self.color = color
    }

    if let decoration {
      self.decoration = decoration
    }

    if let decorationColor {
      self.decorationColor = decorationColor
    }

    if let decorationStyle {
      self.decorationStyle = decorationStyle
    }

    if let decorationThickness {
      self.decorationThickness = decorationThickness
    }

    if let fontStyle {
      self.fontStyle = fontStyle
    }

    if fontFamily != nil || fontFamilyFallback != nil {
      fontFamilies = (fontFamily != nil ? [fontFamily!] : []) + (fontFamilyFallback ?? [])
    }

    if let fontSize {
      self.fontSize = fontSize
    }

    if let letterSpacing {
      self.letterSpacing = letterSpacing
    }

    if let wordSpacing {
      self.wordSpacing = wordSpacing
    }

    if let height {
      self.height = height
    }

    if let locale {
      self.locale = locale
    }

    if let background {
      self.background = background
    }

    if let foreground {
      self.foreground = foreground
    }

    if let shadows {
      shadows.forEach(add(shadow:))
    }
  }

  init(handle: OpaquePointer) {
    self.handle = handle
  }

  deinit {
    sk_textstyle_destroy(handle)
  }

  public var color: SkColor {
    get { sk_textstyle_get_color(handle) }
    set { sk_textstyle_set_color(handle, newValue) }
  }

  public var fontSize: Float {
    get { sk_textstyle_get_font_size(handle) }
    set { sk_textstyle_set_font_size(handle, newValue) }
  }

  public var fontStyle: FontStyle {
    get {
      var style = sk_fontstyle_t()
      sk_textstyle_get_font_style(handle, &style)
      return FontStyle(style)
    }
    set {
      withUnsafePointer(to: newValue.native()) {
        sk_textstyle_set_font_style(handle, $0)
      }
    }
  }

  public var background: Paint? {
    get {
      guard let pointer = sk_textstyle_get_background(handle) else { return nil }
      return Paint(handle: pointer)
    }
    set {
      if let paint = newValue {
        sk_textstyle_set_background_color(handle, paint.handle)
      } else {
        sk_textstyle_clear_background_color(handle)
      }
    }
  }

  public var foreground: Paint? {
    get {
      guard let pointer = sk_textstyle_get_foreground(handle) else { return nil }
      return Paint(handle: pointer)
    }
    set {
      if let paint = newValue {
        sk_textstyle_set_foreground_color(handle, paint.handle)
      } else {
        sk_textstyle_clear_foreground_color(handle)
      }
    }
  }

  public var height: Float {
    get { sk_textstyle_get_height(handle) }
    set { sk_textstyle_set_height(handle, newValue) }
  }

  public var halfLeading: Bool {
    get { sk_textstyle_get_half_leading(handle) }
    set { sk_textstyle_set_half_leading(handle, newValue) }
  }

  public var wordSpacing: Float {
    get { sk_textstyle_get_word_spacing(handle) }
    set { sk_textstyle_set_word_spacing(handle, newValue) }
  }

  public var letterSpacing: Float {
    get { sk_textstyle_get_letter_spacing(handle) }
    set { sk_textstyle_set_letter_spacing(handle, newValue) }
  }

  /// Locales are canonicalized according to the "preferred value" entries in the IANA Language Subtag Registry.
  public var locale: String {
    get { String(cString: sk_string_get_text(sk_textstyle_get_locale(handle))) }
    set { sk_textstyle_set_locale(handle, newValue.cString(using: .utf8)) }
  }

  public var decoration: TextDecoration {
    get { TextDecoration(rawValue: sk_textstyle_get_decorations(handle))! }
    set { sk_textstyle_set_decorations(handle, newValue.rawValue) }
  }

  public var decorationColor: SkColor {
    get { sk_textstyle_get_decoration_color(handle) }
    set { sk_textstyle_set_decoration_color(handle, newValue) }
  }

  public var decorationStyle: TextDecoration.Style {
    get { TextDecoration.Style(sk_textstyle_get_decoration_style(handle)) }
    set { sk_textstyle_set_decoration_style(handle, newValue.native()) }
  }

  public var decorationThickness: Float {
    get { sk_textstyle_get_decoration_thickness(handle) }
    set { sk_textstyle_set_decoration_thickness(handle, newValue) }
  }

  public var fontFamilies: [String] {
    get {
      let count = sk_textstyle_get_font_families(handle, nil)
      var buffer = [UnsafePointer<CChar>?](repeating: nil, count: Int(count))
      _ = sk_textstyle_get_font_families(handle, &buffer)
      var result: [String] = []
      for i in 0 ..< Int(count) {
        if let cString = buffer[i] {
          result.append(String(cString: cString))
        }
      }

      return result
    }

    set {
      var strings = [UnsafePointer<CChar>?]()
      for string in newValue {
        strings.append(strdup(string))
      }

      strings.withUnsafeMutableBufferPointer {
        sk_textstyle_set_font_families(handle, $0.baseAddress, newValue.count)
      }

      for cString in strings {
        free(UnsafeMutablePointer(mutating: cString))
      }
    }
  }

  public func add(shadow: TextShadow) {
    withUnsafePointer(to: shadow) {
      sk_textstyle_add_shadow(handle, $0)
    }
  }

  public func resetShadows() {
    sk_textstyle_reset_shadows(handle)
  }
}

public extension TextStyle {
  static func == (lhs: TextStyle, rhs: TextStyle) -> Bool {
    sk_textstyle_is_equal(lhs.handle, rhs.handle)
  }
}
