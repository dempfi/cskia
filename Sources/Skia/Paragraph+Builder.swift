import CSkia

public extension Paragraph {
  class Builder {
    let handle: OpaquePointer!

    public init(_ style: Style) {
      handle = sk_paragraphbuilder_create(style.handle)
    }

    deinit {
      sk_paragraphbuilder_destroy(handle)
    }
  }
}

public extension Paragraph.Builder {
  convenience init(
    textAlign: TextAlign? = nil,
    maxLines: Int? = nil,
    fontFamily: String? = nil,
    fontSize: Float? = nil,
    height: Float? = nil,
    fontStyle: FontStyle? = nil,
    ellipsis: String? = nil,
    locale: String? = nil
  ) {
    self.init(Paragraph.Style(
      textAlign: textAlign,
      maxLines: maxLines,
      fontFamily: fontFamily,
      fontSize: fontSize,
      height: height,
      fontStyle: fontStyle,
      ellipsis: ellipsis,
      locale: locale
    ))
  }

  @discardableResult func add(_ text: String) -> Self {
    sk_paragraphbuilder_add_text(handle, text.cString(using: .utf8))
    return self
  }

  @discardableResult func add(placeholder: Paragraph.Placeholder) -> Self {
    withUnsafePointer(to: placeholder.native()) { pointer in
      sk_paragraphbuilder_add_placeholder(handle, pointer)
    }
    return self
  }

  @discardableResult func add(width: Float, height: Float, alignment: Paragraph.Placeholder.Alignment = .baseline, baseline: TextBaseline = .alphabetic, baselineOffset: Float = 0) -> Self {
    let placeholder = sk_placeholderstyle_t(width: width, height: height, alignment: alignment.native(), baseline: baseline.native(), baseline_offset: baselineOffset)
    withUnsafePointer(to: placeholder) { pointer in
      sk_paragraphbuilder_add_placeholder(handle, pointer)
    }
    return self
  }

  @discardableResult func push(_ style: TextStyle) -> Self {
    sk_paragraphbuilder_push_style(handle, style.handle)
    return self
  }

  @discardableResult func push(
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
  ) -> Self {
    push(TextStyle(
      color: color,
      decoration: decoration,
      decorationColor: decorationColor,
      decorationStyle: decorationStyle,
      decorationThickness: decorationThickness,
      fontStyle: fontStyle,
      fontFamily: fontFamily,
      fontFamilyFallback: fontFamilyFallback,
      fontSize: fontSize,
      letterSpacing: letterSpacing,
      wordSpacing: wordSpacing,
      height: height,
      locale: locale,
      background: background,
      foreground: foreground,
      shadows: shadows
    ))
  }

  @discardableResult func pop() -> Self {
    sk_paragraphbuilder_pop(handle)
    return self
  }

  @discardableResult func build() -> Paragraph {
    Paragraph(handle: build())
  }

  internal func build() -> OpaquePointer {
    sk_paragraphbuilder_build(handle)
  }
}
