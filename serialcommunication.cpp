
#include <iostream>
#include <QVector>
#include <fstream>
#include "serialcommunication.h"
#include "logger.h"
#include <types.h>
#include <QThread>

using namespace std;
serialCommunication::serialCommunication()
{
    m_device = make_shared<QSerialPort>();
    m_isRunning = false;
    m_channel = 0xab01;
}

serialCommunication::~serialCommunication()
{

}
void serialCommunication::parser(void)
{
    enum READ_STATE {
        HEADER,
        CHANNEL,
        PEAK_0,
        PEAK_1,
        AREA_0,
        AREA_1,
        AREA_2,
        AREA_3,
        TT_0,
        TT_1,
        STATUS
    };

    serialReadData fetched_data;
    READ_STATE current_state = HEADER;
    while (m_isRunning)
    {
        QThread::usleep(100);
        std::lock_guard<std::mutex> guard(m_lock);
        std::vector<uint8_t> buffer;
        auto buff = m_device->readAll();
        buffer.insert(buffer.end(),buff.begin(),buff.end());
        uint32_t availableSize = buffer.size();
        uint32_t pointer = 0;
        while(availableSize > pointer)
        {
            switch (current_state) {
            case HEADER:
                if(buffer[pointer++] == ((m_channel >> 8) & 0xff))
                    current_state = CHANNEL;
                break;
            case CHANNEL:
                if(buffer[pointer++] == (m_channel & 0xff))
                    current_state = PEAK_0;
                break;
            case PEAK_0:
                fetched_data.m_peak = buffer[pointer++];
                current_state = PEAK_1;
                break;
            case PEAK_1:
                fetched_data.m_peak = (((uint32_t)fetched_data.m_peak << 8) | buffer[pointer++]);
                current_state = AREA_0;
                break;
            case AREA_0:
                fetched_data.m_area = buffer[pointer++];
                current_state = AREA_1;
                break;
            case AREA_1:
                fetched_data.m_area = (((uint32_t)fetched_data.m_area << 8) | buffer[pointer++]);
                current_state = AREA_2;
                break;
            case AREA_2:
                fetched_data.m_area = (((uint32_t)fetched_data.m_area << 8) | buffer[pointer++]);
                current_state = AREA_3;
                break;
            case AREA_3:
                fetched_data.m_area = (((uint32_t)fetched_data.m_area << 8) | buffer[pointer++]);
                current_state = TT_0;
                break;
            case TT_0:
                fetched_data.m_transmitTime = buffer[pointer++];
                current_state = TT_1;
                break;
            case TT_1:
                fetched_data.m_transmitTime = (((uint32_t)fetched_data.m_transmitTime << 8) | buffer[pointer++]);
                fetched_data.m_intencity = fetched_data.m_area/fetched_data.m_transmitTime;
                current_state = STATUS;
                break;
            case STATUS:
                fetched_data.m_status = buffer[pointer++];

                //                printf("peak : 0x%X\n", (uint16_t)fetched_data.m_peak);
                //                printf("area : 0x%X\n", (uint32_t)fetched_data.m_area);
                //                printf("TT : 0x%X\n", (uint16_t)fetched_data.m_transmitTime);
                //                printf("Intensity : 0x%X\n", (uint16_t)fetched_data.m_intencity);
                //                printf("Status : 0x%X\n", (uint8_t)fetched_data.m_status);
                //                buffer.erase(buffer.begin(), buffer.begin() + pointer);

                m_updateReadData(&fetched_data);
                current_state = HEADER;
                break;
            };
        }
    }
}

bool serialCommunication::Initialization()
{
    bool ret = false;

     m_serial_configurations = std::static_pointer_cast<serialConfiguration>(m_settings->getDeviceSettings(SERIAL));

    std::cout << "*********** Serial Configuration ****************" << std::endl;
    std::cout << "Port Name:  " << m_serial_configurations->getPortName().toStdString() << std::endl;
    std::cout << "Baud Rate : " << GetBaudRateStr(m_serial_configurations->getBaudRate()) << std::endl;
    std::cout << "Parity : " << GetParityStr(m_serial_configurations->getParity()) << std::endl;
    std::cout << "Data Bits : " << GetDataBitsStr(m_serial_configurations->getDataBits()) << std::endl;
    auto str = (m_serial_configurations->getStopBit() == QSerialPort::OneStop) ? "One Bit" : "Two Bit";
    std::cout << "Stop bit : " <<  str  << std::endl;

    if(m_device)
    {
        m_device->setPortName(m_serial_configurations->getPortName());
        if(m_serial_configurations->getBaudRate() == QSerialPort::Baud4800)
            m_device->setBaudRate(1152000);
        else
            m_device->setBaudRate(m_serial_configurations->getBaudRate());
        m_device->setDataBits(m_serial_configurations->getDataBits());
        m_device->setParity(m_serial_configurations->getParity());
        m_device->setStopBits(m_serial_configurations->getStopBit());
        m_device->setFlowControl(m_serial_configurations->getFlowControl());

        if(m_device->open(QIODevice::ReadWrite))
        {
            ret = cGetSerialStatus(true);
        }
        else
        {
            std::cout << "Error: Not Able to Open " << m_serial_configurations->getPortName().toStdString() << "Serial Port" << std::endl;
        }
    }
    return ret;
}

void serialCommunication::readData(read_metaData *ptr_read_data)
{
   if(m_device && ptr_read_data)
   {
       if(m_device->isOpen())
       {
           ptr_read_data->buffer.clear();
           ptr_read_data->buffer.resize(ptr_read_data->len);
           m_device->read((char *)&ptr_read_data->buffer[0],ptr_read_data->len);
           ptr_read_data->actual_read = static_cast<uint16_t>(ptr_read_data->buffer.size());
       }
   }
}

void serialCommunication::clean(bool isInt)
{
    m_isRunning =  false;
    parserThread.join();
    cGetSerialStatus(false);
    m_device->close();
}

std::string serialCommunication::GetBaudRateStr(QSerialPort::BaudRate baudrate)
{
    std::string retStr;
    switch(baudrate)
    {
    default:
        retStr = "Not Valid BaudRate";
        break;
    case QSerialPort::Baud9600:
        retStr = "9600";
        break;
    case QSerialPort::Baud19200:
        retStr = "19200";
        break;
    case QSerialPort::Baud38400:
        retStr = "38400";
        break;
    case QSerialPort::Baud57600:
        retStr = "57600";
        break;
    case QSerialPort::Baud115200:
        retStr = "115200";
        break;
    case QSerialPort::Baud4800:
        retStr = "1152000";
        break;
    }
    return  retStr;
}


std::string serialCommunication::GetParityStr(QSerialPort::Parity parity)
{
    std::string retStr;
    switch(parity)
    {
    default:
        retStr = "No Parity";
        break;
    case QSerialPort::EvenParity:
        retStr = "Even";
        break;
    case QSerialPort::OddParity:
        retStr = "Odd";
        break;
    }
    return  retStr;
}

std::string serialCommunication::GetDataBitsStr(QSerialPort::DataBits databits)
{
    std::string retStr;
    switch(databits)
    {
    default:
        retStr = "No Data Bits";
        break;
    case QSerialPort::Data7:
        retStr = "7-Bit";
        break;
    case QSerialPort::Data8:
        retStr = "8-Bit";
        break;
    }
    return  retStr;
}

void serialCommunication::registerForData(dataCallback_t callback)
{
    m_dataCallback = callback;
    logger::getInstance()->log("Callback Registered");
}

void serialCommunication::setSettingIntf(SettingsPtr settingsIntf)
{
    m_settings = settingsIntf;
}

int serialCommunication::sendCommand(t_serialCommand *commandMetaData)
{
    std::lock_guard<std::mutex> guard(m_lock);
    int ret = -1;
    if ( (commandMetaData != nullptr) && (m_device) )
    {
        std::vector<uint8_t> packet;
        packet.push_back(commandMetaData->command_id);

        if(commandMetaData->command_len == commandMetaData->commandBuffer.size())
        {
            m_device->clear();
            packet.insert(packet.end(),commandMetaData->commandBuffer.begin(),commandMetaData->commandBuffer.end());
            if( m_device->write((char *)packet.data(), packet.size()) )
            {
                m_device->waitForBytesWritten();
                if(commandMetaData->command_resp_len)
                {
                    m_device->waitForReadyRead();
                    commandMetaData->respBuffer.clear();
                    commandMetaData->respBuffer.resize(commandMetaData->command_resp_len);

                    if ( m_device->read((char *)&commandMetaData->respBuffer[0], commandMetaData->command_resp_len))
                        ret = 0;
                }
                else
                    ret = 0;
            }
        }
    }
    return ret;
}

int serialCommunication::cGetADCInstValue(void)
{
    int ret = -1;
    t_serialCommand command;
    command.command_id = 0xfe;
    command.command_len = 0x00;
    command.command_resp_len = 0x03;
    if (!sendCommand(&command))
    {
        if(command.command_resp_len == 0)
            ret = true;
        else if(command.respBuffer.size() == command.command_resp_len)
        {
            if(command.respBuffer[0] == command.command_id)
            {
                ret = command.respBuffer[1];
                ret = ((ret << 8) | command.respBuffer[2]);
            }
        }
    }
    return ret;
}

bool serialCommunication::cGetSerialStatus(bool enable)
{
    bool ret = false;

    t_serialCommand command;
    command.command_id = (enable) ? 0xf1 : 0xf7;
    command.command_len = 0x00;
    command.command_resp_len = 0x01;
    if (!sendCommand(&command))
    {
        if (command.command_resp_len == 0)
            ret = true;
        else if(command.respBuffer.size() == command.command_resp_len)
        {
            ret = (command.command_id == command.respBuffer[0]) ? true : false;
        }
    }
    return ret;
}

bool serialCommunication::cSetEventThr(int val)
{
    bool ret = false;
    t_serialCommand command;
    command.command_id = 0xef;
    command.command_len = 0x02;
    command.command_resp_len = 0x01;
    command.commandBuffer.push_back((uint8_t)((val >> 8) & 0xff));
    command.commandBuffer.push_back((uint8_t)val);

    if (!sendCommand(&command))
    {
        if (command.command_resp_len == 0)
            ret = true;
        else if(command.respBuffer.size() == command.command_resp_len)
        {
            ret = (command.respBuffer[0] == command.command_id) ? true : false;
        }
    }
    return ret;
}

void serialCommunication::registerForData(std::function<void(struct serialReadData *)> cbDataCallback)
{
    m_updateReadData = cbDataCallback;
}

bool serialCommunication::cEnabledHisto(bool enabled)
{
    bool ret = false;

    t_serialCommand command;
    command.command_id = (enabled) ? 0xf9:0xf8;
    command.command_len = 0x00;
    command.command_resp_len = 0x01;
    if (!sendCommand(&command))
    {
        if (command.command_resp_len == 0 || !enabled)
             ret = true;
        else if(command.respBuffer.size() == command.command_resp_len)
        {
            ret = (command.command_id == command.respBuffer[0]) ? true : false;
        }

        if(ret)
        {
            m_isRunning = enabled;
            if(enabled)
               parserThread = std::thread(std::bind(&serialCommunication::parser,this));
            else
               parserThread.join();
        }
    }
    return ret;
}

bool serialCommunication::cSetTTThr(int upperThr, int lowerThr)
{
    bool ret = true;
    t_serialCommand command;
    command.command_id = 0xee;
    command.command_len = 0x04;
    command.command_resp_len = 0x00;

    command.commandBuffer.push_back((uint8_t)((lowerThr >> 8) & 0xff));
    command.commandBuffer.push_back((uint8_t)lowerThr);

    command.commandBuffer.push_back((uint8_t)((upperThr >> 8) & 0xff));
    command.commandBuffer.push_back((uint8_t)upperThr);

    if (!sendCommand(&command))
    {
        if (command.command_resp_len == 0)
             ret = true;
        else if(command.respBuffer.size() == command.command_resp_len)
        {
            ret = (command.respBuffer[0] == command.command_id) ? true : false;
        }
    }
    return ret;
}

bool serialCommunication::cEnabledTTThr(bool enable)
{
    bool ret = true;

    t_serialCommand command;
    command.command_id = (enable) ? 0xE8:0xED;
    command.command_len = 0x00;
    command.command_resp_len = 0x00;
    if (!sendCommand(&command))
    {
        if(command.command_resp_len == 0)
            ret = true;
        else if(command.respBuffer.size() == command.command_resp_len)
        {
            ret = (command.command_id == command.respBuffer[0]) ? true : false;
        }
    }
    return ret;
}

bool serialCommunication::cSetAblationThr(int val)
{
    bool ret = true;
    t_serialCommand command;
    command.command_id = 0xec;
    command.command_len = 0x04;
    command.command_resp_len = 0x00;

    command.commandBuffer.push_back((uint8_t)((val >> 24) & 0xff));
    command.commandBuffer.push_back((uint8_t)((val >> 16) & 0xff));
    command.commandBuffer.push_back((uint8_t)((val >> 8) & 0xff));
    command.commandBuffer.push_back((uint8_t)val);

    if (!sendCommand(&command))
    {
        if (command.command_resp_len == 0)
            ret = true;
        else if(command.respBuffer.size() == command.command_resp_len)
        {
            ret = (command.respBuffer[0] == command.command_id) ? true : false;
        }
    }
    return ret;
}

bool serialCommunication::cEnabledAblationThr(bool enable)
{
    bool ret = true;

    t_serialCommand command;
    command.command_id = (enable) ? 0xE7:0xEB;
    command.command_len = 0x00;
    command.command_resp_len = 0x00;
    if (!sendCommand(&command))
    {
        if(command.command_resp_len == 0)
            ret = true;
        else if(command.respBuffer.size() == command.command_resp_len)
        {
            ret = (command.command_id == command.respBuffer[0]) ? true : false;
        }
    }
    return ret;
}

bool serialCommunication::cSetPeakIntensityThr(int upperThr, int lowerThr)
{
    bool ret = true;
    t_serialCommand command;
    command.command_id = 0xea;
    command.command_len = 0x04;
    command.command_resp_len = 0x00;

    command.commandBuffer.push_back((uint8_t)((lowerThr >> 8) & 0xff));
    command.commandBuffer.push_back((uint8_t)lowerThr);

    command.commandBuffer.push_back((uint8_t)((upperThr >> 8) & 0xff));
    command.commandBuffer.push_back((uint8_t)upperThr);

    if (!sendCommand(&command))
    {
        if(command.command_resp_len == 0)
            ret = true;
        else if(command.respBuffer.size() == command.command_resp_len)
        {
            ret = (command.respBuffer[0] == command.command_id) ? true : false;
        }
    }
    return ret;
}

bool serialCommunication::cEnabledPeakIntensityThr(bool enable)
{
    bool ret = true;

    t_serialCommand command;
    command.command_id = (enable) ? 0xE6:0xE9;
    command.command_len = 0x00;
    command.command_resp_len = 0x00;
    if (!sendCommand(&command))
    {
        if(command.command_resp_len == 0)
            ret = true;
        else if(command.respBuffer.size() == command.command_resp_len)
        {
            ret = (command.command_id == command.respBuffer[0]) ? true : false;
        }
    }
    return ret;
}

void serialCommunication::setCurrentChannel(uint16_t channel)
{
    m_channel = channel;
}
