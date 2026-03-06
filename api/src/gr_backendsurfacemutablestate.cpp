#include "include/gr_backendsurfacemutablestate.h"

#include "sk_mapping.h"

gr_backendsurfacemutablestate_t* gr_backendsurfacemutablestate_create(gr_vk_imagelayout_t image_layout, uint32_t queue_family_index) {
  return SK_ONLY_VULKAN(ToGrBackendSurfaceMutableState(new GrBackendSurfaceMutableState(AsVkImageLayout(image_layout), queue_family_index)), nullptr);
}

void gr_backendsurfacemutablestate_destroy(gr_backendsurfacemutablestate_t* self) {
  SK_ONLY_VULKAN(delete AsGrBackendSurfaceMutableState(self);)
}
