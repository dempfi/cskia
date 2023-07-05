#ifndef sk_font_DEFINED
#define sk_font_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_font_t *sk_font_create(sk_typeface_t *typeface, float size, float sx, float kx);
SK_C_API sk_font_t *sk_font_create2(const sk_font_t *font);
SK_C_API void sk_font_destroy(sk_font_t *self);
SK_C_API bool sk_font_get_baseline_snap(const sk_font_t *self);
SK_C_API sk_fontedging_t sk_font_get_edging(const sk_font_t *self);
SK_C_API bool sk_font_get_embedded_bitmaps(const sk_font_t *self);
SK_C_API bool sk_font_get_embolden(const sk_font_t *self);
SK_C_API bool sk_font_get_force_auto_hinting(const sk_font_t *self);
SK_C_API int32_t sk_font_get_glyphs(const sk_font_t *self, const void *text, size_t size, sk_textencoding_t encoding, sk_glyphid_t result[], int32_t max_count);
SK_C_API int32_t sk_font_get_glyphs_count(const sk_font_t *self, const void *text, size_t size, sk_textencoding_t encoding);
SK_C_API sk_fonthinting_t sk_font_get_hinting(const sk_font_t *self);
SK_C_API void sk_font_get_horizontal_positions(const sk_font_t *self, const sk_glyphid_t glyphs[], int32_t count, float result[], float origin);
SK_C_API size_t sk_font_get_intercepts(const sk_font_t *self, const sk_glyphid_t glyphs[], int32_t count, const sk_point_t positions[], const float bounds[2], float result[], const sk_paint_t *paint);
SK_C_API bool sk_font_get_linear_metrics(const sk_font_t *self);
SK_C_API float sk_font_get_metrics(const sk_font_t *self, sk_fontmetrics_t *metrics);
SK_C_API sk_path_t *sk_font_get_path(const sk_font_t *self, sk_glyphid_t glyph);
SK_C_API void sk_font_get_paths(const sk_font_t *self, const sk_glyphid_t glyphs[], int32_t count, sk_font_path_proc proc, void *proc_context);
SK_C_API void sk_font_get_positions(const sk_font_t *self, const sk_glyphid_t glyphs[], int32_t count, sk_point_t result[], const sk_point_t *origin);
SK_C_API float sk_font_get_scale_x(const sk_font_t *self);
SK_C_API float sk_font_get_size(const sk_font_t *self);
SK_C_API float sk_font_get_skew_x(const sk_font_t *self);
SK_C_API bool sk_font_get_subpixel(const sk_font_t *self);
SK_C_API sk_typeface_t *sk_font_get_typeface(const sk_font_t *self);
SK_C_API sk_typeface_t *sk_font_get_typeface_or_default(const sk_font_t *self);
SK_C_API void sk_font_get_widths_bounds(const sk_font_t *self, const sk_glyphid_t glyphs[], int32_t count, float widths[], sk_rect_t bounds[], const sk_paint_t *paint);
SK_C_API bool sk_font_is_equal(const sk_font_t *self, const sk_font_t *font);
SK_C_API float sk_font_measure_text(const sk_font_t *self, const void *text, size_t size, sk_textencoding_t encoding, sk_rect_t *bounds, const sk_paint_t *paint);
SK_C_API void sk_font_set_baseline_snap(sk_font_t *self, bool value);
SK_C_API void sk_font_set_edging(sk_font_t *self, sk_fontedging_t value);
SK_C_API void sk_font_set_embedded_bitmaps(sk_font_t *self, bool value);
SK_C_API void sk_font_set_embolden(sk_font_t *self, bool value);
SK_C_API void sk_font_set_force_auto_hinting(sk_font_t *self, bool value);
SK_C_API void sk_font_set_hinting(sk_font_t *self, sk_fonthinting_t value);
SK_C_API void sk_font_set_linear_metrics(sk_font_t *self, bool value);
SK_C_API void sk_font_set_scale_x(sk_font_t *self, float value);
SK_C_API void sk_font_set_size(sk_font_t *self, float value);
SK_C_API void sk_font_set_skew_x(sk_font_t *self, float value);
SK_C_API void sk_font_set_subpixel(sk_font_t *self, bool value);
SK_C_API void sk_font_set_typeface(sk_font_t *self, sk_typeface_t *typeface);
SK_C_API sk_glyphid_t sk_font_unichar_to_glyph(const sk_font_t *self, sk_unichar_t unichar);
SK_C_API void sk_font_unichars_to_glyphs(const sk_font_t *self, const sk_unichar_t unichars[], int32_t count, sk_glyphid_t result[]);

SK_C_PLUS_PLUS_END_GUARD
#endif
