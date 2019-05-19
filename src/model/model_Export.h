
#ifndef model_EXPORT_H
#define model_EXPORT_H

#ifdef model_BUILT_AS_STATIC
#  define model_EXPORT
#  define MODEL_NO_EXPORT
#else
#  ifndef model_EXPORT
#    ifdef model_EXPORTS
        /* We are building this library */
#      define model_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define model_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef MODEL_NO_EXPORT
#    define MODEL_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef MODEL_DEPRECATED
#  define MODEL_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef MODEL_DEPRECATED_EXPORT
#  define MODEL_DEPRECATED_EXPORT model_EXPORT MODEL_DEPRECATED
#endif

#ifndef MODEL_DEPRECATED_NO_EXPORT
#  define MODEL_DEPRECATED_NO_EXPORT MODEL_NO_EXPORT MODEL_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef MODEL_NO_DEPRECATED
#    define MODEL_NO_DEPRECATED
#  endif
#endif

#endif
