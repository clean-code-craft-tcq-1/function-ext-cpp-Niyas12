#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

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
    ePARAMETER eParameter;
    float min;
    float max;
};


class BMS
{
    vector<parameterInfo> paramterList;

    bool ValidateMax(float value, float max);
    bool ValidateMin(float value, float min);
    bool ValidateRange(float value, float min, float max);

public:
    BMS();
    void AddParamter(parameterInfo info);
    void RemoveParamter(parameterInfo info);

    bool IsBatteryOK(ePARAMETER type, float value);
};
