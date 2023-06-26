#include "include/sk_image.h"
#include "include/core/SkImage.h"
#include "include/core/SkColorSpace.h"

static inline SkImageInfo AsImageInfo(const sk_imageinfo_t *info)
{
  return SkImageInfo::Make(
      info->width,
      info->height,
      (SkColorType)info->colorType,
      (SkAlphaType)info->alphaType,
      sk_ref_sp(reinterpret_cast<SkColorSpace *>(info->colorSpace)));
}

sk_image_t *sk_image_new_raster_copy(const sk_imageinfo_t *info, const void *pixels, size_t rowBytes)
{
  return reinterpret_cast<sk_image_t *>(sk_ref_sp(SkImage::MakeRasterCopy(AsImageInfo(info), pixels, rowBytes).release()));
};

sk_image_t *sk_image_new_raster_copy_with_pixmap(const sk_pixmap_t *pixmap)
{
  return reinterpret_cast<sk_image_t *>(sk_ref_sp(SkImage::MakeRasterCopy(*reinterpret_cast<const SkPixmap *>(pixmap)).release()));
};

sk_image_t *sk_image_new_from_bitmap(const sk_bitmap_t *cbitmap){

};

sk_image_t *sk_image_make_subset(const sk_image_t *cimage, const sk_irect_t *subset){

};

sk_image_t *sk_image_make_non_texture_image(const sk_image_t *cimage){

};

sk_image_t *sk_image_make_raster_image(const sk_image_t *cimage){

};

sk_image_t *sk_image_make_with_filter(const sk_image_t *cimage, const sk_imagefilter_t *filter, const sk_irect_t *subset, const sk_irect_t *clipBounds, sk_irect_t *outSubset, sk_ipoint_t *outOffset){

};

void sk_image_ref(const sk_image_t *){

};

void sk_image_unref(const sk_image_t *){

};

int sk_image_get_width(const sk_image_t *){

};

int sk_image_get_height(const sk_image_t *){

};

uint32_t sk_image_get_unique_id(const sk_image_t *){

};

sk_alphatype_t sk_image_get_alpha_type(const sk_image_t *){

};

sk_colortype_t sk_image_get_color_type(const sk_image_t *){

};

sk_colorspace_t *sk_image_get_colorspace(const sk_image_t *){

};

bool sk_image_is_alpha_only(const sk_image_t *){

};

bool sk_image_peek_pixels(const sk_image_t *image, sk_pixmap_t *pixmap){

};

bool sk_image_is_texture_backed(const sk_image_t *image){

};

bool sk_image_is_lazy_generated(const sk_image_t *image){

};

bool sk_image_read_pixels(const sk_image_t *image, const sk_imageinfo_t *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY, sk_image_caching_hint_t cachingHint){

};

bool sk_image_read_pixels_into_pixmap(const sk_image_t *image, const sk_pixmap_t *dst, int srcX, int srcY, sk_image_caching_hint_t cachingHint){

};

bool sk_image_scale_pixels(const sk_image_t *image, const sk_pixmap_t *dst, sk_filter_quality_t quality, sk_image_caching_hint_t cachingHint){

};
