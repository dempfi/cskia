#ifndef sk_graphics_DEFINED
#define sk_graphics_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API void sk_graphics_dump_memory_statistics(sk_tracememorydump_t *trace_memory_dump);
SK_C_API int32_t sk_graphics_get_font_cache_count_limit(void);
SK_C_API int32_t sk_graphics_get_font_cache_count_used(void);
SK_C_API size_t sk_graphics_get_font_cache_limit(void);
SK_C_API size_t sk_graphics_get_font_cache_used(void);
SK_C_API size_t sk_graphics_get_resource_cache_single_allocation_byte_limit(void);
SK_C_API size_t sk_graphics_get_resource_cache_total_byte_limit(void);
SK_C_API size_t sk_graphics_get_resource_cache_total_bytes_used(void);
SK_C_API void sk_graphics_init(void);
SK_C_API void sk_graphics_purge_all_caches(void);
SK_C_API void sk_graphics_purge_font_cache(void);
SK_C_API void sk_graphics_purge_resource_cache(void);
SK_C_API int32_t sk_graphics_set_font_cache_count_limit(int32_t value);
SK_C_API size_t sk_graphics_set_font_cache_limit(size_t value);
SK_C_API size_t sk_graphics_set_resource_cache_single_allocation_byte_limit(size_t value);
SK_C_API size_t sk_graphics_set_resource_cache_total_byte_limit(size_t value);

SK_C_PLUS_PLUS_END_GUARD
#endif
