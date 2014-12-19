#ifndef TEMPERATUREHUMIDITYSENSOR_H_
#define TEMPERATUREHUMIDITYSENSOR_H_

#include "Config.h"

class DHT11;

class TemperatureHumiditySensor
{
public:
    
    TemperatureHumiditySensorConfig m_cfg;
    float m_fHumidityValue;
    float m_fTemperatureValue;
    DHT11 *m_pDht11;

    float getHumidityValue();
    float getTemperatureValue();
    void checkHumidityTemperatureValues();
    void setup();
};

#endif /* TEMPERATUREHUMIDITYSENSOR_H_ */
