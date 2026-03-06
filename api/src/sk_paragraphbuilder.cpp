#include "include/sk_paragraphbuilder.h"

#include <string.h>

#include "sk_default_fontmgr.h"
#include "sk_paragraph_mapping.h"
#include "modules/skunicode/include/SkUnicode.h"

#if defined(SK_UNICODE_ICU_IMPLEMENTATION)
#include "modules/skunicode/include/SkUnicode_icu.h"
#elif defined(SK_UNICODE_ICU4X_IMPLEMENTATION)
#include "modules/skunicode/include/SkUnicode_icu4x.h"
#elif defined(SK_UNICODE_LIBGRAPHEME_IMPLEMENTATION)
#include "modules/skunicode/include/SkUnicode_libgrapheme.h"
#endif

static sk_sp<SkUnicode> sk_get_unicode() {
#if defined(SK_UNICODE_ICU_IMPLEMENTATION)
  return SkUnicodes::ICU::Make();
#elif defined(SK_UNICODE_ICU4X_IMPLEMENTATION)
  return SkUnicodes::ICU4X::Make();
#elif defined(SK_UNICODE_LIBGRAPHEME_IMPLEMENTATION)
  return SkUnicodes::Libgrapheme::Make();
#else
  return nullptr;
#endif
}

void sk_paragraphbuilder_add_placeholder(sk_paragraphbuilder_t* self, const sk_placeholderstyle_t* placeholder) {
  AsParagraphBuilder(self)->addPlaceholder(AsPlaceholderStyle(*placeholder));
}

void sk_paragraphbuilder_add_text(sk_paragraphbuilder_t* self, const char text[]) {
  AsParagraphBuilder(self)->addText(text, strlen(text));
}

void sk_paragraphbuilder_add_text_sized(sk_paragraphbuilder_t* self, const char text[], size_t length) {
  AsParagraphBuilder(self)->addText(text, length);
}

sk_paragraph_t* sk_paragraphbuilder_build(sk_paragraphbuilder_t* self) {
  return ToParagraph(AsParagraphBuilder(self)->Build().release());
}

sk_paragraphbuilder_t* sk_paragraphbuilder_create(const sk_paragraphstyle_t* paragraph_style) {
  auto unicode = sk_get_unicode();
  if (!unicode)
    return nullptr;
  auto fontCollection = sk_make_sp<skia::textlayout::FontCollection>();
  fontCollection->setDefaultFontManager(sk_get_default_fontmgr());
  return ToParagraphBuilder(skia::textlayout::ParagraphBuilder::make(AsParagraphStyle(*paragraph_style), fontCollection, std::move(unicode)).release());
}

sk_paragraphbuilder_t* sk_paragraphbuilder_create2(const sk_paragraphstyle_t* paragraph_style, sk_fontmgr_t* font_provider, bool enable_font_fallback) {
  auto unicode = sk_get_unicode();
  if (!unicode)
    return nullptr;
  auto fontCollection = sk_make_sp<skia::textlayout::FontCollection>();
  if (enable_font_fallback)
    fontCollection->setDefaultFontManager(sk_get_default_fontmgr());
  fontCollection->setAssetFontManager(sk_ref_sp(AsFontMgr(font_provider)));
  return ToParagraphBuilder(skia::textlayout::ParagraphBuilder::make(AsParagraphStyle(*paragraph_style), fontCollection, std::move(unicode)).release());
}

void sk_paragraphbuilder_destroy(sk_paragraphbuilder_t* self) {
  delete AsParagraphBuilder(self);
}

void sk_paragraphbuilder_pop(sk_paragraphbuilder_t* self) {
  AsParagraphBuilder(self)->pop();
}

void sk_paragraphbuilder_push_style(sk_paragraphbuilder_t* self, const sk_textstyle_t* text_style) {
  AsParagraphBuilder(self)->pushStyle(AsTextStyle(*text_style));
}
