#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <experimental/filesystem>
class USBCommunication;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),m_histo(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->console->setReadOnly(true);

    m_graphWidget = new QWidget;
    m_graphs.setupUi(m_graphWidget);

    logger::getInstance()->setLoggerWindow(ui->console);

    savedfiles.resize(4);

    m_playState = STOP;
    m_AcqState = OFF;
    m_AnalysisState = OFF;
    m_DisplayNowState = DISPLAY_ACQ;

    logger::getInstance()->log("Initialize GUI ...");
    connect(ui->m_bDataAcq, SIGNAL (released()), this ,SLOT(AcqOnOffClicked()));
    connect(ui->m_bDataAna, SIGNAL (released()), this ,SLOT(AnalysisOnOffClicked()));
    connect(ui->m_bSettings, SIGNAL (released()), this ,SLOT(settingClicked()));
    connect(ui->m_bCurDisplay, SIGNAL (released()), this ,SLOT(DisplayNowClicked()));
    connect(ui->m_bDataAcqPlay, SIGNAL (released()), this ,SLOT(playClicked()));

    configureChart(m_graphs.m_channel_1);
    configureChart(m_graphs.m_channel_2);
    configureChart(m_graphs.m_channel_3);
    configureChart(m_graphs.m_channel_4);
    logger::getInstance()->log("Initialize GUI completer...");

    ui->m_stacked->addWidget(m_graphWidget);
    ui->m_stacked->addWidget(m_histo.getWidget());
    ui->m_stacked->setCurrentWidget(m_graphWidget);
    ui->m_stacked->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AcqOnOffClicked(void)
{
     auto state = (m_AcqState == OFF)? ON : OFF;

     if(state == ON)
     {
         bool ret = (m_deviceList.size()) ? true : false;
         std::for_each(m_deviceList.begin(), m_deviceList.end(),[&ret](CommunicationIF::Ptr dev)
         {
             if(dev->type() == COMM_USB)
                 ret = dev->Initialization();
         });


         if(ret)
         {
             setButtonIcon(ICON_BUTTON_ON, qobject_cast<QPushButton*>(sender()));
             ui->m_bSettings->setDisabled(true);
             ui->m_USB_Link_Led->setStyleSheet(ui->m_USB_Link_Led->styleSheet() + "background-color: green;");
         }
         else
             return;
     }
     else
     {

         close();
         setButtonIcon(ICON_BUTTON_OFF, ui->m_bDataAcq);
         ui->m_bSettings->setDisabled(false);
         ui->m_USB_Link_Led->setStyleSheet(ui->m_USB_Link_Led->styleSheet() + "background-color: red;");

     }
     m_AcqState = state;
}

void MainWindow::AnalysisOnOffClicked(void)
{
     auto state = (m_AnalysisState == OFF)? ON : OFF;

     if(state == ON)
     {
         bool ret = (m_deviceList.size()) ? true : false;
         std::for_each(m_deviceList.begin(), m_deviceList.end(),[&ret, this](CommunicationIF::Ptr dev)
         {
             if(dev->type() == COMM_SERIAL)
             {
                 ret = dev->Initialization();
                 m_histo.insertDevice(dev);
             }
         });


         if(ret)
         {
             setButtonIcon(ICON_BUTTON_ON, qobject_cast<QPushButton*>(sender()));
             ui->m_bSettings->setDisabled(true);
             ui->m_Uart_Link_LED->setStyleSheet(ui->m_Uart_Link_LED->styleSheet() + "background-color: green;");
         }
         else
             return;
     }
     else
     {
         close();
         setButtonIcon(ICON_BUTTON_OFF, ui->m_bDataAna);
         ui->m_bSettings->setDisabled(false);
         ui->m_Uart_Link_LED->setStyleSheet(ui->m_Uart_Link_LED->styleSheet() + "background-color: red;");

     }

     m_AnalysisState = state;
}

void MainWindow::DisplayNowClicked(void)
{
    auto state = (m_DisplayNowState == DISPLAY_ACQ)? DISPLAY_ANALYSIS : DISPLAY_ACQ;
    if(state == DISPLAY_ANALYSIS)
    {
           setButtonIcon(ICON_CURR_DISPLAY_ANALYSIS, qobject_cast<QPushButton*>(sender()));
           ui->m_stacked->setCurrentWidget(m_histo.getWidget());
           m_histo.prepareShow(ui->centralWidget->size());
           ui->m_stacked->show();
    }
    else
    {
           setButtonIcon(ICON_CURR_DISPLAY_ACQ, qobject_cast<QPushButton*>(sender()));
           ui->m_stacked->setCurrentWidget(m_graphWidget);
           ui->m_stacked->show();
    }
    m_DisplayNowState = state;
}

void MainWindow::playClicked(void)
{
    if(m_AcqState == ON)
    {
        auto state = (m_playState == STOP)? PLAY : STOP;
        if(state == PLAY)
        {
            setButtonIcon(ICON_PLAY_OFF, ui->m_bDataAcqPlay);
        }
        else
        {
            setButtonIcon(ICON_PLAY_ON, ui->m_bDataAcqPlay);
            clearChart(m_graphs.m_channel_1);
            clearChart(m_graphs.m_channel_2);
            clearChart(m_graphs.m_channel_3);
            clearChart(m_graphs.m_channel_4);

        }
        m_playState = state;
    }
}

void MainWindow::settingClicked(void)
{
     m_settings.show_setting_window();
}

void MainWindow::configureChart(QCustomPlot *ptr)
{
    logger::getInstance()->log("Configure Chart...");

    ptr->setOpenGl(true);
    ptr->addGraph();
    auto pen = QPen(Qt::green);
    pen.setWidth(1);
    pen.setCosmetic(true);
    ptr->graph(0)->setPen(pen); // line color blue for first graph
    ptr->graph(0)->setBrush(QBrush(QColor(0, 0, 0, 0)));
    ptr->graph(0)->setAdaptiveSampling(true);
    ptr->setBackground(QBrush(QColor(Qt::black)));
    ptr->plotLayout()->setRowSpacing(10);
    ptr->plotLayout()->setColumnSpacing(10);

    ptr->xAxis2->setVisible(false);
    ptr->xAxis2->setTickLabels(false);
    ptr->yAxis2->setVisible(false);
    ptr->yAxis2->setTickLabels(false);
}

void MainWindow::setButtonIcon(QString path, QPushButton *btn)
{
    //logger::getInstance()->log("%s",path.toStdString().c_str());

    QString str;
    str = "background-image: url(";
    str += path;
    str += ");";
    str += "border-radius: 10px;";

    btn->setStyleSheet(str);
}


void MainWindow::updateChart(uint16_t index, QVector<double> &plotData)
{
    if(m_playState == PLAY)
    {
        QCustomPlot *graphPtr = nullptr;
        switch (index)
        {
        case 1:
            graphPtr = m_graphs.m_channel_1;
            break;
        case 2:
            graphPtr = m_graphs.m_channel_2;
            break;
        case 3:
            graphPtr = m_graphs.m_channel_3;
            break;
        case 4:
            graphPtr = m_graphs.m_channel_4;
            break;
        }

        if(graphPtr != nullptr)
        {
            QVector<double> xAxs;
            xAxs.resize(plotData.size());
            for(int i = 0; i < xAxs.size(); i++)
            {
                xAxs[i] = i;
            }

            graphPtr->graph(0)->setData(xAxs,plotData);
            graphPtr->rescaleAxes();
            graphPtr->replot(QCustomPlot::rpQueuedReplot);
        }
        else
        {
            std::cout << "Error : Sources Not allocated for Channel : " << index << std::endl;
        }
    }
    Sleep(1);
}


void MainWindow::InsertDevice(CommunicationIF::Ptr device)
{
    if(device)
    {
        logger::getInstance()->log("Insert %s", device->type(true).c_str());
        CommunicationIF::dataCallback_t cb = std::bind(&MainWindow::processData,this,std::placeholders::_1,std::placeholders::_2, std::placeholders::_3);
        device->registerForData(cb);
        CommunicationIF::closeCallback_t cb2 = std::bind(&MainWindow::disconnectDevice,this,std::placeholders::_1);
        device->registerForDisconnect(cb2);
        device->setSettingIntf(CommunicationIF::SettingsPtr(&m_settings));
        m_deviceList.insert(m_deviceList.end(),device);
    }
}

void MainWindow::processData(CommunicationIF::Ptr device, std::vector<uint8_t> &data, uint16_t index)
{
   auto filFormatistxt = m_settings.getFileFormat();
   uint32_t default_size = m_data[index].size();

    m_data[index].resize(m_data[index].size() + (data.size()/ 2));

    std::string fileContain(data.begin(),data.end());
    if(filFormatistxt == true)
    {
        fileContain.clear();
    }

    uint32_t sample = 0;
    for (uint32_t i = 0; i < data.size();i+=2)
    {
        sample = data[i];
        sample = (sample << 8) | data[i + 1];
        m_data[index][(i/2)+default_size] = static_cast<double>(sample);
        if(filFormatistxt)
            fileContain.insert(fileContain.size(),std::to_string(sample) + "\n");
    }

    if(m_data[index].size() >= 25*1024)
    {
        updateChart(index,m_data[index]);
        m_data[index].clear();
    }
    writeFile(index,fileContain);
}

void MainWindow::disconnectDevice(CommunicationIF::Ptr device)
{
    AcqOnOffClicked();
}

void MainWindow::clearChart(QCustomPlot *ptr)
{
    QVector<double> vec(5000,0.0);
    ptr->graph(0)->setData(vec,vec);
    ptr->rescaleAxes();
    ptr->replot(QCustomPlot::rpQueuedReplot);
}

void MainWindow::writeFile(uint16_t index, const std::string &data)
{
    auto EnabledChannels = m_settings.GetEnabledChannel();

    if(!(EnabledChannels >> (index - 1) & 0x01))
    {
        std::cout << "not enabled" << std::endl;
        return;
    }

    if (index && index <= savedfiles.size())
    {
        if(savedfiles[index -  1].is_open() == false)
        {
            auto currentTime = m_settings.GetDataFileStorePath() + '\\' + "ChannelData" + '\\';
            if (!std::experimental::filesystem::is_directory(currentTime)
                    || !std::experimental::filesystem::exists(currentTime))
            {
                std::experimental::filesystem::create_directory(currentTime); // create src folder
            }
            currentTime = currentTime + m_settings.GetFileName() + "_";
            currentTime = currentTime + QDateTime::currentDateTime().toString().toStdString();
            std::replace( currentTime.begin(), currentTime.end(), ' ', '_');
            std::replace( currentTime.begin() + 3, currentTime.end(), ':', '_');
            std::replace( currentTime.begin() + 3, currentTime.end(), '\\', '/');
            currentTime = currentTime + "_";
            currentTime = currentTime + QString::number(index).toStdString();
            if(m_settings.getFileFormat())
            {
                currentTime = currentTime + ".txt";
            }
            else
            {
                currentTime = currentTime + ".bin";
            }

            savedfiles[index -  1].open(currentTime, std::ios::trunc  | std::ios::out | std::ios::binary);
        }
        savedfiles[index -  1].write((const char *)&data[0], data.size());
    }
}

void MainWindow::close(void)
{
    std::for_each(m_deviceList.begin(), m_deviceList.end(),[](CommunicationIF::Ptr dev)
    {
        if(dev->type() == COMM_USB)
            dev->clean();
    });

    if(m_playState == PLAY)
    {
       playClicked();
    }
    m_data.clear();

    std::for_each(savedfiles.begin(), savedfiles.end(),[](std::ofstream &fileStrem){
        if(fileStrem.is_open())
        {
            fileStrem.close();
        }
    });
}



