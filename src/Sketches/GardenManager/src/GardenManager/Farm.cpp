#include "Farm.h"
#include "Section.h"
#include <stddef.h>
#include <string.h>
#include <Arduino.h>

Farm::Farm() : m_iSectionCount(0), m_pSections(NULL)
{
    addSection(new Section());
    //...
}

Farm::~Farm()
{
    for(int i = 0; i < m_iSectionCount; i++)
        delete m_pSections[i];
    delete[] m_pSections;
    m_pSections = NULL;
}

FarmConfig Farm::loadConfig()
{
    // farm / section 0 / moisturecensor 0
    struct MoistureSensorConfig s0_m0 = {1030, 350, 100, 0, A4};
    // farm / section 0 / temphumcensor 0
    struct TemperatureHumidityConfig s0_th0 = {3};
    // farm / section 0 / lightsensor 0
    struct LightSensorConfig s0_l0 = {1000, 0, 100, 0, A3, 8, 80};
    // farm / section 0
    struct SectionConfig s0 = {s0_l0, s0_m0, s0_th0};
    // farm
    struct FarmConfig cfg = {14, 16, s0};
    
    return cfg;
}

void Farm::addSection(Section *pSection)
{
    Section **pSections = new Section*[m_iSectionCount + 1];
    if(m_pSections != NULL)
    {
        memcpy(pSections, m_pSections, m_iSectionCount * sizeof(void*));
        delete[] m_pSections;
    }
    m_pSections = pSections;
    m_pSections[m_iSectionCount++] = pSection;
}

void Farm::configure(FarmConfig cfg)
{
    m_cfg = cfg;
    m_pSections[0]->configure(m_cfg.s0);
}

void Farm::setup()
{
    Serial.println("Setting up Farm...");
    
    //initSDCard();
    
    for(unsigned int i = 0; i < m_iSectionCount; i++)
        m_pSections[i]->setup();

    //initFlowMeter();
    //initIrrigation();
    
    pinMode(m_cfg.powerLedPin, OUTPUT);
    pinMode(m_cfg.errorPin, OUTPUT);
    
    digitalWrite(m_cfg.powerLedPin, HIGH);
}
