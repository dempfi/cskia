#include "include/sk_region.h"

#include <memory>

#include "sk_mapping.h"

bool sk_region_contains(const sk_region_t* self, const sk_region_t* region) {
  return AsRegion(self)->contains(AsRegion(*region));
}

bool sk_region_contains2(const sk_region_t* self, const sk_irect_t* rect) {
  return AsRegion(self)->contains(AsIRect(*rect));
}

bool sk_region_contains3(const sk_region_t* self, int32_t x, int32_t y) {
  return AsRegion(self)->contains(x, y);
}

sk_region_t* sk_region_create(void) {
  return ToRegion(new SkRegion());
}

sk_region_t* sk_region_create2(const sk_region_t* region) {
  return ToRegion(new SkRegion(AsRegion(*region)));
}

void sk_region_destroy(sk_region_t* self) {
  delete AsRegion(self);
}

sk_path_t* sk_region_get_boundary_path(const sk_region_t* self) {
  auto r = std::make_unique<SkPath>();
  return AsRegion(self)->getBoundaryPath(r.get()) ? ToPath(r.release()) : nullptr;
}

void sk_region_get_bounds(const sk_region_t* self, sk_irect_t* result) {
  *result = ToIRect(AsRegion(self)->getBounds());
}

bool sk_region_intersects(const sk_region_t* self, const sk_region_t* region) {
  return AsRegion(self)->intersects(AsRegion(*region));
}

bool sk_region_intersects2(const sk_region_t* self, const sk_irect_t* rect) {
  return AsRegion(self)->intersects(AsIRect(*rect));
}

bool sk_region_is_complex(const sk_region_t* self) {
  return AsRegion(self)->isComplex();
}

bool sk_region_is_empty(const sk_region_t* self) {
  return AsRegion(self)->isEmpty();
}

bool sk_region_is_equal(const sk_region_t* self, const sk_region_t* region) {
  return AsRegion(*self) == AsRegion(*region);
}

bool sk_region_is_rect(const sk_region_t* self) {
  return AsRegion(self)->isRect();
}

bool sk_region_op(sk_region_t* self, const sk_region_t* region, sk_regionop_t op) {
  return AsRegion(self)->op(AsRegion(*region), AsRegionOp(op));
}

bool sk_region_op2(sk_region_t* self, const sk_irect_t* rect, sk_regionop_t op) {
  return AsRegion(self)->op(AsIRect(*rect), AsRegionOp(op));
}

bool sk_region_quick_contains(const sk_region_t* self, const sk_irect_t* rect) {
  return AsRegion(self)->quickContains(AsIRect(*rect));
}

bool sk_region_quick_reject(const sk_region_t* self, const sk_region_t* region) {
  return AsRegion(self)->quickReject(AsRegion(*region));
}

bool sk_region_quick_reject2(const sk_region_t* self, const sk_irect_t* rect) {
  return AsRegion(self)->quickReject(AsIRect(*rect));
}

void sk_region_set_empty(sk_region_t* self) {
  AsRegion(self)->setEmpty();
}

bool sk_region_set_path(sk_region_t* self, const sk_path_t* path, const sk_region_t* clip) {
  return AsRegion(self)->setPath(AsPath(*path), AsRegion(*clip));
}

bool sk_region_set_rect(sk_region_t* self, const sk_irect_t* rect) {
  return AsRegion(self)->setRect(AsIRect(*rect));
}

bool sk_region_set_rects(sk_region_t* self, const sk_irect_t rects[], int32_t count) {
  return AsRegion(self)->setRects(AsIRect(rects), count);
}

void sk_region_translate(sk_region_t* self, int32_t x, int32_t y) {
  AsRegion(self)->translate(x, y);
}

sk_regioncliperator_t* sk_regioncliperator_create(const sk_region_t* region, const sk_irect_t* clip) {
  return ToRegionCliperator(new SkRegion::Cliperator(AsRegion(*region), AsIRect(*clip)));
}

void sk_regioncliperator_destroy(sk_regioncliperator_t* self) {
  delete AsRegionCliperator(self);
}

void sk_regioncliperator_get_current(const sk_regioncliperator_t* self, sk_irect_t* result) {
  *result = ToIRect(AsRegionCliperator(self)->rect());
}

bool sk_regioncliperator_move_next(sk_regioncliperator_t* self) {
  if (AsRegionCliperator(self)->done())
    return false;
  AsRegionCliperator(self)->next();
  return true;
}

sk_regioniterator_t* sk_regioniterator_create(const sk_region_t* region) {
  return ToRegionIterator(new SkRegion::Iterator(AsRegion(*region)));
}

void sk_regioniterator_destroy(sk_regioniterator_t* self) {
  delete AsRegionIterator(self);
}

void sk_regioniterator_get_current(const sk_regioniterator_t* self, sk_irect_t* result) {
  *result = ToIRect(AsRegionIterator(self)->rect());
}

bool sk_regioniterator_move_next(sk_regioniterator_t* self) {
  if (AsRegionIterator(self)->done())
    return false;
  AsRegionIterator(self)->next();
  return true;
}

sk_regionspanerator_t* sk_regionspanerator_create(const sk_region_t* region, int32_t y, int32_t left, int32_t right) {
  return ToRegionSpanerator(new SkRegion::Spanerator(AsRegion(*region), y, left, right));
}

void sk_regionspanerator_destroy(sk_regionspanerator_t* self) {
  delete AsRegionSpanerator(self);
}

bool sk_regionspanerator_next(sk_regionspanerator_t* self, sk_ipoint_t* elem) {
  return AsRegionSpanerator(self)->next(&AsIPoint(elem)->fX, &AsIPoint(elem)->fY);
}
