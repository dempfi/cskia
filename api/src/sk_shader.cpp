#include "include/sk_shader.h"

#include <vector>

#include "sk_mapping.h"

sk_shader_t* sk_shader_make_blend(sk_blendmode_t mode, sk_shader_t* dest, sk_shader_t* src) {
  return ToShader(SkShaders::Blend(AsBlendMode(mode), sk_ref_sp(AsShader(dest)), sk_ref_sp(AsShader(src))).release());
}

sk_shader_t* sk_shader_make_color(sk_color_t color) {
  return ToShader(SkShaders::Color(color).release());
}

sk_shader_t* sk_shader_make_color2(const sk_color4f_t* color, sk_colorspace_t* color_space) {
  return ToShader(SkShaders::Color(AsColor4f(*color), sk_ref_sp(AsColorSpace(color_space))).release());
}

sk_shader_t* sk_shader_make_empty(void) {
  return ToShader(SkShaders::Empty().release());
}

static SkGradient MakeGrad(const SkColor4f colors[], const float positions[], int32_t count, SkTileMode mode, sk_sp<SkColorSpace> cs = nullptr) {
  SkGradient::Colors c(SkSpan<const SkColor4f>(colors, count),
                        positions ? SkSpan<const float>(positions, count) : SkSpan<const float>(),
                        mode,
                        std::move(cs));
  return SkGradient(c, {});
}

static SkGradient MakeGradFromColors(const SkColor skColors[], const float positions[], int32_t count, SkTileMode mode) {
  // Convert SkColor (uint32_t) to SkColor4f
  std::vector<SkColor4f> colors4f(count);
  for (int i = 0; i < count; i++) {
    colors4f[i] = SkColor4f::FromColor(skColors[i]);
  }
  return MakeGrad(colors4f.data(), positions, count, mode);
}

sk_shader_t* sk_shader_make_gradient_linear(const sk_point_t points[2], const sk_color_t colors[], const float positions[], int32_t count, sk_tilemode_t tile_mode, const sk_matrix_t* local_matrix) {
  SkMatrix m;
  if (local_matrix)
    m = AsMatrix(local_matrix);
  auto grad = MakeGradFromColors(colors, positions, count, AsTileMode(tile_mode));
  return ToShader(SkShaders::LinearGradient(AsPoint(points), grad, (local_matrix) ? &m : nullptr).release());
}

sk_shader_t* sk_shader_make_gradient_linear2(const sk_point_t points[2], const sk_color4f_t colors[], sk_colorspace_t* color_space, const float positions[], int32_t count, sk_tilemode_t tile_mode, const sk_matrix_t* local_matrix) {
  SkMatrix m;
  if (local_matrix)
    m = AsMatrix(local_matrix);
  auto grad = MakeGrad(AsColor4f(colors), positions, count, AsTileMode(tile_mode), sk_ref_sp(AsColorSpace(color_space)));
  return ToShader(SkShaders::LinearGradient(AsPoint(points), grad, (local_matrix) ? &m : nullptr).release());
}

sk_shader_t* sk_shader_make_gradient_radial(const sk_point_t* center, float radius, const sk_color_t colors[], const float positions[], int32_t count, sk_tilemode_t tile_mode, const sk_matrix_t* local_matrix) {
  SkMatrix m;
  if (local_matrix)
    m = AsMatrix(local_matrix);
  auto grad = MakeGradFromColors(colors, positions, count, AsTileMode(tile_mode));
  return ToShader(SkShaders::RadialGradient(AsPoint(*center), radius, grad, (local_matrix) ? &m : nullptr).release());
}

sk_shader_t* sk_shader_make_gradient_radial2(const sk_point_t* center, float radius, const sk_color4f_t colors[], sk_colorspace_t* color_space, const float positions[], int32_t count, sk_tilemode_t tile_mode, const sk_matrix_t* local_matrix) {
  SkMatrix m;
  if (local_matrix)
    m = AsMatrix(local_matrix);
  auto grad = MakeGrad(AsColor4f(colors), positions, count, AsTileMode(tile_mode), sk_ref_sp(AsColorSpace(color_space)));
  return ToShader(SkShaders::RadialGradient(AsPoint(*center), radius, grad, (local_matrix) ? &m : nullptr).release());
}

sk_shader_t* sk_shader_make_gradient_sweep(float center_x, float center_y, const sk_color_t colors[], const float positions[], int32_t count, sk_tilemode_t tile_mode, float start_angle, float end_angle, const sk_matrix_t* local_matrix) {
  SkMatrix m;
  if (local_matrix)
    m = AsMatrix(local_matrix);
  auto grad = MakeGradFromColors(colors, positions, count, AsTileMode(tile_mode));
  return ToShader(SkShaders::SweepGradient(SkPoint::Make(center_x, center_y), start_angle, end_angle, grad, (local_matrix) ? &m : nullptr).release());
}

sk_shader_t* sk_shader_make_gradient_sweep2(float center_x, float center_y, const sk_color4f_t colors[], sk_colorspace_t* color_space, const float positions[], int32_t count, sk_tilemode_t tile_mode, float start_angle, float end_angle, const sk_matrix_t* local_matrix) {
  SkMatrix m;
  if (local_matrix)
    m = AsMatrix(local_matrix);
  auto grad = MakeGrad(AsColor4f(colors), positions, count, AsTileMode(tile_mode), sk_ref_sp(AsColorSpace(color_space)));
  return ToShader(SkShaders::SweepGradient(SkPoint::Make(center_x, center_y), start_angle, end_angle, grad, (local_matrix) ? &m : nullptr).release());
}

sk_shader_t* sk_shader_make_gradient_two_point_conical(const sk_point_t* start, float start_radius, const sk_point_t* end, float end_radius, const sk_color_t colors[], const float positions[], int32_t count, sk_tilemode_t tile_mode, const sk_matrix_t* local_matrix) {
  SkMatrix m;
  if (local_matrix)
    m = AsMatrix(local_matrix);
  auto grad = MakeGradFromColors(colors, positions, count, AsTileMode(tile_mode));
  return ToShader(SkShaders::TwoPointConicalGradient(AsPoint(*start), start_radius, AsPoint(*end), end_radius, grad, (local_matrix) ? &m : nullptr).release());
}

sk_shader_t* sk_shader_make_gradient_two_point_conical2(const sk_point_t* start, float start_radius, const sk_point_t* end, float end_radius, const sk_color4f_t colors[], sk_colorspace_t* color_space, const float positions[], int32_t count, sk_tilemode_t tile_mode, const sk_matrix_t* local_matrix) {
  SkMatrix m;
  if (local_matrix)
    m = AsMatrix(local_matrix);
  auto grad = MakeGrad(AsColor4f(colors), positions, count, AsTileMode(tile_mode), sk_ref_sp(AsColorSpace(color_space)));
  return ToShader(SkShaders::TwoPointConicalGradient(AsPoint(*start), start_radius, AsPoint(*end), end_radius, grad, (local_matrix) ? &m : nullptr).release());
}

sk_shader_t* sk_shader_make_with_color_filter(const sk_shader_t* self, sk_colorfilter_t* color_filter) {
  return ToShader(AsShader(self)->makeWithColorFilter(sk_ref_sp(AsColorFilter(color_filter))).release());
}

sk_shader_t* sk_shader_make_with_local_matrix(const sk_shader_t* self, const sk_matrix_t* local_matrix) {
  return ToShader(AsShader(self)->makeWithLocalMatrix(AsMatrix(local_matrix)).release());
}

void sk_shader_unref(sk_shader_t* self) {
  AsShader(self)->unref();
}
