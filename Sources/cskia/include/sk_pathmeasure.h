#ifndef sk_pathmeasure_DEFINED
#define sk_pathmeasure_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_pathmeasure_t* sk_pathmeasure_create(const sk_path_t* path, bool force_closed, float res_scale);
SK_C_API void sk_pathmeasure_destroy(sk_pathmeasure_t* self);
SK_C_API float sk_pathmeasure_get_length(sk_pathmeasure_t* self);
SK_C_API bool sk_pathmeasure_get_matrix(sk_pathmeasure_t* self, float distance, /*out*/ sk_matrix_t* matrix, uint32_t matrix_flags);
SK_C_API bool sk_pathmeasure_get_position_and_tangent(sk_pathmeasure_t* self, float distance, /*out*/ sk_point_t* position, /*out*/ sk_vector_t* tangent);
SK_C_API sk_path_t* sk_pathmeasure_get_segment(sk_pathmeasure_t* self, float start, float stop, bool start_with_move_to);
SK_C_API bool sk_pathmeasure_is_closed(sk_pathmeasure_t* self);
SK_C_API bool sk_pathmeasure_next_contour(sk_pathmeasure_t* self);

SK_C_PLUS_PLUS_END_GUARD
#endif
