#ifndef TYPES_H
#define TYPES_H

#include<QVector>
#include<functional>
#include<tuple>

enum buttonStatus
{
    OFF,
    ON,
    DISPLAY_ACQ,
    DISPLAY_ANALYSIS,
    PLAY,
    STOP
};

#define ICON_BUTTON_ON ":/Images/On"
#define ICON_BUTTON_OFF ":/Images/OFF"
#define ICON_PLAY_ON ":/Images/Play"
#define ICON_PLAY_OFF ":/Images/Stop"
#define ICON_CURR_DISPLAY_ACQ ":/Images/Acq"
#define ICON_CURR_DISPLAY_ANALYSIS ":/Images/Analysis"

struct  serialReadData
{
    uint32_t m_peak;
    uint32_t m_transmitTime;
    uint32_t m_area;
    uint32_t m_intencity;
    uint8_t m_status;
};

#endif // TYPES_H
