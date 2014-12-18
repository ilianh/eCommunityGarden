#ifndef LIGHTSENSOR_H_
#define LIGHTSENSOR_H_

class LighSensor
{
public:
    
    // Light data variables
    int sensorHigh, sensorLow, valueHigh, valueLow;
    
    // Declare the pin that measures light levels
    int sensorPin;
    
    // Declare the pin that controls grow lights
    int controlPin;
    
    // Declare the minimum light level, at which lower levels will turn on grow lights
    int controlThreshold;
    
    LightSensor(int sH, int sL, int vH, int vL, int sP, int cP, int cT);
    
    void init();
    int getValue();
}

#endif /* LIGHTSENSOR_H_ */
