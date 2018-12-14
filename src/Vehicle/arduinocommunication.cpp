#include "arduinocommunication.h"
#include "string"
#include "QCameraInfo"


using namespace std;

ArduinoCommunication::ArduinoCommunication(bool a, bool b,bool c, bool d,bool e, string f,bool g, int h)
{
    SetValueIsRecording(a);
    SetValueHasVideoSignal(b);
    SetValueHasTelemetrySignal(c);
    SetValueIsArmed(d);
    SetValueIsApplicationStarted(e);
    SetValueFlightMode(f);
    SetValueIsGPS3dFixed(g); //,false
    SetValueBatteryRemaining(h);
//    SetArduinoConnection(true);
}

//void ArduinoCommunication::SetArduinoConnection(bool x)
//{
//    IsArduinoConnection=x;
//}
void ArduinoCommunication::SetValueIsRecording(bool a)
{
    if(a)
        IsRecording="L";
    else
        IsRecording="H";
}
void ArduinoCommunication::SetValueHasVideoSignal(bool b)
{
    if(b)
        HasVideoSignal="L";
    else
        HasVideoSignal="H";
}

void ArduinoCommunication::SetValueHasTelemetrySignal(bool c)
{
    if(c)
        HasTelemetrySignal="L";
    else
        HasTelemetrySignal="H";
}
void ArduinoCommunication::SetValueIsArmed(bool d)
{
    if(d)
        IsArmed="L";
    else
        IsArmed="H";
}
void ArduinoCommunication::SetValueIsApplicationStarted(bool e)
{
    if(e)
        IsApplicationStarted="L";
    else
        IsApplicationStarted="H";
}

void ArduinoCommunication::SetValueFlightMode(std::string f)
{
    FlightMode = f;
}

void ArduinoCommunication::SetValueIsGPS3dFixed(bool g) //,bool h
{
//    IsSendMessage=h;
    if(g)
        IsGPS3dFixed="L";
    else
        IsGPS3dFixed="H";
}
void ArduinoCommunication::SetValueBatteryRemaining(int h)
{
    BatteryRemaining=QString::number(h).rightJustified(3, '0').toStdString();
}
//void ArduinoCommunication::SetLastValue(string f)
//{
//    LastValue=f;
//}
std::string ArduinoCommunication::GetValue()
{
    string s="KY"+IsRecording+"VY"+HasVideoSignal+"TY"+HasTelemetrySignal+"AL"+IsArmed+"S"+IsApplicationStarted+"C"+FlightMode+"GPF"+IsGPS3dFixed+"DB"+BatteryRemaining;
    return s;
}
std::string ArduinoCommunication::GetIsRecording()
{
    string s="KY"+IsRecording;
    return s;
}
std::string ArduinoCommunication::GetHasVideoSignal()
{
    string s="VY"+HasVideoSignal;
    return s;
}
std::string ArduinoCommunication::GetHasTelemetrySignal()
{
    string s="TY"+HasTelemetrySignal;
    return s;
}
std::string ArduinoCommunication::GetIsArmed()
{
    string s="AL"+IsArmed;
    return s;
}
std::string ArduinoCommunication::GetIsApplicationStarted()
{
    string s="S"+IsApplicationStarted;
    return s;
}
std::string ArduinoCommunication::GetFlightMode()
{
    string s="C"+FlightMode;
    return s;
}
std::string ArduinoCommunication::GetIsGPS3dFixed()
{
    string s="GPF"+IsGPS3dFixed;
    return s;
}
std::string ArduinoCommunication::GetBatteryRemaining()
{
    string s="DB"+BatteryRemaining;
    return s;
}
//std::string ArduinoCommunication::GetLastValue()
//{
//    return LastValue;
//}
//bool ArduinoCommunication::GetIsSendMessage()
//{
//    return  IsSendMessage;
//}
//bool ArduinoCommunication::GetArduinoConnection()
//{
//    return  IsArduinoConnection;
//}

bool ArduinoCommunication::SetVideoSignalValueAndReturnIsChanged()
{
    const QList<QCameraInfo> availableCameras = QCameraInfo::availableCameras();

    if(availableCameras.count() > 1) //PC'nin webcam'i olduğundan ekstra bir video source var mı diye kontrol ediyoruz
    {
        if(GetHasVideoSignal() != "VYL"){
            SetValueHasVideoSignal(true);
            return true;
        }
    }
    else
    {
        if(GetHasVideoSignal() != "VYH"){
            SetValueHasVideoSignal(false);
            return true;
        }
    }
    return  false;
}
