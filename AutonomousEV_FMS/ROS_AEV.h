/**
 * \file ROS_AEV.h
 */

#ifndef ROS_AEV_H
#define ROS_AEV_H

#include <QVariant>
#include <QString>
#include <QQueue>
#include "json.h"

using namespace std;

using QtJson::JsonObject;

//typedef struct
//{
//    double Roll;
//    double Pitch;
//    double Yaw;
//    double Depth;
//} IMU_Depth_Data;

//typedef struct
//{
//    QString Select_PID;
//    QString Config_Kx;
//    int Value;
//} K_PID_Data;

//typedef struct
//{
//    QString Manual_Mode;
//    int Duty_Value;
//} Manual_Control_Data;

//typedef struct
//{
//    QString Select_PID;
//    int Setpoint_Value;
//} Setpoint_Data;

struct GUI_Control_Data
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

JsonObject Json_Make_GUI_Control_Data(GUI_Control_Data data)
{
    JsonObject Send_Data;
    JsonObject msg;
    msg["msg_counter"] = data.msg_counter;
    msg["userReqAutoRun"] = data.userReqAutoRun;
    msg["userReqStart"] = data.userReqStart;
    msg["userReqStop"] = data.userReqStop;
    msg["clearError"] = data.clearError;
    msg["speedSetpoint"] = data.speedSetpoint;
    msg["turnSignal"] = data.turnSignal;
    msg["horn"] = data.horn;
    msg["frontLight"] = data.frontLight;
    msg["steeringLeftRight"] = data.steeringLeftRight;
    msg["previewCurvature"] = data.previewCurvature;

    Send_Data["op"] = "publish";
    Send_Data["topic"] = "GUI_Data";
    Send_Data["msg"] = msg;
    return Send_Data;
}

//JsonObject Json_Make_Setpoint_Data(QString Select_PID, double Setpoint_Value)
//{
//    JsonObject Setpoint_Data;
//    JsonObject msg;
//    msg["Select_PID"] = Select_PID;
//    msg["Setpoint_Value"] = Setpoint_Value;
//    Setpoint_Data["op"] = "publish";
//    Setpoint_Data["topic"] = "GUI_Config_Setpoint";
//    Setpoint_Data["msg"] = msg;
//    return Setpoint_Data;
//}

JsonObject Json_Make_Advertise_Msg(QString topic, QString type)
{
    JsonObject Advertise_Msg;
    Advertise_Msg["op"] = "advertise";
    Advertise_Msg["topic"] = topic;
    Advertise_Msg["type"] = type;
    return Advertise_Msg;
}

JsonObject Json_Make_Unadvertise_Msg(QString topic, QString type)
{
    JsonObject Unadvertise_Msg;
    Unadvertise_Msg["op"] = "unadvertise";
    Unadvertise_Msg["topic"] = topic;
    Unadvertise_Msg["type"] = type;
    return Unadvertise_Msg;
}

JsonObject Json_Make_Subscribe_Msg(QString topic)
{
    JsonObject Subscribe_Msg;
    Subscribe_Msg["op"] = "subscribe";
    Subscribe_Msg["topic"] = topic;
    return Subscribe_Msg;
}

JsonObject Json_Make_Unsubscribe_Msg(QString topic)
{
    JsonObject Unsubscribe_Msg;
    Unsubscribe_Msg["op"] = "unsubscribe";
    Unsubscribe_Msg["topic"] = topic;
    return Unsubscribe_Msg;
}



#endif //ROS_AEV_H
