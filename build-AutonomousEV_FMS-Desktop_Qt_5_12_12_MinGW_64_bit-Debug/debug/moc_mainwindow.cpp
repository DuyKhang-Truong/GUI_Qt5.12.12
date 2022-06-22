/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AutonomousEV_FMS/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[67];
    char stringdata0[1550];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 17), // "receiveSerialData"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 16), // "checkDestination"
QT_MOC_LITERAL(4, 47, 16), // "postDataToServer"
QT_MOC_LITERAL(5, 64, 17), // "showMousePosition"
QT_MOC_LITERAL(6, 82, 7), // "QPoint&"
QT_MOC_LITERAL(7, 90, 3), // "pos"
QT_MOC_LITERAL(8, 94, 5), // "delta"
QT_MOC_LITERAL(9, 100, 14), // "showMousePress"
QT_MOC_LITERAL(10, 115, 20), // "showMouseDoubleClick"
QT_MOC_LITERAL(11, 136, 27), // "on_pushButton_pageB_clicked"
QT_MOC_LITERAL(12, 164, 27), // "on_pushButton_pageN_clicked"
QT_MOC_LITERAL(13, 192, 28), // "on_pushButton_page2B_clicked"
QT_MOC_LITERAL(14, 221, 28), // "on_pushButton_page2N_clicked"
QT_MOC_LITERAL(15, 250, 28), // "on_pushButton_page3B_clicked"
QT_MOC_LITERAL(16, 279, 28), // "on_pushButton_page3N_clicked"
QT_MOC_LITERAL(17, 308, 25), // "on_pushButton_Dir_clicked"
QT_MOC_LITERAL(18, 334, 30), // "on_pushButton_resetPos_clicked"
QT_MOC_LITERAL(19, 365, 29), // "on_pushButton_autoRun_clicked"
QT_MOC_LITERAL(20, 395, 27), // "on_pushButton_start_clicked"
QT_MOC_LITERAL(21, 423, 14), // "controlStartBT"
QT_MOC_LITERAL(22, 438, 26), // "on_pushButton_stop_clicked"
QT_MOC_LITERAL(23, 465, 36), // "on_pushButton_turnSignalLeft_..."
QT_MOC_LITERAL(24, 502, 37), // "on_pushButton_turnSignalRight..."
QT_MOC_LITERAL(25, 540, 26), // "on_pushButton_horn_clicked"
QT_MOC_LITERAL(26, 567, 32), // "on_pushButton_frontLight_clicked"
QT_MOC_LITERAL(27, 600, 32), // "on_pushButton_clearError_clicked"
QT_MOC_LITERAL(28, 633, 38), // "on_horizontalSlider_speed_val..."
QT_MOC_LITERAL(29, 672, 5), // "value"
QT_MOC_LITERAL(30, 678, 29), // "on_textEdit_speed_textChanged"
QT_MOC_LITERAL(31, 708, 27), // "on_pushButton_speed_clicked"
QT_MOC_LITERAL(32, 736, 30), // "on_pushButton_ctrlNMEA_clicked"
QT_MOC_LITERAL(33, 767, 28), // "on_pushButton_cfgFrq_clicked"
QT_MOC_LITERAL(34, 796, 26), // "on_pushButton_open_clicked"
QT_MOC_LITERAL(35, 823, 27), // "on_pushButton_close_clicked"
QT_MOC_LITERAL(36, 851, 25), // "on_button_Refresh_clicked"
QT_MOC_LITERAL(37, 877, 24), // "onTcpClientButtonClicked"
QT_MOC_LITERAL(38, 902, 28), // "onTcpClientStopButtonClicked"
QT_MOC_LITERAL(39, 931, 34), // "onTcpClientDisconnectButtonCl..."
QT_MOC_LITERAL(40, 966, 18), // "Add_Message_To_Box"
QT_MOC_LITERAL(41, 985, 4), // "from"
QT_MOC_LITERAL(42, 990, 7), // "message"
QT_MOC_LITERAL(43, 998, 24), // "onTcpClientNewConnection"
QT_MOC_LITERAL(44, 1023, 4), // "port"
QT_MOC_LITERAL(45, 1028, 23), // "onTcpClientDisconnected"
QT_MOC_LITERAL(46, 1052, 22), // "onTcpClientSendMessage"
QT_MOC_LITERAL(47, 1075, 24), // "onTcpClientAppendMessage"
QT_MOC_LITERAL(48, 1100, 18), // "onTcpClientTimeOut"
QT_MOC_LITERAL(49, 1119, 18), // "user_Timer_Timeout"
QT_MOC_LITERAL(50, 1138, 20), // "SetSteeringDriverPos"
QT_MOC_LITERAL(51, 1159, 11), // "SteeringSet"
QT_MOC_LITERAL(52, 1171, 26), // "manualSteeringControlTimer"
QT_MOC_LITERAL(53, 1198, 30), // "on_pushButton_steering_clicked"
QT_MOC_LITERAL(54, 1229, 34), // "on_pushButton_autoSteering_cl..."
QT_MOC_LITERAL(55, 1264, 28), // "on_pushButton_openSV_clicked"
QT_MOC_LITERAL(56, 1293, 29), // "on_pushButton_closeSV_clicked"
QT_MOC_LITERAL(57, 1323, 7), // "CalcCRC"
QT_MOC_LITERAL(58, 1331, 5), // "uCode"
QT_MOC_LITERAL(59, 1337, 5), // "uSize"
QT_MOC_LITERAL(60, 1343, 15), // "unsigned char[]"
QT_MOC_LITERAL(61, 1359, 6), // "buffer"
QT_MOC_LITERAL(62, 1366, 34), // "on_pushButton_svSteeringON_cl..."
QT_MOC_LITERAL(63, 1401, 35), // "on_pushButton_svSteeringOFF_c..."
QT_MOC_LITERAL(64, 1437, 34), // "on_pushButton_steeringLeft_cl..."
QT_MOC_LITERAL(65, 1472, 35), // "on_pushButton_steeringRight_c..."
QT_MOC_LITERAL(66, 1508, 41) // "on_horizontalSlider_steering_..."

    },
    "MainWindow\0receiveSerialData\0\0"
    "checkDestination\0postDataToServer\0"
    "showMousePosition\0QPoint&\0pos\0delta\0"
    "showMousePress\0showMouseDoubleClick\0"
    "on_pushButton_pageB_clicked\0"
    "on_pushButton_pageN_clicked\0"
    "on_pushButton_page2B_clicked\0"
    "on_pushButton_page2N_clicked\0"
    "on_pushButton_page3B_clicked\0"
    "on_pushButton_page3N_clicked\0"
    "on_pushButton_Dir_clicked\0"
    "on_pushButton_resetPos_clicked\0"
    "on_pushButton_autoRun_clicked\0"
    "on_pushButton_start_clicked\0controlStartBT\0"
    "on_pushButton_stop_clicked\0"
    "on_pushButton_turnSignalLeft_clicked\0"
    "on_pushButton_turnSignalRight_clicked\0"
    "on_pushButton_horn_clicked\0"
    "on_pushButton_frontLight_clicked\0"
    "on_pushButton_clearError_clicked\0"
    "on_horizontalSlider_speed_valueChanged\0"
    "value\0on_textEdit_speed_textChanged\0"
    "on_pushButton_speed_clicked\0"
    "on_pushButton_ctrlNMEA_clicked\0"
    "on_pushButton_cfgFrq_clicked\0"
    "on_pushButton_open_clicked\0"
    "on_pushButton_close_clicked\0"
    "on_button_Refresh_clicked\0"
    "onTcpClientButtonClicked\0"
    "onTcpClientStopButtonClicked\0"
    "onTcpClientDisconnectButtonClicked\0"
    "Add_Message_To_Box\0from\0message\0"
    "onTcpClientNewConnection\0port\0"
    "onTcpClientDisconnected\0onTcpClientSendMessage\0"
    "onTcpClientAppendMessage\0onTcpClientTimeOut\0"
    "user_Timer_Timeout\0SetSteeringDriverPos\0"
    "SteeringSet\0manualSteeringControlTimer\0"
    "on_pushButton_steering_clicked\0"
    "on_pushButton_autoSteering_clicked\0"
    "on_pushButton_openSV_clicked\0"
    "on_pushButton_closeSV_clicked\0CalcCRC\0"
    "uCode\0uSize\0unsigned char[]\0buffer\0"
    "on_pushButton_svSteeringON_clicked\0"
    "on_pushButton_svSteeringOFF_clicked\0"
    "on_pushButton_steeringLeft_clicked\0"
    "on_pushButton_steeringRight_clicked\0"
    "on_horizontalSlider_steering_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      53,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  279,    2, 0x08 /* Private */,
       3,    0,  280,    2, 0x08 /* Private */,
       4,    0,  281,    2, 0x08 /* Private */,
       5,    2,  282,    2, 0x08 /* Private */,
       9,    2,  287,    2, 0x08 /* Private */,
      10,    2,  292,    2, 0x08 /* Private */,
      11,    0,  297,    2, 0x08 /* Private */,
      12,    0,  298,    2, 0x08 /* Private */,
      13,    0,  299,    2, 0x08 /* Private */,
      14,    0,  300,    2, 0x08 /* Private */,
      15,    0,  301,    2, 0x08 /* Private */,
      16,    0,  302,    2, 0x08 /* Private */,
      17,    0,  303,    2, 0x08 /* Private */,
      18,    0,  304,    2, 0x08 /* Private */,
      19,    0,  305,    2, 0x08 /* Private */,
      20,    0,  306,    2, 0x08 /* Private */,
      21,    0,  307,    2, 0x08 /* Private */,
      22,    0,  308,    2, 0x08 /* Private */,
      23,    0,  309,    2, 0x08 /* Private */,
      24,    0,  310,    2, 0x08 /* Private */,
      25,    0,  311,    2, 0x08 /* Private */,
      26,    0,  312,    2, 0x08 /* Private */,
      27,    0,  313,    2, 0x08 /* Private */,
      28,    1,  314,    2, 0x08 /* Private */,
      30,    0,  317,    2, 0x08 /* Private */,
      31,    0,  318,    2, 0x08 /* Private */,
      32,    0,  319,    2, 0x08 /* Private */,
      33,    0,  320,    2, 0x08 /* Private */,
      34,    0,  321,    2, 0x08 /* Private */,
      35,    0,  322,    2, 0x08 /* Private */,
      36,    0,  323,    2, 0x08 /* Private */,
      37,    0,  324,    2, 0x08 /* Private */,
      38,    0,  325,    2, 0x08 /* Private */,
      39,    0,  326,    2, 0x08 /* Private */,
      40,    2,  327,    2, 0x08 /* Private */,
      43,    2,  332,    2, 0x08 /* Private */,
      45,    0,  337,    2, 0x08 /* Private */,
      46,    0,  338,    2, 0x08 /* Private */,
      47,    2,  339,    2, 0x08 /* Private */,
      48,    0,  344,    2, 0x08 /* Private */,
      49,    0,  345,    2, 0x08 /* Private */,
      50,    1,  346,    2, 0x08 /* Private */,
      52,    0,  349,    2, 0x08 /* Private */,
      53,    0,  350,    2, 0x08 /* Private */,
      54,    0,  351,    2, 0x08 /* Private */,
      55,    0,  352,    2, 0x08 /* Private */,
      56,    0,  353,    2, 0x08 /* Private */,
      57,    3,  354,    2, 0x08 /* Private */,
      62,    0,  361,    2, 0x08 /* Private */,
      63,    0,  362,    2, 0x08 /* Private */,
      64,    0,  363,    2, 0x08 /* Private */,
      65,    0,  364,    2, 0x08 /* Private */,
      66,    1,  365,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,    8,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,    8,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   29,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   41,   42,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,   41,   44,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   41,   42,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,   51,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, 0x80000000 | 60,   58,   59,   61,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   29,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receiveSerialData(); break;
        case 1: _t->checkDestination(); break;
        case 2: _t->postDataToServer(); break;
        case 3: _t->showMousePosition((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 4: _t->showMousePress((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 5: _t->showMouseDoubleClick((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 6: _t->on_pushButton_pageB_clicked(); break;
        case 7: _t->on_pushButton_pageN_clicked(); break;
        case 8: _t->on_pushButton_page2B_clicked(); break;
        case 9: _t->on_pushButton_page2N_clicked(); break;
        case 10: _t->on_pushButton_page3B_clicked(); break;
        case 11: _t->on_pushButton_page3N_clicked(); break;
        case 12: _t->on_pushButton_Dir_clicked(); break;
        case 13: _t->on_pushButton_resetPos_clicked(); break;
        case 14: _t->on_pushButton_autoRun_clicked(); break;
        case 15: _t->on_pushButton_start_clicked(); break;
        case 16: _t->controlStartBT(); break;
        case 17: _t->on_pushButton_stop_clicked(); break;
        case 18: _t->on_pushButton_turnSignalLeft_clicked(); break;
        case 19: _t->on_pushButton_turnSignalRight_clicked(); break;
        case 20: _t->on_pushButton_horn_clicked(); break;
        case 21: _t->on_pushButton_frontLight_clicked(); break;
        case 22: _t->on_pushButton_clearError_clicked(); break;
        case 23: _t->on_horizontalSlider_speed_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->on_textEdit_speed_textChanged(); break;
        case 25: _t->on_pushButton_speed_clicked(); break;
        case 26: _t->on_pushButton_ctrlNMEA_clicked(); break;
        case 27: _t->on_pushButton_cfgFrq_clicked(); break;
        case 28: _t->on_pushButton_open_clicked(); break;
        case 29: _t->on_pushButton_close_clicked(); break;
        case 30: _t->on_button_Refresh_clicked(); break;
        case 31: _t->onTcpClientButtonClicked(); break;
        case 32: _t->onTcpClientStopButtonClicked(); break;
        case 33: _t->onTcpClientDisconnectButtonClicked(); break;
        case 34: _t->Add_Message_To_Box((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 35: _t->onTcpClientNewConnection((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 36: _t->onTcpClientDisconnected(); break;
        case 37: _t->onTcpClientSendMessage(); break;
        case 38: _t->onTcpClientAppendMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 39: _t->onTcpClientTimeOut(); break;
        case 40: _t->user_Timer_Timeout(); break;
        case 41: _t->SetSteeringDriverPos((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 42: _t->manualSteeringControlTimer(); break;
        case 43: _t->on_pushButton_steering_clicked(); break;
        case 44: _t->on_pushButton_autoSteering_clicked(); break;
        case 45: _t->on_pushButton_openSV_clicked(); break;
        case 46: _t->on_pushButton_closeSV_clicked(); break;
        case 47: { unsigned char _r = _t->CalcCRC((*reinterpret_cast< unsigned char(*)>(_a[1])),(*reinterpret_cast< unsigned char(*)>(_a[2])),(*reinterpret_cast< unsigned char(*)[]>(_a[3])));
            if (_a[0]) *reinterpret_cast< unsigned char*>(_a[0]) = std::move(_r); }  break;
        case 48: _t->on_pushButton_svSteeringON_clicked(); break;
        case 49: _t->on_pushButton_svSteeringOFF_clicked(); break;
        case 50: _t->on_pushButton_steeringLeft_clicked(); break;
        case 51: _t->on_pushButton_steeringRight_clicked(); break;
        case 52: _t->on_horizontalSlider_steering_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 53)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 53;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 53)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 53;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
