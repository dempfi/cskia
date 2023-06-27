#ifndef sk_canvas_DEFINED
#define sk_canvas_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API int sk_canvas_save(sk_canvas_t *canvas);
SK_C_API int sk_canvas_save_layer(sk_canvas_t *canvas, const sk_rect_t *rect, const sk_paint_t *paint);
SK_C_API void sk_canvas_restore(sk_canvas_t *canvas);
SK_C_API void sk_canvas_translate(sk_canvas_t *canvas, float dx, float dy);
SK_C_API void sk_canvas_scale(sk_canvas_t *canvas, float sx, float sy);
SK_C_API void sk_canvas_rotate_radians(sk_canvas_t *canvas, float radians);
SK_C_API void sk_canvas_skew(sk_canvas_t *canvas, float sx, float sy);

SK_C_API void sk_canvas_draw_paint(sk_canvas_t *canvas, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_rect(sk_canvas_t *canvas, const sk_rect_t *rect, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_rrect(sk_canvas_t *canvas, const sk_rrect_t *rrect, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_circle(sk_canvas_t *canvas, float cx, float cy, float radius, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_path(sk_canvas_t *canvas, const sk_path_t *path, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_line(sk_canvas_t *canvas, float x0, float y0, float x1, float y1, sk_paint_t *paint);
SK_C_API void sk_canvas_draw_round_rect(sk_canvas_t *canvas, const sk_rect_t *rect, float rx, float ry, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_arc(sk_canvas_t *canvas, const sk_rect_t *oval, float startAngle, float sweepAngle, bool useCenter, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_drrect(sk_canvas_t *canvas, const sk_rrect_t *outer, const sk_rrect_t *inner, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_oval(sk_canvas_t *canvas, const sk_rect_t *oval, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_image(sk_canvas_t *canvas, const sk_image_t *image, float dx, float dy, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_image_nine(sk_canvas_t *canvas, const sk_image_t *image, const sk_rect_t *center, const sk_rect_t *dst, sk_filter_mode_t filterMode, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_image_rect(sk_canvas_t *canvas, const sk_image_t *image, const sk_rect_t *src, const sk_rect_t *dst, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_simple_text(sk_canvas_t *canvas, const void *text, size_t byte_length, sk_text_encoding_t encoding, float x, float y, const sk_font_t *font, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_text_blob(sk_canvas_t *canvas, sk_textblob_t *text, float x, float y, const sk_paint_t *cpaint);
SK_C_API void sk_canvas_draw_shadow(sk_canvas_t *canvas, const sk_path_t *path, const sk_point3_t *zPlaneParams, const sk_point3_t *lightPos, float lightRadius, sk_color_t ambientColor, sk_color_t spotColor, sk_shadow_flags_t flag);

SK_C_API void sk_canvas_clear(sk_canvas_t *canvas, sk_color_t);
SK_C_API void sk_canvas_discard(sk_canvas_t *canvas);
SK_C_API int sk_canvas_get_save_count(sk_canvas_t *canvas);
SK_C_API void sk_canvas_get_total_matrix(sk_canvas_t *canvas, sk_matrix_t *matrix);
SK_C_API void sk_canvas_restore_to_count(sk_canvas_t *canvas, int saveCount);

SK_C_PLUS_PLUS_END_GUARD

#endif
