#ifndef GLOBALIZATIONSTRINGS_H
#define GLOBALIZATIONSTRINGS_H

#include <string>

static const std::map<batteryStatusType, std::string> batteryStatusStrings{
    {batteryStatusType::Temperature,   "Temperature"},
    {batteryStatusType::StateOfCharge,"State Of Charge"},
    {batteryStatusType::ChargeRate,    "Charge Rate"}
};

#endif