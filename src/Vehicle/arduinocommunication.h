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

    ArduinoCommunication(bool,bool,int,int,bool);
    void SetValueApplicationStart(bool);
    void SetValueArmed(bool);
    void SetValueCustomMode(int);
    void SetValueBatteryStatus(int);
    void SetValueGPS3DFix(bool,bool);
    void SetLastValue(std::string);
    std::string  GetValue();
    std::string GetApplicationStart();
    std::string GetArmed();
    std::string GetCustomMode();
    std::string GetBatteryStatus();
    std::string GetGPS3DFix();
    std::string GetLastValue();
    bool GetIsSendMessage();

private:
    std::string ApplicationStart;
    std::string Armed;
    int CustomMode;
    int BatteryStatus;
    std::string GPS3DFix;
    std::string LastValue;
    bool IsSendMessage;
/*private:
    Fact        _connected; ///< is an RTK gps connected?
    Fact        _currentDuration; ///< survey-in status in [s]
    Fact        _currentAccuracy; ///< survey-in accuracy in [mm]
    Fact        _valid; ///< survey-in valid?
    Fact        _active; ///< survey-in active?
    Fact        _numSatellites; ///< number of satellites*/
};
