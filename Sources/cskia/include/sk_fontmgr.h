#ifndef sk_fontmgr_DEFINED
#define sk_fontmgr_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API sk_fontmgr_t* sk_fontmgr_create_default(void);
SK_C_API void sk_fontmgr_unref(sk_fontmgr_t* self);
SK_C_API int32_t sk_fontmgr_count_families(const sk_fontmgr_t* self);
SK_C_API sk_string_t* sk_fontmgr_get_family_name(const sk_fontmgr_t* self, int32_t index);
SK_C_API sk_fontstyleset_t* sk_fontmgr_create_styleset(const sk_fontmgr_t* self, int32_t index);
SK_C_API sk_fontstyleset_t* sk_fontmgr_match_family(const sk_fontmgr_t* self, const char family_name[]);
SK_C_API sk_typeface_t* sk_fontmgr_match_family_style(const sk_fontmgr_t* self, const char family_name[], const sk_fontstyle_t* style);
SK_C_API sk_typeface_t* sk_fontmgr_match_family_style_character(const sk_fontmgr_t* self, const char family_name[], const sk_fontstyle_t* style, const char* bcp47[], int32_t bcp47_count, sk_unichar_t character);
SK_C_API sk_typeface_t* sk_fontmgr_make_from_data(sk_fontmgr_t* self, sk_data_t* data, int32_t ttc_index);
SK_C_API sk_typeface_t* sk_fontmgr_make_from_file(sk_fontmgr_t* self, const char file_name[], int32_t ttc_index);

SK_C_PLUS_PLUS_END_GUARD
#endif
