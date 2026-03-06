#ifndef sk_textstyle_DEFINED
#define sk_textstyle_DEFINED

#include "sk_paragraph_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API void sk_textstyle_add_font_feature(sk_textstyle_t* self, const char feature[], int32_t value);
SK_C_API void sk_textstyle_add_shadow(sk_textstyle_t* self, const sk_textshadow_t* shadow);
SK_C_API void sk_textstyle_clear_background_color(sk_textstyle_t* self);
SK_C_API void sk_textstyle_clear_foreground_color(sk_textstyle_t* self);
SK_C_API sk_textstyle_t* sk_textstyle_create(void);
SK_C_API void sk_textstyle_destroy(sk_textstyle_t* self);
SK_C_API sk_paint_t* sk_textstyle_get_background(const sk_textstyle_t* self);
SK_C_API sk_color_t sk_textstyle_get_color(const sk_textstyle_t* self);
SK_C_API sk_color_t sk_textstyle_get_decoration_color(const sk_textstyle_t* self);
SK_C_API sk_textdecorationstyle_t sk_textstyle_get_decoration_style(const sk_textstyle_t* self);
SK_C_API float sk_textstyle_get_decoration_thickness(const sk_textstyle_t* self);
SK_C_API uint32_t sk_textstyle_get_decorations(const sk_textstyle_t* self);
SK_C_API size_t sk_textstyle_get_font_families(const sk_textstyle_t* self, const char* result[]);
SK_C_API void sk_textstyle_get_font_metrics(const sk_textstyle_t* self, /*out*/ sk_fontmetrics_t* result);
SK_C_API float sk_textstyle_get_font_size(const sk_textstyle_t* self);
SK_C_API void sk_textstyle_get_font_style(const sk_textstyle_t* self, /*out*/ sk_fontstyle_t* result);
SK_C_API sk_paint_t* sk_textstyle_get_foreground(const sk_textstyle_t* self);
SK_C_API bool sk_textstyle_get_half_leading(const sk_textstyle_t* self);
SK_C_API float sk_textstyle_get_height(const sk_textstyle_t* self);
SK_C_API float sk_textstyle_get_letter_spacing(const sk_textstyle_t* self);
SK_C_API sk_string_t* sk_textstyle_get_locale(const sk_textstyle_t* self);
SK_C_API float sk_textstyle_get_word_spacing(const sk_textstyle_t* self);
SK_C_API bool sk_textstyle_is_equal(const sk_textstyle_t* self, const sk_textstyle_t* text_style);
SK_C_API void sk_textstyle_reset_font_features(sk_textstyle_t* self);
SK_C_API void sk_textstyle_reset_shadows(sk_textstyle_t* self);
SK_C_API void sk_textstyle_set_background_color(sk_textstyle_t* self, sk_paint_t* paint);
SK_C_API void sk_textstyle_set_color(sk_textstyle_t* self, sk_color_t value);
SK_C_API void sk_textstyle_set_decoration_color(sk_textstyle_t* self, sk_color_t value);
SK_C_API void sk_textstyle_set_decoration_style(sk_textstyle_t* self, sk_textdecorationstyle_t value);
SK_C_API void sk_textstyle_set_decoration_thickness(sk_textstyle_t* self, float value);
SK_C_API void sk_textstyle_set_decorations(sk_textstyle_t* self, uint32_t value);
SK_C_API void sk_textstyle_set_font_families(sk_textstyle_t* self, const char* values[], size_t count);
SK_C_API void sk_textstyle_set_font_size(sk_textstyle_t* self, float value);
SK_C_API void sk_textstyle_set_font_style(sk_textstyle_t* self, const sk_fontstyle_t* value);
SK_C_API void sk_textstyle_set_foreground_color(sk_textstyle_t* self, sk_paint_t* paint);
SK_C_API void sk_textstyle_set_half_leading(sk_textstyle_t* self, bool value);
SK_C_API void sk_textstyle_set_height(sk_textstyle_t* self, float value);
SK_C_API void sk_textstyle_set_letter_spacing(sk_textstyle_t* self, float value);
SK_C_API void sk_textstyle_set_locale(sk_textstyle_t* self, const char value[]);
SK_C_API void sk_textstyle_set_word_spacing(sk_textstyle_t* self, float value);

SK_C_PLUS_PLUS_END_GUARD

#endif
