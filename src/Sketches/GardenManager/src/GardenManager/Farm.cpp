#include "Farm.h"
#include "Section.h"
#include "FlowMeter.h"
#include "SDCard.h"
#include "Irrigation.h"
#include <stddef.h>
#include <string.h>
#include <Arduino.h>
#include "Logger.h"
#include "Time.h"

Farm::Farm() : m_iSectionCount(0), m_pSections(NULL)
{
    m_pSDCard = new SDCard();
    m_pFlowMeter = new FlowMeter();
    m_pIrrigation = new Irrigation();
}

Farm::~Farm()
{
    for(int i = 0; i < m_iSectionCount; i++)
        delete m_pSections[i];
    delete[] m_pSections;
    m_pSections = NULL;
    delete m_pFlowMeter;
    m_pFlowMeter = NULL;
    delete m_pSDCard;
    m_pSDCard = NULL;
    delete m_pIrrigation;
    m_pIrrigation = NULL;
}

FarmConfig Farm::loadConfig()
{
    // SECTION 0
    // farm / section 0 / moisturecensor 0
    struct MoistureSensorConfig s0_m0 = {1030, 350, 100, 0, A4};
    // farm / section 0 / temphumcensor 0
    struct TemperatureHumiditySensorConfig s0_th0 = {3};
    // farm / section 0 / lightsensor 0
    struct LightSensorConfig s0_l0 = {1000, 0, 100, 0, A3, 8, 80};
    // farm / section 0
    struct SectionConfig s0 = {s0_l0, s0_m0, s0_th0};
    
    // SECTION 1
    // farm / section 1 / moisturecensor 0
    struct MoistureSensorConfig s1_m0 = {1030, 350, 100, 0, A4};
    // farm / section 1 / temphumcensor 0
    struct TemperatureHumiditySensorConfig s1_th0 = {3};
    // farm / section 1 / lightsensor 0
    struct LightSensorConfig s1_l0 = {1000, 0, 100, 0, A3, 8, 80};
    // farm / section 1
    struct SectionConfig s1 = {s1_l0, s1_m0, s1_th0};
    
    // FARM
    // farm / SDCard 0
    struct SDCardConfig sd0 = {4, 10};
    // farm / FlowMeter 0
    struct FlowMeterConfig fm0 = {2, 0};
    // farm / Irrigation 0
    struct IrrigationConfig i0 = {20, 15, 9};
    // farm
    struct FarmConfig cfg = {2000, 14, 16, sd0, fm0, i0, 2, {s0, s1}};
    
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
    
    m_pSDCard->configure(m_cfg.sd0);
    m_pFlowMeter->configure(m_cfg.fm0);
    m_pIrrigation->configure(m_cfg.i0);
    
    for(unsigned int i = 0; i < m_cfg.sectionCount; i++)
    {
        addSection(new Section());
        m_pSections[i]->configure(m_cfg.s[i]);
    }
}

void Farm::setup()
{
    Serial.println("Setting up Farm...");
    
    m_pSDCard->setup();;
    
    for(unsigned int i = 0; i < m_iSectionCount; i++)
        m_pSections[i]->setup();

    m_pFlowMeter->setup();
    m_pIrrigation->setup();
    
    pinMode(m_cfg.powerLedPin, OUTPUT);
    pinMode(m_cfg.errorPin, OUTPUT);
    
    digitalWrite(m_cfg.powerLedPin, HIGH);
}

void Farm::loop()
{
    logStart();
    
    char* dateTime = getTime();
    logStringValue("T", dateTime);
    
    for(unsigned int i = 0; i < m_iSectionCount; i++)
        m_pSections[i]->loop();
    
    logFloatValue("Fl", m_pFlowMeter->getFlowRate(), 4);
    m_pIrrigation->irrigate();
    
    logFinish();
    
    delay(m_cfg.delayTime);
}
