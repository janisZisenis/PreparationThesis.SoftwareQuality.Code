
#ifndef utilities_EXPORT_H
#define utilities_EXPORT_H

#ifdef utilities_BUILT_AS_STATIC
#  define utilities_EXPORT
#  define UTILITIES_NO_EXPORT
#else
#  ifndef utilities_EXPORT
#    ifdef utilities_EXPORTS
        /* We are building this library */
#      define utilities_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define utilities_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef UTILITIES_NO_EXPORT
#    define UTILITIES_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef UTILITIES_DEPRECATED
#  define UTILITIES_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef UTILITIES_DEPRECATED_EXPORT
#  define UTILITIES_DEPRECATED_EXPORT utilities_EXPORT UTILITIES_DEPRECATED
#endif

#ifndef UTILITIES_DEPRECATED_NO_EXPORT
#  define UTILITIES_DEPRECATED_NO_EXPORT UTILITIES_NO_EXPORT UTILITIES_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef UTILITIES_NO_DEPRECATED
#    define UTILITIES_NO_DEPRECATED
#  endif
#endif

#endif
