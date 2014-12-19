#include "Arduino.h"
#include "Logger.h"
#include "Conversion.h"
#include "MoistureSensor.h"

void MoistureSensor::configure(MoistureSensorConfig cfg)
{
    m_cfg = cfg;
}

void MoistureSensor::setup()
{
    //...
}

int MoistureSensor::getValue()
{
    m_iValue = analogRead(m_cfg.sensorPin);    
    m_iValue = map(m_iValue, m_cfg.sensorHigh, m_cfg.sensorLow, m_cfg.valueLow, m_cfg.valueHigh);
    return m_iValue;

}
