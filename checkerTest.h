#ifndef CHECKERTEST_H
#define CHECKERTEST_H

#include "Battery.h"

void TEST_TemperatureValues();
void TEST_StateOfChargeValues();
void TEST_ChargeRateValues();
void TEST_BatteryOK();
void TEST_BatteryNotOK();

void TEST_warningLevel_NoWarningsEnabled();
void TEST_warningLevel_allWarningsEnabled();
void TEST_warningLevel_temperatureWarningEnabled();
void TEST_warningLevel_stateofChargeWarningEnabled();
void TEST_warningLevel_chargeRateWarningEnabled();
#ifdef ENGLISH
void TEST_Language_English_Normal();
void TEST_Language_English_Warning();
void TEST_Language_English_Error();
#endif
#ifdef GERMAN
void TEST_Language_German_Normal();
void TEST_Language_German_Warning();
void TEST_Language_German_Error();
#endif
#ifdef SPANISH
void TEST_Language_Spanish_Normal();
void TEST_Language_Spanish_Warning();
void TEST_Language_Spanish_Error();
#endif
#endif