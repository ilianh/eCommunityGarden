#include "Logger.h"
#include <DHT11.h>

void TemperatureHumiditySensor::configure(TemperatureHumiditySensorConfig cfg)
{
   m_cfg = cfg;
   m_pDht11(m_cfg.dht11Pin);
} 

void TemperatureHumiditySensor::setup()
{
    //...
}

void TemperatureHumiditySensor::checkHumidityTemperatureValues()
{
  int err;
  if((err=dht11.read(m_fHumidityValue, m_fTemperatureValue))==0)
  {
  }
  else
  {
    logError("DHT 11 error");
  }
}

float TemperatureHumiditySensor::getHumidityValue()
{
  return m_fHumidityValue;
}

float TemperatureHumiditySensor::getTemperatureValue()
{
  return m_fTemperatureValue;
}
