#include "include/sk_paint.h"
#include "sk_mapping.h"
#include "include/core/SkPathUtils.h"

#include <memory>

sk_paint_t *sk_paint_create(void)
{
  return ToPaint(new SkPaint());
}

sk_paint_t *sk_paint_create2(const sk_paint_t *paint)
{
  return ToPaint(new SkPaint(AsPaint(*paint)));
}

void sk_paint_destroy(sk_paint_t *self)
{
  delete AsPaint(self);
}

uint8_t sk_paint_get_alpha(const sk_paint_t *self)
{
  return AsPaint(self)->getAlpha();
}

float sk_paint_get_alphaf(const sk_paint_t *self)
{
  return AsPaint(self)->getAlphaf();
}

bool sk_paint_get_antialias(const sk_paint_t *self)
{
  return AsPaint(self)->isAntiAlias();
}

sk_blender_t *sk_paint_get_blender(const sk_paint_t *self)
{
  return ToBlender(AsPaint(self)->refBlender().release());
}

sk_color_t sk_paint_get_color(const sk_paint_t *self)
{
  return AsPaint(self)->getColor();
}

void sk_paint_get_colorf(const sk_paint_t *self, sk_color4f_t *result)
{
  *result = ToColor4f(AsPaint(self)->getColor4f());
}

sk_colorfilter_t *sk_paint_get_color_filter(const sk_paint_t *self)
{
  return ToColorFilter(AsPaint(self)->refColorFilter().release());
}

bool sk_paint_get_dither(const sk_paint_t *self)
{
  return AsPaint(self)->isDither();
}

sk_path_t *sk_paint_get_fill_path(const sk_paint_t *self, const sk_path_t *path, const sk_rect_t *cull_rect, float res_scale)
{
  auto r = std::make_unique<SkPath>();
  return skpathutils::FillPathWithPaint(AsPath(*path), AsPaint(*self), r.get(), AsRect(cull_rect), res_scale) ? ToPath(r.release()) : nullptr;
}

sk_imagefilter_t *sk_paint_get_image_filter(const sk_paint_t *self)
{
  return ToImageFilter(AsPaint(self)->refImageFilter().release());
}

sk_maskfilter_t *sk_paint_get_mask_filter(const sk_paint_t *self)
{
  return ToMaskFilter(AsPaint(self)->refMaskFilter().release());
}

sk_patheffect_t *sk_paint_get_path_effect(const sk_paint_t *self)
{
  return ToPathEffect(AsPaint(self)->refPathEffect().release());
}

sk_shader_t *sk_paint_get_shader(const sk_paint_t *self)
{
  return ToShader(AsPaint(self)->refShader().release());
}

sk_strokecap_t sk_paint_get_stroke_cap(const sk_paint_t *self)
{
  return ToStrokeCap(AsPaint(self)->getStrokeCap());
}

sk_strokejoin_t sk_paint_get_stroke_join(const sk_paint_t *self)
{
  return ToStrokeJoin(AsPaint(self)->getStrokeJoin());
}

float sk_paint_get_stroke_miter(const sk_paint_t *self)
{
  return AsPaint(self)->getStrokeMiter();
}

float sk_paint_get_stroke_width(const sk_paint_t *self)
{
  return AsPaint(self)->getStrokeWidth();
}

sk_paintstyle_t sk_paint_get_style(const sk_paint_t *self)
{
  return ToPaintStyle(AsPaint(self)->getStyle());
}

void sk_paint_reset(sk_paint_t *self)
{
  AsPaint(self)->reset();
}

void sk_paint_set_alpha(sk_paint_t *self, uint8_t value)
{
  AsPaint(self)->setAlpha(value);
}

void sk_paint_set_alphaf(sk_paint_t *self, float value)
{
  AsPaint(self)->setAlphaf(value);
}

void sk_paint_set_antialias(sk_paint_t *self, bool value)
{
  AsPaint(self)->setAntiAlias(value);
}

void sk_paint_set_argb(sk_paint_t *self, uint8_t a, uint8_t r, uint8_t g, uint8_t b)
{
  AsPaint(self)->setARGB(a, r, g, b);
}

void sk_paint_set_blender(sk_paint_t *self, sk_blender_t *value)
{
  AsPaint(self)->setBlender(sk_ref_sp(AsBlender(value)));
}

void sk_paint_set_color(sk_paint_t *self, sk_color_t value)
{
  AsPaint(self)->setColor(value);
}

void sk_paint_set_color_filter(sk_paint_t *self, sk_colorfilter_t *value)
{
  AsPaint(self)->setColorFilter(sk_ref_sp(AsColorFilter(value)));
}

void sk_paint_set_colorf(sk_paint_t *self, const sk_color4f_t *value, sk_colorspace_t *color_space)
{
  AsPaint(self)->setColor(AsColor4f(*value), AsColorSpace(color_space));
}

void sk_paint_set_dither(sk_paint_t *self, bool value)
{
  AsPaint(self)->setDither(value);
}

void sk_paint_set_image_filter(sk_paint_t *self, sk_imagefilter_t *value)
{
  AsPaint(self)->setImageFilter(sk_ref_sp(AsImageFilter(value)));
}

void sk_paint_set_mask_filter(sk_paint_t *self, sk_maskfilter_t *value)
{
  AsPaint(self)->setMaskFilter(sk_ref_sp(AsMaskFilter(value)));
}

void sk_paint_set_path_effect(sk_paint_t *self, sk_patheffect_t *value)
{
  AsPaint(self)->setPathEffect(sk_ref_sp(AsPathEffect(value)));
}

void sk_paint_set_shader(sk_paint_t *self, sk_shader_t *value)
{
  AsPaint(self)->setShader(sk_ref_sp(AsShader(value)));
}

void sk_paint_set_stroke_cap(sk_paint_t *self, sk_strokecap_t value)
{
  AsPaint(self)->setStrokeCap(AsStrokeCap(value));
}

void sk_paint_set_stroke_join(sk_paint_t *self, sk_strokejoin_t value)
{
  AsPaint(self)->setStrokeJoin(AsStrokeJoin(value));
}

void sk_paint_set_stroke_miter(sk_paint_t *self, float value)
{
  AsPaint(self)->setStrokeMiter(value);
}

void sk_paint_set_stroke_width(sk_paint_t *self, float value)
{
  AsPaint(self)->setStrokeWidth(value);
}

void sk_paint_set_style(sk_paint_t *self, sk_paintstyle_t value)
{
  AsPaint(self)->setStyle(AsPaintStyle(value));
}
