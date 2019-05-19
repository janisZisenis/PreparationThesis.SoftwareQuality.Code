
#ifndef QCustomPlot_EXPORT_H
#define QCustomPlot_EXPORT_H

#ifdef QCustomPlot_BUILT_AS_STATIC
#  define QCustomPlot_EXPORT
#  define QCUSTOMPLOT_NO_EXPORT
#else
#  ifndef QCustomPlot_EXPORT
#    ifdef QCustomPlot_EXPORTS
        /* We are building this library */
#      define QCustomPlot_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define QCustomPlot_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef QCUSTOMPLOT_NO_EXPORT
#    define QCUSTOMPLOT_NO_EXPORT 
#  endif
#endif

#ifndef QCUSTOMPLOT_DEPRECATED
#  define QCUSTOMPLOT_DEPRECATED __declspec(deprecated)
#endif

#ifndef QCUSTOMPLOT_DEPRECATED_EXPORT
#  define QCUSTOMPLOT_DEPRECATED_EXPORT QCustomPlot_EXPORT QCUSTOMPLOT_DEPRECATED
#endif

#ifndef QCUSTOMPLOT_DEPRECATED_NO_EXPORT
#  define QCUSTOMPLOT_DEPRECATED_NO_EXPORT QCUSTOMPLOT_NO_EXPORT QCUSTOMPLOT_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef QCUSTOMPLOT_NO_DEPRECATED
#    define QCUSTOMPLOT_NO_DEPRECATED
#  endif
#endif

#endif
