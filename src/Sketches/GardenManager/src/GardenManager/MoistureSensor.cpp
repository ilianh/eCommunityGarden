#include "Arduino.h"
#include "Logger.h"
#include "Conversion.h"
#include "MoistureSensor.h"

void MoistureSensor::configure(MoistureSensorConfig cfg)
{
    m_cfg = cfg;
}

int MoistureSensor::getValue()
{
    int value;
    value = analogRead(m_cfg.sensorPin);    
    value = map(value, m_cfg.sensorHigh, m_cfg.sensorLow, m_cfg.valueLow, c_cfg.valueHigh);
    return value;

}
