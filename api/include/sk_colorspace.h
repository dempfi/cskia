#ifndef sk_colorspace_DEFINED
#define sk_colorspace_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_colorspace_t *sk_colorspace_new_p3(void);
SK_C_API sk_colorspace_t *sk_colorspace_new_srgb(void);
SK_C_API void sk_colorspace_unref(sk_colorspace_t *colorspace);

SK_C_PLUS_PLUS_END_GUARD
#endif
