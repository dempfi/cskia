#include "sk_mapping.h"
#include "include/sk_typeface.h"
#include "include/core/SkTypeface.h"
#include "include/core/SkFontMgr.h"

void sk_typeface_unref(sk_typeface_t *typeface)
{
  AsTypeface(typeface)->unref();
};

sk_fontstyle_t *sk_typeface_get_fontstyle(const sk_typeface_t *typeface)
{
  return reinterpret_cast<sk_fontstyle_t *>(new SkFontStyle(AsTypeface(typeface)->fontStyle()));
};

int sk_typeface_get_font_weight(const sk_typeface_t *typeface)
{
  return AsTypeface(typeface)->fontStyle().weight();
};

int sk_typeface_get_font_width(const sk_typeface_t *typeface)
{
  return AsTypeface(typeface)->fontStyle().width();
};

sk_font_style_slant_t sk_typeface_get_font_slant(const sk_typeface_t *typeface)
{
  return static_cast<sk_font_style_slant_t>(AsTypeface(typeface)->fontStyle().slant());
};

bool sk_typeface_is_fixed_pitch(const sk_typeface_t *typeface)
{
  return AsTypeface(typeface)->isFixedPitch();
};

sk_typeface_t *sk_typeface_create_default(void)
{
  return ToTypeface(SkTypeface::MakeDefault().release());
};

sk_typeface_t *sk_typeface_create_from_name(const char *familyName, const sk_fontstyle_t *style)
{
  return ToTypeface(SkTypeface::MakeFromName(familyName, *reinterpret_cast<const SkFontStyle *>(style)).release());
};

sk_typeface_t *sk_typeface_create_from_file(const char *path, int index)
{
  return ToTypeface(SkTypeface::MakeFromFile(path, index).release());
};

void sk_typeface_unichars_to_glyphs(const sk_typeface_t *typeface, const int32_t unichars[], int count, uint16_t glyphs[])
{
  AsTypeface(typeface)->unicharsToGlyphs(unichars, count, glyphs);
};

uint16_t sk_typeface_unichar_to_glyph(const sk_typeface_t *typeface, const int32_t unichar)
{
  return AsTypeface(typeface)->unicharToGlyph(unichar);
};

int sk_typeface_count_glyphs(const sk_typeface_t *typeface)
{
  return AsTypeface(typeface)->countGlyphs();
};

int sk_typeface_count_tables(const sk_typeface_t *typeface)
{
  return AsTypeface(typeface)->countTables();
};

int sk_typeface_get_table_tags(const sk_typeface_t *typeface, sk_font_table_tag_t tags[])
{
  return AsTypeface(typeface)->getTableTags(tags);
};

size_t sk_typeface_get_table_size(const sk_typeface_t *typeface, sk_font_table_tag_t tag)
{
  return AsTypeface(typeface)->getTableSize(tag);
};

size_t sk_typeface_get_table_data(const sk_typeface_t *typeface, sk_font_table_tag_t tag, size_t offset, size_t length, void *data)
{
  return AsTypeface(typeface)->getTableData(tag, offset, length, data);
};

int sk_typeface_get_units_per_em(const sk_typeface_t *typeface)
{
  return AsTypeface(typeface)->getUnitsPerEm();
};

bool sk_typeface_get_kerning_pair_adjustments(const sk_typeface_t *typeface, const uint16_t glyphs[], int count, int32_t adjustments[])
{
  return AsTypeface(typeface)->getKerningPairAdjustments(glyphs, count, adjustments);
};

sk_string_t *sk_typeface_get_family_name(const sk_typeface_t *typeface)
{
  SkString *family_name = new SkString();
  AsTypeface(typeface)->getFamilyName(family_name);
  return ToString(family_name);
};

// font manager

sk_fontmgr_t *sk_fontmgr_ref_default(void)
{
  return ToFontMgr(SkFontMgr::RefDefault().release());
};

void sk_fontmgr_unref(sk_fontmgr_t *fontmgr)
{
  SkSafeUnref(AsFontMgr(fontmgr));
};

int sk_fontmgr_count_families(sk_fontmgr_t *fontmgr)
{
  return AsFontMgr(fontmgr)->countFamilies();
};

void sk_fontmgr_get_family_name(sk_fontmgr_t *fontmgr, int index, sk_string_t *familyName)
{
  AsFontMgr(fontmgr)->getFamilyName(index, reinterpret_cast<SkString *>(familyName));
};

sk_fontstyleset_t *sk_fontmgr_create_styleset(sk_fontmgr_t *fontmgr, int index)
{
  return reinterpret_cast<sk_fontstyleset_t *>(AsFontMgr(fontmgr)->createStyleSet(index).release());
};

sk_fontstyleset_t *sk_fontmgr_match_family(sk_fontmgr_t *fontmgr, const char *familyName)
{
  return reinterpret_cast<sk_fontstyleset_t *>(AsFontMgr(fontmgr)->matchFamily(familyName).release());
};

sk_typeface_t *sk_fontmgr_match_family_style(sk_fontmgr_t *fontmgr, const char *familyName, sk_fontstyle_t *style)
{
  return ToTypeface(AsFontMgr(fontmgr)->matchFamilyStyle(familyName, *reinterpret_cast<SkFontStyle *>(style)).release());
};

sk_typeface_t *sk_fontmgr_match_family_style_character(sk_fontmgr_t *fontmgr, const char *familyName, sk_fontstyle_t *style, const char **bcp47, int bcp47Count, int32_t character)
{
  return ToTypeface(AsFontMgr(fontmgr)->matchFamilyStyleCharacter(familyName, *reinterpret_cast<SkFontStyle *>(style), bcp47, bcp47Count, character).release());
};

sk_typeface_t *sk_fontmgr_create_from_file(sk_fontmgr_t *fontmgr, const char *path, int index)
{
  return ToTypeface(AsFontMgr(fontmgr)->makeFromFile(path, index).release());
};

// font style

sk_fontstyle_t *sk_fontstyle_new(int weight, int width, sk_font_style_slant_t slant)
{
  return reinterpret_cast<sk_fontstyle_t *>(new SkFontStyle(weight, width, static_cast<SkFontStyle::Slant>(slant)));
};

void sk_fontstyle_delete(sk_fontstyle_t *fs)
{
  delete reinterpret_cast<SkFontStyle *>(fs);
};

int sk_fontstyle_get_weight(const sk_fontstyle_t *fs)
{
  return reinterpret_cast<const SkFontStyle *>(fs)->weight();
};

int sk_fontstyle_get_width(const sk_fontstyle_t *fs)
{
  return reinterpret_cast<const SkFontStyle *>(fs)->width();
};

sk_font_style_slant_t sk_fontstyle_get_slant(const sk_fontstyle_t *fs)
{
  return static_cast<sk_font_style_slant_t>(reinterpret_cast<const SkFontStyle *>(fs)->slant());
};

// font style set

void sk_fontstyleset_unref(sk_fontstyleset_t *fss)
{
  SkSafeUnref(reinterpret_cast<SkFontStyleSet *>(fss));
};

int sk_fontstyleset_get_count(sk_fontstyleset_t *fss)
{
  return reinterpret_cast<SkFontStyleSet *>(fss)->count();
};

void sk_fontstyleset_get_style(sk_fontstyleset_t *fss, int index, sk_fontstyle_t *fs, sk_string_t *style)
{
  reinterpret_cast<SkFontStyleSet *>(fss)->getStyle(index, reinterpret_cast<SkFontStyle *>(fs), reinterpret_cast<SkString *>(style));
};

sk_typeface_t *sk_fontstyleset_create_typeface(sk_fontstyleset_t *fss, int index)
{
  return ToTypeface(reinterpret_cast<SkFontStyleSet *>(fss)->createTypeface(index).release());
};

sk_typeface_t *sk_fontstyleset_match_style(sk_fontstyleset_t *fss, sk_fontstyle_t *style)
{
  return ToTypeface(reinterpret_cast<SkFontStyleSet *>(fss)->matchStyle(*reinterpret_cast<SkFontStyle *>(style)).release());
};
