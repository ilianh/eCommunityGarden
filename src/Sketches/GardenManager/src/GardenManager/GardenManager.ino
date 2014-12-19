#include "Arduino.h"

#include <SPI.h>
#include <SD.h>
#include <DHT11.h>
#include <DS1302.h>

#include "Farm.h"
#include "Section.h"
#include "SDCard.h"
#include "Logger.h"
#include "FlowMeter.h"
#include "MoistureSensor.h"
#include "LightSensor.h"
#include "TemperatureHumiditySensor.h"
#include "Time.h"
#include "Irrigation.h"

// Set the delay between each loop (in milliseconds)
int delayTime = 2000;

Farm farm;

void setup()
{
    Serial.begin(9600); //This is the setup function where the serial port is

    farm.configure(farm.loadConfig());
    farm.setup();
}

void loop ()    
{
  loopGardenManager();
}

void loopGardenManager()
{
  logStart();
  
  char* dateTime = getTime();
  
  logStringValue("T", dateTime);
  
  //float flowRateValue = getFlowRate();
  
  int moistureValue = getMoistureValue();
  
  int lightValue = farm.m_pSections[0]->m_pLightSensor->getValue();

  checkHumidityTemperatureValues();

  float temperatureValue = getTemperatureValue();
  
  float humidityValue = getHumidityValue();

  logIntValue("Mst", moistureValue);
  logIntValue("Lt", lightValue);
  logFloatValue("Hm", humidityValue, 1);
  logFloatValue("Tmp", temperatureValue, 1);
  //logFloatValue("Fl", flowRateValue, 4);
  logFinish();

  checkIrrigation();
  
  delay(delayTime);
}


