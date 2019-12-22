#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QFileDialog>
#include <QString>
#include "usb_settings.h"
#include "serialconfiguration.h"

#if 1
namespace Ui {
class settings;
}
#endif

enum settingDevices
{
    USB,
    SERIAL,
    GENERAL
};

class settings : public QDialog
{
    Q_OBJECT

    std::map< settingDevices, settingsIF::Ptr> m_devicesSettings;

    bool setting_init;
    QString m_path;
    QString tmpPath;
    QString tempFileName;
    QString m_fileName;
    uint32_t m_numBuffer;
    uint32_t m_packetSize;
    uint32_t m_readLimit;
    uint8_t m_enableChannel;
    bool m_fileFormat;
    //serialConfiguraion m_serialConfiguration;
    QString m_currentPortName;
    uint8_t m_baudrate_index;
    uint8_t m_parity_index;
    uint8_t m_stopbit_index;

public slots:
    void browseClicked(void);
    void okCliked(void);
    void CancleCliked(void);
public:
    explicit settings(QWidget *parent = nullptr);
    ~settings();

    uint32_t  GetNumBuff( void );
    uint32_t  GetPacketSize( void );
    uint32_t  GetReadLimit( void );
    std::string  GetDataFileStorePath( void );
    std::string GetFileName(void);
    uint8_t GetEnabledChannel(void);
    bool getFileFormat(void);
    void UpdateSerialConfiguration(void);
    void show_setting_window(void);
    settingsIF::Ptr getDeviceSettings(settingDevices device);

private:
    Ui::settings *ui;
};

#endif // SETTINGS_H
