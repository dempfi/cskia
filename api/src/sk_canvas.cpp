#include "include/sk_canvas.h"
#include "include/core/SkCanvas.h"

int sk_canvas_save(sk_canvas_t *canvas)
{
  return reinterpret_cast<SkCanvas *>(canvas)->save();
};

int sk_canvas_save_layer(sk_canvas_t *canvas, const sk_rect_t *rect, const sk_paint_t *paint)
{
  return reinterpret_cast<SkCanvas *>(canvas)->saveLayer(reinterpret_cast<const SkRect *>(rect), reinterpret_cast<const SkPaint *>(paint));
};

void sk_canvas_restore(sk_canvas_t *canvas)
{
  reinterpret_cast<SkCanvas *>(canvas)->restore();
};

void sk_canvas_translate(sk_canvas_t *canvas, float dx, float dy)
{
  reinterpret_cast<SkCanvas *>(canvas)->translate(dx, dy);
}

void sk_canvas_scale(sk_canvas_t *canvas, float sx, float sy)
{
  reinterpret_cast<SkCanvas *>(canvas)->scale(sx, sy);
};

void sk_canvas_rotate_radians(sk_canvas_t *canvas, float radians)
{
  reinterpret_cast<SkCanvas *>(canvas)->rotate(radians);
};

void sk_canvas_skew(sk_canvas_t *canvas, float sx, float sy)
{
  reinterpret_cast<SkCanvas *>(canvas)->skew(sx, sy);
};

void sk_canvas_draw_paint(sk_canvas_t *canvas, const sk_paint_t *paint)
{
  reinterpret_cast<SkCanvas *>(canvas)->drawPaint(*reinterpret_cast<const SkPaint *>(paint));
};

void sk_canvas_draw_rect(sk_canvas_t *canvas, const sk_rect_t *rect, const sk_paint_t *paint)
{
  reinterpret_cast<SkCanvas *>(canvas)->drawRect(*reinterpret_cast<const SkRect *>(rect), *reinterpret_cast<const SkPaint *>(paint));
};

void sk_canvas_draw_rrect(sk_canvas_t *canvas, const sk_rrect_t *rect, const sk_paint_t *paint)
{
  reinterpret_cast<SkCanvas *>(canvas)->drawRRect(*reinterpret_cast<const SkRRect *>(rect), *reinterpret_cast<const SkPaint *>(paint));
};

void sk_canvas_draw_circle(sk_canvas_t *canvas, float cx, float cy, float radius, const sk_paint_t *paint)
{
  reinterpret_cast<SkCanvas *>(canvas)->drawCircle(cx, cy, radius, *reinterpret_cast<const SkPaint *>(paint));
};

void sk_canvas_draw_path(sk_canvas_t *canvas, const sk_path_t *path, const sk_paint_t *paint)
{
  reinterpret_cast<SkCanvas *>(canvas)->drawPath(*reinterpret_cast<const SkPath *>(path), *reinterpret_cast<const SkPaint *>(paint));
};

void sk_canvas_draw_line(sk_canvas_t *canvas, float x0, float y0, float x1, float y1, sk_paint_t *paint)
{
  reinterpret_cast<SkCanvas *>(canvas)->drawLine(x0, y0, x1, y1, *reinterpret_cast<const SkPaint *>(paint));
};

void sk_canvas_draw_round_rect(sk_canvas_t *canvas, const sk_rect_t *rect, float rx, float ry, const sk_paint_t *paint)
{
  reinterpret_cast<SkCanvas *>(canvas)->drawRoundRect(*reinterpret_cast<const SkRect *>(rect), rx, ry, *reinterpret_cast<const SkPaint *>(paint));
};

void sk_canvas_draw_arc(sk_canvas_t *canvas, const sk_rect_t *oval, float startAngle, float sweepAngle, bool useCenter, const sk_paint_t *paint)
{
  reinterpret_cast<SkCanvas *>(canvas)->drawArc(*reinterpret_cast<const SkRect *>(oval), startAngle, sweepAngle, useCenter, *reinterpret_cast<const SkPaint *>(paint));
};

void sk_canvas_draw_drrect(sk_canvas_t *canvas, const sk_rrect_t *outer, const sk_rrect_t *inner, const sk_paint_t *paint)
{
  reinterpret_cast<SkCanvas *>(canvas)->drawDRRect(*reinterpret_cast<const SkRRect *>(outer), *reinterpret_cast<const SkRRect *>(inner), *reinterpret_cast<const SkPaint *>(paint));
};

void sk_canvas_draw_oval(sk_canvas_t *canvas, const sk_rect_t *rect, const sk_paint_t *paint)
{
  reinterpret_cast<SkCanvas *>(canvas)->drawOval(*reinterpret_cast<const SkRect *>(rect), *reinterpret_cast<const SkPaint *>(paint));
};

void sk_canvas_draw_image(sk_canvas_t *canvas, const sk_image_t *image, float dx, float dy, const sk_sampling_options_t *samplingOptions, const sk_paint_t *paint)
{
  reinterpret_cast<SkCanvas *>(canvas)->drawImage(reinterpret_cast<const SkImage *>(image), dx, dy, *reinterpret_cast<const SkSamplingOptions *>(samplingOptions), reinterpret_cast<const SkPaint *>(paint));
};

void sk_canvas_draw_image_rect(sk_canvas_t *canvas, const sk_image_t *image, const sk_rect_t *src, const sk_rect_t *dst, const sk_sampling_options_t *samplingOptions, const sk_paint_t *paint, sk_src_rect_constraint_t constraint)
{
  if (src)
  {
    reinterpret_cast<SkCanvas *>(canvas)->drawImageRect(reinterpret_cast<const SkImage *>(image), *reinterpret_cast<const SkRect *>(src), *reinterpret_cast<const SkRect *>(dst), *reinterpret_cast<const SkSamplingOptions *>(samplingOptions), reinterpret_cast<const SkPaint *>(paint), (SkCanvas::SrcRectConstraint)constraint);
  }
  else
  {
    reinterpret_cast<SkCanvas *>(canvas)->drawImageRect(reinterpret_cast<const SkImage *>(image), *reinterpret_cast<const SkRect *>(dst), *reinterpret_cast<const SkSamplingOptions *>(samplingOptions), reinterpret_cast<const SkPaint *>(paint));
  }
}

void sk_canvas_draw_simple_text(sk_canvas_t *canvas, const void *text, size_t byte_length, sk_text_encoding_t encoding, float x, float y, const sk_font_t *font, const sk_paint_t *paint)
{
  reinterpret_cast<SkCanvas *>(canvas)->drawSimpleText(text, byte_length, (SkTextEncoding)encoding, x, y, *reinterpret_cast<const SkFont *>(font), *reinterpret_cast<const SkPaint *>(paint));
};

void sk_canvas_draw_text_blob(sk_canvas_t *canvas, sk_textblob_t *text, float x, float y, const sk_paint_t *cpaint)
{
  reinterpret_cast<SkCanvas *>(canvas)->drawTextBlob(reinterpret_cast<SkTextBlob *>(text), x, y, *reinterpret_cast<const SkPaint *>(cpaint));
}

void sk_canvas_clear(sk_canvas_t *canvas, sk_color_t color)
{
  reinterpret_cast<SkCanvas *>(canvas)->clear(color);
};

void sk_canvas_discard(sk_canvas_t *canvas)
{
  return reinterpret_cast<SkCanvas *>(canvas)->discard();
};

int sk_canvas_get_save_count(sk_canvas_t *canvas)
{
  return reinterpret_cast<SkCanvas *>(canvas)->getSaveCount();
};

void sk_canvas_restore_to_count(sk_canvas_t *canvas, int saveCount)
{
  return reinterpret_cast<SkCanvas *>(canvas)->restoreToCount(saveCount);
};
