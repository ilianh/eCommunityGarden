#ifndef FLOWMETER_H_
#define FLOWMETER_H_

#include "Config.h"

class FlowMeter
{
public:

    FlowMeterConfig m_cfg
    volatile byte m_bFlowPulseCount;
    
    void configure(FlowMeterConfig cfg); 
    void init();
    void flowPulseCounter();
    float getFlowRate();
};

#endif /* FLOWMETER_H_ */
