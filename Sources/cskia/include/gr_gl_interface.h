#ifndef gr_gl_interface_DEFINED
#define gr_gl_interface_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

SK_C_API bool gr_gl_interface_has_extension(const gr_gl_interface_t* self, const char name[]);
SK_C_API const gr_gl_interface_t* gr_gl_interface_make_assembled(void* context, gr_gl_get_proc proc);
SK_C_API const gr_gl_interface_t* gr_gl_interface_make_assembled_gl(void* context, gr_gl_get_proc proc);
SK_C_API const gr_gl_interface_t* gr_gl_interface_make_assembled_gles(void* context, gr_gl_get_proc proc);
SK_C_API const gr_gl_interface_t* gr_gl_interface_make_assembled_webgl(void* context, gr_gl_get_proc proc);
SK_C_API const gr_gl_interface_t* gr_gl_interface_make_native(void);
SK_C_API bool gr_gl_interface_validate(const gr_gl_interface_t* self);

SK_C_PLUS_PLUS_END_GUARD
#endif
