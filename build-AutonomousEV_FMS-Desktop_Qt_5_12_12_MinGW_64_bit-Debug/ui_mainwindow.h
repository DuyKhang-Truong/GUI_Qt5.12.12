/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "mymaplayers.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QPushButton *pushButton_pageB;
    QPushButton *pushButton_pageN;
    myMapLayers *graphicsView_mapLayers;
    QLabel *label_currentPos;
    QPushButton *pushButton_horn;
    QPushButton *pushButton_frontLight;
    QPushButton *pushButton_clearError;
    QGroupBox *groupBox_speedDisplay;
    QPushButton *pushButton_Dir;
    QLabel *label_cirSpd;
    QLabel *label_dim;
    QLabel *label_speed;
    QPushButton *pushButton_speed;
    QTextEdit *textEdit_speed;
    QSlider *horizontalSlider_speed;
    QPushButton *pushButton_turnSignalLeft;
    QPushButton *pushButton_turnSignalRight;
    QLabel *label_Straight;
    QLabel *label_Left;
    QLabel *label_Right;
    QLabel *label_steeringWheel;
    QPushButton *pushButton_autoRun;
    QPushButton *pushButton_start;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_steeringLeft;
    QPushButton *pushButton_steeringRight;
    QLabel *label_steering;
    QPushButton *pushButton_resetPos;
    QGraphicsView *graphicsView_radarScan;
    QLabel *lblVel;
    QLabel *lblTTC;
    QLabel *label_SPSpeed;
    QLabel *label_Dir;
    QPushButton *pushButton_steering;
    QSlider *horizontalSlider_steering;
    QPushButton *pushButton_autoSteering;
    QLabel *label_destination;
    QLabel *label_checkDes;
    QPushButton *pushButton_open;
    QLabel *label_pixel;
    QComboBox *comboBox_comUart;
    QWidget *page_2;
    QPushButton *pushButton_page2B;
    QPushButton *pushButton_page2N;
    QGroupBox *groupBox_2;
    QComboBox *comboBox_Interface;
    QLabel *label_4;
    QLabel *label_LocalIP;
    QPushButton *button_Refresh;
    QGroupBox *groupBox_message;
    QTextBrowser *textBrowser_TcpClientMessage;
    QLabel *label_topic;
    QComboBox *comboBox_topic;
    QPushButton *button_TcpClientSend;
    QGroupBox *groupBox_clientConnect;
    QLabel *label_targetIP;
    QLineEdit *lineEdit_TcpClientTargetIP;
    QLabel *label_targetPort;
    QLineEdit *lineEdit_TcpClientTargetPort;
    QPushButton *button_TcpClient;
    QLineEdit *lineEdit_TcpClientSend;
    QLabel *label_2;
    QWidget *page_3;
    QLabel *label_3;
    QPushButton *pushButton_page3B;
    QPushButton *pushButton_page3N;
    QGroupBox *groupBox_3;
    QComboBox *comboBox_NMEA;
    QLabel *label_5;
    QPushButton *pushButton_ctrlNMEA;
    QComboBox *comboBox_FREQ;
    QPushButton *pushButton_cfgFrq;
    QPushButton *pushButton_close;
    QLabel *label_UART;
    QGroupBox *groupBox;
    QPushButton *pushButton_svSteeringON;
    QPushButton *pushButton_svSteeringOFF;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton_closeSV;
    QComboBox *comboBox_comServo;
    QPushButton *pushButton_openSV;
    QLabel *label_serialSV;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1070, 780);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/car.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1071, 780));
        QFont font;
        font.setPointSize(13);
        stackedWidget->setFont(font);
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(43, 71, 106, 255), stop:1 rgba(67, 53, 91, 255));\n"
"\n"
"color: rgb(255, 255, 255);"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setFont(font);
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 740, 41, 31));
        label->setStyleSheet(QString::fromUtf8(""));
        pushButton_pageB = new QPushButton(page);
        pushButton_pageB->setObjectName(QString::fromUtf8("pushButton_pageB"));
        pushButton_pageB->setGeometry(QRect(0, 0, 41, 751));
        pushButton_pageB->setLayoutDirection(Qt::LeftToRight);
        pushButton_pageB->setStyleSheet(QString::fromUtf8("image: url(:/NextAndBack/back.png);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border:  0px;"));
        pushButton_pageN = new QPushButton(page);
        pushButton_pageN->setObjectName(QString::fromUtf8("pushButton_pageN"));
        pushButton_pageN->setGeometry(QRect(1030, 0, 41, 751));
        pushButton_pageN->setStyleSheet(QString::fromUtf8("image: url(:/NextAndBack/next.png);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border:  0px;"));
        graphicsView_mapLayers = new myMapLayers(page);
        graphicsView_mapLayers->setObjectName(QString::fromUtf8("graphicsView_mapLayers"));
        graphicsView_mapLayers->setGeometry(QRect(50, 10, 701, 460));
        graphicsView_mapLayers->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        graphicsView_mapLayers->setMouseTracking(true);
        graphicsView_mapLayers->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-radius: 7px;\n"
"border: 5px solid rgb(75, 85, 117);\n"
"\n"
""));
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        graphicsView_mapLayers->setBackgroundBrush(brush);
        label_currentPos = new QLabel(page);
        label_currentPos->setObjectName(QString::fromUtf8("label_currentPos"));
        label_currentPos->setGeometry(QRect(760, 480, 151, 31));
        label_currentPos->setFrameShape(QFrame::Box);
        label_currentPos->setFrameShadow(QFrame::Raised);
        label_currentPos->setAlignment(Qt::AlignCenter);
        pushButton_horn = new QPushButton(page);
        pushButton_horn->setObjectName(QString::fromUtf8("pushButton_horn"));
        pushButton_horn->setGeometry(QRect(565, 480, 90, 90));
        pushButton_horn->setStyleSheet(QString::fromUtf8("image: url(:/image/horn.png);\n"
"border-radius: 5px;\n"
"background-color: rgba(243, 243, 243, 30)"));
        pushButton_frontLight = new QPushButton(page);
        pushButton_frontLight->setObjectName(QString::fromUtf8("pushButton_frontLight"));
        pushButton_frontLight->setGeometry(QRect(660, 480, 90, 90));
        pushButton_frontLight->setStyleSheet(QString::fromUtf8("image: url(:/image/light.png);\n"
"border-radius: 5px;\n"
"background-color: rgba(243, 243, 243, 30)"));
        pushButton_clearError = new QPushButton(page);
        pushButton_clearError->setObjectName(QString::fromUtf8("pushButton_clearError"));
        pushButton_clearError->setGeometry(QRect(660, 575, 90, 90));
        pushButton_clearError->setStyleSheet(QString::fromUtf8("image: url(:/image/clearError.png);\n"
"border-radius: 5px;\n"
"background-color: rgba(243, 243, 243, 30)"));
        groupBox_speedDisplay = new QGroupBox(page);
        groupBox_speedDisplay->setObjectName(QString::fromUtf8("groupBox_speedDisplay"));
        groupBox_speedDisplay->setGeometry(QRect(360, 525, 120, 120));
        groupBox_speedDisplay->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: rgba(243, 243, 243, 30)"));
        pushButton_Dir = new QPushButton(page);
        pushButton_Dir->setObjectName(QString::fromUtf8("pushButton_Dir"));
        pushButton_Dir->setEnabled(false);
        pushButton_Dir->setGeometry(QRect(565, 575, 90, 90));
        pushButton_Dir->setStyleSheet(QString::fromUtf8("image: url(:/image/dir.png);\n"
"border-radius: 5px;\n"
"background-color: rgba(243, 243, 243, 30)\n"
"\n"
"\n"
""));
        label_cirSpd = new QLabel(page);
        label_cirSpd->setObjectName(QString::fromUtf8("label_cirSpd"));
        label_cirSpd->setGeometry(QRect(360, 525, 120, 120));
        label_cirSpd->setStyleSheet(QString::fromUtf8("border-radius: 60px;\n"
"color: rgb(255, 255, 255);\n"
"font: 25 14pt \"Calibri Light\";\n"
"border:  2px solid rgb(69, 229, 139);\n"
"background-color: rgba(243, 243, 243, 0)"));
        label_dim = new QLabel(page);
        label_dim->setObjectName(QString::fromUtf8("label_dim"));
        label_dim->setGeometry(QRect(390, 600, 61, 31));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_dim->sizePolicy().hasHeightForWidth());
        label_dim->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setStyleStrategy(QFont::PreferAntialias);
        label_dim->setFont(font1);
        label_dim->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        label_dim->setAlignment(Qt::AlignCenter);
        label_speed = new QLabel(page);
        label_speed->setObjectName(QString::fromUtf8("label_speed"));
        label_speed->setGeometry(QRect(390, 550, 61, 51));
        sizePolicy.setHeightForWidth(label_speed->sizePolicy().hasHeightForWidth());
        label_speed->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(36);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setStyleStrategy(QFont::PreferAntialias);
        label_speed->setFont(font2);
        label_speed->setStyleSheet(QString::fromUtf8("font: 63 36pt \"Source Sans Pro SemiBold\";\n"
"background-color: rgba(255, 255, 255, 0);"));
        label_speed->setAlignment(Qt::AlignCenter);
        pushButton_speed = new QPushButton(page);
        pushButton_speed->setObjectName(QString::fromUtf8("pushButton_speed"));
        pushButton_speed->setGeometry(QRect(780, 520, 121, 41));
        QFont font3;
        font3.setPointSize(12);
        pushButton_speed->setFont(font3);
        pushButton_speed->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"border:  2px solid rgb(69, 229, 139);\n"
"background-color: rgba(255, 255, 255, 0);"));
        textEdit_speed = new QTextEdit(page);
        textEdit_speed->setObjectName(QString::fromUtf8("textEdit_speed"));
        textEdit_speed->setGeometry(QRect(920, 560, 51, 51));
        textEdit_speed->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 30);\n"
"color: rgb(255, 255, 255);\n"
"font: 25 10pt \"Calibri Light\";"));
        horizontalSlider_speed = new QSlider(page);
        horizontalSlider_speed->setObjectName(QString::fromUtf8("horizontalSlider_speed"));
        horizontalSlider_speed->setGeometry(QRect(760, 570, 151, 31));
        horizontalSlider_speed->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: rgba(243, 243, 243, 30)"));
        horizontalSlider_speed->setMinimum(-25);
        horizontalSlider_speed->setMaximum(25);
        horizontalSlider_speed->setOrientation(Qt::Horizontal);
        pushButton_turnSignalLeft = new QPushButton(page);
        pushButton_turnSignalLeft->setObjectName(QString::fromUtf8("pushButton_turnSignalLeft"));
        pushButton_turnSignalLeft->setGeometry(QRect(280, 525, 75, 120));
        pushButton_turnSignalLeft->setStyleSheet(QString::fromUtf8("image: url(:/image/turnLeft.png);\n"
"border-radius: 5px;\n"
"background-color: rgba(243, 243, 243, 30)"));
        pushButton_turnSignalRight = new QPushButton(page);
        pushButton_turnSignalRight->setObjectName(QString::fromUtf8("pushButton_turnSignalRight"));
        pushButton_turnSignalRight->setGeometry(QRect(485, 525, 75, 120));
        pushButton_turnSignalRight->setStyleSheet(QString::fromUtf8("image: url(:/image/turnRight.png);\n"
"border-radius: 5px;\n"
"background-color: rgba(243, 243, 243, 30)"));
        label_Straight = new QLabel(page);
        label_Straight->setObjectName(QString::fromUtf8("label_Straight"));
        label_Straight->setGeometry(QRect(360, 480, 120, 40));
        label_Straight->setStyleSheet(QString::fromUtf8("image: url(:/image/straight.png);\n"
"border-radius: 5px;\n"
"background-color: rgba(243, 243, 243, 30)"));
        label_Straight->setFrameShape(QFrame::Box);
        label_Left = new QLabel(page);
        label_Left->setObjectName(QString::fromUtf8("label_Left"));
        label_Left->setGeometry(QRect(280, 480, 75, 40));
        label_Left->setStyleSheet(QString::fromUtf8("image: url(:/image/left.png);\n"
"border-radius: 5px;\n"
"background-color: rgba(243, 243, 243, 30)"));
        label_Left->setFrameShape(QFrame::Box);
        label_Right = new QLabel(page);
        label_Right->setObjectName(QString::fromUtf8("label_Right"));
        label_Right->setGeometry(QRect(485, 480, 75, 40));
        label_Right->setStyleSheet(QString::fromUtf8("image: url(:/image/right.png);\n"
"border-radius: 5px;\n"
"background-color: rgba(243, 243, 243, 30)"));
        label_Right->setFrameShape(QFrame::Box);
        label_steeringWheel = new QLabel(page);
        label_steeringWheel->setObjectName(QString::fromUtf8("label_steeringWheel"));
        label_steeringWheel->setGeometry(QRect(310, 650, 221, 61));
        label_steeringWheel->setStyleSheet(QString::fromUtf8("image: url(:/image/steeringWheel.png);\n"
"border-radius: 30px;\n"
"border:  2px solid rgb(69, 229, 139);\n"
"background-color: rgba(243, 243, 243, 30);"));
        pushButton_autoRun = new QPushButton(page);
        pushButton_autoRun->setObjectName(QString::fromUtf8("pushButton_autoRun"));
        pushButton_autoRun->setGeometry(QRect(60, 480, 105, 105));
        pushButton_autoRun->setFont(font);
        pushButton_autoRun->setStyleSheet(QString::fromUtf8("border-radius: 20px;\n"
"border:  2px solid rgb(69, 229, 139);\n"
"background-color: rgba(243, 243, 243, 30)"));
        pushButton_start = new QPushButton(page);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setGeometry(QRect(170, 480, 105, 105));
        pushButton_start->setFont(font);
        pushButton_start->setAutoFillBackground(false);
        pushButton_start->setStyleSheet(QString::fromUtf8("border-radius: 20px;\n"
"border:  2px solid rgb(69, 229, 139);\n"
"background-color: rgba(243, 243, 243, 30)"));
        pushButton_stop = new QPushButton(page);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(170, 590, 105, 105));
        pushButton_stop->setFont(font);
        pushButton_stop->setStyleSheet(QString::fromUtf8("border-radius: 20px;\n"
"border:  2px solid rgb(69, 229, 139);\n"
"background-color: rgba(243, 243, 243, 30);\n"
""));
        pushButton_steeringLeft = new QPushButton(page);
        pushButton_steeringLeft->setObjectName(QString::fromUtf8("pushButton_steeringLeft"));
        pushButton_steeringLeft->setGeometry(QRect(320, 660, 40, 40));
        pushButton_steeringLeft->setStyleSheet(QString::fromUtf8("image: url(:/image/minusSteering.png);\n"
"border-radius: 20px;\n"
"background-color: rgba(243, 243, 243, 30)"));
        pushButton_steeringRight = new QPushButton(page);
        pushButton_steeringRight->setObjectName(QString::fromUtf8("pushButton_steeringRight"));
        pushButton_steeringRight->setGeometry(QRect(480, 660, 40, 40));
        pushButton_steeringRight->setStyleSheet(QString::fromUtf8("image: url(:/image/plusSteering.png);\n"
"border-radius: 20px;\n"
"background-color: rgba(243, 243, 243, 30);"));
        label_steering = new QLabel(page);
        label_steering->setObjectName(QString::fromUtf8("label_steering"));
        label_steering->setGeometry(QRect(920, 620, 71, 31));
        pushButton_resetPos = new QPushButton(page);
        pushButton_resetPos->setObjectName(QString::fromUtf8("pushButton_resetPos"));
        pushButton_resetPos->setGeometry(QRect(540, 660, 16, 16));
        pushButton_resetPos->setStyleSheet(QString::fromUtf8("background-color: #ff0000;\n"
"border-radius: 4px;\n"
"\n"
"\n"
""));
        graphicsView_radarScan = new QGraphicsView(page);
        graphicsView_radarScan->setObjectName(QString::fromUtf8("graphicsView_radarScan"));
        graphicsView_radarScan->setGeometry(QRect(755, 10, 250, 460));
        graphicsView_radarScan->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-radius: 10px;\n"
"border: 5px solid rgb(75, 85, 117);\n"
""));
        lblVel = new QLabel(page);
        lblVel->setObjectName(QString::fromUtf8("lblVel"));
        lblVel->setGeometry(QRect(920, 505, 61, 31));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(false);
        font4.setItalic(false);
        lblVel->setFont(font4);
        lblVel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font:100 10pt \"Source Sans Pro SemiBold\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
""));
        lblTTC = new QLabel(page);
        lblTTC->setObjectName(QString::fromUtf8("lblTTC"));
        lblTTC->setGeometry(QRect(920, 475, 51, 31));
        lblTTC->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"font: 100 10pt \"Source Sans Pro SemiBold\";\n"
"background-color: rgba(255, 255, 255, 0);"));
        label_SPSpeed = new QLabel(page);
        label_SPSpeed->setObjectName(QString::fromUtf8("label_SPSpeed"));
        label_SPSpeed->setGeometry(QRect(920, 530, 71, 31));
        label_Dir = new QLabel(page);
        label_Dir->setObjectName(QString::fromUtf8("label_Dir"));
        label_Dir->setGeometry(QRect(380, 730, 81, 31));
        pushButton_steering = new QPushButton(page);
        pushButton_steering->setObjectName(QString::fromUtf8("pushButton_steering"));
        pushButton_steering->setGeometry(QRect(780, 610, 121, 41));
        pushButton_steering->setFont(font3);
        pushButton_steering->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"border:  2px solid rgb(69, 229, 139);\n"
"background-color: rgba(255, 255, 255, 0);"));
        horizontalSlider_steering = new QSlider(page);
        horizontalSlider_steering->setObjectName(QString::fromUtf8("horizontalSlider_steering"));
        horizontalSlider_steering->setGeometry(QRect(764, 660, 151, 31));
        horizontalSlider_steering->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: rgba(243, 243, 243, 30)"));
        horizontalSlider_steering->setMinimum(-70);
        horizontalSlider_steering->setMaximum(70);
        horizontalSlider_steering->setSingleStep(2);
        horizontalSlider_steering->setOrientation(Qt::Horizontal);
        pushButton_autoSteering = new QPushButton(page);
        pushButton_autoSteering->setObjectName(QString::fromUtf8("pushButton_autoSteering"));
        pushButton_autoSteering->setGeometry(QRect(60, 590, 105, 105));
        pushButton_autoSteering->setFont(font);
        pushButton_autoSteering->setStyleSheet(QString::fromUtf8("border-radius: 20px;\n"
"border:  2px solid rgb(69, 229, 139);\n"
"background-color: rgba(243, 243, 243, 30)"));
        label_destination = new QLabel(page);
        label_destination->setObjectName(QString::fromUtf8("label_destination"));
        label_destination->setGeometry(QRect(760, 20, 301, 31));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(false);
        font5.setItalic(false);
        label_destination->setFont(font5);
        label_destination->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(40, 133, 80);\n"
"font: 100 12pt \"Source Sans Pro SemiBold\";\n"
"background-color: rgba(255, 255, 255, 0);"));
        label_checkDes = new QLabel(page);
        label_checkDes->setObjectName(QString::fromUtf8("label_checkDes"));
        label_checkDes->setGeometry(QRect(980, 490, 63, 20));
        pushButton_open = new QPushButton(page);
        pushButton_open->setObjectName(QString::fromUtf8("pushButton_open"));
        pushButton_open->setGeometry(QRect(940, 660, 81, 31));
        pushButton_open->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"color: rgb(255, 255, 255);\n"
"font: 25 13pt \"Calibri Light\";\n"
"border:  2px solid rgb(69, 229, 139);\n"
"background-color: rgba(255, 255, 255, 0);"));
        label_pixel = new QLabel(page);
        label_pixel->setObjectName(QString::fromUtf8("label_pixel"));
        label_pixel->setGeometry(QRect(980, 520, 81, 31));
        comboBox_comUart = new QComboBox(page);
        comboBox_comUart->setObjectName(QString::fromUtf8("comboBox_comUart"));
        comboBox_comUart->setGeometry(QRect(940, 700, 79, 25));
        comboBox_comUart->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"color: rgb(255, 255, 255);\n"
"font: 25 10pt \"Calibri Light\";\n"
"border:  2px solid rgb(69, 229, 139);\n"
"background-color: rgba(255, 255, 255, 0);"));
        stackedWidget->addWidget(page);
        groupBox_speedDisplay->raise();
        label->raise();
        pushButton_pageB->raise();
        pushButton_pageN->raise();
        graphicsView_mapLayers->raise();
        label_currentPos->raise();
        pushButton_horn->raise();
        pushButton_frontLight->raise();
        pushButton_clearError->raise();
        pushButton_Dir->raise();
        label_cirSpd->raise();
        label_dim->raise();
        label_speed->raise();
        pushButton_speed->raise();
        textEdit_speed->raise();
        horizontalSlider_speed->raise();
        pushButton_turnSignalLeft->raise();
        pushButton_turnSignalRight->raise();
        label_Straight->raise();
        label_Left->raise();
        label_Right->raise();
        label_steeringWheel->raise();
        pushButton_autoRun->raise();
        pushButton_start->raise();
        pushButton_stop->raise();
        pushButton_steeringLeft->raise();
        pushButton_steeringRight->raise();
        label_steering->raise();
        pushButton_resetPos->raise();
        graphicsView_radarScan->raise();
        lblVel->raise();
        lblTTC->raise();
        label_SPSpeed->raise();
        label_Dir->raise();
        pushButton_steering->raise();
        horizontalSlider_steering->raise();
        pushButton_autoSteering->raise();
        label_destination->raise();
        label_checkDes->raise();
        pushButton_open->raise();
        label_pixel->raise();
        comboBox_comUart->raise();
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        pushButton_page2B = new QPushButton(page_2);
        pushButton_page2B->setObjectName(QString::fromUtf8("pushButton_page2B"));
        pushButton_page2B->setGeometry(QRect(0, 0, 41, 751));
        pushButton_page2B->setStyleSheet(QString::fromUtf8("image: url(:/NextAndBack/back.png);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border:  0px;"));
        pushButton_page2N = new QPushButton(page_2);
        pushButton_page2N->setObjectName(QString::fromUtf8("pushButton_page2N"));
        pushButton_page2N->setGeometry(QRect(1030, 0, 41, 751));
        pushButton_page2N->setStyleSheet(QString::fromUtf8("image: url(:/NextAndBack/next.png);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border:  0px;"));
        groupBox_2 = new QGroupBox(page_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(280, 30, 441, 71));
        groupBox_2->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"background-color: rgba(243, 243, 243, 30)"));
        comboBox_Interface = new QComboBox(groupBox_2);
        comboBox_Interface->setObjectName(QString::fromUtf8("comboBox_Interface"));
        comboBox_Interface->setGeometry(QRect(10, 30, 100, 30));
        sizePolicy.setHeightForWidth(comboBox_Interface->sizePolicy().hasHeightForWidth());
        comboBox_Interface->setSizePolicy(sizePolicy);
        comboBox_Interface->setMinimumSize(QSize(100, 0));
        comboBox_Interface->setMaximumSize(QSize(200, 16777215));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(120, 30, 30, 30));
        label_4->setStyleSheet(QString::fromUtf8("border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 0px;"));
        label_4->setAlignment(Qt::AlignCenter);
        label_LocalIP = new QLabel(groupBox_2);
        label_LocalIP->setObjectName(QString::fromUtf8("label_LocalIP"));
        label_LocalIP->setGeometry(QRect(150, 30, 150, 30));
        label_LocalIP->setStyleSheet(QString::fromUtf8("border-top-left-radius: 0px;\n"
"border-bottom-left-radius: 0px;"));
        button_Refresh = new QPushButton(groupBox_2);
        button_Refresh->setObjectName(QString::fromUtf8("button_Refresh"));
        button_Refresh->setGeometry(QRect(337, 30, 91, 30));
        button_Refresh->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"color: rgb(255, 255, 255);\n"
"font: 25 13pt \"Calibri Light\";\n"
"border:  2px solid rgb(69, 229, 139);\n"
"background-color: rgba(255, 255, 255, 0);"));
        groupBox_message = new QGroupBox(page_2);
        groupBox_message->setObjectName(QString::fromUtf8("groupBox_message"));
        groupBox_message->setGeometry(QRect(279, 189, 441, 391));
        groupBox_message->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"background-color: rgba(243, 243, 243, 30)"));
        textBrowser_TcpClientMessage = new QTextBrowser(groupBox_message);
        textBrowser_TcpClientMessage->setObjectName(QString::fromUtf8("textBrowser_TcpClientMessage"));
        textBrowser_TcpClientMessage->setGeometry(QRect(0, 30, 441, 311));
        textBrowser_TcpClientMessage->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
""));
        label_topic = new QLabel(groupBox_message);
        label_topic->setObjectName(QString::fromUtf8("label_topic"));
        label_topic->setGeometry(QRect(0, 350, 50, 30));
        label_topic->setStyleSheet(QString::fromUtf8("border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 0px;"));
        label_topic->setAlignment(Qt::AlignCenter);
        comboBox_topic = new QComboBox(groupBox_message);
        comboBox_topic->setObjectName(QString::fromUtf8("comboBox_topic"));
        comboBox_topic->setGeometry(QRect(50, 350, 110, 30));
        comboBox_topic->setStyleSheet(QString::fromUtf8("border-top-left-radius: 0px;\n"
"border-bottom-left-radius: 0px;"));
        comboBox_topic->setEditable(false);
        button_TcpClientSend = new QPushButton(groupBox_message);
        button_TcpClientSend->setObjectName(QString::fromUtf8("button_TcpClientSend"));
        button_TcpClientSend->setGeometry(QRect(170, 350, 161, 30));
        button_TcpClientSend->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"color: rgb(255, 255, 255);\n"
"font: 25 14pt \"Calibri Light\";\n"
"border:  2px solid rgb(69, 229, 139);\n"
"background-color: rgba(255, 255, 255, 0);"));
        groupBox_clientConnect = new QGroupBox(page_2);
        groupBox_clientConnect->setObjectName(QString::fromUtf8("groupBox_clientConnect"));
        groupBox_clientConnect->setGeometry(QRect(280, 110, 441, 71));
        groupBox_clientConnect->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"background-color: rgba(243, 243, 243, 30)"));
        label_targetIP = new QLabel(groupBox_clientConnect);
        label_targetIP->setObjectName(QString::fromUtf8("label_targetIP"));
        label_targetIP->setGeometry(QRect(10, 30, 30, 30));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_targetIP->sizePolicy().hasHeightForWidth());
        label_targetIP->setSizePolicy(sizePolicy1);
        label_targetIP->setMinimumSize(QSize(0, 0));
        label_targetIP->setBaseSize(QSize(0, 0));
        label_targetIP->setStyleSheet(QString::fromUtf8("border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 0px;"));
        label_targetIP->setAlignment(Qt::AlignCenter);
        lineEdit_TcpClientTargetIP = new QLineEdit(groupBox_clientConnect);
        lineEdit_TcpClientTargetIP->setObjectName(QString::fromUtf8("lineEdit_TcpClientTargetIP"));
        lineEdit_TcpClientTargetIP->setGeometry(QRect(40, 30, 150, 30));
        lineEdit_TcpClientTargetIP->setMinimumSize(QSize(150, 0));
        lineEdit_TcpClientTargetIP->setMaximumSize(QSize(200, 16777215));
        lineEdit_TcpClientTargetIP->setStyleSheet(QString::fromUtf8("border-top-left-radius: 0px;\n"
"border-bottom-left-radius: 0px;"));
        label_targetPort = new QLabel(groupBox_clientConnect);
        label_targetPort->setObjectName(QString::fromUtf8("label_targetPort"));
        label_targetPort->setGeometry(QRect(200, 30, 40, 30));
        sizePolicy1.setHeightForWidth(label_targetPort->sizePolicy().hasHeightForWidth());
        label_targetPort->setSizePolicy(sizePolicy1);
        label_targetPort->setMinimumSize(QSize(0, 0));
        label_targetPort->setStyleSheet(QString::fromUtf8("border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 0px;"));
        label_targetPort->setAlignment(Qt::AlignCenter);
        lineEdit_TcpClientTargetPort = new QLineEdit(groupBox_clientConnect);
        lineEdit_TcpClientTargetPort->setObjectName(QString::fromUtf8("lineEdit_TcpClientTargetPort"));
        lineEdit_TcpClientTargetPort->setGeometry(QRect(240, 30, 80, 30));
        lineEdit_TcpClientTargetPort->setMinimumSize(QSize(80, 0));
        lineEdit_TcpClientTargetPort->setMaximumSize(QSize(80, 16777215));
        lineEdit_TcpClientTargetPort->setStyleSheet(QString::fromUtf8("border-top-left-radius: 0px;\n"
"border-bottom-left-radius: 0px;"));
        button_TcpClient = new QPushButton(groupBox_clientConnect);
        button_TcpClient->setObjectName(QString::fromUtf8("button_TcpClient"));
        button_TcpClient->setGeometry(QRect(340, 30, 91, 31));
        button_TcpClient->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"color: rgb(255, 255, 255);\n"
"font: 25 13pt \"Calibri Light\";\n"
"border:  2px solid rgb(69, 229, 139);\n"
"background-color: rgba(255, 255, 255, 0);"));
        lineEdit_TcpClientSend = new QLineEdit(page_2);
        lineEdit_TcpClientSend->setObjectName(QString::fromUtf8("lineEdit_TcpClientSend"));
        lineEdit_TcpClientSend->setGeometry(QRect(280, 590, 441, 25));
        lineEdit_TcpClientSend->setMinimumSize(QSize(241, 25));
        lineEdit_TcpClientSend->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"background-color: rgba(243, 243, 243, 30)"));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 730, 121, 31));
        label_2->setStyleSheet(QString::fromUtf8(""));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        label_3 = new QLabel(page_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 750, 63, 20));
        pushButton_page3B = new QPushButton(page_3);
        pushButton_page3B->setObjectName(QString::fromUtf8("pushButton_page3B"));
        pushButton_page3B->setGeometry(QRect(0, 0, 41, 751));
        pushButton_page3B->setStyleSheet(QString::fromUtf8("image: url(:/NextAndBack/back.png);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border:  0px;"));
        pushButton_page3N = new QPushButton(page_3);
        pushButton_page3N->setObjectName(QString::fromUtf8("pushButton_page3N"));
        pushButton_page3N->setGeometry(QRect(1030, 0, 41, 751));
        pushButton_page3N->setStyleSheet(QString::fromUtf8("image: url(:/NextAndBack/next.png);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border:  0px;"));
        groupBox_3 = new QGroupBox(page_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(110, 10, 221, 171));
        QFont font6;
        font6.setPointSize(14);
        font6.setBold(false);
        font6.setItalic(false);
        groupBox_3->setFont(font6);
        groupBox_3->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: rgba(243, 243, 243, 30)"));
        comboBox_NMEA = new QComboBox(groupBox_3);
        comboBox_NMEA->setObjectName(QString::fromUtf8("comboBox_NMEA"));
        comboBox_NMEA->setGeometry(QRect(10, 40, 81, 31));
        comboBox_NMEA->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"color: rgb(255, 255, 255);\n"
"font: 25 10pt \"Calibri Light\";\n"
"border:  2px solid rgb(69, 229, 139);\n"
"background-color: rgba(255, 255, 255, 0);"));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 10, 71, 25));
        QFont font7;
        font7.setPointSize(13);
        font7.setBold(false);
        font7.setItalic(false);
        label_5->setFont(font7);
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"font: 25 13pt \"Calibri Light\";"));
        label_5->setAlignment(Qt::AlignCenter);
        pushButton_ctrlNMEA = new QPushButton(groupBox_3);
        pushButton_ctrlNMEA->setObjectName(QString::fromUtf8("pushButton_ctrlNMEA"));
        pushButton_ctrlNMEA->setGeometry(QRect(100, 40, 101, 31));
        pushButton_ctrlNMEA->setFont(font7);
        pushButton_ctrlNMEA->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"color: rgb(255, 255, 255);\n"
"font: 25 13pt \"Calibri Light\";\n"
"border:  2px solid rgb(69, 229, 139);\n"
"background-color: rgba(255, 255, 255, 0);"));
        comboBox_FREQ = new QComboBox(groupBox_3);
        comboBox_FREQ->setObjectName(QString::fromUtf8("comboBox_FREQ"));
        comboBox_FREQ->setGeometry(QRect(10, 80, 81, 31));
        comboBox_FREQ->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"color: rgb(255, 255, 255);\n"
"font: 25 10pt \"Calibri Light\";\n"
"border:  2px solid rgb(69, 229, 139);\n"
"background-color: rgba(255, 255, 255, 0);"));
        pushButton_cfgFrq = new QPushButton(groupBox_3);
        pushButton_cfgFrq->setObjectName(QString::fromUtf8("pushButton_cfgFrq"));
        pushButton_cfgFrq->setGeometry(QRect(110, 80, 81, 31));
        pushButton_cfgFrq->setFont(font7);
        pushButton_cfgFrq->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"color: rgb(255, 255, 255);\n"
"font: 25 13pt \"Calibri Light\";\n"
"border:  2px solid rgb(69, 229, 139);\n"
"background-color: rgba(255, 255, 255, 0);"));
        pushButton_close = new QPushButton(groupBox_3);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setGeometry(QRect(110, 120, 81, 31));
        pushButton_close->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"color: rgb(255, 255, 255);\n"
"font: 25 13pt \"Calibri Light\";\n"
"border:  2px solid rgb(69, 229, 139);\n"
"background-color: rgba(255, 255, 255, 0);"));
        label_UART = new QLabel(groupBox_3);
        label_UART->setObjectName(QString::fromUtf8("label_UART"));
        label_UART->setGeometry(QRect(200, 10, 16, 16));
        label_UART->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 4px;"));
        label_UART->setFrameShape(QFrame::Box);
        groupBox = new QGroupBox(page_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(120, 290, 811, 321));
        groupBox->setFont(font3);
        groupBox->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: rgba(243, 243, 243, 30)"));
        pushButton_svSteeringON = new QPushButton(groupBox);
        pushButton_svSteeringON->setObjectName(QString::fromUtf8("pushButton_svSteeringON"));
        pushButton_svSteeringON->setGeometry(QRect(180, 50, 141, 31));
        pushButton_svSteeringON->setFont(font7);
        pushButton_svSteeringON->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"color: rgb(255, 255, 255);\n"
"font: 25 13pt \"Calibri Light\";\n"
"border:  2px solid rgb(69, 229, 139);\n"
"background-color: rgba(255, 255, 255, 0);"));
        pushButton_svSteeringOFF = new QPushButton(groupBox);
        pushButton_svSteeringOFF->setObjectName(QString::fromUtf8("pushButton_svSteeringOFF"));
        pushButton_svSteeringOFF->setGeometry(QRect(350, 50, 141, 31));
        pushButton_svSteeringOFF->setFont(font7);
        pushButton_svSteeringOFF->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"color: rgb(255, 255, 255);\n"
"font: 25 13pt \"Calibri Light\";\n"
"border:  2px solid rgb(69, 229, 139);\n"
"background-color: rgba(255, 255, 255, 0);"));
        plainTextEdit = new QPlainTextEdit(groupBox);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(80, 120, 631, 151));
        pushButton_closeSV = new QPushButton(groupBox);
        pushButton_closeSV->setObjectName(QString::fromUtf8("pushButton_closeSV"));
        pushButton_closeSV->setGeometry(QRect(700, 60, 81, 31));
        pushButton_closeSV->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"color: rgb(255, 255, 255);\n"
"font: 25 13pt \"Calibri Light\";\n"
"border:  2px solid rgb(69, 229, 139);\n"
"background-color: rgba(255, 255, 255, 0);"));
        comboBox_comServo = new QComboBox(groupBox);
        comboBox_comServo->setObjectName(QString::fromUtf8("comboBox_comServo"));
        comboBox_comServo->setGeometry(QRect(600, 20, 79, 25));
        comboBox_comServo->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"color: rgb(255, 255, 255);\n"
"font: 25 10pt \"Calibri Light\";\n"
"border:  2px solid rgb(69, 229, 139);\n"
"background-color: rgba(255, 255, 255, 0);"));
        pushButton_openSV = new QPushButton(groupBox);
        pushButton_openSV->setObjectName(QString::fromUtf8("pushButton_openSV"));
        pushButton_openSV->setGeometry(QRect(600, 60, 81, 31));
        pushButton_openSV->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"color: rgb(255, 255, 255);\n"
"font: 25 13pt \"Calibri Light\";\n"
"border:  2px solid rgb(69, 229, 139);\n"
"background-color: rgba(255, 255, 255, 0);"));
        label_serialSV = new QLabel(groupBox);
        label_serialSV->setObjectName(QString::fromUtf8("label_serialSV"));
        label_serialSV->setGeometry(QRect(760, 20, 16, 16));
        label_serialSV->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 4px;"));
        label_serialSV->setFrameShape(QFrame::Box);
        stackedWidget->addWidget(page_3);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Car Dashboard", nullptr));
        label->setText(QApplication::translate("MainWindow", "1", nullptr));
        pushButton_pageB->setText(QString());
        pushButton_pageN->setText(QString());
        label_currentPos->setText(QApplication::translate("MainWindow", "X = 0, Y = 0", nullptr));
        pushButton_horn->setText(QString());
        pushButton_frontLight->setText(QString());
        pushButton_clearError->setText(QString());
        groupBox_speedDisplay->setTitle(QString());
        pushButton_Dir->setText(QString());
        label_cirSpd->setText(QString());
        label_dim->setText(QApplication::translate("MainWindow", "km/h", nullptr));
        label_speed->setText(QApplication::translate("MainWindow", "0", nullptr));
        pushButton_speed->setText(QApplication::translate("MainWindow", "RS Speed", nullptr));
        pushButton_turnSignalLeft->setText(QString());
        pushButton_turnSignalRight->setText(QString());
        label_Straight->setText(QString());
        label_Left->setText(QString());
        label_Right->setText(QString());
        label_steeringWheel->setText(QString());
        pushButton_autoRun->setText(QApplication::translate("MainWindow", "AUTO", nullptr));
        pushButton_start->setText(QApplication::translate("MainWindow", "START", nullptr));
        pushButton_stop->setText(QApplication::translate("MainWindow", "STOP", nullptr));
        pushButton_steeringLeft->setText(QString());
        pushButton_steeringRight->setText(QString());
        label_steering->setText(QApplication::translate("MainWindow", "Steering", nullptr));
        pushButton_resetPos->setText(QString());
        lblVel->setText(QApplication::translate("MainWindow", "TTC", nullptr));
        lblTTC->setText(QApplication::translate("MainWindow", "TTC", nullptr));
        label_SPSpeed->setText(QApplication::translate("MainWindow", "SPSpd", nullptr));
        label_Dir->setText(QApplication::translate("MainWindow", "Dir", nullptr));
        pushButton_steering->setText(QApplication::translate("MainWindow", "RS Steering", nullptr));
        pushButton_autoSteering->setText(QApplication::translate("MainWindow", "STEERING", nullptr));
        label_destination->setText(QApplication::translate("MainWindow", "Destination", nullptr));
        label_checkDes->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_open->setText(QApplication::translate("MainWindow", "OPEN", nullptr));
        label_pixel->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_page2B->setText(QString());
        pushButton_page2N->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Network Interface", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "IP: ", nullptr));
        label_LocalIP->setText(QApplication::translate("MainWindow", "255.255.255.255", nullptr));
        button_Refresh->setText(QApplication::translate("MainWindow", "Refresh", nullptr));
        groupBox_message->setTitle(QApplication::translate("MainWindow", "Message", nullptr));
        label_topic->setText(QApplication::translate("MainWindow", "Topic:", nullptr));
        button_TcpClientSend->setText(QApplication::translate("MainWindow", "Subcribe topic", nullptr));
        groupBox_clientConnect->setTitle(QApplication::translate("MainWindow", "Client Connect to", nullptr));
        label_targetIP->setText(QApplication::translate("MainWindow", "IP:", nullptr));
        label_targetPort->setText(QApplication::translate("MainWindow", "Port:", nullptr));
        button_TcpClient->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "2", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "3", nullptr));
        pushButton_page3B->setText(QString());
        pushButton_page3N->setText(QString());
        groupBox_3->setTitle(QString());
        label_5->setText(QApplication::translate("MainWindow", "NMEA", nullptr));
        pushButton_ctrlNMEA->setText(QApplication::translate("MainWindow", "DISABLE", nullptr));
        pushButton_cfgFrq->setText(QApplication::translate("MainWindow", "SEND", nullptr));
        pushButton_close->setText(QApplication::translate("MainWindow", "CLOSE", nullptr));
        label_UART->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "Steering Driver Control", nullptr));
        pushButton_svSteeringON->setText(QApplication::translate("MainWindow", "SERVO ON", nullptr));
        pushButton_svSteeringOFF->setText(QApplication::translate("MainWindow", "SERVO OFF", nullptr));
        pushButton_closeSV->setText(QApplication::translate("MainWindow", "CLOSE", nullptr));
        pushButton_openSV->setText(QApplication::translate("MainWindow", "OPEN", nullptr));
        label_serialSV->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
