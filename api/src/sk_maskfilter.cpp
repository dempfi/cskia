#include "include/sk_maskfilter.h"
#include "sk_mapping.h"

sk_maskfilter_t *sk_maskfilter_make_blur(sk_blurstyle_t style, float sigma, bool respect_ctm)
{
  return ToMaskFilter(SkMaskFilter::MakeBlur(AsBlurStyle(style), sigma, respect_ctm).release());
}

sk_maskfilter_t *sk_maskfilter_make_shader(sk_shader_t *shader)
{
  return ToMaskFilter(SkShaderMaskFilter::Make(sk_ref_sp(AsShader(shader))).release());
}

sk_maskfilter_t *sk_maskfilter_make_table(const uint8_t *table)
{
  return ToMaskFilter(SkTableMaskFilter::Create(table));
}

sk_maskfilter_t *sk_maskfilter_make_table_clip(uint8_t min, uint8_t max)
{
  return ToMaskFilter(SkTableMaskFilter::CreateClip(min, max));
}

sk_maskfilter_t *sk_maskfilter_make_table_gamma(float gamma)
{
  return ToMaskFilter(SkTableMaskFilter::CreateGamma(gamma));
}
