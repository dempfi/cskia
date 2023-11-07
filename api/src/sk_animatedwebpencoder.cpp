#include "include/sk_animatedwebpencoder.h"

#include "sk_mapping.h"

bool sk_animatedwebpencoder_encode_to_file(const char file_name[], const sk_frame_t src[], size_t count, int32_t quality) {
  SkFILEWStream file(file_name);
  SkWebpEncoder::Options opts;
  std::vector<SkEncoder::Frame> vector;
  vector.reserve(count);
  for (size_t i = 0; i < count; i++)
    vector.emplace_back(AsFrame(&src[i]));
  if (quality == 100) {
    opts.fCompression = SkWebpEncoder::Compression::kLossless;
    opts.fQuality = 75;
  } else {
    opts.fCompression = SkWebpEncoder::Compression::kLossy;
    opts.fQuality = quality;
  }
  return SkWebpEncoder::EncodeAnimated(&file, SkSpan(vector), opts);
}

bool sk_animatedwebpencoder_encode_to_stream(sk_wstream_t* w_stream, const sk_frame_t src[], size_t count, int32_t quality) {
  SkWebpEncoder::Options opts;
  std::vector<SkEncoder::Frame> vector;
  vector.reserve(count);
  for (size_t i = 0; i < count; i++)
    vector.emplace_back(AsFrame(&src[i]));
  if (quality == 100) {
    opts.fCompression = SkWebpEncoder::Compression::kLossless;
    opts.fQuality = 75;
  } else {
    opts.fCompression = SkWebpEncoder::Compression::kLossy;
    opts.fQuality = quality;
  }
  return SkWebpEncoder::EncodeAnimated(AsWStream(w_stream), SkSpan(vector), opts);
}
