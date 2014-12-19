#include <Arduino.h>
#include "Logger.h"
#include "LightSensor.h"

void LightSensor::configure(LightSensorConfig cfg)
{
    m_cfg = cfg;
}

void LightSensor::setup()
{
  pinMode(m_cfg.controlPin, OUTPUT);
}

int LightSensor::getValue()
{
  int value = analogRead(m_cfg.sensorPin);
  
  value = map(value, m_cfg.sensorHigh, m_cfg.sensorLow, m_cfg.valueLow, m_cfg.valueHigh);
  
  int lightOutputValue = map(value, m_cfg.controlThreshold, 0, 0, 255);
  
  if (lightOutputValue < 0)
    lightOutputValue == 0;
  
  logIntValue("LtOut", lightOutputValue);
  
  // If light levels are low, turn on the grow lights
  if (value < m_cfg.controlThreshold)
    analogWrite(m_cfg.controlPin, lightOutputValue);
  else
    analogWrite(m_cfg.controlPin, 0);
  
  return value;
}
