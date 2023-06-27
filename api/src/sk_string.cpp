#include "sk_mapping.h"
#include "include/sk_string.h"
#include "include/core/SkString.h"

sk_string_t *sk_string_new_empty(void)
{
  return ToString(new SkString());
};

sk_string_t *sk_string_new_with_copy(const char *src, size_t length)
{
  return ToString(new SkString(src, length));
};

void sk_string_destructor(const sk_string_t *str)
{
  AsString(str)->~SkString();
};

size_t sk_string_get_size(const sk_string_t *str)
{
  return AsString(str)->size();
};

const char *sk_string_get_c_str(const sk_string_t *str)
{
  return AsString(str)->c_str();
};
