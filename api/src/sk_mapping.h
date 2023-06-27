#include "include/sk_types.h"
#include "include/codec/SkCodec.h"
#include "include/core/SkAlphaType.h"
#include "include/core/SkBlender.h"
#include "include/core/SkBlendMode.h"
#include "include/core/SkBlurTypes.h"
#include "include/core/SkCanvas.h"
#include "include/core/SkClipOp.h"
#include "include/core/SkColor.h"
#include "include/core/SkColorFilter.h"
#include "include/core/SkColorSpace.h"
#include "include/core/SkColorType.h"
#include "include/core/SkData.h"
#include "include/core/SkDocument.h"
#include "include/core/SkEncodedImageFormat.h"
#include "include/core/SkFlattenable.h"
#include "include/core/SkFont.h"
#include "include/core/SkFontMetrics.h"
#include "include/core/SkFontMgr.h"
#include "include/core/SkFontStyle.h"
#include "include/core/SkFontTypes.h"
#include "include/core/SkGraphics.h"
#include "include/core/SkImage.h"
#include "include/core/SkImageFilter.h"
#include "include/core/SkImageInfo.h"
#include "include/core/SkM44.h"
#include "include/core/SkMaskFilter.h"
#include "include/core/SkMatrix.h"
#include "include/core/SkPaint.h"
#include "include/core/SkPath.h"
#include "include/core/SkPathBuilder.h"
#include "include/core/SkPathEffect.h"
#include "include/core/SkPathMeasure.h"
#include "include/core/SkPathTypes.h"
#include "include/core/SkPicture.h"
#include "include/core/SkPictureRecorder.h"
#include "include/core/SkPixmap.h"
#include "include/core/SkPoint3.h"
#include "include/core/SkRefCnt.h"
#include "include/core/SkRegion.h"
#include "include/core/SkRRect.h"
#include "include/core/SkRSXform.h"
#include "include/core/SkSamplingOptions.h"
#include "include/core/SkScalar.h"
#include "include/core/SkShader.h"
#include "include/core/SkSize.h"
#include "include/core/SkStream.h"
#include "include/core/SkString.h"
#include "include/core/SkSurface.h"
#include "include/core/SkSurfaceProps.h"
#include "include/core/SkTextBlob.h"
#include "include/core/SkTileMode.h"
#include "include/core/SkTime.h"
#include "include/core/SkTraceMemoryDump.h"
#include "include/core/SkTypeface.h"
#include "include/core/SkTypes.h"
#include "include/core/SkVertices.h"
#include "include/docs/SkPDFDocument.h"
#include "include/effects/Sk1DPathEffect.h"
#include "include/effects/Sk2DPathEffect.h"
#include "include/effects/SkBlenders.h"
#include "include/effects/SkColorMatrix.h"
#include "include/effects/SkColorMatrixFilter.h"
#include "include/effects/SkCornerPathEffect.h"
#include "include/effects/SkDashPathEffect.h"
#include "include/effects/SkDiscretePathEffect.h"
#include "include/effects/SkGradientShader.h"
#include "include/effects/SkHighContrastFilter.h"
#include "include/effects/SkImageFilters.h"
#include "include/effects/SkLumaColorFilter.h"
#include "include/effects/SkOpPathEffect.h"
#include "include/effects/SkOverdrawColorFilter.h"
#include "include/effects/SkPerlinNoiseShader.h"
#include "include/effects/SkRuntimeEffect.h"
#include "include/effects/SkShaderMaskFilter.h"
#include "include/effects/SkStrokeAndFillPathEffect.h"
#include "include/effects/SkTableColorFilter.h"
#include "include/effects/SkTableMaskFilter.h"
#include "include/effects/SkTrimPathEffect.h"
#include "include/encode/SkEncoder.h"
#include "include/encode/SkWebpEncoder.h"
#include "include/pathops/SkPathOps.h"
#include "include/svg/SkSVGCanvas.h"
#include "include/utils/SkAnimCodecPlayer.h"
#include "include/utils/SkParsePath.h"
#include "modules/skcms/skcms.h"

// Auxiliary macro for mapping

#define SK_DEF_MAP(type, type_t, name, cast)                      \
  static inline type As##name(type_t t) { return cast<type>(t); } \
  static inline type_t To##name(type t) { return cast<type_t>(t); }

// Generic mapping
//
// Parameters:
//   - C++ |  type
//   - C   |  type_t
//   - Map |  name

#define SK_DEF_TYPE_MAP(type, type_t, name) \
  SK_DEF_MAP(type, type_t, name, reinterpret_cast)

// Class mapping
//
// Parameters:
//   - C++ Class |  type
//   - C   Class |  type_t
//   - Map       |  name

#define SK_DEF_CLASS_MAP(type, type_t, name)          \
  SK_DEF_TYPE_MAP(type *, type_t *, name)             \
  SK_DEF_TYPE_MAP(type &, type_t &, name)             \
  SK_DEF_TYPE_MAP(const type *, const type_t *, name) \
  SK_DEF_TYPE_MAP(const type &, const type_t &, name)

// Enum mapping
//
// Parameters:
//   - C++ Enum |  type
//   - C   Enum |  type_t
//   - Map      |  name

#define SK_DEF_ENUM_MAP(type, type_t, name) \
  SK_DEF_MAP(type, type_t, name, static_cast)

SK_DEF_CLASS_MAP(SkCanvas, sk_canvas_t, Canvas)
SK_DEF_CLASS_MAP(SkColorSpace, sk_colorspace_t, ColorSpace)
SK_DEF_CLASS_MAP(SkData, sk_data_t, Data)
SK_DEF_CLASS_MAP(SkFont, sk_font_t, Font)
SK_DEF_CLASS_MAP(SkFontMetrics, sk_fontmetrics_t, FontMetrics)
SK_DEF_CLASS_MAP(SkFontMgr, sk_fontmgr_t, FontMgr)
SK_DEF_CLASS_MAP(SkImage, sk_image_t, Image)
SK_DEF_CLASS_MAP(SkImageFilter, sk_imagefilter_t, ImageFilter)
SK_DEF_CLASS_MAP(SkIPoint, sk_ipoint_t, IPoint)
SK_DEF_CLASS_MAP(SkIRect, sk_irect_t, IRect)
SK_DEF_CLASS_MAP(SkOpBuilder, sk_opbuilder_t, OpBuilder)
SK_DEF_CLASS_MAP(SkPaint, sk_paint_t, Paint)
SK_DEF_CLASS_MAP(SkPath, sk_path_t, Path)
SK_DEF_CLASS_MAP(SkPathMeasure, sk_pathmeasure_t, PathMeasure)
SK_DEF_CLASS_MAP(SkPixmap, sk_pixmap_t, Pixmap)
SK_DEF_CLASS_MAP(SkPoint, sk_point_t, Point)
SK_DEF_CLASS_MAP(SkPoint3, sk_point3_t, Point3)
SK_DEF_CLASS_MAP(SkRect, sk_rect_t, Rect)
SK_DEF_CLASS_MAP(SkRRect, sk_rrect_t, RRect)
SK_DEF_CLASS_MAP(SkString, sk_string_t, String)
SK_DEF_CLASS_MAP(SkSurface, sk_surface_t, Surface)
SK_DEF_CLASS_MAP(SkSurfaceProps, sk_surfaceprops_t, SurfaceProps)
SK_DEF_CLASS_MAP(SkTextBlob, sk_textblob_t, TextBlob)
SK_DEF_CLASS_MAP(SkTypeface, sk_typeface_t, Typeface)
SK_DEF_CLASS_MAP(SkVector, sk_vector_t, Vector)

SK_DEF_ENUM_MAP(SkAlphaType, sk_alphatype_t, AlphaType)
SK_DEF_ENUM_MAP(SkCanvas::SaveLayerFlagsSet, uint32_t, SaveLayerFlagsSet)
SK_DEF_ENUM_MAP(SkColorType, sk_colortype_t, ColorType)
SK_DEF_ENUM_MAP(SkFontStyle::Slant, sk_fontslant_t, FontSlant)
SK_DEF_ENUM_MAP(SkImageFilters::Dither, bool, ImageFiltersDither)
SK_DEF_ENUM_MAP(SkPathMeasure::MatrixFlags, uint32_t, PathMeasureMatrixFlags)
SK_DEF_ENUM_MAP(SkPathOp, sk_pathop_t, PathOp)

/*
 * CUSTOM MAPPING
 */

static inline SkFontStyle AsFontStyle(const sk_fontstyle_t *style)
{
  return SkFontStyle(style->weight, style->width, AsFontSlant(style->slant));
}
static inline sk_fontstyle_t ToFontStyle(const SkFontStyle &style)
{
  return {style.weight(), style.width(), ToFontSlant(style.slant())};
}

static inline SkImageInfo AsImageInfo(const sk_imageinfo_t *info)
{
  return SkImageInfo::Make(
      info->width,
      info->height,
      AsColorType(info->color_type),
      AsAlphaType(info->alpha_type),
      sk_ref_sp(AsColorSpace(info->color_space)));
}
static inline sk_imageinfo_t ToImageInfo(const SkImageInfo &info)
{
  return {
      info.width(),
      info.height(),
      ToColorType(info.colorType()),
      ToAlphaType(info.alphaType()),
      ToColorSpace(info.refColorSpace().release()),
  };
}

/* Converting from sk_matrix_t to SkMatrix:
 * [ a b c ]      [ a d g ]
 * [ d e f ]  ->  [ b e h ]
 * [ g h i ]      [ c f i ]
 */

static inline SkMatrix AsMatrix(const sk_matrix_t *matrix)
{
  return SkMatrix::MakeAll(
      matrix->scaleX, matrix->skewX, matrix->transX,
      matrix->skewY, matrix->scaleY, matrix->transY,
      matrix->persp0, matrix->persp1, matrix->persp2);
}

static inline sk_matrix_t ToMatrix(const SkMatrix *matrix)
{
  sk_matrix_t m;
  m.scaleX = matrix->get(SkMatrix::kMScaleX);
  m.skewX = matrix->get(SkMatrix::kMSkewX);
  m.transX = matrix->get(SkMatrix::kMTransX);
  m.skewY = matrix->get(SkMatrix::kMSkewY);
  m.scaleY = matrix->get(SkMatrix::kMScaleY);
  m.transY = matrix->get(SkMatrix::kMTransY);
  m.persp0 = matrix->get(SkMatrix::kMPersp0);
  m.persp1 = matrix->get(SkMatrix::kMPersp1);
  m.persp2 = matrix->get(SkMatrix::kMPersp2);
  return m;
}

/////////////////////////////////////////////
#include "modules/skparagraph/include/DartTypes.h"
#include "modules/skparagraph/include/Paragraph.h"
#include "modules/skparagraph/include/ParagraphBuilder.h"
#include "modules/skparagraph/include/ParagraphStyle.h"
#include "modules/skparagraph/include/TextShadow.h"
#include "modules/skparagraph/include/TextStyle.h"
#include "modules/skparagraph/include/TypefaceFontProvider.h"

SK_DEF_CLASS_MAP(skia::textlayout::Paragraph, sk_paragraph_t, Paragraph)
SK_DEF_CLASS_MAP(skia::textlayout::ParagraphBuilder, sk_paragraphbuilder_t, ParagraphBuilder)
SK_DEF_CLASS_MAP(skia::textlayout::ParagraphStyle, sk_paragraphstyle_t, ParagraphStyle)
SK_DEF_CLASS_MAP(skia::textlayout::PlaceholderStyle, sk_placeholderstyle_t, PlaceholderStyle)
SK_DEF_CLASS_MAP(skia::textlayout::PositionWithAffinity, sk_positionaffinity_t, PositionAffinity)
SK_DEF_CLASS_MAP(skia::textlayout::StrutStyle, sk_strutstyle_t, StrutStyle)
SK_DEF_CLASS_MAP(skia::textlayout::TextBox, sk_textbox_t, TextBox)
SK_DEF_CLASS_MAP(skia::textlayout::TextShadow, sk_textshadow_t, TextShadow)
SK_DEF_CLASS_MAP(skia::textlayout::TextStyle, sk_textstyle_t, TextStyle)

SK_DEF_ENUM_MAP(skia::textlayout::RectHeightStyle, sk_rectheightstyle_t, RectHeightStyle)
SK_DEF_ENUM_MAP(skia::textlayout::RectWidthStyle, sk_rectwidthstyle_t, RectWidthStyle)
SK_DEF_ENUM_MAP(skia::textlayout::TextAlign, sk_textalign_t, TextAlign)
SK_DEF_ENUM_MAP(skia::textlayout::TextBaseline, sk_textbaseline_t, TextBaseline)
SK_DEF_ENUM_MAP(skia::textlayout::TextDecoration, uint32_t, TextDecoration)
SK_DEF_ENUM_MAP(skia::textlayout::TextDecorationStyle, sk_textdecorationstyle_t, TextDecorationStyle)
SK_DEF_ENUM_MAP(skia::textlayout::TextDirection, sk_textdirection_t, TextDirection)
SK_DEF_ENUM_MAP(skia::textlayout::TextHeightBehavior, uint32_t, TextHeightBehavior)
