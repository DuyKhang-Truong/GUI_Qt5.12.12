#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ROS_AEV.h"
#include "accesstonet.h"
//#include "radarscan.h"

using QtJson::JsonObject;

GUI_Control_Data GUIControlData = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

AccessToNet accessToNet;
int inc = 1;
double timeDes = 0;
bool startPathPlanning = false;

const float PI = 3.141592653f;
const float STEERING_FACTOR = 10 * 2 * PI * 46 / 20 * 1.5f;
bool AutoSteering_Flag = false;

float currentSteeringPosition_Setpoint = 0.0f;

const unsigned char MTR_PROTOCOL_CODE_EXECUTE_CMD = 0x03;
const unsigned char MTR_PROTOCOL_CODE_SET_REG = 0x01;
const unsigned char MTR_PROTOCOL_CMD_SERVO_ON = 0x01;
const unsigned char MTR_PROTOCOL_CMD_SERVO_OFF = 0x02;
const unsigned char MTR_PROTOCOL_REG_POSITION_REF = 93;
const unsigned char MTR_PROTOCOL_REG_POSITION_MODE = 98;
const unsigned char MTR_POS_STEP = (1);
const unsigned char MTR_REF_POS_ABS = 0;
const unsigned char MTR_PROTOCOL_REG_BASE_CURRENT = 62;

bool SteeringMotor_Init_Finish = false;

/*cofig frame GPS*/
const unsigned char txbuff_cofGPS1N[] = {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x04, 0x00, 0xFE, 0x17};
const unsigned char txbuff_cofGPS2N[] = {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x05, 0x00, 0xFF, 0x19};
const unsigned char txbuff_cofGPS3N[] = {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x00, 0x00, 0xFA, 0x0F};
const unsigned char txbuff_cofGPS4N[] = {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x02, 0x00, 0xFC, 0x13};
const unsigned char txbuff_cofGPS5N[] = {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x03, 0x00, 0xFD, 0x15};
const unsigned char txbuff_cofGPS6N[] = {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x01, 0x00, 0xFB, 0x11};

const unsigned char txbuff_cofGPS1[] = {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x04, 0x01, 0xFF, 0x18};
const unsigned char txbuff_cofGPS2[] = {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x05, 0x01, 0x00, 0x1A};
const unsigned char txbuff_cofGPS3[] = {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x00, 0x01, 0xFB, 0x10};
const unsigned char txbuff_cofGPS4[] = {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x02, 0x01, 0xFD, 0x14};
const unsigned char txbuff_cofGPS5[] = {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x03, 0x01, 0xFE, 0x16};
const unsigned char txbuff_cofGPS6[] = {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x01, 0x01, 0xFC, 0x12};

QByteArray txbuff_cofGPS_GPRMC = QByteArray((char*)txbuff_cofGPS1, 11);
QByteArray txbuff_cofGPS_GPVTG = QByteArray((char*)txbuff_cofGPS2, 11);
QByteArray txbuff_cofGPS_GPGGA = QByteArray((char*)txbuff_cofGPS3, 11);
QByteArray txbuff_cofGPS_GPGSA = QByteArray((char*)txbuff_cofGPS4, 11);
QByteArray txbuff_cofGPS_GPGSV = QByteArray((char*)txbuff_cofGPS5, 11);
QByteArray txbuff_cofGPS_GPGLL = QByteArray((char*)txbuff_cofGPS6, 11);

QByteArray txbuff_cofGPS_GPRMCN = QByteArray((char*)txbuff_cofGPS1N, 11);
QByteArray txbuff_cofGPS_GPVTGN = QByteArray((char*)txbuff_cofGPS2N, 11);
QByteArray txbuff_cofGPS_GPGGAN = QByteArray((char*)txbuff_cofGPS3N, 11);
QByteArray txbuff_cofGPS_GPGSAN = QByteArray((char*)txbuff_cofGPS4N, 11);
QByteArray txbuff_cofGPS_GPGSVN = QByteArray((char*)txbuff_cofGPS5N, 11);
QByteArray txbuff_cofGPS_GPGLLN = QByteArray((char*)txbuff_cofGPS6N, 11);

/***Cofig Freq***/
const unsigned char txbuff_cofFRQ50[] = {0xB5, 0x62, 0x06, 0x08, 0x06, 0x00, 0x32, 0x00, 0x01, 0x00, 0x01, 0x00, 0x48, 0xE6};//50ms
const unsigned char txbuff_cofFRQ100[] = {0xB5, 0x62, 0x06, 0x08, 0x06, 0x00, 0x64, 0x00, 0x01, 0x00, 0x01, 0x00, 0x7A, 0x12};//100ms
const unsigned char txbuff_cofFRQ150[] = {0xB5, 0x62, 0x06, 0x08, 0x06, 0x00, 0x96, 0x00, 0x01, 0x00, 0x01, 0x00, 0xAC, 0x3E};//150ms
const unsigned char txbuff_cofFRQ200[] = {0xB5, 0x62, 0x06, 0x08, 0x06, 0x00, 0xC8, 0x00, 0x01, 0x00, 0x01, 0x00, 0xDE, 0x6A};//200ms
const unsigned char txbuff_cofFRQ500[] = {0xB5, 0x62, 0x06, 0x08, 0x06, 0x00, 0xF4, 0x01, 0x01, 0x00, 0x01, 0x00, 0x0B, 0x77};//500ms


const unsigned char txbuff_cofFRQb[] = {0xB5, 0x62, 0x06, 0x08, 0x00, 0x00, 0x0E, 0x30};
QByteArray txbuff_cofFRQ1_50 = QByteArray((char*)txbuff_cofFRQ50, 14);
QByteArray txbuff_cofFRQ1_100 = QByteArray((char*)txbuff_cofFRQ100, 14);
QByteArray txbuff_cofFRQ1_150 = QByteArray((char*)txbuff_cofFRQ150, 14);
QByteArray txbuff_cofFRQ1_200 = QByteArray((char*)txbuff_cofFRQ200, 14);
QByteArray txbuff_cofFRQ1_500 = QByteArray((char*)txbuff_cofFRQ500, 14);
QByteArray txbuff_cofFRQ2 = QByteArray((char*)txbuff_cofFRQb, 8);


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    Node.initMapDormData(mapPicDorm, astarParam);

    displayGUI(mapPicDorm);

    connect(ui->graphicsView_mapLayers, SIGNAL(sendMousePosition(QPoint&, QPoint&)), this, SLOT(showMousePosition(QPoint&, QPoint&)));
    connect(ui->graphicsView_mapLayers, SIGNAL(sendMousePress(QPoint&, QPoint&)), this, SLOT(showMousePress(QPoint&, QPoint&)));
    connect(ui->graphicsView_mapLayers, SIGNAL(sendMouseDoubleClick(QPoint&, QPoint&)), this, SLOT(showMouseDoubleClick(QPoint&, QPoint&)));

    /*Receive data from GPS*/
    fillPort();
    connect(Uart_timer, SIGNAL(timeout()), this, SLOT(receiveSerialData()));

    /**Start Button**/
    startBTTimer = new QTimer(this);
    connect(startBTTimer, SIGNAL(timeout()), this, SLOT(controlStartBT()));


    /**Check Destination**/
    destinationTimer = new QTimer(this);
    connect(destinationTimer, SIGNAL(timeout()), this, SLOT(checkDestination()));

    /**Customer**/
    CustomerWaitingTimer = new QTimer(this);
    connect(CustomerWaitingTimer, SIGNAL(timeout()), this, SLOT(customerStartMoving()));

    /**TCPConnection**/
    connect(ui->button_TcpClient, SIGNAL(clicked()), this, SLOT(onTcpClientButtonClicked()));
    initUI();
    findLocalIPs();
    loadSettings();

    /**Steering**/
    fillPortServo();
    ServoTimer = new QTimer(this);
    connect(ServoTimer, SIGNAL(timeout()), this, SLOT(manualSteeringControlTimer()));


//    /**Get data from server**/
//    serverTimer = new QTimer(this);
//    connect(serverTimer, SIGNAL(timeout()), this, SLOT(getDataFromServer()));
//    serverTimer->start(SERVERTIMEOUT);




    /**Radar Scan**/

//
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayGUI(mapPic mapPicDorm)
{
    graphic = new QGraphicsScene();
    mapLayer = new QGraphicsPixmapItem(QPixmap::fromImage(mapPicDorm.imageShow));
    graphic->addItem(mapLayer);
    ui->graphicsView_mapLayers->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView_mapLayers->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView_mapLayers->setScene(graphic);
    GPSmarker = new QGraphicsPixmapItem(QPixmap(":/image/GPSmarker.png").scaled(30, 30, Qt::KeepAspectRatio));
    graphic->addItem(GPSmarker);
    markerA = new QGraphicsPixmapItem(QPixmap(":/image/GPSmarkerA.png").scaled(30, 30, Qt::KeepAspectRatio));
    graphic->addItem(markerA);
    markerB = new QGraphicsPixmapItem(QPixmap(":/image/GPSmarkerB.png").scaled(30, 30, Qt::KeepAspectRatio));
    graphic->addItem(markerB);
}

void MainWindow::makePath()
{
    if(astarParam.maps.at(pathParam.xS).at(pathParam.yS) == 255)
    {
        for(int y = pathParam.yS - 15; y < pathParam.yS + 15; y++)
            for(int x = pathParam.xS - 15; x < pathParam.xS + 15; x++)
            {
                if(astarParam.maps.at(x).at(y) != 255)
                {
                    pathParam.xS = x;
                    pathParam.yS = y;
                    goto verifyF_dir;
                }
            }
//        findClosePointS(pathParam.xS, pathParam.yS, pathParam);
//        qInfo() << pathParam.xS;

    }

verifyF_dir:
    if(astarParam.maps.at(pathParam.xE).at(pathParam.yE) == 255)
    {
        for(int y = pathParam.yE - 15; y < pathParam.yE + 15; y++)
            for(int x = pathParam.xE - 15; x < pathParam.xE + 15; x++)
            {
                if(astarParam.maps.at(x).at(y) != 255)
                {
                    pathParam.xE = x;
                    pathParam.yE = y;
                    goto startAstar_dir;
                }
            }
//        findClosePointE(pathParam.xE, pathParam.yE, pathParam);

    }

startAstar_dir:
    string route = Node.pathFind(pathParam.xS, pathParam.yS, pathParam.xE, pathParam.yE, astarParam);
    if(route.length()>0){
        pathParam.xPath.clear();
        pathParam.yPath.clear();
        astarParam.dir_map = astarParam.reset;
        int j;
        char c;
        int x=pathParam.xS;
        int y=pathParam.yS;
        astarParam.dir_map.at(x).at(y) = 2;
        qDebug() << "Astar";
        for(int i = 0; i < route.length(); i++) {
            c = route.at(i); //lay ki tu tai vi tri i
            j = atoi(&c); //chuyen gia tri string ve int
            x = x + astarParam.dx[j];
            y = y + astarParam.dy[j];
            astarParam.dir_map.at(x).at(y) = 3;
            qDebug() << x;
            qDebug() << y;
            pathParam.xPath.push_back(x);
            pathParam.yPath.push_back(y);
        }
        astarParam.dir_map.at(x).at(y) = 4;
        // display the map with the route
        for(int y = 0; y < mapPicDorm.h; y++)
            for(int x = 0; x < mapPicDorm.w; x++)
                if(astarParam.dir_map.at(x).at(y) == 2 || astarParam.dir_map.at(x).at(y) == 3 || astarParam.dir_map.at(x).at(y) == 4){
                    mapPicDorm.imageShow.setPixel(x, y, qRgb(0, 0, 255));
                    mapPicDorm.imageShow.setPixel(x + 1, y + 1, qRgb(0, 0, 255));
                    mapPicDorm.imageShow.setPixel(x - 1, y - 1, qRgb(0, 0, 255));
                    mapPicDorm.imageShow.setPixel(x, y + 1, qRgb(0, 0, 255));
                    mapPicDorm.imageShow.setPixel(x + 1, y, qRgb(0, 0, 255));
                    mapPicDorm.imageShow.setPixel(x - 1, y, qRgb(0, 0, 255));
                    mapPicDorm.imageShow.setPixel(x, y - 1, qRgb(0, 0, 255));
                }
    }
    else{
        QMessageBox mess;
        mess.setText("Fail Path!");
        mess.exec();
    }

}

void MainWindow::findClosePointS(int x, int y, path_parameter &pathParam)
{
    for(int i = 0; i < mapPicDorm.w; i++)
    {
        if(astarParam.maps.at(i).at(y) < 50){
            pathParam.xS = i;
            pathParam.yS = y;

            break;
        }
    }

    for(int j = 0; j < mapPicDorm.h; j++)
    {
        if((astarParam.maps.at(x).at(j) < 50) && (abs(j - y) < abs(pathParam.xS - x)))
        {

            pathParam.xS = x;
            pathParam.yS = j;

            break;
        }
    }
    return;

}

void MainWindow::findClosePointE(int x, int y, path_parameter &pathParam)
{
    for(int i = 0; i < mapPicDorm.w; i++)
    {
        if(astarParam.maps.at(i).at(y) < 50){
            pathParam.xE = i;
            pathParam.yE = y;

            break;
        }
    }


    for(int j = 0; j < mapPicDorm.h; j++)
    {
        if((astarParam.maps.at(x).at(j) < 50) && (abs(j - y) < abs(pathParam.xE - x)))
        {

            pathParam.xE = x;
            pathParam.yE = j;

            break;
        }
    }
    return;

}

void MainWindow::findClosePointInPath(int x, int y)
{
    vector<int> xClose, yClose;
    int temp = 0, dTemp = 0, dmin = 0, index = 0;

    for(int i = 0; i < mapPicDorm.w; i++)
    {
        if(astarParam.dir_map.at(i).at(y) == 3){
            xClose.push_back(i);
            yClose.push_back(y);
            temp++;
        }
    }

    for(int j = 0; j < mapPicDorm.h; j++)
    {
        if(astarParam.dir_map.at(x).at(j) == 3){
            xClose.push_back(x);
            yClose.push_back(j);
            temp++;
        }
    }

    if(!xClose.empty()){
        pathPlanning.predictPoint[0] = xClose.back();
        pathPlanning.predictPoint[1] = yClose.back();
        dmin = abs(xClose.back() - x) + abs(yClose.back() - y);
        for(int k = temp - 2; k >= 0; k--){
            dTemp = abs(xClose.at(k) - x) + abs(yClose.at(k) - y);
            if(dTemp < dmin){
                pathPlanning.predictPoint[0] = xClose.at(k);
                pathPlanning.predictPoint[1] = yClose.at(k);
                dmin = dTemp;
            }
        }

        for(int t = 0; t < pathParam.xPath.size(); t++){
            if((pathPlanning.predictPoint[0] == pathParam.xPath.at(t)) && (pathPlanning.predictPoint[1] == pathParam.yPath.at(t))){
                if((t + pathPlanning.distancePred) >= pathParam.xPath.size()){
                    pathPlanning.predictPoint[0] = pathParam.xPath.back();
                    pathPlanning.predictPoint[1] = pathParam.yPath.back();
                    break;
                }
                if(pathParam.xPath.at(t + pathPlanning.distancePred) != 0){
                    pathPlanning.predictPoint[0] = pathParam.xPath.at(t + pathPlanning.distancePred);
                    pathPlanning.predictPoint[1] = pathParam.yPath.at(t + pathPlanning.distancePred);

                    break;
                }
                else{
                    for(int z = t + pathPlanning.distancePred; z > (t - 1); z--){
                        if(pathParam.xPath.at(z) != 0){
                            pathPlanning.predictPoint[0] = pathParam.xPath.at(z);
                            pathPlanning.predictPoint[1] = pathParam.yPath.at(z);
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
    else if (!pathParam.xPath.empty()) {
//        pathPlanning.predictPoint[0] = pathParam.xPath.front();
//        pathPlanning.predictPoint[1] = pathParam.yPath.front();
        pathPlanning.predictPoint[0] = linearParam.xSample.back() - 20;
        pathPlanning.predictPoint[1] = - linearParam.ySample.back() - 20;
    }
    else {
        pathPlanning.predictPoint[0] = linearParam.xSample.back() - 20;
        pathPlanning.predictPoint[1] = - linearParam.ySample.back() - 20;
    }

//    if (!pathParam.xPath.empty())
//    {
////        pathPlanning.predictPoint[0] = pathParam.xPath.front();
////        pathPlanning.predictPoint[1] = pathParam.yPath.front();
//        dmin = abs(pathParam.xPath.at(0) - x) + abs(pathParam.yPath.at(0) - y);
//        for (auto i = 0; i < pathParam.xPath.size(); i++ )
//        {
//            dTemp = abs(pathParam.xPath.at(i) - x) + abs(pathParam.yPath.at(i) - y);
//            if (dTemp <= dmin)
//            {
//                if (i + pathPlanning.distancePred < pathParam.xPath.size())
//                {
//                    QColor clrCurrent(mapPicDorm.imageTemp.pixel(pathParam.xPath.at(i + pathPlanning.distancePred), pathParam.yPath.at(i + pathPlanning.distancePred)));
//                    if (clrCurrent.blue() == 255)
//                    {
//                        pathPlanning.predictPoint[0] = pathParam.xPath.at(i + pathPlanning.distancePred);
//                        pathPlanning.predictPoint[1] = pathParam.yPath.at(i + pathPlanning.distancePred);
//                    }
//                    else
//                    {
//                        pathPlanning.predictPoint[0] = pathParam.xPath.back();
//                        pathPlanning.predictPoint[1] = pathParam.yPath.back();
//                    }
//                }
//                else
//                {
//                    ;
//                }
//                dmin = dTemp;
//            }
//            else
//            {
////                pathPlanning.predictPoint[0] = pathParam.xPath.back();
////                pathPlanning.predictPoint[1] = pathParam.yPath.back();
//                ;
//            }

//        }

//    }
//    else
//    {
//        pathPlanning.predictPoint[0] = linearParam.xSample.back() - 20;
//        pathPlanning.predictPoint[1] = - linearParam.ySample.back() - 20;

//    }

}

void MainWindow::GPGLL_analysis(string raw_data)
{
    if((raw_data.substr(0, 6) == "$GPGLL") && (raw_data.length() == 52))
    {
        while ((gpsAnalysisParam.pos = raw_data.find(',')) != string::npos)
        {
            switch (gpsAnalysisParam.cnt)
            {
            case 1:
                gpsAnalysisParam.token = raw_data.substr(0, gpsAnalysisParam.pos);

                if(!(gpsAnalysisParam.token.empty()))
                {
//                    qInfo() << QByteArray::fromStdString(gpsAnalysisParam.token);
                    postPos.Lat = gpsAnalysisParam.token;
                    gpsAnalysisParam.degLat = atoi(gpsAnalysisParam.token.substr(0, 2).c_str());
                    gpsAnalysisParam.minLat = (round(atof(gpsAnalysisParam.token.substr(2).c_str()) * pow(10, 5))/pow(10, 5))/60;

//                    qDebug() << (round(atof(gpsAnalysisParam.token.substr(2).c_str()) * pow(10, 5))/pow(10, 5) - 45);

                    rawLocation.lat = (double)gpsAnalysisParam.degLat + gpsAnalysisParam.minLat;
                }
                else
                {
                    break;
                }
                break;

            case 3:
                gpsAnalysisParam.token = raw_data.substr(0, gpsAnalysisParam.pos);

                if(!(gpsAnalysisParam.token.empty()))
                {
//                    qInfo() << QByteArray::fromStdString(gpsAnalysisParam.token);
                    postPos.Lon = gpsAnalysisParam.token;
                    gpsAnalysisParam.degLng = atoi(gpsAnalysisParam.token.substr(0, 3).c_str());
                    gpsAnalysisParam.minLng = (round(atof(gpsAnalysisParam.token.substr(3).c_str()) * pow(10, 5))/pow(10, 5))/60;

//                    qDebug() << (round(atof(gpsAnalysisParam.token.substr(3).c_str()) * pow(10, 5))/pow(10, 5) - 39);

                    rawLocation.lng = (double)gpsAnalysisParam.degLng + gpsAnalysisParam.minLng;
                    break;
                }
                else
                {
                    break;
                }

            default:
                break;
            }
            raw_data.erase(0, gpsAnalysisParam.pos + 1);
            gpsAnalysisParam.cnt++;
        }
//        postDataToServer();

//        qDebug() << rawLocation.lat - 10;
//        qDebug() << rawLocation.lng - 106;
        gpsAnalysisParam = {"GP", 0, 0, 0, 0, 0, 0, 0, 0};
        return;

    }

}

void MainWindow::checkCarBooking(string carBookingData)
{
    //{"guest_num":"0384370222","lat_a":"1357.13579","lon_a":"24680.02468","lat_b":"9753.95731","lon_b":"86420.08642"}
    if((carBookingData.substr(2, 9) == "guest_num") && (carBookingData.length() >= 100))
    {
        int cnt = 0, pos = 0;
        serialPort->close();
        Uart_timer->stop();

        qDebug() << "OK";

        while ((pos = carBookingData.find('"')) != string::npos)
        {
            switch (cnt)
            {
            case 7:
                pathParam.yS = (int)((abs(atof(carBookingData.substr(0, pos).c_str()) - mapPicDorm.latStart))/(mapPicDorm.deltaLat));
                CustomerInfor.yA = (int)((abs(atof(carBookingData.substr(0, pos).c_str()) - mapPicDorm.latStart))/(mapPicDorm.deltaLat));

//                pathParam.yS = (int)(atoi(carBookingData.substr(0, pos).c_str()));
//                qDebug() << pathParam.yS;
                break;

            case 11:
                pathParam.xS = (int)((abs(atof(carBookingData.substr(0, pos).c_str()) - mapPicDorm.lngStart))/(mapPicDorm.deltaLng));
                CustomerInfor.xA = (int)((abs(atof(carBookingData.substr(0, pos).c_str()) - mapPicDorm.lngStart))/(mapPicDorm.deltaLng));

//                pathParam.xS = (int)(atoi(carBookingData.substr(0, pos).c_str()));
//                qDebug() << pathParam.xS;
                break;

            case 15:
                pathParam.yE = (int)(abs((atof(carBookingData.substr(0, pos).c_str()) - mapPicDorm.latStart))/(mapPicDorm.deltaLat));
                CustomerInfor.yB = (int)(abs((atof(carBookingData.substr(0, pos).c_str()) - mapPicDorm.latStart))/(mapPicDorm.deltaLat));

//                pathParam.yE = (int)(atoi(carBookingData.substr(0, pos).c_str()));
//                qDebug() << pathParam.yE;
                break;

            case 19:
                pathParam.xE = (int)(abs((atof(carBookingData.substr(0, pos).c_str()) - mapPicDorm.lngStart))/(mapPicDorm.deltaLng));
                CustomerInfor.xB = (int)(abs((atof(carBookingData.substr(0, pos).c_str()) - mapPicDorm.lngStart))/(mapPicDorm.deltaLng));

//                pathParam.xE = (int)(atoi(carBookingData.substr(0, pos).c_str()));
//                qDebug() << pathParam.xE;
                break;

            default:
                break;
            }
            carBookingData.erase(0, pos + 1);
            cnt++;

        }

//        GUIControlData.userReqAutoRun = true;

        CustomerInfor.customerInProccess = true;
        CustomerInfor.xyA_Ok = true;

        pathParam.xS = xyLocation.xLng;
        pathParam.yS = xyLocation.yLat;
        pathParam.xE = CustomerInfor.xA;
        pathParam.yE = CustomerInfor.yA;

        setPath();

        serialPort->open(QIODevice::ReadWrite);
        StatusVehicle.statusVehicleFlag[0] = 'R';
        serialPort->write(StatusVehicle.statusVehicleFlag);

        Uart_timer->start(TIMEOUTRxGPS);
        destinationTimer->start(CHECKDESTINATIONTIM);
        startPathPlanning = true;

        return;

    }

}

void MainWindow::getDataFromServer(string raw_SVdata)
{
    if(raw_SVdata.substr(0, 12) == "01234567\r\n")
    {
        StatusVehicle.statusVehicleFlag[0] = 'R';
        serialPort->write(StatusVehicle.statusVehicleFlag);
    }
//    if(accessToNet.dataServer.bytedata.length() > 0)
//    {
//        while ((gpsAnalysisParam.pos = gps_string.find('"')) != string::npos)
//        {
//            switch (gpsAnalysisParam.cnt)
//            {
//            case 11:
//                rawLocation.lat = atof(gps_string.substr(0, gpsAnalysisParam.pos).c_str());
//                break;

//            case 15:
//                rawLocation.lng = atof(gps_string.substr(0, gpsAnalysisParam.pos).c_str());
//                break;

//            case 19:
//                rawLocation.vel = atof(gps_string.substr(0, gpsAnalysisParam.pos).c_str());
//                break;

//            default:
//                break;
//            }

//            gps_string.erase(0, gpsAnalysisParam.pos + 1);
//            gpsAnalysisParam.cnt++;

//        }
//        inc++;

//    }

    return;

}


bool MainWindow::LinearRegress()
{
    double sumx = 0, sumy = 0, sumx2 = 0, sumy2 = 0, sumxy = 0;
    double sxx = 0, syy = 0, sxy = 0;
    auto n = linearParam.xSample.size();

    linearParam.slope = 0;
    linearParam.yIntercept = 0;
    linearParam.regressionCoefficient = 0;
    if (n < 2)
       return(false);

    /* Conpute some things we need */
    for (auto i = 0; i < n; i++) {
       sumx += linearParam.xSample.at(i);
       sumy += linearParam.ySample.at(i);
       sumx2 += pow(linearParam.xSample.at(i), 2);
       sumy2 += pow(linearParam.ySample.at(i), 2);
       sumxy += linearParam.xSample.at(i) * linearParam.ySample.at(i);
    }
    sxx = sumx2 - sumx * sumx / n;
    syy = sumy2 - sumy * sumy / n;
    sxy = sumxy - sumx * sumy / n;

    /* Infinite slope (b), non existant intercept (a) */
    if (abs(sxx) == 0)
       return(false);

    /* Calculate the slope (b) and intercept (a) */
    linearParam.slope = sxy / sxx;
    linearParam.yIntercept = sumy / n - (linearParam.slope) * sumx / n;

    /* Compute the regression coefficient */
    if (abs(syy) == 0)
       linearParam.regressionCoefficient = 1;
    else
       linearParam.regressionCoefficient = sxy / sqrt(sxx * syy);

    return(true);

}

void MainWindow::calcAngle()
{
    double b1 = linearParam.ySample.back() - (linearParam.k1) * (linearParam.xSample.back());
    int x1 = 0, y1 = 0, dist = 0;

    dist = (int)abs(((drawVelocityVector.velocityVector) * cos(atan(linearParam.k1))));

    if(linearParam.xSample.back() > linearParam.xSample.front())
    {
        x1 = linearParam.xSample.back() + dist;
        if(x1 > mapPicDorm.w){
            x1 = mapPicDorm.w;
        }
    }
    else if (linearParam.xSample.back() == linearParam.xSample.front())
    {
        if (linearParam.ySample.back() < linearParam.ySample.front()) // y < 0
        {
            x1 = linearParam.xSample.back() + dist;
            if(x1 > mapPicDorm.w)
            {
                x1 = mapPicDorm.w;
            }
        }
        else
        {
            x1 = linearParam.xSample.back() - dist;
            if(x1 < 0)
            {
                x1 = 0;
            }
        }
    }
    else
    {
        x1 = linearParam.xSample.back() - dist;
        if(x1 < 0){
            x1 = 0;
        }
    }

    y1 = (int)(-((linearParam.k1)*x1 + b1));
    if(y1 > mapPicDorm.h) y1 = mapPicDorm.h;
    if(y1 < 0) y1 = 0;

    mapPicDorm.imageDir = mapPicDorm.imageTemp;
//    for(int i = 0; i < linearParam.xSample.size(); i++)
//    {
//        mapPicDorm.imageDir.setPixel(linearParam.xSample.at(i), - linearParam.ySample.at(i), qRgb(0, 0, 255));
//    }

    double vectorVx = (x1 - linearParam.xSample.back()), vectorVy = (-y1 - linearParam.ySample.back()),
            vectorPx = (pathPlanning.predictPoint[0] - linearParam.xSample.back()), vectorPy = (-pathPlanning.predictPoint[1] - linearParam.ySample.back()),

            arcsinPredict = asin(((vectorVx*vectorPy) - (vectorVy*vectorPx))/
            (sqrt(vectorVx*vectorVx + vectorVy*vectorVy)*sqrt(vectorPx*vectorPx + vectorPy*vectorPy)));

    linearParam.angle = acos(((vectorVx*vectorPx) + (vectorVy*vectorPy))/
            (sqrt(vectorVx*vectorVx + vectorVy*vectorVy)*sqrt(vectorPx*vectorPx + vectorPy*vectorPy)))*(180/M_PI);

    if(arcsinPredict < 0)
    {
        linearParam.angle = - linearParam.angle;
    }

    QPixmap layerDir(QPixmap::fromImage(mapPicDorm.imageDir));
    QPainter directionLayer(&layerDir);
    directionLayer.setPen(QPen(Qt::blue, 3));
    directionLayer.drawLine(linearParam.xSample.back(), - linearParam.ySample.back(), x1, y1);
    directionLayer.setPen(QPen(Qt::red, 3));
//    qDebug() << linearParam.xSample.size();
    for(int i = 0; i < linearParam.xSample.size(); i++)
    {
        directionLayer.drawPoint(linearParam.xSample.at(i), - linearParam.ySample.at(i));
    }
    directionLayer.drawPoint(xyLocation.xLng, xyLocation.yLat);
    qDebug() << "x: " << xyLocation.xLng;
//    qDebug() << linearParam.xSample.back();
    qDebug() << "y: " << -xyLocation.yLat;

//    qDebug() << "v: " << GUIControlData.speedSetpoint;
//    qDebug() << -linearParam.ySample.back();
//    directionLayer.drawPoint(linearParam.xSample.back(), - linearParam.ySample.back());
    directionLayer.drawLine(linearParam.xSample.back(), - linearParam.ySample.back(), pathPlanning.predictPoint[0], pathPlanning.predictPoint[1]);
    GPSmarker->setPos(xyLocation.xLng - halfWidthIcon, xyLocation.yLat - halfWidthIcon);
    mapLayer->setPixmap(QPixmap(layerDir));
    ui->graphicsView_mapLayers->setScene(graphic);

}

void MainWindow::receiveSerialData()
{
    QByteArray byte_data = serialPort->readLine();
    string gps_string = byte_data.toStdString();
//    qInfo() << byte_data;

//    StatusVehicle.statusVehicleFlag[0] = 'R';
//    serialPort->write(StatusVehicle.statusVehicleFlag);

//    serialPort->close();
//    Uart_timer->stop();

    if (byte_data.length() == 0)
        return;
    if (StatusVehicle.statusVehicleFlag[0] != 'R')
    {
        checkCarBooking(gps_string);
    }

    GPGLL_analysis(gps_string);

    xyLocation.yLat = (int)(abs(rawLocation.lat - mapPicDorm.latStart)/(mapPicDorm.deltaLat));
    xyLocation.xLng = (int)(abs(rawLocation.lng - mapPicDorm.lngStart)/(mapPicDorm.deltaLng));
//    GPSmarker->setPos(xyLocation.xLng - halfWidthIcon, xyLocation.yLat - halfWidthIcon);
//    QPixmap layerDir(QPixmap::fromImage(mapPicDorm.imageDir));
//    QPainter directionLayer(&layerDir);
//    directionLayer.setPen(QPen(Qt::red, 3));
//    directionLayer.drawPoint(xyLocation.xLng, xyLocation.yLat);
////    if(linearParam.xSample.size() > 0)
////    directionLayer.drawPoint(accumulate(linearParam.xSample.begin(), linearParam.xSample.end(), 0)/linearParam.xSample.size(), - accumulate(linearParam.ySample.begin(), linearParam.ySample.end(), 0)/linearParam.ySample.size());
//    for(int i = 0; i < linearParam.xSample.size(); i++)
//    {
//        directionLayer.drawPoint(linearParam.xSample.at(i), - linearParam.ySample.at(i));
//    }
////    directionLayer.drawLine(linearParam.xSample.back(), - linearParam.ySample.back(), pathPlanning.predictPoint[0], pathPlanning.predictPoint[1]);
//    GPSmarker->setPos(xyLocation.xLng - halfWidthIcon, xyLocation.yLat - halfWidthIcon);
//    mapLayer->setPixmap(QPixmap(layerDir));
//    ui->graphicsView_mapLayers->setScene(graphic);

    linearParam.xSample.push_back(xyLocation.xLng);
    linearParam.ySample.push_back(-xyLocation.yLat);

    if(xyLocation.xLng > mapPicDorm.w)
    {
//        QMessageBox::information(this, "Warning", "Out of your area.\nTurn back right now!");
        linearParam.xSample.clear();
        linearParam.ySample.clear();
        xyLocation.xLng = mapPicDorm.w - 1;
    }
    if(xyLocation.yLat > mapPicDorm.h)
    {
//        QMessageBox::information(this, "Warning", "Out of your area.\nTurn back right now!");
        linearParam.xSample.clear();
        linearParam.ySample.clear();
        xyLocation.yLat = mapPicDorm.h - 1;
    }

    if(linearParam.xSample.size() >= 2)
    {
        if(LinearRegress()){
            linearParam.k1 = linearParam.slope;
        }
        else{
            linearParam.k1 = 0;
        }

        findClosePointInPath(linearParam.xSample.back(), -linearParam.ySample.back());
        if(pathPlanning.predictPoint[0] == linearParam.xSample.back()) linearParam.xSample.back() = linearParam.xSample.back() + 1;

        linearParam.k2 = (float)(-pathPlanning.predictPoint[1] - linearParam.ySample.back())/(pathPlanning.predictPoint[0] - linearParam.xSample.back());

        //check all points in the same position
        for (auto i = 0; i < linearParam.xSample.size(); i++)
        {
            if ((linearParam.xSample.at(i) > xyLocation.xLng + 4) || (linearParam.xSample.at(i) < xyLocation.xLng - 4) || (linearParam.ySample.at(i) > -xyLocation.yLat + 4) || (linearParam.ySample.at(i) < -xyLocation.yLat - 4))
            {
                CheckCarState = Running;
                break;
            }

            CheckCarState = Stop;
        }

        calcAngle();

        controlDataQt.previewCurvature =
                (sqrt(pow((xyLocation.xLng - pathPlanning.predictPoint[0]), 2) + pow((-xyLocation.yLat - pathPlanning.predictPoint[1]), 2))/(2*sin(abs(linearParam.angle)*M_PI/180)))*0.23;

        if (CheckCarState == Running)
        {
            if(linearParam.angle <= negativeLim){
//                controlDataQt.turnSignal = 2;
                controlDataQt.steeringLeftRight = 2;
                ui->label_Dir->setText("Right");
                qDebug() << "Dir: " << "Right";
                ui->label_Right->setStyleSheet("image: url(:/image/right.png); border-radius: 5px; background-color: rgba(243, 243, 243, 30);");
                ui->label_Straight->setStyleSheet("image: url(:/image/straightDis.png); border-radius: 5px; background-color: rgba(243, 243, 243, 30);");
                ui->label_Left->setStyleSheet("image: url(:/image/leftDis.png); border-radius: 5px; background-color: rgba(243, 243, 243, 30);");
            } else if(linearParam.angle >= positiveLim){
//                controlDataQt.turnSignal = 1;
                controlDataQt.steeringLeftRight = 1;
                ui->label_Dir->setText("Left");
                qDebug() << "Dir: " << "Left";
                ui->label_Right->setStyleSheet("image: url(:/image/rightDis.png); border-radius: 5px; background-color: rgba(243, 243, 243, 30);");
                ui->label_Straight->setStyleSheet("image: url(:/image/straightDis.png); border-radius: 5px; background-color: rgba(243, 243, 243, 30);");
                ui->label_Left->setStyleSheet("image: url(:/image/left.png); border-radius: 5px; background-color: rgba(243, 243, 243, 30);");
            } else if((linearParam.angle > negativeLim) && (linearParam.angle < positiveLim)){
//                controlDataQt.turnSignal = 0;
                controlDataQt.steeringLeftRight = 0;
                ui->label_Dir->setText("Straight");
                qDebug() << "Dir: " << "Straight";
                ui->label_Right->setStyleSheet("image: url(:/image/rightDis.png); border-radius: 5px; background-color: rgba(243, 243, 243, 30);");
                ui->label_Straight->setStyleSheet("image: url(:/image/straight.png); border-radius: 5px; background-color: rgba(243, 243, 243, 30);");
                ui->label_Left->setStyleSheet("image: url(:/image/leftDis.png); border-radius: 5px; background-color: rgba(243, 243, 243, 30);");
            } else;

        }
        else
        {
            controlDataQt.steeringLeftRight = 0;
            ui->label_Dir->setText("Straight");
            qDebug() << "Dir: " << "Straight";
            ui->label_Right->setStyleSheet("image: url(:/image/rightDis.png); border-radius: 5px; background-color: rgba(243, 243, 243, 30);");
            ui->label_Straight->setStyleSheet("image: url(:/image/straight.png); border-radius: 5px; background-color: rgba(243, 243, 243, 30);");
            ui->label_Left->setStyleSheet("image: url(:/image/leftDis.png); border-radius: 5px; background-color: rgba(243, 243, 243, 30);");
        }

        if (startPathPlanning == true)
        {
            if (controlDataQt.steeringLeftRight == 0)
            {
                controlDataQt.speedSetpoint = STRAIGHTSPEED;
                ui->horizontalSlider_speed->setValue(controlDataQt.speedSetpoint);
                ui->label_SPSpeed->setText(QString::number(controlDataQt.speedSetpoint));
            }
            else
            {
                controlDataQt.speedSetpoint = TURNSPEED;
                ui->horizontalSlider_speed->setValue(controlDataQt.speedSetpoint);
                ui->label_SPSpeed->setText(QString::number(controlDataQt.speedSetpoint));
            }
        }

    }

//    qInfo() << linearParam.xSample.size();
//    qInfo() << linearParam.xSample.at(0);
//    qInfo() << linearParam.ySample.at(0);

    if(linearParam.xSample.size() == SAMPLES)
    {
        linearParam.xSample.erase(linearParam.xSample.begin());
        linearParam.ySample.erase(linearParam.ySample.begin());
    }

}

void MainWindow::setPath()
{

    makePath();
    mapLayer->setPixmap(QPixmap::fromImage(mapPicDorm.imageShow));
    ui->graphicsView_mapLayers->setScene(graphic);
    mapPicDorm.imageTemp = mapPicDorm.imageShow;
    mapPicDorm.imageShow = mapPicDorm.imageSrc;
    ui->pushButton_Dir->setEnabled(false);
    ui->pushButton_Dir->setStyleSheet("image: url(:/image/dirDis.png);border-radius: 5px;background-color: rgba(243, 243, 243, 30);");

}

void MainWindow::customerStartMoving()
{
    CustomerWaitingTimer->stop();
    Uart_timer->stop();
    pathParam.xS = xyLocation.xLng;
    pathParam.yS = xyLocation.yLat;
    pathParam.xE = CustomerInfor.xB;
    pathParam.yE = CustomerInfor.yB;

    setPath();

    CustomerInfor.xyA_Ok = false;
    CustomerInfor.xyB_Ok = true;

    Uart_timer->start(TIMEOUTRxGPS);
    destinationTimer->start(CHECKDESTINATIONTIM);
    startPathPlanning = true;

}

void MainWindow::checkDestination()
{
    timeDes++;
    ui->label_checkDes->setText(QString::number(timeDes));
//    qDebug() << pathParam.xE;
//    qDebug() << pathParam.yE;
//    qDebug() << xyLocation.xLng;
//    qDebug() << xyLocation.yLat;
    for(int y = pathParam.yE - DESTINATIONAREA; y < pathParam.yE + DESTINATIONAREA; y++)
        for(int x = pathParam.xE - DESTINATIONAREA; x < pathParam.xE + DESTINATIONAREA; x++)
        {
            if((x == xyLocation.xLng) && (y == xyLocation.yLat))
            {
                startPathPlanning = false;
                destinationTimer->stop();

                controlDataQt.speedSetpoint = 0;
                ui->horizontalSlider_speed->setValue(controlDataQt.speedSetpoint);
                ui->label_SPSpeed->setText(QString::number(controlDataQt.speedSetpoint));

                pathParam.xS = 0, pathParam.yS = 0, pathParam.xE = 0, pathParam.yE = 0;
                pathParam.startOk = false;
                mapLayer->setPixmap(QPixmap::fromImage(mapPicDorm.imageSrc));
                mapPicDorm.imageTemp = mapPicDorm.imageSrc;
                markerA->setPos(0, 0);
                markerB->setPos(0, 0);
                ui->graphicsView_mapLayers->setScene(graphic);
                ui->pushButton_Dir->setEnabled(true);
                ui->pushButton_Dir->setStyleSheet("image: url(:/image/dir.png);border-radius: 5px;background-color: rgba(243, 243, 243, 30);");

                if(CustomerInfor.customerInProccess == true)
                {
                    if(CustomerInfor.xyA_Ok == true)
                    {
                        CustomerWaitingTimer->start(CUSTOMERWAITINGTIMEOUT);

                        return;

                    }
                    else if (CustomerInfor.xyB_Ok == true)
                    {
                        CustomerInfor.customerInProccess = false;
                        CustomerInfor.xyA_Ok = false;
                        CustomerInfor.xyB_Ok = false;

                        StatusVehicle.statusVehicleFlag[0] = 'S';
                        serialPort->write(StatusVehicle.statusVehicleFlag);
                        ui->label_destination->setText("Your destination is here");
                        return;
                    }
                    else;

                }
                else
                {
                    StatusVehicle.statusVehicleFlag[0] = 'S';
                    serialPort->write(StatusVehicle.statusVehicleFlag);
                    ui->label_destination->setText("Your destination is here");
                    return;
                }
            }

        }
    ui->label_destination->setText("Running");

}

void MainWindow::postDataToServer()
{
//    QByteArray data = "car_gps_ID=2&longtitude=10639.67639&latitude=1045.59172&velocity=16\r\n";
    QByteArray data = "car_gps_ID=4&longtitude=" + QByteArray::fromStdString(postPos.Lon) + "&latitude=" + QByteArray::fromStdString(postPos.Lat) + "&velocity=" + QByteArray::number(rcSpdFromEPC.myFloat) + "\r\n";

//    QByteArray data = "msgcont=helloThanh";

    accessToNet.post(myServer, data);

}


void MainWindow::showMousePosition(QPoint &pos, QPoint &delta)
{
    int i, j;
    i = pos.x() + delta.x();
    j = pos.y() + delta.y();
    QColor clrCurrent(mapPicDorm.imageShow.pixel(i, j));
    ui->label_pixel->setText(QString::number(clrCurrent.blue()));
    ui->label_currentPos->setText("x: " + QString::number(i) + ",y: " + QString::number(j));

}

void MainWindow::showMousePress(QPoint &pos, QPoint &delta)
{

}

void MainWindow::showMouseDoubleClick(QPoint &pos, QPoint &delta)
{
    mapLayer->setPixmap(QPixmap::fromImage(mapPicDorm.imageSrc));
    mapPicDorm.imageTemp = mapPicDorm.imageSrc;
    if(pathParam.startOk == false){
        pathParam.xS = pos.x() + delta.x();
        pathParam.yS = pos.y() + delta.y();
        pathParam.startOk = true;

        markerA->setPos(pathParam.xS - halfWidthIcon, pathParam.yS - iconScale);
        ui->graphicsView_mapLayers->setScene(graphic);

    }
    else{
        pathParam.xE = pos.x() + delta.x();
        pathParam.yE = pos.y() + delta.y();
        pathParam.startOk = false;
        ui->pushButton_Dir->setEnabled(true);
        ui->pushButton_Dir->setStyleSheet("image: url(:/image/dir.png);border-radius: 5px;background-color: rgba(243, 243, 243, 30);");

        markerB->setPos(pathParam.xE - halfWidthIcon, pathParam.yE - iconScale);
        ui->graphicsView_mapLayers->setScene(graphic);
    }

}


void MainWindow::on_pushButton_pageB_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_pageN_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}


void MainWindow::on_pushButton_page2B_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}


void MainWindow::on_pushButton_page2N_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}


void MainWindow::on_pushButton_page3B_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}


void MainWindow::on_pushButton_page3N_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}


void MainWindow::on_pushButton_Dir_clicked()
{
    Uart_timer->stop();
    setPath();
    Uart_timer->start(TIMEOUTRxGPS);
    destinationTimer->start(CHECKDESTINATIONTIM);
    startPathPlanning = true;

}


void MainWindow::on_pushButton_resetPos_clicked()
{
    startPathPlanning = false;
    destinationTimer->stop();

    pathParam.xS = 0, pathParam.yS = 0, pathParam.xE = 0, pathParam.yE = 0;
    pathParam.startOk = false;
    mapLayer->setPixmap(QPixmap::fromImage(mapPicDorm.imageSrc));
    mapPicDorm.imageTemp = mapPicDorm.imageSrc;
    markerA->setPos(0, 0);
    markerB->setPos(0, 0);
//    mapPicDorm.imageDir = mapPicDorm.imageTemp;
    ui->graphicsView_mapLayers->setScene(graphic);
}


void MainWindow::on_pushButton_autoRun_clicked()
{
    if(controlDataQt.userReqAutoRun == false){
        controlDataQt.userReqAutoRun = true;
        ui->pushButton_autoRun->setStyleSheet("border-radius: 20px;color: rgb(255, 255, 255);border:  2px solid rgb(69, 229, 139);background-color: rgba(69, 229, 139, 50)");

    }
    else{
        controlDataQt.userReqAutoRun = false;
        ui->pushButton_autoRun->setStyleSheet("border-radius: 20px;color: rgb(255, 255, 255);border:  2px solid rgb(69, 229, 139);background-color: rgba(243, 243, 243, 30);");

    }

}


void MainWindow::on_pushButton_start_clicked()
{
    if(controlDataQt.userReqStart == false)
    {
        controlDataQt.userReqStart = true;
        ui->pushButton_start->setStyleSheet("border-radius: 20px;color: rgb(255, 255, 255);border: 2px solid rgb(69, 229, 139);background-color: rgba(69, 229, 139, 50);");
    }
    else
    {
        controlDataQt.userReqStart = false;
        ui->pushButton_start->setStyleSheet("border-radius: 20px;color: rgb(255, 255, 255);border: 2px solid rgb(69, 229, 139);background-color: rgba(243, 243, 243, 30);");
    }

    startBTTimer->start(500);

}

void MainWindow::controlStartBT()
{
    if(controlDataQt.userReqStart == true)
    {
        controlDataQt.userReqStart = false;
        ui->pushButton_start->setStyleSheet("border-radius: 20px;color: rgb(255, 255, 255);border: 2px solid rgb(69, 229, 139);background-color: rgba(243, 243, 243, 30);");
        startBTTimer->stop();
    }

}


void MainWindow::on_pushButton_stop_clicked()
{

    if(controlDataQt.userReqStop == false)
    {
        controlDataQt.userReqStop = true;
        ui->pushButton_stop->setStyleSheet("border-radius: 20px;color: rgb(255, 255, 255);border: 2px solid rgb(69, 229, 139);background-color: rgba(69, 229, 139, 50);");
    }
    else
    {
        controlDataQt.userReqStop = false;
        ui->pushButton_stop->setStyleSheet("border-radius: 20px;color: rgb(255, 255, 255);border: 2px solid rgb(69, 229, 139);background-color: rgba(243, 243, 243, 30);");

    }

    controlDataQt.speedSetpoint = 0;
//    ui->label_speed->setText(QString::number(controlDataQt.speedSetpoint));
    ui->horizontalSlider_speed->setValue(controlDataQt.speedSetpoint);

}


void MainWindow::on_pushButton_turnSignalLeft_clicked()
{
    if (controlDataQt.turnSignal != 1)
    {
        controlDataQt.turnSignal = 1;
        ui->pushButton_turnSignalLeft->setStyleSheet("image: url(:/image/turnLeft.png);border-radius: 5px;background-color: rgba(69, 229, 139, 50);");
        ui->pushButton_turnSignalRight->setStyleSheet("image: url(:/image/turnRight.png);border-radius: 5px;background-color: rgba(243, 243, 243, 30);");

    }
    else
    {
        controlDataQt.turnSignal = 0;
        ui->pushButton_turnSignalLeft->setStyleSheet("image: url(:/image/turnLeft.png);border-radius: 5px;background-color: rgba(243, 243, 243, 30);");
        ui->pushButton_turnSignalRight->setStyleSheet("image: url(:/image/turnRight.png);border-radius: 5px;background-color: rgba(243, 243, 243, 30);");

    }

}


void MainWindow::on_pushButton_turnSignalRight_clicked()
{
    if (controlDataQt.turnSignal != 2)
    {
        controlDataQt.turnSignal = 2;
        ui->pushButton_turnSignalRight->setStyleSheet("image: url(:/image/turnRight.png);border-radius: 5px;background-color: rgba(69, 229, 139, 50);");
        ui->pushButton_turnSignalLeft->setStyleSheet("image: url(:/image/turnLeft.png);border-radius: 5px;background-color: rgba(243, 243, 243, 30);");

    }
    else
    {
        controlDataQt.turnSignal = 0;
        ui->pushButton_turnSignalLeft->setStyleSheet("image: url(:/image/turnLeft.png);border-radius: 5px;background-color: rgba(243, 243, 243, 30);");
        ui->pushButton_turnSignalRight->setStyleSheet("image: url(:/image/turnRight.png);border-radius: 5px;background-color: rgba(243, 243, 243, 30);");

    }

}





void MainWindow::on_pushButton_horn_clicked()
{
    if (controlDataQt.horn == false)
    {
        controlDataQt.horn = true;
        ui->pushButton_horn->setStyleSheet("image: url(:/image/horn.png);border-radius: 5px;background-color: rgba(69, 229, 139, 50);");

    }
    else
    {
        controlDataQt.horn = false;
        ui->pushButton_horn->setStyleSheet("image: url(:/image/horn.png);border-radius: 5px;background-color: rgba(243, 243, 243, 30);");

    }

}


void MainWindow::on_pushButton_frontLight_clicked()
{
    if (controlDataQt.frontLight == false)
    {
        controlDataQt.frontLight = true;
        ui->pushButton_frontLight->setStyleSheet("image: url(:/image/light.png);border-radius: 5px;background-color: rgba(69, 229, 139, 50);");

    }
    else
    {
        controlDataQt.frontLight = false;
        ui->pushButton_frontLight->setStyleSheet("image: url(:/image/light.png);border-radius: 5px;background-color: rgba(243, 243, 243, 30);");
    }

}


void MainWindow::on_pushButton_clearError_clicked()
{
    if (controlDataQt.clearError == false)
    {
        controlDataQt.clearError = true;
        ui->pushButton_clearError->setStyleSheet("image: url(:/image/clearError.png);border-radius: 5px;background-color: rgba(69, 229, 139, 50);");

    }
    else
    {
        controlDataQt.clearError = false;
        ui->pushButton_clearError->setStyleSheet("image: url(:/image/clearError.png);border-radius: 5px;background-color: rgba(243, 243, 243, 30);");

    }

}


void MainWindow::on_horizontalSlider_speed_valueChanged(int value)
{
    controlDataQt.speedSetpoint = value;
    drawVelocityVector.velocityVector = drawVelocityVector.scaleVectorV * abs(controlDataQt.speedSetpoint);
//    if(controlDataQt.speedSetpoint >= 0)
//    {
//        ui->groupBox_speedDisplay->setStyleSheet("border-radius: 5px; background-color: rgba(243, 243, 243, 30)");
//    }
//    else
//    {
//        ui->groupBox_speedDisplay->setStyleSheet("border-radius: 5px; background-color: rgba(69, 229, 139, 50)");
//    }
    ui->label_SPSpeed->setText(QString::number(controlDataQt.speedSetpoint));
}

void MainWindow::on_textEdit_speed_textChanged()
{
    int temp_speedSetpoint;
    temp_speedSetpoint = ui->textEdit_speed->toPlainText().toInt();

    if(temp_speedSetpoint > 25)
    {
        temp_speedSetpoint = 25;
    }
    else if(temp_speedSetpoint < -25)
    {
        temp_speedSetpoint = -25;
    }
    else;
    controlDataQt.speedSetpoint = temp_speedSetpoint;

    drawVelocityVector.velocityVector = drawVelocityVector.scaleVectorV * abs(controlDataQt.speedSetpoint);
    ui->horizontalSlider_speed->setValue(controlDataQt.speedSetpoint);

    if(controlDataQt.speedSetpoint >= 0)
    {
        ui->groupBox_speedDisplay->setStyleSheet("border-radius: 5px; background-color: rgba(243, 243, 243, 30)");
    }
    else
    {
        ui->groupBox_speedDisplay->setStyleSheet("border-radius: 5px; background-color: rgba(69, 229, 139, 50)");
    }

    ui->label_SPSpeed->setText(QString::number(controlDataQt.speedSetpoint));
}

void MainWindow::on_pushButton_speed_clicked()
{
    controlDataQt.speedSetpoint = 0;
    ui->groupBox_speedDisplay->setStyleSheet("border-radius: 5px; background-color: rgba(243, 243, 243, 30)");
    ui->horizontalSlider_speed->setValue(controlDataQt.speedSetpoint);
    ui->label_SPSpeed->setText(QString::number(controlDataQt.speedSetpoint));
}



void MainWindow::on_pushButton_ctrlNMEA_clicked()
{
    string check = ui->comboBox_NMEA->currentText().toStdString();

    if(check == "GPRMC")
    {
        if(NMEACof.temp_cofigGPS == 0)
        {
            serialPort->write(txbuff_cofGPS_GPRMCN, 11);
            ui->pushButton_ctrlNMEA->setText("ENABLE");
            NMEACof.temp_cofigGPS = 1;
        }
        else
        {
            serialPort->write(txbuff_cofGPS_GPRMC, 11);
            ui->pushButton_ctrlNMEA->setText("DISABLE");
            NMEACof.temp_cofigGPS = 0;
        }

    }
    else if (check == "GPVTG")
    {
        if(NMEACof.temp_cofigGPS == 0)
        {
            serialPort->write(txbuff_cofGPS_GPVTGN, 11);
            ui->pushButton_ctrlNMEA->setText("ENABLE");
            NMEACof.temp_cofigGPS = 1;
        }
        else
        {
            serialPort->write(txbuff_cofGPS_GPVTG, 11);
            ui->pushButton_ctrlNMEA->setText("DISABLE");
            NMEACof.temp_cofigGPS = 0;
        }
    }
    else if (check == "GPGGA")
    {
        if(NMEACof.temp_cofigGPS == 0)
        {
            serialPort->write(txbuff_cofGPS_GPGGAN, 11);
            ui->pushButton_ctrlNMEA->setText("ENABLE");
            NMEACof.temp_cofigGPS = 1;
        }
        else
        {
            serialPort->write(txbuff_cofGPS_GPGGA, 11);
            ui->pushButton_ctrlNMEA->setText("DISABLE");
            NMEACof.temp_cofigGPS = 0;
        }
    }
    else if (check == "GPGSA")
    {
        if(NMEACof.temp_cofigGPS == 0)
        {
            serialPort->write(txbuff_cofGPS_GPGSAN, 11);
            ui->pushButton_ctrlNMEA->setText("ENABLE");
            NMEACof.temp_cofigGPS = 1;
        }
        else
        {
            serialPort->write(txbuff_cofGPS_GPGSA, 11);
            ui->pushButton_ctrlNMEA->setText("DISABLE");
            NMEACof.temp_cofigGPS = 0;
        }
    }
    else if (check == "GPGSV")
    {
        if(NMEACof.temp_cofigGPS == 0)
        {
            serialPort->write(txbuff_cofGPS_GPGSVN, 11);
            ui->pushButton_ctrlNMEA->setText("ENABLE");
            NMEACof.temp_cofigGPS = 1;
        }
        else
        {
            serialPort->write(txbuff_cofGPS_GPGSV, 11);
            ui->pushButton_ctrlNMEA->setText("DISABLE");
            NMEACof.temp_cofigGPS = 0;
        }
    }
    else
    {
        if(NMEACof.temp_cofigGPS == 0)
        {
            serialPort->write(txbuff_cofGPS_GPGLLN, 11);
            ui->pushButton_ctrlNMEA->setText("ENABLE");
            NMEACof.temp_cofigGPS = 1;
        }
        else
        {
            serialPort->write(txbuff_cofGPS_GPGLL, 11);
            ui->pushButton_ctrlNMEA->setText("DISABLE");
            NMEACof.temp_cofigGPS = 0;
        }
    }

}


void MainWindow::on_pushButton_cfgFrq_clicked()
{
    string check = ui->comboBox_FREQ->currentText().toStdString();
    if (check == "50")
    {
        serialPort->write(txbuff_cofFRQ1_50, 14);
        serialPort->write(txbuff_cofFRQ2, 8);
    }
    else if (check == "100")
    {
        serialPort->write(txbuff_cofFRQ1_100, 14);
        serialPort->write(txbuff_cofFRQ2, 8);
    }
    else if (check == "150")
    {
        serialPort->write(txbuff_cofFRQ1_150, 14);
        serialPort->write(txbuff_cofFRQ2, 8);
    }
    else if (check == "200")
    {
        serialPort->write(txbuff_cofFRQ1_200, 14);
        serialPort->write(txbuff_cofFRQ2, 8);
    }
    else if (check == "500")
    {
        serialPort->write(txbuff_cofFRQ1_500, 14);
        serialPort->write(txbuff_cofFRQ2, 8);
    }
    else;

}


void MainWindow::on_pushButton_open_clicked()
{
//    serialPort->setPortName(ui->comboBox_comUart->currentText());
    serialPort->setPortName("COM3");
    serialPort->setBaudRate(QSerialPort::Baud115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);
    serialPort->open(QIODevice::ReadWrite);
    ui->label_UART->setStyleSheet("background-color: rgb(0, 255, 0);");
    Uart_timer->start(TIMEOUTRxGPS);

}


void MainWindow::on_pushButton_close_clicked()
{
    serialPort->close();
    Uart_timer->stop();
    ui->label_UART->setStyleSheet("background-color: rgb(255, 255, 255);");

}

void MainWindow::fillPort()
{
    serialPort = new QSerialPort(this);
    Uart_timer = new QTimer(this);
    const auto infos = QSerialPortInfo::availablePorts();
    for(const QSerialPortInfo &info : infos)
    {
    ui->comboBox_comUart->addItem(info.portName());
    }

    ui->comboBox_NMEA->addItem("GPRMC");
    ui->comboBox_NMEA->addItem("GPVTG");
    ui->comboBox_NMEA->addItem("GPGGA");
    ui->comboBox_NMEA->addItem("GPGSA");
    ui->comboBox_NMEA->addItem("GPGSV");
    ui->comboBox_NMEA->addItem("GPGLL");

    ui->comboBox_FREQ->addItem("50");
    ui->comboBox_FREQ->addItem("100");
    ui->comboBox_FREQ->addItem("150");
    ui->comboBox_FREQ->addItem("200");
    ui->comboBox_FREQ->addItem("500");

}

void MainWindow::fillPortServo()
{
    ServoSerialPort = new QSerialPort(this);
    ServoTimer = new QTimer(this);
    const auto infos = QSerialPortInfo::availablePorts();
    for(const QSerialPortInfo &info : infos)
    {
        ui->comboBox_comServo->addItem(info.portName());
    }
}

void MainWindow::initUI()
{
    QString rule = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";
    ui->lineEdit_TcpClientTargetIP->setValidator(new QRegExpValidator(QRegExp("^" + rule + "\\." + rule + "\\." + rule + "\\." + rule + "$"), this));
    ui->lineEdit_TcpClientTargetPort->setValidator(new QIntValidator(0, 65535, this));

    ui->textBrowser_TcpClientMessage->setFocusPolicy(Qt::NoFocus);

    ui->lineEdit_TcpClientSend->setFocusPolicy(Qt::StrongFocus);
    ui->lineEdit_TcpClientSend->setFocus();

    ui->button_TcpClientSend->setDisabled(true);
    ui->lineEdit_TcpClientSend->setDisabled(true);
    ui->textBrowser_TcpClientMessage->setDisabled(true);

//    GUIControlData.msg_counter = 0;
//    GUIControlData.userReqAutoRun = false;
//    GUIControlData.userReqStart = false;
//    GUIControlData.userReqStop = false;
//    GUIControlData.clearError = false;
//    GUIControlData.speedSetpoint = 0;
//    GUIControlData.turnSignal = 0;
//    GUIControlData.horn = false;
//    GUIControlData.frontLight = false;
//    GUIControlData.steeringLeftRight = 0;

}

void MainWindow::loadSettings()
{
    settingsFileDir = QApplication::applicationDirPath() + "/config.ini";
    QSettings settings(settingsFileDir, QSettings::IniFormat);
    ui->lineEdit_TcpClientTargetIP->setText(settings.value("TCP_CLIENT_TARGET_IP", "192.168.0.2").toString());
    ui->lineEdit_TcpClientTargetPort->setText(settings.value("TCP_CLIENT_TARGET_PORT", 9091).toString());

}

void MainWindow::saveSettings()
{
    //    QSettings settings(settingsFileDir, QSettings::IniFormat);
    //    settings.setValue("TCP_CLIENT_TARGET_IP", ui->lineEdit_TcpClientTargetIP->text());
    //    settings.setValue("TCP_CLIENT_TARGET_PORT", ui->lineEdit_TcpClientTargetPort->text());
    //    settings.setValue("INTERFACE_INDEX", ui->comboBox_Interface->currentIndex());


    //    settings.setValue("m1_percent", m1_percent);
    //    settings.setValue("m2_percent", m2_percent);
    //    settings.setValue("m3_percent", m3_percent);
    //    settings.setValue("m4_percent", m4_percent);
    //    settings.setValue("m5_percent", m5_percent);
    //    settings.setValue("m6_percent", m6_percent);
    //    settings.setValue("m7_percent", m7_percent);

    //    settings.sync();

}

void MainWindow::findLocalIPs()
{
    ui->comboBox_Interface->clear();
    interfaceList.clear();
    QList<QNetworkInterface> listInterface = QNetworkInterface::allInterfaces();
    for (int i = 0; i < listInterface.size(); ++i)
    {
        //qDebug()<<listInterface.at(i).name();
        if (listInterface.at(i).humanReadableName().contains("Wi-Fi") || listInterface.at(i).humanReadableName().contains("wlp"))
        {
            interfaceList.append(listInterface.at(i));
        }
    }

    if (interfaceList.isEmpty())
    {
        // TODO wifilist is empty
    }
    else
    {
        for (int j = 0; j < interfaceList.size(); ++j)
        {
            ui->comboBox_Interface->addItem(interfaceList.at(j).humanReadableName());
        }
    }

}

bool MainWindow::setupConnection(quint8 type)
{
    bool isSuccess = false;
    localAddr.setAddress(ui->label_LocalIP->text());

    switch (type)
    {
    case TCPCLIENT:
        isSuccess = true;
        tcpClientTargetAddr.setAddress(ui->lineEdit_TcpClientTargetIP->text());
        tcpClientTargetPort = ui->lineEdit_TcpClientTargetPort->text().toInt();
        if (mytcpclient == nullptr)
        {
            mytcpclient = new MyTCPClient;
        }
        mytcpclient->connectTo(tcpClientTargetAddr, tcpClientTargetPort);
        break;
    }
    return isSuccess;

}


void MainWindow::on_button_Refresh_clicked()
{
    saveSettings();
    findLocalIPs();
    loadSettings();

}

void MainWindow::onTcpClientButtonClicked()
{
    disconnect(ui->button_TcpClient, SIGNAL(clicked()), this, SLOT(onTcpClientButtonClicked()));

    if (setupConnection(TCPCLIENT))
    {
//        ui->statusBar->showMessage(messageTCP + "Connecting to " + tcpClientTargetAddr.toString() + ": " + QString::number(tcpClientTargetPort), 0);
        ui->lineEdit_TcpClientTargetIP->setDisabled(true);
        ui->lineEdit_TcpClientTargetPort->setDisabled(true);
        ui->button_TcpClient->setText("Stop");

        connect(ui->button_TcpClient, SIGNAL(clicked()), this, SLOT(onTcpClientStopButtonClicked()));
        connect(mytcpclient, SIGNAL(myClientConnected(QString, quint16)), this, SLOT(onTcpClientNewConnection(QString, quint16)));
        connect(mytcpclient, SIGNAL(connectionFailed()), this, SLOT(onTcpClientTimeOut()));
    }

    saveSettings();

}


void MainWindow::onTcpClientStopButtonClicked()
{
    disconnect(ui->button_TcpClient, SIGNAL(clicked()), this, SLOT(onTcpClientStopButtonClicked()));

//    ui->statusBar->showMessage(messageTCP + "Stopped", 2000);
    disconnect(mytcpclient, SIGNAL(myClientConnected(QString, quint16)), this, SLOT(onTcpClientNewConnection(QString, quint16)));
    disconnect(mytcpclient, SIGNAL(connectionFailed()), this, SLOT(onTcpClientTimeOut()));
    ui->button_TcpClient->setText("Connect");
    mytcpclient->abortConnection();
    ui->lineEdit_TcpClientTargetIP->setDisabled(false);
    ui->lineEdit_TcpClientTargetPort->setDisabled(false);

    ui->button_TcpClientSend->setDisabled(true);
    ui->lineEdit_TcpClientSend->setDisabled(true);
    ui->textBrowser_TcpClientMessage->setDisabled(true);

    connect(ui->button_TcpClient, SIGNAL(clicked()), this, SLOT(onTcpClientButtonClicked()));

}

void MainWindow::onTcpClientDisconnectButtonClicked()
{
    mytcpclient->disconnectCurrentConnection();

}

void MainWindow::Add_Message_To_Box(const QString &from, const QString &message)
{
    QTextCursor cursor(ui->textBrowser_TcpClientMessage->textCursor());
    cursor.movePosition(QTextCursor::End);
    if (from == "System")
    {
        QColor color = ui->textBrowser_TcpClientMessage->textColor();
        ui->textBrowser_TcpClientMessage->setTextColor(Qt::red);
        ui->textBrowser_TcpClientMessage->append(message);
        ui->textBrowser_TcpClientMessage->setTextColor(color);
    }
    else
    {
//        QTextTable *table = cursor.insertTable(1, 2, tableFormat);
//        table->cellAt(0, 0).firstCursorPosition().insertText('<' + from + "> ");
//        table->cellAt(0, 1).firstCursorPosition().insertText(message);
    }
//    QScrollBar *bar = ui->textBrowser_TcpClientMessage->verticalScrollBar();
//    bar->setValue(bar->maximum());

}

void MainWindow::onTcpClientNewConnection(const QString &from, quint16 port)
{
    disconnect(mytcpclient, SIGNAL(myClientConnected(QString, quint16)), this, SLOT(onTcpClientNewConnection(QString, quint16)));
    disconnect(mytcpclient, SIGNAL(connectionFailed()), this, SLOT(onTcpClientTimeOut()));
    disconnect(ui->button_TcpClient, SIGNAL(clicked()), this, SLOT(onTcpClientStopButtonClicked()));
    connect(mytcpclient, SIGNAL(myClientDisconnected()), this, SLOT(onTcpClientDisconnected()));

    ui->button_TcpClient->setDisabled(false);
    ui->button_TcpClient->setText("Disconnect");

    ui->button_TcpClientSend->setDisabled(false);
//    ui->lineEdit_TcpClientSend->setDisabled(false);
    ui->textBrowser_TcpClientMessage->setDisabled(false);

//    ui->statusBar->showMessage(messageTCP + "Connected to " + from + ": " + QString::number(port), 0);
    connect(ui->button_TcpClient, SIGNAL(clicked()), this, SLOT(onTcpClientDisconnectButtonClicked()));

    connect(mytcpclient, SIGNAL(newMessage(QString, QString)), this, SLOT(onTcpClientAppendMessage(QString, QString)));
    connect(ui->button_TcpClientSend, SIGNAL(clicked()), this, SLOT(onTcpClientSendMessage()));
//    connect(ui->lineEdit_TcpClientSend, SIGNAL(returnPressed()), this, SLOT(onTcpClientSendMessage()));

    JsonObject sub;

    sub["op"] = "subscribe";
    sub["topic"] = "/ObjDetc_Data"; //
    sub["type"] = "/aev_pkg/object_detection_msg"; //
    mytcpclient->sendMessage(QtJson::serializeStr(sub));
    QThread::msleep(100);

    sub["topic"] = "/Radar_Data"; //
    sub["type"] = "/aev_pkg/radar_msg"; //
    mytcpclient->sendMessage(QtJson::serializeStr(sub));
    QThread::msleep(100);

    sub["topic"] = "/MPC_Data"; //
    sub["type"] = "/aev_pkg/mpc_msg"; //
    mytcpclient->sendMessage(QtJson::serializeStr(sub));
    QThread::msleep(100);

    sub["topic"] = "/SystemMonitor_Data"; //
    sub["type"] = "/aev_pkg/system_monitor_msg"; //
    mytcpclient->sendMessage(QtJson::serializeStr(sub));
    QThread::msleep(100);

    sub["topic"] = "/ECU_Feedback_Data"; //
    sub["type"] = "/aev_pkg/ecu_feedback_msg"; //
    mytcpclient->sendMessage(QtJson::serializeStr(sub));
    QThread::msleep(100);

    sub["topic"] = "/DrivingMode_Data"; //
    sub["type"] = "/aev_pkg/driving_mode_msg"; //
    mytcpclient->sendMessage(QtJson::serializeStr(sub));

    JsonObject adv = Json_Make_Advertise_Msg("GUI_Data", "aev_pkg/gui_msg");
    mytcpclient->sendMessage(QtJson::serializeStr(adv));
    Add_Message_To_Box("Me", QtJson::serialize(adv));
    ui->lineEdit_TcpClientSend->clear();

    TCP_Timer = new QTimer(this);
    connect(TCP_Timer, SIGNAL(timeout()), this, SLOT(user_Timer_Timeout()));
    TCP_Timer->start(TCPTIMERTIMEOUT);

}

void MainWindow::onTcpClientDisconnected()
{
//    ui->statusBar->showMessage(messageTCP + "Disconnected from server", 2000);
    disconnect(mytcpclient, SIGNAL(myClientDisconnected()), this, SLOT(onTcpClientDisconnected()));
    disconnect(mytcpclient, SIGNAL(newMessage(QString, QString)), this, SLOT(onTcpClientAppendMessage(QString, QString)));
    disconnect(ui->button_TcpClientSend, SIGNAL(clicked()), this, SLOT(onTcpClientSendMessage()));
    disconnect(ui->lineEdit_TcpClientSend, SIGNAL(returnPressed()), this, SLOT(onTcpClientSendMessage()));
    disconnect(ui->button_TcpClient, SIGNAL(clicked()), this, SLOT(onTcpClientDisconnectButtonClicked()));
    ui->button_TcpClient->setText("Connect");

    TCP_Timer->stop();

    ui->button_TcpClientSend->setDisabled(true);
    ui->lineEdit_TcpClientSend->setDisabled(true);
    ui->textBrowser_TcpClientMessage->setDisabled(true);

    ui->button_TcpClient->setDisabled(false);
    ui->lineEdit_TcpClientTargetIP->setDisabled(false);
    ui->lineEdit_TcpClientTargetPort->setDisabled(false);

    mytcpclient->closeClient();
    mytcpclient->close();

    connect(ui->button_TcpClient, SIGNAL(clicked()), this, SLOT(onTcpClientButtonClicked()));

}

void MainWindow::onTcpClientSendMessage()
{
    QString topic = ui->comboBox_topic->currentText();
    //    if (topic.isEmpty())
    //    {
    //        return;
    //    }
    QString type;
    if(topic == "/turtle1/cmd_vel") type = "/geometry_msgs/Twist";
    else if (topic == "/image_raw") type = "/sensor_msgs/Image";
    else if (topic == "/IMU_Depth") type = "/beginner_tutorials/IMU_Depth_Data";

    JsonObject Khang;
    Khang["op"] = "subscribe";
    Khang["topic"] = topic; //         /turtle1/cmd_vel       /image_raw
    Khang["type"] = type; //           /geometry_msgs/Twist   /sensor_msgs/Image

    mytcpclient->sendMessage(QtJson::serializeStr(Khang)); // hoặc serialize đều được

    Add_Message_To_Box("Me", QtJson::serialize(Khang));
    ui->lineEdit_TcpClientSend->clear();

//    JsonObject radar;
//    radar["op"] = "subscribe";
//    radar["topic"] = "/Radar_Data";
//    radar["type"] = "radar_msg";

//    mytcpclient->sendMessage(QtJson::serializeStr(radar)); // hoặc serialize đều được

}

QtJson::JsonObject ConvertToJson(const QString &message)
{
    bool ok;
    // json is a QString containing the JSON data
    QtJson::JsonObject result = QtJson::parse(message, ok).toMap();
    return(result);
}

void MainWindow::onTcpClientAppendMessage(const QString &from, const QString &message)
{
    if (from.isEmpty() || message.isEmpty())
    {
        return;
    }

    bool ok;
    QtJson::JsonObject result = QtJson::parse(message, ok).toMap();
    QString msg_string = QtJson::serialize(result["msg"]);
    QString topic_string = QtJson::serialize(result["topic"]);
    JsonObject msg = ConvertToJson(msg_string);

    if(topic_string == "\"/MPC_Data\"")
    {
//        quint32 msg_cnt = (QtJson::serialize(msg["msg_counter"])).toUInt();
        double msg_steering = (QtJson::serialize(msg["SteeringAngle"])).toDouble();
        ui->label_steering->setText(QString::number(msg_steering));

        if (AutoSteering_Flag == true)
        {
            SetSteeringDriverPos(- msg_steering);
        }
        else
        {

        }

//        rcSpdFromEPC.speed = (QtJson::serialize(msg["Speed"])).toInt();
//        ui->label_speed->setText(QString::number(rcDataFromEPC.speed));



    }

    if(topic_string == "\"/Radar_Data\"")
    {
        ttcRadar.numObj = (QtJson::serialize(msg["numObj"])).toUInt();

        ui->lblTTC->setText(QString::number(ttcRadar.numObj));



//        double msg_steering = (QtJson::serialize(msg["SteeringAngle"])).toDouble();
//        ui->label_steering->setText(QString::number(msg_steering));

//        rcSpdFromEPC.speed = (QtJson::serialize(msg["Speed"])).toInt();
//        ui->label_speed->setText(QString::number(rcDataFromEPC.speed));
    }

    if(topic_string == "\"/ECU_Feedback_Data\"")
    {
//        quint32 msg_cnt = (QtJson::serialize(msg["msg_counter"])).toUInt();
//        uint8_t myByteFeedbackSpeed[4];
//        myByteFeedbackSpeed[0] = (QtJson::serialize(msg["FeedbackSpeed_b1"])).toUInt();
//        myByteFeedbackSpeed[1] = (QtJson::serialize(msg["FeedbackSpeed_b2"])).toUInt();
//        myByteFeedbackSpeed[2] = (QtJson::serialize(msg["FeedbackSpeed_b3"])).toUInt();
//        myByteFeedbackSpeed[3] = (QtJson::serialize(msg["FeedbackSpeed_b4"])).toUInt();

        rcSpdFromEPC.myByte[0] = (QtJson::serialize(msg["feedbackSpeed_b1"])).toUInt();
        rcSpdFromEPC.myByte[1] = (QtJson::serialize(msg["feedbackSpeed_b2"])).toUInt();
        rcSpdFromEPC.myByte[2] = (QtJson::serialize(msg["feedbackSpeed_b3"])).toUInt();
        rcSpdFromEPC.myByte[3] = (QtJson::serialize(msg["feedbackSpeed_b4"])).toUInt();
        qInfo() << "v: " << rcSpdFromEPC.myFloat;
//        qDebug() << rcSpdFromEPC.myFloat;
        if(rcSpdFromEPC.myFloat >= 0)
        {
            ui->groupBox_speedDisplay->setStyleSheet("border-radius: 5px; background-color: rgba(243, 243, 243, 30)");
        }
        else
        {
            ui->groupBox_speedDisplay->setStyleSheet("border-radius: 5px; background-color: rgba(69, 229, 139, 50)");
        }

        ui->label_speed->setText(QString::number(round(abs(rcSpdFromEPC.myFloat))));

//        rcSpdFromEPC.speed = (QtJson::serialize(msg["Speed"])).toInt();
//        ui->label_speed->setText(QString::number(rcSpdFromEPC.speed));
    }
}


void MainWindow::onTcpClientTimeOut()
{
//    ui->statusBar->showMessage(messageTCP + "Connection time out", 2000);
    disconnect(ui->button_TcpClient, SIGNAL(clicked()), this, SLOT(onTcpClientStopButtonClicked()));
    disconnect(mytcpclient, SIGNAL(myClientConnected(QString, quint16)), this, SLOT(onTcpClientNewConnection(QString, quint16)));
    disconnect(mytcpclient, SIGNAL(connectionFailed()), this, SLOT(onTcpClientTimeOut()));

    ui->button_TcpClient->setText("Connect");
    ui->lineEdit_TcpClientTargetIP->setDisabled(false);
    ui->lineEdit_TcpClientTargetPort->setDisabled(false);

    mytcpclient->closeClient();
    connect(ui->button_TcpClient, SIGNAL(clicked()), this, SLOT(onTcpClientButtonClicked()));

}

void MainWindow::user_Timer_Timeout()
{
    controlDataQt.msg_counter++;
    GUIControlData.msg_counter = controlDataQt.msg_counter;
    GUIControlData.userReqAutoRun = controlDataQt.userReqAutoRun;
    GUIControlData.userReqStart = controlDataQt.userReqStart;
    GUIControlData.userReqStop = controlDataQt.userReqStop;
    GUIControlData.clearError = controlDataQt.clearError;
    GUIControlData.speedSetpoint = controlDataQt.speedSetpoint;
    GUIControlData.turnSignal = controlDataQt.turnSignal;
    GUIControlData.horn = controlDataQt.horn;
    GUIControlData.frontLight = controlDataQt.frontLight;
    GUIControlData.steeringLeftRight = controlDataQt.steeringLeftRight;
    GUIControlData.previewCurvature = controlDataQt.previewCurvature;

    JsonObject GUI_Output = Json_Make_GUI_Control_Data(GUIControlData);
    mytcpclient->sendMessage(QtJson::serializeStr(GUI_Output));
    Add_Message_To_Box("Me", QtJson::serialize(GUI_Output));

}

void MainWindow::SetSteeringDriverPos(float SteeringSet)
{
    uint8_t arr[9];

    if ((SteeringSet <= 0.7) && (SteeringSet >= -0.7) && (abs(SteeringSet - currentSteeringPosition_Setpoint) > 0.005))
    {
        SteeringPosition.myFloat = SteeringSet * STEERING_FACTOR;

        arr[0] = MTR_PROTOCOL_CODE_SET_REG;
        arr[1] = 6;
        arr[2] = MTR_PROTOCOL_REG_POSITION_REF;
        arr[3] = SteeringPosition.byteArray[0];
        arr[4] = SteeringPosition.byteArray[1];
        arr[5] = SteeringPosition.byteArray[2];
        arr[6] = SteeringPosition.byteArray[3];
        arr[7] = MTR_REF_POS_ABS;
        arr[8] = CalcCRC(arr[0], arr[1], arr);

        if (SteeringMotor_Init_Finish)
        {
            if (ServoSerialPort->isOpen())
            {
                qDebug() << SteeringPosition.myFloat;
                QByteArray arrSend = QByteArray((char*)arr, 9);
                ServoSerialPort->write(arrSend, 9);
                currentSteeringPosition_Setpoint = SteeringSet;
            }
        }
    }

}

void MainWindow::manualSteeringControlTimer()
{
    if (AutoSteering_Flag == false)
    {
        if (controlDataQt.steeringLeftRight == 2)
        {
            qDebug() << currentSteeringPosition_Setpoint;
            SetSteeringDriverPos((currentSteeringPosition_Setpoint - 0.05f));
        }
        else if (controlDataQt.steeringLeftRight == 1)
        {
            qDebug() << currentSteeringPosition_Setpoint;
            SetSteeringDriverPos((currentSteeringPosition_Setpoint + 0.05f));
        }
    }
}



void MainWindow::on_pushButton_steering_clicked()
{
    ServoTimer->stop();
    SetSteeringDriverPos(0.0f);
    ui->horizontalSlider_steering->setValue(0);
    controlDataQt.steeringLeftRight = 0;

    ui->pushButton_steeringLeft->setStyleSheet("image: url(:/image/minusSteering.png);border-radius: 20px;background-color: rgba(243, 243, 243, 30);");
    ui->pushButton_steeringRight->setStyleSheet("image: url(:/image/plusSteering.png);border-radius: 20px;background-color: rgba(243, 243, 243, 30);");

}



void MainWindow::on_pushButton_autoSteering_clicked()
{
    if (AutoSteering_Flag == false)
    {
        AutoSteering_Flag = true;
        ui->pushButton_autoSteering->setStyleSheet("border-radius: 20px;color: rgb(255, 255, 255);border:  2px solid rgb(69, 229, 139);background-color: rgba(69, 229, 139, 50)");

    }
    else {
        AutoSteering_Flag = false;
        ui->pushButton_autoSteering->setStyleSheet("border-radius: 20px;color: rgb(255, 255, 255);border:  2px solid rgb(69, 229, 139);background-color: rgba(243, 243, 243, 30);");

    }
}


void MainWindow::on_pushButton_openSV_clicked()
{
//    ServoSerialPort->setPortName(ui->comboBox_comUart->currentText());
    ServoSerialPort->setPortName("COM9");
    ServoSerialPort->setBaudRate(QSerialPort::Baud115200);
    ServoSerialPort->setDataBits(QSerialPort::Data8);
    ServoSerialPort->setParity(QSerialPort::NoParity);
    ServoSerialPort->setStopBits(QSerialPort::OneStop);
    ServoSerialPort->setFlowControl(QSerialPort::NoFlowControl);
    ServoSerialPort->open(QIODevice::ReadWrite);
    ui->label_serialSV->setStyleSheet("background-color: rgb(0, 255, 0);");
//    ServoTimer->start(200);

}


void MainWindow::on_pushButton_closeSV_clicked()
{
    ServoSerialPort->close();
    ServoTimer->stop();
    ui->label_serialSV->setStyleSheet("background-color: rgb(255, 255, 255);");

}

unsigned char MainWindow::CalcCRC(unsigned char uCode, unsigned char uSize, unsigned char buffer[])
{
    unsigned char uCRC = 0;
    uint16_t uSum = 0;
    unsigned char idx;
    {
        uSum += uCode;
        uSum += uSize;

        for (idx = 0; idx < uSize; idx++)
        {
            uSum += buffer[idx + 2];
        }

        uCRC = (unsigned char)(uSum & 0xFF); // Low Byte of nSum
        uCRC += (unsigned char)(uSum >> 8); // High Byte of nSum
    }

    return uCRC;
}


void MainWindow::on_pushButton_svSteeringON_clicked()
{
    uint8_t arr[4];
    arr[0] = MTR_PROTOCOL_CODE_EXECUTE_CMD;
    arr[1] = 1;
    arr[2] = MTR_PROTOCOL_CMD_SERVO_ON;
    arr[3] = CalcCRC(arr[0], arr[1], arr);
    QByteArray arrSend = QByteArray((char*)arr, 4);
    ServoSerialPort->write(arrSend, 4);

    SteeringMotor_Init_Finish = true;

}


void MainWindow::on_pushButton_svSteeringOFF_clicked()
{
    uint8_t arr[4];
    arr[0] = MTR_PROTOCOL_CODE_EXECUTE_CMD;
    arr[1] = 1;
    arr[2] = MTR_PROTOCOL_CMD_SERVO_OFF;
    arr[3] = CalcCRC(arr[0], arr[1], arr);
    QByteArray arrSend = QByteArray((char*)arr, 4);
    ServoSerialPort->write(arrSend, 4);

    SteeringMotor_Init_Finish = false;

}

void MainWindow::on_pushButton_steeringLeft_clicked()
{
    if (controlDataQt.steeringLeftRight != 1)
    {
        controlDataQt.steeringLeftRight = 1;
        ui->pushButton_steeringLeft->setStyleSheet("image: url(:/image/minusSteering.png);border-radius: 20px;background-color: rgba(69, 229, 139, 50);");
        ui->pushButton_steeringRight->setStyleSheet("image: url(:/image/plusSteering.png);border-radius: 20px;background-color: rgba(243, 243, 243, 30);");
        ServoTimer->start(STEERINGTIM);

    }
    else
    {
        controlDataQt.steeringLeftRight = 0;
        ui->pushButton_steeringLeft->setStyleSheet("image: url(:/image/minusSteering.png);border-radius: 20px;background-color: rgba(243, 243, 243, 30);");
        ui->pushButton_steeringRight->setStyleSheet("image: url(:/image/plusSteering.png);border-radius: 20px;background-color: rgba(243, 243, 243, 30);");
        ServoTimer->stop();

    }

}


void MainWindow::on_pushButton_steeringRight_clicked()
{
    if (controlDataQt.steeringLeftRight != 2)
    {
        controlDataQt.steeringLeftRight = 2;
        ui->pushButton_steeringRight->setStyleSheet("image: url(:/image/plusSteering.png);border-radius: 20px;background-color: rgba(69, 229, 139, 50);");
        ui->pushButton_steeringLeft->setStyleSheet("image: url(:/image/minusSteering.png);border-radius: 20px;background-color: rgba(243, 243, 243, 30);");
        ServoTimer->start(STEERINGTIM);

    }
    else
    {
        controlDataQt.steeringLeftRight = 0;
        ui->pushButton_steeringLeft->setStyleSheet("image: url(:/image/minusSteering.png);border-radius: 20px;background-color: rgba(243, 243, 243, 30);");
        ui->pushButton_steeringRight->setStyleSheet("image: url(:/image/plusSteering.png);border-radius: 20px;background-color: rgba(243, 243, 243, 30);");
        ServoTimer->stop();

    }

}

void MainWindow::on_horizontalSlider_steering_valueChanged(int value)
{
    if (AutoSteering_Flag == false)
    {
        float DriverPosition_set = 0.0f;

        DriverPosition_set = (float)(-value) / 100.0f;

        if ((DriverPosition_set <= 0.7) && (DriverPosition_set >= -0.7))
        {
//            qDebug() << DriverPosition_set;
            SetSteeringDriverPos(DriverPosition_set);
        }
    }
}

