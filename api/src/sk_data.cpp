#include "include/sk_data.h"

#include "sk_mapping.h"

sk_data_t* sk_data_make_empty(void) {
  return ToData(SkData::MakeEmpty().release());
}

sk_data_t* sk_data_make_with_copy(const void* data, size_t size) {
  return ToData(SkData::MakeWithCopy(data, size).release());
}

void sk_data_ref(const sk_data_t* self) {
  AsData(self)->ref();
}

void sk_data_unref(const sk_data_t* self) {
  AsData(self)->unref();
}
