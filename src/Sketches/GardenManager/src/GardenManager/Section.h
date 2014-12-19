#ifndef SECTION_H_
#define SECTION_H_

#include "Config.h"

class LightSensor;

class Section
{
public:
    
    SectionConfig m_cfg;
    LightSensor *m_pLightSensor;
    
    Section();
    ~Section();
    
    void configure(SectionConfig cfg);
};

#endif // SECTION_H_

