/****************************************************************************
** Meta object code from reading C++ file 'MyQEditMenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/qtView/MyQMenu/MyQEditMenu/MyQEditMenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyQEditMenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyQEditMenu_t {
    QByteArrayData data[4];
    char stringdata0[37];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyQEditMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyQEditMenu_t qt_meta_stringdata_MyQEditMenu = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MyQEditMenu"
QT_MOC_LITERAL(1, 12, 11), // "undoClicked"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11) // "redoClicked"

    },
    "MyQEditMenu\0undoClicked\0\0redoClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyQEditMenu[] = {

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
       1,    0,   24,    2, 0x08 /* Private */,
       3,    0,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyQEditMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyQEditMenu *_t = static_cast<MyQEditMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->undoClicked(); break;
        case 1: _t->redoClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MyQEditMenu::staticMetaObject = {
    { &QMenu::staticMetaObject, qt_meta_stringdata_MyQEditMenu.data,
      qt_meta_data_MyQEditMenu,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyQEditMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyQEditMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyQEditMenu.stringdata0))
        return static_cast<void*>(const_cast< MyQEditMenu*>(this));
    if (!strcmp(_clname, "EditMenu"))
        return static_cast< EditMenu*>(const_cast< MyQEditMenu*>(this));
    return QMenu::qt_metacast(_clname);
}

int MyQEditMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
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
