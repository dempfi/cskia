#include "sk_mapping.h"
#include "include/sk_font.h"
#include "include/core/SkFont.h"

sk_font_t *sk_font_new(void)
{
  return ToFont(new SkFont());
};

sk_font_t *sk_font_new_with_values(sk_typeface_t *typeface, float size, float scaleX, float skewX)
{
  return ToFont(new SkFont(sk_ref_sp(AsTypeface(typeface)), size, scaleX, skewX));
};

void sk_font_delete(sk_font_t *font)
{
  delete AsFont(font);
};

bool sk_font_is_force_auto_hinting(const sk_font_t *font)
{
  return AsFont(font)->isForceAutoHinting();
};

void sk_font_set_force_auto_hinting(sk_font_t *font, bool value)
{
  AsFont(font)->setForceAutoHinting(value);
};

bool sk_font_is_embedded_bitmaps(const sk_font_t *font)
{
  return AsFont(font)->isEmbeddedBitmaps();
};

void sk_font_set_embedded_bitmaps(sk_font_t *font, bool value)
{
  AsFont(font)->setEmbeddedBitmaps(value);
};

bool sk_font_is_subpixel(const sk_font_t *font)
{
  return AsFont(font)->isSubpixel();
};

void sk_font_set_subpixel(sk_font_t *font, bool value)
{
  AsFont(font)->setSubpixel(value);
};

bool sk_font_is_linear_metrics(const sk_font_t *font)
{
  return AsFont(font)->isLinearMetrics();
};

void sk_font_set_linear_metrics(sk_font_t *font, bool value)
{
  AsFont(font)->setLinearMetrics(value);
};

bool sk_font_is_embolden(const sk_font_t *font)
{
  return AsFont(font)->isEmbolden();
};

void sk_font_set_embolden(sk_font_t *font, bool value)
{
  AsFont(font)->setEmbolden(value);
};

bool sk_font_is_baseline_snap(const sk_font_t *font)
{
  return AsFont(font)->isBaselineSnap();
};

void sk_font_set_baseline_snap(sk_font_t *font, bool value)
{
  AsFont(font)->setBaselineSnap(value);
};

sk_font_edging_t sk_font_get_edging(const sk_font_t *font)
{
  return static_cast<sk_font_edging_t>(AsFont(font)->getEdging());
};

void sk_font_set_edging(sk_font_t *font, sk_font_edging_t value)
{
  AsFont(font)->setEdging(static_cast<SkFont::Edging>(value));
};

sk_font_hinting_t sk_font_get_hinting(const sk_font_t *font)
{
  return static_cast<sk_font_hinting_t>(AsFont(font)->getHinting());
};

void sk_font_set_hinting(sk_font_t *font, sk_font_hinting_t value)
{
  AsFont(font)->setHinting(static_cast<SkFontHinting>(value));
};

sk_typeface_t *sk_font_get_typeface(const sk_font_t *font)
{
  return ToTypeface(AsFont(font)->getTypeface());
};

void sk_font_set_typeface(sk_font_t *font, sk_typeface_t *value)
{
  AsFont(font)->setTypeface(sk_ref_sp(AsTypeface(value)));
};

float sk_font_get_size(const sk_font_t *font)
{
  return AsFont(font)->getSize();
};

void sk_font_set_size(sk_font_t *font, float value)
{
  AsFont(font)->setSize(value);
};

float sk_font_get_scale_x(const sk_font_t *font)
{
  return AsFont(font)->getScaleX();
};

void sk_font_set_scale_x(sk_font_t *font, float value)
{
  AsFont(font)->setScaleX(value);
};

float sk_font_get_skew_x(const sk_font_t *font)
{
  return AsFont(font)->getSkewX();
};

void sk_font_set_skew_x(sk_font_t *font, float value)
{
  AsFont(font)->setSkewX(value);
};

int sk_font_text_to_glyphs(const sk_font_t *font, const void *text, size_t byteLength, sk_text_encoding_t encoding, uint16_t glyphs[], int maxGlyphCount)
{
  return AsFont(font)->textToGlyphs(text, byteLength, (SkTextEncoding)encoding, glyphs, maxGlyphCount);
};

uint16_t sk_font_unichar_to_glyph(const sk_font_t *font, int32_t uni)
{
  return AsFont(font)->unicharToGlyph(uni);
};

void sk_font_unichars_to_glyphs(const sk_font_t *font, const int32_t uni[], int count, uint16_t glyphs[])
{
  AsFont(font)->unicharsToGlyphs(uni, count, glyphs);
};

float sk_font_measure_text(const sk_font_t *font, const void *text, size_t byteLength, sk_text_encoding_t encoding, sk_rect_t *bounds, const sk_paint_t *paint)
{
  return AsFont(font)->measureText(text, byteLength, (SkTextEncoding)encoding, AsRect(bounds), AsPaint(paint));
};

void sk_font_get_widths_bounds(const sk_font_t *font, const uint16_t glyphs[], int count, float widths[], sk_rect_t bounds[], const sk_paint_t *paint)
{
  AsFont(font)->getWidthsBounds(glyphs, count, widths, AsRect(bounds), AsPaint(paint));
};

void sk_font_get_pos(const sk_font_t *font, const uint16_t glyphs[], int count, sk_point_t pos[], sk_point_t *origin)
{
  AsFont(font)->getPos(glyphs, count, AsPoint(pos), AsPoint(*origin));
};

void sk_font_get_xpos(const sk_font_t *font, const uint16_t glyphs[], int count, float xpos[], float origin)
{
  AsFont(font)->getXPos(glyphs, count, xpos, origin);
};

bool sk_font_get_path(const sk_font_t *font, uint16_t glyph, sk_path_t *path)
{
  return AsFont(font)->getPath(glyph, AsPath(path));
};

float sk_font_get_metrics(const sk_font_t *font, sk_fontmetrics_t *metrics)
{
  return AsFont(font)->getMetrics(AsFontMetrics(metrics));
};
