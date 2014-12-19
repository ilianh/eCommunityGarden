#ifndef LIGHTSENSOR_H_
#define LIGHTSENSOR_H_

class LightSensor
{
public:
    
    // Light data variables
    int m_iSensorHigh, m_iSensorLow, m_iValueHigh, m_iValueLow;
    
    // Declare the pin that measures light levels
    int m_iSensorPin;
    
    // Declare the pin that controls grow lights
    int m_iControlPin;
    
    // Declare the minimum light level, at which lower levels will turn on grow lights
    int m_iControlThreshold;
    
    LightSensor(int sH, int sL, int vH, int vL, int sP, int cP, int cT);
    
    void init();
    int getValue();
};

#endif /* LIGHTSENSOR_H_ */
