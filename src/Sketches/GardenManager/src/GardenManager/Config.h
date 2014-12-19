#ifndef CONFIG_H_
#define CONFIG_H_
#include "Arduino.h"

struct LightSensorConfig
{
    // Light data variables
    int sensorHigh, sensorLow, valueHigh, valueLow;
    
    // Declare the pin that measures light levels
    int sensorPin;
    
    // Declare the pin that controls grow lights
    int controlPin;
    
    // Declare the minimum light level, at which lower levels will turn on grow lights
    int controlThreshold;
};

struct MoistureSensorConfig
{
    int sensorHigh, sensorLow, valueHigh, valueLow;
    int sensorPin;
};

struct TemperatureHumiditySensorConfig
{
    int dht11Pin;
};

struct FlowMeterConfig
{
    int sensorPin;
    byte sensorInterrupt;
};

struct SDCardConfig
{
    int sdCardPin;
    int chipSelect;
};

struct SectionConfig
{
    LightSensorConfig l0;
    MoistureSensorConfig m0;
    TemperatureHumiditySensorConfig th0;
};

struct FarmConfig
{
    int delayTime;
    
    // Declare output pins
    int powerLedPin;
    int errorPin;

    SectionConfig s0;
    SDCardConfig sd0;
    FlowMeterConfig fm0;
};

#endif // CONFIG_H_
