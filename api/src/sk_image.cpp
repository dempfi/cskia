#include "include/sk_image.h"

#include <memory>
#include <utility>

#include "include/gpu/ganesh/SkImageGanesh.h"
#include "sk_mapping.h"

sk_alphatype_t sk_image_get_alpha_type(const sk_image_t* self) {
  return ToAlphaType(AsImage(self)->alphaType());
}

sk_colorspace_t* sk_image_get_color_space(const sk_image_t* self) {
  return ToColorSpace(AsImage(self)->refColorSpace().release());
}

sk_colortype_t sk_image_get_color_type(const sk_image_t* self) {
  return ToColorType(AsImage(self)->colorType());
}

int32_t sk_image_get_height(const sk_image_t* self) {
  return AsImage(self)->height();
}

void sk_image_get_image_info(const sk_image_t* self, sk_imageinfo_t* result) {
  *result = ToImageInfo(AsImage(self)->imageInfo());
}

uint32_t sk_image_get_unique_id(const sk_image_t* self) {
  return AsImage(self)->uniqueID();
}

int32_t sk_image_get_width(const sk_image_t* self) {
  return AsImage(self)->width();
}

bool sk_image_is_lazy_generated(const sk_image_t* self) {
  return AsImage(self)->isLazyGenerated();
}

bool sk_image_is_texture_backed(const sk_image_t* self) {
  return AsImage(self)->isTextureBacked();
}

bool sk_image_is_valid(const sk_image_t* self, gr_directcontext_t* context) {
  return AsImage(self)->isValid(SK_ONLY_GPU(AsGrDirectContext(context), nullptr));
}

sk_image_t* sk_image_make_cross_context(gr_directcontext_t* context, const sk_pixmap_t* pixmap, bool build_mips, bool limit_to_max_texture_size) {
  return SK_ONLY_GPU(ToImage(SkImages::CrossContextTextureFromPixmap(AsGrDirectContext(context), AsPixmap(*pixmap), build_mips, limit_to_max_texture_size).release()), nullptr);
}

sk_image_t* sk_image_make_from_adopted_texture(gr_directcontext_t* context, const gr_backendtexture_t* texture, gr_surfaceorigin_t origin, sk_colortype_t color_type, sk_alphatype_t alpha_type, sk_colorspace_t* color_space) {
  return SK_ONLY_GPU(ToImage(SkImages::AdoptTextureFrom(AsGrDirectContext(context), AsGrBackendTexture(*texture), AsGrSurfaceOrigin(origin), AsColorType(color_type), AsAlphaType(alpha_type), sk_ref_sp(AsColorSpace(color_space))).release()), nullptr);
}

sk_image_t* sk_image_make_from_encoded_file(const char file_name[]) {
  auto data = SkData::MakeFromFileName(file_name);
  if (!data)
    return nullptr;
  return ToImage(SkImages::DeferredFromEncodedData(data).release());
}

sk_image_t* sk_image_make_from_encoded_stream(sk_stream_t* stream) {
  if (!AsStream(stream)->hasLength())
    return nullptr;
  auto data = SkData::MakeFromStream(AsStream(stream), AsStream(stream)->getLength());
  if (!data)
    return nullptr;
  return ToImage(SkImages::DeferredFromEncodedData(data).release());
}

sk_image_t* sk_image_make_from_picture(sk_picture_t* picture, const sk_isize_t* dimensions, const sk_matrix_t* matrix, const sk_paint_t* paint, sk_colorspace_t* color_space, const sk_surfaceprops_t* props) {
  SkMatrix m;
  if (matrix)
    m = AsMatrix(matrix);
  if (props)
    return ToImage(SkImages::DeferredFromPicture(sk_ref_sp(AsPicture(picture)), AsISize(*dimensions), (matrix) ? &m : nullptr, AsPaint(paint), SkImages::BitDepth::kU8, sk_ref_sp(AsColorSpace(color_space)), *AsSurfaceProps(props)).release());
  else
    return ToImage(SkImages::DeferredFromPicture(sk_ref_sp(AsPicture(picture)), AsISize(*dimensions), (matrix) ? &m : nullptr, AsPaint(paint), SkImages::BitDepth::kU8, sk_ref_sp(AsColorSpace(color_space))).release());
}

sk_image_t* sk_image_make_from_raster(const sk_pixmap_t* pixmap, sk_image_raster_release_proc proc, void* proc_context) {
  return ToImage(SkImages::RasterFromPixmap(AsPixmap(*pixmap), proc, proc_context).release());
}

sk_image_t* sk_image_make_from_texture(gr_directcontext_t* context, const gr_backendtexture_t* texture, gr_surfaceorigin_t origin, sk_colortype_t color_type, sk_alphatype_t alpha_type, sk_colorspace_t* color_space, sk_image_texture_release_proc proc, void* proc_context) {
  return SK_ONLY_GPU(ToImage(SkImages::BorrowTextureFrom(AsGrDirectContext(context), AsGrBackendTexture(*texture), AsGrSurfaceOrigin(origin), AsColorType(color_type), AsAlphaType(alpha_type), sk_ref_sp(AsColorSpace(color_space)), proc, proc_context).release()), nullptr);
}

sk_image_t* sk_image_make_non_texture_image(const sk_image_t* self) {
  return ToImage(AsImage(self)->makeNonTextureImage().release());
}

sk_image_t* sk_image_make_raster_copy(const sk_pixmap_t* pixmap) {
  return ToImage(SkImages::RasterFromPixmapCopy(AsPixmap(*pixmap)).release());
}

sk_image_t* sk_image_make_raster_image(const sk_image_t* self) {
  return ToImage(AsImage(self)->makeRasterImage().release());
}

sk_shader_t* sk_image_make_raw_shader(const sk_image_t* self, sk_tilemode_t tile_mode_x, sk_tilemode_t tile_mode_y, const sk_samplingoptions_t* sampling, const sk_matrix_t* local_matrix) {
  SkMatrix m;
  if (local_matrix)
    m = AsMatrix(local_matrix);
  return ToShader(AsImage(self)->makeRawShader(AsTileMode(tile_mode_x), AsTileMode(tile_mode_y), AsSamplingOptions(*sampling), (local_matrix) ? &m : nullptr).release());
}

sk_shader_t* sk_image_make_shader(const sk_image_t* self, sk_tilemode_t tile_mode_x, sk_tilemode_t tile_mode_y, const sk_samplingoptions_t* sampling, const sk_matrix_t* local_matrix) {
  SkMatrix m;
  if (local_matrix)
    m = AsMatrix(local_matrix);
  return ToShader(AsImage(self)->makeShader(AsTileMode(tile_mode_x), AsTileMode(tile_mode_y), AsSamplingOptions(*sampling), (local_matrix) ? &m : nullptr).release());
}

sk_image_t* sk_image_make_subset(const sk_image_t* self, const sk_irect_t* subset, gr_directcontext_t* context) {
  return ToImage(AsImage(self)->makeSubset(SK_ONLY_GPU(AsGrDirectContext(context), nullptr), AsIRect(*subset)).release());
}

sk_image_t* sk_image_make_texture_image(const sk_image_t* self, gr_directcontext_t* context, bool is_mipmapped) {
  return SK_ONLY_GPU(ToImage(SkImages::TextureFromImage(AsGrDirectContext(context), AsImage(self)).release()), nullptr);
}

sk_image_t* sk_image_make_with_filter(const sk_image_t* self, gr_directcontext_t* context, const sk_imagefilter_t* filter, const sk_irect_t* subset, const sk_irect_t* clip_bounds, sk_irect_t* out_subset, sk_ipoint_t* offset) {
  return ToImage(AsImage(self)->makeWithFilter(SK_ONLY_GPU(AsGrDirectContext(context), nullptr), AsImageFilter(filter), AsIRect(*subset), AsIRect(*clip_bounds), AsIRect(out_subset), AsIPoint(offset)).release());
}

sk_pixmap_t* sk_image_peek_pixels(const sk_image_t* self) {
  auto r = std::make_unique<SkPixmap>();
  return AsImage(self)->peekPixels(r.get()) ? ToPixmap(r.release()) : nullptr;
}

bool sk_image_read_pixels(const sk_image_t* self, gr_directcontext_t* context, const sk_pixmap_t* dest, int32_t src_x, int32_t src_y, sk_imagecachinghint_t caching_hint) {
  return AsImage(self)->readPixels(SK_ONLY_GPU(AsGrDirectContext(context), nullptr), AsPixmap(*dest), src_x, src_y, AsImageCachingHint(caching_hint));
}

bool sk_image_scale_pixels(const sk_image_t* self, const sk_pixmap_t* dest, const sk_samplingoptions_t* sampling, sk_imagecachinghint_t caching_hint) {
  return AsImage(self)->scalePixels(AsPixmap(*dest), AsSamplingOptions(*sampling), AsImageCachingHint(caching_hint));
}
