import CSkia

public enum TextDecoration: UInt32 {
  case none = 0x0
  case underline = 0x1
  case overline = 0x2
  case lineThrough = 0x4
}

public extension TextDecoration {
  enum Style: UInt32 {
    case solid = 0
    case double = 1
    case dotted = 2
    case dashed = 3
    case wavy = 4

    func native() -> sk_textdecorationstyle_t {
      sk_textdecorationstyle_t(rawValue: rawValue)
    }

    init(_ x: sk_textdecorationstyle_t) {
      self.init(rawValue: x.rawValue)!
    }
  }
}
