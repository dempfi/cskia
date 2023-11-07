#ifndef sk_paint_DEFINED
#define sk_paint_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_paint_t* sk_paint_create(void);
SK_C_API sk_paint_t* sk_paint_create2(const sk_paint_t* paint);
SK_C_API void sk_paint_destroy(sk_paint_t* self);
SK_C_API uint8_t sk_paint_get_alpha(const sk_paint_t* self);
SK_C_API float sk_paint_get_alphaf(const sk_paint_t* self);
SK_C_API bool sk_paint_get_antialias(const sk_paint_t* self);
SK_C_API sk_blender_t* sk_paint_get_blender(const sk_paint_t* self);
SK_C_API sk_color_t sk_paint_get_color(const sk_paint_t* self);
SK_C_API void sk_paint_get_colorf(const sk_paint_t* self, /*out*/ sk_color4f_t* result);
SK_C_API sk_colorfilter_t* sk_paint_get_color_filter(const sk_paint_t* self);
SK_C_API bool sk_paint_get_dither(const sk_paint_t* self);
SK_C_API sk_path_t* sk_paint_get_fill_path(const sk_paint_t* self, const sk_path_t* path, const sk_rect_t* cull_rect, float res_scale);
SK_C_API sk_imagefilter_t* sk_paint_get_image_filter(const sk_paint_t* self);
SK_C_API sk_maskfilter_t* sk_paint_get_mask_filter(const sk_paint_t* self);
SK_C_API sk_patheffect_t* sk_paint_get_path_effect(const sk_paint_t* self);
SK_C_API sk_shader_t* sk_paint_get_shader(const sk_paint_t* self);
SK_C_API sk_strokecap_t sk_paint_get_stroke_cap(const sk_paint_t* self);
SK_C_API sk_strokejoin_t sk_paint_get_stroke_join(const sk_paint_t* self);
SK_C_API float sk_paint_get_stroke_miter(const sk_paint_t* self);
SK_C_API float sk_paint_get_stroke_width(const sk_paint_t* self);
SK_C_API sk_paintstyle_t sk_paint_get_style(const sk_paint_t* self);
SK_C_API void sk_paint_reset(sk_paint_t* self);
SK_C_API void sk_paint_set_alpha(sk_paint_t* self, uint8_t value);
SK_C_API void sk_paint_set_alphaf(sk_paint_t* self, float value);
SK_C_API void sk_paint_set_antialias(sk_paint_t* self, bool value);
SK_C_API void sk_paint_set_argb(sk_paint_t* self, uint8_t a, uint8_t r, uint8_t g, uint8_t b);
SK_C_API void sk_paint_set_blender(sk_paint_t* self, sk_blender_t* value);
SK_C_API void sk_paint_set_color(sk_paint_t* self, sk_color_t value);
SK_C_API void sk_paint_set_colorf(sk_paint_t* self, const sk_color4f_t* value, sk_colorspace_t* color_space);
SK_C_API void sk_paint_set_color_filter(sk_paint_t* self, sk_colorfilter_t* value);
SK_C_API void sk_paint_set_dither(sk_paint_t* self, bool value);
SK_C_API void sk_paint_set_image_filter(sk_paint_t* self, sk_imagefilter_t* value);
SK_C_API void sk_paint_set_mask_filter(sk_paint_t* self, sk_maskfilter_t* value);
SK_C_API void sk_paint_set_path_effect(sk_paint_t* self, sk_patheffect_t* value);
SK_C_API void sk_paint_set_shader(sk_paint_t* self, sk_shader_t* value);
SK_C_API void sk_paint_set_stroke_cap(sk_paint_t* self, sk_strokecap_t value);
SK_C_API void sk_paint_set_stroke_join(sk_paint_t* self, sk_strokejoin_t value);
SK_C_API void sk_paint_set_stroke_miter(sk_paint_t* self, float value);
SK_C_API void sk_paint_set_stroke_width(sk_paint_t* self, float value);
SK_C_API void sk_paint_set_style(sk_paint_t* self, sk_paintstyle_t value);

SK_C_PLUS_PLUS_END_GUARD
#endif
