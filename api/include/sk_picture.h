#ifndef sk_picture_DEFINED
#define sk_picture_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API size_t sk_picture_approximate_bytes_used(const sk_picture_t *self);
SK_C_API int32_t sk_picture_approximate_op_count(const sk_picture_t *self, bool nested);
SK_C_API void sk_picture_get_cull_rect(const sk_picture_t *self, /*out*/ sk_rect_t *result);
SK_C_API sk_picture_t *sk_picture_make_from_stream(sk_stream_t *stream);
SK_C_API sk_shader_t *sk_picture_make_shader(const sk_picture_t *self, sk_tilemode_t tile_mode_x, sk_tilemode_t tile_mode_y, sk_filtermode_t filter_mode, const sk_matrix_t *local_matrix, const sk_rect_t *tile_rect);
SK_C_API void sk_picture_playback(const sk_picture_t *self, sk_canvas_t *canvas);
SK_C_API void sk_picture_serialize_to_stream(const sk_picture_t *self, sk_wstream_t *w_stream);

SK_C_PLUS_PLUS_END_GUARD
#endif
