#include "include/sk_string.h"

#include "sk_mapping.h"

sk_string_t* sk_string_create(void) {
  return ToString(new SkString());
}

sk_string_t* sk_string_create_text(const char* src, size_t length) {
  return ToString(new SkString(src, length));
}

void sk_string_destroy(sk_string_t* self) {
  delete AsString(self);
}

const char* sk_string_get_text(const sk_string_t* self) {
  return AsString(self)->c_str();
}
