#ifndef LIGHTSENSOR_H_
#define LIGHTSENSOR_H_

#include "Config.h"

class LightSensor
{
public:
    
    LightSensorConfig m_cfg;

    void configure(LightSensorConfig cfg);
    void setup();
    int getValue();
};

#endif /* LIGHTSENSOR_H_ */
