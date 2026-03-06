#ifndef sk_shader_DEFINED
#define sk_shader_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_shader_t* sk_shader_make_blend(sk_blendmode_t mode, sk_shader_t* dest, sk_shader_t* src);
SK_C_API sk_shader_t* sk_shader_make_color(sk_color_t color);
SK_C_API sk_shader_t* sk_shader_make_color2(const sk_color4f_t* color, sk_colorspace_t* color_space);
SK_C_API sk_shader_t* sk_shader_make_empty(void);
SK_C_API sk_shader_t* sk_shader_make_gradient_linear(const sk_point_t points[2], const sk_color_t colors[], const float positions[], int32_t count, sk_tilemode_t tile_mode, const sk_matrix_t* local_matrix);
SK_C_API sk_shader_t* sk_shader_make_gradient_linear2(const sk_point_t points[2], const sk_color4f_t colors[], sk_colorspace_t* color_space, const float positions[], int32_t count, sk_tilemode_t tile_mode, const sk_matrix_t* local_matrix);
SK_C_API sk_shader_t* sk_shader_make_gradient_radial(const sk_point_t* center, float radius, const sk_color_t colors[], const float positions[], int32_t count, sk_tilemode_t tile_mode, const sk_matrix_t* local_matrix);
SK_C_API sk_shader_t* sk_shader_make_gradient_radial2(const sk_point_t* center, float radius, const sk_color4f_t colors[], sk_colorspace_t* color_space, const float positions[], int32_t count, sk_tilemode_t tile_mode, const sk_matrix_t* local_matrix);
SK_C_API sk_shader_t* sk_shader_make_gradient_sweep(float center_x, float center_y, const sk_color_t colors[], const float positions[], int32_t count, sk_tilemode_t tile_mode, float start_angle, float end_angle, const sk_matrix_t* local_matrix);
SK_C_API sk_shader_t* sk_shader_make_gradient_sweep2(float center_x, float center_y, const sk_color4f_t colors[], sk_colorspace_t* color_space, const float positions[], int32_t count, sk_tilemode_t tile_mode, float start_angle, float end_angle, const sk_matrix_t* local_matrix);
SK_C_API sk_shader_t* sk_shader_make_gradient_two_point_conical(const sk_point_t* start, float start_radius, const sk_point_t* end, float end_radius, const sk_color_t colors[], const float positions[], int32_t count, sk_tilemode_t tile_mode, const sk_matrix_t* local_matrix);
SK_C_API sk_shader_t* sk_shader_make_gradient_two_point_conical2(const sk_point_t* start, float start_radius, const sk_point_t* end, float end_radius, const sk_color4f_t colors[], sk_colorspace_t* color_space, const float positions[], int32_t count, sk_tilemode_t tile_mode, const sk_matrix_t* local_matrix);
SK_C_API sk_shader_t* sk_shader_make_with_color_filter(const sk_shader_t* self, sk_colorfilter_t* color_filter);
SK_C_API sk_shader_t* sk_shader_make_with_local_matrix(const sk_shader_t* self, const sk_matrix_t* local_matrix);
void sk_shader_unref(sk_shader_t* self);

SK_C_PLUS_PLUS_END_GUARD
#endif
