#include "sk_mapping.h"
#include "include/sk_data.h"
#include "include/core/SkData.h"

sk_data_t *sk_data_new_empty(void)
{
  return ToData(SkData::MakeEmpty().release());
};

sk_data_t *sk_data_new_with_copy(const void *src, size_t length)
{
  return ToData(SkData::MakeWithCopy(src, length).release());
};

sk_data_t *sk_data_new_subset(const sk_data_t *src, size_t offset, size_t length)
{
  return ToData(SkData::MakeSubset(reinterpret_cast<const SkData *>(src), offset, length).release());
};

void sk_data_ref(const sk_data_t *data)
{
  reinterpret_cast<const SkData *>(data)->ref();
};

void sk_data_unref(const sk_data_t *data)
{
  reinterpret_cast<const SkData *>(data)->unref();
};

size_t sk_data_get_size(const sk_data_t *data)
{
  return reinterpret_cast<const SkData *>(data)->size();
};

const void *sk_data_get_data(const sk_data_t *data)
{
  return reinterpret_cast<const SkData *>(data)->data();
};

sk_data_t *sk_data_new_from_file(const char *path)
{
  return ToData(SkData::MakeFromFileName(path).release());
};

const uint8_t *sk_data_get_bytes(const sk_data_t *data)
{
  return reinterpret_cast<const SkData *>(data)->bytes();
};

sk_data_t *sk_data_new_uninitialized(size_t size)
{
  return ToData(SkData::MakeUninitialized(size).release());
};
