#include "include/sk_fontmgr.h"

#include "sk_mapping.h"

#if defined(SK_BUILD_FOR_MAC) || defined(SK_BUILD_FOR_IOS)
#include "include/ports/SkFontMgr_mac_ct.h"
#elif defined(SK_BUILD_FOR_ANDROID)
#include "include/ports/SkFontMgr_android.h"
#elif defined(SK_FONTMGR_FONTCONFIG_AVAILABLE)
#include "include/ports/SkFontMgr_fontconfig.h"
#else
#include "include/ports/SkFontMgr_empty.h"
#endif

static sk_sp<SkFontMgr> sk_get_default_fontmgr() {
#if defined(SK_BUILD_FOR_MAC) || defined(SK_BUILD_FOR_IOS)
  return SkFontMgr_New_CoreText(nullptr);
#elif defined(SK_BUILD_FOR_ANDROID)
  return SkFontMgr_New_Android(nullptr, nullptr);
#elif defined(SK_FONTMGR_FONTCONFIG_AVAILABLE)
  return SkFontMgr_New_FontConfig(nullptr, nullptr);
#else
  return SkFontMgr_New_Custom_Empty();
#endif
}

sk_fontmgr_t* sk_fontmgr_create_default(void) {
  return ToFontMgr(sk_get_default_fontmgr().release());
}

void sk_fontmgr_unref(sk_fontmgr_t* self) {
  AsFontMgr(self)->unref();
}

int32_t sk_fontmgr_count_families(const sk_fontmgr_t* self) {
  return AsFontMgr(self)->countFamilies();
}

sk_string_t* sk_fontmgr_get_family_name(const sk_fontmgr_t* self, int32_t index) {
  auto r = new SkString();
  AsFontMgr(self)->getFamilyName(index, r);
  return ToString(r);
}

sk_fontstyleset_t* sk_fontmgr_create_styleset(const sk_fontmgr_t* self, int32_t index) {
  auto ss = AsFontMgr(self)->createStyleSet(index);
  return ToFontStyleSet(ss.release());
}

sk_fontstyleset_t* sk_fontmgr_match_family(const sk_fontmgr_t* self, const char family_name[]) {
  auto ss = AsFontMgr(self)->matchFamily(family_name);
  return ToFontStyleSet(ss.release());
}

sk_typeface_t* sk_fontmgr_match_family_style(const sk_fontmgr_t* self, const char family_name[], const sk_fontstyle_t* style) {
  auto tf = AsFontMgr(self)->matchFamilyStyle(family_name, AsFontStyle(style));
  return ToTypeface(tf.release());
}

sk_typeface_t* sk_fontmgr_match_family_style_character(const sk_fontmgr_t* self, const char family_name[], const sk_fontstyle_t* style, const char* bcp47[], int32_t bcp47_count, sk_unichar_t character) {
  auto tf = AsFontMgr(self)->matchFamilyStyleCharacter(family_name, AsFontStyle(style), bcp47, bcp47_count, character);
  return ToTypeface(tf.release());
}

sk_typeface_t* sk_fontmgr_make_from_data(sk_fontmgr_t* self, sk_data_t* data, int32_t ttc_index) {
  return ToTypeface(AsFontMgr(self)->makeFromData(sk_ref_sp(AsData(data)), ttc_index).release());
}

sk_typeface_t* sk_fontmgr_make_from_file(sk_fontmgr_t* self, const char file_name[], int32_t ttc_index) {
  return ToTypeface(AsFontMgr(self)->makeFromFile(file_name, ttc_index).release());
}
