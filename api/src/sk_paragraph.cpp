#include "include/sk_paragraph.h"
#include "modules/skparagraph/include/Paragraph.h"

void sk_paragraph_destroy(sk_paragraph_t *self)
{
  delete reinterpret_cast<skia::textlayout::Paragraph *>(self);
}

bool sk_paragraph_did_exceed_max_lines(sk_paragraph_t *self)
{
  return reinterpret_cast<skia::textlayout::Paragraph *>(self)->didExceedMaxLines();
}

float sk_paragraph_get_alphabetic_baseline(sk_paragraph_t *self)
{
  return reinterpret_cast<skia::textlayout::Paragraph *>(self)->getAlphabeticBaseline();
}

float sk_paragraph_get_height(sk_paragraph_t *self)
{
  return reinterpret_cast<skia::textlayout::Paragraph *>(self)->getHeight();
}

float sk_paragraph_get_ideographic_baseline(sk_paragraph_t *self)
{
  return reinterpret_cast<skia::textlayout::Paragraph *>(self)->getIdeographicBaseline();
}

float sk_paragraph_get_longest_line(sk_paragraph_t *self)
{
  return reinterpret_cast<skia::textlayout::Paragraph *>(self)->getLongestLine();
}

float sk_paragraph_get_max_intrinsic_width(sk_paragraph_t *self)
{
  return reinterpret_cast<skia::textlayout::Paragraph *>(self)->getMaxIntrinsicWidth();
}

float sk_paragraph_get_max_width(sk_paragraph_t *self)
{
  return reinterpret_cast<skia::textlayout::Paragraph *>(self)->getMaxWidth();
}

float sk_paragraph_get_min_intrinsic_width(sk_paragraph_t *self)
{
  return reinterpret_cast<skia::textlayout::Paragraph *>(self)->getMinIntrinsicWidth();
}

void sk_paragraph_get_word_boundary(sk_paragraph_t *self, uint32_t offset, uint32_t *start, uint32_t *end)
{
  auto result = reinterpret_cast<skia::textlayout::Paragraph *>(self)->getWordBoundary(offset);
  *start = result.start;
  *end = result.end;
}

void sk_paragraph_layout(sk_paragraph_t *self, float width)
{
  reinterpret_cast<skia::textlayout::Paragraph *>(self)->layout(width);
}

void sk_paragraph_paint(sk_paragraph_t *self, sk_canvas_t *canvas, float x, float y)
{
  reinterpret_cast<skia::textlayout::Paragraph *>(self)->paint(reinterpret_cast<SkCanvas *>(canvas), x, y);
}
