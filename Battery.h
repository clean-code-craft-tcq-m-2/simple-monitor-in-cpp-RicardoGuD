#ifndef BATTERY_H
#define BATTERY_H

#include <map>

enum class batteryParamType{
    Temperature,
    StateOfCharge,
    ChargeRate
};

enum class warningLevelType{
    disabled,
    errorLogEnabled,
    warningLogsEnabled
};

static const std::pair<float, float> temperatureRange  {0.0,  45.0};
static const std::pair<float, float> stateOfChargeRange{20.0, 80.0};
static const std::pair<float, float> chargeRateRange   {0.0,  0.8};

static const std::map<batteryParamType, std::pair<float, float>> parameterRangeMap{
    {batteryParamType::Temperature,   temperatureRange},
    {batteryParamType::StateOfCharge, stateOfChargeRange},
    {batteryParamType::ChargeRate,    chargeRateRange}
};

class Battery{
    std::map<batteryParamType, float> m_parameterValueMap;
    std::map<batteryParamType, warningLevelType> m_parameterWarningLevelMap;
    
    public:
    Battery();
    Battery(float tempValue, warningLevelType tempWarningLevel,
            float stateOfChargeValue, warningLevelType stateOfChargeWarningLevel,
            float chargeRateValue, warningLevelType chargeRateWarningLevel );
    bool isInRange(batteryParamType statusType);
    bool batteryIsOk();
    std::pair<float, float> calcWarningTolerances(batteryParamType statusType);
    void setBatteryParameter(batteryParamType paramType, float tempValue);
    float getBatteryParameter(batteryParamType paramType);
    void setParamWarningLevel(batteryParamType paramType, warningLevelType warningLevel);
    warningLevelType getParamWarningLevel(batteryParamType paramType);
        
};

#endif//BATTERY_H