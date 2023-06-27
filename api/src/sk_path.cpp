#include "sk_mapping.h"
#include "include/sk_path.h"
#include "include/core/SkPath.h"
#include "include/core/SkString.h"
#include "include/core/SkPathMeasure.h"
#include "include/utils/SkParsePath.h"
#include "include/pathops/SkPathOps.h"

sk_path_t *sk_path_new(void)
{
  return ToPath(new SkPath());
};

void sk_path_delete(sk_path_t *path)
{
  delete AsPath(path);
};

void sk_path_move_to(sk_path_t *path, float x, float y)
{
  AsPath(path)->moveTo(x, y);
};

void sk_path_line_to(sk_path_t *path, float x, float y)
{
  AsPath(path)->lineTo(x, y);
};

void sk_path_quad_to(sk_path_t *path, float x0, float y0, float x1, float y1)
{
  AsPath(path)->quadTo(x0, y0, x1, y1);
};

void sk_path_conic_to(sk_path_t *path, float x0, float y0, float x1, float y1, float w)
{
  AsPath(path)->conicTo(x0, y0, x1, y1, w);
};

void sk_path_cubic_to(sk_path_t *path, float x0, float y0, float x1, float y1, float x2, float y2)
{
  AsPath(path)->cubicTo(x0, y0, x1, y1, x2, y2);
};

void sk_path_arc_to(sk_path_t *path, float rx, float ry, float xAxisRotate, sk_path_arc_size_t largeArc, sk_path_direction_t sweep, float x, float y)
{
  AsPath(path)->arcTo(rx, ry, xAxisRotate, (SkPath::ArcSize)largeArc, (SkPathDirection)sweep, x, y);
};

void sk_path_rarc_to(sk_path_t *path, float rx, float ry, float xAxisRotate, sk_path_arc_size_t largeArc, sk_path_direction_t sweep, float x, float y)
{
  AsPath(path)->rArcTo(rx, ry, xAxisRotate, (SkPath::ArcSize)largeArc, (SkPathDirection)sweep, x, y);
};

void sk_path_arc_to_with_oval(sk_path_t *path, const sk_rect_t *oval, float startAngle, float sweepAngle, bool forceMoveTo)
{
  AsPath(path)->arcTo(*AsRect(oval), startAngle, sweepAngle, forceMoveTo);
};

void sk_path_arc_to_with_points(sk_path_t *path, float x1, float y1, float x2, float y2, float radius)
{
  AsPath(path)->arcTo(x1, y1, x2, y2, radius);
};

void sk_path_close(sk_path_t *path)
{
  AsPath(path)->close();
};

void sk_path_add_rect(sk_path_t *path, const sk_rect_t *rect, sk_path_direction_t dir)
{
  AsPath(path)->addRect(*AsRect(rect), (SkPathDirection)dir);
};

void sk_path_add_rrect(sk_path_t *path, const sk_rrect_t *rrect, sk_path_direction_t dir)
{
  AsPath(path)->addRRect(*reinterpret_cast<const SkRRect *>(rrect), (SkPathDirection)dir);
};

void sk_path_add_rrect_start(sk_path_t *path, const sk_rrect_t *rrect, sk_path_direction_t dir, uint32_t start)
{
  AsPath(path)->addRRect(*reinterpret_cast<const SkRRect *>(rrect), (SkPathDirection)dir, start);
};

void sk_path_add_rounded_rect(sk_path_t *path, const sk_rect_t *rect, float rx, float ry, sk_path_direction_t dir)
{
  AsPath(path)->addRoundRect(*AsRect(rect), rx, ry, (SkPathDirection)dir);
};

void sk_path_add_oval(sk_path_t *path, const sk_rect_t *rect, sk_path_direction_t dir)
{
  AsPath(path)->addOval(*AsRect(rect), (SkPathDirection)dir);
};

void sk_path_add_circle(sk_path_t *path, float x, float y, float radius, sk_path_direction_t dir)
{
  AsPath(path)->addCircle(x, y, radius, (SkPathDirection)dir);
};

void sk_path_get_bounds(const sk_path_t *path, sk_rect_t *rect)
{
  SkRect r = AsPath(path)->getBounds();
  *rect = reinterpret_cast<sk_rect_t &>(r);
};

void sk_path_compute_tight_bounds(const sk_path_t *path, sk_rect_t *rect)
{
  SkRect r = AsPath(path)->computeTightBounds();
  *rect = reinterpret_cast<sk_rect_t &>(r);
};

void sk_path_rmove_to(sk_path_t *path, float dx, float dy)
{
  AsPath(path)->rMoveTo(dx, dy);
};

void sk_path_rline_to(sk_path_t *path, float dx, float yd)
{
  AsPath(path)->rLineTo(dx, yd);
};

void sk_path_rquad_to(sk_path_t *path, float dx0, float dy0, float dx1, float dy1)
{
  AsPath(path)->rQuadTo(dx0, dy0, dx1, dy1);
};

void sk_path_rconic_to(sk_path_t *path, float dx0, float dy0, float dx1, float dy1, float w)
{
  AsPath(path)->rConicTo(dx0, dy0, dx1, dy1, w);
};

void sk_path_rcubic_to(sk_path_t *path, float dx0, float dy0, float dx1, float dy1, float dx2, float dy2)
{
  AsPath(path)->rCubicTo(dx0, dy0, dx1, dy1, dx2, dy2);
};

void sk_path_add_rect_start(sk_path_t *path, const sk_rect_t *crect, sk_path_direction_t cdir, uint32_t startIndex)
{
  AsPath(path)->addRect(*AsRect(crect), (SkPathDirection)cdir, startIndex);
};

void sk_path_add_arc(sk_path_t *path, const sk_rect_t *crect, float startAngle, float sweepAngle)
{
  AsPath(path)->addArc(*AsRect(crect), startAngle, sweepAngle);
};

sk_path_filltype_t sk_path_get_filltype(sk_path_t *path)
{
  return (sk_path_filltype_t)AsPath(path)->getFillType();
};

void sk_path_set_filltype(sk_path_t *path, sk_path_filltype_t filltype)
{
  AsPath(path)->setFillType((SkPathFillType)filltype);
};

void sk_path_transform(sk_path_t *path, const sk_matrix_t *matrix)
{
  AsPath(path)->transform(AsMatrix(matrix));
};

void sk_path_transform_to_dest(const sk_path_t *path, const sk_matrix_t *matrix, sk_path_t *destination)
{
  AsPath(path)->transform(AsMatrix(matrix), AsPath(destination));
};

sk_path_t *sk_path_clone(const sk_path_t *path)
{
  return ToPath(new SkPath(*AsPath(path)));
};

void sk_path_add_path_offset(sk_path_t *path, sk_path_t *other, float dx, float dy, sk_path_add_mode_t add_mode)
{
  AsPath(path)->addPath(*AsPath(other), dx, dy, (SkPath::AddPathMode)add_mode);
};

void sk_path_add_path_matrix(sk_path_t *path, sk_path_t *other, const sk_matrix_t *matrix, sk_path_add_mode_t add_mode)
{
  AsPath(path)->addPath(*AsPath(other), AsMatrix(matrix), (SkPath::AddPathMode)add_mode);
};

void sk_path_add_path(sk_path_t *path, sk_path_t *other, sk_path_add_mode_t add_mode)
{
  AsPath(path)->addPath(*AsPath(other), (SkPath::AddPathMode)add_mode);
};

void sk_path_add_path_reverse(sk_path_t *path, sk_path_t *other)
{
  AsPath(path)->reverseAddPath(*AsPath(other));
};

void sk_path_reset(sk_path_t *path)
{
  AsPath(path)->reset();
};

void sk_path_rewind(sk_path_t *path)
{
  AsPath(path)->rewind();
};

int sk_path_count_points(const sk_path_t *path)
{
  return AsPath(path)->countPoints();
};

int sk_path_count_verbs(const sk_path_t *path)
{
  return AsPath(path)->countVerbs();
};

void sk_path_get_point(const sk_path_t *path, int index, sk_point_t *point)
{
  SkPoint p = AsPath(path)->getPoint(index);
  *point = reinterpret_cast<sk_point_t &>(p);
};

int sk_path_get_points(const sk_path_t *path, sk_point_t *points, int max)
{
  return AsPath(path)->getPoints(AsPoint(points), max);
};

bool sk_path_contains(const sk_path_t *path, float x, float y)
{
  return AsPath(path)->contains(x, y);
};

bool sk_path_is_convex(const sk_path_t *path)
{
  return AsPath(path)->isConvex();
};

bool sk_path_parse_svg_string(sk_path_t *path, const char *str)
{
  return SkParsePath::FromSVGString(str, AsPath(path));
};

sk_string_t *sk_path_to_svg_string(const sk_path_t *path)
{
  return reinterpret_cast<sk_string_t *>(new SkString(SkParsePath::ToSVGString(*AsPath(path), SkParsePath::PathEncoding::Relative)));
};

bool sk_path_get_last_point(const sk_path_t *path, sk_point_t *point)
{
  return AsPath(path)->getLastPt(AsPoint(point));
};

int sk_path_convert_conic_to_quads(const sk_point_t *p0, const sk_point_t *p1, const sk_point_t *p2, float w, sk_point_t *pts, int pow2)
{
  return SkPath::ConvertConicToQuads(*AsPoint(p0), *AsPoint(p1), *AsPoint(p2), w, AsPoint(pts), pow2);
};

void sk_path_add_poly(sk_path_t *path, const sk_point_t *points, int count, bool close)
{
  AsPath(path)->addPoly(AsPoint(points), count, close);
};

uint32_t sk_path_get_segment_masks(sk_path_t *path)
{
  return AsPath(path)->getSegmentMasks();
};

bool sk_path_is_oval(sk_path_t *path, sk_rect_t *bounds)
{
  return AsPath(path)->isOval(AsRect(bounds));
};

bool sk_path_is_rrect(sk_path_t *path, sk_rrect_t *bounds)
{
  return AsPath(path)->isRRect(AsRRect(bounds));
};

bool sk_path_is_line(sk_path_t *path, sk_point_t line[2])
{
  return AsPath(path)->isLine(AsPoint(line));
};

bool sk_path_is_rect(sk_path_t *path, sk_rect_t *rect, bool *isClosed, sk_path_direction_t *direction)
{
  return AsPath(path)->isRect(AsRect(rect), isClosed, (SkPathDirection *)direction);
};

/* Path Ops */
bool sk_pathop_op(const sk_path_t *one, const sk_path_t *two, sk_pathop_t op, sk_path_t *result)
{
  return (*AsPath(one), *AsPath(two), (SkPathOp)op, AsPath(result));
};

bool sk_pathop_simplify(const sk_path_t *path, sk_path_t *result)
{
  return Simplify(*AsPath(path), AsPath(result));
};

bool sk_pathop_tight_bounds(const sk_path_t *path, sk_rect_t *result)
{
  return TightBounds(*AsPath(path), AsRect(result));
};

bool sk_pathop_as_winding(const sk_path_t *path, sk_path_t *result)
{
  return AsWinding(*AsPath(path), AsPath(result));
};

/* Path Op Builder */
sk_opbuilder_t *sk_opbuilder_new(void)
{
  return ToOpBuilder(new SkOpBuilder());
};

void sk_opbuilder_destroy(sk_opbuilder_t *builder)
{
  delete AsOpBuilder(builder);
};

void sk_opbuilder_add(sk_opbuilder_t *builder, const sk_path_t *path, sk_pathop_t op)
{
  AsOpBuilder(builder)->add(*AsPath(path), (SkPathOp)op);
};

bool sk_opbuilder_resolve(sk_opbuilder_t *builder, sk_path_t *result)
{
  return AsOpBuilder(builder)->resolve(AsPath(result));
};

/* Path Measure */
sk_pathmeasure_t *sk_pathmeasure_new(void)
{
  return ToPathMeasure(new SkPathMeasure());
};

sk_pathmeasure_t *sk_pathmeasure_new_with_path(const sk_path_t *path, bool forceClosed, float resScale)
{
  return ToPathMeasure(new SkPathMeasure(*AsPath(path), forceClosed, resScale));
};

void sk_pathmeasure_destroy(sk_pathmeasure_t *measure)
{
  delete AsPathMeasure(measure);
};

void sk_pathmeasure_set_path(sk_pathmeasure_t *measure, const sk_path_t *path, bool forceClosed)
{
  AsPathMeasure(measure)->setPath(AsPath(path), forceClosed);
};

float sk_pathmeasure_get_length(sk_pathmeasure_t *measure)
{
  return AsPathMeasure(measure)->getLength();
};

bool sk_pathmeasure_get_pos_tan(sk_pathmeasure_t *measure, float distance, sk_point_t *position, sk_vector_t *tangent)
{
  return AsPathMeasure(measure)->getPosTan(distance, AsPoint(position), AsVector(tangent));
};

bool sk_pathmeasure_get_matrix(sk_pathmeasure_t *measure, float distance, sk_matrix_t *matrix, sk_pathmeasure_matrixflags_t flags)
{
  return AsPathMeasure(measure)->getMatrix(distance, reinterpret_cast<SkMatrix *>(matrix), (SkPathMeasure::MatrixFlags)flags);
};

bool sk_pathmeasure_get_segment(sk_pathmeasure_t *measure, float start, float stop, sk_path_t *dst, bool startWithMoveTo)
{
  return AsPathMeasure(measure)->getSegment(start, stop, AsPath(dst), startWithMoveTo);
};

bool sk_pathmeasure_is_closed(sk_pathmeasure_t *measure)
{
  return AsPathMeasure(measure)->isClosed();
};

bool sk_pathmeasure_next_contour(sk_pathmeasure_t *measure)
{
  return AsPathMeasure(measure)->nextContour();
};
