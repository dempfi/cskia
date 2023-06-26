#include "include/sk_font.h"
#include "include/core/SkFont.h"

sk_font_t *sk_font_new(void)
{
  return reinterpret_cast<sk_font_t *>(new SkFont());
};

sk_font_t *sk_font_new_with_values(sk_typeface_t *typeface, float size, float scaleX, float skewX)
{
  return reinterpret_cast<sk_font_t *>(new SkFont(sk_ref_sp(reinterpret_cast<SkTypeface *>(typeface)), size, scaleX, skewX));
};

void sk_font_delete(sk_font_t *font)
{
  delete reinterpret_cast<SkFont *>(font);
};

bool sk_font_is_force_auto_hinting(const sk_font_t *font)
{
  return reinterpret_cast<const SkFont *>(font)->isForceAutoHinting();
};

void sk_font_set_force_auto_hinting(sk_font_t *font, bool value)
{
  reinterpret_cast<SkFont *>(font)->setForceAutoHinting(value);
};

bool sk_font_is_embedded_bitmaps(const sk_font_t *font)
{
  return reinterpret_cast<const SkFont *>(font)->isEmbeddedBitmaps();
};

void sk_font_set_embedded_bitmaps(sk_font_t *font, bool value)
{
  reinterpret_cast<SkFont *>(font)->setEmbeddedBitmaps(value);
};

bool sk_font_is_subpixel(const sk_font_t *font)
{
  return reinterpret_cast<const SkFont *>(font)->isSubpixel();
};

void sk_font_set_subpixel(sk_font_t *font, bool value)
{
  reinterpret_cast<SkFont *>(font)->setSubpixel(value);
};

bool sk_font_is_linear_metrics(const sk_font_t *font)
{
  return reinterpret_cast<const SkFont *>(font)->isLinearMetrics();
};

void sk_font_set_linear_metrics(sk_font_t *font, bool value)
{
  reinterpret_cast<SkFont *>(font)->setLinearMetrics(value);
};

bool sk_font_is_embolden(const sk_font_t *font)
{
  return reinterpret_cast<const SkFont *>(font)->isEmbolden();
};

void sk_font_set_embolden(sk_font_t *font, bool value)
{
  reinterpret_cast<SkFont *>(font)->setEmbolden(value);
};

bool sk_font_is_baseline_snap(const sk_font_t *font)
{
  return reinterpret_cast<const SkFont *>(font)->isBaselineSnap();
};

void sk_font_set_baseline_snap(sk_font_t *font, bool value)
{
  reinterpret_cast<SkFont *>(font)->setBaselineSnap(value);
};

sk_font_edging_t sk_font_get_edging(const sk_font_t *font)
{
  return static_cast<sk_font_edging_t>(reinterpret_cast<const SkFont *>(font)->getEdging());
};

void sk_font_set_edging(sk_font_t *font, sk_font_edging_t value)
{
  reinterpret_cast<SkFont *>(font)->setEdging(static_cast<SkFont::Edging>(value));
};

sk_font_hinting_t sk_font_get_hinting(const sk_font_t *font)
{
  return static_cast<sk_font_hinting_t>(reinterpret_cast<const SkFont *>(font)->getHinting());
};

void sk_font_set_hinting(sk_font_t *font, sk_font_hinting_t value)
{
  reinterpret_cast<SkFont *>(font)->setHinting(static_cast<SkFontHinting>(value));
};

sk_typeface_t *sk_font_get_typeface(const sk_font_t *font)
{
  return reinterpret_cast<sk_typeface_t *>(reinterpret_cast<const SkFont *>(font)->getTypeface());
};

void sk_font_set_typeface(sk_font_t *font, sk_typeface_t *value)
{
  reinterpret_cast<SkFont *>(font)->setTypeface(sk_ref_sp(reinterpret_cast<SkTypeface *>(value)));
};

float sk_font_get_size(const sk_font_t *font)
{
  return reinterpret_cast<const SkFont *>(font)->getSize();
};

void sk_font_set_size(sk_font_t *font, float value)
{
  reinterpret_cast<SkFont *>(font)->setSize(value);
};

float sk_font_get_scale_x(const sk_font_t *font)
{
  return reinterpret_cast<const SkFont *>(font)->getScaleX();
};

void sk_font_set_scale_x(sk_font_t *font, float value)
{
  reinterpret_cast<SkFont *>(font)->setScaleX(value);
};

float sk_font_get_skew_x(const sk_font_t *font)
{
  return reinterpret_cast<const SkFont *>(font)->getSkewX();
};

void sk_font_set_skew_x(sk_font_t *font, float value)
{
  reinterpret_cast<SkFont *>(font)->setSkewX(value);
};

int sk_font_text_to_glyphs(const sk_font_t *font, const void *text, size_t byteLength, sk_text_encoding_t encoding, uint16_t glyphs[], int maxGlyphCount)
{
  return reinterpret_cast<const SkFont *>(font)->textToGlyphs(text, byteLength, static_cast<SkTextEncoding>(encoding), glyphs, maxGlyphCount);
};

uint16_t sk_font_unichar_to_glyph(const sk_font_t *font, int32_t uni)
{
  return reinterpret_cast<const SkFont *>(font)->unicharToGlyph(uni);
};

void sk_font_unichars_to_glyphs(const sk_font_t *font, const int32_t uni[], int count, uint16_t glyphs[])
{
  reinterpret_cast<const SkFont *>(font)->unicharsToGlyphs(uni, count, glyphs);
};

float sk_font_measure_text(const sk_font_t *font, const void *text, size_t byteLength, sk_text_encoding_t encoding, sk_rect_t *bounds, const sk_paint_t *paint)
{
  return reinterpret_cast<const SkFont *>(font)->measureText(text, byteLength, static_cast<SkTextEncoding>(encoding), reinterpret_cast<SkRect *>(bounds), reinterpret_cast<const SkPaint *>(paint));
};

void sk_font_get_widths_bounds(const sk_font_t *font, const uint16_t glyphs[], int count, float widths[], sk_rect_t bounds[], const sk_paint_t *paint)
{
  reinterpret_cast<const SkFont *>(font)->getWidthsBounds(glyphs, count, widths, reinterpret_cast<SkRect *>(bounds), reinterpret_cast<const SkPaint *>(paint));
};

void sk_font_get_pos(const sk_font_t *font, const uint16_t glyphs[], int count, sk_point_t pos[], sk_point_t *origin)
{
  reinterpret_cast<const SkFont *>(font)->getPos(glyphs, count, reinterpret_cast<SkPoint *>(pos), *reinterpret_cast<const SkPoint *>(origin));
};

void sk_font_get_xpos(const sk_font_t *font, const uint16_t glyphs[], int count, float xpos[], float origin)
{
  reinterpret_cast<const SkFont *>(font)->getXPos(glyphs, count, xpos, origin);
};

bool sk_font_get_path(const sk_font_t *font, uint16_t glyph, sk_path_t *path)
{
  return reinterpret_cast<const SkFont *>(font)->getPath(glyph, reinterpret_cast<SkPath *>(path));
};

float sk_font_get_metrics(const sk_font_t *font, sk_fontmetrics_t *metrics)
{
  return reinterpret_cast<const SkFont *>(font)->getMetrics(reinterpret_cast<SkFontMetrics *>(metrics));
};
