#ifndef sk_colorspace_DEFINED
#define sk_colorspace_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API bool sk_colorspace_gamma_close_to_srgb(const sk_colorspace_t *self);
SK_C_API bool sk_colorspace_gamma_is_linear(const sk_colorspace_t *self);
SK_C_API bool sk_colorspace_is_equal(const sk_colorspace_t *self, const sk_colorspace_t *color_space);
SK_C_API bool sk_colorspace_is_numerical_transfer_fn(const sk_colorspace_t *self, /*out*/ sk_colorspacetransferfn_t *transfer_function);
SK_C_API bool sk_colorspace_is_srgb(const sk_colorspace_t *self);
SK_C_API sk_colorspace_t *sk_colorspace_make(const sk_colorspaceiccprofile_t *profile);
SK_C_API sk_colorspace_t *sk_colorspace_make_linear_gamma(const sk_colorspace_t *self);
SK_C_API sk_colorspace_t *sk_colorspace_make_rgb(const sk_colorspacetransferfn_t *transfer_function, const sk_colorspacexyz_t *xyz);
SK_C_API sk_colorspace_t *sk_colorspace_make_srgb(void);
SK_C_API sk_colorspace_t *sk_colorspace_make_p3(void);
SK_C_API sk_colorspace_t *sk_colorspace_make_srgb_gamma(const sk_colorspace_t *self);
SK_C_API sk_colorspace_t *sk_colorspace_make_srgb_linear(void);
SK_C_API void sk_colorspace_ref(const sk_colorspace_t *self);
SK_C_API sk_colorspaceiccprofile_t *sk_colorspace_to_profile(const sk_colorspace_t *self);
SK_C_API bool sk_colorspace_to_xyz(const sk_colorspace_t *self, /*out*/ sk_colorspacexyz_t *xyz);
SK_C_API void sk_colorspace_unref(const sk_colorspace_t *self);
SK_C_API void sk_colorspaceiccprofile_destroy(sk_colorspaceiccprofile_t *self);
SK_C_API const uint8_t *sk_colorspaceiccprofile_get_buffer(const sk_colorspaceiccprofile_t *self, uint32_t *size);
SK_C_API sk_colorspaceiccprofile_t *sk_colorspaceiccprofile_make_with_parse(const void *buffer, size_t size);
SK_C_API bool sk_colorspaceiccprofile_to_xyz(const sk_colorspaceiccprofile_t *self, /*out*/ sk_colorspacexyz_t *dest);
SK_C_API bool sk_colorspaceprimaries_to_xyz(const sk_colorspaceprimaries_t *self, /*out*/ sk_colorspacexyz_t *xyz);
SK_C_API bool sk_colorspacetransferfn_invert(const sk_colorspacetransferfn_t *self, sk_colorspacetransferfn_t *transfer_function);
SK_C_API float sk_colorspacetransferfn_transform(const sk_colorspacetransferfn_t *self, float x);

SK_C_PLUS_PLUS_END_GUARD
#endif
