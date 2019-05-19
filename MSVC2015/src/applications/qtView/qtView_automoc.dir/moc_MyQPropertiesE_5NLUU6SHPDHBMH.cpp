/****************************************************************************
** Meta object code from reading C++ file 'MyQPropertiesExplorer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/qtView/MyQDockWidget/MyQPropertiesExplorer/MyQPropertiesExplorer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyQPropertiesExplorer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyQPropertiesExplorer_t {
    QByteArrayData data[8];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyQPropertiesExplorer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyQPropertiesExplorer_t qt_meta_stringdata_MyQPropertiesExplorer = {
    {
QT_MOC_LITERAL(0, 0, 21), // "MyQPropertiesExplorer"
QT_MOC_LITERAL(1, 22, 19), // "onVisibilityChanged"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 7), // "visible"
QT_MOC_LITERAL(4, 51, 16), // "onPropertyEdited"
QT_MOC_LITERAL(5, 68, 11), // "std::string"
QT_MOC_LITERAL(6, 80, 12), // "propertyName"
QT_MOC_LITERAL(7, 93, 13) // "propertyValue"

    },
    "MyQPropertiesExplorer\0onVisibilityChanged\0"
    "\0visible\0onPropertyEdited\0std::string\0"
    "propertyName\0propertyValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyQPropertiesExplorer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       4,    2,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,    6,    7,

       0        // eod
};

void MyQPropertiesExplorer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyQPropertiesExplorer *_t = static_cast<MyQPropertiesExplorer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onVisibilityChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->onPropertyEdited((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject MyQPropertiesExplorer::staticMetaObject = {
    { &MyQDockWidget::staticMetaObject, qt_meta_stringdata_MyQPropertiesExplorer.data,
      qt_meta_data_MyQPropertiesExplorer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyQPropertiesExplorer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyQPropertiesExplorer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyQPropertiesExplorer.stringdata0))
        return static_cast<void*>(const_cast< MyQPropertiesExplorer*>(this));
    if (!strcmp(_clname, "PropertiesExplorer"))
        return static_cast< PropertiesExplorer*>(const_cast< MyQPropertiesExplorer*>(this));
    return MyQDockWidget::qt_metacast(_clname);
}

int MyQPropertiesExplorer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MyQDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
