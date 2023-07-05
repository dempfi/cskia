#ifndef sk_canvas_DEFINED
#define sk_canvas_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API void sk_canvas_clear(sk_canvas_t *self, sk_color_t color);
SK_C_API void sk_canvas_clear2(sk_canvas_t *self, const sk_color4f_t *color);
SK_C_API void sk_canvas_destroy(sk_canvas_t *self);
SK_C_API void sk_canvas_discard(sk_canvas_t *self);
SK_C_API void sk_canvas_clip_path(sk_canvas_t *self, const sk_path_t *path, sk_clipop_t op, bool antialias);
SK_C_API void sk_canvas_clip_rect(sk_canvas_t *self, const sk_rect_t *rect, sk_clipop_t op, bool antialias);
SK_C_API void sk_canvas_clip_region(sk_canvas_t *self, const sk_region_t *region, sk_clipop_t op);
SK_C_API void sk_canvas_clip_rrect(sk_canvas_t *self, const sk_rrect_t *rrect, sk_clipop_t op, bool antialias);
SK_C_API void sk_canvas_clip_shader(sk_canvas_t *self, sk_shader_t *shader, sk_clipop_t op);
SK_C_API void sk_canvas_concat(sk_canvas_t *self, const sk_matrix44_t *matrix);
SK_C_API void sk_canvas_concat2(sk_canvas_t *self, const sk_matrix_t *matrix);
SK_C_API void sk_canvas_draw_annotation(sk_canvas_t *self, const sk_rect_t *rect, const char key[], const void *value, size_t size);
SK_C_API void sk_canvas_draw_arc(sk_canvas_t *self, const sk_rect_t *oval, float start_angle, float sweep_angle, bool use_center, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_atlas(sk_canvas_t *self, const sk_image_t *atlas, const sk_rotationscalematrix_t transforms[], const sk_rect_t sprites[], const sk_color_t colors[], int32_t count, sk_blendmode_t blend_mode, const sk_samplingoptions_t *sampling, const sk_rect_t *cull_rect, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_circle(sk_canvas_t *self, float x, float y, float radius, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_color(sk_canvas_t *self, sk_color_t color, sk_blendmode_t blend_mode);
SK_C_API void sk_canvas_draw_color2(sk_canvas_t *self, const sk_color4f_t *color, sk_blendmode_t blend_mode);
SK_C_API void sk_canvas_draw_glyphs(sk_canvas_t *self, int32_t count, const sk_glyphid_t glyphs[], const sk_point_t positions[], const sk_point_t *origin, const sk_font_t *font, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_glyphs2(sk_canvas_t *self, int32_t count, const sk_glyphid_t glyphs[], const sk_rotationscalematrix_t matrices[], const sk_point_t *origin, const sk_font_t *font, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_image(sk_canvas_t *self, const sk_image_t *image, float x, float y, const sk_samplingoptions_t *sampling, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_image_lattice(sk_canvas_t *self, const sk_image_t *image, const sk_lattice_t *lattice, const sk_rect_t *dest, sk_filtermode_t filter_mode, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_image_nine(sk_canvas_t *self, const sk_image_t *image, const sk_irect_t *center, const sk_rect_t *dest, sk_filtermode_t filter_mode, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_image_rect(sk_canvas_t *self, const sk_image_t *image, const sk_rect_t *dest, const sk_samplingoptions_t *sampling, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_line(sk_canvas_t *self, float x1, float y1, float x2, float y2, sk_paint_t *paint);
SK_C_API void sk_canvas_draw_oval(sk_canvas_t *self, const sk_rect_t *oval, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_paint(sk_canvas_t *self, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_patch(sk_canvas_t *self, const sk_point_t cubics[12], const sk_color_t colors[4], const sk_point_t tex_coords[4], sk_blendmode_t blend_mode, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_path(sk_canvas_t *self, const sk_path_t *path, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_picture(sk_canvas_t *self, const sk_picture_t *picture, const sk_matrix_t *matrix, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_point(sk_canvas_t *self, const sk_point_t *point, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_points(sk_canvas_t *self, sk_drawpointsmode_t mode, size_t count, const sk_point_t points[], const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_rect(sk_canvas_t *self, const sk_rect_t *rect, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_region(sk_canvas_t *self, const sk_region_t *region, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_rrect(sk_canvas_t *self, const sk_rrect_t *rrect, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_rrect2(sk_canvas_t *self, const sk_rect_t *rect, float radius_x, float radius_y, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_rrect_difference(sk_canvas_t *self, const sk_rrect_t *outer, const sk_rrect_t *inner, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_simple_text(sk_canvas_t *self, const void *text, size_t size, sk_textencoding_t encoding, float x, float y, const sk_font_t *font, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_text_blob(sk_canvas_t *self, const sk_textblob_t *text_blob, float x, float y, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_vertices(sk_canvas_t *self, const sk_vertices_t *vertices, sk_blendmode_t blend_mode, const sk_paint_t *paint);
SK_C_API void sk_canvas_draw_shadow(sk_canvas_t *canvas, const sk_path_t *path, const sk_point3_t *zPlaneParams, const sk_point3_t *lightPos, float lightRadius, sk_color_t ambientColor, sk_color_t spotColor, sk_shadowflags_t flag);

SK_C_API void sk_canvas_get_total_matrix(sk_canvas_t *canvas, sk_matrix_t *matrix);
SK_C_API void sk_canvas_get_base_props(const sk_canvas_t *self, /*out*/ sk_surfaceprops_t *result);
SK_C_API void sk_canvas_get_device_clip_bounds(const sk_canvas_t *self, /*out*/ sk_irect_t *result);
SK_C_API void sk_canvas_get_local_clip_bounds(const sk_canvas_t *self, /*out*/ sk_rect_t *result);
SK_C_API void sk_canvas_get_local_to_device(const sk_canvas_t *self, /*out*/ sk_matrix44_t *result);
SK_C_API void sk_canvas_get_local_to_device_as_3x3(const sk_canvas_t *self, /*out*/ sk_matrix_t *result);
SK_C_API void sk_canvas_get_top_props(const sk_canvas_t *self, /*out*/ sk_surfaceprops_t *result);
SK_C_API int32_t sk_canvas_get_save_count(const sk_canvas_t *self);
SK_C_API sk_surface_t *sk_canvas_make_surface(sk_canvas_t *self, const sk_imageinfo_t *image_info, const sk_surfaceprops_t *surface_props);
SK_C_API bool sk_canvas_quick_reject(const sk_canvas_t *self, const sk_rect_t *rect);
SK_C_API bool sk_canvas_quick_reject2(const sk_canvas_t *self, const sk_path_t *path);
SK_C_API void sk_canvas_reset_matrix(sk_canvas_t *self);
SK_C_API void sk_canvas_restore(sk_canvas_t *self);
SK_C_API void sk_canvas_restore_to_count(sk_canvas_t *self, int32_t save_count);
SK_C_API void sk_canvas_rotate(sk_canvas_t *self, float degrees);
SK_C_API void sk_canvas_rotate2(sk_canvas_t *self, float degrees, float px, float py);
SK_C_API int32_t sk_canvas_save(sk_canvas_t *self);
SK_C_API int32_t sk_canvas_save_layer_with_filter(sk_canvas_t *self, const sk_rect_t *bounds, const sk_paint_t *paint, const sk_imagefilter_t *backdrop, uint32_t flags);
SK_C_API int32_t sk_canvas_save_layer(sk_canvas_t *self, const sk_rect_t *bounds, const sk_paint_t *paint);
SK_C_API int32_t sk_canvas_save_layer_alpha(sk_canvas_t *self, const sk_rect_t *bounds, uint8_t alpha);
SK_C_API void sk_canvas_scale(sk_canvas_t *self, float sx, float sy);
SK_C_API void sk_canvas_set_matrix(sk_canvas_t *self, const sk_matrix44_t *matrix);
SK_C_API void sk_canvas_set_matrix2(sk_canvas_t *self, const sk_matrix_t *matrix);
SK_C_API void sk_canvas_skew(sk_canvas_t *self, float kx, float ky);
SK_C_API void sk_canvas_translate(sk_canvas_t *self, float dx, float dy);

SK_C_PLUS_PLUS_END_GUARD
#endif
