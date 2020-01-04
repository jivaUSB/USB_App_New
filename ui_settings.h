/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_settings
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *m_chkboxChannel_3;
    QLabel *m_labelPacketSize;
    QCheckBox *m_chkboxChannel_4;
    QLineEdit *m_lineEditSaveFileName;
    QLabel *m_labelCOMPort;
    QLabel *m_labelADCChannel;
    QLineEdit *m_lineEditSaveFileLocation;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *m_spinBoxReadLimit;
    QLabel *m_labelNumberOfBuffer;
    QSpinBox *m_spinBoxPacketSize;
    QLabel *m_labelSaveFileName;
    QLabel *m_labelSaveFileLoc;
    QDialogButtonBox *buttonBox;
    QCheckBox *m_chkboxChannel_2;
    QRadioButton *m_radioButtonFileType;
    QLabel *m_labelReadLimit;
    QSpinBox *m_spinBoxADCCahnnel;
    QToolButton *m_exploreButton;
    QLineEdit *m_headerUSBSettings;
    QCheckBox *m_chkboxChannel_1;
    QSpinBox *m_spinBoxNumberOfBuffer;
    QLineEdit *m_headerGeneralSettings;
    QLineEdit *m_headerUARTSettings;
    QComboBox *m_comboBoxComPort;
    QLabel *m_labelBaudRate;
    QComboBox *m_comboBoxBaudRate;

    void setupUi(QDialog *settings)
    {
        if (settings->objectName().isEmpty())
            settings->setObjectName(QString::fromUtf8("settings"));
        settings->resize(630, 448);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(settings->sizePolicy().hasHeightForWidth());
        settings->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/settings.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        settings->setWindowIcon(icon);
        settings->setStyleSheet(QString::fromUtf8("background-color: rgb(143, 143, 143);"));
        gridLayout_2 = new QGridLayout(settings);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 9, 4, 1, 1);

        m_chkboxChannel_3 = new QCheckBox(settings);
        m_chkboxChannel_3->setObjectName(QString::fromUtf8("m_chkboxChannel_3"));
        m_chkboxChannel_3->setEnabled(true);
        m_chkboxChannel_3->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";\n"
"color: rgb(236, 236, 236);"));
        m_chkboxChannel_3->setChecked(true);

        gridLayout_2->addWidget(m_chkboxChannel_3, 9, 6, 1, 1);

        m_labelPacketSize = new QLabel(settings);
        m_labelPacketSize->setObjectName(QString::fromUtf8("m_labelPacketSize"));
        m_labelPacketSize->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_labelPacketSize->sizePolicy().hasHeightForWidth());
        m_labelPacketSize->setSizePolicy(sizePolicy1);
        m_labelPacketSize->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";\n"
"color: rgb(236, 236, 236);"));

        gridLayout_2->addWidget(m_labelPacketSize, 9, 3, 1, 1);

        m_chkboxChannel_4 = new QCheckBox(settings);
        m_chkboxChannel_4->setObjectName(QString::fromUtf8("m_chkboxChannel_4"));
        m_chkboxChannel_4->setEnabled(true);
        m_chkboxChannel_4->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";\n"
"color: rgb(236, 236, 236);"));
        m_chkboxChannel_4->setChecked(true);

        gridLayout_2->addWidget(m_chkboxChannel_4, 13, 6, 1, 1);

        m_lineEditSaveFileName = new QLineEdit(settings);
        m_lineEditSaveFileName->setObjectName(QString::fromUtf8("m_lineEditSaveFileName"));

        gridLayout_2->addWidget(m_lineEditSaveFileName, 4, 0, 1, 2);

        m_labelCOMPort = new QLabel(settings);
        m_labelCOMPort->setObjectName(QString::fromUtf8("m_labelCOMPort"));
        m_labelCOMPort->setEnabled(false);
        m_labelCOMPort->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";\n"
"color: rgb(236, 236, 236);"));

        gridLayout_2->addWidget(m_labelCOMPort, 22, 3, 1, 1);

        m_labelADCChannel = new QLabel(settings);
        m_labelADCChannel->setObjectName(QString::fromUtf8("m_labelADCChannel"));
        m_labelADCChannel->setEnabled(false);
        m_labelADCChannel->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";\n"
"color: rgb(236, 236, 236);"));

        gridLayout_2->addWidget(m_labelADCChannel, 5, 3, 1, 1);

        m_lineEditSaveFileLocation = new QLineEdit(settings);
        m_lineEditSaveFileLocation->setObjectName(QString::fromUtf8("m_lineEditSaveFileLocation"));
        m_lineEditSaveFileLocation->setEnabled(false);
        m_lineEditSaveFileLocation->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(m_lineEditSaveFileLocation, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(250, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 9, 7, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 9, 2, 1, 1);

        m_spinBoxReadLimit = new QSpinBox(settings);
        m_spinBoxReadLimit->setObjectName(QString::fromUtf8("m_spinBoxReadLimit"));
        m_spinBoxReadLimit->setMinimum(40);
        m_spinBoxReadLimit->setMaximum(25600);
        m_spinBoxReadLimit->setValue(400);

        gridLayout_2->addWidget(m_spinBoxReadLimit, 14, 0, 1, 2);

        m_labelNumberOfBuffer = new QLabel(settings);
        m_labelNumberOfBuffer->setObjectName(QString::fromUtf8("m_labelNumberOfBuffer"));
        m_labelNumberOfBuffer->setEnabled(false);
        m_labelNumberOfBuffer->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";\n"
"color: rgb(236, 236, 236);"));

        gridLayout_2->addWidget(m_labelNumberOfBuffer, 13, 3, 1, 1);

        m_spinBoxPacketSize = new QSpinBox(settings);
        m_spinBoxPacketSize->setObjectName(QString::fromUtf8("m_spinBoxPacketSize"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(m_spinBoxPacketSize->sizePolicy().hasHeightForWidth());
        m_spinBoxPacketSize->setSizePolicy(sizePolicy2);
        m_spinBoxPacketSize->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);"));
        m_spinBoxPacketSize->setMinimum(4);
        m_spinBoxPacketSize->setMaximum(256);
        m_spinBoxPacketSize->setSingleStep(4);
        m_spinBoxPacketSize->setValue(64);

        gridLayout_2->addWidget(m_spinBoxPacketSize, 9, 0, 1, 2);

        m_labelSaveFileName = new QLabel(settings);
        m_labelSaveFileName->setObjectName(QString::fromUtf8("m_labelSaveFileName"));
        m_labelSaveFileName->setEnabled(false);
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(m_labelSaveFileName->sizePolicy().hasHeightForWidth());
        m_labelSaveFileName->setSizePolicy(sizePolicy3);
        m_labelSaveFileName->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";\n"
"color: rgb(236, 236, 236);"));

        gridLayout_2->addWidget(m_labelSaveFileName, 4, 3, 1, 1);

        m_labelSaveFileLoc = new QLabel(settings);
        m_labelSaveFileLoc->setObjectName(QString::fromUtf8("m_labelSaveFileLoc"));
        m_labelSaveFileLoc->setEnabled(false);
        sizePolicy3.setHeightForWidth(m_labelSaveFileLoc->sizePolicy().hasHeightForWidth());
        m_labelSaveFileLoc->setSizePolicy(sizePolicy3);
        m_labelSaveFileLoc->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";\n"
"color: rgb(236, 236, 236);"));

        gridLayout_2->addWidget(m_labelSaveFileLoc, 2, 3, 1, 1);

        buttonBox = new QDialogButtonBox(settings);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 24, 0, 1, 1);

        m_chkboxChannel_2 = new QCheckBox(settings);
        m_chkboxChannel_2->setObjectName(QString::fromUtf8("m_chkboxChannel_2"));
        m_chkboxChannel_2->setEnabled(true);
        m_chkboxChannel_2->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";\n"
"color: rgb(236, 236, 236);"));
        m_chkboxChannel_2->setChecked(true);

        gridLayout_2->addWidget(m_chkboxChannel_2, 13, 5, 1, 1);

        m_radioButtonFileType = new QRadioButton(settings);
        m_radioButtonFileType->setObjectName(QString::fromUtf8("m_radioButtonFileType"));
        m_radioButtonFileType->setEnabled(true);
        m_radioButtonFileType->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";\n"
"color: rgb(236, 236, 236);"));

        gridLayout_2->addWidget(m_radioButtonFileType, 2, 5, 1, 1);

        m_labelReadLimit = new QLabel(settings);
        m_labelReadLimit->setObjectName(QString::fromUtf8("m_labelReadLimit"));
        m_labelReadLimit->setEnabled(false);
        m_labelReadLimit->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";\n"
"color: rgb(236, 236, 236);"));

        gridLayout_2->addWidget(m_labelReadLimit, 14, 3, 1, 1);

        m_spinBoxADCCahnnel = new QSpinBox(settings);
        m_spinBoxADCCahnnel->setObjectName(QString::fromUtf8("m_spinBoxADCCahnnel"));

        gridLayout_2->addWidget(m_spinBoxADCCahnnel, 5, 0, 1, 2);

        m_exploreButton = new QToolButton(settings);
        m_exploreButton->setObjectName(QString::fromUtf8("m_exploreButton"));

        gridLayout_2->addWidget(m_exploreButton, 2, 1, 1, 1);

        m_headerUSBSettings = new QLineEdit(settings);
        m_headerUSBSettings->setObjectName(QString::fromUtf8("m_headerUSBSettings"));
        m_headerUSBSettings->setEnabled(false);
        m_headerUSBSettings->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 44, 44);\n"
"font: 87 8pt \"Arial Black\";\n"
"color: rgb(255, 255, 255);"));

        gridLayout_2->addWidget(m_headerUSBSettings, 6, 0, 1, 8);

        m_chkboxChannel_1 = new QCheckBox(settings);
        m_chkboxChannel_1->setObjectName(QString::fromUtf8("m_chkboxChannel_1"));
        m_chkboxChannel_1->setEnabled(true);
        m_chkboxChannel_1->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";\n"
"color: rgb(236, 236, 236);"));
        m_chkboxChannel_1->setChecked(true);

        gridLayout_2->addWidget(m_chkboxChannel_1, 9, 5, 1, 1);

        m_spinBoxNumberOfBuffer = new QSpinBox(settings);
        m_spinBoxNumberOfBuffer->setObjectName(QString::fromUtf8("m_spinBoxNumberOfBuffer"));
        m_spinBoxNumberOfBuffer->setMinimum(1);
        m_spinBoxNumberOfBuffer->setMaximum(16);
        m_spinBoxNumberOfBuffer->setValue(4);

        gridLayout_2->addWidget(m_spinBoxNumberOfBuffer, 13, 0, 1, 2);

        m_headerGeneralSettings = new QLineEdit(settings);
        m_headerGeneralSettings->setObjectName(QString::fromUtf8("m_headerGeneralSettings"));
        m_headerGeneralSettings->setEnabled(false);
        m_headerGeneralSettings->setStyleSheet(QString::fromUtf8("background-color: rgb(33, 33, 33);\n"
"font: 87 8pt \"Arial Black\";\n"
"color: rgb(255, 255, 255);"));

        gridLayout_2->addWidget(m_headerGeneralSettings, 0, 0, 1, 8);

        m_headerUARTSettings = new QLineEdit(settings);
        m_headerUARTSettings->setObjectName(QString::fromUtf8("m_headerUARTSettings"));
        m_headerUARTSettings->setEnabled(false);
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(m_headerUARTSettings->sizePolicy().hasHeightForWidth());
        m_headerUARTSettings->setSizePolicy(sizePolicy4);
        m_headerUARTSettings->setStyleSheet(QString::fromUtf8("background-color: rgb(33, 33, 33);\n"
"font: 87 8pt \"Arial Black\";\n"
"color: rgb(255, 255, 255);"));

        gridLayout_2->addWidget(m_headerUARTSettings, 21, 0, 1, 8);

        m_comboBoxComPort = new QComboBox(settings);
        m_comboBoxComPort->setObjectName(QString::fromUtf8("m_comboBoxComPort"));

        gridLayout_2->addWidget(m_comboBoxComPort, 22, 0, 1, 1);

        m_labelBaudRate = new QLabel(settings);
        m_labelBaudRate->setObjectName(QString::fromUtf8("m_labelBaudRate"));
        m_labelBaudRate->setEnabled(false);
        m_labelBaudRate->setStyleSheet(QString::fromUtf8("font: 87 8pt \"Arial Black\";\n"
"color: rgb(236, 236, 236);"));

        gridLayout_2->addWidget(m_labelBaudRate, 23, 3, 1, 1);

        m_comboBoxBaudRate = new QComboBox(settings);
        m_comboBoxBaudRate->addItem(QString());
        m_comboBoxBaudRate->addItem(QString());
        m_comboBoxBaudRate->addItem(QString());
        m_comboBoxBaudRate->addItem(QString());
        m_comboBoxBaudRate->addItem(QString());
        m_comboBoxBaudRate->addItem(QString());
        m_comboBoxBaudRate->setObjectName(QString::fromUtf8("m_comboBoxBaudRate"));

        gridLayout_2->addWidget(m_comboBoxBaudRate, 23, 0, 1, 1);


        retranslateUi(settings);
        QObject::connect(buttonBox, SIGNAL(accepted()), settings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), settings, SLOT(reject()));

        m_comboBoxComPort->setCurrentIndex(-1);
        m_comboBoxBaudRate->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(settings);
    } // setupUi

    void retranslateUi(QDialog *settings)
    {
        settings->setWindowTitle(QApplication::translate("settings", "Settings", nullptr));
        m_chkboxChannel_3->setText(QApplication::translate("settings", "Channel 3", nullptr));
        m_labelPacketSize->setText(QApplication::translate("settings", "Packet Size (KB)", nullptr));
        m_chkboxChannel_4->setText(QApplication::translate("settings", "Channel 4", nullptr));
        m_labelCOMPort->setText(QApplication::translate("settings", "COM Ports", nullptr));
        m_labelADCChannel->setText(QApplication::translate("settings", "ADC Channel", nullptr));
        m_labelNumberOfBuffer->setText(QApplication::translate("settings", "Number of buffer", nullptr));
        m_labelSaveFileName->setText(QApplication::translate("settings", "Save File Name", nullptr));
        m_labelSaveFileLoc->setText(QApplication::translate("settings", "Save File Location", nullptr));
        m_chkboxChannel_2->setText(QApplication::translate("settings", "Channel 2", nullptr));
        m_radioButtonFileType->setText(QApplication::translate("settings", "Text", nullptr));
        m_labelReadLimit->setText(QApplication::translate("settings", "Read Limit (MB)", nullptr));
        m_exploreButton->setText(QApplication::translate("settings", "...", nullptr));
        m_headerUSBSettings->setText(QApplication::translate("settings", "USB Settings", nullptr));
        m_chkboxChannel_1->setText(QApplication::translate("settings", "Channel 1", nullptr));
        m_headerGeneralSettings->setText(QApplication::translate("settings", "General Settings", nullptr));
        m_headerUARTSettings->setText(QApplication::translate("settings", "UART Settings", nullptr));
        m_labelBaudRate->setText(QApplication::translate("settings", "Baud Rate", nullptr));
        m_comboBoxBaudRate->setItemText(0, QApplication::translate("settings", "9600", nullptr));
        m_comboBoxBaudRate->setItemText(1, QApplication::translate("settings", "19200", nullptr));
        m_comboBoxBaudRate->setItemText(2, QApplication::translate("settings", "38400", nullptr));
        m_comboBoxBaudRate->setItemText(3, QApplication::translate("settings", "57600", nullptr));
        m_comboBoxBaudRate->setItemText(4, QApplication::translate("settings", "115200", nullptr));
        m_comboBoxBaudRate->setItemText(5, QApplication::translate("settings", "1152000", nullptr));

    } // retranslateUi

};

namespace Ui {
    class settings: public Ui_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
