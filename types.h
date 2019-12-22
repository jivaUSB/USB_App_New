#ifndef TYPES_H
#define TYPES_H

#include<QVector>

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

struct histoData
{
    QVector<double>  m_peak;
    QVector<double>  m_transmitTime;
    QVector<double>  m_area;
    QVector<double>  m_intencity;
    QVector<uint8_t>  m_status;
    uint32_t m_xCellCount;
    uint32_t m_yCellCount;
    uint32_t m_multiCellCount;
    uint32_t m_totalCellCount;
    bool isCounterOn;
};

#endif // TYPES_H
