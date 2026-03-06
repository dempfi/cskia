#ifndef sk_paragraphstyle_DEFINED
#define sk_paragraphstyle_DEFINED

#include "sk_paragraph_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_paragraphstyle_t* sk_paragraphstyle_create(void);
SK_C_API void sk_paragraphstyle_destroy(sk_paragraphstyle_t* self);
SK_C_API void sk_paragraphstyle_disable_hinting(sk_paragraphstyle_t* self);
SK_C_API sk_string_t* sk_paragraphstyle_get_ellipsis(const sk_paragraphstyle_t* self);
SK_C_API float sk_paragraphstyle_get_height(const sk_paragraphstyle_t* self);
SK_C_API size_t sk_paragraphstyle_get_max_lines(const sk_paragraphstyle_t* self);
SK_C_API const sk_strutstyle_t* sk_paragraphstyle_get_strut_style(const sk_paragraphstyle_t* self);
SK_C_API sk_textalign_t sk_paragraphstyle_get_text_align(const sk_paragraphstyle_t* self);
SK_C_API sk_textdirection_t sk_paragraphstyle_get_text_direction(const sk_paragraphstyle_t* self);
SK_C_API uint32_t sk_paragraphstyle_get_text_height_behaviors(const sk_paragraphstyle_t* self);
SK_C_API const sk_textstyle_t* sk_paragraphstyle_get_text_style(const sk_paragraphstyle_t* self);
SK_C_API void sk_paragraphstyle_set_ellipsis(sk_paragraphstyle_t* self, const char value[]);
SK_C_API void sk_paragraphstyle_set_height(sk_paragraphstyle_t* self, float value);
SK_C_API void sk_paragraphstyle_set_max_lines(sk_paragraphstyle_t* self, size_t value);
SK_C_API void sk_paragraphstyle_set_strut_style(sk_paragraphstyle_t* self, const sk_strutstyle_t* value);
SK_C_API void sk_paragraphstyle_set_text_align(sk_paragraphstyle_t* self, sk_textalign_t value);
SK_C_API void sk_paragraphstyle_set_text_direction(sk_paragraphstyle_t* self, sk_textdirection_t value);
SK_C_API void sk_paragraphstyle_set_text_height_behaviors(sk_paragraphstyle_t* self, uint32_t value);
SK_C_API void sk_paragraphstyle_set_text_style(sk_paragraphstyle_t* self, sk_textstyle_t* value);
SK_C_API sk_strutstyle_t* sk_strutstyle_create(void);
SK_C_API void sk_strutstyle_destroy(sk_strutstyle_t* self);
SK_C_API bool sk_strutstyle_get_enabled(const sk_strutstyle_t* self);
SK_C_API size_t sk_strutstyle_get_font_families(const sk_strutstyle_t* self, const char* result[]);
SK_C_API float sk_strutstyle_get_font_size(const sk_strutstyle_t* self);
SK_C_API void sk_strutstyle_get_font_style(const sk_strutstyle_t* self, /*out*/ sk_fontstyle_t* result);
SK_C_API bool sk_strutstyle_get_force_height(const sk_strutstyle_t* self);
SK_C_API bool sk_strutstyle_get_half_leading(const sk_strutstyle_t* self);
SK_C_API float sk_strutstyle_get_height_multiplier(const sk_strutstyle_t* self);
SK_C_API float sk_strutstyle_get_leading(const sk_strutstyle_t* self);
SK_C_API bool sk_strutstyle_is_equal(const sk_strutstyle_t* self, const sk_strutstyle_t* strut_style);
SK_C_API void sk_strutstyle_set_enabled(sk_strutstyle_t* self, bool value);
SK_C_API void sk_strutstyle_set_font_families(sk_strutstyle_t* self, const char* values[], size_t count);
SK_C_API void sk_strutstyle_set_font_size(sk_strutstyle_t* self, float value);
SK_C_API void sk_strutstyle_set_font_style(sk_strutstyle_t* self, sk_fontstyle_t* value);
SK_C_API void sk_strutstyle_set_force_height(sk_strutstyle_t* self, bool value);
SK_C_API void sk_strutstyle_set_half_leading(sk_strutstyle_t* self, bool value);
SK_C_API void sk_strutstyle_set_height_multiplier(sk_strutstyle_t* self, float value);
SK_C_API void sk_strutstyle_set_leading(sk_strutstyle_t* self, float value);

SK_C_PLUS_PLUS_END_GUARD
#endif
