#include "include/sk_picture.h"

#include "sk_mapping.h"

size_t sk_picture_approximate_bytes_used(const sk_picture_t* self) {
  return AsPicture(self)->approximateBytesUsed();
}

int32_t sk_picture_approximate_op_count(const sk_picture_t* self, bool nested) {
  return AsPicture(self)->approximateOpCount(nested);
}

void sk_picture_get_cull_rect(const sk_picture_t* self, sk_rect_t* result) {
  *result = ToRect(AsPicture(self)->cullRect());
}

sk_picture_t* sk_picture_make_from_stream(sk_stream_t* stream) {
  return ToPicture(SkPicture::MakeFromStream(AsStream(stream)).release());
}

sk_shader_t* sk_picture_make_shader(const sk_picture_t* self, sk_tilemode_t tile_mode_x, sk_tilemode_t tile_mode_y, sk_filtermode_t filter_mode, const sk_matrix_t* local_matrix, const sk_rect_t* tile_rect) {
  SkMatrix m;
  if (local_matrix)
    m = AsMatrix(local_matrix);
  return ToShader(AsPicture(self)->makeShader(AsTileMode(tile_mode_x), AsTileMode(tile_mode_y), AsFilterMode(filter_mode), (local_matrix) ? &m : nullptr, AsRect(tile_rect)).release());
}

void sk_picture_playback(const sk_picture_t* self, sk_canvas_t* canvas) {
  AsPicture(self)->playback(AsCanvas(canvas));
}

void sk_picture_serialize_to_stream(const sk_picture_t* self, sk_wstream_t* w_stream) {
  AsPicture(self)->serialize(AsWStream(w_stream));
}
