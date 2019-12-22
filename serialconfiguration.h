#ifndef SERIALCONFIGURATION_H
#define SERIALCONFIGURATION_H


#include "settingsif.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class settings;

class serialConfiguration: public settingsIF
{
    friend class settings;

    QString portName;
    QSerialPort::BaudRate baudrate;
    QSerialPort::DataBits dataBits;
    QSerialPort::Parity parity;
    QSerialPort::StopBits stopbit;
    QSerialPort::FlowControl flowControl;

public:
    serialConfiguration()
    {
        portName = "";
        baudrate  = QSerialPort::Baud115200;
        dataBits =  QSerialPort::Data8;
        parity = QSerialPort::NoParity;
        stopbit = QSerialPort::OneStop;
        flowControl = QSerialPort::NoFlowControl;
    }

    virtual ~serialConfiguration()
    {

    }

    QString getPortName(void) { return portName; }
    QSerialPort::BaudRate getBaudRate(void) { return baudrate; }
    QSerialPort::DataBits getDataBits(void) { return dataBits; }
    QSerialPort::Parity getParity(void) { return parity; }
    QSerialPort::StopBits getStopBit(void) { return stopbit; }
    QSerialPort::FlowControl getFlowControl(void) { return flowControl; }
};

#endif // SERIALCONFIGURATION_H
