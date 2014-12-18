#include "Arduino.h"

#include <SD.h>
#include <DHT11.h>
#include <DS1302.h>

#include "SDCard.h"
#include "Logger.h"
#include "FlowMeter.h"
#include "MoistureSensor.h"
#include "LightSensor.h"
#include "TemperatureHumiditySensor.h"
#include "Time.h"
#include "Irrigation.h"

// LED pins
int powerLedPin       = 14;
int errorPin          = 16;

// Set the delay between each loop (in milliseconds)
int delayTime = 2000;

LightSensor lightSensor;

void setup() //
{
  Serial.begin(9600); //This is the setup function where the serial port is 

  setupGardenManager();
} 

void loop ()    
{
  loopGardenManager();
}

void setupGardenManager()
{
  Serial.println("Setting up GardenManager...");

  // Initialize the flow meter
  initFlowMeter();
  
  // Initialize the SD card
  initSDCard();

  // Initialize the irrigation
  initIrrigation();
  
  // Initialize the light sensor and light control
  lightSensor.init(1000, 0, 100, 0, A3, 8, 80);

  // Declare output pins
  pinMode(powerLedPin, OUTPUT);  
  pinMode(errorPin, OUTPUT);
 
  // Turn the power LED on
  digitalWrite(powerLedPin, HIGH);
}

void loopGardenManager()
{
  logStart();
  
  char* dateTime = getTime();
  
  logStringValue("T", dateTime);
  
  float flowRateValue = getFlowRate();
  
  int moistureValue = getMoistureValue();
  
  int lightValue = lightSensor.getValue();

  checkHumidityTemperatureValues();

  float temperatureValue = getTemperatureValue();
  
  float humidityValue = getHumidityValue();

  logIntValue("Mst", moistureValue);
  logIntValue("Lt", lightValue);
  logFloatValue("Hm", humidityValue, 1);
  logFloatValue("Tmp", temperatureValue, 1);
  logFloatValue("Fl", flowRateValue, 4);
  logFinish();

  checkIrrigation();
  
  delay(delayTime);
}


