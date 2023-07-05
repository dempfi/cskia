#ifndef sk_blender_DEFINED
#define sk_blender_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_blender_t *sk_blender_make_arithmetic(float k1, float k2, float k3, float k4, bool enforce_premultiplied_color);
SK_C_API sk_blender_t *sk_blender_make_mode(sk_blendmode_t mode);

SK_C_PLUS_PLUS_END_GUARD
#endif
