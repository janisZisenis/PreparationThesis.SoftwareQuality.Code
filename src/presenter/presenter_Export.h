
#ifndef presenter_EXPORT_H
#define presenter_EXPORT_H

#ifdef presenter_BUILT_AS_STATIC
#  define presenter_EXPORT
#  define PRESENTER_NO_EXPORT
#else
#  ifndef presenter_EXPORT
#    ifdef presenter_EXPORTS
        /* We are building this library */
#      define presenter_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define presenter_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef PRESENTER_NO_EXPORT
#    define PRESENTER_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef PRESENTER_DEPRECATED
#  define PRESENTER_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef PRESENTER_DEPRECATED_EXPORT
#  define PRESENTER_DEPRECATED_EXPORT presenter_EXPORT PRESENTER_DEPRECATED
#endif

#ifndef PRESENTER_DEPRECATED_NO_EXPORT
#  define PRESENTER_DEPRECATED_NO_EXPORT PRESENTER_NO_EXPORT PRESENTER_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef PRESENTER_NO_DEPRECATED
#    define PRESENTER_NO_DEPRECATED
#  endif
#endif

#endif
