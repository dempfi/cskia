#ifndef sk_paint_DEFINED
#define sk_paint_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_paint_t *sk_paint_new(void);
SK_C_API void sk_paint_delete(sk_paint_t *paint);
SK_C_API void sk_paint_reset(sk_paint_t *paint);
SK_C_API bool sk_paint_is_antialias(const sk_paint_t *paint);
SK_C_API void sk_paint_set_antialias(sk_paint_t *paint, bool);
SK_C_API sk_color_t sk_paint_get_color(const sk_paint_t *paint);
SK_C_API void sk_paint_set_color(sk_paint_t *paint, sk_color_t);
SK_C_API sk_paint_style_t sk_paint_get_style(const sk_paint_t *paint);
SK_C_API void sk_paint_set_style(sk_paint_t *paint, sk_paint_style_t);
SK_C_API float sk_paint_get_stroke_width(const sk_paint_t *paint);
SK_C_API void sk_paint_set_stroke_width(sk_paint_t *paint, float width);
SK_C_API float sk_paint_get_stroke_miter(const sk_paint_t *paint);
SK_C_API void sk_paint_set_stroke_miter(sk_paint_t *paint, float miter);
SK_C_API sk_stroke_cap_t sk_paint_get_stroke_cap(const sk_paint_t *paint);
SK_C_API void sk_paint_set_stroke_cap(sk_paint_t *paint, sk_stroke_cap_t);
SK_C_API sk_stroke_join_t sk_paint_get_stroke_join(const sk_paint_t *paint);
SK_C_API void sk_paint_set_stroke_join(sk_paint_t *paint, sk_stroke_join_t);
SK_C_API bool sk_paint_is_dither(const sk_paint_t *paint);
SK_C_API void sk_paint_set_dither(sk_paint_t *paint, bool);
void sk_paint_set_path_effect(sk_paint_t *paint, sk_path_effect_t *effect);
sk_path_effect_t *sk_paint_get_path_effect(sk_paint_t *paint);

SK_C_PLUS_PLUS_END_GUARD
#endif
