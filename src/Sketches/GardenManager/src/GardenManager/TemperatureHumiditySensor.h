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

    void configure(TemperatureHumiditySensorConfig cfg);
    void setup();
    float getHumidityValue();
    float getTemperatureValue();
    void read();
};

#endif /* TEMPERATUREHUMIDITYSENSOR_H_ */
