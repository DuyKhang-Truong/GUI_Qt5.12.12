QT       += core gui network quickwidgets serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accesstonet.cpp \
    astaralgorithm.cpp \
    json.cpp \
    main.cpp \
    mainwindow.cpp \
    mymaplayers.cpp \
    mytcpclient.cpp \
    radarscan.cpp

HEADERS += \
    ROS_AEV.h \
    accesstonet.h \
    astaralgorithm.h \
    json.h \
    mainwindow.h \
    mymaplayers.h \
    mytcpclient.h \
    radarscan.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources/qml.qrc \
    Resources/radarScan/resourceRadarScan.qrc

DISTFILES += \
    Resources/back.png \
    Resources/car.ico \
    Resources/clearError.png \
    Resources/dir.png \
    Resources/dirDis.png \
    Resources/horn.png \
    Resources/left.png \
    Resources/leftDis.png \
    Resources/light.png \
    Resources/minusSteering.png \
    Resources/next.png \
    Resources/plusSteering.png \
    Resources/right.png \
    Resources/rightDis.png \
    Resources/steeringWheel.png \
    Resources/straight.png \
    Resources/straightDis.png \
    Resources/turnLeft.png \
    Resources/turnRight.png
