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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

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
    QScrollArea *scrollArea_4;
    QWidget *scrollAreaWidgetContents_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
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
    QTextEdit *m_vUpdateFreq;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;

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
        m_vTotalCount->setGeometry(QRect(11, 90, 51, 17));
        sizePolicy2.setHeightForWidth(m_vTotalCount->sizePolicy().hasHeightForWidth());
        m_vTotalCount->setSizePolicy(sizePolicy2);
        m_vTotalCount->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"color: rgb(0, 0, 0);"));
        m_vAlbationFireCount = new QLabel(m_fCellDataCounter);
        m_vAlbationFireCount->setObjectName(QString::fromUtf8("m_vAlbationFireCount"));
        m_vAlbationFireCount->setEnabled(false);
        m_vAlbationFireCount->setGeometry(QRect(11, 110, 51, 17));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(m_vAlbationFireCount->sizePolicy().hasHeightForWidth());
        m_vAlbationFireCount->setSizePolicy(sizePolicy3);
        m_vAlbationFireCount->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"color: rgb(0, 0, 0);"));
        m_labelAlbationFireCount = new QLabel(m_fCellDataCounter);
        m_labelAlbationFireCount->setObjectName(QString::fromUtf8("m_labelAlbationFireCount"));
        m_labelAlbationFireCount->setGeometry(QRect(70, 110, 92, 16));
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
        m_labelTotalCount->setGeometry(QRect(70, 90, 76, 16));
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

        gridLayout->addWidget(frame, 0, 0, 5, 1);

        scrollArea_4 = new QScrollArea(histograms);
        scrollArea_4->setObjectName(QString::fromUtf8("scrollArea_4"));
        scrollArea_4->setStyleSheet(QString::fromUtf8("border: 2px solid black"));
        scrollArea_4->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 816, 493));
        scrollArea_4->setWidget(scrollAreaWidgetContents_4);

        gridLayout->addWidget(scrollArea_4, 3, 2, 1, 1);

        scrollArea = new QScrollArea(histograms);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setEnabled(true);
        scrollArea->setMinimumSize(QSize(51, 0));
        scrollArea->setStyleSheet(QString::fromUtf8("border: 2px solid black"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 816, 494));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 2, 1, 1, 1);

        scrollArea_2 = new QScrollArea(histograms);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setStyleSheet(QString::fromUtf8("border: 2px solid black"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 816, 494));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayout->addWidget(scrollArea_2, 2, 2, 1, 1);

        m_histoSettings = new QWidget(histograms);
        m_histoSettings->setObjectName(QString::fromUtf8("m_histoSettings"));
        sizePolicy1.setHeightForWidth(m_histoSettings->sizePolicy().hasHeightForWidth());
        m_histoSettings->setSizePolicy(sizePolicy1);
        m_histoSettings->setMinimumSize(QSize(720, 55));
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
        m_cbTextFileSave->setGeometry(QRect(590, 10, 87, 16));
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
        m_vUpdateFreq = new QTextEdit(m_histoSettings);
        m_vUpdateFreq->setObjectName(QString::fromUtf8("m_vUpdateFreq"));
        m_vUpdateFreq->setGeometry(QRect(230, 30, 51, 17));
        sizePolicy3.setHeightForWidth(m_vUpdateFreq->sizePolicy().hasHeightForWidth());
        m_vUpdateFreq->setSizePolicy(sizePolicy3);
        m_vUpdateFreq->setLayoutDirection(Qt::LeftToRight);
        m_vUpdateFreq->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        m_vUpdateFreq->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        m_vUpdateFreq->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);

        gridLayout->addWidget(m_histoSettings, 0, 1, 1, 2);

        scrollArea_3 = new QScrollArea(histograms);
        scrollArea_3->setObjectName(QString::fromUtf8("scrollArea_3"));
        scrollArea_3->setStyleSheet(QString::fromUtf8("border: 2px solid black"));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 816, 493));
        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        gridLayout->addWidget(scrollArea_3, 3, 1, 1, 1);

        scrollArea->raise();
        scrollArea_2->raise();
        scrollArea_4->raise();
        scrollArea_3->raise();
        m_histoSettings->raise();
        frame->raise();

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
        m_vUpdateFreq->setHtml(QApplication::translate("histograms", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class histograms: public Ui_histograms {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAMS_H
