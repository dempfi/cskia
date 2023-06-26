#include "include/sk_string.h"
#include "include/core/SkString.h"

sk_string_t *sk_string_new_empty(void)
{
  return reinterpret_cast<sk_string_t *>(new SkString());
};

sk_string_t *sk_string_new_with_copy(const char *src, size_t length)
{
  return reinterpret_cast<sk_string_t *>(new SkString(src, length));
};

void sk_string_destructor(const sk_string_t *str)
{
  reinterpret_cast<const SkString *>(str)->~SkString();
};

size_t sk_string_get_size(const sk_string_t *str)
{
  return reinterpret_cast<const SkString *>(str)->size();
};

const char *sk_string_get_c_str(const sk_string_t *str)
{
  return reinterpret_cast<const SkString *>(str)->c_str();
};
