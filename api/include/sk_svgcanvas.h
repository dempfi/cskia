#ifndef sk_svgcanvas_DEFINED
#define sk_svgcanvas_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_canvas_t *sk_svgcanvas_make(const sk_rect_t *bounds, sk_wstream_t *w_stream, uint32_t flags);

SK_C_PLUS_PLUS_END_GUARD
#endif
