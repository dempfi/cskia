#include "include/sk_paragraphbuilder.h"
#include "modules/skparagraph/include/ParagraphBuilder.h"

void sk_paragraphbuilder_add_placeholder(sk_paragraphbuilder_t *self, const sk_placeholderstyle_t *placeholder)
{
  reinterpret_cast<skia::textlayout::ParagraphBuilder *>(self)->addPlaceholder(*reinterpret_cast<const skia::textlayout::PlaceholderStyle *>(placeholder));
};

void sk_paragraphbuilder_add_text(sk_paragraphbuilder_t *self, const char text[])
{
  reinterpret_cast<skia::textlayout::ParagraphBuilder *>(self)->addText(text);
};

sk_paragraph_t *sk_paragraphbuilder_build(sk_paragraphbuilder_t *self)
{
  return reinterpret_cast<sk_paragraph_t *>(reinterpret_cast<skia::textlayout::ParagraphBuilder *>(self)->Build().release());
};

sk_paragraphbuilder_t *sk_paragraphbuilder_create(const sk_paragraphstyle_t *paragraph_style)
{
  auto fontCollection = sk_make_sp<skia::textlayout::FontCollection>();
  fontCollection->setDefaultFontManager(SkFontMgr::RefDefault());
  return reinterpret_cast<sk_paragraphbuilder_t *>(skia::textlayout::ParagraphBuilder::make(*reinterpret_cast<const skia::textlayout::ParagraphStyle *>(paragraph_style), fontCollection).release());
};

sk_paragraphbuilder_t *sk_paragraphbuilder_create2(const sk_paragraphstyle_t *paragraph_style, sk_fontmgr_t *font_provider, bool enable_font_fallback)
{
  auto fontCollection = sk_make_sp<skia::textlayout::FontCollection>();
  if (enable_font_fallback)
    fontCollection->setDefaultFontManager(SkFontMgr::RefDefault());
  fontCollection->setAssetFontManager(sk_ref_sp(reinterpret_cast<SkFontMgr *>(font_provider)));
  return reinterpret_cast<sk_paragraphbuilder_t *>(skia::textlayout::ParagraphBuilder::make(*reinterpret_cast<const skia::textlayout::ParagraphStyle *>(paragraph_style), fontCollection).release());
};

void sk_paragraphbuilder_destroy(sk_paragraphbuilder_t *self)
{
  delete reinterpret_cast<skia::textlayout::ParagraphBuilder *>(self);
};

void sk_paragraphbuilder_pop(sk_paragraphbuilder_t *self)
{
  reinterpret_cast<skia::textlayout::ParagraphBuilder *>(self)->pop();
};

void sk_paragraphbuilder_push_style(sk_paragraphbuilder_t *self, const sk_textstyle_t *text_style)
{
  reinterpret_cast<skia::textlayout::ParagraphBuilder *>(self)->pushStyle(*reinterpret_cast<const skia::textlayout::TextStyle *>(text_style));
};
