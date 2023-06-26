#include "include/sk_path.h"
#include "include/core/SkPath.h"
#include "include/core/SkString.h"
#include "include/core/SkPathMeasure.h"
#include "include/utils/SkParsePath.h"
#include "include/pathops/SkPathOps.h"

sk_path_t *sk_path_new(void)
{
  return reinterpret_cast<sk_path_t *>(new SkPath());
};

void sk_path_delete(sk_path_t *path)
{
  delete reinterpret_cast<SkPath *>(path);
};

void sk_path_move_to(sk_path_t *path, float x, float y)
{
  reinterpret_cast<SkPath *>(path)->moveTo(x, y);
};

void sk_path_line_to(sk_path_t *path, float x, float y)
{
  reinterpret_cast<SkPath *>(path)->lineTo(x, y);
};

void sk_path_quad_to(sk_path_t *path, float x0, float y0, float x1, float y1)
{
  reinterpret_cast<SkPath *>(path)->quadTo(x0, y0, x1, y1);
};

void sk_path_conic_to(sk_path_t *path, float x0, float y0, float x1, float y1, float w)
{
  reinterpret_cast<SkPath *>(path)->conicTo(x0, y0, x1, y1, w);
};

void sk_path_cubic_to(sk_path_t *path, float x0, float y0, float x1, float y1, float x2, float y2)
{
  reinterpret_cast<SkPath *>(path)->cubicTo(x0, y0, x1, y1, x2, y2);
};

void sk_path_arc_to(sk_path_t *path, float rx, float ry, float xAxisRotate, sk_path_arc_size_t largeArc, sk_path_direction_t sweep, float x, float y)
{
  reinterpret_cast<SkPath *>(path)->arcTo(rx, ry, xAxisRotate, (SkPath::ArcSize)largeArc, (SkPathDirection)sweep, x, y);
};

void sk_path_rarc_to(sk_path_t *path, float rx, float ry, float xAxisRotate, sk_path_arc_size_t largeArc, sk_path_direction_t sweep, float x, float y)
{
  reinterpret_cast<SkPath *>(path)->rArcTo(rx, ry, xAxisRotate, (SkPath::ArcSize)largeArc, (SkPathDirection)sweep, x, y);
};

void sk_path_arc_to_with_oval(sk_path_t *path, const sk_rect_t *oval, float startAngle, float sweepAngle, bool forceMoveTo)
{
  reinterpret_cast<SkPath *>(path)->arcTo(*reinterpret_cast<const SkRect *>(oval), startAngle, sweepAngle, forceMoveTo);
};

void sk_path_arc_to_with_points(sk_path_t *path, float x1, float y1, float x2, float y2, float radius)
{
  reinterpret_cast<SkPath *>(path)->arcTo(x1, y1, x2, y2, radius);
};

void sk_path_close(sk_path_t *path)
{
  reinterpret_cast<SkPath *>(path)->close();
};

void sk_path_add_rect(sk_path_t *path, const sk_rect_t *rect, sk_path_direction_t dir)
{
  reinterpret_cast<SkPath *>(path)->addRect(*reinterpret_cast<const SkRect *>(rect), (SkPathDirection)dir);
};

void sk_path_add_rrect(sk_path_t *path, const sk_rrect_t *rrect, sk_path_direction_t dir)
{
  reinterpret_cast<SkPath *>(path)->addRRect(*reinterpret_cast<const SkRRect *>(rrect), (SkPathDirection)dir);
};

void sk_path_add_rrect_start(sk_path_t *path, const sk_rrect_t *rrect, sk_path_direction_t dir, uint32_t start)
{
  reinterpret_cast<SkPath *>(path)->addRRect(*reinterpret_cast<const SkRRect *>(rrect), (SkPathDirection)dir, start);
};

void sk_path_add_rounded_rect(sk_path_t *path, const sk_rect_t *rect, float rx, float ry, sk_path_direction_t dir)
{
  reinterpret_cast<SkPath *>(path)->addRoundRect(*reinterpret_cast<const SkRect *>(rect), rx, ry, (SkPathDirection)dir);
};

void sk_path_add_oval(sk_path_t *path, const sk_rect_t *rect, sk_path_direction_t dir)
{
  reinterpret_cast<SkPath *>(path)->addOval(*reinterpret_cast<const SkRect *>(rect), (SkPathDirection)dir);
};

void sk_path_add_circle(sk_path_t *path, float x, float y, float radius, sk_path_direction_t dir)
{
  reinterpret_cast<SkPath *>(path)->addCircle(x, y, radius, (SkPathDirection)dir);
};

void sk_path_get_bounds(const sk_path_t *path, sk_rect_t *rect)
{
  SkRect r = reinterpret_cast<const SkPath *>(path)->getBounds();
  *rect = reinterpret_cast<sk_rect_t &>(r);
};

void sk_path_compute_tight_bounds(const sk_path_t *path, sk_rect_t *rect)
{
  SkRect r = reinterpret_cast<const SkPath *>(path)->computeTightBounds();
  *rect = reinterpret_cast<sk_rect_t &>(r);
};

void sk_path_rmove_to(sk_path_t *path, float dx, float dy)
{
  reinterpret_cast<SkPath *>(path)->rMoveTo(dx, dy);
};

void sk_path_rline_to(sk_path_t *path, float dx, float yd)
{
  reinterpret_cast<SkPath *>(path)->rLineTo(dx, yd);
};

void sk_path_rquad_to(sk_path_t *path, float dx0, float dy0, float dx1, float dy1)
{
  reinterpret_cast<SkPath *>(path)->rQuadTo(dx0, dy0, dx1, dy1);
};

void sk_path_rconic_to(sk_path_t *path, float dx0, float dy0, float dx1, float dy1, float w)
{
  reinterpret_cast<SkPath *>(path)->rConicTo(dx0, dy0, dx1, dy1, w);
};

void sk_path_rcubic_to(sk_path_t *path, float dx0, float dy0, float dx1, float dy1, float dx2, float dy2)
{
  reinterpret_cast<SkPath *>(path)->rCubicTo(dx0, dy0, dx1, dy1, dx2, dy2);
};

void sk_path_add_rect_start(sk_path_t *path, const sk_rect_t *crect, sk_path_direction_t cdir, uint32_t startIndex)
{
  reinterpret_cast<SkPath *>(path)->addRect(*reinterpret_cast<const SkRect *>(crect), (SkPathDirection)cdir, startIndex);
};

void sk_path_add_arc(sk_path_t *path, const sk_rect_t *crect, float startAngle, float sweepAngle)
{
  reinterpret_cast<SkPath *>(path)->addArc(*reinterpret_cast<const SkRect *>(crect), startAngle, sweepAngle);
};

sk_path_filltype_t sk_path_get_filltype(sk_path_t *path)
{
  return (sk_path_filltype_t) reinterpret_cast<SkPath *>(path)->getFillType();
};

void sk_path_set_filltype(sk_path_t *path, sk_path_filltype_t filltype)
{
  reinterpret_cast<SkPath *>(path)->setFillType((SkPathFillType)filltype);
};

void sk_path_transform(sk_path_t *path, const sk_matrix_t *cmatrix)
{
  reinterpret_cast<SkPath *>(path)->transform(*reinterpret_cast<const SkMatrix *>(cmatrix));
};

void sk_path_transform_to_dest(const sk_path_t *path, const sk_matrix_t *cmatrix, sk_path_t *destination)
{
  reinterpret_cast<const SkPath *>(path)->transform(*reinterpret_cast<const SkMatrix *>(cmatrix), reinterpret_cast<SkPath *>(destination));
};

sk_path_t *sk_path_clone(const sk_path_t *path)
{
  return reinterpret_cast<sk_path_t *>(new SkPath(*reinterpret_cast<const SkPath *>(path)));
};

void sk_path_add_path_offset(sk_path_t *path, sk_path_t *other, float dx, float dy, sk_path_add_mode_t add_mode)
{
  reinterpret_cast<SkPath *>(path)->addPath(*reinterpret_cast<SkPath *>(other), dx, dy, (SkPath::AddPathMode)add_mode);
};

void sk_path_add_path_matrix(sk_path_t *path, sk_path_t *other, sk_matrix_t *matrix, sk_path_add_mode_t add_mode)
{
  reinterpret_cast<SkPath *>(path)->addPath(*reinterpret_cast<SkPath *>(other), *reinterpret_cast<SkMatrix *>(matrix), (SkPath::AddPathMode)add_mode);
};

void sk_path_add_path(sk_path_t *path, sk_path_t *other, sk_path_add_mode_t add_mode)
{
  reinterpret_cast<SkPath *>(path)->addPath(*reinterpret_cast<SkPath *>(other), (SkPath::AddPathMode)add_mode);
};

void sk_path_add_path_reverse(sk_path_t *path, sk_path_t *other)
{
  reinterpret_cast<SkPath *>(path)->reverseAddPath(*reinterpret_cast<SkPath *>(other));
};

void sk_path_reset(sk_path_t *path)
{
  reinterpret_cast<SkPath *>(path)->reset();
};

void sk_path_rewind(sk_path_t *path)
{
  reinterpret_cast<SkPath *>(path)->rewind();
};

int sk_path_count_points(const sk_path_t *path)
{
  return reinterpret_cast<const SkPath *>(path)->countPoints();
};

int sk_path_count_verbs(const sk_path_t *path)
{
  return reinterpret_cast<const SkPath *>(path)->countVerbs();
};

void sk_path_get_point(const sk_path_t *path, int index, sk_point_t *point)
{
  SkPoint p = reinterpret_cast<const SkPath *>(path)->getPoint(index);
  *point = reinterpret_cast<sk_point_t &>(p);
};

int sk_path_get_points(const sk_path_t *path, sk_point_t *points, int max)
{
  return reinterpret_cast<const SkPath *>(path)->getPoints(reinterpret_cast<SkPoint *>(points), max);
};

bool sk_path_contains(const sk_path_t *path, float x, float y)
{
  return reinterpret_cast<const SkPath *>(path)->contains(x, y);
};

bool sk_path_is_convex(const sk_path_t *path)
{
  return reinterpret_cast<const SkPath *>(path)->isConvex();
};

bool sk_path_parse_svg_string(sk_path_t *path, const char *str)
{
  return SkParsePath::FromSVGString(str, reinterpret_cast<SkPath *>(path));
};

sk_string_t *sk_path_to_svg_string(const sk_path_t *path)
{
  return reinterpret_cast<sk_string_t *>(new SkString(SkParsePath::ToSVGString(*reinterpret_cast<const SkPath *>(path), SkParsePath::PathEncoding::Relative)));
};

bool sk_path_get_last_point(const sk_path_t *path, sk_point_t *point)
{
  return reinterpret_cast<const SkPath *>(path)->getLastPt(reinterpret_cast<SkPoint *>(point));
};

int sk_path_convert_conic_to_quads(const sk_point_t *p0, const sk_point_t *p1, const sk_point_t *p2, float w, sk_point_t *pts, int pow2)
{
  return SkPath::ConvertConicToQuads(*reinterpret_cast<const SkPoint *>(p0), *reinterpret_cast<const SkPoint *>(p1), *reinterpret_cast<const SkPoint *>(p2), w, reinterpret_cast<SkPoint *>(pts), pow2);
};

void sk_path_add_poly(sk_path_t *path, const sk_point_t *points, int count, bool close)
{
  reinterpret_cast<SkPath *>(path)->addPoly(reinterpret_cast<const SkPoint *>(points), count, close);
};

uint32_t sk_path_get_segment_masks(sk_path_t *path)
{
  return reinterpret_cast<SkPath *>(path)->getSegmentMasks();
};

bool sk_path_is_oval(sk_path_t *path, sk_rect_t *bounds)
{
  return reinterpret_cast<SkPath *>(path)->isOval(reinterpret_cast<SkRect *>(bounds));
};

bool sk_path_is_rrect(sk_path_t *path, sk_rrect_t *bounds)
{
  return reinterpret_cast<SkPath *>(path)->isRRect(reinterpret_cast<SkRRect *>(bounds));
};

bool sk_path_is_line(sk_path_t *path, sk_point_t line[2])
{
  return reinterpret_cast<SkPath *>(path)->isLine(reinterpret_cast<SkPoint *>(line));
};

bool sk_path_is_rect(sk_path_t *path, sk_rect_t *rect, bool *isClosed, sk_path_direction_t *direction)
{
  return reinterpret_cast<SkPath *>(path)->isRect(reinterpret_cast<SkRect *>(rect), isClosed, (SkPathDirection *)direction);
};

/* Path Ops */
bool sk_pathop_op(const sk_path_t *one, const sk_path_t *two, sk_pathop_t op, sk_path_t *result)
{
  return (*reinterpret_cast<const SkPath *>(one), *reinterpret_cast<const SkPath *>(two), (SkPathOp)op, reinterpret_cast<SkPath *>(result));
};

bool sk_pathop_simplify(const sk_path_t *path, sk_path_t *result)
{
  return Simplify(*reinterpret_cast<const SkPath *>(path), reinterpret_cast<SkPath *>(result));
};

bool sk_pathop_tight_bounds(const sk_path_t *path, sk_rect_t *result)
{
  return TightBounds(*reinterpret_cast<const SkPath *>(path), reinterpret_cast<SkRect *>(result));
};

bool sk_pathop_as_winding(const sk_path_t *path, sk_path_t *result)
{
  return AsWinding(*reinterpret_cast<const SkPath *>(path), reinterpret_cast<SkPath *>(result));
};

/* Path Op Builder */
sk_opbuilder_t *sk_opbuilder_new(void)
{
  return reinterpret_cast<sk_opbuilder_t *>(new SkOpBuilder());
};

void sk_opbuilder_destroy(sk_opbuilder_t *builder)
{
  delete reinterpret_cast<SkOpBuilder *>(builder);
};

void sk_opbuilder_add(sk_opbuilder_t *builder, const sk_path_t *path, sk_pathop_t op)
{
  reinterpret_cast<SkOpBuilder *>(builder)->add(*reinterpret_cast<const SkPath *>(path), (SkPathOp)op);
};

bool sk_opbuilder_resolve(sk_opbuilder_t *builder, sk_path_t *result)
{
  return reinterpret_cast<SkOpBuilder *>(builder)->resolve(reinterpret_cast<SkPath *>(result));
};

/* Path Measure */
sk_pathmeasure_t *sk_pathmeasure_new(void)
{
  return reinterpret_cast<sk_pathmeasure_t *>(new SkPathMeasure());
};

sk_pathmeasure_t *sk_pathmeasure_new_with_path(const sk_path_t *path, bool forceClosed, float resScale)
{
  return reinterpret_cast<sk_pathmeasure_t *>(new SkPathMeasure(*reinterpret_cast<const SkPath *>(path), forceClosed, resScale));
};

void sk_pathmeasure_destroy(sk_pathmeasure_t *measure)
{
  delete reinterpret_cast<SkPathMeasure *>(measure);
};

void sk_pathmeasure_set_path(sk_pathmeasure_t *measure, const sk_path_t *path, bool forceClosed)
{
  reinterpret_cast<SkPathMeasure *>(measure)->setPath(reinterpret_cast<const SkPath *>(path), forceClosed);
};

float sk_pathmeasure_get_length(sk_pathmeasure_t *measure)
{
  return reinterpret_cast<SkPathMeasure *>(measure)->getLength();
};

bool sk_pathmeasure_get_pos_tan(sk_pathmeasure_t *measure, float distance, sk_point_t *position, sk_vector_t *tangent)
{
  return reinterpret_cast<SkPathMeasure *>(measure)->getPosTan(distance, reinterpret_cast<SkPoint *>(position), reinterpret_cast<SkVector *>(tangent));
};

bool sk_pathmeasure_get_matrix(sk_pathmeasure_t *measure, float distance, sk_matrix_t *matrix, sk_pathmeasure_matrixflags_t flags)
{
  return reinterpret_cast<SkPathMeasure *>(measure)->getMatrix(distance, reinterpret_cast<SkMatrix *>(matrix), (SkPathMeasure::MatrixFlags)flags);
};

bool sk_pathmeasure_get_segment(sk_pathmeasure_t *measure, float start, float stop, sk_path_t *dst, bool startWithMoveTo)
{
  return reinterpret_cast<SkPathMeasure *>(measure)->getSegment(start, stop, reinterpret_cast<SkPath *>(dst), startWithMoveTo);
};

bool sk_pathmeasure_is_closed(sk_pathmeasure_t *measure)
{
  return reinterpret_cast<SkPathMeasure *>(measure)->isClosed();
};

bool sk_pathmeasure_next_contour(sk_pathmeasure_t *measure)
{
  return reinterpret_cast<SkPathMeasure *>(measure)->nextContour();
};
