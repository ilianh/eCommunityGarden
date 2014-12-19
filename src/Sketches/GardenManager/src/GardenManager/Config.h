#ifndef CONFIG_H_
#define CONFIG_H_

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

struct TemperatureHumidityConfig
{
    int dht11Pin;
};

struct FlowMeterConfig
{
    int sensorPin;
    byte sensorInterrupt;
}

struct SDCardConfig
{
    int sdCardPin;
    int chipSelect;
}

struct SectionConfig
{
    LightSensorConfig l0;
    MoistureSensorConfig m0;
    TemperatureHumidityConfig th0;
};

struct FarmConfig
{
    // Declare output pins
    int powerLedPin;
    int errorPin;

    FlowMeterConfig fm0;
    SDCardConfig sd0;
    SectionConfig s0;
};

#endif // CONFIG_H_
