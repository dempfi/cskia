#include "include/gr_backendrendertarget.h"
#include "include/gpu/GrBackendSurface.h"

#ifdef SK_METAL

gr_backendrendertarget_t *gr_backendrendertarget_new_metal(int width, int height, int samples, const gr_mtl_textureinfo_t *mtlInfo)
{
  return reinterpret_cast<gr_backendrendertarget_t *>(new GrBackendRenderTarget(width, height, samples, *reinterpret_cast<const GrMtlTextureInfo *>(mtlInfo)));
};

#endif

bool gr_backendrendertarget_is_valid(const gr_backendrendertarget_t *rendertarget)
{
  return reinterpret_cast<const GrBackendRenderTarget *>(rendertarget)->isValid();
};

int gr_backendrendertarget_get_width(const gr_backendrendertarget_t *rendertarget)
{
  return reinterpret_cast<const GrBackendRenderTarget *>(rendertarget)->width();
};

int gr_backendrendertarget_get_height(const gr_backendrendertarget_t *rendertarget)
{
  return reinterpret_cast<const GrBackendRenderTarget *>(rendertarget)->height();
};

int gr_backendrendertarget_get_samples(const gr_backendrendertarget_t *rendertarget)
{
  return reinterpret_cast<const GrBackendRenderTarget *>(rendertarget)->sampleCnt();
};

void gr_backendrendertarget_delete(const gr_backendrendertarget_t *rendertarget)
{
  delete reinterpret_cast<const GrBackendRenderTarget *>(rendertarget);
};
