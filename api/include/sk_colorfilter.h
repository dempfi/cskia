#ifndef sk_colorfilter_DEFINED
#define sk_colorfilter_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_colorfilter_t* sk_colorfilter_make_blend(sk_color_t color, sk_blendmode_t mode);
SK_C_API sk_colorfilter_t* sk_colorfilter_make_blend2(const sk_color4f_t* color, sk_colorspace_t* color_space, sk_blendmode_t mode);
SK_C_API sk_colorfilter_t* sk_colorfilter_make_compose(sk_colorfilter_t* outer, sk_colorfilter_t* inner);
SK_C_API sk_colorfilter_t* sk_colorfilter_make_high_contrast(const sk_highcontrastconfig_t* config);
SK_C_API sk_colorfilter_t* sk_colorfilter_make_hsla_matrix(const sk_colormatrix_t* matrix);
SK_C_API sk_colorfilter_t* sk_colorfilter_make_lighting(sk_color_t multiply, sk_color_t add);
SK_C_API sk_colorfilter_t* sk_colorfilter_make_linear_to_srgb_gamma(void);
SK_C_API sk_colorfilter_t* sk_colorfilter_make_luma_color(void);
SK_C_API sk_colorfilter_t* sk_colorfilter_make_matrix(const sk_colormatrix_t* matrix);
SK_C_API sk_colorfilter_t* sk_colorfilter_make_overdraw(const sk_color_t* colors);
SK_C_API sk_colorfilter_t* sk_colorfilter_make_table(const uint8_t* tablea_a, const uint8_t* tablea_r, const uint8_t* tablea_g, const uint8_t* tablea_b);

SK_C_PLUS_PLUS_END_GUARD
#endif
