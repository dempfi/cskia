import CSkia

public enum TextDirection: UInt32 {
  case rtl,
       ltr

  func native() -> sk_textdirection_t {
    sk_textdirection_t(rawValue: rawValue)
  }

  public init(_ native: sk_textdirection_t) {
    self.init(rawValue: native.rawValue)!
  }
}
