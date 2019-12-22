/********************************************************************************
** Form generated from reading UI file 'graphs.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHS_H
#define UI_GRAPHS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    QCustomPlot *m_channel_1;
    QCustomPlot *m_channel_2;
    QCustomPlot *m_channel_3;
    QCustomPlot *m_channel_4;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(1920, 1080);
        Form->setStyleSheet(QString::fromUtf8("background-color: rgb(143, 143, 143);"));
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_channel_1 = new QCustomPlot(Form);
        m_channel_1->setObjectName(QString::fromUtf8("m_channel_1"));
        m_channel_1->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        gridLayout->addWidget(m_channel_1, 0, 0, 1, 1);

        m_channel_2 = new QCustomPlot(Form);
        m_channel_2->setObjectName(QString::fromUtf8("m_channel_2"));
        m_channel_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        gridLayout->addWidget(m_channel_2, 1, 0, 1, 1);

        m_channel_3 = new QCustomPlot(Form);
        m_channel_3->setObjectName(QString::fromUtf8("m_channel_3"));
        m_channel_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        gridLayout->addWidget(m_channel_3, 2, 0, 1, 1);

        m_channel_4 = new QCustomPlot(Form);
        m_channel_4->setObjectName(QString::fromUtf8("m_channel_4"));
        m_channel_4->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        gridLayout->addWidget(m_channel_4, 3, 0, 1, 1);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHS_H
