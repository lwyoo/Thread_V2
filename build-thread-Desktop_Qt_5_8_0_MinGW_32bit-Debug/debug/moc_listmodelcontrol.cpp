/****************************************************************************
** Meta object code from reading C++ file 'listmodelcontrol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../thread/listmodelcontrol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'listmodelcontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ListModelControl_t {
    QByteArrayData data[10];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ListModelControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ListModelControl_t qt_meta_stringdata_ListModelControl = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ListModelControl"
QT_MOC_LITERAL(1, 17, 8), // "listInit"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 12), // "addListModel"
QT_MOC_LITERAL(4, 40, 6), // "nValue"
QT_MOC_LITERAL(5, 47, 14), // "removListModel"
QT_MOC_LITERAL(6, 62, 11), // "startOffSet"
QT_MOC_LITERAL(7, 74, 9), // "endOffSet"
QT_MOC_LITERAL(8, 84, 18), // "allRemoveListModel"
QT_MOC_LITERAL(9, 103, 18) // "addListModelThread"

    },
    "ListModelControl\0listInit\0\0addListModel\0"
    "nValue\0removListModel\0startOffSet\0"
    "endOffSet\0allRemoveListModel\0"
    "addListModelThread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ListModelControl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x02 /* Public */,
       3,    1,   40,    2, 0x02 /* Public */,
       5,    2,   43,    2, 0x02 /* Public */,
       8,    0,   48,    2, 0x02 /* Public */,
       9,    1,   49,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,

       0        // eod
};

void ListModelControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ListModelControl *_t = static_cast<ListModelControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->listInit(); break;
        case 1: _t->addListModel((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->removListModel((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 3: _t->allRemoveListModel(); break;
        case 4: _t->addListModelThread((*reinterpret_cast< const int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ListModelControl::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ListModelControl.data,
      qt_meta_data_ListModelControl,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ListModelControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ListModelControl::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ListModelControl.stringdata0))
        return static_cast<void*>(const_cast< ListModelControl*>(this));
    return QObject::qt_metacast(_clname);
}

int ListModelControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
