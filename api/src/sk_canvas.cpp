#include "sk_mapping.h"
#include "include/sk_canvas.h"
#include "include/core/SkCanvas.h"
#include "include/utils/SkShadowUtils.h"

int sk_canvas_save(sk_canvas_t *canvas)
{
  return AsCanvas(canvas)->save();
};

int sk_canvas_save_layer(sk_canvas_t *canvas, const sk_rect_t *rect, const sk_paint_t *paint)
{
  return AsCanvas(canvas)->saveLayer(AsRect(rect), AsPaint(paint));
};

void sk_canvas_restore(sk_canvas_t *canvas)
{
  AsCanvas(canvas)->restore();
};

void sk_canvas_translate(sk_canvas_t *canvas, float dx, float dy)
{
  AsCanvas(canvas)->translate(dx, dy);
}

void sk_canvas_scale(sk_canvas_t *canvas, float sx, float sy)
{
  AsCanvas(canvas)->scale(sx, sy);
};

void sk_canvas_rotate_radians(sk_canvas_t *canvas, float radians)
{
  AsCanvas(canvas)->rotate(radians);
};

void sk_canvas_skew(sk_canvas_t *canvas, float sx, float sy)
{
  AsCanvas(canvas)->skew(sx, sy);
};

void sk_canvas_draw_paint(sk_canvas_t *canvas, const sk_paint_t *paint)
{
  AsCanvas(canvas)->drawPaint(*AsPaint(paint));
};

void sk_canvas_draw_rect(sk_canvas_t *canvas, const sk_rect_t *rect, const sk_paint_t *paint)
{
  AsCanvas(canvas)->drawRect(*AsRect(rect), *AsPaint(paint));
};

void sk_canvas_draw_rrect(sk_canvas_t *canvas, const sk_rrect_t *rect, const sk_paint_t *paint)
{
  AsCanvas(canvas)->drawRRect(*AsRRect(rect), *AsPaint(paint));
};

void sk_canvas_draw_circle(sk_canvas_t *canvas, float cx, float cy, float radius, const sk_paint_t *paint)
{
  AsCanvas(canvas)->drawCircle(cx, cy, radius, *AsPaint(paint));
};

void sk_canvas_draw_path(sk_canvas_t *canvas, const sk_path_t *path, const sk_paint_t *paint)
{
  AsCanvas(canvas)->drawPath(*AsPath(path), *AsPaint(paint));
};

void sk_canvas_draw_line(sk_canvas_t *canvas, float x0, float y0, float x1, float y1, sk_paint_t *paint)
{
  AsCanvas(canvas)->drawLine(x0, y0, x1, y1, *AsPaint(paint));
};

void sk_canvas_draw_round_rect(sk_canvas_t *canvas, const sk_rect_t *rect, float rx, float ry, const sk_paint_t *paint)
{
  AsCanvas(canvas)->drawRoundRect(*AsRect(rect), rx, ry, *AsPaint(paint));
};

void sk_canvas_draw_arc(sk_canvas_t *canvas, const sk_rect_t *oval, float startAngle, float sweepAngle, bool useCenter, const sk_paint_t *paint)
{
  AsCanvas(canvas)->drawArc(*AsRect(oval), startAngle, sweepAngle, useCenter, *AsPaint(paint));
};

void sk_canvas_draw_drrect(sk_canvas_t *canvas, const sk_rrect_t *outer, const sk_rrect_t *inner, const sk_paint_t *paint)
{
  AsCanvas(canvas)->drawDRRect(*AsRRect(outer), *AsRRect(inner), *AsPaint(paint));
};

void sk_canvas_draw_oval(sk_canvas_t *canvas, const sk_rect_t *rect, const sk_paint_t *paint)
{
  AsCanvas(canvas)->drawOval(*AsRect(rect), *AsPaint(paint));
};

void sk_canvas_draw_image(sk_canvas_t *canvas, const sk_image_t *image, float dx, float dy, const sk_sampling_options_t *samplingOptions, const sk_paint_t *paint)
{
  AsCanvas(canvas)->drawImage(AsImage(image), dx, dy, *reinterpret_cast<const SkSamplingOptions *>(samplingOptions), AsPaint(paint));
};

void sk_canvas_draw_image_nine(sk_canvas_t *canvas, const sk_image_t *image, const sk_rect_t *center, const sk_rect_t *dst, sk_filter_mode_t filterMode, const sk_paint_t *paint)
{
  AsCanvas(canvas)->drawImageNine(AsImage(image), *reinterpret_cast<const SkIRect *>(center), *AsRect(dst), (SkFilterMode)filterMode, AsPaint(paint));
};

void sk_canvas_draw_image_rect(sk_canvas_t *canvas, const sk_image_t *image, const sk_rect_t *src, const sk_rect_t *dst, const sk_sampling_options_t *samplingOptions, const sk_paint_t *paint, sk_src_rect_constraint_t constraint)
{
  if (src)
  {
    AsCanvas(canvas)->drawImageRect(AsImage(image), *AsRect(src), *AsRect(dst), *reinterpret_cast<const SkSamplingOptions *>(samplingOptions), AsPaint(paint), (SkCanvas::SrcRectConstraint)constraint);
  }
  else
  {
    AsCanvas(canvas)->drawImageRect(AsImage(image), *AsRect(dst), *reinterpret_cast<const SkSamplingOptions *>(samplingOptions), AsPaint(paint));
  }
}

void sk_canvas_draw_simple_text(sk_canvas_t *canvas, const void *text, size_t byte_length, sk_text_encoding_t encoding, float x, float y, const sk_font_t *font, const sk_paint_t *paint)
{
  AsCanvas(canvas)->drawSimpleText(text, byte_length, (SkTextEncoding)encoding, x, y, *AsFont(font), *AsPaint(paint));
};

void sk_canvas_draw_text_blob(sk_canvas_t *canvas, sk_textblob_t *text, float x, float y, const sk_paint_t *cpaint)
{
  AsCanvas(canvas)->drawTextBlob(AsTextBlob(text), x, y, *AsPaint(cpaint));
}

void sk_canvas_draw_shadow(sk_canvas_t *canvas, const sk_path_t *path, const sk_point3_t *zPlaneParams, const sk_point3_t *lightPos, float lightRadius, sk_color_t ambientColor, sk_color_t spotColor, sk_shadow_flags_t flag)
{
  SkShadowUtils::DrawShadow(AsCanvas(canvas), *AsPath(path), *AsPoint3(zPlaneParams), *AsPoint3(lightPos), lightRadius, ambientColor, spotColor, (SkShadowFlags)flag);
}

void sk_canvas_clear(sk_canvas_t *canvas, sk_color_t color)
{
  AsCanvas(canvas)->clear(color);
};

void sk_canvas_discard(sk_canvas_t *canvas)
{
  return AsCanvas(canvas)->discard();
};

int sk_canvas_get_save_count(sk_canvas_t *canvas)
{
  return AsCanvas(canvas)->getSaveCount();
};

void sk_canvas_get_total_matrix(sk_canvas_t *canvas, sk_matrix_t *matrix)
{
  SkMatrix totalMatrix = AsCanvas(canvas)->getTotalMatrix();
  *matrix = ToMatrix(&totalMatrix);
};

void sk_canvas_restore_to_count(sk_canvas_t *canvas, int saveCount)
{
  return AsCanvas(canvas)->restoreToCount(saveCount);
};
