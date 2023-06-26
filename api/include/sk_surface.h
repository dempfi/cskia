#ifndef sk_surface_DEFINED
#define sk_surface_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_surface_t *sk_surface_new_metal_layer(gr_direct_context_t *context, void *layer, gr_surfaceorigin_t origin, int samples, sk_colortype_t colorType, sk_colorspace_t *colorspace, const sk_surfaceprops_t *props, const void **drawable);
SK_C_API sk_surface_t *sk_surface_new_backend_render_target(gr_direct_context_t *context, const gr_backendrendertarget_t *target, gr_surfaceorigin_t origin, sk_colortype_t colorType, sk_colorspace_t *colorspace, const sk_surfaceprops_t *props);

SK_C_API sk_canvas_t *sk_surface_get_canvas(sk_surface_t *);
SK_C_API void sk_surface_unref(sk_surface_t *);

SK_C_PLUS_PLUS_END_GUARD
#endif
