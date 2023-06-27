#ifndef sk_types_DEFINED
#define sk_types_DEFINED

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
#define SK_C_PLUS_PLUS_BEGIN_GUARD \
  extern "C"                       \
  {
#define SK_C_PLUS_PLUS_END_GUARD }
#else
#include <stdbool.h>
#define SK_C_PLUS_PLUS_BEGIN_GUARD
#define SK_C_PLUS_PLUS_END_GUARD
#endif

#if !defined(SK_C_API)
#if defined(SKIA_C_DLL)
#if defined(_MSC_VER)
#if SKIA_IMPLEMENTATION
#define SK_C_API __declspec(dllexport)
#else
#define SK_C_API __declspec(dllimport)
#endif
#else
#define SK_C_API __attribute__((visibility("default")))
#endif
#else
#define SK_C_API
#endif
#endif

#if defined(_WIN32)
// On Windows, Vulkan commands use the stdcall convention
#define VKAPI_ATTR
#define VKAPI_CALL __stdcall
#define VKAPI_PTR VKAPI_CALL
#elif defined(__ANDROID__) && defined(__ARM_ARCH) && __ARM_ARCH < 7
#error "Vulkan isn't supported for the 'armeabi' NDK ABI"
#elif defined(__ANDROID__) && defined(__ARM_ARCH) && __ARM_ARCH >= 7 && defined(__ARM_32BIT_STATE)
// On Android 32-bit ARM targets, Vulkan functions use the "hardfloat"
// calling convention, i.e. float parameters are passed in registers. This
// is true even if the rest of the application passes floats on the stack,
// as it does by default when compiling for the armeabi-v7a NDK ABI.
#define VKAPI_ATTR __attribute__((pcs("aapcs-vfp")))
#define VKAPI_CALL
#define VKAPI_PTR VKAPI_ATTR
#else
// On other platforms, use the default calling convention
#define VKAPI_ATTR
#define VKAPI_CALL
#define VKAPI_PTR
#endif

SK_C_PLUS_PLUS_BEGIN_GUARD

// Primitives
typedef struct sk_string_t sk_string_t;
typedef uint32_t sk_color_t;

typedef struct
{
  float x;
  float y;
} sk_point_t;

typedef struct
{
  int32_t x;
  int32_t y;
} sk_ipoint_t;

typedef struct
{
  float x;
  float y;
  float z;
} sk_point3_t;

typedef sk_point_t sk_vector_t;

typedef struct
{
  int32_t left;
  int32_t top;
  int32_t right;
  int32_t bottom;
} sk_irect_t;

typedef struct
{
  float left;
  float top;
  float right;
  float bottom;
} sk_rect_t;

typedef struct
{
  float scaleX, skewX, transX;
  float skewY, scaleY, transY;
  float persp0, persp1, persp2;
} sk_matrix_t;

typedef enum
{
  FILL_SK_PAINT_STYLE,
  STROKE_SK_PAINT_STYLE,
  STROKE_AND_FILL_SK_PAINT_STYLE,
} sk_paint_style_t;

typedef enum
{
  BUTT_SK_STROKE_CAP,
  ROUND_SK_STROKE_CAP,
  SQUARE_SK_STROKE_CAP
} sk_stroke_cap_t;

typedef enum
{
  MITER_SK_STROKE_JOIN,
  ROUND_SK_STROKE_JOIN,
  BEVEL_SK_STROKE_JOIN
} sk_stroke_join_t;

typedef enum
{
  TRANSLATE_SK_PATH_EFFECT_1D_STYLE,
  ROTATE_SK_PATH_EFFECT_1D_STYLE,
  MORPH_SK_PATH_EFFECT_1D_STYLE,
} sk_path_effect_1d_style_t;

typedef enum
{
  NORMAL_SK_PATH_EFFECT_TRIM_MODE,
  INVERTED_SK_PATH_EFFECT_TRIM_MODE,
} sk_path_effect_trim_mode_t;

typedef struct sk_path_effect_t sk_path_effect_t;

typedef enum
{
  SMALL_SK_PATH_ARC_SIZE,
  LARGE_SK_PATH_ARC_SIZE,
} sk_path_arc_size_t;

typedef enum
{
  CW_SK_PATH_DIRECTION,
  CCW_SK_PATH_DIRECTION,
} sk_path_direction_t;

typedef enum
{
  WINDING_SK_PATH_FILLTYPE,
  EVENODD_SK_PATH_FILLTYPE,
  INVERSE_WINDING_SK_PATH_FILLTYPE,
  INVERSE_EVENODD_SK_PATH_FILLTYPE,
} sk_path_filltype_t;

typedef enum
{
  APPEND_SK_PATH_ADD_MODE,
  EXTEND_SK_PATH_ADD_MODE,
} sk_path_add_mode_t;

typedef enum
{
  DIFFERENCE_SK_PATHOP,
  INTERSECT_SK_PATHOP,
  UNION_SK_PATHOP,
  XOR_SK_PATHOP,
  REVERSE_DIFFERENCE_SK_PATHOP,
} sk_pathop_t;

typedef struct sk_opbuilder_t sk_opbuilder_t;
typedef struct sk_pathmeasure_t sk_pathmeasure_t;

typedef enum
{
  GET_POSITION_SK_PATHMEASURE_MATRIXFLAGS = 0x01,
  GET_TANGENT_SK_PATHMEASURE_MATRIXFLAGS = 0x02,
  GET_POS_AND_TAN_SK_PATHMEASURE_MATRIXFLAGS = GET_POSITION_SK_PATHMEASURE_MATRIXFLAGS | GET_TANGENT_SK_PATHMEASURE_MATRIXFLAGS,
} sk_pathmeasure_matrixflags_t;

typedef enum
{
  EMPTY_SK_RRECT_TYPE,
  RECT_SK_RRECT_TYPE,
  OVAL_SK_RRECT_TYPE,
  SIMPLE_SK_RRECT_TYPE,
  NINE_PATCH_SK_RRECT_TYPE,
  COMPLEX_SK_RRECT_TYPE,
} sk_rrect_type_t;

typedef enum
{
  UPPER_LEFT_SK_RRECT_CORNER,
  UPPER_RIGHT_SK_RRECT_CORNER,
  LOWER_RIGHT_SK_RRECT_CORNER,
  LOWER_LEFT_SK_RRECT_CORNER,
} sk_rrect_corner_t;

// Rounded rectangle
typedef struct sk_rrect_t sk_rrect_t;

// Canvas
typedef struct sk_canvas_t sk_canvas_t;

// Paint
typedef enum
{
  NO_SHADOW_FLAG = 0x00,
  /** The occluding object is not opaque. Knowing that the occluder is opaque allows
   * us to cull shadow geometry behind it and improve performance. */
  TRANSPARENT_OCCLUDER_SHADOW_FLAG = 0x01,
  /** Don't try to use analytic shadows. */
  GEOMETRIC_ONLY_SHADOW_FLAG = 0x02,
  /** Light position represents a direction, light radius is blur radius at elevation 1 */
  DIRECTIONAL_LIGHT_SHADOW_FLAG = 0x04,
  /** Concave paths will only use blur to generate the shadow */
  CONCAVE_BLUR_ONLY_SHADOW_FLAG = 0x08,
  /** mask for all shadow flags */
  ALL_SHADOW_FLAG = 0x0F
} sk_shadow_flags_t;

typedef struct sk_paint_t sk_paint_t;

// Path
typedef struct sk_path_t sk_path_t;

// Surface
typedef struct sk_surface_t sk_surface_t;

typedef enum
{
  TOP_LEFT_GR_SURFACE_ORIGIN,
  BOTTOM_LEFT_GR_SURFACE_ORIGIN,
} gr_surfaceorigin_t;

typedef enum
{
  UNKNOWN_SK_COLORTYPE = 0,
  ALPHA_8_SK_COLORTYPE,
  RGB_565_SK_COLORTYPE,
  ARGB_4444_SK_COLORTYPE,
  RGBA_8888_SK_COLORTYPE,
  RGB_888X_SK_COLORTYPE,
  BGRA_8888_SK_COLORTYPE,
  RGBA_1010102_SK_COLORTYPE,
  RGB_101010X_SK_COLORTYPE,
  GRAY_8_SK_COLORTYPE,
  RGBA_F16_NORM_SK_COLORTYPE,
  RGBA_F16_SK_COLORTYPE,
  RGBA_F32_SK_COLORTYPE,

  // READONLY
  R8G8_UNORM_SK_COLORTYPE,
  A16_FLOAT_SK_COLORTYPE,
  R16G16_FLOAT_SK_COLORTYPE,
  A16_UNORM_SK_COLORTYPE,
  R16G16_UNORM_SK_COLORTYPE,
  R16G16B16A16_UNORM_SK_COLORTYPE,
} sk_colortype_t;

typedef struct sk_colorspace_t sk_colorspace_t;

typedef struct sk_surfaceprops_t sk_surfaceprops_t;

// Raster
typedef struct sk_bitmap_t sk_bitmap_t;

typedef enum
{
  UNKNOWN_SK_ALPHATYPE,
  OPAQUE_SK_ALPHATYPE,
  PREMUL_SK_ALPHATYPE,
  UNPREMUL_SK_ALPHATYPE,
} sk_alphatype_t;

typedef struct
{
  int32_t width;
  int32_t height;
  sk_colortype_t color_type;
  sk_alphatype_t alpha_type;
  sk_colorspace_t *color_space;
} sk_imageinfo_t;

typedef enum
{
  ALLOW_SK_IMAGE_CACHING_HINT,
  DISALLOW_SK_IMAGE_CACHING_HINT,
} sk_image_caching_hint_t;

typedef enum
{
  NONE_SK_FILTER_QUALITY,
  LOW_SK_FILTER_QUALITY,
  MEDIUM_SK_FILTER_QUALITY,
  HIGH_SK_FILTER_QUALITY
} sk_filter_quality_t;

typedef enum
{
  BMP_SK_ENCODED_FORMAT,
  GIF_SK_ENCODED_FORMAT,
  ICO_SK_ENCODED_FORMAT,
  JPEG_SK_ENCODED_FORMAT,
  PNG_SK_ENCODED_FORMAT,
  WBMP_SK_ENCODED_FORMAT,
  WEBP_SK_ENCODED_FORMAT,
  PKM_SK_ENCODED_FORMAT,
  KTX_SK_ENCODED_FORMAT,
  ASTC_SK_ENCODED_FORMAT,
  DNG_SK_ENCODED_FORMAT,
  HEIF_SK_ENCODED_FORMAT,
} sk_encoded_image_format_t;

typedef struct sk_pixmap_t sk_pixmap_t;

typedef struct sk_imagefilter_t sk_imagefilter_t;

typedef struct sk_image_t sk_image_t;

typedef enum
{
  STRICT_SRC_RECT_CONSTRAINT, // Sample only inside bounds; slower
  FAST_SRC_RECT_CONSTRAINT,   // Sample outside bounds; faster
} sk_src_rect_constraint_t;

typedef struct
{
  float B;
  float C;
} sk_cubic_resampler_t;

typedef enum
{
  NEAREST_SK_FILTER_MODE,
  LINEAR_SK_FILTER_MODE,
  LAST_SK_FILTER_MODE = LINEAR_SK_FILTER_MODE,
} sk_filter_mode_t;

typedef enum
{
  NONE_SK_MIPMAP_MODE,
  NEAREST_SK_MIPMAP_MODE,
  LINEAR_SK_MIPMAP_MODE,
  LAST_SK_MIPMAP_MODE = LINEAR_SK_MIPMAP_MODE,
} sk_mipmap_mode_t;

typedef struct
{
  int maxAniso;
  bool useCubic;
  sk_cubic_resampler_t cubic;
  sk_filter_mode_t filter;
  sk_mipmap_mode_t mipmap;
} sk_sampling_options_t;

// Text
typedef enum
{
  UTF8_SK_TEXT_ENCODING,     // uses bytes to represent UTF-8 or ASCII
  UTF16_SK_TEXT_ENCODING,    // uses two byte words to represent most of Unicode
  UTF32_SK_TEXT_ENCODING,    // uses four byte words to represent all of Unicode
  GLYPH_ID_SK_TEXT_ENCODING, // uses two byte words to represent glyph indices
} sk_text_encoding_t;

typedef struct sk_textblob_t sk_textblob_t;
typedef struct sk_textblob_builder_t sk_textblob_builder_t;

typedef struct
{
  void *glyphs;
  void *pos;
  void *utf8text;
  void *clusters;
} sk_textblob_builder_runbuffer_t;

// Font

typedef struct
{
  uint32_t fFlags;
  float fTop;
  float fAscent;
  float fDescent;
  float fBottom;
  float fLeading;
  float fAvgCharWidth;
  float fMaxCharWidth;
  float fXMin;
  float fXMax;
  float fXHeight;
  float fCapHeight;
  float fUnderlineThickness;
  float fUnderlinePosition;
  float fStrikeoutThickness;
  float fStrikeoutPosition;
} sk_fontmetrics_t;

typedef enum
{
  NONE_SK_FONT_HINTING,
  SLIGHT_SK_FONT_HINTING,
  NORMAL_SK_FONT_HINTING,
  FULL_SK_FONT_HINTING,
} sk_font_hinting_t;

typedef enum
{
  ALIAS_SK_FONT_EDGING,
  ANTIALIAS_SK_FONT_EDGING,
  SUBPIXEL_ANTIALIAS_SK_FONT_EDGING,
} sk_font_edging_t;

typedef enum
{
  UPRIGHT_SK_FONT_STYLE_SLANT = 0,
  ITALIC_SK_FONT_STYLE_SLANT = 1,
  OBLIQUE_SK_FONT_STYLE_SLANT = 2,
} sk_font_style_slant_t;

typedef struct sk_font_t sk_font_t;

/**
   A sk_typeface_t pecifies the typeface and intrinsic style of a font.
    This is used in the paint, along with optionally algorithmic settings like
    textSize, textSkewX, textScaleX, kFakeBoldText_Mask, to specify
    how text appears when drawn (and measured).

    Typeface objects are immutable, and so they can be shared between threads.
*/
typedef struct sk_typeface_t sk_typeface_t;
typedef uint32_t sk_font_table_tag_t;
typedef struct sk_fontmgr_t sk_fontmgr_t;
typedef struct sk_fontstyleset_t sk_fontstyleset_t;

typedef enum
{
  UPRIGHT_SK_FONTSLANT,
  ITALIC_SK_FONTSLANT,
  OBLIQUE_SK_FONTSLANT,
} sk_fontslant_t;

typedef struct
{
  int32_t weight;
  int32_t width;
  sk_fontslant_t slant;
} sk_fontstyle_t;

/**
    A sk_data_ holds an immutable data buffer.
*/
typedef struct sk_data_t sk_data_t;

////////////////////////////////////////////////
//////////////////// GPU ///////////////////////
typedef struct
{
  const void *fDevice;
  const void *fQueue;
  const void *fBinaryArchive;
} gr_mtl_backend_context_t;

typedef struct gr_direct_context_t gr_direct_context_t;

typedef struct gr_backendrendertarget_t gr_backendrendertarget_t;

typedef struct
{
  const void *fTexture;
} gr_mtl_textureinfo_t;

////////////////////////////////////////////////
///////////////// PARAGRAPH ////////////////////
typedef struct sk_paragraph_t sk_paragraph_t;
typedef struct sk_paragraphbuilder_t sk_paragraphbuilder_t;
typedef struct sk_paragraphstyle_t sk_paragraphstyle_t;
typedef struct sk_textstyle_t sk_textstyle_t;
typedef struct sk_strutstyle_t sk_strutstyle_t;

typedef enum
{
  UPSTREAM_SK_AFFINITY,
  DOWNSTREAM_SK_AFFINITY,
} sk_affinity_t;

typedef struct
{
  int32_t position;
  sk_affinity_t affinity;
} sk_positionaffinity_t;

typedef struct
{
  size_t start_index;
  size_t end_index;
  size_t end_excluding_whitespaces;
  size_t end_including_newline;
  bool is_hard_break;
  double ascent;
  double descent;
  double height;
  double width;
  double left;
  double baseline;
  size_t line_number;
} sk_metrics_t;

typedef enum
{
  RIGHT_TO_LEFT_SK_TEXTDIRECTION,
  LEFT_TO_RIGHT_SK_TEXTDIRECTION,
} sk_textdirection_t;

typedef struct
{
  sk_rect_t rect;
  sk_textdirection_t direction;
} sk_textbox_t;

typedef enum
{
  TIGHT_SK_RECTHEIGHTSTYLE,
  MAX_SK_RECTHEIGHTSTYLE,
  INCLUDE_LINE_SPACING_MIDDLE_SK_RECTHEIGHTSTYLE,
  INCLUDE_LINE_SPACING_TOP_SK_RECTHEIGHTSTYLE,
  INCLUDE_LINE_SPACING_BOTTOM_SK_RECTHEIGHTSTYLE,
  STRUT_SK_RECTHEIGHTSTYLE,
} sk_rectheightstyle_t;

typedef enum
{
  TIGHT_SK_RECTWIDTHSTYLE,
  MAX_SK_RECTWIDTHSTYLE,
} sk_rectwidthstyle_t;

typedef enum
{
  BASELINE_SK_PLACEHOLDERALIGNMENT,
  ABOVE_BASELINE_SK_PLACEHOLDERALIGNMENT,
  BELOW_BASELINE_SK_PLACEHOLDERALIGNMENT,
  TOP_SK_PLACEHOLDERALIGNMENT,
  BOTTOM_SK_PLACEHOLDERALIGNMENT,
  MIDDLE_SK_PLACEHOLDERALIGNMENT,
} sk_placeholderalignment_t;

typedef enum
{
  ALPHABETIC_SK_TEXTBASELINE,
  IDEOGRAPHIC_SK_TEXTBASELINE,
} sk_textbaseline_t;

typedef struct
{
  float width;
  float height;
  sk_placeholderalignment_t alignment;
  sk_textbaseline_t baseline;
  float baseline_offset;
} sk_placeholderstyle_t;

typedef enum
{
  LEFT_SK_TEXTALIGN,
  RIGHT_SK_TEXTALIGN,
  CENTER_SK_TEXTALIGN,
  JUSTIFY_SK_TEXTALIGN,
  START_SK_TEXTALIGN,
  TERMINATE_SK_TEXTALIGN,
} sk_textalign_t;

typedef struct
{
  sk_color_t color;
  sk_point_t offset;
  double blur_radius;
} sk_textshadow_t;

typedef enum
{
  SOLID_SK_TEXTDECORATIONSTYLE,
  DOUBLE_SK_TEXTDECORATIONSTYLE,
  DOTTED_SK_TEXTDECORATIONSTYLE,
  DASHED_SK_TEXTDECORATIONSTYLE,
  WAVY_SK_TEXTDECORATIONSTYLE,
} sk_textdecorationstyle_t;

SK_C_PLUS_PLUS_END_GUARD
#endif
