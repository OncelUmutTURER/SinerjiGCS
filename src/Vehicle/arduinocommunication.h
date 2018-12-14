//#ifndef ARDUINOCOMMUNICATION_H
//#define ARDUINOCOMMUNICATION_H

//#include <QObject>

#pragma once

#include "string"

class ArduinoCommunication //: public QObject
{
//    Q_OBJECT

public:
    ArduinoCommunication(bool, bool, bool, bool, bool, std::string, bool, int); //(false,false,false,false,true,"0",false,0);

    //Parametrelerin Set etmek için kullanılan fonksiyonlar
    void SetValueIsRecording(bool); //KY --1
    void SetValueHasVideoSignal(bool); //VY --2
    void SetValueHasTelemetrySignal(bool); //TY --3
    void SetValueIsArmed(bool); //AL --4
    void SetValueIsApplicationStarted(bool); //S --5
    void SetValueFlightMode(std::string); //C --6
    void SetValueIsGPS3dFixed(bool); //GPF --7  //,bool
    void SetValueBatteryRemaining(int); //DB --8

    //Parametrelerin alınması için oluşturulan fonksiyonlar
    std::string  GetValue();
    std::string GetIsApplicationStarted();
    std::string GetIsArmed();
    std::string GetFlightMode();
    std::string GetBatteryRemaining();
    std::string GetIsGPS3dFixed();
    std::string GetIsRecording();
    std::string GetHasVideoSignal();
    std::string GetHasTelemetrySignal();

    bool SetVideoSignalValueAndReturnIsChanged(void);

private:
    //Parametre tanımlarını içerir
    std::string IsRecording = "H";
    std::string HasVideoSignal = "H";
    std::string HasTelemetrySignal = "H";
    std::string IsArmed = "H";
    std::string IsApplicationStarted = "L";
    std::string FlightMode = "0";
    std::string IsGPS3dFixed = "H";
    std::string BatteryRemaining = "000";
};

//#endif  //ARDUINOCOMMUNICATION_H
