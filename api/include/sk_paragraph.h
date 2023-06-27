#ifndef sk_paragraph_DEFINED
#define sk_paragraph_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD
// https://github.com/skia4delphi/skia/blob/main/sk4d/modules/skparagraph/include/sk4d_paragraph.h

SK_C_API void sk_paragraph_destroy(sk_paragraph_t *self);
SK_C_API bool sk_paragraph_did_exceed_max_lines(sk_paragraph_t *self);
SK_C_API float sk_paragraph_get_alphabetic_baseline(sk_paragraph_t *self);
SK_C_API float sk_paragraph_get_height(sk_paragraph_t *self);
SK_C_API float sk_paragraph_get_ideographic_baseline(sk_paragraph_t *self);
SK_C_API float sk_paragraph_get_longest_line(sk_paragraph_t *self);
SK_C_API float sk_paragraph_get_max_intrinsic_width(sk_paragraph_t *self);
SK_C_API float sk_paragraph_get_max_width(sk_paragraph_t *self);
SK_C_API float sk_paragraph_get_min_intrinsic_width(sk_paragraph_t *self);
SK_C_API void sk_paragraph_get_word_boundary(sk_paragraph_t *self, uint32_t offset, /*out*/ uint32_t *start, /*out*/ uint32_t *end);
SK_C_API void sk_paragraph_layout(sk_paragraph_t *self, float width);
SK_C_API void sk_paragraph_paint(sk_paragraph_t *self, sk_canvas_t *canvas, float x, float y);

SK_C_PLUS_PLUS_END_GUARD
#endif
