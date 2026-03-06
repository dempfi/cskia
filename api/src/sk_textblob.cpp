#include "include/sk_textblob.h"

#include "sk_mapping.h"

int32_t sk_textblob_get_intercepts(const sk_textblob_t* self, const float bounds[2], float result[], const sk_paint_t* paint) {
  return AsTextBlob(self)->getIntercepts(bounds, result, AsPaint(paint));
}

sk_textblob_t* sk_textblob_make_from_text(const void* text, size_t size, const sk_font_t* font, sk_textencoding_t encoding) {
  return ToTextBlob(SkTextBlob::MakeFromText(text, size, AsFont(*font), AsTextEncoding(encoding)).release());
}

sk_textblob_t* sk_textblob_make_from_text_horizontally_positioned(const void* text, size_t size, const float x_positions[], float y, const sk_font_t* font, sk_textencoding_t encoding) {
  return ToTextBlob(SkTextBlob::MakeFromPosTextH(text, size, x_positions, y, AsFont(*font), AsTextEncoding(encoding)).release());
}

sk_textblob_t* sk_textblob_make_from_text_positioned(const void* text, size_t size, const sk_point_t positions[], const sk_font_t* font, sk_textencoding_t encoding) {
  return ToTextBlob(SkTextBlob::MakeFromPosText(text, size, AsPoint(positions), AsFont(*font), AsTextEncoding(encoding)).release());
}

sk_textblob_t* sk_textblob_make_from_text_transform(const void* text, size_t size, const sk_rotationscalematrix_t matrices[], const sk_font_t* font, sk_textencoding_t encoding) {
  return ToTextBlob(SkTextBlob::MakeFromRSXform(text, size, AsRotationScaleMatrix(matrices), AsFont(*font), AsTextEncoding(encoding)).release());
}

void sk_textblob_ref(const sk_textblob_t* self) {
  AsTextBlob(self)->ref();
}

void sk_textblob_unref(const sk_textblob_t* self) {
  AsTextBlob(self)->unref();
}

void sk_textblob_get_bounds(const sk_textblob_t* blob, sk_rect_t* bounds) {
  *bounds = reinterpret_cast<const sk_rect_t&>(reinterpret_cast<const SkTextBlob*>(blob)->bounds());
};

// sk_textblob_builder_t

sk_textblob_builder_t* sk_textblob_builder_new(void) {
  return reinterpret_cast<sk_textblob_builder_t*>(new SkTextBlobBuilder());
};

void sk_textblob_builder_delete(sk_textblob_builder_t* builder) {
  delete reinterpret_cast<SkTextBlobBuilder*>(builder);
};

sk_textblob_t* sk_textblob_builder_make(sk_textblob_builder_t* builder) {
  return reinterpret_cast<sk_textblob_t*>(reinterpret_cast<SkTextBlobBuilder*>(builder)->make().release());
};

void sk_textblob_builder_alloc_run(sk_textblob_builder_t* builder, const sk_font_t* font, int count, float x, float y, const sk_rect_t* bounds, sk_textblob_builder_runbuffer_t* runbuffer) {
  *runbuffer = reinterpret_cast<const sk_textblob_builder_runbuffer_t&>(reinterpret_cast<SkTextBlobBuilder*>(builder)->allocRun(reinterpret_cast<const SkFont&>(*font), count, x, y, reinterpret_cast<const SkRect*>(bounds)));
};

void sk_textblob_builder_alloc_run_pos_h(sk_textblob_builder_t* builder, const sk_font_t* font, int count, float y, const sk_rect_t* bounds, sk_textblob_builder_runbuffer_t* runbuffer) {
  *runbuffer = reinterpret_cast<const sk_textblob_builder_runbuffer_t&>(reinterpret_cast<SkTextBlobBuilder*>(builder)->allocRunPosH(reinterpret_cast<const SkFont&>(*font), count, y, reinterpret_cast<const SkRect*>(bounds)));
};

void sk_textblob_builder_alloc_run_pos(sk_textblob_builder_t* builder, const sk_font_t* font, int count, const sk_rect_t* bounds, sk_textblob_builder_runbuffer_t* runbuffer) {
  *runbuffer = reinterpret_cast<const sk_textblob_builder_runbuffer_t&>(reinterpret_cast<SkTextBlobBuilder*>(builder)->allocRunPos(reinterpret_cast<const SkFont&>(*font), count, reinterpret_cast<const SkRect*>(bounds)));
};

void sk_textblob_builder_alloc_run_rsxform(sk_textblob_builder_t* builder, const sk_font_t* font, int count, sk_textblob_builder_runbuffer_t* runbuffer) {
  *runbuffer = reinterpret_cast<const sk_textblob_builder_runbuffer_t&>(reinterpret_cast<SkTextBlobBuilder*>(builder)->allocRunRSXform(reinterpret_cast<const SkFont&>(*font), count));
};

// (obsolete)
void sk_textblob_builder_alloc_run_text(sk_textblob_builder_t* builder, const sk_font_t* font, int count, float x, float y, int textByteCount, const sk_rect_t* bounds, sk_textblob_builder_runbuffer_t* runbuffer) {
  *runbuffer = reinterpret_cast<const sk_textblob_builder_runbuffer_t&>(reinterpret_cast<SkTextBlobBuilder*>(builder)->allocRunText(reinterpret_cast<const SkFont&>(*font), count, x, y, textByteCount, reinterpret_cast<const SkRect*>(bounds)));
};

void sk_textblob_builder_alloc_run_text_pos_h(sk_textblob_builder_t* builder, const sk_font_t* font, int count, float y, int textByteCount, const sk_rect_t* bounds, sk_textblob_builder_runbuffer_t* runbuffer) {
  *runbuffer = reinterpret_cast<const sk_textblob_builder_runbuffer_t&>(reinterpret_cast<SkTextBlobBuilder*>(builder)->allocRunTextPosH(reinterpret_cast<const SkFont&>(*font), count, y, textByteCount, reinterpret_cast<const SkRect*>(bounds)));
};

void sk_textblob_builder_alloc_run_text_pos(sk_textblob_builder_t* builder, const sk_font_t* font, int count, int textByteCount, const sk_rect_t* bounds, sk_textblob_builder_runbuffer_t* runbuffer) {
  *runbuffer = reinterpret_cast<const sk_textblob_builder_runbuffer_t&>(reinterpret_cast<SkTextBlobBuilder*>(builder)->allocRunTextPos(reinterpret_cast<const SkFont&>(*font), count, textByteCount, reinterpret_cast<const SkRect*>(bounds)));
};
