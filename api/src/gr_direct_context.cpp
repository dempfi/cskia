#include "include/gr_direct_context.h"
#include "include/gpu/GrDirectContext.h"
#include "include/gpu/mtl/GrMtlBackendContext.h"

#ifdef SK_METAL
gr_direct_context_t *gr_direct_context_make_metal(const gr_mtl_backend_context_t *backendContext)
{
  return reinterpret_cast<gr_direct_context_t *>(GrDirectContext::MakeMetal(*reinterpret_cast<const GrMtlBackendContext *>(backendContext)).release());
};
#endif

void gr_direct_context_flush(gr_direct_context_t *context)
{
  reinterpret_cast<GrDirectContext *>(context)->flush();
};

void gr_direct_context_flush_and_submit(gr_direct_context_t *context, bool syncCpu)
{
  reinterpret_cast<GrDirectContext *>(context)->flushAndSubmit(syncCpu);
};

void gr_direct_context_delete(gr_direct_context_t *context)
{
  delete reinterpret_cast<GrDirectContext *>(context);
};

void gr_direct_context_abandon_context(gr_direct_context_t *context)
{
  reinterpret_cast<GrDirectContext *>(context)->abandonContext();
};

void gr_direct_context_release_resources_and_abandon_context(gr_direct_context_t *context)
{
  reinterpret_cast<GrDirectContext *>(context)->releaseResourcesAndAbandonContext();
};
