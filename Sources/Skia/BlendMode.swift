import CSkia

public enum BlendMode: UInt32 {
  case clear
  case src
  case dest
  case srcOver
  case destOver
  case srcIn
  case destIn
  case srcOut
  case destOut
  case srcATop
  case destATop
  case xor
  case plus
  case modulate
  case screen
  case overlay
  case darken
  case lighten
  case colorDodge
  case colorBurn
  case hardLight
  case softLight
  case difference
  case exclusion
  case multiply
  case hue
  case saturation
  case color
  case luminosity

  func native() -> sk_blendmode_t {
    sk_blendmode_t(rawValue)
  }

  init(_ native: sk_blendmode_t) {
    self.init(rawValue: native.rawValue)!
  }
}
