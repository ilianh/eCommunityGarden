#ifndef IRRIGATION_H_
#define IRRIGATION_H_

#include "Config.h"

class Irrigation
{
public:
    IrrigationConfig m_cfg;

    void configure(IrrigationConfig cfg);
    void setup();
    void checkIrrigation();
};

#endif /* IRRIGATION_H_ */
