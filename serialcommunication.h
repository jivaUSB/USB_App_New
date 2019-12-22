#ifndef SERIALCOMMUNICATION_H
#define SERIALCOMMUNICATION_H

#include "communicationif.h"
#include <memory>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <string>
#include <QString>
#include <thread>
#include <functional>
#include "serialconfiguration.h"
#include<bits/stdc++.h>
#include <mutex>

#define NO_FILTER 0
#define X_CELL  1
#define Y_CELL  2
#define MULTIPLIES_CELL 3


typedef struct
{
    uint8_t command_id;
    uint32_t command_len;
    uint32_t command_resp_len;
    std::vector<uint8_t> commandBuffer;
    std::vector<uint8_t> respBuffer;
}t_serialCommand;


using namespace std;
class serialCommunication : public CommunicationIF, public std::enable_shared_from_this<serialCommunication>
{

    std::shared_ptr<QSerialPort> m_device;
    bool m_isRunning;
    dataCallback_t m_dataCallback;
    SettingsPtr m_settings;
    std::shared_ptr<serialConfiguration> m_serial_configurations;
    std::thread parserThread;
    std::mutex m_lock;



    QVector<double> m_tmp;
    void parser(void);
    void clearProcessData(void);

    /**
         * @brief GetBaudRateStr
         * @param baudrate
         * @return
         */
    string GetBaudRateStr(QSerialPort::BaudRate baudrate);

    /**
         * @brief GetParityStr
         * @param baudrate
         * @return
         */
    string GetParityStr(QSerialPort::Parity parity);

    /**
         * @brief GetDataBitsStr
         * @param databits
         * @return
         */
    string GetDataBitsStr(QSerialPort::DataBits databits);

    /**
         * @brief showHisto
         */
    //void processHisto(void);
public:


    enum dataType
    {
        AREA,
        TT,
        PEAK,
        INTENCITY
    };


    serialCommunication();

    virtual ~serialCommunication() override;

    /**
     * @brief Initialization
     */
    virtual bool Initialization(void) override;

    /**
     * @brief readData
     * @param data
     */
    virtual void readData(read_metaData *ptr_read ) override;

    /**
     * @brief writeData
     * @param data
     */
    virtual void writeData(std::vector<uint8_t> data ) override
    {

    }

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

    virtual void registerForDisconnect(closeCallback_t callback) override
    {

    }

    virtual uint64_t getTransferedByte(void) override
    {
        return 0;
    }

    virtual CommunicationDevices type(void) override
    {
        return CommunicationDevices::COMM_SERIAL;
    }

    virtual std::string type(bool is_string) override
    {
        return "Serial";
    }

    /**
     * @brief setSettingIntf
     * @param settingsIntf
     */
    void setSettingIntf(SettingsPtr settingsIntf) override;

    /**
     * @brief ParseData
     */
    void ParseData();

    /**
     * @brief getData
     * @param type
     */
    void getData(dataType type);

    /**
     * @brief parseStatus
     * @param status
     */
    void parseStatus(uint8_t status);

    /**
     * @brief sendCommand
     * @param commandMetaData
     * @return
     */
    int sendCommand(t_serialCommand *commandMetaData);

    /**
     * @brief cGetADCInstValue
     * @return
     */
    int cGetADCInstValue(void);

    /**
     * @brief cGetSerialStatus
     * @return
     */
    bool cGetSerialStatus(void);

    /**
     * @brief cSetEventThr
     * @param val
     */
    bool cSetEventThr(int val);

};

#endif // SERIALCOMMUNICATION_H
