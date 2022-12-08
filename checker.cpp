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
  TEST_warningLevel_stateofChargeWarningEnabled();
  TEST_warningLevel_chargeRateWarningEnabled();
  #ifdef ENGLISH
  TEST_Language_English_Normal();
  TEST_Language_English_Warning();
  TEST_Language_English_Error();
  #endif
   #ifdef GERMAN
  TEST_Language_German_Normal();
  TEST_Language_German_Warning();
  TEST_Language_German_Error();
  #endif
}
