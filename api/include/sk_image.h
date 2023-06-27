#ifndef sk_image_DEFINED
#define sk_image_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_image_t *sk_image_new_raster_copy_with_pixmap(const sk_pixmap_t *pixmap);
SK_C_API sk_image_t *sk_image_new_raster_data(const sk_imageinfo_t *cinfo, sk_data_t *pixels, size_t rowBytes);
SK_C_API sk_image_t *sk_image_new_from_bitmap(const sk_bitmap_t *cbitmap);
SK_C_API sk_image_t *sk_image_new_from_encoded(sk_data_t *encoded, const sk_alphatype_t *alpha);

SK_C_API sk_image_t *sk_image_make_subset(const sk_image_t *cimage, const sk_irect_t *subset);
SK_C_API sk_image_t *sk_image_make_non_texture_image(const sk_image_t *cimage);
SK_C_API sk_image_t *sk_image_make_raster_image(const sk_image_t *cimage);
SK_C_API sk_image_t *sk_image_make_with_filter(const sk_image_t *cimage, const sk_imagefilter_t *filter, const sk_irect_t *subset, const sk_irect_t *clipBounds, sk_irect_t *outSubset, sk_ipoint_t *outOffset);

SK_C_API void sk_image_ref(const sk_image_t *);
SK_C_API void sk_image_unref(const sk_image_t *);
SK_C_API int sk_image_get_width(const sk_image_t *);
SK_C_API int sk_image_get_height(const sk_image_t *);
SK_C_API uint32_t sk_image_get_unique_id(const sk_image_t *);
SK_C_API sk_alphatype_t sk_image_get_alpha_type(const sk_image_t *);
SK_C_API sk_colortype_t sk_image_get_color_type(const sk_image_t *);
SK_C_API sk_colorspace_t *sk_image_get_colorspace(const sk_image_t *);
SK_C_API bool sk_image_is_alpha_only(const sk_image_t *);
SK_C_API bool sk_image_peek_pixels(const sk_image_t *image, sk_pixmap_t *pixmap);
SK_C_API bool sk_image_is_texture_backed(const sk_image_t *image);
SK_C_API bool sk_image_is_lazy_generated(const sk_image_t *image);
SK_C_API bool sk_image_is_valid(const sk_image_t *image, gr_direct_context_t *context);
SK_C_API bool sk_image_read_pixels(const sk_image_t *image, const sk_imageinfo_t *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY, sk_image_caching_hint_t cachingHint);
SK_C_API bool sk_image_read_pixels_into_pixmap(const sk_image_t *image, const sk_pixmap_t *dst, int srcX, int srcY, sk_image_caching_hint_t cachingHint);
SK_C_API bool sk_image_scale_pixels(const sk_image_t *image, const sk_pixmap_t *dst, const sk_sampling_options_t *options, sk_image_caching_hint_t cachingHint);

SK_C_PLUS_PLUS_END_GUARD

#endif
