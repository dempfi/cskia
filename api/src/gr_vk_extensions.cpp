#include "include/gr_vk_extensions.h"

#include "sk_mapping.h"

gr_vk_extensions_t* gr_vk_extensions_create(void) {
  return SK_ONLY_VULKAN(ToGrVkExtensions(new GrVkExtensions()), nullptr);
}

void gr_vk_extensions_destroy(gr_vk_extensions_t* self) {
  SK_ONLY_VULKAN(delete AsGrVkExtensions(self);)
}

bool gr_vk_extensions_has_extension(const gr_vk_extensions_t* self, const char name[], uint32_t min_api_version) {
  return SK_ONLY_VULKAN(AsGrVkExtensions(self)->hasExtension(name, min_api_version), false);
}

void gr_vk_extensions_init(gr_vk_extensions_t* self, void* context, gr_vk_get_proc proc, gr_vk_instance_t instance, gr_vk_physicaldevice_t physical_device, int32_t instance_extension_count, const char* instance_extensions[], int32_t device_extension_count, const char* device_extensions[]) {
  SK_ONLY_VULKAN(
      AsGrVkExtensions(self)->init(
          [context, proc](const char name[], VkInstance instance, VkDevice device) {
            return AsPFN_vkVoidFunction(proc(context, name, ToVkInstance(instance), ToVkDevice(device)));
          },
          AsVkInstance(instance), AsVkPhysicalDevice(physical_device), instance_extension_count, instance_extensions, device_extension_count, device_extensions);)
}
