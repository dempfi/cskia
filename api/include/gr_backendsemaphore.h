#ifndef gr_backendsemaphore_DEFINED
#define gr_backendsemaphore_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API gr_backendsemaphore_t* gr_backendsemaphore_create(void);
SK_C_API void gr_backendsemaphore_destroy(gr_backendsemaphore_t* self);
SK_C_API void gr_backendsemaphore_init_vulkan(gr_backendsemaphore_t* self, gr_vk_semaphore_t semaphore);

SK_C_PLUS_PLUS_END_GUARD
#endif
