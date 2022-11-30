#include "rangeCheck.h"
#include "globalizationStrings.h"

std::string logRangeError(batteryStatusType& statusType){
   
    std::string errorText = batteryStatusStrings.at(statusType) + " out of range!\n";
    return errorText;
}

bool isInRange(batteryStatusType statusType, float& batteryStatusValue){
    bool isInRange = false;
    if(batteryStatusValue >= validRangesMap.at(statusType).first && 
       batteryStatusValue <= validRangesMap.at(statusType).second)
       {
        isInRange = true;
       }
       else{
        std::cout << logRangeError(statusType);
       }
       return isInRange;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  return (isInRange(batteryStatusType::Temperature, temperature) &&
          isInRange(batteryStatusType::StateOfCharge, soc)       &&
          isInRange(batteryStatusType::ChargeRate, chargeRate));
}
