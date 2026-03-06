#ifndef SK_DEFAULT_FONTMGR_H
#define SK_DEFAULT_FONTMGR_H

#include "include/core/SkFontMgr.h"

#if defined(SK_BUILD_FOR_MAC) || defined(SK_BUILD_FOR_IOS)
#include "include/ports/SkFontMgr_mac_ct.h"
#elif defined(SK_BUILD_FOR_ANDROID)
#include "include/ports/SkFontMgr_android.h"
#elif defined(SK_FONTMGR_FONTCONFIG_AVAILABLE)
#include "include/ports/SkFontMgr_fontconfig.h"
#else
#include "include/ports/SkFontMgr_empty.h"
#endif

inline sk_sp<SkFontMgr> sk_get_default_fontmgr() {
  static sk_sp<SkFontMgr> mgr = [] {
#if defined(SK_BUILD_FOR_MAC) || defined(SK_BUILD_FOR_IOS)
    return SkFontMgr_New_CoreText(nullptr);
#elif defined(SK_BUILD_FOR_ANDROID)
    return SkFontMgr_New_Android(nullptr, nullptr);
#elif defined(SK_FONTMGR_FONTCONFIG_AVAILABLE)
    return SkFontMgr_New_FontConfig(nullptr, nullptr);
#else
    return SkFontMgr_New_Custom_Empty();
#endif
  }();
  return mgr;
}

#endif
