#ifndef sk_fontstyleset_DEFINED
#define sk_fontstyleset_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API void sk_fontstyleset_unref(sk_fontstyleset_t* self);
SK_C_API int32_t sk_fontstyleset_get_count(sk_fontstyleset_t* self);
SK_C_API void sk_fontstyleset_get_style(sk_fontstyleset_t* self, int32_t index, /*out*/ sk_fontstyle_t* style, /*out*/ sk_string_t** name);
SK_C_API sk_typeface_t* sk_fontstyleset_create_typeface(sk_fontstyleset_t* self, int32_t index);
SK_C_API sk_typeface_t* sk_fontstyleset_match_style(sk_fontstyleset_t* self, const sk_fontstyle_t* style);

SK_C_PLUS_PLUS_END_GUARD
#endif
