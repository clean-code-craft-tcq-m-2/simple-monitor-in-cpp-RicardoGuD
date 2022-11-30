#ifndef RANGES_H
#define RANGES_H

#include <map>

namespace rangeDefinition
{
enum class batteryStatusType{
    Temperature,
    StateOfCharge,
    ChargeRate
};

static const std::pair<float, float> temperatureRange  {0.0,  45.0};
static const std::pair<float, float> stateOfChargeRange{20.0, 80.0};
static const std::pair<float, float> chargeRateRange   {0.0,  0.8};

static const std::map<batteryStatusType, std::pair<float, float>> validRangesMap{
    {batteryStatusType::Temperature,   temperatureRange},
    {batteryStatusType::StateOfCharge, stateOfChargeRange},
    {batteryStatusType::ChargeRate,    chargeRateRange}
};

}

#endif