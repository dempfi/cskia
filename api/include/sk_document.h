#ifndef sk_document_DEFINED
#define sk_document_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_canvas_t *sk_document_begin_page(sk_document_t *self, float width, float height, const sk_rect_t *content);
SK_C_API void sk_document_close(sk_document_t *self);
SK_C_API void sk_document_end_page(sk_document_t *self);
SK_C_API sk_document_t *sk_document_make_pdf(sk_wstream_t *w_stream);
SK_C_API sk_document_t *sk_document_make_pdf2(sk_wstream_t *w_stream, const sk_pdfmetadata_t *metadata);
SK_C_API sk_document_t *sk_document_make_xps(sk_wstream_t *w_stream, float dpi);
SK_C_API void sk_document_terminate(sk_document_t *self);

SK_C_PLUS_PLUS_END_GUARD
#endif
