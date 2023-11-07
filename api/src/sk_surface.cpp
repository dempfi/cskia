#include "include/sk_surface.h"

#include <memory>

#include "sk_mapping.h"

void sk_surface_draw(sk_surface_t* self, sk_canvas_t* canvas, float x, float y, sk_paint_t* paint) {
  AsSurface(self)->draw(AsCanvas(canvas), x, y, AsPaint(paint));
}

sk_canvas_t* sk_surface_get_canvas(sk_surface_t* self) {
  return ToCanvas(AsSurface(self)->getCanvas());
}

void sk_surface_get_props(const sk_surface_t* self, sk_surfaceprops_t* result) {
  *result = ToSurfaceProps(AsSurface(self)->props());
}

sk_surface_t* sk_surface_make_from_ca_metal_layer(gr_directcontext_t* context, gr_mtl_handle_t layer, gr_surfaceorigin_t origin, int32_t sample_count, sk_colortype_t color_type, sk_colorspace_t* color_space, const sk_surfaceprops_t* props, /*out*/ gr_mtl_handle_t* drawable) {
  return SK_ONLY_METAL(ToSurface(SkSurfaces::WrapCAMetalLayer(AsGrDirectContext(context), layer, AsGrSurfaceOrigin(origin), sample_count, AsColorType(color_type), sk_ref_sp(AsColorSpace(color_space)), AsSurfaceProps(props), drawable).release()), nullptr);
}

sk_surface_t* sk_surface_make_from_mtk_view(gr_directcontext_t* context, gr_mtl_handle_t view, gr_surfaceorigin_t origin, int32_t sample_count, sk_colortype_t color_type, sk_colorspace_t* color_space, const sk_surfaceprops_t* props) {
  return SK_ONLY_METAL(ToSurface(SkSurfaces::WrapMTKView(AsGrDirectContext(context), view, AsGrSurfaceOrigin(origin), sample_count, AsColorType(color_type), sk_ref_sp(AsColorSpace(color_space)), AsSurfaceProps(props)).release()), nullptr);
}

sk_surface_t* sk_surface_make_from_render_target(gr_directcontext_t* context, const gr_backendrendertarget_t* render_target, gr_surfaceorigin_t origin, sk_colortype_t color_type, sk_colorspace_t* color_space, const sk_surfaceprops_t* props) {
  return SK_ONLY_GPU(ToSurface(SkSurfaces::WrapBackendRenderTarget(AsGrDirectContext(context), AsGrBackendRenderTarget(*render_target), AsGrSurfaceOrigin(origin), AsColorType(color_type), sk_ref_sp(AsColorSpace(color_space)), AsSurfaceProps(props)).release()), nullptr);
}

sk_surface_t* sk_surface_make_from_texture(gr_directcontext_t* context, const gr_backendtexture_t* texture, gr_surfaceorigin_t origin, int32_t sample_count, sk_colortype_t color_type, sk_colorspace_t* color_space, const sk_surfaceprops_t* props) {
  return SK_ONLY_GPU(ToSurface(SkSurfaces::WrapBackendTexture(AsGrDirectContext(context), AsGrBackendTexture(*texture), AsGrSurfaceOrigin(origin), sample_count, AsColorType(color_type), sk_ref_sp(AsColorSpace(color_space)), AsSurfaceProps(props)).release()), nullptr);
}

sk_image_t* sk_surface_make_image_snapshot(sk_surface_t* self) {
  return ToImage(AsSurface(self)->makeImageSnapshot().release());
}

sk_image_t* sk_surface_make_image_snapshot2(sk_surface_t* self, const sk_irect_t* bounds) {
  return ToImage(AsSurface(self)->makeImageSnapshot(AsIRect(*bounds)).release());
}

sk_surface_t* sk_surface_make_raster(const sk_imageinfo_t* image_info, size_t row_bytes, const sk_surfaceprops_t* props) {
  return ToSurface(SkSurfaces::Raster(AsImageInfo(image_info), row_bytes, AsSurfaceProps(props)).release());
}

sk_surface_t* sk_surface_make_raster_direct(const sk_pixmap_t* pixmap, sk_surface_raster_release_proc proc, void* proc_context, const sk_surfaceprops_t* props) {
  return ToSurface(SkSurfaces::WrapPixels(AsPixmap(pixmap)->info(), AsPixmap(pixmap)->writable_addr(), AsPixmap(pixmap)->rowBytes(), proc, proc_context, AsSurfaceProps(props)).release());
}

sk_surface_t* sk_surface_make_render_target(gr_directcontext_t* context, bool is_budgeted, const sk_imageinfo_t* image_info, int32_t sample_count, gr_surfaceorigin_t origin, const sk_surfaceprops_t* props, bool should_create_with_mips) {
  return SK_ONLY_GPU(ToSurface(SkSurfaces::RenderTarget(AsGrDirectContext(context), AsBudgeted(is_budgeted), AsImageInfo(image_info), sample_count, AsGrSurfaceOrigin(origin), AsSurfaceProps(props), should_create_with_mips).release()), nullptr);
}

sk_pixmap_t* sk_surface_peek_pixels(sk_surface_t* self) {
  auto r = std::make_unique<SkPixmap>();
  return AsSurface(self)->peekPixels(r.get()) ? ToPixmap(r.release()) : nullptr;
}

bool sk_surface_read_pixels(sk_surface_t* self, const sk_pixmap_t* dest, int32_t src_x, int32_t src_y) {
  return AsSurface(self)->readPixels(AsPixmap(*dest), src_x, src_y);
}

void sk_surface_wait(sk_surface_t* self, const gr_backendsemaphore_t* semaphores[], int32_t count) {
  SK_ONLY_GPU(
      GrFlushInfo info;
      std::vector<GrBackendSemaphore> vector;
      vector.reserve(count);
      for (size_t i = 0; i < count; i++)
          vector.emplace_back(*AsGrBackendSemaphore(semaphores[i]));
      AsSurface(self)->wait(count, vector.data());)
}

void sk_surface_write_pixels(sk_surface_t* self, const sk_pixmap_t* src, int32_t dest_x, int32_t dest_y) {
  AsSurface(self)->writePixels(AsPixmap(*src), dest_x, dest_y);
}

void sk_surface_unref(sk_surface_t* self) {
  SkSafeUnref(AsSurface(self));
};

float sk_surface_get_width(sk_surface_t* self) {
  return AsSurface(self)->width();
};

float sk_surface_get_height(sk_surface_t* self) {
  return AsSurface(self)->height();
};
