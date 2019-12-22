#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include <memory>
#include "logger.h"
#include "types.h"
#include "communicationif.h"
#include "settings.h"
#include <fstream>
#include "ui_graphs.h"
#include "histograms.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    histograms m_histo;

    QWidget *m_graphWidget;
    Ui::Form m_graphs;

    settings m_settings;
    QPushButton m_bPlay;
    std::vector < std::shared_ptr<QCustomPlot> > m_channels;
    std::vector < std::ofstream > savedfiles;

    buttonStatus m_AcqState = OFF;
    buttonStatus m_AnalysisState = OFF;
    buttonStatus m_DisplayNowState = DISPLAY_ACQ;
    buttonStatus m_playState = PLAY;
    buttonStatus m_settingClicked = OFF;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void InsertDevice(CommunicationIF::Ptr device);

private:
    Ui::MainWindow *ui;
    std::list<CommunicationIF::Ptr> m_deviceList;
    std::map < uint16_t, QVector<double> >  m_data;

    void setButtonIcon(QString path, QPushButton *btn);
    void configureChart(QCustomPlot *ptr);
    void processData(CommunicationIF::Ptr device, std::vector<uint8_t> &data, uint16_t index);
    void disconnectDevice(CommunicationIF::Ptr device);
    void updateChart(uint16_t index, QVector<double> &plotData);
    void clearChart(QCustomPlot *ptr);
    void writeFile(uint16_t index, const std::string &data);
    void close(void);

public slots:
    void AcqOnOffClicked(void);
    void AnalysisOnOffClicked(void);
    void DisplayNowClicked(void);
    void playClicked(void);
    void settingClicked(void);

};

#endif // MAINWINDOW_H
