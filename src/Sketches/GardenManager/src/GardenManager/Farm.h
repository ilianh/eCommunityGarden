#ifndef FARM_H_
#define FARM_H_

#include "Config.h"

class Section;

class Farm
{
public:
    
    FarmConfig m_cfg;
    unsigned int m_iSectionCount;
    Section **m_pSections;
    
    Farm();
    ~Farm();
    FarmConfig loadConfig();
    void addSection(Section *pSection);
    void configure(FarmConfig cfg);
    void setup();
};

#endif // FARM_H_
