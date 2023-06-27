#ifndef gr_direct_context_DEFINED
#define gr_direct_context_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API gr_direct_context_t *gr_direct_context_make_metal(const gr_mtl_backend_context_t *backendContext);

SK_C_API void gr_direct_context_flush(gr_direct_context_t *context);
SK_C_API void gr_direct_context_flush_and_submit(gr_direct_context_t *context, bool syncCpu);

SK_C_API void gr_direct_context_delete(gr_direct_context_t *context);
SK_C_API void gr_direct_context_abandon_context(gr_direct_context_t *context);
SK_C_API void gr_direct_context_release_resources_and_abandon_context(gr_direct_context_t *context);

SK_C_PLUS_PLUS_END_GUARD
#endif
