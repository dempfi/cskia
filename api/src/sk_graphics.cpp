#include "include/sk_graphics.h"
#include "sk_mapping.h"

void sk_graphics_dump_memory_statistics(sk_tracememorydump_t *trace_memory_dump)
{
  SkGraphics::DumpMemoryStatistics(AsTraceMemoryDump(trace_memory_dump));
}

int32_t sk_graphics_get_font_cache_count_limit(void)
{
  return SkGraphics::GetFontCacheCountLimit();
}

int32_t sk_graphics_get_font_cache_count_used(void)
{
  return SkGraphics::GetFontCacheCountUsed();
}

size_t sk_graphics_get_font_cache_limit(void)
{
  return SkGraphics::GetFontCacheLimit();
}

size_t sk_graphics_get_font_cache_used(void)
{
  return SkGraphics::GetFontCacheUsed();
}

size_t sk_graphics_get_resource_cache_single_allocation_byte_limit(void)
{
  return SkGraphics::GetResourceCacheSingleAllocationByteLimit();
}

size_t sk_graphics_get_resource_cache_total_byte_limit(void)
{
  return SkGraphics::GetResourceCacheTotalByteLimit();
}

size_t sk_graphics_get_resource_cache_total_bytes_used(void)
{
  return SkGraphics::GetResourceCacheTotalBytesUsed();
}

void sk_graphics_init(void)
{
  SkGraphics::Init();
}

void sk_graphics_purge_all_caches(void)
{
  SkGraphics::PurgeAllCaches();
}

void sk_graphics_purge_font_cache(void)
{
  SkGraphics::PurgeFontCache();
}

void sk_graphics_purge_resource_cache(void)
{
  SkGraphics::PurgeResourceCache();
}

int32_t sk_graphics_set_font_cache_count_limit(int32_t value)
{
  return SkGraphics::SetFontCacheCountLimit(value);
}

size_t sk_graphics_set_font_cache_limit(size_t value)
{
  return SkGraphics::SetFontCacheLimit(value);
}

size_t sk_graphics_set_resource_cache_single_allocation_byte_limit(size_t value)
{
  return SkGraphics::SetResourceCacheSingleAllocationByteLimit(value);
}

size_t sk_graphics_set_resource_cache_total_byte_limit(size_t value)
{
  return SkGraphics::SetResourceCacheTotalByteLimit(value);
}
