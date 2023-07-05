#ifndef sk_data_DEFINED
#define sk_data_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_data_t *sk_data_make_empty(void);
SK_C_API sk_data_t *sk_data_make_with_copy(const void *data, size_t size);
SK_C_API void sk_data_ref(const sk_data_t *self);
SK_C_API void sk_data_unref(const sk_data_t *self);

SK_C_PLUS_PLUS_END_GUARD
#endif
