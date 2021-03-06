#include "Logger.h"
#include <DHT11.h>
#include "TemperatureHumiditySensor.h"

void TemperatureHumiditySensor::configure(TemperatureHumiditySensorConfig cfg)
{
   m_cfg = cfg;
   m_pDht11 = new DHT11(m_cfg.dht11Pin);
} 

void TemperatureHumiditySensor::setup()
{
    //...
}

void TemperatureHumiditySensor::read()
{
  int err;
  if((err=m_pDht11->read(m_fHumidityValue, m_fTemperatureValue))==0)
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
