#include <string.h>

#include "include/sk_paragraphbuilder.h"
#include "sk_paragraph_mapping.h"

void sk_paragraphbuilder_add_placeholder(sk_paragraphbuilder_t *self, const sk_placeholderstyle_t *placeholder)
{
  AsParagraphBuilder(self)->addPlaceholder(AsPlaceholderStyle(*placeholder));
}

void sk_paragraphbuilder_add_text(sk_paragraphbuilder_t *self, const char text[])
{
  AsParagraphBuilder(self)->addText(text, strlen(text));
}

sk_paragraph_t *sk_paragraphbuilder_build(sk_paragraphbuilder_t *self)
{
  return ToParagraph(AsParagraphBuilder(self)->Build().release());
}

sk_paragraphbuilder_t *sk_paragraphbuilder_create(const sk_paragraphstyle_t *paragraph_style)
{
  auto fontCollection = sk_make_sp<skia::textlayout::FontCollection>();
  fontCollection->setDefaultFontManager(SkFontMgr::RefDefault());
  return ToParagraphBuilder(skia::textlayout::ParagraphBuilder::make(AsParagraphStyle(*paragraph_style), fontCollection).release());
}

sk_paragraphbuilder_t *sk_paragraphbuilder_create2(const sk_paragraphstyle_t *paragraph_style, sk_fontmgr_t *font_provider, bool enable_font_fallback)
{
  auto fontCollection = sk_make_sp<skia::textlayout::FontCollection>();
  if (enable_font_fallback)
    fontCollection->setDefaultFontManager(SkFontMgr::RefDefault());
  fontCollection->setAssetFontManager(sk_ref_sp(AsFontMgr(font_provider)));
  return ToParagraphBuilder(skia::textlayout::ParagraphBuilder::make(AsParagraphStyle(*paragraph_style), fontCollection).release());
}

void sk_paragraphbuilder_destroy(sk_paragraphbuilder_t *self)
{
  delete AsParagraphBuilder(self);
}

void sk_paragraphbuilder_pop(sk_paragraphbuilder_t *self)
{
  AsParagraphBuilder(self)->pop();
}

void sk_paragraphbuilder_push_style(sk_paragraphbuilder_t *self, const sk_textstyle_t *text_style)
{
  AsParagraphBuilder(self)->pushStyle(AsTextStyle(*text_style));
}
