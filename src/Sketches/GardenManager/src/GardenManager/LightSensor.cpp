#include <Arduino.h>
#include "Logger.h"

LightSensor::LightSensor(int sH, int sL, int vH, int vL, int sP, int cP, int cT) : sensorHigh(sH), sensorLow(sL), valueHigh(vH), valueLow(vL), sensorPin(sP), controlPin(cP), controlThreshold(cT) {}

void LightSensor::init()
{
  pinMode(controlPin, OUTPUT);
}
  
int LightSensor::getValue()
{
  int value = analogRead(sensorPin);
  
  value = map(value, sensorHigh, sensorLow, valueLow, valueHigh);
  
  int lightOutputValue = map(value, controlThreshold, 0, 0, 255);
  
  if (lightOutputValue < 0)
    lightOutputValue == 0;
  
  logIntValue("LtOut", lightOutputValue);
  
  // If light levels are low, turn on the grow lights
  if (value < controlThreshold)
    analogWrite(controlPin, lightOutputValue);
  else
    analogWrite(controlPin, 0);
  
  return value;
}
