#ifndef FLOWMETER_H_
#define FLOWMETER_H_

class FlowMeter
{
public:
    // Declare the pin that measures flow
    int m_iFlowMeterPin;
    volatile byte m_bFlowPulseCount;
    byte m_bSensorInterrupt; //0 = pin2; 1 = pin3
    
    FlowMeter(int fP, byte fC, byte sI);
    
    void init();
    void flowPulseCounter();
    float getFlowRate();
};

#endif /* FLOWMETER_H_ */
