#ifndef sk_typeface_DEFINED
#define sk_typeface_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_string_t* sk_typeface_get_family_name(const sk_typeface_t* self);
SK_C_API sk_fontslant_t sk_typeface_get_slant(const sk_typeface_t* self);
SK_C_API void sk_typeface_get_style(const sk_typeface_t* self, /*out*/ sk_fontstyle_t* result);
SK_C_API int32_t sk_typeface_get_weight(const sk_typeface_t* self);
SK_C_API int32_t sk_typeface_get_width(const sk_typeface_t* self);
SK_C_API uint32_t sk_typeface_get_unique_id(const sk_typeface_t* self);
SK_C_API int32_t sk_typeface_count_glyphs(const sk_typeface_t* self);
SK_C_API int32_t sk_typeface_get_units_per_em(const sk_typeface_t* self);
SK_C_API bool sk_typeface_is_fixed_pitch(const sk_typeface_t* self);
SK_C_API int32_t sk_typeface_count_tables(const sk_typeface_t* self);
SK_C_API int32_t sk_typeface_get_table_tags(const sk_typeface_t* self, uint32_t tags[]);
SK_C_API size_t sk_typeface_get_table_size(const sk_typeface_t* self, uint32_t tag);
SK_C_API size_t sk_typeface_get_table_data(const sk_typeface_t* self, uint32_t tag, size_t offset, size_t length, void* data);
SK_C_API void sk_typeface_get_bounds(const sk_typeface_t* self, /*out*/ sk_rect_t* bounds);
SK_C_API void sk_typeface_unref(const sk_typeface_t* self);
SK_C_API sk_typeface_t* sk_typeface_make_default(void);
SK_C_API sk_typeface_t* sk_typeface_make_from_file(const char file_name[], int32_t ttc_index);
SK_C_API sk_typeface_t* sk_typeface_make_from_stream(sk_stream_t* stream, int32_t ttc_index);
SK_C_API sk_typeface_t* sk_typeface_make_from_name(const char family_name[], const sk_fontstyle_t* style);
SK_C_API sk_typeface_t* sk_typeface_make_from_data(sk_data_t* data, int32_t ttc_index);

SK_C_PLUS_PLUS_END_GUARD
#endif
