#include "arduinocommunication.h"
#include "string"

using namespace std;

ArduinoCommunication::ArduinoCommunication(bool a, bool b, int c, int d,bool e)
{
    SetValueApplicationStart(a);
    SetValueArmed(b);
    SetValueCustomMode(c);
    SetValueBatteryStatus(d);
    SetValueGPS3DFix(e,false);
}

void ArduinoCommunication::SetValueApplicationStart(bool x)
{
    if(x)
        ApplicationStart="H";
    else
        ApplicationStart="L";
}
void ArduinoCommunication::SetValueArmed(bool y)
{
    if(y)
        Armed="H";
    else
        Armed="L";
}
void ArduinoCommunication::SetValueCustomMode(int z)
{
    CustomMode=z;
}
void ArduinoCommunication::SetValueBatteryStatus(int d)
{
    BatteryStatus=d;
}
void ArduinoCommunication::SetValueGPS3DFix(bool e,bool g)
{
    IsSendMessage=g;
    if(e)
        GPS3DFix="H";
    else
        GPS3DFix="L";
}
void ArduinoCommunication::SetLastValue(string f)
{
    LastValue=f;
}
std::string ArduinoCommunication::GetValue()
{
    string s="S"+ApplicationStart+"AL"+Armed+"C"+std::to_string(CustomMode)+"DB"+std::to_string(BatteryStatus)+"GPF"+GPS3DFix;
    return s;
}
std::string ArduinoCommunication::GetApplicationStart()
{
    string s="S"+ApplicationStart;
    return s;
}
std::string ArduinoCommunication::GetArmed()
{
    string s="AL"+Armed;
    return s;
}
std::string ArduinoCommunication::GetCustomMode()
{
    string s="C"+std::to_string(CustomMode);
    return s;
}
std::string ArduinoCommunication::GetBatteryStatus()
{
    string s="DB"+std::to_string(BatteryStatus);
    return s;
}
std::string ArduinoCommunication::GetGPS3DFix()
{
    string s="GPF"+GPS3DFix;
    return s;
}
std::string ArduinoCommunication::GetLastValue()
{
    return LastValue;
}
bool ArduinoCommunication::GetIsSendMessage()
{
    return  IsSendMessage;
}
