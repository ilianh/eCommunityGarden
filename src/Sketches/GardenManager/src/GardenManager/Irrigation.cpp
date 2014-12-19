#include <Arduino.h>
#include "Irrigation.h"
#include "MoistureSensor.h"

void Irrigation::configure(IrrigationConfig cfg)
{
    m_cfg = cfg;
}

void Irrigation::setup()
{
    pinMode(m_cfg.wateringPin, OUTPUT); 
    pinMode(m_cfg.wateringLedPin, OUTPUT);  
}

void Irrigation::checkIrrigation()
{
    int moistureValue = 0; //getMoistureValue();

    if (moistureValue < m_cfg.threshold)
    {
        digitalWrite(m_cfg.wateringPin, HIGH);
        digitalWrite(m_cfg.wateringLedPin, HIGH);
    }
    else
    {
        digitalWrite(m_cfg.wateringPin, LOW);
        digitalWrite(m_cfg.wateringLedPin, LOW);
    }
}


