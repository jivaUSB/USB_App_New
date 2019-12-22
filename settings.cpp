#include "settings.h"
#include "ui_settings.h"
#include <iostream>
#include <QStandardPaths>
#include "logger.h"
//#include <QSerialPortInfo>

settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{
    setting_init = false;
    m_fileFormat = true;
    m_fileName = "Default";
    m_enableChannel = 0;
    ui->setupUi(this);

    m_numBuffer = ui->m_spinBoxNumberOfBuffer->value();
    m_readLimit = ui->m_spinBoxReadLimit->value();
    m_packetSize = ui->m_spinBoxPacketSize->value();

    m_path = QDir::toNativeSeparators( QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) );
    tmpPath = m_path;
    ui->m_lineEditSaveFileLocation->setText(m_path);
    ui->m_lineEditSaveFileName->setText(m_fileName);
    m_fileName = ui->m_lineEditSaveFileName->text();
    m_fileFormat = (ui->m_radioButtonFileType->isChecked()) ? true: false;

    m_enableChannel = ui->m_chkboxChannel_1->isChecked() ? m_enableChannel |= (1 << 0): m_enableChannel &= ~(1 << 0);
    m_enableChannel = ui->m_chkboxChannel_1->isChecked() ? m_enableChannel |= (1 << 1): m_enableChannel &= ~(1 << 1);
    m_enableChannel = ui->m_chkboxChannel_1->isChecked() ? m_enableChannel |= (1 << 2): m_enableChannel &= ~(1 << 2);
    m_enableChannel = ui->m_chkboxChannel_1->isChecked() ? m_enableChannel |= (1 << 3): m_enableChannel &= ~(1 << 3);

    connect(ui->m_exploreButton, SIGNAL (released()), this ,SLOT(browseClicked()));
    connect(ui->buttonBox, SIGNAL (accepted()), this ,SLOT(okCliked()));
    connect(ui->buttonBox, SIGNAL (rejected()), this ,SLOT(CancleCliked()));

    auto ptr = std::make_shared<settings_usb>();
    ptr->readLimit = ui->m_spinBoxReadLimit->value();
    ptr->bufferSize = ui->m_spinBoxNumberOfBuffer->value();
    ptr->packetSize = ui->m_spinBoxPacketSize->value();
    m_devicesSettings[USB] = ptr;
    m_devicesSettings[SERIAL] = std::make_shared<serialConfiguration>();
    UpdateSerialConfiguration();

}

settings::~settings()
{
    delete ui;
}

void settings::CancleCliked(void)
{
    ui->m_lineEditSaveFileName->setText(m_fileName);
    ui->m_lineEditSaveFileLocation->setText(m_path);
    ui->m_spinBoxNumberOfBuffer->setValue(m_numBuffer);
    ui->m_spinBoxReadLimit->setValue(m_readLimit);
    ui->m_spinBoxPacketSize->setValue(m_packetSize);
    if(m_fileFormat) ui->m_radioButtonFileType->setChecked(true);


    ui->m_chkboxChannel_1->setChecked(false);
    if(m_enableChannel & 0x01)
        ui->m_chkboxChannel_1->setChecked(true);

    ui->m_chkboxChannel_2->setChecked(false);
    if(m_enableChannel & 0x02)
        ui->m_chkboxChannel_2->setChecked(true);

    ui->m_chkboxChannel_3->setChecked(false);
    if(m_enableChannel & 0x04)
        ui->m_chkboxChannel_3->setChecked(true);

    ui->m_chkboxChannel_4->setChecked(false);
    if(m_enableChannel & 0x08)
        ui->m_chkboxChannel_4->setChecked(true);

    ui->m_comboBoxComPort->setCurrentText(m_currentPortName);
    ui->m_comboBoxBaudRate->setCurrentIndex(m_baudrate_index);
}

void settings::okCliked(void)
{
    setting_init = true;
    m_path = tmpPath;
    m_fileName = ui->m_lineEditSaveFileName->text();
    m_numBuffer = ui->m_spinBoxNumberOfBuffer->value();
    m_readLimit = ui->m_spinBoxReadLimit->value();
    m_packetSize = ui->m_spinBoxPacketSize->value();
    m_fileFormat = (ui->m_radioButtonFileType->isChecked()) ? true: false;
    m_enableChannel = ui->m_chkboxChannel_1->isChecked() ? m_enableChannel |= (1 << 0): m_enableChannel &= ~(1 << 0);
    m_enableChannel = ui->m_chkboxChannel_2->isChecked() ? m_enableChannel |= (1 << 1): m_enableChannel &= ~(1 << 1);
    m_enableChannel = ui->m_chkboxChannel_3->isChecked() ? m_enableChannel |= (1 << 2): m_enableChannel &= ~(1 << 2);
    m_enableChannel = ui->m_chkboxChannel_4->isChecked() ? m_enableChannel |= (1 << 3): m_enableChannel &= ~(1 << 3);

    UpdateSerialConfiguration();
}

void settings::browseClicked(void)
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select Save Directory"),
                                                "C:/Users/jivai/OneDrive/Desktop/my_data_check",
                                                QFileDialog::ShowDirsOnly
                                                | QFileDialog::DontResolveSymlinks);

    tmpPath = QDir::toNativeSeparators( dir );
    if(tmpPath.size())
        ui->m_lineEditSaveFileLocation->setText(tmpPath.toStdString().c_str());
}

uint32_t settings::GetNumBuff(void)
{
    return  m_numBuffer;
}

uint32_t settings::GetReadLimit(void)
{
    return  m_readLimit;
}

uint32_t settings::GetPacketSize(void)
{
    return  m_packetSize;
}

std::string settings::GetDataFileStorePath(void)
{
        return m_path.toStdString();
}

std::string settings::GetFileName(void)
{
    return m_fileName.toStdString();
}

uint8_t settings::GetEnabledChannel(void)
{
    return m_enableChannel;
}

bool settings::getFileFormat(void)
{
    return  m_fileFormat;
}

void settings::show_setting_window(void)
{
    Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
           ui->m_comboBoxComPort->addItem(port.portName());
       }

    m_currentPortName = ui->m_comboBoxComPort->currentText();
    m_baudrate_index = (uint8_t)ui->m_comboBoxBaudRate->currentIndex();

    this->show();
}

settingsIF::Ptr settings::getDeviceSettings(settingDevices device)
{
    settingsIF::Ptr ret;

    auto it = m_devicesSettings.find(device);
    if(it != m_devicesSettings.end())
    {
        ret = it->second;
    }
    else {
        logger::getInstance()->log("ERROR : No Device Settings avialable");
    }
    return ret;
}

void settings::UpdateSerialConfiguration(void)
{
    std::shared_ptr<serialConfiguration> setting_ptr = std::dynamic_pointer_cast<serialConfiguration>(m_devicesSettings[SERIAL]);

    setting_ptr->portName = ui->m_comboBoxComPort->currentText();
    switch (ui->m_comboBoxBaudRate->currentIndex())
    {
    default:
        break;
    case 0:
        setting_ptr->baudrate = QSerialPort::Baud9600;
        break;
    case 1:
        setting_ptr->baudrate = QSerialPort::Baud19200;
        break;
    case 2:
        setting_ptr->baudrate = QSerialPort::Baud38400;
        break;
    case 3:
        setting_ptr->baudrate = QSerialPort::Baud57600;
        break;
    case 4:
        setting_ptr->baudrate = QSerialPort::Baud115200;
        break;
    };
}
