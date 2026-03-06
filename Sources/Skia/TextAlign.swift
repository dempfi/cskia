import CSkia

public enum TextAlign: UInt32 {
  case left = 0
  case right
  case center
  case justify
  case start
  case terminate

  func native() -> sk_textalign_t {
    sk_textalign_t.init(rawValue)
  }

  init(_ x: sk_textalign_t) {
    self.init(rawValue: x.rawValue)!
  }
}
