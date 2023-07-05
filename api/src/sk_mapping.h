#ifndef sk_mapping_DEFINED
#define sk_mapping_DEFINED

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

SK_DEF_CLASS_MAP(SkAnimCodecPlayer, sk_animcodecplayer_t, AnimCodecPlayer)
SK_DEF_CLASS_MAP(SkBlender, sk_blender_t, Blender)
SK_DEF_CLASS_MAP(SkCanvas, sk_canvas_t, Canvas)
SK_DEF_CLASS_MAP(SkCanvas::Lattice, sk_lattice_t, Lattice)
SK_DEF_CLASS_MAP(skcms_ICCProfile, sk_colorspaceiccprofile_t, ColorSpaceICCProfile)
SK_DEF_CLASS_MAP(skcms_Matrix3x3, sk_colorspacexyz_t, ColorSpaceXYZ)
SK_DEF_CLASS_MAP(skcms_TransferFunction, sk_colorspacetransferfn_t, ColorSpaceTransferFn)
SK_DEF_CLASS_MAP(SkCodec, sk_codec_t, Codec)
SK_DEF_CLASS_MAP(SkColor4f, sk_color4f_t, Color4f)
SK_DEF_CLASS_MAP(SkColorFilter, sk_colorfilter_t, ColorFilter)
SK_DEF_CLASS_MAP(SkColorMatrix, sk_colormatrix_t, ColorMatrix)
SK_DEF_CLASS_MAP(SkColorSpace, sk_colorspace_t, ColorSpace)
SK_DEF_CLASS_MAP(SkColorSpacePrimaries, sk_colorspaceprimaries_t, ColorSpacePrimaries)
SK_DEF_CLASS_MAP(SkCubicResampler, sk_cubicresampler_t, CubicResampler)
SK_DEF_CLASS_MAP(SkData, sk_data_t, Data)
SK_DEF_CLASS_MAP(SkDocument, sk_document_t, Document)
SK_DEF_CLASS_MAP(SkFlattenable, sk_flattenable_t, Flattenable)
SK_DEF_CLASS_MAP(SkFont, sk_font_t, Font)
SK_DEF_CLASS_MAP(SkFontMetrics, sk_fontmetrics_t, FontMetrics)
SK_DEF_CLASS_MAP(SkFontMgr, sk_fontmgr_t, FontMgr)
SK_DEF_CLASS_MAP(SkHighContrastConfig, sk_highcontrastconfig_t, HighContrastConfig)
SK_DEF_CLASS_MAP(SkImage, sk_image_t, Image)
SK_DEF_CLASS_MAP(SkImageFilter, sk_imagefilter_t, ImageFilter)
SK_DEF_CLASS_MAP(SkIPoint, sk_ipoint_t, IPoint)
SK_DEF_CLASS_MAP(SkIRect, sk_irect_t, IRect)
SK_DEF_CLASS_MAP(SkISize, sk_isize_t, ISize)
SK_DEF_CLASS_MAP(SkMaskFilter, sk_maskfilter_t, MaskFilter)
SK_DEF_CLASS_MAP(SkOpBuilder, sk_opbuilder_t, OpBuilder)
SK_DEF_CLASS_MAP(SkPaint, sk_paint_t, Paint)
SK_DEF_CLASS_MAP(SkPath, sk_path_t, Path)
SK_DEF_CLASS_MAP(SkPath::Iter, sk_pathiterator_t, PathIterator)
SK_DEF_CLASS_MAP(SkPath::RawIter, sk_pathrawiter_t, PathRawIter)
SK_DEF_CLASS_MAP(SkPathBuilder, sk_pathbuilder_t, PathBuilder)
SK_DEF_CLASS_MAP(SkPathEffect, sk_patheffect_t, PathEffect)
SK_DEF_CLASS_MAP(SkPathMeasure, sk_pathmeasure_t, PathMeasure)
SK_DEF_CLASS_MAP(SkPicture, sk_picture_t, Picture)
SK_DEF_CLASS_MAP(SkPictureRecorder, sk_picturerecorder_t, PictureRecorder)
SK_DEF_CLASS_MAP(SkPixmap, sk_pixmap_t, Pixmap)
SK_DEF_CLASS_MAP(SkPoint, sk_point_t, Point)
SK_DEF_CLASS_MAP(SkPoint3, sk_point3_t, Point3)
SK_DEF_CLASS_MAP(SkRect, sk_rect_t, Rect)
SK_DEF_CLASS_MAP(SkRefCnt, sk_refcnt_t, RefCnt)
SK_DEF_CLASS_MAP(SkRegion, sk_region_t, Region)
SK_DEF_CLASS_MAP(SkRegion::Cliperator, sk_regioncliperator_t, RegionCliperator)
SK_DEF_CLASS_MAP(SkRegion::Iterator, sk_regioniterator_t, RegionIterator)
SK_DEF_CLASS_MAP(SkRegion::Spanerator, sk_regionspanerator_t, RegionSpanerator)
SK_DEF_CLASS_MAP(SkRRect, sk_rrect_t, RRect);
SK_DEF_CLASS_MAP(SkRSXform, sk_rotationscalematrix_t, RotationScaleMatrix)
SK_DEF_CLASS_MAP(SkSamplingOptions, sk_samplingoptions_t, SamplingOptions)
SK_DEF_CLASS_MAP(SkShader, sk_shader_t, Shader)
SK_DEF_CLASS_MAP(SkSize, sk_size_t, Size)
SK_DEF_CLASS_MAP(SkStream, sk_stream_t, Stream)
SK_DEF_CLASS_MAP(SkString, sk_string_t, String)
SK_DEF_CLASS_MAP(SkSurface, sk_surface_t, Surface)
SK_DEF_CLASS_MAP(SkSurfaceProps, sk_surfaceprops_t, SurfaceProps)
SK_DEF_CLASS_MAP(SkTextBlob, sk_textblob_t, TextBlob)
SK_DEF_CLASS_MAP(SkTime::DateTime, sk_datetime_t, DateTime)
SK_DEF_CLASS_MAP(SkTraceMemoryDump, sk_tracememorydump_t, TraceMemoryDump)
SK_DEF_CLASS_MAP(SkTypeface, sk_typeface_t, Typeface)
SK_DEF_CLASS_MAP(SkVector, sk_vector_t, Vector)
SK_DEF_CLASS_MAP(SkVertices, sk_vertices_t, Vertices)
SK_DEF_CLASS_MAP(SkWStream, sk_wstream_t, WStream)

SK_DEF_ENUM_MAP(SkAlphaType, sk_alphatype_t, AlphaType)
SK_DEF_ENUM_MAP(SkBlendMode, sk_blendmode_t, BlendMode)
SK_DEF_ENUM_MAP(SkBlurStyle, sk_blurstyle_t, BlurStyle)
SK_DEF_ENUM_MAP(SkCanvas::PointMode, sk_drawpointsmode_t, DrawPointsMode)
SK_DEF_ENUM_MAP(SkCanvas::SaveLayerFlagsSet, uint32_t, SaveLayerFlagsSet)
SK_DEF_ENUM_MAP(SkCanvas::SrcRectConstraint, sk_srcrectconstraint_t, SrcRectConstraint)
SK_DEF_ENUM_MAP(SkClipOp, sk_clipop_t, ClipOp)
SK_DEF_ENUM_MAP(SkColorChannel, sk_colorchannel_t, ColorChannel)
SK_DEF_ENUM_MAP(SkColorType, sk_colortype_t, ColorType)
SK_DEF_ENUM_MAP(SkEncodedImageFormat, sk_encodedimageformat_t, EncodedImageFormat)
SK_DEF_ENUM_MAP(SkFilterMode, sk_filtermode_t, FilterMode)
SK_DEF_ENUM_MAP(SkFont::Edging, sk_fontedging_t, FontEdging)
SK_DEF_ENUM_MAP(SkFontHinting, sk_fonthinting_t, FontHinting)
SK_DEF_ENUM_MAP(SkFontStyle::Slant, sk_fontslant_t, FontSlant)
SK_DEF_ENUM_MAP(SkImage::CachingHint, sk_imagecachinghint_t, ImageCachingHint)
SK_DEF_ENUM_MAP(SkImageFilters::Dither, bool, ImageFiltersDither)
SK_DEF_ENUM_MAP(SkPaint::Cap, sk_strokecap_t, StrokeCap)
SK_DEF_ENUM_MAP(SkPaint::Join, sk_strokejoin_t, StrokeJoin)
SK_DEF_ENUM_MAP(SkPaint::Style, sk_paintstyle_t, PaintStyle)
SK_DEF_ENUM_MAP(SkPath::Verb, sk_pathverb_t, PathVerb)
SK_DEF_ENUM_MAP(SkPath1DPathEffect::Style, sk_patheffect1dstyle_t, PathEffect1DStyle)
SK_DEF_ENUM_MAP(SkPathBuilder::ArcSize, sk_patharcsize_t, PathArcSize)
SK_DEF_ENUM_MAP(SkPathDirection, sk_pathdirection_t, PathDirection)
SK_DEF_ENUM_MAP(SkPathFillType, sk_pathfilltype_t, PathFillType)
SK_DEF_ENUM_MAP(SkPathMeasure::MatrixFlags, uint32_t, PathMeasureMatrixFlags)
SK_DEF_ENUM_MAP(SkPathOp, sk_pathop_t, PathOp)
SK_DEF_ENUM_MAP(SkPixelGeometry, sk_pixelgeometry_t, PixelGeometry)
SK_DEF_ENUM_MAP(SkRegion::Op, sk_regionop_t, RegionOp)
SK_DEF_ENUM_MAP(SkRRect::Corner, sk_rrectcorner_t, RRectCorner)
SK_DEF_ENUM_MAP(SkTextEncoding, sk_textencoding_t, TextEncoding)
SK_DEF_ENUM_MAP(SkTileMode, sk_tilemode_t, TileMode)
SK_DEF_ENUM_MAP(SkTrimPathEffect::Mode, sk_patheffecttrimmode_t, PathEffectTrimMode)
SK_DEF_ENUM_MAP(SkVertices::VertexMode, sk_vertexmode_t, VertexMode)

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

static inline SkEncoder::Frame AsFrame(const sk_frame_t *frame)
{
  return {
      *AsPixmap(frame->pixmap),
      frame->duration,
  };
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

static inline sk_matrix_t ToMatrix(const SkMatrix &matrix)
{
  sk_matrix_t m;
  m.scaleX = matrix.get(SkMatrix::kMScaleX);
  m.skewX = matrix.get(SkMatrix::kMSkewX);
  m.transX = matrix.get(SkMatrix::kMTransX);
  m.skewY = matrix.get(SkMatrix::kMSkewY);
  m.scaleY = matrix.get(SkMatrix::kMScaleY);
  m.transY = matrix.get(SkMatrix::kMTransY);
  m.persp0 = matrix.get(SkMatrix::kMPersp0);
  m.persp1 = matrix.get(SkMatrix::kMPersp1);
  m.persp2 = matrix.get(SkMatrix::kMPersp2);
  return m;
}

/* Converting from sk_matrix44_t to SkM44:
 * [ a b c d ]      [ a e i m ]
 * [ e f g h ]  ->  [ b f j n ]
 * [ i j k l ]      [ c g k o ]
 * [ m n o p ]      [ d h l p ]
 */

static inline SkM44 AsMatrix44(const sk_matrix44_t *matrix)
{
  return SkM44(
      matrix->m_11, matrix->m_12, matrix->m_13, matrix->m_14,
      matrix->m_21, matrix->m_22, matrix->m_23, matrix->m_24,
      matrix->m_31, matrix->m_32, matrix->m_33, matrix->m_34,
      matrix->m_41, matrix->m_42, matrix->m_43, matrix->m_44);
}
static inline sk_matrix44_t ToMatrix44(const SkM44 &matrix)
{
  return {
      matrix.rc(0, 0),
      matrix.rc(0, 1),
      matrix.rc(0, 2),
      matrix.rc(0, 3),
      matrix.rc(1, 0),
      matrix.rc(1, 1),
      matrix.rc(1, 2),
      matrix.rc(1, 3),
      matrix.rc(2, 0),
      matrix.rc(2, 1),
      matrix.rc(2, 2),
      matrix.rc(2, 3),
      matrix.rc(3, 0),
      matrix.rc(3, 1),
      matrix.rc(3, 2),
      matrix.rc(3, 3),
  };
}

static inline SkPDF::Metadata AsPDFMetadata(const sk_pdfmetadata_t *metadata)
{
  SkPDF::Metadata result;
  result.fTitle = SkString(metadata->title);
  result.fAuthor = SkString(metadata->author);
  result.fSubject = SkString(metadata->subject);
  result.fKeywords = SkString(metadata->keywords);
  result.fCreator = SkString(metadata->creator);
  result.fProducer = SkString(metadata->producer);
  result.fCreation = AsDateTime(metadata->creation);
  result.fModified = AsDateTime(metadata->modified);
  result.fRasterDPI = metadata->raster_dpi;
  result.fPDFA = metadata->pdfa;
  result.fEncodingQuality = metadata->encoding_quality;
  return result;
}

/*
 * SPECIFIC
 */

#define SK_SKIP_ARG__(keep, skip, ...) skip
#define SK_SKIP_ARG_(args) SK_SKIP_ARG__ args
#define SK_SKIP_ARG(...) SK_SKIP_ARG_((__VA_ARGS__, ))

#define SK_FIRST_ARG__(keep, skip, ...) keep
#define SK_FIRST_ARG_(args) SK_FIRST_ARG__ args
#define SK_FIRST_ARG(...) SK_FIRST_ARG_((__VA_ARGS__, ))

// XPS

#ifdef SK_SUPPORT_XPS
#define SK_ONLY_XPS(...) SK_FIRST_ARG(__VA_ARGS__)

#include "include/docs/SkXPSDocument.h"
#else
#define SK_ONLY_XPS(...) SK_SKIP_ARG(__VA_ARGS__)
#endif

// Ganesh

#if defined(SK_GANESH)
#define SK_ONLY_GPU(...) SK_FIRST_ARG(__VA_ARGS__)

#include "include/gpu/GrBackendSemaphore.h"
#include "include/gpu/GrBackendSurface.h"
#include "include/gpu/GrBackendSurfaceMutableState.h"
#include "include/gpu/GrContextOptions.h"
#include "include/gpu/GrDirectContext.h"
#include "include/gpu/GrTypes.h"
#include "include/gpu/ShaderErrorHandler.h"
#include "include/gpu/ganesh/SkSurfaceGanesh.h"

SK_DEF_ENUM_MAP(GrBackendApi, gr_backendapi_t, GrBackendAPI)
SK_DEF_ENUM_MAP(GrContextOptions::ShaderCacheStrategy, gr_shadercachestrategy_t, GrShaderCacheStrategy)
SK_DEF_ENUM_MAP(GrMipmapped, bool, GrMipmapped)
SK_DEF_ENUM_MAP(GrProtected, bool, GrProtected)
SK_DEF_ENUM_MAP(GrRenderable, bool, GrRenderable)
SK_DEF_ENUM_MAP(skgpu::Budgeted, bool, Budgeted)
SK_DEF_ENUM_MAP(GrSurfaceOrigin, gr_surfaceorigin_t, GrSurfaceOrigin)

SK_DEF_CLASS_MAP(GrBackendRenderTarget, gr_backendrendertarget_t, GrBackendRenderTarget)
SK_DEF_CLASS_MAP(GrBackendSemaphore, gr_backendsemaphore_t, GrBackendSemaphore)
SK_DEF_CLASS_MAP(GrBackendSurfaceMutableState, gr_backendsurfacemutablestate_t, GrBackendSurfaceMutableState)
SK_DEF_CLASS_MAP(GrBackendTexture, gr_backendtexture_t, GrBackendTexture)
SK_DEF_CLASS_MAP(GrContextOptions::PersistentCache, gr_persistentcache_t, GrPersistentCache)
SK_DEF_CLASS_MAP(GrDirectContext, gr_directcontext_t, GrDirectContext)

SK_DEF_CLASS_MAP(skgpu::ShaderErrorHandler, gr_shadererrorhandler_t, GrShaderErrorHandler)

static inline GrContextOptions AsGrContextOptions(const gr_contextoptions_t *options)
{
  GrContextOptions result;
  result.fBufferMapThreshold = options->buffer_map_threshold;
  result.fDoManualMipmapping = options->do_manual_mipmapping;
  result.fAllowPathMaskCaching = options->allow_path_mask_caching;
  result.fGlyphCacheTextureMaximumBytes = options->glyph_cache_texture_maximum_bytes;
  result.fAvoidStencilBuffers = options->avoid_stencil_buffers;
  result.fRuntimeProgramCacheSize = options->runtime_program_cache_size;
  result.fPersistentCache = AsGrPersistentCache(options->persistent_cache);
  result.fShaderCacheStrategy = AsGrShaderCacheStrategy(options->shader_cache_strategy);
  result.fShaderErrorHandler = AsGrShaderErrorHandler(options->shader_error_handler);
  return result;
}

#ifdef SK_GL
#define SK_ONLY_GL(...) SK_FIRST_ARG(__VA_ARGS__)

#include "include/gpu/gl/GrGLAssembleInterface.h"
#include "include/gpu/gl/GrGLConfig.h"
#include "include/gpu/gl/GrGLInterface.h"
#include "include/gpu/gl/GrGLTypes.h"

SK_DEF_TYPE_MAP(GrGLGetProc, gr_gl_get_proc, GrGLGetProc)

SK_DEF_CLASS_MAP(GrGLFramebufferInfo, gr_gl_framebufferinfo_t, GrGLFramebufferInfo)
SK_DEF_CLASS_MAP(GrGLInterface, gr_gl_interface_t, GrGLInterface)
SK_DEF_CLASS_MAP(GrGLTextureInfo, gr_gl_textureinfo_t, GrGLTextureInfo)
#else
#define SK_ONLY_GL(...) SK_SKIP_ARG(__VA_ARGS__)
#endif

#ifdef SK_METAL
#define SK_ONLY_METAL(...) SK_FIRST_ARG(__VA_ARGS__)

#include "include/gpu/mtl/GrMtlBackendContext.h"
#include "include/gpu/mtl/GrMtlTypes.h"
#include "include/gpu/ganesh/mtl/SkSurfaceMetal.h"

static inline GrMtlBackendContext AsGrMtlBackendContext(const gr_mtl_backendcontext_t *context)
{
  GrMtlBackendContext result = {};
  result.fDevice.reset(context->device);
  result.fQueue.reset(context->queue);
  result.fBinaryArchive.reset(context->binary_archive);
  return result;
}

static inline GrMtlTextureInfo AsGrMtlTextureInfo(const gr_mtl_textureinfo_t *info)
{
  GrMtlTextureInfo result;
  result.fTexture.retain(info->texture);
  return result;
}
#else
#define SK_ONLY_METAL(...) SK_SKIP_ARG(__VA_ARGS__)
#endif

#ifdef SK_VULKAN
#define SK_ONLY_VULKAN(...) SK_FIRST_ARG(__VA_ARGS__)

#include "include/gpu/vk/GrVkBackendContext.h"
#include "include/gpu/vk/GrVkExtensions.h"
#include "include/gpu/vk/GrVkTypes.h"
#include "include/gpu/vk/VulkanTypes.h"

SK_DEF_TYPE_MAP(PFN_vkVoidFunction, void *, PFN_vkVoidFunction)
SK_DEF_TYPE_MAP(VkDevice, gr_vk_device_t, VkDevice)
SK_DEF_TYPE_MAP(VkDeviceMemory, gr_vk_devicememory_t, VkDeviceMemory)
SK_DEF_TYPE_MAP(VkImage, gr_vk_image_t, VkImage)
SK_DEF_TYPE_MAP(VkInstance, gr_vk_instance_t, VkInstance)
SK_DEF_TYPE_MAP(VkPhysicalDevice, gr_vk_physicaldevice_t, VkPhysicalDevice)
SK_DEF_TYPE_MAP(VkQueue, gr_vk_queue_t, VkQueue)
SK_DEF_TYPE_MAP(VkSemaphore, gr_vk_semaphore_t, VkSemaphore)

SK_DEF_ENUM_MAP(VkFormat, gr_vk_format_t, VkFormat)
SK_DEF_ENUM_MAP(VkImageLayout, gr_vk_imagelayout_t, VkImageLayout)
SK_DEF_ENUM_MAP(VkImageTiling, gr_vk_imagetiling_t, VkImageTiling)
SK_DEF_ENUM_MAP(VkSharingMode, gr_vk_sharingmode_t, VkSharingMode)

SK_DEF_CLASS_MAP(GrVkExtensions, gr_vk_extensions_t, GrVkExtensions)
SK_DEF_CLASS_MAP(GrVkYcbcrConversionInfo, gr_vk_ycbcrconversioninfo_t, GrVkYcbcrConversionInfo)
SK_DEF_CLASS_MAP(VkPhysicalDeviceFeatures, gr_vk_physicaldevicefeatures_t, VkPhysicalDeviceFeatures)
SK_DEF_CLASS_MAP(VkPhysicalDeviceFeatures2, gr_vk_physicaldevicefeatures2_t, VkPhysicalDeviceFeatures2)

static inline GrVkAlloc AsGrVkAlloc(const gr_vk_alloc_t *alloc)
{
  GrVkAlloc result;
  result.fMemory = AsVkDeviceMemory(alloc->device_memory);
  result.fOffset = alloc->offset;
  result.fSize = alloc->size;
  result.fFlags = alloc->flags;
  return result;
}

static inline GrVkBackendContext AsGrVkBackendContext(const gr_vk_backendcontext_t *context)
{
  GrVkBackendContext result;
  result.fInstance = AsVkInstance(context->instance);
  result.fPhysicalDevice = AsVkPhysicalDevice(context->physical_device);
  result.fDevice = AsVkDevice(context->device);
  result.fQueue = AsVkQueue(context->queue);
  result.fGraphicsQueueIndex = context->graphics_queue_index;
  result.fMaxAPIVersion = context->max_api_version;
  result.fVkExtensions = AsGrVkExtensions(context->extensions);
  result.fDeviceFeatures = AsVkPhysicalDeviceFeatures(context->physical_device_features);
  result.fDeviceFeatures2 = AsVkPhysicalDeviceFeatures2(context->physical_device_features2);
  if (context->get_context != nullptr)
  {
    result.fGetProc = [context = context->get_context, proc = context->get_proc](const char name[], VkInstance instance, VkDevice device)
    {
      return AsPFN_vkVoidFunction(proc(context, name, ToVkInstance(instance), ToVkDevice(device)));
    };
  }
  result.fProtectedContext = AsGrProtected(context->protected_context);
  return result;
}

static inline GrVkImageInfo AsGrVkImageInfo(const gr_vk_imageinfo_t *info)
{
  GrVkImageInfo result;
  result.fImage = AsVkImage(info->image);
  result.fAlloc = AsGrVkAlloc(&info->alloc);
  result.fImageTiling = AsVkImageTiling(info->image_tiling);
  result.fImageLayout = AsVkImageLayout(info->image_layout);
  result.fFormat = AsVkFormat(info->format);
  result.fImageUsageFlags = info->image_usage_flags;
  result.fSampleCount = info->sample_count;
  result.fLevelCount = info->level_count;
  result.fCurrentQueueFamily = info->current_queue_family;
  result.fProtected = AsGrProtected(info->protected_image);
  result.fYcbcrConversionInfo = AsGrVkYcbcrConversionInfo(info->ycbcr_conversion_info);
  result.fSharingMode = AsVkSharingMode(info->sharing_mode);
  return result;
}
#else
#define SK_ONLY_VULKAN(...) SK_SKIP_ARG(__VA_ARGS__)
#endif
#else
#define SK_ONLY_GPU(...) SK_SKIP_ARG(__VA_ARGS__)
#define SK_ONLY_GL(...) SK_SKIP_ARG(__VA_ARGS__)
#define SK_ONLY_METAL(...) SK_SKIP_ARG(__VA_ARGS__)
#define SK_ONLY_VULKAN(...) SK_SKIP_ARG(__VA_ARGS__)
#endif

#endif
