#ifndef RANGECHECK_H
#define RANGECHECK_H

#include <iostream>
#include "validRangesDef.h"

using namespace rangeDefinition;
std::string logRangeError(batteryStatusType& statusType);
bool isInRange(batteryStatusType statusType, float& batteryStatusValue);
bool batteryIsOk(float temperature, float soc, float chargeRate);
 
#endif