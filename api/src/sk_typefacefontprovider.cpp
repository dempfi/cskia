#include "include/sk_typefacefontprovider.h"

#include "sk_paragraph_mapping.h"

sk_typefacefontprovider_t* sk_typefacefontprovider_create(void) {
  return ToTypefaceFontProvider(new skia::textlayout::TypefaceFontProvider());
}

void sk_typefacefontprovider_register_typeface(sk_typefacefontprovider_t* self, sk_typeface_t* typeface) {
  AsTypefaceFontProvider(self)->registerTypeface(sk_ref_sp(AsTypeface(typeface)));
}

void sk_typefacefontprovider_register_typeface2(sk_typefacefontprovider_t* self, sk_typeface_t* typeface, const char family_name[]) {
  AsTypefaceFontProvider(self)->registerTypeface(sk_ref_sp(AsTypeface(typeface)), SkString(family_name));
}
