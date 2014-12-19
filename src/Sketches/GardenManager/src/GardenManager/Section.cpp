#include "Section.h"
#include "LightSensor.h"
#include <stddef.h>

Section::Section()
{
    m_pLightSensor = new LightSensor();
}

Section::~Section()
{
    delete m_pLightSensor;
    m_pLightSensor = NULL;
}

void Section::configure(SectionConfig cfg)
{
    m_cfg = cfg;
    m_pLightSensor->configure(m_cfg.l0);
}

void Section::setup()
{
    m_pLightSensor->setup();
    //...
}
