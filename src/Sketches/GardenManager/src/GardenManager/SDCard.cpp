#include <Arduino.h>

#include <SD.h>
#include "Logger.h"
#include "SDCard.h"

void SDCard::configure(SDCardConfig cfg)
{
    m_cfg = cfg;
}

void SDCard::setup()
{
  pinMode(m_cfg.sdCardPin, OUTPUT);
  
  // see if the card is present and can be initialized:
  if (!SD.begin(m_cfg.chipSelect)) {
    logError("Failed to write to SD card.");
    // don't do anything more:
    return;
  }
  
}
