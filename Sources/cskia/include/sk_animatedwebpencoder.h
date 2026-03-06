#ifndef sk_animatedwebpencoder_DEFINED
#define sk_animatedwebpencoder_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API bool sk_animatedwebpencoder_encode_to_file(const char file_name[], const sk_frame_t src[], size_t count, int32_t quality);
SK_C_API bool sk_animatedwebpencoder_encode_to_stream(sk_wstream_t* w_stream, const sk_frame_t src[], size_t count, int32_t quality);

SK_C_PLUS_PLUS_END_GUARD
#endif
