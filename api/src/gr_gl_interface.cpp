#include "include/gr_gl_interface.h"
#include "sk_mapping.h"

bool gr_gl_interface_has_extension(const gr_gl_interface_t *self, const char name[])
{
  return SK_ONLY_GL(AsGrGLInterface(self)->hasExtension(name), false);
}

const gr_gl_interface_t *gr_gl_interface_make_assembled(void *context, gr_gl_get_proc proc)
{
  return SK_ONLY_GL(ToGrGLInterface(GrGLMakeAssembledInterface(context, AsGrGLGetProc(proc)).release()), nullptr);
}

const gr_gl_interface_t *gr_gl_interface_make_assembled_gl(void *context, gr_gl_get_proc proc)
{
  return SK_ONLY_GL(ToGrGLInterface(GrGLMakeAssembledGLInterface(context, AsGrGLGetProc(proc)).release()), nullptr);
}

const gr_gl_interface_t *gr_gl_interface_make_assembled_gles(void *context, gr_gl_get_proc proc)
{
  return SK_ONLY_GL(ToGrGLInterface(GrGLMakeAssembledGLESInterface(context, AsGrGLGetProc(proc)).release()), nullptr);
}

const gr_gl_interface_t *gr_gl_interface_make_assembled_webgl(void *context, gr_gl_get_proc proc)
{
  return SK_ONLY_GL(ToGrGLInterface(GrGLMakeAssembledWebGLInterface(context, AsGrGLGetProc(proc)).release()), nullptr);
}

const gr_gl_interface_t *gr_gl_interface_make_native(void)
{
  return SK_ONLY_GL(ToGrGLInterface(GrGLMakeNativeInterface().release()), nullptr);
}

bool gr_gl_interface_validate(const gr_gl_interface_t *self)
{
  return SK_ONLY_GL(AsGrGLInterface(self)->validate(), false);
}
