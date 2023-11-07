#ifndef sk_string_DEFINED
#define sk_string_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_string_t* sk_string_create(void);
SK_C_API sk_string_t* sk_string_create_text(const char* src, size_t length);
SK_C_API void sk_string_destroy(sk_string_t* self);
SK_C_API const char* sk_string_get_text(const sk_string_t* self);

SK_C_PLUS_PLUS_END_GUARD
#endif
