
#ifndef item_EXPORT_H
#define item_EXPORT_H

#ifdef item_BUILT_AS_STATIC
#  define item_EXPORT
#  define ITEM_NO_EXPORT
#else
#  ifndef item_EXPORT
#    ifdef item_EXPORTS
        /* We are building this library */
#      define item_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define item_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef ITEM_NO_EXPORT
#    define ITEM_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef ITEM_DEPRECATED
#  define ITEM_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef ITEM_DEPRECATED_EXPORT
#  define ITEM_DEPRECATED_EXPORT item_EXPORT ITEM_DEPRECATED
#endif

#ifndef ITEM_DEPRECATED_NO_EXPORT
#  define ITEM_DEPRECATED_NO_EXPORT ITEM_NO_EXPORT ITEM_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITEM_NO_DEPRECATED
#    define ITEM_NO_DEPRECATED
#  endif
#endif

#endif
