#include "BMS.h"

BMS::BMS()
{
}

bool BMS::ValidateMax(float value, float max)
{
    if (max != NO_LIMIT)
    {
        return max >= value;
    }
    return true;
}
bool BMS::ValidateMin(float value, float min)
{
    if (min != NO_LIMIT)
    {
        return min <= value;
    }
    return true;
}
bool BMS::ValidateRange(float value, float min, float max)
{
    return ValidateMax(value, max) && ValidateMin(value, min);
}

void BMS::AddParamter(parameterInfo info)
{
    auto itr = find_if(paramterList.begin(), paramterList.end(), [&](parameterInfo listInfo) {
        return listInfo.eParameter == info.eParameter;
    });

    if (itr == paramterList.end())
    {
        paramterList.push_back(info);
    }
}

void BMS::RemoveParamter(parameterInfo info)
{
    auto itr = find_if(paramterList.begin(), paramterList.end(), [&](parameterInfo listInfo) {
        return listInfo.eParameter == info.eParameter;
    });

    if (itr != paramterList.end())
    {
        paramterList.erase(itr);
    }
}


bool BMS::IsBatteryOK(ePARAMETER type, float value)
{
    auto itr = find_if(paramterList.begin(), paramterList.end(), [&](parameterInfo listInfo) {
        return listInfo.eParameter == type;
    });

    if (itr != paramterList.end())
    {
        return ValidateRange(value, itr->min, itr->max);
    }
}
