#include "include/sk_rrect.h"
#include "include/core/SkRRect.h"

sk_rrect_t *sk_rrect_new(void)
{
  return reinterpret_cast<sk_rrect_t *>(new SkRRect());
};

sk_rrect_t *sk_rrect_new_copy(const sk_rrect_t *rrect)
{
  return reinterpret_cast<sk_rrect_t *>(new SkRRect(*reinterpret_cast<const SkRRect *>(rrect)));
};

void sk_rrect_delete(const sk_rrect_t *rrect)
{
  delete reinterpret_cast<const SkRRect *>(rrect);
};

sk_rrect_type_t sk_rrect_get_type(const sk_rrect_t *rrect)
{
  return static_cast<sk_rrect_type_t>(reinterpret_cast<const SkRRect *>(rrect)->type());
};

void sk_rrect_get_rect(const sk_rrect_t *rrect, sk_rect_t *rect)
{
  SkRect r = reinterpret_cast<const SkRRect *>(rrect)->rect();
  *rect = reinterpret_cast<const sk_rect_t &>(r);
};

void sk_rrect_get_radii(const sk_rrect_t *rrect, sk_rrect_corner_t corner, sk_vector_t *radii)
{
  SkVector r = reinterpret_cast<const SkRRect *>(rrect)->radii(static_cast<SkRRect::Corner>(corner));
  *radii = reinterpret_cast<const sk_vector_t &>(r);
};

float sk_rrect_get_width(const sk_rrect_t *rrect)
{
  return reinterpret_cast<const SkRRect *>(rrect)->width();
};

float sk_rrect_get_height(const sk_rrect_t *rrect)
{
  return reinterpret_cast<const SkRRect *>(rrect)->height();
};

void sk_rrect_set_empty(sk_rrect_t *rrect)
{
  reinterpret_cast<SkRRect *>(rrect)->setEmpty();
};

void sk_rrect_set_rect(sk_rrect_t *rrect, const sk_rect_t *rect)
{
  reinterpret_cast<SkRRect *>(rrect)->setRect(reinterpret_cast<const SkRect &>(*rect));
};

void sk_rrect_set_oval(sk_rrect_t *rrect, const sk_rect_t *rect)
{
  reinterpret_cast<SkRRect *>(rrect)->setOval(reinterpret_cast<const SkRect &>(*rect));
};

void sk_rrect_set_rect_xy(sk_rrect_t *rrect, const sk_rect_t *rect, float xRad, float yRad)
{
  reinterpret_cast<SkRRect *>(rrect)->setRectXY(reinterpret_cast<const SkRect &>(*rect), xRad, yRad);
};

void sk_rrect_set_nine_patch(sk_rrect_t *rrect, const sk_rect_t *rect, float leftRad, float topRad, float rightRad, float bottomRad)
{
  reinterpret_cast<SkRRect *>(rrect)->setNinePatch(reinterpret_cast<const SkRect &>(*rect), leftRad, topRad, rightRad, bottomRad);
};

void sk_rrect_inset(sk_rrect_t *rrect, float dx, float dy)
{
  reinterpret_cast<SkRRect *>(rrect)->inset(dx, dy);
};

void sk_rrect_outset(sk_rrect_t *rrect, float dx, float dy)
{
  reinterpret_cast<SkRRect *>(rrect)->outset(dx, dy);
};

void sk_rrect_offset(sk_rrect_t *rrect, float dx, float dy)
{
  reinterpret_cast<SkRRect *>(rrect)->offset(dx, dy);
};

bool sk_rrect_contains(const sk_rrect_t *rrect, const sk_rect_t *rect)
{
  return reinterpret_cast<const SkRRect *>(rrect)->contains(reinterpret_cast<const SkRect &>(*rect));
};

bool sk_rrect_is_valid(const sk_rrect_t *rrect)
{
  return reinterpret_cast<const SkRRect *>(rrect)->isValid();
};

bool sk_rrect_transform(sk_rrect_t *rrect, const sk_matrix_t *matrix, sk_rrect_t *dest)
{
  return reinterpret_cast<SkRRect *>(rrect)->transform(reinterpret_cast<const SkMatrix &>(*matrix), reinterpret_cast<SkRRect *>(dest));
};
