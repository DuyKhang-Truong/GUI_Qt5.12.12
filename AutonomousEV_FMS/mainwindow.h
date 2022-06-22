#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>

#include <QMessageBox>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include <QtMath>
#include <QThread>
#include <numeric>

#include <QSettings>
#include <QList>
#include <QNetworkInterface>
#include "json.h"
#include "mytcpclient.h"

#include <iostream>
#include <numeric>
#include "astaralgorithm.h"




using namespace std;

#define iconScale 30
#define halfWidthIcon 15

#define MAXSPEED 20
#define MINSPEED 0

#define TIMEOUTRxGPS 200

#define SAMPLES 15
#define positiveLim 30
#define negativeLim -30
#define STRAIGHTSPEED 10
#define TURNSPEED 7

#define TCPCLIENT 20
#define TCPTIMERTIMEOUT 100

#define SERVERTIMEOUT 5000

#define CHECKDESTINATIONTIM 100
#define DESTINATIONAREA 17
#define CUSTOMERWAITINGTIMEOUT 8000

#define STEERINGTIM 200

struct controlData
{
    quint32 msg_counter;
    bool userReqAutoRun;
    bool userReqStart;
    bool userReqStop;
    bool clearError;
    qint16 speedSetpoint;
    unsigned char turnSignal;
    bool horn;
    bool frontLight;
    unsigned char steeringLeftRight;
    float previewCurvature;
};

union receiveSpeedFromEPC
{
    float myFloat;
    uint8_t myByte[4];
};

union steeringPosition
{
    float myFloat;
    uint8_t byteArray[4];
};

struct cofigGPS
{
    bool temp_cofigGPS;
};


struct co_ordinatesInfo
{
    float lat;
    float lng;
    float vel;
};

struct co_ordinatesXY
{
    int xLng;
    int yLat;
};

struct textLat_Lng
{
    string Lat;
    string Lon;
};

struct gps_analysis_param
{
    string token;
    int pos;
    int cnt;
    int degLat;
    int degLng;
    double minLat;
    double minLng;
    double speed;
    double course;
};

union DoubleToByte{
 double myDouble;
 uint8_t myByte[8];
};

struct linearRegression
{
    double slope;
    double yIntercept;
    double regressionCoefficient;
    double k1;
    double k2;
    double angle;
    vector<int> xSample;
    vector<int> ySample;
};

struct path_Planning
{
    int distancePred;
    int predictPoint[2];
};


struct vVector
{
    double velocityVector;
    int scaleVectorV;
};

struct radarData
{
    uint8_t numObj;
    vector<uint8_t> IdObj;
    vector<bool> isApproach;
    vector<float> alpha;
    vector<float> posX;
    vector<float> posY;
    vector<float> dis;
    vector<float> vel;
    vector<float> ttc;
    vector<string> safetyZone;

    uint32_t msg_counter;
    bool isObject;
    float distance;

};

struct statusVehicle
{
    char statusVehicleFlag[1];
};

struct customerInfo
{
    bool customerInProccess;
    int xA;
    int yA;
    bool xyA_Ok;
    int xB;
    int yB;
    bool xyB_Ok;
};

enum checkCarState
{
    Stop,
    Running
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Ui::MainWindow *ui;

    node Node;

    mapPic mapPicDorm;

    astar_parameter astarParam;

    path_parameter pathParam;

    controlData controlDataQt = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    receiveSpeedFromEPC rcSpdFromEPC = {0};

    cofigGPS NMEACof = {0};

    co_ordinatesInfo rawLocation = {0, 0, 0};
    gps_analysis_param gpsAnalysisParam = {"GP", 0, 0, 0, 0, 0, 0, 0, 0};
    co_ordinatesXY xyLocation = {0, 0};

    QString myServer = "https://fleetmonitoring.000webhostapp.com/createGPSdata.php";

    DoubleToByte doubleToByte;

    linearRegression linearParam = {0, 0, 0, 0, 0, 0};

    path_Planning pathPlanning = {100};

    statusVehicle StatusVehicle = {'S'};

    checkCarState CheckCarState = {Stop};

    vVector drawVelocityVector {50, 2};

    radarData ttcRadar;


    textLat_Lng postPos = {"123", "123"};

    steeringPosition SteeringPosition;

    customerInfo CustomerInfor = {false, 0, 0, false, 0, 0, false};

    void displayGUI(mapPic mapPicDorm);

    void makePath();

    void findClosePointS(int x, int y, path_parameter &pathParam);

    void findClosePointE(int x, int y, path_parameter &pathParam);

    void findClosePointInPath(int x, int y);

protected:

    void GPGLL_analysis(string raw_data);

    void checkCarBooking(string carBookingData);

    void getDataFromServer(string raw_SVdata);

    bool LinearRegress();

    void calcAngle();

private slots:

    void receiveSerialData();

    void setPath();

    void customerStartMoving();

    void checkDestination();

    void postDataToServer();

    void showMousePosition(QPoint& pos, QPoint& delta);

    void showMousePress(QPoint& pos, QPoint& delta);

    void showMouseDoubleClick(QPoint& pos, QPoint& delta);

    void on_pushButton_pageB_clicked();

    void on_pushButton_pageN_clicked();

    void on_pushButton_page2B_clicked();

    void on_pushButton_page2N_clicked();

    void on_pushButton_page3B_clicked();

    void on_pushButton_page3N_clicked();

    void on_pushButton_Dir_clicked();

    void on_pushButton_resetPos_clicked();

    void on_pushButton_autoRun_clicked();

    void on_pushButton_start_clicked();

    void controlStartBT();

    void on_pushButton_stop_clicked();

    void on_pushButton_turnSignalLeft_clicked();

    void on_pushButton_turnSignalRight_clicked();

    void on_pushButton_horn_clicked();

    void on_pushButton_frontLight_clicked();

    void on_pushButton_clearError_clicked();

    void on_horizontalSlider_speed_valueChanged(int value);

    void on_textEdit_speed_textChanged();

    void on_pushButton_speed_clicked();

    void on_pushButton_ctrlNMEA_clicked();

    void on_pushButton_cfgFrq_clicked();

    void on_pushButton_open_clicked();

    void on_pushButton_close_clicked();


    /****TCP****/
    void on_button_Refresh_clicked();

    void onTcpClientButtonClicked();

    void onTcpClientStopButtonClicked();

    void onTcpClientDisconnectButtonClicked();

    void Add_Message_To_Box(const QString &from, const QString &message);

    void onTcpClientNewConnection(const QString &from, quint16 port);

    void onTcpClientDisconnected();

    void onTcpClientSendMessage();

    void onTcpClientAppendMessage(const QString &from, const QString &message);

    void onTcpClientTimeOut();

    void user_Timer_Timeout();


    /****SteeringServoControl****/

    void SetSteeringDriverPos(float SteeringSet);

    void manualSteeringControlTimer();

    void on_pushButton_steering_clicked();

    void on_pushButton_autoSteering_clicked();

    void on_pushButton_openSV_clicked();

    void on_pushButton_closeSV_clicked();

    unsigned char CalcCRC(unsigned char uCode, unsigned char uSize, unsigned char buffer[]);

    void on_pushButton_svSteeringON_clicked();

    void on_pushButton_svSteeringOFF_clicked();

    void on_pushButton_steeringLeft_clicked();

    void on_pushButton_steeringRight_clicked();

    void on_horizontalSlider_steering_valueChanged(int value);

private:

    void fillPort();

    void fillPortServo();

    void initUI();

    void loadSettings();

    void saveSettings();

    void findLocalIPs();

    bool setupConnection(quint8 type);

    QString settingsFileDir;
    QList<QNetworkInterface> interfaceList;
    QHostAddress localAddr;
    QHostAddress tcpClientTargetAddr;
    quint16 tcpClientTargetPort;
    MyTCPClient *mytcpclient = nullptr;
    QTimer *TCP_Timer;
    quint8 type;
    QString messageTCP = "[TCP] ";

    QTimer *serverTimer, *startBTTimer;

    QGraphicsScene *graphic;
    QGraphicsPixmapItem *GPSmarker, *markerA, *markerB, *mapLayer;

    QTimer *Uart_timer, *destinationTimer, *ServoTimer, *CustomerWaitingTimer;
    QSerialPort *serialPort, *ServoSerialPort;



};
#include "radarscan.h"
#endif // MAINWINDOW_H
