#ifndef gr_backendrendertarget_DEFINED
#define gr_backendrendertarget_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API gr_backendrendertarget_t *gr_backendrendertarget_new_metal(int width, int height, int samples, const gr_mtl_textureinfo_t *mtlInfo);
SK_C_API bool gr_backendrendertarget_is_valid(const gr_backendrendertarget_t *rendertarget);
SK_C_API int gr_backendrendertarget_get_width(const gr_backendrendertarget_t *rendertarget);
SK_C_API int gr_backendrendertarget_get_height(const gr_backendrendertarget_t *rendertarget);
SK_C_API int gr_backendrendertarget_get_samples(const gr_backendrendertarget_t *rendertarget);
SK_C_API void gr_backendrendertarget_delete(const gr_backendrendertarget_t *rendertarget);

SK_C_PLUS_PLUS_END_GUARD
#endif
