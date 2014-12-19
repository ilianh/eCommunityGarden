#include "Farm.h"
#include "Section.h"
#include <stddef.h>
#include <string.h>
#include <Arduino.h>

Farm::Farm() : m_iSectionCount(0), m_pSections(NULL)
{
    addSection(new Section());
    //...
}

Farm::~Farm()
{
    for(int i = 0; i < m_iSectionCount; i++)
        delete m_pSections[i];
    delete[] m_pSections;
    m_pSections = NULL;
}

void Farm::addSection(Section *pSection)
{
    Section **pSections = new Section*[m_iSectionCount + 1];
    if(m_pSections != NULL)
    {
        memcpy(pSections, m_pSections, m_iSectionCount * sizeof(void*));
        delete[] m_pSections;
    }
    m_pSections = pSections;
    m_pSections[m_iSectionCount++] = pSection;
}

void Farm::configure()
{
    // section 0
    struct LightSensorConfig l0 = {1000, 0, 100, 0, A3, 8, 80};
    //   lightsensor 0
    struct SectionConfig s0 = {l0};
    m_pSections[0]->configure(s0);
    
    //...
}
