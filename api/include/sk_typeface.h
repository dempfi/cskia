#ifndef sk_typeface_DEFINED
#define sk_typeface_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_string_t *sk_typeface_get_family_name(const sk_typeface_t *self);
SK_C_API sk_fontslant_t sk_typeface_get_slant(const sk_typeface_t *self);
SK_C_API void sk_typeface_get_style(const sk_typeface_t *self, /*out*/ sk_fontstyle_t *result);
SK_C_API int32_t sk_typeface_get_weight(const sk_typeface_t *self);
SK_C_API int32_t sk_typeface_get_width(const sk_typeface_t *self);
SK_C_API sk_typeface_t *sk_typeface_make_default(void);
SK_C_API sk_typeface_t *sk_typeface_make_from_file(const char file_name[], int32_t ttc_index);
SK_C_API sk_typeface_t *sk_typeface_make_from_stream(sk_stream_t *stream, int32_t ttc_index);
SK_C_API sk_typeface_t *sk_typeface_make_from_name(const char family_name[], const sk_fontstyle_t *style);

SK_C_PLUS_PLUS_END_GUARD
#endif
