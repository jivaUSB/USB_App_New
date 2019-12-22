#ifndef USBCOMMUNICATION_H
#define USBCOMMUNICATION_H

#include "communicationif.h"
#include "DRV_DriverInterface.h"
#include <string>
#include <deque>
#include <iostream>
#include <map>
#include <QMutex>
#include <fstream>
#include <condition_variable> // std::condition_variable
#include <thread>

#define BUFF_SIZE 1024

struct USB_read_meta_data : public read_metaData
{
    uint8_t endPoint;
    USB_read_meta_data()
    {
        endPoint = 0;
    }
};

class USBCommunication : public CommunicationIF, public std::enable_shared_from_this<USBCommunication>
{
    std::vector<USB_read_meta_data *> m_ptrReadMetaData;
    std::shared_ptr<settings_usb> m_usb_settings;
    SettingsPtr m_settings;
    uint64_t m_DataCounter;
    uint64_t m_ProcessedData;
    uint32_t m_bufferNums;
    uint8_t bufferNum;
    uint32_t m_channelNo;
    //settings_usb m_settings;
    std::shared_ptr<CDriverInterface> m_device;
    bool m_isRunning;
    bool m_stopParseThread;
    bool m_stopParseThread1;
    QMutex m_mtx;
    dataCallback_t m_dataCallback;
    closeCallback_t m_closeCallback;
    std::deque < std::shared_ptr<std::vector<uint8_t>> > bufferContainer;
    std::vector <uint8_t> tmpData;
    std::shared_ptr <std::thread> parseThread;
    std::shared_ptr <std::thread> readThr;
    std::mutex cv_mtx;
    std::condition_variable cv;
    std::ofstream binfile;
public:
    USBCommunication();

    virtual ~USBCommunication();

    /**
     * @brief Initialization
     */
    virtual bool Initialization(void) override;

    /**
     * @brief readData
     * @param data
     */
    virtual void readData(struct read_metaData *read_data ) override;

    /**
     * @brief writeData
     * @param data
     */
    virtual void writeData(std::vector<uint8_t> data ) override;

    /**
     * @brief clean
     */
    virtual void clean(bool isInternal = true) override;

    /**
     * @brief isRunning
     * @return
     */
    virtual bool isRunning(void) override
    {
        return m_isRunning;
    }

    virtual void registerForData(dataCallback_t callback) override;

    virtual void registerForDisconnect(closeCallback_t callback) override;

    virtual uint64_t getTransferedByte(void) override;

    virtual CommunicationDevices type(void) override
    {
        return CommunicationDevices::COMM_USB;
    }

    virtual std::string type(bool is_string) override
    {
        return "USB";
    }

    void setSettingIntf(SettingsPtr settingsIntf) override;

    void ParseData();
};

#endif // USBCOMMUNICATION_H
