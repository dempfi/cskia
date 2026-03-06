#ifndef gr_backendsurface_DEFINED
#define gr_backendsurface_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API gr_backendrendertarget_t* gr_backendrendertarget_create_gl(int32_t width, int32_t height, int32_t sample_count, int32_t stencil_bits, const gr_gl_framebufferinfo_t* framebuffer_info);
SK_C_API gr_backendrendertarget_t* gr_backendrendertarget_create_mtl(int32_t width, int32_t height, const gr_mtl_textureinfo_t* texture_info);
SK_C_API gr_backendrendertarget_t* gr_backendrendertarget_create_vk(int32_t width, int32_t height, const gr_vk_imageinfo_t* image_info);
SK_C_API void gr_backendrendertarget_destroy(gr_backendrendertarget_t* self);
SK_C_API gr_backendapi_t gr_backendrendertarget_get_backend_api(const gr_backendrendertarget_t* self);
SK_C_API int32_t gr_backendrendertarget_get_height(const gr_backendrendertarget_t* self);
SK_C_API int32_t gr_backendrendertarget_get_sample_count(const gr_backendrendertarget_t* self);
SK_C_API int32_t gr_backendrendertarget_get_stencil_bits(const gr_backendrendertarget_t* self);
SK_C_API int32_t gr_backendrendertarget_get_width(const gr_backendrendertarget_t* self);
SK_C_API bool gr_backendrendertarget_is_valid(const gr_backendrendertarget_t* self);
SK_C_API gr_backendtexture_t* gr_backendtexture_create_gl(int32_t width, int32_t height, bool is_mipmapped, const gr_gl_textureinfo_t* texture_info);
SK_C_API gr_backendtexture_t* gr_backendtexture_create_mtl(int32_t width, int32_t height, bool is_mipmapped, const gr_mtl_textureinfo_t* texture_info);
SK_C_API gr_backendtexture_t* gr_backendtexture_create_vk(int32_t width, int32_t height, const gr_vk_imageinfo_t* image_info);
SK_C_API void gr_backendtexture_destroy(gr_backendtexture_t* self);
SK_C_API gr_backendapi_t gr_backendtexture_get_backend_api(const gr_backendtexture_t* self);
SK_C_API bool gr_backendtexture_get_gl_framebuffer_info(const gr_backendtexture_t* self, /*out*/ gr_gl_textureinfo_t* texture_info);
SK_C_API int32_t gr_backendtexture_get_height(const gr_backendtexture_t* self);
SK_C_API int32_t gr_backendtexture_get_width(const gr_backendtexture_t* self);
SK_C_API bool gr_backendtexture_has_mipmaps(const gr_backendtexture_t* self);
SK_C_API bool gr_backendtexture_is_valid(const gr_backendtexture_t* self);

SK_C_PLUS_PLUS_END_GUARD
#endif
