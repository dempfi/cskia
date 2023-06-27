#include "sk_mapping.h"
#include "include/sk_path_effect.h"
#include "include/core/SkPathEffect.h"
#include "include/effects/Sk1DPathEffect.h"
#include "include/effects/Sk2DPathEffect.h"
#include "include/effects/SkColorMatrixFilter.h"
#include "include/effects/SkCornerPathEffect.h"
#include "include/effects/SkDashPathEffect.h"
#include "include/effects/SkDiscretePathEffect.h"
#include "include/effects/SkGradientShader.h"
#include "include/effects/SkHighContrastFilter.h"
#include "include/effects/SkImageFilters.h"
#include "include/effects/SkLumaColorFilter.h"
#include "include/effects/SkPerlinNoiseShader.h"
#include "include/effects/SkShaderMaskFilter.h"
#include "include/effects/SkTableColorFilter.h"
#include "include/effects/SkTableMaskFilter.h"
#include "include/effects/SkTrimPathEffect.h"

void sk_path_effect_unref(sk_path_effect_t *effect)
{
  SkSafeUnref(reinterpret_cast<SkPathEffect *>(effect));
};

sk_path_effect_t *sk_path_effect_create_compose(sk_path_effect_t *outer, sk_path_effect_t *inner)
{
  return reinterpret_cast<sk_path_effect_t *>(SkPathEffect::MakeCompose(sk_ref_sp(reinterpret_cast<SkPathEffect *>(outer)), sk_ref_sp(reinterpret_cast<SkPathEffect *>(inner))).release());
};

sk_path_effect_t *sk_path_effect_create_sum(sk_path_effect_t *first, sk_path_effect_t *second)
{
  return reinterpret_cast<sk_path_effect_t *>(SkPathEffect::MakeSum(sk_ref_sp(reinterpret_cast<SkPathEffect *>(first)), sk_ref_sp(reinterpret_cast<SkPathEffect *>(second))).release());
};

sk_path_effect_t *sk_path_effect_create_discrete(float segLength, float deviation, uint32_t seedAssist /*0*/)
{
  return reinterpret_cast<sk_path_effect_t *>(SkDiscretePathEffect::Make(segLength, deviation, seedAssist).release());
};

sk_path_effect_t *sk_path_effect_create_corner(float radius)
{
  return reinterpret_cast<sk_path_effect_t *>(SkCornerPathEffect::Make(radius).release());
};

sk_path_effect_t *sk_path_effect_create_1d_path(const sk_path_t *path, float advance, float phase, sk_path_effect_1d_style_t style)
{
  return reinterpret_cast<sk_path_effect_t *>(SkPath1DPathEffect::Make(*AsPath(path), advance, phase, (SkPath1DPathEffect::Style)style).release());
};

sk_path_effect_t *sk_path_effect_create_2d_line(float width, const sk_matrix_t *matrix)
{
  return reinterpret_cast<sk_path_effect_t *>(SkLine2DPathEffect::Make(width, AsMatrix(matrix)).release());
};

sk_path_effect_t *sk_path_effect_create_2d_path(const sk_matrix_t *matrix, const sk_path_t *path)
{
  return reinterpret_cast<sk_path_effect_t *>(SkPath2DPathEffect::Make(AsMatrix(matrix), *AsPath(path)).release());
};

sk_path_effect_t *sk_path_effect_create_dash(const float intervals[], int count, float phase)
{
  return reinterpret_cast<sk_path_effect_t *>(SkDashPathEffect::Make(intervals, count, phase).release());
};

sk_path_effect_t *sk_path_effect_create_trim(float start, float stop, sk_path_effect_trim_mode_t mode)
{
  return reinterpret_cast<sk_path_effect_t *>(SkTrimPathEffect::Make(start, stop, (SkTrimPathEffect::Mode)mode).release());
};
