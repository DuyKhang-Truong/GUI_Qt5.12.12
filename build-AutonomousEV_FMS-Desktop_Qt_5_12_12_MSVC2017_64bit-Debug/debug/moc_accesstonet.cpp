/****************************************************************************
** Meta object code from reading C++ file 'accesstonet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AutonomousEV_FMS/accesstonet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'accesstonet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AccessToNet_t {
    QByteArrayData data[25];
    char stringdata0[368];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AccessToNet_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AccessToNet_t qt_meta_stringdata_AccessToNet = {
    {
QT_MOC_LITERAL(0, 0, 11), // "AccessToNet"
QT_MOC_LITERAL(1, 12, 3), // "get"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 8), // "location"
QT_MOC_LITERAL(4, 26, 4), // "post"
QT_MOC_LITERAL(5, 31, 4), // "data"
QT_MOC_LITERAL(6, 36, 9), // "readyRead"
QT_MOC_LITERAL(7, 46, 22), // "authenticationRequired"
QT_MOC_LITERAL(8, 69, 14), // "QNetworkReply*"
QT_MOC_LITERAL(9, 84, 5), // "reply"
QT_MOC_LITERAL(10, 90, 15), // "QAuthenticator*"
QT_MOC_LITERAL(11, 106, 13), // "authenticator"
QT_MOC_LITERAL(12, 120, 9), // "encrypted"
QT_MOC_LITERAL(13, 130, 8), // "finished"
QT_MOC_LITERAL(14, 139, 25), // "networkAccessibleChannged"
QT_MOC_LITERAL(15, 165, 43), // "QNetworkAccessManager::Networ..."
QT_MOC_LITERAL(16, 209, 10), // "accessible"
QT_MOC_LITERAL(17, 220, 34), // "preSharedKeyAuthenticationReq..."
QT_MOC_LITERAL(18, 255, 30), // "QSslPreSharedKeyAuthenticator*"
QT_MOC_LITERAL(19, 286, 27), // "proxyAuthenticationRequired"
QT_MOC_LITERAL(20, 314, 13), // "QNetworkProxy"
QT_MOC_LITERAL(21, 328, 5), // "proxy"
QT_MOC_LITERAL(22, 334, 9), // "sslErrors"
QT_MOC_LITERAL(23, 344, 16), // "QList<QSslError>"
QT_MOC_LITERAL(24, 361, 6) // "errors"

    },
    "AccessToNet\0get\0\0location\0post\0data\0"
    "readyRead\0authenticationRequired\0"
    "QNetworkReply*\0reply\0QAuthenticator*\0"
    "authenticator\0encrypted\0finished\0"
    "networkAccessibleChannged\0"
    "QNetworkAccessManager::NetworkAccessibility\0"
    "accessible\0preSharedKeyAuthenticationRequired\0"
    "QSslPreSharedKeyAuthenticator*\0"
    "proxyAuthenticationRequired\0QNetworkProxy\0"
    "proxy\0sslErrors\0QList<QSslError>\0"
    "errors"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AccessToNet[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x0a /* Public */,
       4,    2,   67,    2, 0x0a /* Public */,
       6,    0,   72,    2, 0x08 /* Private */,
       7,    2,   73,    2, 0x08 /* Private */,
      12,    1,   78,    2, 0x08 /* Private */,
      13,    1,   81,    2, 0x08 /* Private */,
      14,    1,   84,    2, 0x08 /* Private */,
      17,    2,   87,    2, 0x08 /* Private */,
      19,    2,   92,    2, 0x08 /* Private */,
      22,    2,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QByteArray,    3,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 10,    9,   11,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 18,    9,   11,
    QMetaType::Void, 0x80000000 | 20, 0x80000000 | 10,   21,   11,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 23,    9,   24,

       0        // eod
};

void AccessToNet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AccessToNet *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->get((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->post((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 2: _t->readyRead(); break;
        case 3: _t->authenticationRequired((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< QAuthenticator*(*)>(_a[2]))); break;
        case 4: _t->encrypted((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 5: _t->finished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 6: _t->networkAccessibleChannged((*reinterpret_cast< QNetworkAccessManager::NetworkAccessibility(*)>(_a[1]))); break;
        case 7: _t->preSharedKeyAuthenticationRequired((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< QSslPreSharedKeyAuthenticator*(*)>(_a[2]))); break;
        case 8: _t->proxyAuthenticationRequired((*reinterpret_cast< const QNetworkProxy(*)>(_a[1])),(*reinterpret_cast< QAuthenticator*(*)>(_a[2]))); break;
        case 9: _t->sslErrors((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< const QList<QSslError>(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSslPreSharedKeyAuthenticator* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkProxy >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSslError> >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AccessToNet::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_AccessToNet.data,
    qt_meta_data_AccessToNet,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AccessToNet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AccessToNet::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AccessToNet.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AccessToNet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
