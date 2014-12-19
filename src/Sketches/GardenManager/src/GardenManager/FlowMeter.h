#ifndef FLOWMETER_H_
#define FLOWMETER_H_

class FlowMeter
{
public:
    
    // Declare the pin that measures flow
    int m_iFlowMeterPin;
    
    FlowRate(int fP);
    
    void init();
    void pulseCounter();
    float getFlowRate();
};

#endif /* FLOWMETER_H_ */
