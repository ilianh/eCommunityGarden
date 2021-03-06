#include "Section.h"
#include "LightSensor.h"
#include "MoistureSensor.h"
#include "TemperatureHumiditySensor.h"
#include <stddef.h>
#include "Logger.h"

Section::Section()
{
    m_pLightSensor = new LightSensor();
    m_pMoistureSensor = new MoistureSensor();
    m_pTemperatureHumiditySensor = new TemperatureHumiditySensor();
}

Section::~Section()
{
    delete m_pLightSensor;
    m_pLightSensor = NULL;
    delete m_pMoistureSensor;
    m_pMoistureSensor = NULL;
    delete m_pTemperatureHumiditySensor;
    m_pTemperatureHumiditySensor = NULL;
}

void Section::configure(SectionConfig cfg)
{
    m_cfg = cfg;
    m_pLightSensor->configure(m_cfg.l0);
    m_pMoistureSensor->configure(m_cfg.m0);
    m_pTemperatureHumiditySensor->configure(m_cfg.th0);
}

void Section::setup()
{
    m_pLightSensor->setup();
    m_pMoistureSensor->setup();
    m_pTemperatureHumiditySensor->setup();
    //...
}

void Section::loop()
{
    m_pTemperatureHumiditySensor->read();
    
    logIntValue("Mst", m_pMoistureSensor->getValue());
    logFloatValue("Tmp", m_pTemperatureHumiditySensor->getTemperatureValue(), 1);
    logIntValue("Lt", m_pLightSensor->getValue());
    logFloatValue("Hm", m_pTemperatureHumiditySensor->getHumidityValue(), 1);
}
