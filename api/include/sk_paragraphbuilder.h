#ifndef sk_paragraphbuilder_DEFINED
#define sk_paragraphbuilder_DEFINED

#include "sk_paragraph_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API void sk_paragraphbuilder_add_placeholder(sk_paragraphbuilder_t *self, const sk_placeholderstyle_t *placeholder);
SK_C_API void sk_paragraphbuilder_add_text(sk_paragraphbuilder_t *self, const char text[]);
SK_C_API sk_paragraph_t *sk_paragraphbuilder_build(sk_paragraphbuilder_t *self);
SK_C_API sk_paragraphbuilder_t *sk_paragraphbuilder_create(const sk_paragraphstyle_t *paragraph_style);
SK_C_API sk_paragraphbuilder_t *sk_paragraphbuilder_create2(const sk_paragraphstyle_t *paragraph_style, sk_fontmgr_t *font_provider, bool enable_font_fallback);
SK_C_API void sk_paragraphbuilder_destroy(sk_paragraphbuilder_t *self);
SK_C_API void sk_paragraphbuilder_pop(sk_paragraphbuilder_t *self);
SK_C_API void sk_paragraphbuilder_push_style(sk_paragraphbuilder_t *self, const sk_textstyle_t *text_style);

SK_C_PLUS_PLUS_END_GUARD
#endif
