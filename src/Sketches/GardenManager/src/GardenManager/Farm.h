#ifndef FARM_H_
#define FARM_H_

class Section;

class Farm
{
public:
    
    unsigned int m_iSectionCount;
    Section **m_pSections;
    
    Farm();
    ~Farm();
    void addSection(Section *pSection);
    void configure();
};

#endif // FARM_H_
