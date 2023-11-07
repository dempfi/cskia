#ifndef sk_pathbuilder_DEFINED
#define sk_pathbuilder_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API void sk_pathbuilder_add_arc(sk_pathbuilder_t* self, const sk_rect_t* oval, float start_angle, float sweep_angle);
SK_C_API void sk_pathbuilder_add_circle(sk_pathbuilder_t* self, float center_x, float center_y, float radius, sk_pathdirection_t direction);
SK_C_API void sk_pathbuilder_add_oval(sk_pathbuilder_t* self, const sk_rect_t* oval, sk_pathdirection_t direction, uint32_t start_index);
SK_C_API void sk_pathbuilder_add_path(sk_pathbuilder_t* self, const sk_path_t* path);
SK_C_API void sk_pathbuilder_add_polygon(sk_pathbuilder_t* self, sk_point_t polygon[], int32_t count, bool is_closed);
SK_C_API void sk_pathbuilder_add_rect(sk_pathbuilder_t* self, const sk_rect_t* rect, sk_pathdirection_t direction, uint32_t start_index);
SK_C_API void sk_pathbuilder_add_rrect(sk_pathbuilder_t* self, const sk_rrect_t* rrect, sk_pathdirection_t direction, uint32_t start_index);
SK_C_API void sk_pathbuilder_arc_to(sk_pathbuilder_t* self, float rx, float ry, float x_axis_rotate, sk_patharcsize_t large_arc, sk_pathdirection_t sweep, float x, float y);
SK_C_API void sk_pathbuilder_arc_to2(sk_pathbuilder_t* self, const sk_rect_t* oval, float start_angle, float sweep_angle, bool force_move_to);
SK_C_API void sk_pathbuilder_arc_to3(sk_pathbuilder_t* self, float x0, float y0, float x1, float y1, float radius);
SK_C_API void sk_pathbuilder_close(sk_pathbuilder_t* self);
SK_C_API void sk_pathbuilder_conic_to(sk_pathbuilder_t* self, float x0, float y0, float x1, float y1, float weight);
SK_C_API sk_pathbuilder_t* sk_pathbuilder_create(void);
SK_C_API sk_pathbuilder_t* sk_pathbuilder_create2(const sk_pathbuilder_t* path_builder);
SK_C_API void sk_pathbuilder_cubic_to(sk_pathbuilder_t* self, float x0, float y0, float x1, float y1, float x2, float y2);
SK_C_API void sk_pathbuilder_destroy(sk_pathbuilder_t* self);
SK_C_API sk_path_t* sk_pathbuilder_detach(sk_pathbuilder_t* self);
SK_C_API void sk_pathbuilder_get_bounds(const sk_pathbuilder_t* self, /*out*/ sk_rect_t* result);
SK_C_API sk_pathfilltype_t sk_pathbuilder_get_fill_type(const sk_pathbuilder_t* self);
SK_C_API void sk_pathbuilder_inc_reserve(sk_pathbuilder_t* self, int32_t extra_point_count, int32_t extra_verb_count);
SK_C_API void sk_pathbuilder_line_to(sk_pathbuilder_t* self, float x, float y);
SK_C_API void sk_pathbuilder_move_to(sk_pathbuilder_t* self, float x, float y);
SK_C_API void sk_pathbuilder_offset(sk_pathbuilder_t* self, float dx, float dy);
SK_C_API void sk_pathbuilder_polyline_to(sk_pathbuilder_t* self, const sk_point_t points[], int32_t count);
SK_C_API void sk_pathbuilder_quad_to(sk_pathbuilder_t* self, float x0, float y0, float x1, float y1);
SK_C_API void sk_pathbuilder_r_conic_to(sk_pathbuilder_t* self, float x0, float y0, float x1, float y1, float weight);
SK_C_API void sk_pathbuilder_r_cubic_to(sk_pathbuilder_t* self, float x0, float y0, float x1, float y1, float x2, float y2);
SK_C_API void sk_pathbuilder_r_line_to(sk_pathbuilder_t* self, float x, float y);
SK_C_API void sk_pathbuilder_r_quad_to(sk_pathbuilder_t* self, float x0, float y0, float x1, float y1);
SK_C_API void sk_pathbuilder_reset(sk_pathbuilder_t* self);
SK_C_API void sk_pathbuilder_set_filltype(sk_pathbuilder_t* self, sk_pathfilltype_t value);
SK_C_API sk_path_t* sk_pathbuilder_snapshot(const sk_pathbuilder_t* self);
SK_C_API void sk_pathbuilder_toggle_inverse_filltype(sk_pathbuilder_t* self);

SK_C_PLUS_PLUS_END_GUARD
#endif
