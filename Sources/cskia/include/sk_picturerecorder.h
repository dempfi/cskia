#ifndef sk_picturerecorder_DEFINED
#define sk_picturerecorder_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_canvas_t* sk_picturerecorder_begin_recording(sk_picturerecorder_t* self, const sk_rect_t* bounds);
SK_C_API sk_picturerecorder_t* sk_picturerecorder_create(void);
SK_C_API void sk_picturerecorder_destroy(sk_picturerecorder_t* self);
SK_C_API sk_picture_t* sk_picturerecorder_finish_recording(sk_picturerecorder_t* self);
SK_C_API sk_picture_t* sk_picturerecorder_finish_recording2(sk_picturerecorder_t* self, const sk_rect_t* cull_rect);

SK_C_PLUS_PLUS_END_GUARD
#endif
