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

uint32_t sk_typeface_get_unique_id(const sk_typeface_t* self) {
  return AsTypeface(self)->uniqueID();
}

int32_t sk_typeface_count_glyphs(const sk_typeface_t* self) {
  return AsTypeface(self)->countGlyphs();
}

int32_t sk_typeface_get_units_per_em(const sk_typeface_t* self) {
  return AsTypeface(self)->getUnitsPerEm();
}

bool sk_typeface_is_fixed_pitch(const sk_typeface_t* self) {
  return AsTypeface(self)->isFixedPitch();
}

int32_t sk_typeface_count_tables(const sk_typeface_t* self) {
  return AsTypeface(self)->countTables();
}

int32_t sk_typeface_get_table_tags(const sk_typeface_t* self, uint32_t tags[]) {
  int count = AsTypeface(self)->countTables();
  if (tags && count > 0)
    return AsTypeface(self)->readTableTags(SkSpan<SkFontTableTag>(reinterpret_cast<SkFontTableTag*>(tags), count));
  return count;
}

size_t sk_typeface_get_table_size(const sk_typeface_t* self, uint32_t tag) {
  return AsTypeface(self)->getTableSize(tag);
}

size_t sk_typeface_get_table_data(const sk_typeface_t* self, uint32_t tag, size_t offset, size_t length, void* data) {
  return AsTypeface(self)->getTableData(tag, offset, length, data);
}

void sk_typeface_get_bounds(const sk_typeface_t* self, sk_rect_t* bounds) {
  *bounds = ToRect(AsTypeface(self)->getBounds());
}

void sk_typeface_unref(const sk_typeface_t* self) {
  AsTypeface(self)->unref();
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

sk_typeface_t* sk_typeface_make_from_data(sk_data_t* data, int32_t ttc_index) {
  auto mgr = sk_get_default_fontmgr();
  return ToTypeface(mgr->makeFromData(sk_ref_sp(AsData(data)), ttc_index).release());
}
