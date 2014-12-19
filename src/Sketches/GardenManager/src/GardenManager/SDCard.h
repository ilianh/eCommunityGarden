#ifndef SDCARD_H_
#define SDCARD_H_

class SDCard
{
public:
    int m_iChipSelect;
    int m_iSdCardPin;

    SDCard();
    void init();
};

#endif /* SDCARD_H_ */
