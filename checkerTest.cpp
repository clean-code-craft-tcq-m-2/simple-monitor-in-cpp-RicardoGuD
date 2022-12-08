#include <assert.h>
#include <iostream>
#include "checkerTest.h"
#include "loggingServices.h"
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
    std::cout << "[RUN]TEST_warningLevel_temperatureWarningEnabled" << std::endl;
    Battery batteryTest(2, warningLevelType::warningLogsEnabled,// Min limit
                        21, warningLevelType::disabled,
                        0.0, warningLevelType::disabled);
    batteryTest.batteryIsOk();
    batteryTest.setBatteryParameter(batteryParamType::Temperature, 44);//Max limit
    batteryTest.batteryIsOk();
}

void TEST_warningLevel_stateofChargeWarningEnabled(){
    std::cout << "[RUN]TEST_warningLevel_stateofChargeWarningEnabled" << std::endl;
    Battery batteryTest(2, warningLevelType::disabled,
                        21, warningLevelType::warningLogsEnabled,// Min limit
                        0.0, warningLevelType::disabled);
    batteryTest.batteryIsOk();
    batteryTest.setBatteryParameter(batteryParamType::StateOfCharge, 79);//Max limit
    batteryTest.batteryIsOk();
}
void TEST_warningLevel_chargeRateWarningEnabled(){
      std::cout << "[RUN]TEST_warningLevel_chargeRateWarningEnabled" << std::endl;
    Battery batteryTest(2, warningLevelType::disabled,
                        21, warningLevelType::disabled,
                        0.0, warningLevelType::warningLogsEnabled);// Min limit
    batteryTest.batteryIsOk();
    batteryTest.setBatteryParameter(batteryParamType::ChargeRate, 0.79);//Max limit
    batteryTest.batteryIsOk();
}
#ifdef ENGLISH
void TEST_Language_English_Normal(){
    std::cout << "[RUN]TEST_Language_English_Normal" << std::endl;
     Battery batteryTest(20, warningLevelType::warningLogsEnabled,// Min limit
                         40, warningLevelType::warningLogsEnabled,
                        .4, warningLevelType::warningLogsEnabled);
    
    std::string expectedString = "Temperature value is within valid range\n";
    std::string actualString = logRangeWarning(batteryParamType::Temperature, batteryTest.getBatteryParameter(batteryParamType::Temperature),
                    batteryTest.getParamWarningLevel(batteryParamType::Temperature), 
                    batteryTest.calcWarningTolerances(batteryParamType::Temperature));
    assert(expectedString == actualString);

    expectedString = "State of Charge value is within valid range\n";
    actualString = logRangeWarning(batteryParamType::StateOfCharge, batteryTest.getBatteryParameter(batteryParamType::StateOfCharge),
                    batteryTest.getParamWarningLevel(batteryParamType::StateOfCharge), 
                    batteryTest.calcWarningTolerances(batteryParamType::StateOfCharge));
    assert(expectedString == actualString);

    expectedString = "Charge Rate value is within valid range\n";
    actualString = logRangeWarning(batteryParamType::ChargeRate, batteryTest.getBatteryParameter(batteryParamType::ChargeRate),
                    batteryTest.getParamWarningLevel(batteryParamType::ChargeRate), 
                    batteryTest.calcWarningTolerances(batteryParamType::ChargeRate));
    assert(expectedString == actualString);
}

void TEST_Language_English_Warning()
{
    std::cout << "[RUN]TEST_Language_English_Warning" << std::endl;
    Battery batteryTest(2, warningLevelType::warningLogsEnabled,// Min limit
                        79, warningLevelType::disabled,
                        .79, warningLevelType::disabled);
    
    std::string expectedString = "WARNING: Temperature value approaching minimum limit!\n";
    std::string actualString = logRangeWarning(batteryParamType::Temperature, batteryTest.getBatteryParameter(batteryParamType::Temperature),
                    batteryTest.getParamWarningLevel(batteryParamType::Temperature), 
                    batteryTest.calcWarningTolerances(batteryParamType::Temperature));

    assert(expectedString == actualString);
}

void TEST_Language_English_Error()
{
 std::cout << "[RUN]TEST_Language_English_Error" << std::endl;
    Battery batteryTest(100, warningLevelType::errorLogEnabled,// Min limit
        79, warningLevelType::disabled,
        .79, warningLevelType::disabled);
    batteryParamType paramType = batteryParamType::Temperature;
    std::string expectedString = "ERROR: Temperature out of range!\n";

    std::string actualString = logRangeError(paramType);
    assert(expectedString == actualString);
}
#endif
#ifdef GERMAN
void TEST_Language_German_Normal(){
    std::cout << "[RUN]TEST_Language_German_Normal" << std::endl;
     Battery batteryTest(20, warningLevelType::warningLogsEnabled,// Min limit
                         40, warningLevelType::warningLogsEnabled,
                        .4, warningLevelType::warningLogsEnabled);
    
    std::string expectedString = "Temperatur Wert liegt im gültigen Bereich\n";
    std::string actualString = logRangeWarning(batteryParamType::Temperature, batteryTest.getBatteryParameter(batteryParamType::Temperature),
                    batteryTest.getParamWarningLevel(batteryParamType::Temperature), 
                    batteryTest.calcWarningTolerances(batteryParamType::Temperature));
    assert(expectedString == actualString);

    expectedString = "Ladezustand Wert liegt im gültigen Bereich\n";
    actualString = logRangeWarning(batteryParamType::StateOfCharge, batteryTest.getBatteryParameter(batteryParamType::StateOfCharge),
                    batteryTest.getParamWarningLevel(batteryParamType::StateOfCharge), 
                    batteryTest.calcWarningTolerances(batteryParamType::StateOfCharge));
    assert(expectedString == actualString);

    expectedString = "Laderate Wert liegt im gültigen Bereich\n";
    actualString = logRangeWarning(batteryParamType::ChargeRate, batteryTest.getBatteryParameter(batteryParamType::ChargeRate),
                    batteryTest.getParamWarningLevel(batteryParamType::ChargeRate), 
                    batteryTest.calcWarningTolerances(batteryParamType::ChargeRate));
    assert(expectedString == actualString);
}
void TEST_Language_German_Warning(){
     std::cout << "[RUN]TEST_Language_German_Warning" << std::endl;
    Battery batteryTest(2, warningLevelType::warningLogsEnabled,// Min limit
                        79, warningLevelType::disabled,
                        .79, warningLevelType::disabled);
    
    std::string expectedString = "WARNUNG: Temperatur Wert nähert sich der Mindestgrenze!\n";
    std::string actualString = logRangeWarning(batteryParamType::Temperature, batteryTest.getBatteryParameter(batteryParamType::Temperature),
                    batteryTest.getParamWarningLevel(batteryParamType::Temperature), 
                    batteryTest.calcWarningTolerances(batteryParamType::Temperature));

    assert(expectedString == actualString);
}
void TEST_Language_German_Error(){
    std::cout << "[RUN]TEST_Language_German_Error" << std::endl;
    Battery batteryTest(100, warningLevelType::errorLogEnabled,// Min limit
        79, warningLevelType::disabled,
        .79, warningLevelType::disabled);
    batteryParamType paramType = batteryParamType::Temperature;
    std::string expectedString = "ERROR: Temperatur außer Reichweite!\n";

    std::string actualString = logRangeError(paramType);
    assert(expectedString == actualString);
}
#endif

#ifdef SPANISH
void TEST_Language_Spanish_Normal(){
      std::cout << "[RUN]TEST_Language_Spanish_Normal" << std::endl;
     Battery batteryTest(20, warningLevelType::warningLogsEnabled,// Min limit
                         40, warningLevelType::warningLogsEnabled,
                        .4, warningLevelType::warningLogsEnabled);
    
    std::string expectedString = "Temperatura esta dentro del rango valido\n";
    std::string actualString = logRangeWarning(batteryParamType::Temperature, batteryTest.getBatteryParameter(batteryParamType::Temperature),
                    batteryTest.getParamWarningLevel(batteryParamType::Temperature), 
                    batteryTest.calcWarningTolerances(batteryParamType::Temperature));
    assert(expectedString == actualString);

    expectedString = "Estado de la carga esta dentro del rango valido\n";
    actualString = logRangeWarning(batteryParamType::StateOfCharge, batteryTest.getBatteryParameter(batteryParamType::StateOfCharge),
                    batteryTest.getParamWarningLevel(batteryParamType::StateOfCharge), 
                    batteryTest.calcWarningTolerances(batteryParamType::StateOfCharge));
    assert(expectedString == actualString);

    expectedString = "Velocidad de carga esta dentro del rango valido\n";
    actualString = logRangeWarning(batteryParamType::ChargeRate, batteryTest.getBatteryParameter(batteryParamType::ChargeRate),
                    batteryTest.getParamWarningLevel(batteryParamType::ChargeRate), 
                    batteryTest.calcWarningTolerances(batteryParamType::ChargeRate));
    assert(expectedString == actualString);
}
void TEST_Language_Spanish_Warning(){
     std::cout << "[RUN]TEST_Language_Spanish_Warning" << std::endl;
    Battery batteryTest(2, warningLevelType::warningLogsEnabled,// Min limit
                        79, warningLevelType::disabled,
                        .79, warningLevelType::disabled);
    
    std::string expectedString = "CUIDADO: Temperatura aproximandose al valor minimo!\n";
    std::string actualString = logRangeWarning(batteryParamType::Temperature, batteryTest.getBatteryParameter(batteryParamType::Temperature),
                    batteryTest.getParamWarningLevel(batteryParamType::Temperature), 
                    batteryTest.calcWarningTolerances(batteryParamType::Temperature));

    assert(expectedString == actualString);
}
void TEST_Language_Spanish_Error(){
      std::cout << "[RUN]TEST_Language_Spanish_Error" << std::endl;
    Battery batteryTest(100, warningLevelType::errorLogEnabled,// Min limit
        79, warningLevelType::disabled,
        .79, warningLevelType::disabled);
    batteryParamType paramType = batteryParamType::Temperature;
    std::string expectedString = "ERROR: Temperatura fuera de rango!\n";

    std::string actualString = logRangeError(paramType);
    assert(expectedString == actualString);
}
#endif