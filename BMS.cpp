#include "BMS.h"

BMS::BMS()
{
}

bool BMS::ValidateHighBreach(float value, parameterInfo& info)
{
    if (info.high_breach != NO_LIMIT)
    {        
        auto status = info.high_breach >= value;
        if (!status)
        {
            std::cout << info.paramterName << " : high breach\n";
        }
        
        return status;
    }
    return true;
}
bool BMS::ValidateLowBreach(float value, parameterInfo& info)
{
    if (info.low_breach != NO_LIMIT)
    {      
        auto status = info.low_breach <= value;
        if (!status)
        {
            std::cout << info.paramterName << " : Low breach\n";
        }

        return status;
    }
    return true;
}
bool BMS::ValidateHighWarning(float value, parameterInfo& info)
{
    if (info.high_warning != NO_LIMIT)
    {        
        auto status = info.high_warning >= value;
        if (!status)
        {
            std::cout << "Warning : " << info.paramterName << " is high\n";
        }

        return status;
    }
    return true;
}
bool BMS::ValidateLowWarning(float value, parameterInfo& info)
{
    if (info.low_warning != NO_LIMIT)
    {        
        auto status = info.low_warning <= value;
        if (!status)
        {
            std::cout << "Warning : " << info.paramterName << " is low\n";
        }

        return status;
    }
    return true;
}
bool BMS::ValidateRange(float value, parameterInfo& info)
{
    return ValidateBreach(value, info) && ValidateWarningLevel(value, info);
}

bool BMS::ValidateBreach(float value, parameterInfo& info)
{
    return ValidateHighBreach(value, info) && ValidateLowBreach(value, info);
}
bool BMS::ValidateWarningLevel(float value, parameterInfo& info)
{
    return ValidateHighWarning(value, info) && ValidateLowWarning(value, info);
}

void BMS::AddParamter(parameterInfo info)
{
    auto itr = find_if(paramterList.begin(), paramterList.end(), [&](parameterInfo listInfo) {
        return listInfo.paramterName == info.paramterName;
    });

    if (itr == paramterList.end())
    {
        paramterList.push_back(info);
    }
}

void BMS::RemoveParamter(parameterInfo info)
{
    auto itr = find_if(paramterList.begin(), paramterList.end(), [&](parameterInfo listInfo) {
        return listInfo.paramterName == info.paramterName;
    });

    if (itr != paramterList.end())
    {
        paramterList.erase(itr);
    }
}


bool BMS::IsBatteryOK(std::string parameterName, float value)
{
    auto itr = find_if(paramterList.begin(), paramterList.end(), [&](parameterInfo listInfo) {
        return listInfo.paramterName == parameterName;
    });

    if (itr != paramterList.end())
    {
        return ValidateRange(value, *itr);
    }
}
