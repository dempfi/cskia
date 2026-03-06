import CSkia

public enum TextBaseline: UInt32 {
  case alphabetic
  case ideographic

  func native() -> sk_textbaseline_t {
    sk_textbaseline_t(rawValue: rawValue)
  }

  init(_ x: sk_textbaseline_t) {
    self.init(rawValue: x.rawValue)!
  }
}
