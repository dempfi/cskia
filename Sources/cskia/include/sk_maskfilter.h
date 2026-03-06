#ifndef sk_maskfilter_DEFINED
#define sk_maskfilter_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_maskfilter_t* sk_maskfilter_make_blur(sk_blurstyle_t style, float sigma, bool respect_ctm);
SK_C_API sk_maskfilter_t* sk_maskfilter_make_shader(sk_shader_t* shader);
SK_C_API sk_maskfilter_t* sk_maskfilter_make_table(const uint8_t* table);
SK_C_API sk_maskfilter_t* sk_maskfilter_make_table_clip(uint8_t min, uint8_t max);
SK_C_API sk_maskfilter_t* sk_maskfilter_make_table_gamma(float gamma);

SK_C_PLUS_PLUS_END_GUARD
#endif
