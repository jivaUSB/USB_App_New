/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QFrame *Menu;
    QGraphicsView *m_logo;
    QPushButton *m_bDataAcq;
    QGraphicsView *On_off_buttons;
    QLabel *Data_acq_txt;
    QLabel *Data_anay_txt;
    QPushButton *m_bDataAna;
    QPushButton *m_bDataAcqPlay;
    QLabel *Acq_play_txt;
    QPushButton *m_bCurDisplay;
    QLabel *label_9;
    QWidget *widget_LED_Setting;
    QPushButton *m_USB_Link_Led;
    QPushButton *m_Uart_Link_LED;
    QLineEdit *USB_link_txt;
    QLineEdit *m_UART_link_txt;
    QPushButton *m_bSettings;
    QLabel *Settings_txt;
    QScrollArea *console_scroll_area;
    QWidget *scrollAreaWidgetContents;
    QTextEdit *console;
    QStackedWidget *m_stacked;
    QWidget *page;
    QWidget *page_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1920, 1080);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(715, 463));
        QIcon icon;
        icon.addFile(QString::fromUtf8("Images/jivalog_10per.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setWindowOpacity(60.000000000000000);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(143, 143, 143);"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Menu = new QFrame(centralWidget);
        Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Menu->sizePolicy().hasHeightForWidth());
        Menu->setSizePolicy(sizePolicy2);
        Menu->setMinimumSize(QSize(0, 130));
        Menu->setStyleSheet(QString::fromUtf8("border: 1px solid black; "));
        Menu->setFrameShape(QFrame::StyledPanel);
        Menu->setFrameShadow(QFrame::Raised);
        m_logo = new QGraphicsView(Menu);
        m_logo->setObjectName(QString::fromUtf8("m_logo"));
        m_logo->setGeometry(QRect(0, 0, 121, 130));
        m_logo->setStyleSheet(QString::fromUtf8("image: url(:/Images/Jivalog.png);\n"
"background-image: url(:/Images/logo.png);\n"
"\n"
""));
        m_bDataAcq = new QPushButton(Menu);
        m_bDataAcq->setObjectName(QString::fromUtf8("m_bDataAcq"));
        m_bDataAcq->setGeometry(QRect(135, 25, 110, 35));
        m_bDataAcq->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-image: url(:/Images/OFF.png);\n"
"\n"
"\n"
""));
        On_off_buttons = new QGraphicsView(Menu);
        On_off_buttons->setObjectName(QString::fromUtf8("On_off_buttons"));
        On_off_buttons->setGeometry(QRect(120, 0, 291, 130));
        Data_acq_txt = new QLabel(Menu);
        Data_acq_txt->setObjectName(QString::fromUtf8("Data_acq_txt"));
        Data_acq_txt->setGeometry(QRect(135, 5, 101, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        Data_acq_txt->setFont(font);
        Data_acq_txt->setStyleSheet(QString::fromUtf8("border: 0px solid black; "));
        Data_anay_txt = new QLabel(Menu);
        Data_anay_txt->setObjectName(QString::fromUtf8("Data_anay_txt"));
        Data_anay_txt->setGeometry(QRect(135, 65, 101, 20));
        Data_anay_txt->setFont(font);
        Data_anay_txt->setStyleSheet(QString::fromUtf8("border: 0px solid black; "));
        m_bDataAna = new QPushButton(Menu);
        m_bDataAna->setObjectName(QString::fromUtf8("m_bDataAna"));
        m_bDataAna->setGeometry(QRect(135, 85, 110, 35));
        m_bDataAna->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-image: url(:/Images/OFF.png);\n"
"\n"
"\n"
""));
        m_bDataAcqPlay = new QPushButton(Menu);
        m_bDataAcqPlay->setObjectName(QString::fromUtf8("m_bDataAcqPlay"));
        m_bDataAcqPlay->setGeometry(QRect(285, 25, 110, 35));
        m_bDataAcqPlay->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-image: url(:/Images/Play.png);\n"
"\n"
"\n"
"\n"
"\n"
""));
        Acq_play_txt = new QLabel(Menu);
        Acq_play_txt->setObjectName(QString::fromUtf8("Acq_play_txt"));
        Acq_play_txt->setGeometry(QRect(280, 5, 101, 20));
        Acq_play_txt->setFont(font);
        Acq_play_txt->setStyleSheet(QString::fromUtf8("border: 0px solid black; "));
        m_bCurDisplay = new QPushButton(Menu);
        m_bCurDisplay->setObjectName(QString::fromUtf8("m_bCurDisplay"));
        m_bCurDisplay->setGeometry(QRect(285, 85, 110, 35));
        m_bCurDisplay->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-image: url(:/Images/Acq.png);\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        label_9 = new QLabel(Menu);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(280, 65, 101, 20));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("border: 0px solid black; "));
        widget_LED_Setting = new QWidget(Menu);
        widget_LED_Setting->setObjectName(QString::fromUtf8("widget_LED_Setting"));
        widget_LED_Setting->setGeometry(QRect(410, 0, 111, 130));
        m_USB_Link_Led = new QPushButton(widget_LED_Setting);
        m_USB_Link_Led->setObjectName(QString::fromUtf8("m_USB_Link_Led"));
        m_USB_Link_Led->setEnabled(false);
        m_USB_Link_Led->setGeometry(QRect(10, 6, 20, 20));
        m_USB_Link_Led->setStyleSheet(QString::fromUtf8("background-color: red;\n"
" border-style: solid;\n"
" border-width:2px;\n"
" border-radius:8px;\n"
" border-color: black;\n"
" max-width:16px;\n"
" max-height:16px;\n"
" min-width:16px;\n"
" min-height:16px;"));
        m_Uart_Link_LED = new QPushButton(widget_LED_Setting);
        m_Uart_Link_LED->setObjectName(QString::fromUtf8("m_Uart_Link_LED"));
        m_Uart_Link_LED->setEnabled(false);
        m_Uart_Link_LED->setGeometry(QRect(10, 34, 20, 20));
        m_Uart_Link_LED->setStyleSheet(QString::fromUtf8("background-color: red;\n"
" border-style: solid;\n"
" border-width:2px;\n"
" border-radius:8px;\n"
" border-color: black;\n"
" max-width:16px;\n"
" max-height:16px;\n"
" min-width:16px;\n"
" min-height:16px;"));
        USB_link_txt = new QLineEdit(widget_LED_Setting);
        USB_link_txt->setObjectName(QString::fromUtf8("USB_link_txt"));
        USB_link_txt->setGeometry(QRect(40, 5, 51, 20));
        USB_link_txt->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);\n"
"border:0px;\n"
"font: 75 8pt \"MS Shell Dlg 2\";"));
        m_UART_link_txt = new QLineEdit(widget_LED_Setting);
        m_UART_link_txt->setObjectName(QString::fromUtf8("m_UART_link_txt"));
        m_UART_link_txt->setGeometry(QRect(40, 33, 61, 20));
        m_UART_link_txt->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);\n"
"border:0px;"));
        m_bSettings = new QPushButton(widget_LED_Setting);
        m_bSettings->setObjectName(QString::fromUtf8("m_bSettings"));
        m_bSettings->setGeometry(QRect(35, 82, 40, 40));
        m_bSettings->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/settings.jpg);"));
        Settings_txt = new QLabel(widget_LED_Setting);
        Settings_txt->setObjectName(QString::fromUtf8("Settings_txt"));
        Settings_txt->setGeometry(QRect(30, 60, 51, 20));
        Settings_txt->setFont(font);
        Settings_txt->setStyleSheet(QString::fromUtf8("border: 0px solid black; "));
        console_scroll_area = new QScrollArea(Menu);
        console_scroll_area->setObjectName(QString::fromUtf8("console_scroll_area"));
        console_scroll_area->setGeometry(QRect(520, 1, 1381, 130));
        console_scroll_area->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1379, 128));
        console = new QTextEdit(scrollAreaWidgetContents);
        console->setObjectName(QString::fromUtf8("console"));
        console->setGeometry(QRect(0, 0, 1381, 130));
        console->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color:green;\n"
"font: 75 12pt \"Calibri\";"));
        console_scroll_area->setWidget(scrollAreaWidgetContents);
        widget_LED_Setting->raise();
        On_off_buttons->raise();
        m_logo->raise();
        Data_acq_txt->raise();
        Data_anay_txt->raise();
        m_bDataAcq->raise();
        m_bDataAna->raise();
        m_bDataAcqPlay->raise();
        Acq_play_txt->raise();
        m_bCurDisplay->raise();
        label_9->raise();
        console_scroll_area->raise();

        gridLayout->addWidget(Menu, 1, 0, 1, 1);

        m_stacked = new QStackedWidget(centralWidget);
        m_stacked->setObjectName(QString::fromUtf8("m_stacked"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        m_stacked->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        m_stacked->addWidget(page_2);

        gridLayout->addWidget(m_stacked, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Bio Data Analyzer", nullptr));
        m_bDataAcq->setText(QString());
        Data_acq_txt->setText(QApplication::translate("MainWindow", "Data Acquisition", nullptr));
        Data_anay_txt->setText(QApplication::translate("MainWindow", "Data Analysis", nullptr));
        m_bDataAna->setText(QString());
        m_bDataAcqPlay->setText(QString());
        Acq_play_txt->setText(QApplication::translate("MainWindow", "Play", nullptr));
        m_bCurDisplay->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "Display Now", nullptr));
        m_USB_Link_Led->setText(QString());
        m_Uart_Link_LED->setText(QString());
        USB_link_txt->setText(QApplication::translate("MainWindow", "USB Link", nullptr));
        m_UART_link_txt->setText(QApplication::translate("MainWindow", "UART Link", nullptr));
        m_bSettings->setText(QString());
        Settings_txt->setText(QApplication::translate("MainWindow", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
