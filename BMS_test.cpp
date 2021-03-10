#include <assert.h>
#include "BMS.h"

using namespace std;

void ConfigureBmsParamters(BMS& bms_instance)
{
    parameterInfo temperature;
    temperature.paramterName = "Temperature";
    temperature.unit = "C";
    temperature.low_breach = 0;
    temperature.high_breach = 45;
    temperature.low_warning = 5;
    temperature.high_warning = 40;

    parameterInfo soc;
    soc.paramterName = "SOC";
    soc.unit = "NO_UNIT";
    soc.low_breach = 10;
    soc.high_breach = 80;
    soc.low_warning = 15;
    soc.high_warning = 75;

    parameterInfo chargeRate;
    chargeRate.paramterName = "ChargeRate";
    chargeRate.unit = "NO_UNIT";
    chargeRate.low_breach = NO_LIMIT;
    chargeRate.high_breach = 80;
    chargeRate.low_warning = NO_LIMIT;
    chargeRate.high_warning = 75;

    bms_instance.AddParamter(temperature);
    bms_instance.AddParamter(soc);
    bms_instance.AddParamter(chargeRate);
}

int main() {
   
    BMS bms_instance;

    ConfigureBmsParamters(bms_instance);
    
    assert(bms_instance.IsBatteryOK("Temperature", 50, "F") == true);      // temperature in limit   
    assert(bms_instance.IsBatteryOK("Temperature", 122, "F") == false);     // temperature high
    assert(bms_instance.IsBatteryOK("Temperature", 28, "F") == false);     // temperature low
    assert(bms_instance.IsBatteryOK("SOC", 40) == true);              // SOC in limit   
    assert(bms_instance.IsBatteryOK("SOC", -2) == false);             // SOC low
    assert(bms_instance.IsBatteryOK("SOC", 90) == false);             // SOC high
    assert(bms_instance.IsBatteryOK("ChargeRate", 70) == true);     // charge rate in limit
    assert(bms_instance.IsBatteryOK("ChargeRate", 82) == false);     // charge rate high

}
