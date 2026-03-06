#ifndef sk_paragraph_DEFINED
#define sk_paragraph_DEFINED

#include "sk_paragraph_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API void sk_paragraph_destroy(sk_paragraph_t* self);
SK_C_API bool sk_paragraph_did_exceed_max_lines(sk_paragraph_t* self);
SK_C_API float sk_paragraph_get_alphabetic_baseline(sk_paragraph_t* self);
SK_C_API void sk_paragraph_get_glyph_position_at_coordinate(sk_paragraph_t* self, float dx, float dy, /*out*/ sk_positionaffinity_t* result);
SK_C_API float sk_paragraph_get_height(sk_paragraph_t* self);
SK_C_API float sk_paragraph_get_ideographic_baseline(sk_paragraph_t* self);
SK_C_API size_t sk_paragraph_get_line_metrics(sk_paragraph_t* self, sk_metrics_t result[]);
SK_C_API float sk_paragraph_get_longest_line(sk_paragraph_t* self);
SK_C_API float sk_paragraph_get_max_intrinsic_width(sk_paragraph_t* self);
SK_C_API float sk_paragraph_get_max_width(sk_paragraph_t* self);
SK_C_API float sk_paragraph_get_min_intrinsic_width(sk_paragraph_t* self);
SK_C_API size_t sk_paragraph_get_rects_for_placeholders(sk_paragraph_t* self, sk_textbox_t result[]);
SK_C_API size_t sk_paragraph_get_rects_for_range(sk_paragraph_t* self, uint32_t start, uint32_t end, sk_rectheightstyle_t rect_height_style, sk_rectwidthstyle_t rect_width_style, sk_textbox_t result[]);
SK_C_API void sk_paragraph_get_word_boundary(sk_paragraph_t* self, uint32_t offset, /*out*/ uint32_t* start, /*out*/ uint32_t* end);
SK_C_API size_t sk_paragraph_get_line_number(sk_paragraph_t* self);
SK_C_API void sk_paragraph_layout(sk_paragraph_t* self, float width);
SK_C_API void sk_paragraph_paint(sk_paragraph_t* self, sk_canvas_t* canvas, float x, float y);
SK_C_API sk_path_t* sk_paragraph_to_path(sk_paragraph_t* self);
SK_C_API void sk_paragraph_visit(sk_paragraph_t* self, sk_paragraph_visit_proc proc, void* proc_context);

SK_C_PLUS_PLUS_END_GUARD
#endif
