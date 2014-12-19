#ifndef CONFIG_H_
#define CONFIG_H_
#include "Arduino.h"

#define SECTIONS 2

struct LightSensorConfig
{
    int sensorHigh, sensorLow, valueHigh, valueLow;
    int sensorPin;
    int controlPin;
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

struct IrrigationConfig
{
    int threshold;
    int wateringLedPin;
    int wateringPin;  
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
    int powerLedPin;
    int errorPin;
    SDCardConfig sd0;
    FlowMeterConfig fm0;
    IrrigationConfig i0;
    unsigned int sectionCount;
    SectionConfig s[2];
};

#endif // CONFIG_H_
