#ifndef sk_typefacefontprovider_DEFINED
#define sk_typefacefontprovider_DEFINED

#include "sk_paragraph_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_typefacefontprovider_t* sk_typefacefontprovider_create(void);
SK_C_API void sk_typefacefontprovider_register_typeface(sk_typefacefontprovider_t* self, sk_typeface_t* typeface);
SK_C_API void sk_typefacefontprovider_register_typeface2(sk_typefacefontprovider_t* self, sk_typeface_t* typeface, const char family_name[]);

SK_C_PLUS_PLUS_END_GUARD
#endif
