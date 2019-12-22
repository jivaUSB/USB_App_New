#-------------------------------------------------
#
# Project created by QtCreator 2019-11-10T13:42:38
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport quick

TARGET = NewLayout
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QCUSTOMPLOT_USE_OPENGL

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += -std-c++11

SOURCES += \
        DRV_DriverInterface.cpp \
        communicationfactory.cpp \
        histograms.cpp \
        logger.cpp \
        main.cpp \
        mainwindow.cpp \
        qcustomplot.cpp \
        serialcommunication.cpp \
        settings.cpp \
        usbcommunication.cpp

HEADERS += \
        DRV_DriverInterface.h \
        FTD3XX.h \
        communicationfactory.h \
        communicationif.h \
        histograms.h \
        logger.h \
        mainwindow.h \
        qcustomplot.h \
        serialcommunication.h \
        serialconfiguration.h \
        settings.h \
        settingsif.h \
        shape.h \
        types.h \
        usb_settings.h \
        usbcommunication.h

FORMS += \
        graphs.ui \
        histograms.ui \
        mainwindow.ui \
        settings.ui

LIBS += -L$$PWD/./ -lFTD3XX
LIBS += -lstdc++fs
LIBS += -lOpengl32

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagesources.qrc

DISTFILES +=
