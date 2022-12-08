#ifndef LOGGINGSERVICES_H
#define LOGGINGSERVICES_H
#include <iostream>
#include <string>
#include "Battery.h"
#include "globalizationStrings.h"

std::string logRangeError(batteryParamType& paramType);

bool areRangeWarningEnabled(warningLevelType warningLevel);

std::string createWarningText(batteryParamType paramType, float paramValue, std::pair<float, float> rangeLimits);
std::string logRangeWarning(batteryParamType paramType, float paramValue,
                            warningLevelType warningLevel, std::pair<float, float> rangeLimits);
#endif