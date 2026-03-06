#ifndef sk_refcnt_h
#define sk_refcnt_h

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API void sk_refcnt_ref(const sk_refcnt_t* self);
SK_C_API void sk_refcnt_unref(const sk_refcnt_t* self);

#ifdef __cplusplus
}
#endif

#endif
