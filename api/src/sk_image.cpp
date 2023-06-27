#include "sk_mapping.h"
#include "include/sk_image.h"
#include "include/core/SkImage.h"
#include "include/core/SkColorSpace.h"
#include "include/core/SkData.h"

sk_image_t *sk_image_new_raster_copy_with_pixmap(const sk_pixmap_t *pixmap)
{
  return ToImage(SkImages::RasterFromPixmapCopy(*AsPixmap(pixmap)).release());
};

sk_image_t *sk_image_new_raster_data(const sk_imageinfo_t *info, sk_data_t *pixels, size_t rowBytes)
{
  return ToImage(SkImages::RasterFromData(AsImageInfo(info), sk_ref_sp(AsData(pixels)), rowBytes).release());
};

sk_image_t *sk_image_new_from_bitmap(const sk_bitmap_t *bitmap)
{
  return ToImage(SkImages::RasterFromBitmap(*reinterpret_cast<const SkBitmap *>(bitmap)).release());
};

sk_image_t *sk_image_new_from_encoded(sk_data_t *encoded, const sk_alphatype_t *alpha)
{
  return ToImage(SkImages::DeferredFromEncodedData(sk_ref_sp(AsData(encoded)), (SkAlphaType)*alpha).release());
};

sk_image_t *sk_image_make_subset(const sk_image_t *image, const sk_irect_t *subset)
{
  return ToImage(AsImage(image)->makeSubset(*reinterpret_cast<const SkIRect *>(subset)).release());
};

sk_image_t *sk_image_make_non_texture_image(const sk_image_t *image)
{
  return ToImage(AsImage(image)->makeNonTextureImage().release());
};

sk_image_t *sk_image_make_raster_image(const sk_image_t *image)
{
  return ToImage(AsImage(image)->makeRasterImage().release());
};

void sk_image_ref(const sk_image_t *image)
{
  AsImage(image)->ref();
};

void sk_image_unref(const sk_image_t *image)
{
  AsImage(image)->unref();
};

int sk_image_get_width(const sk_image_t *image)
{
  return AsImage(image)->width();
};

int sk_image_get_height(const sk_image_t *image)
{
  return AsImage(image)->height();
};

uint32_t sk_image_get_unique_id(const sk_image_t *image)
{
  return AsImage(image)->uniqueID();
};

sk_alphatype_t sk_image_get_alpha_type(const sk_image_t *image)
{
  return (sk_alphatype_t)AsImage(image)->alphaType();
};

sk_colortype_t sk_image_get_color_type(const sk_image_t *image)
{
  return (sk_colortype_t)AsImage(image)->colorType();
};

sk_colorspace_t *sk_image_get_colorspace(const sk_image_t *image)
{
  return reinterpret_cast<sk_colorspace_t *>(AsImage(image)->refColorSpace().release());
};

bool sk_image_is_alpha_only(const sk_image_t *image)
{
  return AsImage(image)->isAlphaOnly();
};

bool sk_image_peek_pixels(const sk_image_t *image, sk_pixmap_t *pixmap)
{
  return AsImage(image)->peekPixels(AsPixmap(pixmap));
};

bool sk_image_is_texture_backed(const sk_image_t *image)
{
  return AsImage(image)->isTextureBacked();
};

bool sk_image_is_lazy_generated(const sk_image_t *image)
{
  return AsImage(image)->isLazyGenerated();
};

bool sk_image_is_valid(const sk_image_t *image, gr_direct_context_t *context)
{
  return AsImage(image)->isValid(reinterpret_cast<GrRecordingContext *>(context));
};

bool sk_image_read_pixels(const sk_image_t *image, const sk_imageinfo_t *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY, sk_image_caching_hint_t cachingHint)
{
  return AsImage(image)->readPixels(AsImageInfo(dstInfo), dstPixels, dstRowBytes, srcX, srcY, (SkImage::CachingHint)cachingHint);
};

bool sk_image_read_pixels_into_pixmap(const sk_image_t *image, const sk_pixmap_t *dst, int srcX, int srcY, sk_image_caching_hint_t cachingHint)
{
  return AsImage(image)->readPixels(*AsPixmap(dst), srcX, srcY, (SkImage::CachingHint)cachingHint);
};

bool sk_image_scale_pixels(const sk_image_t *image, const sk_pixmap_t *dst, const sk_sampling_options_t *options, sk_image_caching_hint_t cachingHint)
{
  return AsImage(image)->scalePixels(*AsPixmap(dst), *reinterpret_cast<const SkSamplingOptions *>(options), (SkImage::CachingHint)cachingHint);
};
