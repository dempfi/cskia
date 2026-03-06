#ifndef gr_vk_extensions_DEFINED
#define gr_vk_extensions_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API gr_vk_extensions_t* gr_vk_extensions_create(void);
SK_C_API void gr_vk_extensions_destroy(gr_vk_extensions_t* self);
SK_C_API bool gr_vk_extensions_has_extension(const gr_vk_extensions_t* self, const char name[], uint32_t min_api_version);
SK_C_API void gr_vk_extensions_init(gr_vk_extensions_t* self, void* context, gr_vk_get_proc proc, gr_vk_instance_t instance, gr_vk_physicaldevice_t physical_device, int32_t instance_extension_count, const char* instance_extensions[], int32_t device_extension_count, const char* device_extensions[]);

SK_C_PLUS_PLUS_END_GUARD
#endif
