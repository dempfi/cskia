import CSkia

final class SKString {
  var handle: OpaquePointer

  init(str: String) {
    handle = sk_string_create_text(str, str.utf8CString.count)
  }

  init() {
    handle = sk_string_create()
  }

  public func string() -> String {
    String(cString: sk_string_get_text(handle))
  }

  deinit {
    sk_string_destroy(handle)
  }
}
