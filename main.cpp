#include "mainwindow.h"
#include <QApplication>
#include <QtGlobal>
#include <QQuickWindow>
#include "communicationfactory.h"
#include "logger.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    logger::getInstance()->log("Creating Communication Channel Object");
    CommunicationIF::Ptr commDeviceUSB = CommunicationFactory::create();
    CommunicationIF::Ptr commDeviceSerial = CommunicationFactory::create(COMM_SERIAL);
    QQuickWindow::setSceneGraphBackend(QSGRendererInterface::OpenGL);

    w.InsertDevice(commDeviceUSB);
    w.InsertDevice(commDeviceSerial);

    w.showMaximized();
    w.show();

    return a.exec();
}
