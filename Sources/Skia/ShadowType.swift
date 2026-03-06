import CSkia

public enum ShadowType: UInt32 {
  case no = 0x00
  /** The occluding object is not opaque. Knowing that the occluder is opaque allows
   * us to cull shadow geometry behind it and improve performance. */
  case transparentOccluder = 0x01
  /** Don't try to use analytic shadows. */
  case geometricOnly = 0x02
  /** Light position represents a direction, light radius is blur radius at elevation 1 */
  case directionalLight = 0x04
  /** Concave paths will only use blur to generate the shadow */
  case concaveBlurOnly = 0x08
  /** mask for all shadow flags */
  case all = 0x0F

  func native() -> sk_shadowflags_t {
    sk_shadowflags_t(rawValue)
  }

  init(_ x: sk_shadowflags_t) {
    self.init(rawValue: x.rawValue)!
  }
}
