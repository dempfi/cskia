#include "include/sk_colorspace.h"

#include <memory>

#include "include/core/SkColorSpace.h"
#include "sk_mapping.h"

bool sk_colorspace_gamma_close_to_srgb(const sk_colorspace_t* self) {
  return AsColorSpace(self)->gammaCloseToSRGB();
}

bool sk_colorspace_gamma_is_linear(const sk_colorspace_t* self) {
  return AsColorSpace(self)->gammaIsLinear();
}

bool sk_colorspace_is_equal(const sk_colorspace_t* self, const sk_colorspace_t* color_space) {
  return SkColorSpace::Equals(AsColorSpace(self), AsColorSpace(color_space));
}

bool sk_colorspace_is_numerical_transfer_fn(const sk_colorspace_t* self, sk_colorspacetransferfn_t* transfer_function) {
  return AsColorSpace(self)->isNumericalTransferFn(AsColorSpaceTransferFn(transfer_function));
}

bool sk_colorspace_is_srgb(const sk_colorspace_t* self) {
  return AsColorSpace(self)->isSRGB();
}

sk_colorspace_t* sk_colorspace_make(const sk_colorspaceiccprofile_t* profile) {
  return ToColorSpace(SkColorSpace::Make(AsColorSpaceICCProfile(*profile)).release());
}

sk_colorspace_t* sk_colorspace_make_linear_gamma(const sk_colorspace_t* self) {
  return ToColorSpace(AsColorSpace(self)->makeLinearGamma().release());
}

sk_colorspace_t* sk_colorspace_make_rgb(const sk_colorspacetransferfn_t* transfer_function, const sk_colorspacexyz_t* xyz) {
  return ToColorSpace(SkColorSpace::MakeRGB(AsColorSpaceTransferFn(*transfer_function), AsColorSpaceXYZ(*xyz)).release());
}

sk_colorspace_t* sk_colorspace_make_srgb(void) {
  return ToColorSpace(SkColorSpace::MakeSRGB().release());
}

sk_colorspace_t* sk_colorspace_make_p3(void) {
  return ToColorSpace(SkColorSpace::MakeRGB(SkNamedTransferFn::kSRGB, SkNamedGamut::kDisplayP3).release());
};

sk_colorspace_t* sk_colorspace_make_srgb_gamma(const sk_colorspace_t* self) {
  return ToColorSpace(AsColorSpace(self)->makeSRGBGamma().release());
}

sk_colorspace_t* sk_colorspace_make_srgb_linear(void) {
  return ToColorSpace(SkColorSpace::MakeSRGBLinear().release());
}

void sk_colorspace_ref(const sk_colorspace_t* self) {
  AsColorSpace(self)->ref();
}

sk_colorspaceiccprofile_t* sk_colorspace_to_profile(const sk_colorspace_t* self) {
  auto r = std::make_unique<skcms_ICCProfile>();
  AsColorSpace(self)->toProfile(r.get());
  return ToColorSpaceICCProfile(r.release());
}

bool sk_colorspace_to_xyz(const sk_colorspace_t* self, sk_colorspacexyz_t* xyz) {
  return AsColorSpace(self)->toXYZD50(AsColorSpaceXYZ(xyz));
}

void sk_colorspace_unref(const sk_colorspace_t* self) {
  AsColorSpace(self)->unref();
}

void sk_colorspaceiccprofile_destroy(sk_colorspaceiccprofile_t* self) {
  delete AsColorSpaceICCProfile(self);
}

const uint8_t* sk_colorspaceiccprofile_get_buffer(const sk_colorspaceiccprofile_t* self, uint32_t* size) {
  if (size)
    *size = AsColorSpaceICCProfile(self)->size;
  return AsColorSpaceICCProfile(self)->buffer;
}

sk_colorspaceiccprofile_t* sk_colorspaceiccprofile_make_with_parse(const void* buffer, size_t size) {
  auto r = std::make_unique<skcms_ICCProfile>();
  return skcms_Parse(buffer, size, r.get()) ? ToColorSpaceICCProfile(r.release()) : nullptr;
}

bool sk_colorspaceiccprofile_to_xyz(const sk_colorspaceiccprofile_t* self, sk_colorspacexyz_t* dest) {
  *dest = ToColorSpaceXYZ(AsColorSpaceICCProfile(self)->toXYZD50);
  return AsColorSpaceICCProfile(self)->has_toXYZD50;
}

bool sk_colorspaceprimaries_to_xyz(const sk_colorspaceprimaries_t* self, sk_colorspacexyz_t* xyz) {
  return AsColorSpacePrimaries(self)->toXYZD50(AsColorSpaceXYZ(xyz));
}

bool sk_colorspacetransferfn_invert(const sk_colorspacetransferfn_t* self, sk_colorspacetransferfn_t* transfer_function) {
  return skcms_TransferFunction_invert(AsColorSpaceTransferFn(self), AsColorSpaceTransferFn(transfer_function));
}

float sk_colorspacetransferfn_transform(const sk_colorspacetransferfn_t* self, float x) {
  return skcms_TransferFunction_eval(AsColorSpaceTransferFn(self), x);
}
