#ifndef sk_path_DEFINED
#define sk_path_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API void sk_opbuilder_add(sk_opbuilder_t *self, const sk_path_t *path, sk_pathop_t op);
SK_C_API sk_opbuilder_t *sk_opbuilder_create(void);
SK_C_API void sk_opbuilder_destroy(sk_opbuilder_t *self);
SK_C_API sk_path_t *sk_opbuilder_detach(sk_opbuilder_t *self);
SK_C_API bool sk_path_contains(const sk_path_t *self, float x, float y);
SK_C_API int32_t sk_path_convert_conic_to_quads(const sk_point_t *point1, const sk_point_t *point2, const sk_point_t *point3, float weight, sk_point_t points[], int32_t power2);
SK_C_API sk_path_t *sk_path_create(const char svg[]);
SK_C_API sk_path_t *sk_path_create2(sk_stream_t *stream);
SK_C_API void sk_path_destroy(sk_path_t *self);
SK_C_API void sk_path_get_bounds(const sk_path_t *self, /*out*/ sk_rect_t *result);
SK_C_API sk_pathfilltype_t sk_path_get_fill_type(const sk_path_t *self);
SK_C_API bool sk_path_get_last_point(const sk_path_t *self, /*out*/ sk_point_t *result);
SK_C_API uint32_t sk_path_get_segment_masks(const sk_path_t *self);
SK_C_API void sk_path_get_tight_bounds(const sk_path_t *self, /*out*/ sk_rect_t *result);
SK_C_API sk_path_t *sk_path_interpolate(const sk_path_t *self, const sk_path_t *ending, float weight);
SK_C_API bool sk_path_is_convex(const sk_path_t *self);
SK_C_API bool sk_path_is_empty(const sk_path_t *self);
SK_C_API bool sk_path_is_finite(const sk_path_t *self);
SK_C_API bool sk_path_is_interpolatable(const sk_path_t *self, const sk_path_t *path);
SK_C_API bool sk_path_is_last_contour_closed(const sk_path_t *self);
SK_C_API bool sk_path_is_line(const sk_path_t *self, sk_point_t lines[2]);
SK_C_API bool sk_path_is_oval(const sk_path_t *self, sk_rect_t *oval);
SK_C_API bool sk_path_is_rect(const sk_path_t *self, sk_rect_t *rect);
SK_C_API bool sk_path_is_rrect(const sk_path_t *self, sk_rrect_t *rrect);
SK_C_API sk_path_t *sk_path_op(const sk_path_t *self, const sk_path_t *path, sk_pathop_t op);
SK_C_API void sk_path_serialize_to_stream(const sk_path_t *self, sk_wstream_t *w_stream);
SK_C_API sk_string_t *sk_path_to_svg(const sk_path_t *self);
SK_C_API sk_path_t *sk_path_transform(const sk_path_t *self, const sk_matrix_t *matrix);
SK_C_API sk_pathiterator_t *sk_pathiterator_create(const sk_path_t *path, bool force_close);
SK_C_API void sk_pathiterator_destroy(sk_pathiterator_t *self);
SK_C_API bool sk_pathiterator_next(sk_pathiterator_t *self, /*out*/ sk_pathiteratorelem_t *elem);

SK_C_PLUS_PLUS_END_GUARD
#endif
