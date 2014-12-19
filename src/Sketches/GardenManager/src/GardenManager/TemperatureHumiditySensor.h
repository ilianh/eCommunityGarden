#ifndef TEMPERATUREHUMIDITYSENSOR_H_
#define TEMPERATUREHUMIDITYSENSOR_H_

#include "Config.h"

class TemperatureHumiditySensor
{
public:
    
    TemperatureHumiditySensorConfig m_cfg;
    float m_fHumidityValue;
    float m_fTemperatureValue;

    float getHumidityValue();
    float getTemperatureValue();
    void checkHumidityTemperatureValues();

#endif /* TEMPERATUREHUMIDITYSENSOR_H_ */
