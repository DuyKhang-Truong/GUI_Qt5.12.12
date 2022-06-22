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
    QByteArrayData data[69];
    char stringdata0[1578];
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
QT_MOC_LITERAL(3, 30, 7), // "setPath"
QT_MOC_LITERAL(4, 38, 19), // "customerStartMoving"
QT_MOC_LITERAL(5, 58, 16), // "checkDestination"
QT_MOC_LITERAL(6, 75, 16), // "postDataToServer"
QT_MOC_LITERAL(7, 92, 17), // "showMousePosition"
QT_MOC_LITERAL(8, 110, 7), // "QPoint&"
QT_MOC_LITERAL(9, 118, 3), // "pos"
QT_MOC_LITERAL(10, 122, 5), // "delta"
QT_MOC_LITERAL(11, 128, 14), // "showMousePress"
QT_MOC_LITERAL(12, 143, 20), // "showMouseDoubleClick"
QT_MOC_LITERAL(13, 164, 27), // "on_pushButton_pageB_clicked"
QT_MOC_LITERAL(14, 192, 27), // "on_pushButton_pageN_clicked"
QT_MOC_LITERAL(15, 220, 28), // "on_pushButton_page2B_clicked"
QT_MOC_LITERAL(16, 249, 28), // "on_pushButton_page2N_clicked"
QT_MOC_LITERAL(17, 278, 28), // "on_pushButton_page3B_clicked"
QT_MOC_LITERAL(18, 307, 28), // "on_pushButton_page3N_clicked"
QT_MOC_LITERAL(19, 336, 25), // "on_pushButton_Dir_clicked"
QT_MOC_LITERAL(20, 362, 30), // "on_pushButton_resetPos_clicked"
QT_MOC_LITERAL(21, 393, 29), // "on_pushButton_autoRun_clicked"
QT_MOC_LITERAL(22, 423, 27), // "on_pushButton_start_clicked"
QT_MOC_LITERAL(23, 451, 14), // "controlStartBT"
QT_MOC_LITERAL(24, 466, 26), // "on_pushButton_stop_clicked"
QT_MOC_LITERAL(25, 493, 36), // "on_pushButton_turnSignalLeft_..."
QT_MOC_LITERAL(26, 530, 37), // "on_pushButton_turnSignalRight..."
QT_MOC_LITERAL(27, 568, 26), // "on_pushButton_horn_clicked"
QT_MOC_LITERAL(28, 595, 32), // "on_pushButton_frontLight_clicked"
QT_MOC_LITERAL(29, 628, 32), // "on_pushButton_clearError_clicked"
QT_MOC_LITERAL(30, 661, 38), // "on_horizontalSlider_speed_val..."
QT_MOC_LITERAL(31, 700, 5), // "value"
QT_MOC_LITERAL(32, 706, 29), // "on_textEdit_speed_textChanged"
QT_MOC_LITERAL(33, 736, 27), // "on_pushButton_speed_clicked"
QT_MOC_LITERAL(34, 764, 30), // "on_pushButton_ctrlNMEA_clicked"
QT_MOC_LITERAL(35, 795, 28), // "on_pushButton_cfgFrq_clicked"
QT_MOC_LITERAL(36, 824, 26), // "on_pushButton_open_clicked"
QT_MOC_LITERAL(37, 851, 27), // "on_pushButton_close_clicked"
QT_MOC_LITERAL(38, 879, 25), // "on_button_Refresh_clicked"
QT_MOC_LITERAL(39, 905, 24), // "onTcpClientButtonClicked"
QT_MOC_LITERAL(40, 930, 28), // "onTcpClientStopButtonClicked"
QT_MOC_LITERAL(41, 959, 34), // "onTcpClientDisconnectButtonCl..."
QT_MOC_LITERAL(42, 994, 18), // "Add_Message_To_Box"
QT_MOC_LITERAL(43, 1013, 4), // "from"
QT_MOC_LITERAL(44, 1018, 7), // "message"
QT_MOC_LITERAL(45, 1026, 24), // "onTcpClientNewConnection"
QT_MOC_LITERAL(46, 1051, 4), // "port"
QT_MOC_LITERAL(47, 1056, 23), // "onTcpClientDisconnected"
QT_MOC_LITERAL(48, 1080, 22), // "onTcpClientSendMessage"
QT_MOC_LITERAL(49, 1103, 24), // "onTcpClientAppendMessage"
QT_MOC_LITERAL(50, 1128, 18), // "onTcpClientTimeOut"
QT_MOC_LITERAL(51, 1147, 18), // "user_Timer_Timeout"
QT_MOC_LITERAL(52, 1166, 20), // "SetSteeringDriverPos"
QT_MOC_LITERAL(53, 1187, 11), // "SteeringSet"
QT_MOC_LITERAL(54, 1199, 26), // "manualSteeringControlTimer"
QT_MOC_LITERAL(55, 1226, 30), // "on_pushButton_steering_clicked"
QT_MOC_LITERAL(56, 1257, 34), // "on_pushButton_autoSteering_cl..."
QT_MOC_LITERAL(57, 1292, 28), // "on_pushButton_openSV_clicked"
QT_MOC_LITERAL(58, 1321, 29), // "on_pushButton_closeSV_clicked"
QT_MOC_LITERAL(59, 1351, 7), // "CalcCRC"
QT_MOC_LITERAL(60, 1359, 5), // "uCode"
QT_MOC_LITERAL(61, 1365, 5), // "uSize"
QT_MOC_LITERAL(62, 1371, 15), // "unsigned char[]"
QT_MOC_LITERAL(63, 1387, 6), // "buffer"
QT_MOC_LITERAL(64, 1394, 34), // "on_pushButton_svSteeringON_cl..."
QT_MOC_LITERAL(65, 1429, 35), // "on_pushButton_svSteeringOFF_c..."
QT_MOC_LITERAL(66, 1465, 34), // "on_pushButton_steeringLeft_cl..."
QT_MOC_LITERAL(67, 1500, 35), // "on_pushButton_steeringRight_c..."
QT_MOC_LITERAL(68, 1536, 41) // "on_horizontalSlider_steering_..."

    },
    "MainWindow\0receiveSerialData\0\0setPath\0"
    "customerStartMoving\0checkDestination\0"
    "postDataToServer\0showMousePosition\0"
    "QPoint&\0pos\0delta\0showMousePress\0"
    "showMouseDoubleClick\0on_pushButton_pageB_clicked\0"
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
      55,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  289,    2, 0x08 /* Private */,
       3,    0,  290,    2, 0x08 /* Private */,
       4,    0,  291,    2, 0x08 /* Private */,
       5,    0,  292,    2, 0x08 /* Private */,
       6,    0,  293,    2, 0x08 /* Private */,
       7,    2,  294,    2, 0x08 /* Private */,
      11,    2,  299,    2, 0x08 /* Private */,
      12,    2,  304,    2, 0x08 /* Private */,
      13,    0,  309,    2, 0x08 /* Private */,
      14,    0,  310,    2, 0x08 /* Private */,
      15,    0,  311,    2, 0x08 /* Private */,
      16,    0,  312,    2, 0x08 /* Private */,
      17,    0,  313,    2, 0x08 /* Private */,
      18,    0,  314,    2, 0x08 /* Private */,
      19,    0,  315,    2, 0x08 /* Private */,
      20,    0,  316,    2, 0x08 /* Private */,
      21,    0,  317,    2, 0x08 /* Private */,
      22,    0,  318,    2, 0x08 /* Private */,
      23,    0,  319,    2, 0x08 /* Private */,
      24,    0,  320,    2, 0x08 /* Private */,
      25,    0,  321,    2, 0x08 /* Private */,
      26,    0,  322,    2, 0x08 /* Private */,
      27,    0,  323,    2, 0x08 /* Private */,
      28,    0,  324,    2, 0x08 /* Private */,
      29,    0,  325,    2, 0x08 /* Private */,
      30,    1,  326,    2, 0x08 /* Private */,
      32,    0,  329,    2, 0x08 /* Private */,
      33,    0,  330,    2, 0x08 /* Private */,
      34,    0,  331,    2, 0x08 /* Private */,
      35,    0,  332,    2, 0x08 /* Private */,
      36,    0,  333,    2, 0x08 /* Private */,
      37,    0,  334,    2, 0x08 /* Private */,
      38,    0,  335,    2, 0x08 /* Private */,
      39,    0,  336,    2, 0x08 /* Private */,
      40,    0,  337,    2, 0x08 /* Private */,
      41,    0,  338,    2, 0x08 /* Private */,
      42,    2,  339,    2, 0x08 /* Private */,
      45,    2,  344,    2, 0x08 /* Private */,
      47,    0,  349,    2, 0x08 /* Private */,
      48,    0,  350,    2, 0x08 /* Private */,
      49,    2,  351,    2, 0x08 /* Private */,
      50,    0,  356,    2, 0x08 /* Private */,
      51,    0,  357,    2, 0x08 /* Private */,
      52,    1,  358,    2, 0x08 /* Private */,
      54,    0,  361,    2, 0x08 /* Private */,
      55,    0,  362,    2, 0x08 /* Private */,
      56,    0,  363,    2, 0x08 /* Private */,
      57,    0,  364,    2, 0x08 /* Private */,
      58,    0,  365,    2, 0x08 /* Private */,
      59,    3,  366,    2, 0x08 /* Private */,
      64,    0,  373,    2, 0x08 /* Private */,
      65,    0,  374,    2, 0x08 /* Private */,
      66,    0,  375,    2, 0x08 /* Private */,
      67,    0,  376,    2, 0x08 /* Private */,
      68,    1,  377,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 8,    9,   10,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 8,    9,   10,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 8,    9,   10,
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
    QMetaType::Void, QMetaType::Int,   31,
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
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   43,   44,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,   43,   46,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   43,   44,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,   53,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, 0x80000000 | 62,   60,   61,   63,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   31,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receiveSerialData(); break;
        case 1: _t->setPath(); break;
        case 2: _t->customerStartMoving(); break;
        case 3: _t->checkDestination(); break;
        case 4: _t->postDataToServer(); break;
        case 5: _t->showMousePosition((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 6: _t->showMousePress((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 7: _t->showMouseDoubleClick((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 8: _t->on_pushButton_pageB_clicked(); break;
        case 9: _t->on_pushButton_pageN_clicked(); break;
        case 10: _t->on_pushButton_page2B_clicked(); break;
        case 11: _t->on_pushButton_page2N_clicked(); break;
        case 12: _t->on_pushButton_page3B_clicked(); break;
        case 13: _t->on_pushButton_page3N_clicked(); break;
        case 14: _t->on_pushButton_Dir_clicked(); break;
        case 15: _t->on_pushButton_resetPos_clicked(); break;
        case 16: _t->on_pushButton_autoRun_clicked(); break;
        case 17: _t->on_pushButton_start_clicked(); break;
        case 18: _t->controlStartBT(); break;
        case 19: _t->on_pushButton_stop_clicked(); break;
        case 20: _t->on_pushButton_turnSignalLeft_clicked(); break;
        case 21: _t->on_pushButton_turnSignalRight_clicked(); break;
        case 22: _t->on_pushButton_horn_clicked(); break;
        case 23: _t->on_pushButton_frontLight_clicked(); break;
        case 24: _t->on_pushButton_clearError_clicked(); break;
        case 25: _t->on_horizontalSlider_speed_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->on_textEdit_speed_textChanged(); break;
        case 27: _t->on_pushButton_speed_clicked(); break;
        case 28: _t->on_pushButton_ctrlNMEA_clicked(); break;
        case 29: _t->on_pushButton_cfgFrq_clicked(); break;
        case 30: _t->on_pushButton_open_clicked(); break;
        case 31: _t->on_pushButton_close_clicked(); break;
        case 32: _t->on_button_Refresh_clicked(); break;
        case 33: _t->onTcpClientButtonClicked(); break;
        case 34: _t->onTcpClientStopButtonClicked(); break;
        case 35: _t->onTcpClientDisconnectButtonClicked(); break;
        case 36: _t->Add_Message_To_Box((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 37: _t->onTcpClientNewConnection((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 38: _t->onTcpClientDisconnected(); break;
        case 39: _t->onTcpClientSendMessage(); break;
        case 40: _t->onTcpClientAppendMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 41: _t->onTcpClientTimeOut(); break;
        case 42: _t->user_Timer_Timeout(); break;
        case 43: _t->SetSteeringDriverPos((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 44: _t->manualSteeringControlTimer(); break;
        case 45: _t->on_pushButton_steering_clicked(); break;
        case 46: _t->on_pushButton_autoSteering_clicked(); break;
        case 47: _t->on_pushButton_openSV_clicked(); break;
        case 48: _t->on_pushButton_closeSV_clicked(); break;
        case 49: { unsigned char _r = _t->CalcCRC((*reinterpret_cast< unsigned char(*)>(_a[1])),(*reinterpret_cast< unsigned char(*)>(_a[2])),(*reinterpret_cast< unsigned char(*)[]>(_a[3])));
            if (_a[0]) *reinterpret_cast< unsigned char*>(_a[0]) = std::move(_r); }  break;
        case 50: _t->on_pushButton_svSteeringON_clicked(); break;
        case 51: _t->on_pushButton_svSteeringOFF_clicked(); break;
        case 52: _t->on_pushButton_steeringLeft_clicked(); break;
        case 53: _t->on_pushButton_steeringRight_clicked(); break;
        case 54: _t->on_horizontalSlider_steering_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        if (_id < 55)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 55;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 55)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 55;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
