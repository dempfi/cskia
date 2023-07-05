#ifndef sk_patheffect_DEFINED
#define sk_patheffect_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_patheffect_t *sk_patheffect_make_1dpath(const sk_path_t *path, float advance, float phase, sk_patheffect1dstyle_t style);
SK_C_API sk_patheffect_t *sk_patheffect_make_2dline(float width, const sk_matrix_t *matrix);
SK_C_API sk_patheffect_t *sk_patheffect_make_2dpath(const sk_matrix_t *matrix, const sk_path_t *path);
SK_C_API sk_patheffect_t *sk_patheffect_make_compose(sk_patheffect_t *outer, sk_patheffect_t *inner);
SK_C_API sk_patheffect_t *sk_patheffect_make_corner(float radius);
SK_C_API sk_patheffect_t *sk_patheffect_make_dash(const float intervals[], int32_t count, float phase);
SK_C_API sk_patheffect_t *sk_patheffect_make_discrete(float seg_length, float deviation, uint32_t seed_assist);
SK_C_API sk_patheffect_t *sk_patheffect_make_matrix(const sk_matrix_t *matrix);
SK_C_API sk_patheffect_t *sk_patheffect_make_merge(sk_patheffect_t *effect1, sk_patheffect_t *effect2, sk_pathop_t op);
SK_C_API sk_patheffect_t *sk_patheffect_make_stroke(float width, sk_strokejoin_t join, sk_strokecap_t cap, float miter);
SK_C_API sk_patheffect_t *sk_patheffect_make_stroke_and_fill(void);
SK_C_API sk_patheffect_t *sk_patheffect_make_sum(sk_patheffect_t *effect1, sk_patheffect_t *effect2);
SK_C_API sk_patheffect_t *sk_patheffect_make_translate(float dx, float dy);
SK_C_API sk_patheffect_t *sk_patheffect_make_trim(float start, float stop, sk_patheffecttrimmode_t mode);

SK_C_PLUS_PLUS_END_GUARD
#endif
