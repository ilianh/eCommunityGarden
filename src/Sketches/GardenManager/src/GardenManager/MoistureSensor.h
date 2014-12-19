#ifndef MOISTURESENSOR_H_
#define MOISTURESENSOR_H_

int getMoistureValue();

class MoistureSensor
{
public:
    
    MoistureSensor m_cfg

    void configure(MoistureSensorConfig cfg);
    void init();

};

#endif /* MOISTURESENSOR_H_ */
