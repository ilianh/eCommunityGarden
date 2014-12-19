#ifndef FLOWMETER_H_
#define FLOWMETER_H_

class FlowMeter
{
public:

    FlowMeterConfig m_cfg
    volatile byte m_bFlowPulseCount;
    
    void configure(FlowMeterConfig cfg); 
    void setup();
    void flowPulseCounter();
    float getFlowRate();
};

#endif /* FLOWMETER_H_ */
