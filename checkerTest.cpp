#include <assert.h>
#include <iostream>
#include "checkerTest.h"

void TEST_TemperatureValues()
{
    std::cout << "[RUN]TEST_TemperatureValues" << std::endl;
    const float TEMP_RANGE_MIN = parameterRangeMap.at(batteryParamType::Temperature).first;
    const float TEMP_RANGE_MAX = parameterRangeMap.at(batteryParamType::Temperature).second;

    Battery batteryTest;
    batteryTest.setParamWarningLevel(batteryParamType::Temperature, warningLevelType::disabled);
    //min range test
    batteryTest.setBatteryParameter(batteryParamType::Temperature, TEMP_RANGE_MIN-1);
    assert(batteryTest.isInRange(batteryParamType::Temperature) == false);
    batteryTest.setBatteryParameter(batteryParamType::Temperature, TEMP_RANGE_MIN);
    assert(batteryTest.isInRange(batteryParamType::Temperature) == true);
    batteryTest.setBatteryParameter(batteryParamType::Temperature, TEMP_RANGE_MIN+1);
    assert(batteryTest.isInRange(batteryParamType::Temperature) == true);
    //max range test
    batteryTest.setBatteryParameter(batteryParamType::Temperature, TEMP_RANGE_MAX-1);
    assert(batteryTest.isInRange(batteryParamType::Temperature) == true);
     batteryTest.setBatteryParameter(batteryParamType::Temperature, TEMP_RANGE_MAX);
    assert(batteryTest.isInRange(batteryParamType::Temperature) == true);
     batteryTest.setBatteryParameter(batteryParamType::Temperature, TEMP_RANGE_MAX+1);
    assert(batteryTest.isInRange(batteryParamType::Temperature) == false);
}

void TEST_StateOfChargeValues()
{
    std::cout << "[RUN]TEST_StateOfChargeValues" << std::endl;
    const float SOC_RANGE_MIN = parameterRangeMap.at(batteryParamType::StateOfCharge).first;
    const float SOC_RANGE_MAX = parameterRangeMap.at(batteryParamType::StateOfCharge).second;

    Battery batteryTest;
    batteryTest.setParamWarningLevel(batteryParamType::StateOfCharge, warningLevelType::disabled);
    //min range test
    batteryTest.setBatteryParameter(batteryParamType::StateOfCharge, SOC_RANGE_MIN-1);
    assert(batteryTest.isInRange(batteryParamType::StateOfCharge) == false);
    batteryTest.setBatteryParameter(batteryParamType::StateOfCharge, SOC_RANGE_MIN);
    assert(batteryTest.isInRange(batteryParamType::StateOfCharge) == true);
    batteryTest.setBatteryParameter(batteryParamType::StateOfCharge, SOC_RANGE_MIN+1);
    assert(batteryTest.isInRange(batteryParamType::StateOfCharge) == true);
    //max range test
    batteryTest.setBatteryParameter(batteryParamType::StateOfCharge, SOC_RANGE_MAX-1);
    assert(batteryTest.isInRange(batteryParamType::StateOfCharge) == true);
    batteryTest.setBatteryParameter(batteryParamType::StateOfCharge, SOC_RANGE_MAX);
    assert(batteryTest.isInRange(batteryParamType::StateOfCharge) == true);
    batteryTest.setBatteryParameter(batteryParamType::StateOfCharge, SOC_RANGE_MAX+1);
    assert(batteryTest.isInRange(batteryParamType::StateOfCharge) == false);
}

void TEST_ChargeRateValues()
{
    std::cout << "[RUN]TEST_ChargeRateValues" << std::endl;
    const float CHARGERATE_RANGE_MAX = parameterRangeMap.at(batteryParamType::ChargeRate).second;

    Battery batteryTest;
    batteryTest.setParamWarningLevel(batteryParamType::StateOfCharge, warningLevelType::disabled);
 
    //max range test
    batteryTest.setBatteryParameter(batteryParamType::ChargeRate, CHARGERATE_RANGE_MAX-0.1);
    assert(batteryTest.isInRange(batteryParamType::ChargeRate) == true);
    batteryTest.setBatteryParameter(batteryParamType::ChargeRate, CHARGERATE_RANGE_MAX);
    assert(batteryTest.isInRange(batteryParamType::ChargeRate) == true);
    batteryTest.setBatteryParameter(batteryParamType::ChargeRate, CHARGERATE_RANGE_MAX+0.1);
    assert(batteryTest.isInRange(batteryParamType::ChargeRate) == false);
}

void TEST_BatteryOK()
{
    std::cout << "[RUN]TEST_BatteryOK" << std::endl;
    Battery batteryTest(30, warningLevelType::disabled, 
                        40, warningLevelType::disabled,
                        0.6, warningLevelType::disabled);
    assert(batteryTest.batteryIsOk() == true);
}

void TEST_BatteryNotOK()
{
    std::cout << "[RUN]TEST_BatteryNotOK" << std::endl;
    Battery batteryTestTempFail(-1, warningLevelType::disabled, 
                        40, warningLevelType::disabled,
                        0.6, warningLevelType::disabled);
    assert(batteryTestTempFail.batteryIsOk() == false);

    Battery batteryTestSocFail(30, warningLevelType::disabled, 
                        100, warningLevelType::disabled,
                        0.6, warningLevelType::disabled);
    assert(batteryTestSocFail.batteryIsOk() == false);
    Battery batteryTestChargeRateFail(30, warningLevelType::disabled, 
                        40, warningLevelType::disabled,
                        1.5, warningLevelType::disabled);
    assert(batteryTestChargeRateFail.batteryIsOk() == false);
}

void TEST_warningLevel_NoWarningsEnabled()
{
    std::cout << "[RUN]TEST_warningLevel_NoWarnings" << std::endl;
    Battery batteryTest(2, warningLevelType::disabled,
                        79, warningLevelType::disabled,
                        .79, warningLevelType::disabled);
    batteryTest.batteryIsOk();
}

void TEST_warningLevel_allWarningsEnabled()
{
    std::cout << "[RUN]TEST_warningLevel_WarningsEnabled" << std::endl;
    Battery batteryTest(2, warningLevelType::warningLogsEnabled,
                        79, warningLevelType::warningLogsEnabled,
                        .79, warningLevelType::warningLogsEnabled);
    batteryTest.batteryIsOk();
}

void TEST_warningLevel_temperatureWarningEnabled()
{
    std::cout << "[RUN]TEST_warningLevel_WarningsEnabled" << std::endl;
    Battery batteryTest(2, warningLevelType::warningLogsEnabled,// Min limit
                        79, warningLevelType::disabled,
                        .79, warningLevelType::disabled);
    batteryTest.batteryIsOk();
    batteryTest.setBatteryParameter(batteryParamType::Temperature, 44);//Max limit
    batteryTest.batteryIsOk();
}

void TEST_warningLevel_stateofChargeWarningEnabled(){}
void TEST_warningLevel_chargeRateWarningEnabled(){}
void TEST_Language_English_Normal(){}
void TEST_Language_English_Warning(){}
void TEST_Language_English_Error(){}
void TEST_Language_German_Normal(){}
void TEST_Language_German_Warning(){}
void TEST_Language_German_Error(){}
void TEST_Language_Spanish_Normal(){}
void TEST_Language_Spanish_Warning(){}
void TEST_Language_Spanish_Error(){}