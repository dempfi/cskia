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
  sk_colorspace_t *colorspace;
  int32_t width;
  int32_t height;
  sk_colortype_t colorType;
  sk_alphatype_t alphaType;
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

typedef struct sk_pixmap_t sk_pixmap_t;

typedef struct sk_imagefilter_t sk_imagefilter_t;

typedef struct sk_image_t sk_image_t;

typedef enum
{
  SRC_RECT_CONSTRAINT_STRICT, // Sample only inside bounds; slower
  SRC_RECT_CONSTRAINT_FAST,   // Sample outside bounds; faster
} sk_src_rect_constraint_t;

typedef struct
{
  float B;
  float C;
} sk_cubic_resampler_t;

typedef enum
{
  SK_FILTER_MODE_NEAREST,
  SK_FILTER_MODE_LINEAR,
  SK_FILTER_MODE_LAST = SK_FILTER_MODE_LINEAR,
} sk_filter_mode_t;

typedef enum
{
  SK_MIPMAP_MODE_NONE,
  SK_MIPMAP_MODE_NEAREST,
  SK_MIPMAP_MODE_LINEAR,
  SK_MIPMAP_MODE_LAST = SK_MIPMAP_MODE_LINEAR,
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
  SK_TEXT_ENCODING_UTF8,     // uses bytes to represent UTF-8 or ASCII
  SK_TEXT_ENCODING_UTF16,    // uses two byte words to represent most of Unicode
  SK_TEXT_ENCODING_UTF32,    // uses four byte words to represent all of Unicode
  SK_TEXT_ENCODING_GLYPH_ID, // uses two byte words to represent glyph indices
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
typedef struct sk_fontstyle_t sk_fontstyle_t;
typedef struct sk_fontstyleset_t sk_fontstyleset_t;

////////////////////////////////////////////////
//////////////////// GPU ///////////////////////
typedef struct gr_direct_context_t gr_direct_context_t;

typedef struct gr_backendrendertarget_t gr_backendrendertarget_t;

typedef struct
{
  const void *fTexture;
} gr_mtl_textureinfo_t;

SK_C_PLUS_PLUS_END_GUARD
#endif
