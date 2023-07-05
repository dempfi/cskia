#ifndef sk_region_DEFINED
#define sk_region_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API bool sk_region_contains(const sk_region_t *self, const sk_region_t *region);
SK_C_API bool sk_region_contains2(const sk_region_t *self, const sk_irect_t *rect);
SK_C_API bool sk_region_contains3(const sk_region_t *self, int32_t x, int32_t y);
SK_C_API sk_region_t *sk_region_create(void);
SK_C_API sk_region_t *sk_region_create2(const sk_region_t *region);
SK_C_API void sk_region_destroy(sk_region_t *self);
SK_C_API sk_path_t *sk_region_get_boundary_path(const sk_region_t *self);
SK_C_API void sk_region_get_bounds(const sk_region_t *self, /*out*/ sk_irect_t *result);
SK_C_API bool sk_region_intersects(const sk_region_t *self, const sk_region_t *region);
SK_C_API bool sk_region_intersects2(const sk_region_t *self, const sk_irect_t *rect);
SK_C_API bool sk_region_is_complex(const sk_region_t *self);
SK_C_API bool sk_region_is_empty(const sk_region_t *self);
SK_C_API bool sk_region_is_equal(const sk_region_t *self, const sk_region_t *region);
SK_C_API bool sk_region_is_rect(const sk_region_t *self);
SK_C_API bool sk_region_op(sk_region_t *self, const sk_region_t *region, sk_regionop_t op);
SK_C_API bool sk_region_op2(sk_region_t *self, const sk_irect_t *rect, sk_regionop_t op);
SK_C_API bool sk_region_quick_contains(const sk_region_t *self, const sk_irect_t *rect);
SK_C_API bool sk_region_quick_reject(const sk_region_t *self, const sk_region_t *region);
SK_C_API bool sk_region_quick_reject2(const sk_region_t *self, const sk_irect_t *rect);
SK_C_API void sk_region_set_empty(sk_region_t *self);
SK_C_API bool sk_region_set_path(sk_region_t *self, const sk_path_t *path, const sk_region_t *clip);
SK_C_API bool sk_region_set_rect(sk_region_t *self, const sk_irect_t *rect);
SK_C_API bool sk_region_set_rects(sk_region_t *self, const sk_irect_t rects[], int32_t count);
SK_C_API void sk_region_translate(sk_region_t *self, int32_t x, int32_t y);
SK_C_API sk_regioncliperator_t *sk_regioncliperator_create(const sk_region_t *region, const sk_irect_t *clip);
SK_C_API void sk_regioncliperator_destroy(sk_regioncliperator_t *self);
SK_C_API void sk_regioncliperator_get_current(const sk_regioncliperator_t *self, /*out*/ sk_irect_t *result);
SK_C_API bool sk_regioncliperator_move_next(sk_regioncliperator_t *self);
SK_C_API sk_regioniterator_t *sk_regioniterator_create(const sk_region_t *region);
SK_C_API void sk_regioniterator_destroy(sk_regioniterator_t *self);
SK_C_API void sk_regioniterator_get_current(const sk_regioniterator_t *self, /*out*/ sk_irect_t *result);
SK_C_API bool sk_regioniterator_move_next(sk_regioniterator_t *self);
SK_C_API sk_regionspanerator_t *sk_regionspanerator_create(const sk_region_t *region, int32_t y, int32_t left, int32_t right);
SK_C_API void sk_regionspanerator_destroy(sk_regionspanerator_t *self);
SK_C_API bool sk_regionspanerator_next(sk_regionspanerator_t *self, /*out*/ sk_ipoint_t *elem);

SK_C_PLUS_PLUS_END_GUARD
#endif
