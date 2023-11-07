#include "include/sk_picturerecorder.h"

#include "sk_mapping.h"

sk_canvas_t* sk_picturerecorder_begin_recording(sk_picturerecorder_t* self, const sk_rect_t* bounds) {
  return ToCanvas(AsPictureRecorder(self)->beginRecording(AsRect(*bounds)));
}

sk_picturerecorder_t* sk_picturerecorder_create(void) {
  return ToPictureRecorder(new SkPictureRecorder);
}

void sk_picturerecorder_destroy(sk_picturerecorder_t* self) {
  delete AsPictureRecorder(self);
}

sk_picture_t* sk_picturerecorder_finish_recording(sk_picturerecorder_t* self) {
  return ToPicture(AsPictureRecorder(self)->finishRecordingAsPicture().release());
}

sk_picture_t* sk_picturerecorder_finish_recording2(sk_picturerecorder_t* self, const sk_rect_t* cull_rect) {
  return ToPicture(AsPictureRecorder(self)->finishRecordingAsPictureWithCull(AsRect(*cull_rect)).release());
}
