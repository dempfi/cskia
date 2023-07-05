#include "include/sk_refcnt.h"
#include "sk_mapping.h"

void sk_refcnt_ref(const sk_refcnt_t *self)
{
  AsRefCnt(self)->ref();
}

void sk_refcnt_unref(const sk_refcnt_t *self)
{
  AsRefCnt(self)->unref();
}
