#include <Arduino.h>

#include <SD.h>
#include "Logger.h"
#include "SDCard.h"

SDCard::SDCard(){}

void SDCard::init()
{
  pinMode(m_iSdCardPin, OUTPUT);
  
  // see if the card is present and can be initialized:
  if (!SD.begin(m_iChipSelect)) {
    logError("Failed to write to SD card.");
    // don't do anything more:
    return;
  }
  
}
