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

Farm farm;

void setup()
{
    Serial.begin(9600); //This is the setup function where the serial port is

    farm.configure(farm.loadConfig());
    farm.setup();
}

void loop ()    
{
  farm.loop();
}
