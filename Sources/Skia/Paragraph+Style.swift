import CSkia

public extension Paragraph {
  class Style {
    let handle: OpaquePointer!

    public init() {
      handle = sk_paragraphstyle_create()
    }

    deinit {
      sk_paragraphstyle_destroy(handle)
    }
  }
}

public extension Paragraph.Style {
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
    self.init()
    if let textAlign {
      self.textAlign = textAlign
    }

    if let maxLines {
      self.maxLines = maxLines
    }

    if let fontFamily {
      let textStyle = textStyle
      textStyle.fontFamilies = [fontFamily]
      self.textStyle = textStyle
    }

    if let fontSize {
      let textStyle = textStyle
      textStyle.fontSize = fontSize
      self.textStyle = textStyle
    }

    if let height {
      self.height = height
    }

    if let fontStyle {
      let textStyle = textStyle
      textStyle.fontStyle = fontStyle
      self.textStyle = textStyle
    }

    if let ellipsis {
      self.ellipsis = ellipsis
    }

    if let locale {
      let textStyle = textStyle
      textStyle.locale = locale
      self.textStyle = textStyle
    }
  }

  var height: Float {
    get { sk_paragraphstyle_get_height(handle) }
    set { sk_paragraphstyle_set_height(handle, newValue) }
  }

  var textAlign: TextAlign {
    get { TextAlign(sk_paragraphstyle_get_text_align(handle)) }
    set { sk_paragraphstyle_set_text_align(handle, newValue.native()) }
  }

  var ellipsis: String {
    get { String(cString: sk_string_get_text(sk_paragraphstyle_get_ellipsis(handle))) }
    set { sk_paragraphstyle_set_ellipsis(handle, newValue.cString(using: .utf8)) }
  }

  var textStyle: TextStyle {
    get { TextStyle(handle: sk_paragraphstyle_get_text_style(handle)) }
    set { sk_paragraphstyle_set_text_style(handle, newValue.handle) }
  }

  var maxLines: Int {
    get { sk_paragraphstyle_get_max_lines(handle) }
    set { sk_paragraphstyle_set_max_lines(handle, newValue) }
  }

  func disableHinting() {
    sk_paragraphstyle_disable_hinting(handle)
  }
}
