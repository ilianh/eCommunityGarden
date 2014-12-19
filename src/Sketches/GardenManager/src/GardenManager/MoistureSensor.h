#ifndef MOISTURESENSOR_H_
#define MOISTURESENSOR_H_

int getMoistureValue();

class MoistureSensor
{
public:
    // Moisture data variables
    int m_iValue;
    int m_iSensorHigh;
    int m_iSensorLow;
    int m_iValueHigh;
    int m_iValueLow;
    int m_iSensorPin;
};

#endif /* MOISTURESENSOR_H_ */
