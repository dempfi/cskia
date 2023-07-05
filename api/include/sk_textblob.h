#ifndef sk_textblob_DEFINED
#define sk_textblob_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API int32_t sk_textblob_get_intercepts(const sk_textblob_t *self, const float bounds[2], float result[], const sk_paint_t *paint);
SK_C_API sk_textblob_t *sk_textblob_make_from_text(const void *text, size_t size, const sk_font_t *font, sk_textencoding_t encoding);
SK_C_API sk_textblob_t *sk_textblob_make_from_text_horizontally_positioned(const void *text, size_t size, const float x_positions[], float y, const sk_font_t *font, sk_textencoding_t encoding);
SK_C_API sk_textblob_t *sk_textblob_make_from_text_positioned(const void *text, size_t size, const sk_point_t positions[], const sk_font_t *font, sk_textencoding_t encoding);
SK_C_API sk_textblob_t *sk_textblob_make_from_text_transform(const void *text, size_t size, const sk_rotationscalematrix_t matrices[], const sk_font_t *font, sk_textencoding_t encoding);
SK_C_API void sk_textblob_ref(const sk_textblob_t *self);
SK_C_API void sk_textblob_unref(const sk_textblob_t *self);
SK_C_API void sk_textblob_get_bounds(const sk_textblob_t *blob, sk_rect_t *bounds);

// sk_textblob_builder_t
SK_C_API sk_textblob_builder_t *sk_textblob_builder_new(void);
SK_C_API void sk_textblob_builder_delete(sk_textblob_builder_t *builder);
SK_C_API sk_textblob_t *sk_textblob_builder_make(sk_textblob_builder_t *builder);
SK_C_API void sk_textblob_builder_alloc_run(sk_textblob_builder_t *builder, const sk_font_t *font, int count, float x, float y, const sk_rect_t *bounds, sk_textblob_builder_runbuffer_t *runbuffer);
SK_C_API void sk_textblob_builder_alloc_run_pos_h(sk_textblob_builder_t *builder, const sk_font_t *font, int count, float y, const sk_rect_t *bounds, sk_textblob_builder_runbuffer_t *runbuffer);
SK_C_API void sk_textblob_builder_alloc_run_pos(sk_textblob_builder_t *builder, const sk_font_t *font, int count, const sk_rect_t *bounds, sk_textblob_builder_runbuffer_t *runbuffer);
SK_C_API void sk_textblob_builder_alloc_run_rsxform(sk_textblob_builder_t *builder, const sk_font_t *font, int count, sk_textblob_builder_runbuffer_t *runbuffer);
// (obsolete)
SK_C_API void sk_textblob_builder_alloc_run_text(sk_textblob_builder_t *builder, const sk_font_t *font, int count, float x, float y, int textByteCount, const sk_rect_t *bounds, sk_textblob_builder_runbuffer_t *runbuffer);
SK_C_API void sk_textblob_builder_alloc_run_text_pos_h(sk_textblob_builder_t *builder, const sk_font_t *font, int count, float y, int textByteCount, const sk_rect_t *bounds, sk_textblob_builder_runbuffer_t *runbuffer);
SK_C_API void sk_textblob_builder_alloc_run_text_pos(sk_textblob_builder_t *builder, const sk_font_t *font, int count, int textByteCount, const sk_rect_t *bounds, sk_textblob_builder_runbuffer_t *runbuffer);
SK_C_API
SK_C_PLUS_PLUS_END_GUARD
#endif
