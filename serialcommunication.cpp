
#include <iostream>
#include <QVector>
#include <fstream>
#include "serialcommunication.h"
#include "logger.h"
#include <types.h>

histoData h_data;

using namespace std;
serialCommunication::serialCommunication()
{
    m_device = make_shared<QSerialPort>();
    m_isRunning = false;
    h_data.isCounterOn = false;

    clearProcessData();
}

serialCommunication::~serialCommunication()
{

}
void serialCommunication::parser(void)
{
    clearProcessData();

    auto *ptr_read_data = new read_metaData();

    while (m_isRunning)
    {
        Sleep(2);
        ptr_read_data->clear();
        ptr_read_data->len = 2;
        readData(ptr_read_data);

        if(ptr_read_data->actual_read  == ptr_read_data->len)
        {
            uint16_t header = ptr_read_data->buffer[0];
            header = ((header << 8) | ptr_read_data->buffer[1]);

            if(header == 0x3301)
            {
                uint16_t transmitTime = 0;
                ptr_read_data->clear();
                ptr_read_data->len = 2;
                readData(ptr_read_data);
                if(ptr_read_data->actual_read  == ptr_read_data->len)
                {
                    uint16_t peak = ptr_read_data->buffer[0];
                    peak = ((peak << 8) | ptr_read_data->buffer[1]);
                    h_data.m_peak.push_back(static_cast<double>(peak));
                }
                ptr_read_data->clear();
                ptr_read_data->len = 2;
                readData(ptr_read_data);
                if(ptr_read_data->actual_read  == ptr_read_data->len)
                {
                    transmitTime = 0;
                    transmitTime = ptr_read_data->buffer[0];
                    transmitTime = ((transmitTime << 8) | ptr_read_data->buffer[1]);
                    h_data.m_transmitTime.push_back(static_cast<double>(transmitTime));
                }
                ptr_read_data->clear();
                ptr_read_data->len = 4;
                readData(ptr_read_data);
                if(ptr_read_data->actual_read  == ptr_read_data->len)
                {
                    uint32_t area = ptr_read_data->buffer[0];
                    area = ((area << 8) | ptr_read_data->buffer[1]);
                    area = ((area << 8) | ptr_read_data->buffer[2]);
                    area = ((area << 8) | ptr_read_data->buffer[3]);
                    h_data.m_area.push_back(static_cast<double>(area));
                    h_data.m_intencity.push_back(static_cast<double>(area/transmitTime));
                }

#if 1
                ptr_read_data->clear();
                ptr_read_data->len = 1;
                readData(ptr_read_data);
                if(ptr_read_data->actual_read  == ptr_read_data->len)
                {
                   h_data.m_status.push_back(ptr_read_data->buffer[0]);
                   parseStatus(ptr_read_data->buffer[0]);
                }
#endif
            }
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
        m_device->setBaudRate(m_serial_configurations->getBaudRate());
        m_device->setDataBits(m_serial_configurations->getDataBits());
        m_device->setParity(m_serial_configurations->getParity());
        m_device->setStopBits(m_serial_configurations->getStopBit());
        m_device->setFlowControl(m_serial_configurations->getFlowControl());

        if(m_device->open(QIODevice::ReadWrite))
        {
            if(cGetSerialStatus())
            {
                ret = m_isRunning =  true;
                parserThread = std::thread(std::bind(&serialCommunication::parser,this));
            }
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
   std::lock_guard<std::mutex> guard(m_lock);
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

void serialCommunication::clearProcessData(void)
{
    h_data.m_area.clear();
    h_data.m_peak.clear();
    h_data.m_intencity.clear();
    h_data.m_transmitTime.clear();

    h_data.m_xCellCount = 0;
    h_data.m_yCellCount = 0;
    h_data.m_multiCellCount = 0;
    h_data.m_totalCellCount = 0;

    h_data.m_area.reserve(1024*1024*10);
    h_data.m_peak.reserve(1024*1024*10);
    h_data.m_intencity.reserve(1024*1024*10);
    h_data.m_intencity.reserve(1024*1024*10);
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

void serialCommunication::getData(dataType type)
{
    if(type == AREA && h_data.m_area.size())
    {
         //return m_area;
    }
    else if(type == PEAK && h_data.m_peak.size())
    {
         //return m_peak;
    }
    else if(type == TT && h_data.m_transmitTime.size())
    {
         //return m_transmitTime;
    }
    else if(type == INTENCITY && h_data.m_intencity.size())
    {
         //return m_intencity;
    }
}

void serialCommunication::parseStatus(uint8_t status)
{
    if(h_data.isCounterOn)
    {
        switch (status & 0x07) {
        default:
            break;
        case  X_CELL:
            h_data.m_xCellCount++;
            break;
        case  Y_CELL:
            h_data.m_yCellCount++;
            break;
        case  MULTIPLIES_CELL:
            h_data.m_multiCellCount++;
            break;

        }

        h_data.m_totalCellCount = h_data.m_xCellCount +
                h_data.m_yCellCount + h_data.m_multiCellCount;
    }
}
int serialCommunication::sendCommand(t_serialCommand *commandMetaData)
{
    int ret = -1;
    std::lock_guard<std::mutex> guard(m_lock);
    if ( (commandMetaData != nullptr) && (m_device) )
    {
        std::vector<uint8_t> packet;
        packet.push_back(commandMetaData->command_id);
        //packet.push_back(commandMetaData->command_len);

        if(commandMetaData->command_len == commandMetaData->commandBuffer.size())
        {
            packet.insert(packet.end(),commandMetaData->commandBuffer.begin(),commandMetaData->commandBuffer.end());
            if( m_device->write((char *)packet.data(), packet.size()) )
            {
                m_device->waitForBytesWritten();
                if(commandMetaData->command_resp_len)
                {
                    commandMetaData->respBuffer.clear();
                    commandMetaData->respBuffer.resize(commandMetaData->command_resp_len);

                    m_device->waitForReadyRead();
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
        if(command.respBuffer.size() == command.command_resp_len)
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

bool serialCommunication::cGetSerialStatus(void)
{
    bool ret = false;

    t_serialCommand command;
    command.command_id = 0xf1;
    command.command_len = 0x00;
    command.command_resp_len = 0x01;
    if (!sendCommand(&command))
    {
        if(command.respBuffer.size() == command.command_resp_len)
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
    command.commandBuffer.push_back((uint8_t)val);
    command.commandBuffer.push_back((uint8_t)((val >> 8) & 0xff));
    if (!sendCommand(&command))
    {
        if(command.respBuffer.size() == command.command_resp_len)
        {
            ret = (command.respBuffer[0] == command.command_id) ? true : false;
        }
    }
    return ret;
}
