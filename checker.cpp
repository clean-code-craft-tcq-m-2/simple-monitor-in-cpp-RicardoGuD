#include <assert.h>
#include "Battery.h"
#include "checkerTest.h"

int main() {
  TEST_TemperatureValues();
  TEST_StateOfChargeValues();
  TEST_ChargeRateValues();
  TEST_BatteryOK();

  TEST_warningLevel_NoWarningsEnabled();
  TEST_warningLevel_allWarningsEnabled();
  TEST_warningLevel_temperatureWarningEnabled();
}
