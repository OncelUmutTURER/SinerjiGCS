#pragma once
#include "string"
class ArduinoCommunication
{


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
    ArduinoCommunication(bool,bool,bool,bool,bool,std::string,bool,int);
    //Parametrelerin Set etmek için kullanılan fonksiyonlar
    void SetValueIsRecord(bool); //KY --1
    void SetValueVideoSignal(bool); //VY --2
    void SetValueTelemetry(bool); //TY --3
    void SetValueArmed(bool); //AL --4
    void SetValueApplicationStart(bool); //S --5
    void SetValueCustomMode(std::string); //C --6
    void SetValueGPS3DFix(bool,bool); //GPF --7
    void SetValueBatteryStatus(int); //DB --8

    //Son değer ile karşılaştırarak mesaj değişiminde arduino'ya iletmesi için
    void SetLastValue(std::string);
    void SetArduinoConnection(bool);

    //Parametrelerin alınması için oluşturulan fonksiyonlar
    std::string  GetValue();
    std::string GetApplicationStart();
    std::string GetArmed();
    std::string GetCustomMode();
    std::string GetBatteryStatus();
    std::string GetGPS3DFix();
    std::string GetLastValue();
    std::string GetIsRecord();
    std::string GetVideoSignal();
    std::string GetTelemetry();
    bool GetIsSendMessage();
    bool GetArduinoConnection();

private:
    //Parametre tanımlarını içerir
    std::string ApplicationStart;
    std::string Armed;
    std::string CustomMode;
    int BatteryStatus;
    std::string GPS3DFix;
    std::string LastValue;
    std::string IsRecord;
    std::string VideoSignal;
    std::string Telemetry;
    bool IsSendMessage;
    bool IsArduinoConnection;

};
