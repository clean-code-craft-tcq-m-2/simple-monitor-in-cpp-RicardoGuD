#ifndef LOGGINGSERVICES_H
#define LOGGINGSERVICES_H
#include <iostream>
#include <string>
#include "Battery.h"
#include "globalizationStrings.h"

std::string logRangeError(batteryParamType& paramType){
   
    std::string errorText = glbStr_Error + glbStr_paramType.at(paramType)+ " " + glbStr_out_of_range +"\n";
    return errorText;
}

bool areRangeWarningEnabled(warningLevelType warningLevel)
{
    return warningLevel == warningLevelType::warningLogsEnabled;
}

std::string createWarningText(batteryParamType paramType, float paramValue, std::pair<float, float> rangeLimits) 
{
    std::string warningText = glbStr_paramType.at(paramType) + glbStr_valWithinValidRange + "\n";
    if(paramValue <= rangeLimits.first)
    {  
         warningText = glbStr_Warning + glbStr_paramType.at(paramType) + glbStr_apprchMinLim + "\n";
    }
    if(paramValue >= rangeLimits.second){
         warningText = glbStr_Warning + glbStr_paramType.at(paramType) + glbStr_apprchMaxLim + "\n";
    }
    return warningText;
}
std::string logRangeWarning(batteryParamType paramType, float paramValue,
                            warningLevelType warningLevel, std::pair<float, float> rangeLimits)
{
    std::string warningText = "";
    if(areRangeWarningEnabled(warningLevel))
    {
        warningText = createWarningText(paramType, paramValue, rangeLimits);
    }
    return warningText;
}

#endif