#include "Battery.h"
#include "loggingServices.h"

Battery::Battery() 
{
    m_parameterValueMap = {{batteryParamType::Temperature,   0.0},
                           {batteryParamType::StateOfCharge, 0.0},
                           {batteryParamType::ChargeRate,    0.0}
    };
    m_parameterWarningLevelMap = {{batteryParamType::Temperature,   warningLevelType::disabled},
                                  {batteryParamType::StateOfCharge, warningLevelType::disabled},
                                  {batteryParamType::ChargeRate,    warningLevelType::disabled}
    };
}

Battery::Battery(float tempValue, warningLevelType tempWarningLevel,
        float stateOfChargeValue, warningLevelType stateOfChargeWarningLevel,
        float chargeRateValue, warningLevelType chargeRateWarningLevel )
        {
            m_parameterValueMap = {{batteryParamType::Temperature,   tempValue},
                                   {batteryParamType::StateOfCharge, stateOfChargeValue},
                                   {batteryParamType::ChargeRate,    chargeRateValue}
                                  };
            m_parameterWarningLevelMap = {{batteryParamType::Temperature,   tempWarningLevel},
                                          {batteryParamType::StateOfCharge, stateOfChargeWarningLevel},
                                          {batteryParamType::ChargeRate,    chargeRateWarningLevel}
                                         };
        }

bool Battery::isInRange(batteryParamType paramType)
{
    bool isInRange = false;
    float l_paramValue = m_parameterValueMap.at(paramType);
    warningLevelType l_warningLevel = m_parameterWarningLevelMap.at(paramType);

    if(l_paramValue >= parameterRangeMap.at(paramType).first && 
       l_paramValue <= parameterRangeMap.at(paramType).second)
    {
        isInRange = true;
        std::cout << logRangeWarning( paramType, l_paramValue, l_warningLevel, calcWarningTolerances(paramType));
    }
    else
    {
        std::cout << logRangeError(paramType);
    }
    return isInRange;
}
    
bool Battery::batteryIsOk()
{
        return (isInRange(batteryParamType::Temperature) &&
        isInRange(batteryParamType::StateOfCharge) &&
        isInRange(batteryParamType::ChargeRate));
}

std::pair<float, float> Battery::calcWarningTolerances(batteryParamType paramType)
{
    const float TOLERANCE = 0.05;//tolerance of 5%
    std::pair<float, float> warningToleranceLimits{0,0};
    
    float limitTolerance = parameterRangeMap.at(paramType).second * TOLERANCE;

    float minWarningTolerance = parameterRangeMap.at(paramType).first  + limitTolerance;
    float maxWarningTolerance = parameterRangeMap.at(paramType).second - limitTolerance;
    
    warningToleranceLimits = std::make_pair(minWarningTolerance, maxWarningTolerance);
    return warningToleranceLimits;
}

void Battery::setBatteryParameter(batteryParamType paramType, float tempValue){
    m_parameterValueMap.at(paramType) = tempValue;
}

float Battery::getBatteryParameter(batteryParamType paramType){
    return m_parameterValueMap.at(paramType);
}

void Battery::setParamWarningLevel(batteryParamType paramType, warningLevelType warningLevel){
    m_parameterWarningLevelMap.at(paramType) = warningLevel;
}

warningLevelType Battery::getParamWarningLevel(batteryParamType paramType){
    return m_parameterWarningLevelMap.at(paramType);
}