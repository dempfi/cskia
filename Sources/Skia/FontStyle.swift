import CSkia

/// Represents a particular style (bold, italic, condensed) of a typeface.
public struct FontStyle {
  public static var normal = FontStyle(weight: .normal, width: .normal, slant: .upright)
  public static var bold = FontStyle(weight: .bold, width: .normal, slant: .upright)
  public static var italic = FontStyle(weight: .normal, width: .normal, slant: .italic)
  public static var boldItalic = FontStyle(weight: .bold, width: .normal, slant: .italic)

  public var weight: Weight
  public var width: Width
  public var slant: Slant

  public init() {
    self.init(weight: .normal, width: .normal, slant: .upright)
  }

  public init(weight: Weight, width: Width, slant: Slant) {
    self.weight = weight
    self.width = width
    self.slant = slant
  }

  func native() -> sk_fontstyle_t {
    sk_fontstyle_t(weight: weight.rawValue, width: width.rawValue, slant: slant.native())
  }

  init(_ x: sk_fontstyle_t) {
    self.init(weight: Weight(rawValue: x.weight)!, width: Width(rawValue: x.width)!, slant: Slant(x.slant))
  }
}

public extension FontStyle {
  ///  Refers to the density of a typeface, in terms of the lightness or heaviness of the strokes.
  ///
  ///  A font weight describes the relative weight of a font, in terms of the lightness or heaviness of the strokes.
  ///  Weight differences are generally differentiated by an increased stroke or thickness that is associated with a
  ///  given character in a font, as compared to a "normal" character from that same font.
  ///
  ///  The values correspond to the `usWeightClass` definition in the OpenType specification.
  ///  The `usWeightClass` represents an integer value between 1 and 999.
  ///  Lower values indicate lighter weights; higher values indicate heavier weights.
  enum Weight: Int32 {
    case invisible = 0
    case thin = 100
    case extraLight = 200
    case light = 300
    case normal = 400
    case medium = 500
    case semiBold = 600
    case bold = 700
    case extraBold = 800
    case black = 900
    case extraBlack = 1000
  }

  /// Predefined font widths from the OpenType specification.  These are numbers from 1 to 9,
  /// lower numbers represent narrower widths, higher numbers indicate wider widths.
  enum Width: Int32 {
    /// 50% width of normal
    case ultraCondensed = 1
    /// 62.5% width of normal
    case extraCondensed = 2
    /// 75% width of normal
    case condensed = 3
    /// 87.5% width of normal
    case semiCondensed = 4
    /// 100% width of normal
    case normal = 5
    /// 112.5% width of normal
    case semiExpanded = 6
    /// 125% width of normal
    case expanded = 7
    /// 150% width of normal
    case extraExpanded = 8
    /// 200% width of normal
    case ultraExpanded = 9
  }

  /// Font slants for use with Typeface.
  enum Slant: UInt32 {
    /// The upright/normal font slant.
    case upright = 0
    /// The italic font slant, in which the slanted characters appear as they were designed.
    case italic = 1
    /// The characters in an oblique font are artificially slanted. The slant is achieved by performing a shear
    /// transformation on the characters from a normal font. When a true italic font is not available
    /// on a computer or printer, an oblique style can generated from the normal
    /// font and used to simulate an italic font.
    case oblique = 2

    func native() -> sk_fontslant_t {
      sk_fontslant_t(rawValue: rawValue)
    }

    init(_ x: sk_fontslant_t) {
      self.init(rawValue: x.rawValue)!
    }
  }
}
