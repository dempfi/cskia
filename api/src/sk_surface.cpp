#include "include/sk_surface.h"
#include "include/core/SkSurface.h"
#include "include/gpu/GrDirectContext.h"
#include "include/core/SkColorSpace.h"

sk_surface_t *sk_surface_new_backend_render_target(gr_direct_context_t *context, const gr_backendrendertarget_t *target, gr_surfaceorigin_t origin, sk_colortype_t colorType, sk_colorspace_t *colorspace, const sk_surfaceprops_t *props)
{
  return reinterpret_cast<sk_surface_t *>(SkSurface::MakeFromBackendRenderTarget(reinterpret_cast<GrDirectContext *>(context), *reinterpret_cast<const GrBackendRenderTarget *>(target), (GrSurfaceOrigin)origin, (SkColorType)colorType, sk_ref_sp(reinterpret_cast<SkColorSpace *>(colorspace)), reinterpret_cast<const SkSurfaceProps *>(props)).release());
};

sk_canvas_t *sk_surface_get_canvas(sk_surface_t *surface)
{
  return reinterpret_cast<sk_canvas_t *>(reinterpret_cast<SkSurface *>(surface)->getCanvas());
};

void sk_surface_unref(sk_surface_t *surface)
{
  SkSafeUnref(reinterpret_cast<SkSurface *>(surface));
};
