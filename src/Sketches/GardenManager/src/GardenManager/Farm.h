#ifndef FARM_H_
#define FARM_H_

#include "Config.h"

class Section;
class SDCard;
class FlowMeter;
class Irrigation;

class Farm
{
public:
    
    FarmConfig m_cfg;
    unsigned int m_iSectionCount;
    Section **m_pSections;
    SDCard *m_pSDCard;
    FlowMeter *m_pFlowMeter;
    Irrigation *m_pIrrigation;
    
    Farm();
    ~Farm();
    FarmConfig loadConfig();
    void addSection(Section *pSection);
    void configure(FarmConfig cfg);
    void setup();
    void loop();
};

#endif // FARM_H_
