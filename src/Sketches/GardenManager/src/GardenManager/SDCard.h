#ifndef SDCARD_H_
#define SDCARD_H_
#include "Config.h"

class SDCard
{
public:
    SDCardConfig m_cfg;
    void configure(SDCardConfig cfg);
    void setup();
};

#endif /* SDCARD_H_ */
