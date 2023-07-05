#ifndef sk_pixmap_DEFINED
#define sk_pixmap_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_pixmap_t *sk_pixmap_create(const sk_imageinfo_t *image_info, const void *pixels, size_t row_bytes);
SK_C_API void sk_pixmap_destroy(sk_pixmap_t *self);
SK_C_API bool sk_pixmap_erase(const sk_pixmap_t *self, sk_color_t color, const sk_irect_t *area);
SK_C_API bool sk_pixmap_erase2(const sk_pixmap_t *self, const sk_color4f_t *color, const sk_irect_t *area);
SK_C_API bool sk_pixmap_extract_subset(const sk_pixmap_t *self, sk_pixmap_t *dest, const sk_irect_t *area);
SK_C_API float sk_pixmap_get_alpha(const sk_pixmap_t *self, int32_t x, int32_t y);
SK_C_API sk_alphatype_t sk_pixmap_get_alpha_type(const sk_pixmap_t *self);
SK_C_API sk_color_t sk_pixmap_get_color(const sk_pixmap_t *self, int32_t x, int32_t y);
SK_C_API void sk_pixmap_get_colorf(const sk_pixmap_t *self, int32_t x, int32_t y, /*out*/ sk_color4f_t *result);
SK_C_API sk_colorspace_t *sk_pixmap_get_color_space(const sk_pixmap_t *self);
SK_C_API sk_colortype_t sk_pixmap_get_color_type(const sk_pixmap_t *self);
SK_C_API int32_t sk_pixmap_get_height(const sk_pixmap_t *self);
SK_C_API void sk_pixmap_get_image_info(const sk_pixmap_t *self, /*out*/ sk_imageinfo_t *result);
SK_C_API void *sk_pixmap_get_pixel_addr(const sk_pixmap_t *self, int32_t x, int32_t y);
SK_C_API void *sk_pixmap_get_pixels(const sk_pixmap_t *self);
SK_C_API size_t sk_pixmap_get_row_bytes(const sk_pixmap_t *self);
SK_C_API int32_t sk_pixmap_get_width(const sk_pixmap_t *self);
SK_C_API bool sk_pixmap_read_pixels(const sk_pixmap_t *self, const sk_pixmap_t *dest, int32_t src_x, int32_t src_y);
SK_C_API bool sk_pixmap_scale_pixels(const sk_pixmap_t *self, const sk_pixmap_t *dest, const sk_samplingoptions_t *sampling);
SK_C_API void sk_pixmap_set_colorspace(sk_pixmap_t *self, sk_colorspace_t *value);

SK_C_PLUS_PLUS_END_GUARD
#endif
