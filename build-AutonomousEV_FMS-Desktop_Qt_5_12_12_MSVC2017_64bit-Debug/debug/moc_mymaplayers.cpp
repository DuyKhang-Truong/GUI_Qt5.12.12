/****************************************************************************
** Meta object code from reading C++ file 'mymaplayers.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AutonomousEV_FMS/mymaplayers.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mymaplayers.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_myMapLayers_t {
    QByteArrayData data[6];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_myMapLayers_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_myMapLayers_t qt_meta_stringdata_myMapLayers = {
    {
QT_MOC_LITERAL(0, 0, 11), // "myMapLayers"
QT_MOC_LITERAL(1, 12, 17), // "sendMousePosition"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 7), // "QPoint&"
QT_MOC_LITERAL(4, 39, 14), // "sendMousePress"
QT_MOC_LITERAL(5, 54, 20) // "sendMouseDoubleClick"

    },
    "myMapLayers\0sendMousePosition\0\0QPoint&\0"
    "sendMousePress\0sendMouseDoubleClick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_myMapLayers[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       4,    2,   34,    2, 0x06 /* Public */,
       5,    2,   39,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    2,    2,

       0        // eod
};

void myMapLayers::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<myMapLayers *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendMousePosition((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 1: _t->sendMousePress((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 2: _t->sendMouseDoubleClick((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (myMapLayers::*)(QPoint & , QPoint & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&myMapLayers::sendMousePosition)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (myMapLayers::*)(QPoint & , QPoint & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&myMapLayers::sendMousePress)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (myMapLayers::*)(QPoint & , QPoint & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&myMapLayers::sendMouseDoubleClick)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject myMapLayers::staticMetaObject = { {
    &QGraphicsView::staticMetaObject,
    qt_meta_stringdata_myMapLayers.data,
    qt_meta_data_myMapLayers,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *myMapLayers::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *myMapLayers::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_myMapLayers.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int myMapLayers::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void myMapLayers::sendMousePosition(QPoint & _t1, QPoint & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void myMapLayers::sendMousePress(QPoint & _t1, QPoint & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void myMapLayers::sendMouseDoubleClick(QPoint & _t1, QPoint & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
