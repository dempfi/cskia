import CSkia

public struct TextBox {
  public let rect: SkRect
  public let direction: TextDirection

  init(_ native: sk_textbox_t) {
    rect = native.rect
    direction = TextDirection(native.direction)
  }
}
