#ifndef sk_rrect_DEFINED
#define sk_rrect_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API bool sk_rrect_contains(const sk_rrect_t *self, const sk_rect_t *rect);
SK_C_API sk_rrect_t *sk_rrect_create(void);
SK_C_API sk_rrect_t *sk_rrect_create2(const sk_rrect_t *rrect);
SK_C_API void sk_rrect_deflate(sk_rrect_t *self, float dx, float dy);
SK_C_API void sk_rrect_destroy(sk_rrect_t *self);
SK_C_API float sk_rrect_get_height(const sk_rrect_t *self);
SK_C_API void sk_rrect_get_radii(const sk_rrect_t *self, sk_rrectcorner_t corner, /*out*/ sk_vector_t *result);
SK_C_API void sk_rrect_get_rect(const sk_rrect_t *self, /*out*/ sk_rect_t *result);
SK_C_API void sk_rrect_get_simple_radii(const sk_rrect_t *self, /*out*/ sk_vector_t *result);
SK_C_API float sk_rrect_get_width(const sk_rrect_t *self);
SK_C_API void sk_rrect_inflate(sk_rrect_t *self, float dx, float dy);
SK_C_API bool sk_rrect_is_complex(const sk_rrect_t *self);
SK_C_API bool sk_rrect_is_empty(const sk_rrect_t *self);
SK_C_API bool sk_rrect_is_equal(const sk_rrect_t *self, const sk_rrect_t *rrect);
SK_C_API bool sk_rrect_is_nine_patch(const sk_rrect_t *self);
SK_C_API bool sk_rrect_is_oval(const sk_rrect_t *self);
SK_C_API bool sk_rrect_is_rect(const sk_rrect_t *self);
SK_C_API bool sk_rrect_is_simple(const sk_rrect_t *self);
SK_C_API bool sk_rrect_is_valid(const sk_rrect_t *self);
SK_C_API void sk_rrect_offset(sk_rrect_t *self, float dx, float dy);
SK_C_API void sk_rrect_set_empty(sk_rrect_t *self);
SK_C_API void sk_rrect_set_nine_patch(sk_rrect_t *self, const sk_rect_t *rect, float radius_left, float radius_top, float radius_right, float radius_bottom);
SK_C_API void sk_rrect_set_oval(sk_rrect_t *self, const sk_rect_t *rect);
SK_C_API void sk_rrect_set_rect(sk_rrect_t *self, const sk_rect_t *rect);
SK_C_API void sk_rrect_set_rect2(sk_rrect_t *self, const sk_rect_t *rect, const sk_vector_t *radii);
SK_C_API void sk_rrect_set_rect3(sk_rrect_t *self, const sk_rect_t *rect, float radius_x, float radius_y);
SK_C_API sk_rrect_t *sk_rrect_transform(const sk_rrect_t *self, const sk_matrix_t *matrix);

SK_C_PLUS_PLUS_END_GUARD
#endif
