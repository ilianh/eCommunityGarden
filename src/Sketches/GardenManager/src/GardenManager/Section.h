#ifndef SECTION_H_
#define SECTION_H_

#include "Config.h"

class LightSensor;
class MoistureSensor;
class TemperatureHumiditySensor;

class Section
{
public:
    
    SectionConfig m_cfg;
    LightSensor *m_pLightSensor;
    MoistureSensor *m_pMoistureSensor;
    TemperatureHumiditySensor *m_pTemperatureHumiditySensor;
    
    Section();
    ~Section();
    
    void configure(SectionConfig cfg);
    void setup();
};

#endif // SECTION_H_

