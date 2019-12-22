#ifndef COMMUNICATIONIF_H
#define COMMUNICATIONIF_H


#include <iostream>
#include <memory>
#include <vector>
#include <functional>
#include <stdint.h>
#include <QMutex>
#include "settingsif.h"
#include "settings.h"


enum CommunicationDevices
{
    COMM_USB,
    COMM_SERIAL,
    COMM_TCPIP,
    COMM_MAX_DEVICE
};

struct read_metaData
{
    std::vector<uint8_t> buffer;
    uint32_t len;
    uint32_t actual_read;

    read_metaData()
    {
        buffer.clear();
        len = 0;
        actual_read = 0;
    }

    void clear(void)
    {
        buffer.clear();
        len = 0;
        actual_read = 0;
    }

    virtual ~read_metaData(){}
};

class CommunicationIF
{
public:
    typedef  std::shared_ptr <CommunicationIF> Ptr;
    typedef  std::function<void(CommunicationIF::Ptr, std::vector<uint8_t>&, uint16_t channel)> dataCallback_t;
    typedef  std::function<void(CommunicationIF::Ptr)> closeCallback_t;
    typedef  std::shared_ptr <settings> SettingsPtr;

    /**
     * @brief Constructor CommunicationIF
     */
    CommunicationIF() = default;


    /**
     * @brief Destructor CommunicationIF
     */
    virtual ~CommunicationIF() = default;

    /**
     * @brief Initialization
     */
    virtual bool Initialization(void) = 0;

    /**
     * @brief readData
     * @param data
     */
    virtual void readData(struct read_metaData *read_data) = 0;

    /**
     * @brief writeData
     * @param data
     */
    virtual void writeData(std::vector<uint8_t> data ) = 0;

    /**
     * @brief clean
     */
    virtual void clean(bool isInternal = false) = 0;

    virtual bool isRunning (void) = 0;

    virtual void registerForData(dataCallback_t callback);

    virtual void registerForDisconnect(closeCallback_t callback);

    virtual uint64_t getTransferedByte(void) = 0;

    virtual CommunicationDevices type(void) = 0;

    virtual std::string type(bool is_string) = 0;

    virtual void setSettingIntf(SettingsPtr settingsIntf) = 0;
};

#endif // COMMUNICATIONIF_H
