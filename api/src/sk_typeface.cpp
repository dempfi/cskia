#include "include/sk_typeface.h"

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

sk_string_t* sk_typeface_get_family_name(const sk_typeface_t* self) {
  auto r = new SkString();
  AsTypeface(self)->getFamilyName(r);
  return ToString(r);
}

sk_fontslant_t sk_typeface_get_slant(const sk_typeface_t* self) {
  return ToFontSlant(AsTypeface(self)->fontStyle().slant());
}

void sk_typeface_get_style(const sk_typeface_t* self, sk_fontstyle_t* result) {
  *result = ToFontStyle(AsTypeface(self)->fontStyle());
}

int32_t sk_typeface_get_weight(const sk_typeface_t* self) {
  return AsTypeface(self)->fontStyle().weight();
}

int32_t sk_typeface_get_width(const sk_typeface_t* self) {
  return AsTypeface(self)->fontStyle().width();
}

sk_typeface_t* sk_typeface_make_default(void) {
  auto mgr = sk_get_default_fontmgr();
  return ToTypeface(mgr->legacyMakeTypeface("", SkFontStyle::Normal()).release());
}

sk_typeface_t* sk_typeface_make_from_file(const char file_name[], int32_t ttc_index) {
  auto mgr = sk_get_default_fontmgr();
  return ToTypeface(mgr->makeFromFile(file_name, ttc_index).release());
}

sk_typeface_t* sk_typeface_make_from_stream(sk_stream_t* stream, int32_t ttc_index) {
  if (!AsStream(stream)->hasLength())
    return nullptr;
  auto data = SkData::MakeFromStream(AsStream(stream), AsStream(stream)->getLength());
  if (!data)
    return nullptr;
  auto mgr = sk_get_default_fontmgr();
  return ToTypeface(mgr->makeFromData(data, ttc_index).release());
}

sk_typeface_t* sk_typeface_make_from_name(const char family_name[], const sk_fontstyle_t* style) {
  auto mgr = sk_get_default_fontmgr();
  return ToTypeface(mgr->legacyMakeTypeface(family_name, AsFontStyle(style)).release());
}
