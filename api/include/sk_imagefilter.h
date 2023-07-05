#ifndef sk_imagefilter_DEFINED
#define sk_imagefilter_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API bool sk_imagefilter_can_compute_fast_bounds(const sk_imagefilter_t *self);
SK_C_API void sk_imagefilter_compute_fast_bounds(const sk_imagefilter_t *self, const sk_rect_t *bounds, /*out*/ sk_rect_t *result);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_arithmetic(float k1, float k2, float k3, float k4, bool enforce_premultiplied_color, sk_imagefilter_t *background, sk_imagefilter_t *foreground, const sk_rect_t *crop_rect);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_blend(sk_blendmode_t mode, sk_imagefilter_t *background, sk_imagefilter_t *foreground, const sk_rect_t *crop_rect);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_blur(float sigma_x, float sigma_y, sk_tilemode_t tile_mode, sk_imagefilter_t *input, const sk_rect_t *crop_rect);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_colorfilter(sk_colorfilter_t *color_filter, sk_imagefilter_t *input, const sk_rect_t *crop_rect);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_compose(sk_imagefilter_t *inner, sk_imagefilter_t *outer);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_dilate(float radius_x, float radius_y, sk_imagefilter_t *input, const sk_rect_t *crop_rect);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_displacement_map(sk_colorchannel_t x_channel_selector, sk_colorchannel_t y_channel_selector, float scale, sk_imagefilter_t *displacement, sk_imagefilter_t *input, const sk_rect_t *crop_rect);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_distant_lit_diffuse(const sk_point3_t *direction, sk_color_t light_color, float surface_scale, float kd, sk_imagefilter_t *input, const sk_rect_t *crop_rect);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_distant_lit_specular(const sk_point3_t *direction, sk_color_t light_color, float surface_scale, float ks, float shininess, sk_imagefilter_t *input, const sk_rect_t *crop_rect);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_drop_shadow(float dx, float dy, float sigma_x, float sigma_y, sk_color_t color, sk_imagefilter_t *input, const sk_rect_t *crop_rect);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_drop_shadow_only(float dx, float dy, float sigma_x, float sigma_y, sk_color_t color, sk_imagefilter_t *input, const sk_rect_t *crop_rect);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_erode(float radius_x, float radius_y, sk_imagefilter_t *input, const sk_rect_t *crop_rect);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_image(sk_image_t *image, const sk_rect_t *src, const sk_rect_t *dest, const sk_samplingoptions_t *sampling);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_matrix_convolution(const sk_isize_t *kernel_size, const float *kernel, float gain, float bias, const sk_ipoint_t *kernel_offset, sk_tilemode_t tile_mode, bool convolve_alpha, sk_imagefilter_t *input, const sk_rect_t *crop_rect);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_matrix_transform(const sk_matrix_t *matrix, const sk_samplingoptions_t *sampling, sk_imagefilter_t *input);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_merge(const sk_imagefilter_t *filters[], int32_t count, const sk_rect_t *crop_rect);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_offset(float dx, float dy, sk_imagefilter_t *input, const sk_rect_t *crop_rect);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_picture(sk_picture_t *picture, const sk_rect_t *crop_rect);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_point_lit_diffuse(const sk_point3_t *location, sk_color_t light_color, float surface_scale, float kd, sk_imagefilter_t *input, const sk_rect_t *crop_rect);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_point_lit_specular(const sk_point3_t *location, sk_color_t light_color, float surface_scale, float ks, float shininess, sk_imagefilter_t *input, const sk_rect_t *crop_rect);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_runtime_shader(const sk_runtimeshaderbuilder_t *effect_builder, const char child[], sk_imagefilter_t *input);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_runtime_shader2(const sk_runtimeshaderbuilder_t *effect_builder, const char *children[], sk_imagefilter_t *inputs[], int32_t count);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_shader(sk_shader_t *shader, bool dither, const sk_rect_t *crop_rect);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_spot_lit_diffuse(const sk_point3_t *location, const sk_point3_t *target, float falloff_exponent, float cutoff_angle, sk_color_t light_color, float surface_scale, float kd, sk_imagefilter_t *input, const sk_rect_t *crop_rect);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_spot_lit_specular(const sk_point3_t *location, const sk_point3_t *target, float falloff_exponent, float cutoff_angle, sk_color_t light_color, float surface_scale, float ks, float shininess, sk_imagefilter_t *input, const sk_rect_t *crop_rect);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_tile(const sk_rect_t *src, const sk_rect_t *dest, sk_imagefilter_t *input);
SK_C_API sk_imagefilter_t *sk_imagefilter_make_with_local_matrix(const sk_imagefilter_t *self, const sk_matrix_t *local_matrix);

SK_C_PLUS_PLUS_END_GUARD
#endif
