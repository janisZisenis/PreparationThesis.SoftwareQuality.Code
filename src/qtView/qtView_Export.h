
#ifndef qtView_EXPORT_H
#define qtView_EXPORT_H

#ifdef qtView_BUILT_AS_STATIC
#  define qtView_EXPORT
#  define QTVIEW_NO_EXPORT
#else
#  ifndef qtView_EXPORT
#    ifdef qtView_EXPORTS
        /* We are building this library */
#      define qtView_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define qtView_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef QTVIEW_NO_EXPORT
#    define QTVIEW_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef QTVIEW_DEPRECATED
#  define QTVIEW_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef QTVIEW_DEPRECATED_EXPORT
#  define QTVIEW_DEPRECATED_EXPORT qtView_EXPORT QTVIEW_DEPRECATED
#endif

#ifndef QTVIEW_DEPRECATED_NO_EXPORT
#  define QTVIEW_DEPRECATED_NO_EXPORT QTVIEW_NO_EXPORT QTVIEW_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef QTVIEW_NO_DEPRECATED
#    define QTVIEW_NO_DEPRECATED
#  endif
#endif

#endif
