#include <Arduino.h>
#include "Logger.h"
#include "LightSensor.h"

LightSensor::LightSensor(int sH, int sL, int vH, int vL, int sP, int cP, int cT) : m_iSensorHigh(sH), m_iSensorLow(sL), m_iValueHigh(vH), m_iValueLow(vL), m_iSensorPin(sP), m_iControlPin(cP), m_iControlThreshold(cT) {}

void LightSensor::init()
{
  pinMode(m_iControlPin, OUTPUT);
}
  
int LightSensor::getValue()
{
  int value = analogRead(m_iSensorPin);
  
  value = map(value, m_iSensorHigh, m_iSensorLow, m_iValueLow, m_iValueHigh);
  
  int lightOutputValue = map(value, m_iControlThreshold, 0, 0, 255);
  
  if (lightOutputValue < 0)
    lightOutputValue == 0;
  
  logIntValue("LtOut", lightOutputValue);
  
  // If light levels are low, turn on the grow lights
  if (value < m_iControlThreshold)
    analogWrite(m_iControlPin, lightOutputValue);
  else
    analogWrite(m_iControlPin, 0);
  
  return value;
}
