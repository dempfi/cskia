import CSkia

public extension Paragraph {
  struct Placeholder {
    public let width: Float
    public let height: Float
    public let alignment: Alignment
    public let baseline: TextBaseline
    public let baselineOffset: Float

    init(width: Float, height: Float, alignment: Alignment, baseline: TextBaseline = .alphabetic, baselineOffset: Float = 0) {
      self.width = width
      self.height = height
      self.alignment = alignment
      self.baseline = baseline
      self.baselineOffset = baselineOffset
    }

    init(_ native: sk_placeholderstyle_t) {
      width = native.width
      height = native.height
      alignment = Alignment(native.alignment)
      baseline = TextBaseline(native.baseline)
      baselineOffset = native.baseline_offset
    }

    func native() -> sk_placeholderstyle_t {
      sk_placeholderstyle_t(width: width, height: height, alignment: alignment.native(), baseline: baseline.native(), baseline_offset: baselineOffset)
    }
  }
}

public extension Paragraph.Placeholder {
  enum Alignment: UInt32 {
    case baseline = 0,
         aboveBaseline,
         belowBaseline,
         top,
         bottom,
         middle

    func native() -> sk_placeholderalignment_t {
      sk_placeholderalignment_t(rawValue: rawValue)
    }

    init(_ x: sk_placeholderalignment_t) {
      self.init(rawValue: x.rawValue)!
    }
  }
}
