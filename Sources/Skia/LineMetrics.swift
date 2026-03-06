import CSkia

public struct LineMetrics {
  public let startIndex: Int
  public let endIndex: Int
  public let endExcludingWhitespaces: Int
  public let endIncludingNewline: Int
  public let hardBreak: Bool
  public let ascent: Double
  public let descent: Double
  public let baseline: Double
  public let lineNumber: Int
  public let rect: SkRect

  @inline(__always) init(_ native: sk_metrics_t, _ y: Float) {
    rect = SkRect(x: Float(native.left), y: Float(y), width: Float(native.width), height: Float(native.height))
    startIndex = native.start_index
    endIndex = native.end_index
    endExcludingWhitespaces = native.end_excluding_whitespaces
    endIncludingNewline = native.end_including_newline
    hardBreak = native.is_hard_break
    ascent = native.ascent
    descent = native.descent
    baseline = native.baseline
    lineNumber = native.line_number
  }
}
