#include "include/sk_pixmap.h"
#include "sk_mapping.h"

sk_pixmap_t *sk_pixmap_create(const sk_imageinfo_t *image_info, const void *pixels, size_t row_bytes)
{
  return ToPixmap(new SkPixmap(AsImageInfo(image_info), pixels, row_bytes));
}

void sk_pixmap_destroy(sk_pixmap_t *self)
{
  delete AsPixmap(self);
}

bool sk_pixmap_erase(const sk_pixmap_t *self, sk_color_t color, const sk_irect_t *area)
{
  return (area) ? AsPixmap(self)->erase(color, AsIRect(*area)) : AsPixmap(self)->erase(color);
}

bool sk_pixmap_erase2(const sk_pixmap_t *self, const sk_color4f_t *color, const sk_irect_t *area)
{
  return AsPixmap(self)->erase(AsColor4f(*color), AsIRect(area));
}

bool sk_pixmap_extract_subset(const sk_pixmap_t *self, sk_pixmap_t *dest, const sk_irect_t *area)
{
  return AsPixmap(self)->extractSubset(AsPixmap(dest), AsIRect(*area));
}

float sk_pixmap_get_alpha(const sk_pixmap_t *self, int32_t x, int32_t y)
{
  return AsPixmap(self)->getAlphaf(x, y);
}

sk_alphatype_t sk_pixmap_get_alpha_type(const sk_pixmap_t *self)
{
  return ToAlphaType(AsPixmap(self)->alphaType());
}

sk_color_t sk_pixmap_get_color(const sk_pixmap_t *self, int32_t x, int32_t y)
{
  return AsPixmap(self)->getColor(x, y);
}

void sk_pixmap_get_colorf(const sk_pixmap_t *self, int32_t x, int32_t y, sk_color4f_t *result)
{
  *result = ToColor4f(AsPixmap(self)->getColor4f(x, y));
}

sk_colorspace_t *sk_pixmap_get_color_space(const sk_pixmap_t *self)
{
  return ToColorSpace(AsPixmap(self)->refColorSpace().release());
}

sk_colortype_t sk_pixmap_get_color_type(const sk_pixmap_t *self)
{
  return ToColorType(AsPixmap(self)->colorType());
}

int32_t sk_pixmap_get_height(const sk_pixmap_t *self)
{
  return AsPixmap(self)->height();
}

void sk_pixmap_get_image_info(const sk_pixmap_t *self, sk_imageinfo_t *result)
{
  *result = ToImageInfo(AsPixmap(self)->info());
}

void *sk_pixmap_get_pixel_addr(const sk_pixmap_t *self, int32_t x, int32_t y)
{
  return AsPixmap(self)->writable_addr(x, y);
}

void *sk_pixmap_get_pixels(const sk_pixmap_t *self)
{
  return AsPixmap(self)->writable_addr();
}

size_t sk_pixmap_get_row_bytes(const sk_pixmap_t *self)
{
  return AsPixmap(self)->rowBytes();
}

int32_t sk_pixmap_get_width(const sk_pixmap_t *self)
{
  return AsPixmap(self)->width();
}

bool sk_pixmap_read_pixels(const sk_pixmap_t *self, const sk_pixmap_t *dest, int32_t src_x, int32_t src_y)
{
  return AsPixmap(self)->readPixels(AsPixmap(*dest), src_x, src_y);
}

bool sk_pixmap_scale_pixels(const sk_pixmap_t *self, const sk_pixmap_t *dest, const sk_samplingoptions_t *sampling)
{
  return AsPixmap(self)->scalePixels(AsPixmap(*dest), AsSamplingOptions(*sampling));
}

void sk_pixmap_set_colorspace(sk_pixmap_t *self, sk_colorspace_t *value)
{
  AsPixmap(self)->setColorSpace(sk_ref_sp(AsColorSpace(value)));
}
