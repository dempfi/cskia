#include "include/sk_surface.h"
#include "include/core/SkSurface.h"
#include "include/gpu/GrDirectContext.h"
#include "include/core/SkColorSpace.h"

#ifdef SK_METAL
sk_surface_t *sk_surface_new_metal_layer(gr_direct_context_t *context, const void *layer, gr_surfaceorigin_t origin, int samples, sk_colortype_t colorType, sk_colorspace_t *colorspace, const sk_surfaceprops_t *props, const void **drawable)
{
  return reinterpret_cast<sk_surface_t *>(SkSurface::MakeFromCAMetalLayer(reinterpret_cast<GrDirectContext *>(context), layer, (GrSurfaceOrigin)origin, samples, (SkColorType)colorType, sk_ref_sp(reinterpret_cast<SkColorSpace *>(colorspace)), reinterpret_cast<const SkSurfaceProps *>(props), drawable).release());
};
#endif
