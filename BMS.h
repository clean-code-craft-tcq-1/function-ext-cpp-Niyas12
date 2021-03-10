#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define NO_LIMIT -555555.0

enum ePARAMETER
{
    TEMPERATURE,
    SOC,
    CHARGE_RATE
};

struct parameterInfo
{
    std::string paramterName;
    float low_breach;
    float low_warning;
    float high_breach;
    float high_warning;
};


class BMS
{
    vector<parameterInfo> paramterList;
    
    bool ValidateHighBreach(float value, parameterInfo &info);
    bool ValidateLowBreach(float value, parameterInfo &info);
    bool ValidateBreach(float value, parameterInfo& info);
    bool ValidateWarningLevel(float value, parameterInfo& info);
    bool ValidateHighWarning(float value, parameterInfo &info);
    bool ValidateLowWarning(float value, parameterInfo &info);
    bool ValidateRange(float value, parameterInfo &info);

public:
    BMS();
    void AddParamter(parameterInfo info);
    void RemoveParamter(parameterInfo info);

    bool IsBatteryOK(std::string parameterName, float value);
};
