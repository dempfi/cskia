#include "sk_mapping.h"
#include "include/sk_paint.h"
#include "include/core/SkPaint.h"
#include "include/core/SkPathEffect.h"

sk_paint_t *sk_paint_new(void)
{
  return ToPaint(new SkPaint());
};

void sk_paint_delete(sk_paint_t *paint)
{
  delete AsPaint(paint);
};

void sk_paint_reset(sk_paint_t *paint)
{
  AsPaint(paint)->reset();
};

bool sk_paint_is_antialias(const sk_paint_t *paint)
{
  return AsPaint(paint)->isAntiAlias();
};

void sk_paint_set_antialias(sk_paint_t *paint, bool antialias)
{
  AsPaint(paint)->setAntiAlias(antialias);
};

sk_color_t sk_paint_get_color(const sk_paint_t *paint)
{
  return AsPaint(paint)->getColor();
};

void sk_paint_set_color(sk_paint_t *paint, sk_color_t color)
{
  AsPaint(paint)->setColor(color);
};

sk_paint_style_t sk_paint_get_style(const sk_paint_t *paint)
{
  return static_cast<sk_paint_style_t>(AsPaint(paint)->getStyle());
};

void sk_paint_set_style(sk_paint_t *paint, sk_paint_style_t style)
{
  AsPaint(paint)->setStyle(static_cast<SkPaint::Style>(style));
};

float sk_paint_get_stroke_width(const sk_paint_t *paint)
{
  return AsPaint(paint)->getStrokeWidth();
};

void sk_paint_set_stroke_width(sk_paint_t *paint, float width)
{
  AsPaint(paint)->setStrokeWidth(width);
};

float sk_paint_get_stroke_miter(const sk_paint_t *paint)
{
  return AsPaint(paint)->getStrokeMiter();
};

void sk_paint_set_stroke_miter(sk_paint_t *paint, float miter)
{
  AsPaint(paint)->setStrokeMiter(miter);
}

sk_stroke_cap_t sk_paint_get_stroke_cap(const sk_paint_t *paint)
{
  return (sk_stroke_cap_t)AsPaint(paint)->getStrokeCap();
};

void sk_paint_set_stroke_cap(sk_paint_t *paint, sk_stroke_cap_t cap)
{
  AsPaint(paint)->setStrokeCap((SkPaint::Cap)cap);
};

sk_stroke_join_t sk_paint_get_stroke_join(const sk_paint_t *paint)
{
  return (sk_stroke_join_t)AsPaint(paint)->getStrokeJoin();
};

void sk_paint_set_stroke_join(sk_paint_t *paint, sk_stroke_join_t join)
{
  AsPaint(paint)->setStrokeJoin((SkPaint::Join)join);
};

bool sk_paint_is_dither(const sk_paint_t *paint)
{
  return AsPaint(paint)->isDither();
};

void sk_paint_set_dither(sk_paint_t *paint, bool dither)
{
  AsPaint(paint)->setDither(dither);
};

void sk_paint_set_path_effect(sk_paint_t *paint, sk_path_effect_t *effect)
{
  AsPaint(paint)->setPathEffect(sk_ref_sp(reinterpret_cast<SkPathEffect *>(effect)));
}

sk_path_effect_t *sk_paint_get_path_effect(sk_paint_t *paint)
{
  return reinterpret_cast<sk_path_effect_t *>(AsPaint(paint)->refPathEffect().release());
}
