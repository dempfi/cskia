#include "sk_mapping.h"
#include "include/sk_colorspace.h"
#include "include/core/SkColorSpace.h"

sk_colorspace_t *sk_colorspace_new_p3(void)
{
  return reinterpret_cast<sk_colorspace_t *>(SkColorSpace::MakeRGB(SkNamedTransferFn::kSRGB, SkNamedGamut::kDisplayP3).release());
};

sk_colorspace_t *sk_colorspace_new_srgb(void)
{
  return reinterpret_cast<sk_colorspace_t *>(SkColorSpace::MakeSRGB().release());
};

void sk_colorspace_unref(sk_colorspace_t *colorspace)
{
  SkSafeUnref(reinterpret_cast<SkColorSpace *>(colorspace));
};
