#include "include/sk_blender.h"

#include "sk_mapping.h"

sk_blender_t* sk_blender_make_arithmetic(float k1, float k2, float k3, float k4, bool enforce_premultiplied_color) {
  return ToBlender(SkBlenders::Arithmetic(k1, k2, k3, k4, enforce_premultiplied_color).release());
}

sk_blender_t* sk_blender_make_mode(sk_blendmode_t mode) {
  return ToBlender(SkBlender::Mode(AsBlendMode(mode)).release());
}
