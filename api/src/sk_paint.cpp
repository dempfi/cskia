#include "include/sk_paint.h"
#include "include/core/SkPaint.h"

sk_paint_t *sk_paint_new(void)
{
  return reinterpret_cast<sk_paint_t *>(new SkPaint());
};

void sk_paint_delete(sk_paint_t *paint)
{
  delete reinterpret_cast<SkPaint *>(paint);
};

void sk_paint_reset(sk_paint_t *paint)
{
  reinterpret_cast<SkPaint *>(paint)->reset();
};

bool sk_paint_is_antialias(const sk_paint_t *paint)
{
  return reinterpret_cast<const SkPaint *>(paint)->isAntiAlias();
};

void sk_paint_set_antialias(sk_paint_t *paint, bool antialias)
{
  reinterpret_cast<SkPaint *>(paint)->setAntiAlias(antialias);
};

sk_color_t sk_paint_get_color(const sk_paint_t *paint)
{
  return reinterpret_cast<const SkPaint *>(paint)->getColor();
};

void sk_paint_set_color(sk_paint_t *paint, sk_color_t color)
{
  reinterpret_cast<SkPaint *>(paint)->setColor(color);
};

sk_paint_style_t sk_paint_get_style(const sk_paint_t *paint)
{
  return static_cast<sk_paint_style_t>(reinterpret_cast<const SkPaint *>(paint)->getStyle());
};

void sk_paint_set_style(sk_paint_t *paint, sk_paint_style_t style)
{
  reinterpret_cast<SkPaint *>(paint)->setStyle(static_cast<SkPaint::Style>(style));
};

float sk_paint_get_stroke_width(const sk_paint_t *paint)
{
  return reinterpret_cast<const SkPaint *>(paint)->getStrokeWidth();
};

void sk_paint_set_stroke_width(sk_paint_t *paint, float width)
{
  reinterpret_cast<SkPaint *>(paint)->setStrokeWidth(width);
};

float sk_paint_get_stroke_miter(const sk_paint_t *paint)
{
  return reinterpret_cast<const SkPaint *>(paint)->getStrokeMiter();
};

void sk_paint_set_stroke_miter(sk_paint_t *paint, float miter)
{
  reinterpret_cast<SkPaint *>(paint)->setStrokeMiter(miter);
}

sk_stroke_cap_t sk_paint_get_stroke_cap(const sk_paint_t *paint)
{
  return (sk_stroke_cap_t) reinterpret_cast<const SkPaint *>(paint)->getStrokeCap();
};

void sk_paint_set_stroke_cap(sk_paint_t *paint, sk_stroke_cap_t cap)
{
  reinterpret_cast<SkPaint *>(paint)->setStrokeCap((SkPaint::Cap)cap);
};

sk_stroke_join_t sk_paint_get_stroke_join(const sk_paint_t *paint)
{
  return (sk_stroke_join_t) reinterpret_cast<const SkPaint *>(paint)->getStrokeJoin();
};

void sk_paint_set_stroke_join(sk_paint_t *paint, sk_stroke_join_t join)
{
  reinterpret_cast<SkPaint *>(paint)->setStrokeJoin((SkPaint::Join)join);
};

bool sk_paint_is_dither(const sk_paint_t *paint)
{
  return reinterpret_cast<const SkPaint *>(paint)->isDither();
};

void sk_paint_set_dither(sk_paint_t *paint, bool dither)
{
  reinterpret_cast<SkPaint *>(paint)->setDither(dither);
};
