#include "mainwindow.h"
#include "accesstonet.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    radarScan   RadarScan;
    RadarScan.initParamTTC();
    RadarScan.initGraphicRadar();
    RadarScan.plotDetectObj();

    w.show();

    AccessToNet accessToNet;

    /****get data****/
//    accessToNet.get("https://autocartech.000webhostapp.com/searchGPSdata.php?frame_ID=3");

//    //posr data
//    QByteArray data;
//    data.append("param1=hello");
//    data.append("&");
//    data.append("param2=bye");
//    accessToNet.post("https://autocartech.000webhostapp.com/searchClient.php?client_ID=2", data);

//    QByteArray data;
//    data.append("4");
//    data.append("77.32");
//    data.append("10.32");
//    data.append("3.21");
//    accessToNet.post("https://autocartechnology.000webhostapp.com", data);

    return a.exec();
}
