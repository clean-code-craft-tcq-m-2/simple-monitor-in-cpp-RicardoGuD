#ifndef GLOBALIZATIONSTRINGS_H
#define GLOBALIZATIONSTRINGS_H
/*--------------------language used------------------*/
#define ENGLISH
//#define GERMAN
//#define SPANISH
/*----------------------------------------------------*/
#include <string>
#include <map>
#include "Battery.h"
typedef std::string globalizationString;

#ifdef ENGLISH
static const globalizationString glbStr_out_of_range = "out of range!";
static const globalizationString glbStr_Warning = "WARNING: ";
static const globalizationString glbStr_Error = "ERROR: ";
static const globalizationString glbStr_apprchMinLim = " value approaching minimum limit!";
static const globalizationString glbStr_apprchMaxLim = " value approaching maximum limit!";
static const globalizationString glbStr_valWithinValidRange = " value is within valid range";

static const std::map<batteryParamType, std::string> glbStr_paramType{
    {batteryParamType::Temperature,   "Temperature"},
    {batteryParamType::StateOfCharge,"State Of Charge"},
    {batteryParamType::ChargeRate,    "Charge Rate"}
};
#endif//ENGLISH

#ifdef GERMAN
static const globalizationString glbStr_out_of_range = "außer Reichweite!";
static const globalizationString glbStr_Warning = "WARNUNG: ";
static const globalizationString glbStr_Error = "ERROR: ";
static const globalizationString glbStr_apprchMinLim = " Wert nähert sich der Mindestgrenze!";
static const globalizationString glbStr_apprchMaxLim = " Wert nähert sich der Höchstgrenze!";
static const globalizationString glbStr_valWithinValidRange = " Wert liegt im gültigen Bereich";

static const std::map<batteryParamType, std::string> glbStr_paramType{
    {batteryParamType::Temperature,   "Temperatur"},
    {batteryParamType::StateOfCharge,"Ladezustand"},
    {batteryParamType::ChargeRate,    "Laderate"}
};
#endif//GERMAN

#ifdef SPANISH
static const globalizationString glbStr_out_of_range = "fuera de rango!";
static const globalizationString glbStr_Warning = "CUIDADO: ";
static const globalizationString glbStr_Error = "ERROR: ";
static const globalizationString glbStr_apprchMinLim = " aproximandose al valor minimo!";
static const globalizationString glbStr_apprchMaxLim = " aproximandose al valor maximo!";
static const globalizationString glbStr_valWithinValidRange = " esta dentro del rango valido";

static const std::map<batteryParamType, std::string> glbStr_paramType{
    {batteryParamType::Temperature,   "Temperatura"},
    {batteryParamType::StateOfCharge,"Estado de la carga"},
    {batteryParamType::ChargeRate,    "Velocidad de carga"}
};
#endif//SPANISH
#endif//GLOBALIZATIONSTRINGS_H