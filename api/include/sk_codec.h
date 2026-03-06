#ifndef sk_codec_DEFINED
#define sk_codec_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API void sk_codec_destroy(sk_codec_t* codec);
SK_C_API void sk_codec_get_dimensions(const sk_codec_t* self, /*out*/ sk_isize_t* result);
SK_C_API sk_encodedimageformat_t sk_codec_get_encoded_image_format(const sk_codec_t* self);
SK_C_API sk_image_t* sk_codec_get_image(sk_codec_t* self, sk_colortype_t color_type, sk_alphatype_t alpha_type, sk_colorspace_t* color_space);
SK_C_API bool sk_codec_get_pixels(sk_codec_t* self, void* pixels, size_t row_bytes, sk_colortype_t color_type, sk_alphatype_t alpha_type, sk_colorspace_t* color_space);
SK_C_API sk_codec_t* sk_codec_make_from_file(const char file_name[]);
SK_C_API sk_codec_t* sk_codec_make_from_stream(sk_stream_t* stream);
SK_C_API sk_codec_t* sk_codec_make_with_copy(const void* data, size_t size);
SK_C_API sk_codec_t* sk_codec_make_without_copy(const void* data, size_t size);
SK_C_API void sk_animcodecplayer_destroy(sk_animcodecplayer_t* self);
SK_C_API void sk_animcodecplayer_get_dimensions(const sk_animcodecplayer_t* self, /*out*/ sk_isize_t* result);
SK_C_API uint32_t sk_animcodecplayer_get_duration(const sk_animcodecplayer_t* self);
SK_C_API sk_image_t* sk_animcodecplayer_get_frame(sk_animcodecplayer_t* self);
SK_C_API sk_animcodecplayer_t* sk_animcodecplayer_make_from_file(const char file_name[]);
SK_C_API sk_animcodecplayer_t* sk_animcodecplayer_make_from_stream(sk_stream_t* stream);
SK_C_API bool sk_animcodecplayer_seek(sk_animcodecplayer_t* self, uint32_t milliseconds);

SK_C_PLUS_PLUS_END_GUARD
#endif
