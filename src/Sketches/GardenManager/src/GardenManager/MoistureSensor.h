#ifndef MOISTURESENSOR_H_
#define MOISTURESENSOR_H_
#include "Config.h"

class MoistureSensor
{
public:
    
    MoistureSensorConfig m_cfg;
    int m_iValue;

    void configure(MoistureSensorConfig cfg);
    void setup();
    int getValue();

};

#endif /* MOISTURESENSOR_H_ */
