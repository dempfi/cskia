#ifndef sk_vertices_DEFINED
#define sk_vertices_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_vertices_t *sk_vertices_make_copy(sk_vertexmode_t vertex_mode, int32_t vertex_count, const sk_point_t *positions, const sk_point_t *textures, const sk_color_t *colors, int32_t index_count, const uint16_t *indices);
SK_C_API void sk_vertices_ref(const sk_vertices_t *self);
SK_C_API void sk_vertices_unref(const sk_vertices_t *self);

SK_C_PLUS_PLUS_END_GUARD
#endif
