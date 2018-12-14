//#ifndef ARDUINOCOMMUNICATION_H
//#define ARDUINOCOMMUNICATION_H

//#include <QObject>

#pragma once

#include "string"

class ArduinoCommunication //: public QObject
{
//    Q_OBJECT

public:
    /* ArduinoCommunication(QObject* parent = NULL);

    Q_PROPERTY(Fact* connected            READ connected            CONSTANT)
    Q_PROPERTY(Fact* currentDuration      READ currentDuration      CONSTANT)
    Q_PROPERTY(Fact* currentAccuracy      READ currentAccuracy      CONSTANT)
    Q_PROPERTY(Fact* valid                READ valid                CONSTANT)
    Q_PROPERTY(Fact* active               READ active               CONSTANT)
    Q_PROPERTY(Fact* numSatellites        READ numSatellites        CONSTANT)

    Fact* connected                    (void) { return &_connected; }
    Fact* currentDuration              (void) { return &_currentDuration; }
    Fact* currentAccuracy              (void) { return &_currentAccuracy; }
    Fact* valid                        (void) { return &_valid; }
    Fact* active                       (void) { return &_active; }
    Fact* numSatellites                (void) { return &_numSatellites; }*/

    //Default olarak tek seferlik değer atamaları için kullanılır
    //ArduinoCommunication(bool,bool,int,int,bool);

//    ArduinoCommunication();
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

    //Son değer ile karşılaştırarak mesaj değişiminde arduino'ya iletmesi için
//    void SetLastValue(std::string);
//    void SetArduinoConnection(bool);

    //Parametrelerin alınması için oluşturulan fonksiyonlar
    std::string  GetValue();
    std::string GetIsApplicationStarted();
    std::string GetIsArmed();
    std::string GetFlightMode();
    std::string GetBatteryRemaining();
    std::string GetIsGPS3dFixed();
//    std::string GetLastValue();
    std::string GetIsRecording();
    std::string GetHasVideoSignal();
    std::string GetHasTelemetrySignal();
//    bool GetIsSendMessage();
//    bool GetArduinoConnection();

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
//    std::string LastValue;
//    bool IsSendMessage;
//    bool IsArduinoConnection;

};

//#endif  //ARDUINOCOMMUNICATION_H
