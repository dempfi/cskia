#include "include/sk_fontstyleset.h"

#include "sk_mapping.h"

void sk_fontstyleset_unref(sk_fontstyleset_t* self) {
  AsFontStyleSet(self)->unref();
}

int32_t sk_fontstyleset_get_count(sk_fontstyleset_t* self) {
  return AsFontStyleSet(self)->count();
}

void sk_fontstyleset_get_style(sk_fontstyleset_t* self, int32_t index, sk_fontstyle_t* style, sk_string_t** name) {
  SkFontStyle fs;
  SkString str;
  AsFontStyleSet(self)->getStyle(index, &fs, &str);
  if (style)
    *style = ToFontStyle(fs);
  if (name)
    *name = ToString(new SkString(str));
}

sk_typeface_t* sk_fontstyleset_create_typeface(sk_fontstyleset_t* self, int32_t index) {
  auto tf = AsFontStyleSet(self)->createTypeface(index);
  return ToTypeface(tf.release());
}

sk_typeface_t* sk_fontstyleset_match_style(sk_fontstyleset_t* self, const sk_fontstyle_t* style) {
  auto tf = AsFontStyleSet(self)->matchStyle(AsFontStyle(style));
  return ToTypeface(tf.release());
}
