#include <assert.h>
#include "BMS.h"

using namespace std;



int main() {
   
    BMS bms_instance;

    parameterInfo temperature{ ePARAMETER::TEMPERATURE, 0, 45 };
    parameterInfo soc{ ePARAMETER::SOC, 10, 80 };
    parameterInfo chargeRate{ ePARAMETER::CHARGE_RATE, NO_LIMIT, 80 };

    bms_instance.AddParamter(temperature);
    bms_instance.AddParamter(soc);
    bms_instance.AddParamter(chargeRate);

    assert(bms_instance.IsBatteryOK(ePARAMETER::TEMPERATURE, 40) == true);      // temperature in limit   
    assert(bms_instance.IsBatteryOK(ePARAMETER::TEMPERATURE, 46) == false);     // temperature high
    assert(bms_instance.IsBatteryOK(ePARAMETER::TEMPERATURE, -2) == false);     // temperature low
    assert(bms_instance.IsBatteryOK(ePARAMETER::SOC, 40) == true);              // SOC in limit   
    assert(bms_instance.IsBatteryOK(ePARAMETER::SOC, -2) == false);             // SOC low
    assert(bms_instance.IsBatteryOK(ePARAMETER::SOC, 90) == false);             // SOC high
    assert(bms_instance.IsBatteryOK(ePARAMETER::CHARGE_RATE, 80) == true);     // charge rate in limit
    assert(bms_instance.IsBatteryOK(ePARAMETER::CHARGE_RATE, 82) == false);     // charge rate high

}
