#include "include/sk_svgcanvas.h"

#include "sk_mapping.h"

sk_canvas_t* sk_svgcanvas_make(const sk_rect_t* bounds, sk_wstream_t* w_stream, uint32_t flags) {
  return ToCanvas(SkSVGCanvas::Make(AsRect(*bounds), AsWStream(w_stream), flags).release());
}
