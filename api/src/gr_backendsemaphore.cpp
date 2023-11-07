#include "include/gr_backendsemaphore.h"

#include "sk_mapping.h"

gr_backendsemaphore_t* gr_backendsemaphore_create(void) {
  return SK_ONLY_GPU(ToGrBackendSemaphore(new GrBackendSemaphore()), nullptr);
}

void gr_backendsemaphore_destroy(gr_backendsemaphore_t* self) {
  SK_ONLY_GPU(delete AsGrBackendSemaphore(self);)
}

void gr_backendsemaphore_init_vulkan(gr_backendsemaphore_t* self, gr_vk_semaphore_t semaphore) {
  SK_ONLY_VULKAN(AsGrBackendSemaphore(self)->initVulkan(AsVkSemaphore(semaphore));)
}
