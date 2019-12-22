#ifndef USB_SETTINGS_H
#define USB_SETTINGS_H

#include "settingsif.h"
#include "DRV_DriverInterface.h"

class settings;

class settings_usb: public settingsIF
{
    friend class settings;
    EOPEN_BY openType;
    std::string openKey;
    uint32_t packetSize;
    uint32_t bufferSize;
    uint64_t readLimit;
public:
    settings_usb()
    {
        openType = EOPEN_BY_SERIAL;
        openKey  = DEFAULT_VALUE_OPENBY_SERIAL;
        packetSize = 0;
        bufferSize = 0;
        readLimit = 0;
    }

    virtual ~settings_usb()
    {

    }

    EOPEN_BY getOpenType(void) { return openType; }
    std::string getOpenKey(void) { return openKey; }
    uint32_t getPacketSize(void) { return packetSize; }
    uint32_t getBufferSize(void) { return bufferSize; }
    uint64_t getReadLimit(void) { return readLimit*1000*1000; }
};

#endif // USB_SETTINGS_H
