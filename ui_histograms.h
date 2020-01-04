/********************************************************************************
** Form generated from reading UI file 'histograms.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOGRAMS_H
#define UI_HISTOGRAMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_histograms
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QFrame *m_fCellDataCounter;
    QLabel *m_vXCellCount;
    QLabel *m_vYCell_Count;
    QLabel *m_labelMultiCellCount;
    QLabel *m_vMultiCellCount;
    QLabel *m_vTotalCount;
    QLabel *m_vAlbationFireCount;
    QLabel *m_labelAlbationFireCount;
    QLabel *m_labelYCell_Count;
    QLabel *m_labelXCellCount;
    QLabel *m_boxLabelCellData;
    QLabel *m_labelTotalCount;
    QFrame *m_fLASERTriggerParams;
    QPushButton *m_bLaserSet;
    QPushButton *m_bEnableAblation;
    QLabel *m_labelOnTime;
    QLabel *m_labelOffTime;
    QLabel *m_labelTriggerWaitTime;
    QLabel *m_labelNumTriggerPulse;
    QLabel *m_labelBoxLaserTriggerParam;
    QTextEdit *m_vOnTime;
    QTextEdit *m_vOffTime;
    QTextEdit *m_vTriggerWaitTime;
    QTextEdit *m_vNumTriggerPulse;
    QFrame *frame_2;
    QLabel *m_labelUTThreshold;
    QLabel *m_labelLTThreshold;
    QLabel *m_labelUPIThreshold;
    QLabel *m_labelLPIThreshold;
    QPushButton *m_bUTIOn;
    QPushButton *m_bUPIOn;
    QLabel *m_labelSomTTThreshold;
    QPushButton *m_bSumOfIntTTOn;
    QLabel *m_labelBoxLaserTriggerParam_2;
    QTextEdit *m_vUTThreshold;
    QTextEdit *m_vLTThreshold;
    QTextEdit *m_vUPIThreshold;
    QTextEdit *m_vLPIThreshold;
    QTextEdit *m_vSomTTThreshold;
    QPushButton *m_bUTISet;
    QPushButton *m_bUPISet;
    QPushButton *m_bSumOfIntTTSet;
    QScrollArea *TT_window;
    QWidget *scrollAreaWidgetContents_4;
    QGridLayout *gridLayout_5;
    QCustomPlot *tt_histo;
    QLineEdit *tt_Median;
    QLineEdit *tt_Dev;
    QScrollArea *area_window;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QCustomPlot *area_histo;
    QLineEdit *area_Median;
    QLineEdit *area_Dev;
    QScrollArea *peak_window;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_3;
    QCustomPlot *peak_histo;
    QLineEdit *peak_Median;
    QLineEdit *peak_Dev;
    QWidget *m_histoSettings;
    QPushButton *m_bGetInstADCVal;
    QPushButton *m_bSetEventThr;
    QLabel *m_vEventElapsed;
    QPushButton *m_bRstCounter;
    QCheckBox *m_cbTextFileSave;
    QCheckBox *m_cbStartCounter;
    QLabel *m_labelInstADCval;
    QLabel *m_labelEventThr;
    QLabel *m_labelEventElapse;
    QLabel *m_labelUpFreq;
    QLabel *m_labelRstCounter;
    QPushButton *m_bEnableHisto;
    QLabel *m_labelEnableHisto;
    QTextEdit *m_vInstADCVal;
    QTextEdit *m_vEvtThrs;
    QSpinBox *m_vUpdateFreq;
    QRadioButton *m_channel_1;
    QRadioButton *m_channel_2;
    QScrollArea *intencity_window;
    QWidget *scrollAreaWidgetContents_3;
    QGridLayout *gridLayout_4;
    QCustomPlot *intensity_histo;
    QLineEdit *intensity_Dev;
    QLineEdit *intensity_Median;

    void setupUi(QWidget *histograms)
    {
        if (histograms->objectName().isEmpty())
            histograms->setObjectName(QString::fromUtf8("histograms"));
        histograms->resize(1920, 1080);
        histograms->setStyleSheet(QString::fromUtf8("background-color: rgb(143, 143, 143);"));
        gridLayout = new QGridLayout(histograms);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(histograms);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(250, 0));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        m_fCellDataCounter = new QFrame(frame);
        m_fCellDataCounter->setObjectName(QString::fromUtf8("m_fCellDataCounter"));
        m_fCellDataCounter->setGeometry(QRect(0, 0, 250, 135));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_fCellDataCounter->sizePolicy().hasHeightForWidth());
        m_fCellDataCounter->setSizePolicy(sizePolicy1);
        m_fCellDataCounter->setMinimumSize(QSize(0, 0));
        m_fCellDataCounter->setMaximumSize(QSize(250, 16777215));
        m_fCellDataCounter->setLayoutDirection(Qt::LeftToRight);
        m_fCellDataCounter->setStyleSheet(QString::fromUtf8("border: 2px solid black"));
        m_fCellDataCounter->setFrameShape(QFrame::StyledPanel);
        m_fCellDataCounter->setFrameShadow(QFrame::Raised);
        m_vXCellCount = new QLabel(m_fCellDataCounter);
        m_vXCellCount->setObjectName(QString::fromUtf8("m_vXCellCount"));
        m_vXCellCount->setEnabled(false);
        m_vXCellCount->setGeometry(QRect(11, 30, 51, 17));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(m_vXCellCount->sizePolicy().hasHeightForWidth());
        m_vXCellCount->setSizePolicy(sizePolicy2);
        m_vXCellCount->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"color: rgb(0, 0, 0);"));
        m_vYCell_Count = new QLabel(m_fCellDataCounter);
        m_vYCell_Count->setObjectName(QString::fromUtf8("m_vYCell_Count"));
        m_vYCell_Count->setEnabled(false);
        m_vYCell_Count->setGeometry(QRect(11, 50, 51, 17));
        sizePolicy2.setHeightForWidth(m_vYCell_Count->sizePolicy().hasHeightForWidth());
        m_vYCell_Count->setSizePolicy(sizePolicy2);
        m_vYCell_Count->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"color: rgb(0, 0, 0);"));
        m_labelMultiCellCount = new QLabel(m_fCellDataCounter);
        m_labelMultiCellCount->setObjectName(QString::fromUtf8("m_labelMultiCellCount"));
        m_labelMultiCellCount->setGeometry(QRect(70, 70, 88, 16));
        sizePolicy2.setHeightForWidth(m_labelMultiCellCount->sizePolicy().hasHeightForWidth());
        m_labelMultiCellCount->setSizePolicy(sizePolicy2);
        m_labelMultiCellCount->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"text-decoration: underline;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        m_vMultiCellCount = new QLabel(m_fCellDataCounter);
        m_vMultiCellCount->setObjectName(QString::fromUtf8("m_vMultiCellCount"));
        m_vMultiCellCount->setEnabled(false);
        m_vMultiCellCount->setGeometry(QRect(11, 70, 51, 17));
        sizePolicy2.setHeightForWidth(m_vMultiCellCount->sizePolicy().hasHeightForWidth());
        m_vMultiCellCount->setSizePolicy(sizePolicy2);
        m_vMultiCellCount->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"color: rgb(0, 0, 0);"));
        m_vTotalCount = new QLabel(m_fCellDataCounter);
        m_vTotalCount->setObjectName(QString::fromUtf8("m_vTotalCount"));
        m_vTotalCount->setGeometry(QRect(11, 110, 51, 17));
        sizePolicy2.setHeightForWidth(m_vTotalCount->sizePolicy().hasHeightForWidth());
        m_vTotalCount->setSizePolicy(sizePolicy2);
        m_vTotalCount->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"color: rgb(0, 0, 0);"));
        m_vAlbationFireCount = new QLabel(m_fCellDataCounter);
        m_vAlbationFireCount->setObjectName(QString::fromUtf8("m_vAlbationFireCount"));
        m_vAlbationFireCount->setEnabled(false);
        m_vAlbationFireCount->setGeometry(QRect(11, 90, 51, 17));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(m_vAlbationFireCount->sizePolicy().hasHeightForWidth());
        m_vAlbationFireCount->setSizePolicy(sizePolicy3);
        m_vAlbationFireCount->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"color: rgb(0, 0, 0);"));
        m_labelAlbationFireCount = new QLabel(m_fCellDataCounter);
        m_labelAlbationFireCount->setObjectName(QString::fromUtf8("m_labelAlbationFireCount"));
        m_labelAlbationFireCount->setGeometry(QRect(70, 90, 92, 16));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(m_labelAlbationFireCount->sizePolicy().hasHeightForWidth());
        m_labelAlbationFireCount->setSizePolicy(sizePolicy4);
        m_labelAlbationFireCount->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"text-decoration: underline;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        m_labelYCell_Count = new QLabel(m_fCellDataCounter);
        m_labelYCell_Count->setObjectName(QString::fromUtf8("m_labelYCell_Count"));
        m_labelYCell_Count->setGeometry(QRect(70, 50, 58, 16));
        sizePolicy2.setHeightForWidth(m_labelYCell_Count->sizePolicy().hasHeightForWidth());
        m_labelYCell_Count->setSizePolicy(sizePolicy2);
        m_labelYCell_Count->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"text-decoration: underline;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        m_labelXCellCount = new QLabel(m_fCellDataCounter);
        m_labelXCellCount->setObjectName(QString::fromUtf8("m_labelXCellCount"));
        m_labelXCellCount->setGeometry(QRect(70, 30, 58, 16));
        sizePolicy2.setHeightForWidth(m_labelXCellCount->sizePolicy().hasHeightForWidth());
        m_labelXCellCount->setSizePolicy(sizePolicy2);
        m_labelXCellCount->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"text-decoration: underline;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        m_boxLabelCellData = new QLabel(m_fCellDataCounter);
        m_boxLabelCellData->setObjectName(QString::fromUtf8("m_boxLabelCellData"));
        m_boxLabelCellData->setEnabled(false);
        m_boxLabelCellData->setGeometry(QRect(11, 10, 107, 16));
        sizePolicy2.setHeightForWidth(m_boxLabelCellData->sizePolicy().hasHeightForWidth());
        m_boxLabelCellData->setSizePolicy(sizePolicy2);
        m_boxLabelCellData->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"color: rgb(0, 0, 0);\n"
"text-decoration: underline;\n"
"font: 87 8pt \"Arial Black\";"));
        m_boxLabelCellData->setAlignment(Qt::AlignCenter);
        m_labelTotalCount = new QLabel(m_fCellDataCounter);
        m_labelTotalCount->setObjectName(QString::fromUtf8("m_labelTotalCount"));
        m_labelTotalCount->setGeometry(QRect(70, 110, 76, 16));
        sizePolicy2.setHeightForWidth(m_labelTotalCount->sizePolicy().hasHeightForWidth());
        m_labelTotalCount->setSizePolicy(sizePolicy2);
        m_labelTotalCount->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"text-decoration: underline;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        m_fLASERTriggerParams = new QFrame(frame);
        m_fLASERTriggerParams->setObjectName(QString::fromUtf8("m_fLASERTriggerParams"));
        m_fLASERTriggerParams->setGeometry(QRect(0, 140, 250, 150));
        sizePolicy4.setHeightForWidth(m_fLASERTriggerParams->sizePolicy().hasHeightForWidth());
        m_fLASERTriggerParams->setSizePolicy(sizePolicy4);
        m_fLASERTriggerParams->setMinimumSize(QSize(220, 150));
        m_fLASERTriggerParams->setMaximumSize(QSize(250, 190));
        m_fLASERTriggerParams->setStyleSheet(QString::fromUtf8("border: 2px solid black"));
        m_fLASERTriggerParams->setFrameShape(QFrame::StyledPanel);
        m_fLASERTriggerParams->setFrameShadow(QFrame::Raised);
        m_bLaserSet = new QPushButton(m_fLASERTriggerParams);
        m_bLaserSet->setObjectName(QString::fromUtf8("m_bLaserSet"));
        m_bLaserSet->setGeometry(QRect(11, 119, 50, 17));
        sizePolicy1.setHeightForWidth(m_bLaserSet->sizePolicy().hasHeightForWidth());
        m_bLaserSet->setSizePolicy(sizePolicy1);
        m_bLaserSet->setMinimumSize(QSize(50, 0));
        m_bEnableAblation = new QPushButton(m_fLASERTriggerParams);
        m_bEnableAblation->setObjectName(QString::fromUtf8("m_bEnableAblation"));
        m_bEnableAblation->setGeometry(QRect(180, 119, 50, 17));
        m_labelOnTime = new QLabel(m_fLASERTriggerParams);
        m_labelOnTime->setObjectName(QString::fromUtf8("m_labelOnTime"));
        m_labelOnTime->setEnabled(false);
        m_labelOnTime->setGeometry(QRect(70, 30, 40, 16));
        sizePolicy2.setHeightForWidth(m_labelOnTime->sizePolicy().hasHeightForWidth());
        m_labelOnTime->setSizePolicy(sizePolicy2);
        m_labelOnTime->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"text-decoration: underline;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        m_labelOffTime = new QLabel(m_fLASERTriggerParams);
        m_labelOffTime->setObjectName(QString::fromUtf8("m_labelOffTime"));
        m_labelOffTime->setEnabled(false);
        m_labelOffTime->setGeometry(QRect(70, 50, 45, 16));
        m_labelOffTime->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"text-decoration: underline;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        m_labelTriggerWaitTime = new QLabel(m_fLASERTriggerParams);
        m_labelTriggerWaitTime->setObjectName(QString::fromUtf8("m_labelTriggerWaitTime"));
        m_labelTriggerWaitTime->setEnabled(false);
        m_labelTriggerWaitTime->setGeometry(QRect(70, 70, 84, 16));
        sizePolicy2.setHeightForWidth(m_labelTriggerWaitTime->sizePolicy().hasHeightForWidth());
        m_labelTriggerWaitTime->setSizePolicy(sizePolicy2);
        m_labelTriggerWaitTime->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"text-decoration: underline;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        m_labelNumTriggerPulse = new QLabel(m_fLASERTriggerParams);
        m_labelNumTriggerPulse->setObjectName(QString::fromUtf8("m_labelNumTriggerPulse"));
        m_labelNumTriggerPulse->setEnabled(false);
        m_labelNumTriggerPulse->setGeometry(QRect(70, 90, 83, 16));
        m_labelNumTriggerPulse->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"text-decoration: underline;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        m_labelBoxLaserTriggerParam = new QLabel(m_fLASERTriggerParams);
        m_labelBoxLaserTriggerParam->setObjectName(QString::fromUtf8("m_labelBoxLaserTriggerParam"));
        m_labelBoxLaserTriggerParam->setEnabled(false);
        m_labelBoxLaserTriggerParam->setGeometry(QRect(10, 10, 154, 16));
        sizePolicy1.setHeightForWidth(m_labelBoxLaserTriggerParam->sizePolicy().hasHeightForWidth());
        m_labelBoxLaserTriggerParam->setSizePolicy(sizePolicy1);
        m_labelBoxLaserTriggerParam->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"color: rgb(0, 0, 0);\n"
"text-decoration: underline;\n"
"font: 87 8pt \"Arial Black\";"));
        m_vOnTime = new QTextEdit(m_fLASERTriggerParams);
        m_vOnTime->setObjectName(QString::fromUtf8("m_vOnTime"));
        m_vOnTime->setGeometry(QRect(11, 30, 51, 17));
        sizePolicy3.setHeightForWidth(m_vOnTime->sizePolicy().hasHeightForWidth());
        m_vOnTime->setSizePolicy(sizePolicy3);
        m_vOnTime->setLayoutDirection(Qt::LeftToRight);
        m_vOnTime->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        m_vOnTime->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        m_vOffTime = new QTextEdit(m_fLASERTriggerParams);
        m_vOffTime->setObjectName(QString::fromUtf8("m_vOffTime"));
        m_vOffTime->setGeometry(QRect(11, 50, 51, 17));
        sizePolicy3.setHeightForWidth(m_vOffTime->sizePolicy().hasHeightForWidth());
        m_vOffTime->setSizePolicy(sizePolicy3);
        m_vOffTime->setLayoutDirection(Qt::LeftToRight);
        m_vOffTime->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        m_vOffTime->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        m_vTriggerWaitTime = new QTextEdit(m_fLASERTriggerParams);
        m_vTriggerWaitTime->setObjectName(QString::fromUtf8("m_vTriggerWaitTime"));
        m_vTriggerWaitTime->setGeometry(QRect(11, 70, 51, 17));
        sizePolicy3.setHeightForWidth(m_vTriggerWaitTime->sizePolicy().hasHeightForWidth());
        m_vTriggerWaitTime->setSizePolicy(sizePolicy3);
        m_vTriggerWaitTime->setLayoutDirection(Qt::LeftToRight);
        m_vTriggerWaitTime->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        m_vTriggerWaitTime->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        m_vNumTriggerPulse = new QTextEdit(m_fLASERTriggerParams);
        m_vNumTriggerPulse->setObjectName(QString::fromUtf8("m_vNumTriggerPulse"));
        m_vNumTriggerPulse->setGeometry(QRect(11, 90, 51, 17));
        sizePolicy3.setHeightForWidth(m_vNumTriggerPulse->sizePolicy().hasHeightForWidth());
        m_vNumTriggerPulse->setSizePolicy(sizePolicy3);
        m_vNumTriggerPulse->setLayoutDirection(Qt::LeftToRight);
        m_vNumTriggerPulse->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        m_vNumTriggerPulse->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 300, 251, 221));
        frame_2->setStyleSheet(QString::fromUtf8("border: 2px solid black"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        m_labelUTThreshold = new QLabel(frame_2);
        m_labelUTThreshold->setObjectName(QString::fromUtf8("m_labelUTThreshold"));
        m_labelUTThreshold->setGeometry(QRect(70, 30, 141, 16));
        m_labelUTThreshold->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"text-decoration: underline;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        m_labelLTThreshold = new QLabel(frame_2);
        m_labelLTThreshold->setObjectName(QString::fromUtf8("m_labelLTThreshold"));
        m_labelLTThreshold->setGeometry(QRect(70, 50, 141, 16));
        m_labelLTThreshold->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"text-decoration: underline;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        m_labelUPIThreshold = new QLabel(frame_2);
        m_labelUPIThreshold->setObjectName(QString::fromUtf8("m_labelUPIThreshold"));
        m_labelUPIThreshold->setGeometry(QRect(70, 90, 151, 20));
        m_labelUPIThreshold->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"text-decoration: underline;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        m_labelLPIThreshold = new QLabel(frame_2);
        m_labelLPIThreshold->setObjectName(QString::fromUtf8("m_labelLPIThreshold"));
        m_labelLPIThreshold->setGeometry(QRect(70, 110, 151, 20));
        m_labelLPIThreshold->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"text-decoration: underline;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        m_bUTIOn = new QPushButton(frame_2);
        m_bUTIOn->setObjectName(QString::fromUtf8("m_bUTIOn"));
        m_bUTIOn->setGeometry(QRect(180, 70, 50, 17));
        m_bUPIOn = new QPushButton(frame_2);
        m_bUPIOn->setObjectName(QString::fromUtf8("m_bUPIOn"));
        m_bUPIOn->setGeometry(QRect(180, 130, 50, 17));
        m_labelSomTTThreshold = new QLabel(frame_2);
        m_labelSomTTThreshold->setObjectName(QString::fromUtf8("m_labelSomTTThreshold"));
        m_labelSomTTThreshold->setGeometry(QRect(70, 150, 151, 31));
        m_labelSomTTThreshold->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"text-decoration: underline;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        m_labelSomTTThreshold->setWordWrap(true);
        m_bSumOfIntTTOn = new QPushButton(frame_2);
        m_bSumOfIntTTOn->setObjectName(QString::fromUtf8("m_bSumOfIntTTOn"));
        m_bSumOfIntTTOn->setGeometry(QRect(180, 190, 50, 17));
        m_labelBoxLaserTriggerParam_2 = new QLabel(frame_2);
        m_labelBoxLaserTriggerParam_2->setObjectName(QString::fromUtf8("m_labelBoxLaserTriggerParam_2"));
        m_labelBoxLaserTriggerParam_2->setEnabled(false);
        m_labelBoxLaserTriggerParam_2->setGeometry(QRect(10, 10, 111, 16));
        sizePolicy3.setHeightForWidth(m_labelBoxLaserTriggerParam_2->sizePolicy().hasHeightForWidth());
        m_labelBoxLaserTriggerParam_2->setSizePolicy(sizePolicy3);
        m_labelBoxLaserTriggerParam_2->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"color: rgb(0, 0, 0);\n"
"text-decoration: underline;\n"
"font: 87 8pt \"Arial Black\";"));
        m_vUTThreshold = new QTextEdit(frame_2);
        m_vUTThreshold->setObjectName(QString::fromUtf8("m_vUTThreshold"));
        m_vUTThreshold->setGeometry(QRect(10, 30, 51, 17));
        sizePolicy3.setHeightForWidth(m_vUTThreshold->sizePolicy().hasHeightForWidth());
        m_vUTThreshold->setSizePolicy(sizePolicy3);
        m_vUTThreshold->setLayoutDirection(Qt::LeftToRight);
        m_vUTThreshold->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        m_vUTThreshold->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        m_vLTThreshold = new QTextEdit(frame_2);
        m_vLTThreshold->setObjectName(QString::fromUtf8("m_vLTThreshold"));
        m_vLTThreshold->setGeometry(QRect(10, 50, 51, 17));
        sizePolicy3.setHeightForWidth(m_vLTThreshold->sizePolicy().hasHeightForWidth());
        m_vLTThreshold->setSizePolicy(sizePolicy3);
        m_vLTThreshold->setLayoutDirection(Qt::LeftToRight);
        m_vLTThreshold->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        m_vLTThreshold->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        m_vUPIThreshold = new QTextEdit(frame_2);
        m_vUPIThreshold->setObjectName(QString::fromUtf8("m_vUPIThreshold"));
        m_vUPIThreshold->setGeometry(QRect(10, 90, 51, 17));
        sizePolicy3.setHeightForWidth(m_vUPIThreshold->sizePolicy().hasHeightForWidth());
        m_vUPIThreshold->setSizePolicy(sizePolicy3);
        m_vUPIThreshold->setLayoutDirection(Qt::LeftToRight);
        m_vUPIThreshold->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        m_vUPIThreshold->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        m_vLPIThreshold = new QTextEdit(frame_2);
        m_vLPIThreshold->setObjectName(QString::fromUtf8("m_vLPIThreshold"));
        m_vLPIThreshold->setGeometry(QRect(10, 110, 51, 17));
        sizePolicy3.setHeightForWidth(m_vLPIThreshold->sizePolicy().hasHeightForWidth());
        m_vLPIThreshold->setSizePolicy(sizePolicy3);
        m_vLPIThreshold->setLayoutDirection(Qt::LeftToRight);
        m_vLPIThreshold->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        m_vLPIThreshold->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        m_vSomTTThreshold = new QTextEdit(frame_2);
        m_vSomTTThreshold->setObjectName(QString::fromUtf8("m_vSomTTThreshold"));
        m_vSomTTThreshold->setGeometry(QRect(10, 160, 51, 17));
        sizePolicy3.setHeightForWidth(m_vSomTTThreshold->sizePolicy().hasHeightForWidth());
        m_vSomTTThreshold->setSizePolicy(sizePolicy3);
        m_vSomTTThreshold->setLayoutDirection(Qt::LeftToRight);
        m_vSomTTThreshold->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        m_vSomTTThreshold->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        m_bUTISet = new QPushButton(frame_2);
        m_bUTISet->setObjectName(QString::fromUtf8("m_bUTISet"));
        m_bUTISet->setGeometry(QRect(120, 70, 50, 17));
        m_bUPISet = new QPushButton(frame_2);
        m_bUPISet->setObjectName(QString::fromUtf8("m_bUPISet"));
        m_bUPISet->setGeometry(QRect(120, 130, 50, 17));
        m_bSumOfIntTTSet = new QPushButton(frame_2);
        m_bSumOfIntTTSet->setObjectName(QString::fromUtf8("m_bSumOfIntTTSet"));
        m_bSumOfIntTTSet->setGeometry(QRect(120, 190, 50, 17));
        frame_2->raise();
        m_fCellDataCounter->raise();
        m_fLASERTriggerParams->raise();

        gridLayout->addWidget(frame, 0, 0, 5, 1);

        TT_window = new QScrollArea(histograms);
        TT_window->setObjectName(QString::fromUtf8("TT_window"));
        TT_window->setStyleSheet(QString::fromUtf8("border: 0px solid black"));
        TT_window->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 820, 497));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(scrollAreaWidgetContents_4->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_4->setSizePolicy(sizePolicy5);
        gridLayout_5 = new QGridLayout(scrollAreaWidgetContents_4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        tt_histo = new QCustomPlot(scrollAreaWidgetContents_4);
        tt_histo->setObjectName(QString::fromUtf8("tt_histo"));
        sizePolicy5.setHeightForWidth(tt_histo->sizePolicy().hasHeightForWidth());
        tt_histo->setSizePolicy(sizePolicy5);
        tt_histo->setStyleSheet(QString::fromUtf8("border: 0.5px solid black;"));
        tt_Median = new QLineEdit(tt_histo);
        tt_Median->setObjectName(QString::fromUtf8("tt_Median"));
        tt_Median->setGeometry(QRect(75, 15, 91, 16));
        tt_Median->setStyleSheet(QString::fromUtf8("border: 0.0px solid black;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"background-color: rgba(0, 0, 0, 20);\n"
"color: rgb(0, 0, 0);\n"
"\n"
""));
        tt_Dev = new QLineEdit(tt_histo);
        tt_Dev->setObjectName(QString::fromUtf8("tt_Dev"));
        tt_Dev->setGeometry(QRect(75, 30, 91, 16));
        tt_Dev->setStyleSheet(QString::fromUtf8("border: 0.0px solid black;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"background-color: rgba(0, 0, 0, 20);\n"
"color: rgb(0, 0, 0);\n"
"\n"
""));

        gridLayout_5->addWidget(tt_histo, 0, 0, 1, 1);

        TT_window->setWidget(scrollAreaWidgetContents_4);

        gridLayout->addWidget(TT_window, 3, 2, 1, 1);

        area_window = new QScrollArea(histograms);
        area_window->setObjectName(QString::fromUtf8("area_window"));
        area_window->setEnabled(true);
        area_window->setMinimumSize(QSize(51, 0));
        area_window->setStyleSheet(QString::fromUtf8("border: 0px solid black"));
        area_window->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 820, 498));
        sizePolicy5.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy5);
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        area_histo = new QCustomPlot(scrollAreaWidgetContents);
        area_histo->setObjectName(QString::fromUtf8("area_histo"));
        sizePolicy5.setHeightForWidth(area_histo->sizePolicy().hasHeightForWidth());
        area_histo->setSizePolicy(sizePolicy5);
        area_histo->setStyleSheet(QString::fromUtf8("border: 0.5px solid black;"));
        area_Median = new QLineEdit(area_histo);
        area_Median->setObjectName(QString::fromUtf8("area_Median"));
        area_Median->setEnabled(false);
        area_Median->setGeometry(QRect(75, 15, 91, 16));
        sizePolicy4.setHeightForWidth(area_Median->sizePolicy().hasHeightForWidth());
        area_Median->setSizePolicy(sizePolicy4);
        area_Median->setStyleSheet(QString::fromUtf8("border: 0.0px solid black;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"background-color: rgba(0, 0, 0, 20);\n"
"color: rgb(0, 0, 0);\n"
""));
        area_Dev = new QLineEdit(area_histo);
        area_Dev->setObjectName(QString::fromUtf8("area_Dev"));
        area_Dev->setEnabled(false);
        area_Dev->setGeometry(QRect(75, 30, 91, 16));
        sizePolicy4.setHeightForWidth(area_Dev->sizePolicy().hasHeightForWidth());
        area_Dev->setSizePolicy(sizePolicy4);
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(8);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        area_Dev->setFont(font);
        area_Dev->setContextMenuPolicy(Qt::ActionsContextMenu);
        area_Dev->setStyleSheet(QString::fromUtf8("border: 0.0px solid black;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"background-color: rgba(0, 0, 0, 20);\n"
"color: rgb(0, 0, 0);\n"
"\n"
""));

        gridLayout_2->addWidget(area_histo, 0, 0, 1, 1);

        area_window->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(area_window, 2, 1, 1, 1);

        peak_window = new QScrollArea(histograms);
        peak_window->setObjectName(QString::fromUtf8("peak_window"));
        peak_window->setStyleSheet(QString::fromUtf8("border: 0px solid black"));
        peak_window->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 820, 498));
        sizePolicy5.setHeightForWidth(scrollAreaWidgetContents_2->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_2->setSizePolicy(sizePolicy5);
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        peak_histo = new QCustomPlot(scrollAreaWidgetContents_2);
        peak_histo->setObjectName(QString::fromUtf8("peak_histo"));
        sizePolicy5.setHeightForWidth(peak_histo->sizePolicy().hasHeightForWidth());
        peak_histo->setSizePolicy(sizePolicy5);
        QFont font1;
        font1.setStyleStrategy(QFont::NoAntialias);
        peak_histo->setFont(font1);
        peak_histo->setStyleSheet(QString::fromUtf8("border: 0.5px solid black;"));
        peak_Median = new QLineEdit(peak_histo);
        peak_Median->setObjectName(QString::fromUtf8("peak_Median"));
        peak_Median->setGeometry(QRect(75, 15, 91, 16));
        peak_Median->setStyleSheet(QString::fromUtf8("border: 0.0px solid black;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"background-color: rgba(0, 0, 0, 20);\n"
"color: rgb(0, 0, 0);\n"
""));
        peak_Dev = new QLineEdit(peak_histo);
        peak_Dev->setObjectName(QString::fromUtf8("peak_Dev"));
        peak_Dev->setGeometry(QRect(75, 30, 91, 16));
        peak_Dev->setStyleSheet(QString::fromUtf8("border: 0.0px solid black;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"background-color: rgba(0, 0, 0, 20);\n"
"color: rgb(0, 0, 0);\n"
"\n"
""));

        gridLayout_3->addWidget(peak_histo, 0, 0, 1, 1);

        peak_window->setWidget(scrollAreaWidgetContents_2);

        gridLayout->addWidget(peak_window, 2, 2, 1, 1);

        m_histoSettings = new QWidget(histograms);
        m_histoSettings->setObjectName(QString::fromUtf8("m_histoSettings"));
        sizePolicy1.setHeightForWidth(m_histoSettings->sizePolicy().hasHeightForWidth());
        m_histoSettings->setSizePolicy(sizePolicy1);
        m_histoSettings->setMinimumSize(QSize(820, 55));
        m_histoSettings->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);\n"
"border: 2px solid black\n"
"\n"
""));
        m_bGetInstADCVal = new QPushButton(m_histoSettings);
        m_bGetInstADCVal->setObjectName(QString::fromUtf8("m_bGetInstADCVal"));
        m_bGetInstADCVal->setGeometry(QRect(66, 10, 31, 17));
        sizePolicy1.setHeightForWidth(m_bGetInstADCVal->sizePolicy().hasHeightForWidth());
        m_bGetInstADCVal->setSizePolicy(sizePolicy1);
        m_bGetInstADCVal->setStyleSheet(QString::fromUtf8("background-color: rgb(143, 143, 143);"));
        m_bSetEventThr = new QPushButton(m_histoSettings);
        m_bSetEventThr->setObjectName(QString::fromUtf8("m_bSetEventThr"));
        m_bSetEventThr->setGeometry(QRect(66, 30, 31, 17));
        sizePolicy1.setHeightForWidth(m_bSetEventThr->sizePolicy().hasHeightForWidth());
        m_bSetEventThr->setSizePolicy(sizePolicy1);
        m_bSetEventThr->setStyleSheet(QString::fromUtf8("background-color: rgb(143, 143, 143);"));
        m_vEventElapsed = new QLabel(m_histoSettings);
        m_vEventElapsed->setObjectName(QString::fromUtf8("m_vEventElapsed"));
        m_vEventElapsed->setEnabled(false);
        m_vEventElapsed->setGeometry(QRect(230, 10, 51, 17));
        sizePolicy.setHeightForWidth(m_vEventElapsed->sizePolicy().hasHeightForWidth());
        m_vEventElapsed->setSizePolicy(sizePolicy);
        m_vEventElapsed->setMinimumSize(QSize(51, 0));
        m_vEventElapsed->setLayoutDirection(Qt::RightToLeft);
        m_vEventElapsed->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        m_bRstCounter = new QPushButton(m_histoSettings);
        m_bRstCounter->setObjectName(QString::fromUtf8("m_bRstCounter"));
        m_bRstCounter->setGeometry(QRect(420, 30, 40, 17));
        sizePolicy1.setHeightForWidth(m_bRstCounter->sizePolicy().hasHeightForWidth());
        m_bRstCounter->setSizePolicy(sizePolicy1);
        m_bRstCounter->setMinimumSize(QSize(40, 0));
        m_cbTextFileSave = new QCheckBox(m_histoSettings);
        m_cbTextFileSave->setObjectName(QString::fromUtf8("m_cbTextFileSave"));
        m_cbTextFileSave->setGeometry(QRect(710, 10, 87, 16));
        m_cbTextFileSave->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"text-decoration: underline;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        m_cbStartCounter = new QCheckBox(m_histoSettings);
        m_cbStartCounter->setObjectName(QString::fromUtf8("m_cbStartCounter"));
        m_cbStartCounter->setGeometry(QRect(400, 30, 16, 16));
        m_cbStartCounter->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"text-decoration: underline;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        m_labelInstADCval = new QLabel(m_histoSettings);
        m_labelInstADCval->setObjectName(QString::fromUtf8("m_labelInstADCval"));
        m_labelInstADCval->setEnabled(false);
        m_labelInstADCval->setGeometry(QRect(100, 10, 107, 16));
        m_labelInstADCval->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"text-decoration: underline;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        m_labelEventThr = new QLabel(m_histoSettings);
        m_labelEventThr->setObjectName(QString::fromUtf8("m_labelEventThr"));
        m_labelEventThr->setEnabled(false);
        m_labelEventThr->setGeometry(QRect(100, 30, 78, 16));
        m_labelEventThr->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"text-decoration: underline;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        m_labelEventThr->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        m_labelEventElapse = new QLabel(m_histoSettings);
        m_labelEventElapse->setObjectName(QString::fromUtf8("m_labelEventElapse"));
        m_labelEventElapse->setEnabled(false);
        m_labelEventElapse->setGeometry(QRect(290, 10, 68, 16));
        m_labelEventElapse->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"text-decoration: underline;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        m_labelEventElapse->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        m_labelUpFreq = new QLabel(m_histoSettings);
        m_labelUpFreq->setObjectName(QString::fromUtf8("m_labelUpFreq"));
        m_labelUpFreq->setEnabled(false);
        m_labelUpFreq->setGeometry(QRect(290, 30, 63, 16));
        m_labelUpFreq->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"text-decoration: underline;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        m_labelUpFreq->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        m_labelRstCounter = new QLabel(m_histoSettings);
        m_labelRstCounter->setObjectName(QString::fromUtf8("m_labelRstCounter"));
        m_labelRstCounter->setGeometry(QRect(470, 30, 70, 16));
        m_labelRstCounter->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"text-decoration: underline;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        m_labelRstCounter->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        m_bEnableHisto = new QPushButton(m_histoSettings);
        m_bEnableHisto->setObjectName(QString::fromUtf8("m_bEnableHisto"));
        m_bEnableHisto->setGeometry(QRect(400, 10, 59, 17));
        sizePolicy1.setHeightForWidth(m_bEnableHisto->sizePolicy().hasHeightForWidth());
        m_bEnableHisto->setSizePolicy(sizePolicy1);
        m_bEnableHisto->setMinimumSize(QSize(51, 0));
        m_labelEnableHisto = new QLabel(m_histoSettings);
        m_labelEnableHisto->setObjectName(QString::fromUtf8("m_labelEnableHisto"));
        m_labelEnableHisto->setGeometry(QRect(470, 10, 83, 16));
        m_labelEnableHisto->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"text-decoration: underline;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        m_labelEnableHisto->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        m_vInstADCVal = new QTextEdit(m_histoSettings);
        m_vInstADCVal->setObjectName(QString::fromUtf8("m_vInstADCVal"));
        m_vInstADCVal->setEnabled(true);
        m_vInstADCVal->setGeometry(QRect(10, 10, 51, 17));
        sizePolicy3.setHeightForWidth(m_vInstADCVal->sizePolicy().hasHeightForWidth());
        m_vInstADCVal->setSizePolicy(sizePolicy3);
        m_vInstADCVal->setLayoutDirection(Qt::LeftToRight);
        m_vInstADCVal->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        m_vInstADCVal->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        m_vInstADCVal->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        m_vEvtThrs = new QTextEdit(m_histoSettings);
        m_vEvtThrs->setObjectName(QString::fromUtf8("m_vEvtThrs"));
        m_vEvtThrs->setGeometry(QRect(10, 30, 51, 17));
        sizePolicy3.setHeightForWidth(m_vEvtThrs->sizePolicy().hasHeightForWidth());
        m_vEvtThrs->setSizePolicy(sizePolicy3);
        m_vEvtThrs->setLayoutDirection(Qt::LeftToRight);
        m_vEvtThrs->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        m_vEvtThrs->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        m_vEvtThrs->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        m_vUpdateFreq = new QSpinBox(m_histoSettings);
        m_vUpdateFreq->setObjectName(QString::fromUtf8("m_vUpdateFreq"));
        m_vUpdateFreq->setGeometry(QRect(230, 30, 51, 17));
        m_vUpdateFreq->setButtonSymbols(QAbstractSpinBox::NoButtons);
        m_vUpdateFreq->setMinimum(25);
        m_vUpdateFreq->setMaximum(10000000);
        m_channel_1 = new QRadioButton(m_histoSettings);
        m_channel_1->setObjectName(QString::fromUtf8("m_channel_1"));
        m_channel_1->setGeometry(QRect(580, 10, 82, 17));
        m_channel_1->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"text-decoration: underline;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        m_channel_1->setChecked(true);
        m_channel_2 = new QRadioButton(m_histoSettings);
        m_channel_2->setObjectName(QString::fromUtf8("m_channel_2"));
        m_channel_2->setGeometry(QRect(580, 30, 82, 17));
        m_channel_2->setStyleSheet(QString::fromUtf8("border: 0px solid black;\n"
"text-decoration: underline;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(m_histoSettings, 0, 1, 1, 2);

        intencity_window = new QScrollArea(histograms);
        intencity_window->setObjectName(QString::fromUtf8("intencity_window"));
        intencity_window->setStyleSheet(QString::fromUtf8("border: 0px solid black"));
        intencity_window->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 820, 497));
        sizePolicy5.setHeightForWidth(scrollAreaWidgetContents_3->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_3->setSizePolicy(sizePolicy5);
        gridLayout_4 = new QGridLayout(scrollAreaWidgetContents_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        intensity_histo = new QCustomPlot(scrollAreaWidgetContents_3);
        intensity_histo->setObjectName(QString::fromUtf8("intensity_histo"));
        sizePolicy5.setHeightForWidth(intensity_histo->sizePolicy().hasHeightForWidth());
        intensity_histo->setSizePolicy(sizePolicy5);
        intensity_histo->setLayoutDirection(Qt::LeftToRight);
        intensity_histo->setStyleSheet(QString::fromUtf8("border: 0.5px solid black;"));
        intensity_Dev = new QLineEdit(intensity_histo);
        intensity_Dev->setObjectName(QString::fromUtf8("intensity_Dev"));
        intensity_Dev->setEnabled(false);
        intensity_Dev->setGeometry(QRect(75, 15, 91, 16));
        sizePolicy1.setHeightForWidth(intensity_Dev->sizePolicy().hasHeightForWidth());
        intensity_Dev->setSizePolicy(sizePolicy1);
        intensity_Dev->setStyleSheet(QString::fromUtf8("border: 0.0px solid black;\n"
"background-color: rgba(0, 0, 0, 20);\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        intensity_Dev->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        intensity_Median = new QLineEdit(intensity_histo);
        intensity_Median->setObjectName(QString::fromUtf8("intensity_Median"));
        intensity_Median->setEnabled(false);
        intensity_Median->setGeometry(QRect(75, 30, 91, 16));
        sizePolicy1.setHeightForWidth(intensity_Median->sizePolicy().hasHeightForWidth());
        intensity_Median->setSizePolicy(sizePolicy1);
        intensity_Median->setStyleSheet(QString::fromUtf8("border: 0.0px solid black;\n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"background-color: rgba(0, 0, 0, 20);\n"
"color: rgb(0, 0, 0);\n"
""));

        gridLayout_4->addWidget(intensity_histo, 0, 0, 1, 1);

        intencity_window->setWidget(scrollAreaWidgetContents_3);

        gridLayout->addWidget(intencity_window, 3, 1, 1, 1);

        m_histoSettings->raise();
        frame->raise();
        area_window->raise();
        peak_window->raise();
        TT_window->raise();
        intencity_window->raise();

        retranslateUi(histograms);

        QMetaObject::connectSlotsByName(histograms);
    } // setupUi

    void retranslateUi(QWidget *histograms)
    {
        histograms->setWindowTitle(QApplication::translate("histograms", "Form", nullptr));
        m_vXCellCount->setText(QApplication::translate("histograms", "0", nullptr));
        m_vYCell_Count->setText(QApplication::translate("histograms", "0", nullptr));
        m_labelMultiCellCount->setText(QApplication::translate("histograms", "Multiple Cell Count", nullptr));
        m_vMultiCellCount->setText(QApplication::translate("histograms", "0", nullptr));
        m_vTotalCount->setText(QApplication::translate("histograms", "0", nullptr));
        m_vAlbationFireCount->setText(QApplication::translate("histograms", "0", nullptr));
        m_labelAlbationFireCount->setText(QApplication::translate("histograms", "Albation Fire Count", nullptr));
        m_labelYCell_Count->setText(QApplication::translate("histograms", "Y Cell Count", nullptr));
        m_labelXCellCount->setText(QApplication::translate("histograms", "X Cell Count", nullptr));
        m_boxLabelCellData->setText(QApplication::translate("histograms", "Cell Data Counter", nullptr));
        m_labelTotalCount->setText(QApplication::translate("histograms", "Total Cell Count", nullptr));
        m_bLaserSet->setText(QApplication::translate("histograms", "Set", nullptr));
        m_bEnableAblation->setText(QApplication::translate("histograms", "OFF", nullptr));
        m_labelOnTime->setText(QApplication::translate("histograms", "ON Time", nullptr));
        m_labelOffTime->setText(QApplication::translate("histograms", "OFF Time", nullptr));
        m_labelTriggerWaitTime->setText(QApplication::translate("histograms", "Trigger Wait Time", nullptr));
        m_labelNumTriggerPulse->setText(QApplication::translate("histograms", "Num of Trig Pulse", nullptr));
        m_labelBoxLaserTriggerParam->setText(QApplication::translate("histograms", "LASER Trigger Parameter", nullptr));
        m_vOnTime->setHtml(QApplication::translate("histograms", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", nullptr));
        m_vOffTime->setHtml(QApplication::translate("histograms", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", nullptr));
        m_vTriggerWaitTime->setHtml(QApplication::translate("histograms", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", nullptr));
        m_vNumTriggerPulse->setHtml(QApplication::translate("histograms", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", nullptr));
        m_labelUTThreshold->setText(QApplication::translate("histograms", "Upper Transit Time Threshold", nullptr));
        m_labelLTThreshold->setText(QApplication::translate("histograms", "Lower Transit Time Threshold", nullptr));
        m_labelUPIThreshold->setText(QApplication::translate("histograms", "Upper Peak Intensity Threshold", nullptr));
        m_labelLPIThreshold->setText(QApplication::translate("histograms", "Lower Peak Intensity Threshold", nullptr));
        m_bUTIOn->setText(QApplication::translate("histograms", "OFF", nullptr));
        m_bUPIOn->setText(QApplication::translate("histograms", "OFF", nullptr));
        m_labelSomTTThreshold->setText(QApplication::translate("histograms", "Sum of Intensities / Transit Time Threshold", nullptr));
        m_bSumOfIntTTOn->setText(QApplication::translate("histograms", "OFF", nullptr));
        m_labelBoxLaserTriggerParam_2->setText(QApplication::translate("histograms", "Filter Parameter", nullptr));
        m_vUTThreshold->setHtml(QApplication::translate("histograms", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", nullptr));
        m_vLTThreshold->setHtml(QApplication::translate("histograms", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", nullptr));
        m_vUPIThreshold->setHtml(QApplication::translate("histograms", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", nullptr));
        m_vLPIThreshold->setHtml(QApplication::translate("histograms", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", nullptr));
        m_vSomTTThreshold->setHtml(QApplication::translate("histograms", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", nullptr));
        m_bUTISet->setText(QApplication::translate("histograms", "Set", nullptr));
        m_bUPISet->setText(QApplication::translate("histograms", "Set", nullptr));
        m_bSumOfIntTTSet->setText(QApplication::translate("histograms", "Set", nullptr));
        tt_Median->setText(QApplication::translate("histograms", "M:0", nullptr));
        tt_Dev->setText(QApplication::translate("histograms", "D:0", nullptr));
        area_Median->setText(QApplication::translate("histograms", "M:0", nullptr));
        area_Dev->setText(QApplication::translate("histograms", "D:0", nullptr));
        peak_Median->setText(QApplication::translate("histograms", "M:0", nullptr));
        peak_Dev->setText(QApplication::translate("histograms", "D:0", nullptr));
        m_bGetInstADCVal->setText(QApplication::translate("histograms", "Get", nullptr));
        m_bSetEventThr->setText(QApplication::translate("histograms", "Set", nullptr));
        m_vEventElapsed->setText(QApplication::translate("histograms", "0", nullptr));
        m_bRstCounter->setText(QApplication::translate("histograms", "rst", nullptr));
        m_cbTextFileSave->setText(QApplication::translate("histograms", "Text File Save", nullptr));
        m_cbStartCounter->setText(QString());
        m_labelInstADCval->setText(QApplication::translate("histograms", "Instaneous ADC Value", nullptr));
        m_labelEventThr->setText(QApplication::translate("histograms", "Event Threshold", nullptr));
        m_labelEventElapse->setText(QApplication::translate("histograms", "Event Elapsed", nullptr));
        m_labelUpFreq->setText(QApplication::translate("histograms", "Update  Freq", nullptr));
        m_labelRstCounter->setText(QApplication::translate("histograms", "Counter", nullptr));
        m_bEnableHisto->setText(QApplication::translate("histograms", "Enable", nullptr));
        m_labelEnableHisto->setText(QApplication::translate("histograms", "Enable Histogram", nullptr));
        m_vInstADCVal->setHtml(QApplication::translate("histograms", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", nullptr));
        m_vEvtThrs->setHtml(QApplication::translate("histograms", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", nullptr));
        m_channel_1->setText(QApplication::translate("histograms", "Channel - 1", nullptr));
        m_channel_2->setText(QApplication::translate("histograms", "Channel - 2", nullptr));
        intensity_Dev->setText(QApplication::translate("histograms", "D:0", nullptr));
        intensity_Median->setText(QApplication::translate("histograms", "M:0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class histograms: public Ui_histograms {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAMS_H
