#include "histograms.h"
#include <QtAlgorithms>
#include <iostream>
#include "types.h"
#include <functional>
#include <QtAlgorithms>

#define MB(val) 1024*1024*val

#define ACTUAL_DEVICE(device) \
    std::dynamic_pointer_cast<serialCommunication>(device)

histograms::histograms(QWidget *parent) :
    QWidget(parent)
{
    m_histograms.setupUi(this);
    m_histograms.m_bRstCounter->setEnabled(false);

    areaDraw = new Draw(m_histograms.area_window, m_histograms.area_histo,
                        m_histograms.area_Dev, m_histograms.area_Median, "Area");
    peakDraw = new Draw(m_histograms.peak_window, m_histograms.peak_histo,
                        m_histograms.peak_Dev, m_histograms.peak_Median,"Peak");
    intencityDraw = new Draw(m_histograms.intencity_window, m_histograms.intensity_histo,
                             m_histograms.intensity_Dev, m_histograms.intensity_Median,"Intencity");
    transitTimeDraw = new Draw(m_histograms.TT_window, m_histograms.tt_histo,
                               m_histograms.tt_Dev, m_histograms.tt_Median, "TransitTime");
    m_histograms.m_vUpdateFreq->setValue(1000);

    connect(m_histograms.m_cbStartCounter, SIGNAL(stateChanged(int)), this, SLOT(counterCheckBox(int)));    //processData();
    connect(m_histograms.m_bRstCounter, SIGNAL(released()), this, SLOT(counterRst()));

    connect(m_histograms.m_bGetInstADCVal, SIGNAL(released()), this, SLOT(InstADCVal()));
    connect(m_histograms.m_bSetEventThr, SIGNAL(released()), this, SLOT(eventThreshold()));
    connect(m_histograms.m_vUpdateFreq,SIGNAL(valueChanged(int)), this, SLOT(getUpdateFreq(int)));
    connect(m_histograms.m_bEnableHisto,SIGNAL(released()), this, SLOT(enableHisto()));

    connect(m_histograms.m_bUTISet,SIGNAL(released()), this, SLOT(setFilterTT()));
    connect(m_histograms.m_bUTIOn,SIGNAL(released()), this, SLOT(enableFilterTT()));

    connect(m_histograms.m_bUPISet,SIGNAL(released()), this, SLOT(setFilterPeak()));
    connect(m_histograms.m_bUPIOn, SIGNAL(released()), this, SLOT(enableFilterPeak()));

    connect(m_histograms.m_bSumOfIntTTSet,SIGNAL(released()), this, SLOT(setFilterAblation()));
    connect(m_histograms.m_bSumOfIntTTOn, SIGNAL(released()), this, SLOT(enableFilterAblation()));
    connect(m_histograms.m_channel_1, SIGNAL(clicked()), this, SLOT(channleChanged()));
    connect(m_histograms.m_channel_2, SIGNAL(clicked()), this, SLOT(channleChanged()));

    m_histograms.m_bSetEventThr->setDisabled(true);
    m_histograms.m_bEnableHisto->setDisabled(true);
    m_histograms.m_vEvtThrs->setDisabled(true);
    m_histograms.m_vInstADCVal->setDisabled(true);
    m_histograms.m_cbStartCounter->setDisabled(true);
    m_histograms.m_cbTextFileSave->setDisabled(true);
    m_histograms.m_vUpdateFreq->setDisabled(true);

    getUpdateFreq(m_histograms.m_vUpdateFreq->value());
    channleChanged();

    m_intADCValue = 0;
    isSetTTFilter = false;
    isSetAblationFilter = false;
    isSetPeakFilter = false;
    isCounterOn = false;

//    m_tmp_timer = new QTimer(this);
//    connect(m_tmp_timer, SIGNAL(timeout()), this, SLOT(tmp_timer_expired()));
//    m_tmp_timer->start(1);

    isEnableHisto = false;
    m_point = 0;

    m_xCellCount = 0;
    m_yCellCount = 0;
    m_multipleCellCount = 0;
    m_totalCellCount = 0;
    m_ablationFireCount = 0;
    m_totalEvents = 0;
    m_containerCount = 0;
    expStopTime = 0;
    expStartTime = 0;
}

histograms::~histograms()
{
    closeFile();
}

QWidget* histograms::getWidget()
{
    return this;
}

void histograms::mouseWheel(QWheelEvent *event)
{
    if ( areaDraw->m_customPlot == QObject::sender() )
    {
        areaDraw->zoom(event->delta());
    }
    else if ( peakDraw->m_customPlot == QObject::sender() )
    {
        peakDraw->zoom(event->delta());
    }
    else if ( intencityDraw->m_customPlot == QObject::sender() )
    {
        intencityDraw->zoom(event->delta());
    }
    else if ( transitTimeDraw->m_customPlot == QObject::sender() )
    {
        transitTimeDraw->zoom(event->delta());
    }
}

void histograms::mouseDoubleClickEvent( QMouseEvent * e )
{
     if ( areaDraw->m_customPlot == QObject::sender() ||
           peakDraw->m_customPlot == QObject::sender() ||
            intencityDraw->m_customPlot == QObject::sender() ||
            transitTimeDraw->m_customPlot == QObject::sender())
     {
         if(intencityDraw->m_customPlot->isHidden() || areaDraw->m_customPlot->isHidden())
         {
             intencityDraw->show();
             transitTimeDraw->show();
             peakDraw->show();
             areaDraw->show();
         }
         else
         {
             intencityDraw->hide();
             transitTimeDraw->hide();
             peakDraw->hide();
             areaDraw->hide();

             if(areaDraw->m_customPlot == QObject::sender())
                 areaDraw->show();
             else if(peakDraw->m_customPlot == QObject::sender())
                 peakDraw->show();
             else if(intencityDraw->m_customPlot == QObject::sender())
                 intencityDraw->show();
             else if(transitTimeDraw->m_customPlot == QObject::sender())
                 transitTimeDraw->show();
         }
     }
}

void printArray(vector<uint32_t> &test)
{
    for(int i = 0; i < test.size(); i++)
    {
        printf("%d ",test[i]);
        if(i && ((i % 10) == 0))
            printf("\n");
    }
}


void histograms::draw_histogram(Draw *draw_histo, QVector<uint32_t> &data)
{
        if(draw_histo == nullptr)
            return;
        if(draw_histo->m_customPlot == nullptr || draw_histo->m_bar == nullptr || draw_histo->scrollArea == nullptr || !data.size())
            return;
//        auto calc = calculateStdDeviation(data);
//        string str = "D:" + to_string(get<0>(calc));
//        draw_histo->m_Dev->setText(str.data());
//        str.clear();
//        str = "M:" + to_string(get<1>(calc));
//        draw_histo->m_Median->setText(str.data());

        // Binning Logic
        std::map<uint32_t, double> valMap;
        std::sort(&data[0], &data[m_updateFreq - 1]);
        uint32_t binning = ((data[m_updateFreq - 1] - data[0]) / 50);
        int  j = 0,i = 0;
        for(; i < m_updateFreq; i++)
        {
            if((data[i] - data[j]) > binning)
                j = i;
            valMap[data[j]]++;
        }

        QVector<double> count(valMap.size());
        QVector<double> val(valMap.size());
        QVector<QString> labels(valMap.size());

        auto it = valMap.begin();
        for(int i = 0;it != valMap.end();it++,i++)
        {
            count[i] = it->second;
            val[i] = i;
            labels[i] = QString::number(static_cast<int>(it->first));
        }
        draw_histo->m_customPlot->xAxis->setTicks(true);
        QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
        textTicker->addTicks(val, labels);
        draw_histo->m_customPlot->xAxis->setTicker(textTicker);
        draw_histo->m_bar->setData(val, count, true);
        if(draw_histo->once)
        {
            draw_histo->once = false;
            connect(draw_histo->m_customPlot, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheel(QWheelEvent*)));
            connect(draw_histo->m_customPlot, SIGNAL(mouseDoubleClick(QMouseEvent* )), this, SLOT(mouseDoubleClickEvent(QMouseEvent*)));
        }
        draw_histo->m_customPlot->rescaleAxes();
        draw_histo->m_customPlot->replot(QCustomPlot::rpQueuedReplot);
        data.erase(data.begin(), data.begin() + m_updateFreq);
       // usleep(100);
}

void histograms::insertDevice(CommunicationIF::Ptr device)
{
     m_device = device;
     std::shared_ptr<serialCommunication> comm = std::dynamic_pointer_cast<serialCommunication>(m_device);
     if(comm)
     {
         comm->registerForData(std::bind(&histograms::updateHistogram,this, std::placeholders::_1));
     }
}

void histograms::updateHistogram(serialReadData *data)
{
    if(data)
    {
        if(isEnableHisto)
        {
            if(m_area.size() <= m_containerCount)
                m_area.resize(m_area.size() + MB(1));
            if(m_peak.size() <= m_containerCount)
                m_peak.resize(m_peak.size() + MB(1));
            if(m_intencity.size() <= m_containerCount)
                m_intencity.resize(m_intencity.size() + MB(1));
            if(m_transmitTime.size() <= m_containerCount)
                m_transmitTime.resize(m_transmitTime.size() + MB(1));
            if(m_status.size() <= m_containerCount)
                m_status.resize(m_status.size() + MB(1));

            m_area[m_containerCount] = data->m_area;
            m_peak[m_containerCount] = data->m_peak;
            m_intencity[m_containerCount] = data->m_intencity;
            m_transmitTime[m_containerCount] = data->m_transmitTime;
            m_status[m_containerCount] = data->m_status;
            m_containerCount++;

            if(m_containerCount == m_updateFreq)
            {
                draw_histogram(areaDraw, m_area);
                draw_histogram(peakDraw, m_peak);
                draw_histogram(intencityDraw, m_intencity);
                draw_histogram(transitTimeDraw, m_transmitTime);
                m_containerCount = 0;
                m_area.clear();
                m_peak.clear();
                m_intencity.clear();
                m_transmitTime.clear();
            }
        }
        else {
            m_containerCount = 0;
        }

        if(m_histograms.m_cbTextFileSave->isChecked())
        {
            UpdateReadingToFile(data);
        }
        else
           closeFile();

        parseStatus(data->m_status);

        m_totalEvents++;
        if(!(m_totalEvents % m_updateFreq))
        {
            m_histograms.m_vEventElapsed->setText(to_string(m_totalEvents).data());
            if(isCounterOn)
                displayCounter();
        }

    }

#if 0
    QVector<double> m_area;
    m_area.clear();
    auto testPath = QDir::toNativeSeparators( QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) );
    testPath = testPath + "\\test.txt";
    QFile test(testPath);
    std::cout << "test Path: " << testPath.toStdString() << std::endl;

    test.open(QIODevice::ReadOnly | QIODevice::Text);

    if(test.isOpen())
    {
        std::string val;
        while(!test.atEnd())
        {
            auto out = test.readLine();
            auto str = out.toStdString();

            str.resize(str.size() - 2 );

            std::cout << "Out :" << str << "Size : " << str.size() <<std::endl;
            m_area.push_back(static_cast<double>(std::atoi(str.data())));
        }
        test.close();
    }
    else
    {

        std::cout << "Open Fail : " <<  test.errorString().toStdString() << std::endl;
    }

    displayArea(m_area);
    displayPeak(m_area);
    displayTransitTime(m_area);
    displayIntencity(m_area);    
#endif
}

void histograms::counterCheckBox(int status)
{
    if(status == Qt::Checked)
    {
        isCounterOn = true;
        //counterRst();
        m_histograms.m_bRstCounter->setEnabled(true);
    }
    else
    {
        isCounterOn = false;
        m_histograms.m_bRstCounter->setEnabled(false);
    }

}

void histograms::displayCounter(void)
{
    int x_count = (isCounterOn) ? m_xCellCount : 0;
    int y_count = (isCounterOn) ? m_yCellCount : 0;
    int multi_count = (isCounterOn) ? m_multipleCellCount : 0;
    int total_count = (isCounterOn) ? m_totalCellCount : 0;
    int ablation_count = (isCounterOn) ? m_ablationFireCount : 0;

    m_histograms.m_vTotalCount->setNum(total_count);
    m_histograms.m_vXCellCount->setNum(x_count);
    m_histograms.m_vYCell_Count->setNum(y_count);
    m_histograms.m_vMultiCellCount->setNum(multi_count);
    m_histograms.m_vAlbationFireCount->setNum(ablation_count);
}

void histograms::counterRst(void)
{
    m_xCellCount = 0;
    m_yCellCount = 0;
    m_multipleCellCount = 0;
    m_totalCellCount = 0;
    m_ablationFireCount = 0;

    displayCounter();
}

void histograms::InstADCVal(void)
{
    m_histograms.m_bGetInstADCVal->setDisabled(true);
    std::shared_ptr<serialCommunication> comm = std::dynamic_pointer_cast<serialCommunication>(m_device);
    if(comm)
    {
        m_intADCValue = comm->cGetADCInstValue();
        if(m_intADCValue >= 0)
        {
            m_histograms.m_vInstADCVal->setText(QString::number(m_intADCValue));
            m_histograms.m_bSetEventThr->setEnabled(true);
            m_histograms.m_vEvtThrs->setEnabled(true);
        }
    }
    m_histograms.m_bGetInstADCVal->setDisabled(false);
}
void histograms::eventThreshold(void)
{
    m_histograms.m_bSetEventThr->setDisabled(true);
    std::shared_ptr<serialCommunication> comm = std::dynamic_pointer_cast<serialCommunication>(m_device);
    if(comm)
    {
        if(comm->cSetEventThr(m_histograms.m_vEvtThrs->toPlainText().toInt()))
        {
            m_histograms.m_bEnableHisto->setDisabled(false);
            m_histograms.m_cbStartCounter->setDisabled(false);
            m_histograms.m_cbTextFileSave->setDisabled(false);
            m_histograms.m_vUpdateFreq->setDisabled(false);

        }
    }
    m_histograms.m_bSetEventThr->setDisabled(false);
}

#include <QDateTime>
void histograms::enableHisto(void)
{
//    if(isEnableHisto)
//        isEnableHisto = false;
//    else {
//        isEnableHisto = true;
//    }
//    return;
    std::shared_ptr<serialCommunication> comm = std::dynamic_pointer_cast<serialCommunication>(m_device);
    if(comm && comm->cEnabledHisto(!isEnableHisto))
    {
        if(isEnableHisto)
        {
            expStopTime = QDateTime::currentSecsSinceEpoch();
            isEnableHisto = false;
            clear_histogram(areaDraw);
            clear_histogram(peakDraw);
            clear_histogram(intencityDraw);
            clear_histogram(transitTimeDraw);
            closeFile();
            m_totalEvents = 0;
            m_histograms.m_vEventElapsed->setText(to_string(m_totalEvents).data());
            if(m_histograms.m_cbTextFileSave->isChecked())
                m_histograms.m_cbTextFileSave->setCheckState(Qt::Unchecked);
            if(m_histograms.m_cbStartCounter->isChecked())
                m_histograms.m_cbStartCounter->setCheckState(Qt::Unchecked);

        }
        else
        {
            expStartTime = QDateTime::currentSecsSinceEpoch();
            isEnableHisto = true;
        }
    }
}

void histograms::getUpdateFreq(int val)
{
    m_updateFreq = val;
}

void histograms::tmp_timer_expired(void)
{
    struct serialReadData data;
    data.m_area =1 + rand() % 2500;
    data.m_peak = 1 + rand() % 7500;
    data.m_intencity = 1 + rand() % 3000;
    data.m_transmitTime = 1 + rand() % 2531;
    data.m_status = 1 + rand() % 254;

    updateHistogram(&data);
   //h_data.updateChart();
}

void histograms::clear_histogram(Draw *draw_histo)
{
    draw_histo->m_bar->data()->clear();
    draw_histo->m_customPlot->xAxis->setTicks(false);
    draw_histo->m_customPlot->replot();

}

void histograms::prepareFile(void)
{
    m_headerStartOfRecodrd = "...................................................."
                             "...................................................."
                             "...................................................."
                             "\nSTART OF RECORD\n"
                             "...................................................."
                             "...................................................."
                             "....................................................";


    m_expDetail = "...................................................."
                  "...................................................."
                  "...................................................."
                  "\nExperiment Details\n"
                  "...................................................."
                  "...................................................."
                  "....................................................";


    m_histoParameter = "...................................................."
                      "...................................................."
                      "...................................................."
                      "\nHistograms Parameters\n"
                      "...................................................."
                      "...................................................."
                      "....................................................";

    m_expDataDetail = "...................................................."
                      "...................................................."
                      "...................................................."
                      "\nExperiment Data Details\n"
                      "...................................................."
                      "...................................................."
                      "...................................................."
                      "\nEvent       Peak      Transit     Sum of     Sum of Intensities/   Transit Time Filter    Peak Intencity    Cell Type    Ablation"
                      "\nNumber    Intensity    Time     Intensities     Transit Time            violation        filter violation                triggered\n";

    m_fileterParameter = "...................................................."
                         "...................................................."
                         "...................................................."
                         "\nFilter Parameters\n"
                         "...................................................."
                         "...................................................."
                         "....................................................";


    m_cellDataCounters =  "...................................................."
                          "...................................................."
                          "...................................................."
                          "\nCell Data Counter\n"
                          "...................................................."
                          "...................................................."
                          "....................................................";


    m_expStatic =  "...................................................."
                   "...................................................."
                   "...................................................."
                   "\nExperiment Statistical Data\n"
                   "...................................................."
                   "...................................................."
                   "...................................................."
                   "\nPeak Intensity"
                   "\nMedian(avg): (float)"
                   "\nStandard Deviation(avg): (float)"
                   "\nTransit Time"
                   "\nMedian(avg): (float)"
                   "\nStandard Deviation(avg): (float)"
                   "\nSum of Intensities"
                   "\nMedian(avg): (float)"
                   "\nStandard Deviation(avg): (float)"
                   "\nSum of Intensities / Transit Time"
                   "\nMedian(avg): (float)"
                   "\nStandard Deviation(avg): (float)";

    m_expRunDetail =  "...................................................."
                   "...................................................."
                   "...................................................."
                   "\nExperiment Run Details\n"
                   "...................................................."
                   "...................................................."
                   "....................................................";

    m_headerEndOfRecord = "...................................................."
                             "...................................................."
                             "...................................................."
                             "\nEND OF RECORD\n"
                             "...................................................."
                             "...................................................."
                             "....................................................";
    UpdateFile();
}

void histograms::UpdateFile(void)
{
    m_reportFile.open("report.txt");
    m_reportFile << m_headerStartOfRecodrd << std::endl;

    m_reportFile << m_expDetail << std::endl;
    m_reportFile << "\nExperiment Name:";
    m_reportFile << "\nDate:" + QDateTime::currentDateTime().date().toString().toStdString();
    m_reportFile << "\nTime:" + QDateTime::currentDateTime().time().toString().toStdString() + "\n";
    //m_reportFile << "\nAblation Status:\n";


    //m_reportFile << m_expStatic << std::endl;
    //m_reportFile << m_expRunDetail << std::endl;

    m_reportFile << m_expDataDetail << std::endl;
    m_reportFile.flush();
}

void histograms::UpdateReadingToFile(serialReadData *data)
{
    if(!m_reportFile.is_open())
        prepareFile();

    m_strReadings.insert(0, 170,' ');
    m_strReadings.insert(m_point++,"\n");
    //Event Number

    m_strReadings.insert(m_point, std::to_string(m_totalEvents));
    m_point += 10;

    //Transit Time
    auto end = std::to_string(data->m_peak).find(".") + 3;
    m_strReadings.insert(m_point, std::to_string(data->m_peak).substr(0,end));
    m_point += 12;

    //Peak Intensity
    end = std::to_string(data->m_transmitTime).find(".") + 3;
    m_strReadings.insert(m_point, std::to_string(data->m_transmitTime).substr(0,end));
    m_point += 11;

    //Sum of intensity
    //end = std::to_string(data->m_intencity).find(".") + 3;
    uint32_t area = data->m_area;
    m_strReadings.insert(m_point, std::to_string(area));
    m_point += 17;

    //Sum of Intensities/ TransitTime
    double val = data->m_area/data->m_transmitTime;
    end = std::to_string(val).find(".") + 3;
    m_strReadings.insert(m_point, std::to_string(val).substr(0, end));
    m_point += 23;

    //Transit Time filter violation
    string str = "  -  ";
    if(data->m_status & 0x80)
    {
        if(data->m_status & 0x03)
            str = "  YES  ";
        else if(data->m_status & 0x05)
            str = "  YES  ";
        else if(data->m_status & 0x06)
            str = "  YES  ";
        else
            str = "  NO  ";
    }

    m_strReadings.insert(m_point, str);
    m_point += 20;

    //Peak Intensity filter violation
    str.clear();
    str = "  -  ";
    if(data->m_status & 0x40)
    {
        if(data->m_status & 0x07)
            str = "  YES  ";
        else if(data->m_status & 0x04)
            str = "  YES  ";
        else
            str = "  NO  ";
    }
    m_strReadings.insert(m_point, str);
    m_point += 15;

    //Cell Type
    str.clear();
    str = "  -  ";
    if(data->m_status & 0x00)
        str = "No Filter";
    else if(data->m_status & 0x01)
        str = "   X   ";
    else if(data->m_status & 0x02)
        str = "   Y   ";
    else if(data->m_status & 0x03)
        str = "MULTIPLE";
    else if(data->m_status & 0x07)
        str = "VALID";
    else
        str = "OUTLIER";

    m_strReadings.insert(m_point, str);
    m_point += 14;

    //Ablation triggered
    str.clear();
    str = "  -  ";
    if(data->m_status & 0x20)
    {
        if(data->m_status & 0x02)
            str = "   YES   ";
        else if(data->m_status & 0x03)
            str = "   YES   ";
        else if(data->m_status & 0x04 ||
                data->m_status & 0x05 ||
                data->m_status & 0x06)
            str = "   YES   ";
        else
            str = "   NO   ";
    }
    m_strReadings.insert(m_point, str);
    //m_point += str.size();

    //m_point++;
    m_point = 0;
    m_reportFile << m_strReadings;
    m_reportFile.flush();
    m_strReadings.clear();
}


void histograms::parseStatus(uint8_t status)
{
    if(isCounterOn)
    {
        switch (status & 0x03) {
        default:
            break;
        case  X_CELL:
            m_xCellCount++;
            break;
        case  Y_CELL:
            m_yCellCount++;
            break;
        case  MULTIPLIES_CELL:
            m_multipleCellCount++;
            break;

        }

        m_ablationFireCount = m_yCellCount + m_multipleCellCount;
        m_totalCellCount = m_xCellCount + m_yCellCount + m_multipleCellCount;
    }
}

void histograms::enableFilterTT(void)
{
    std::shared_ptr<serialCommunication> comm = std::dynamic_pointer_cast<serialCommunication>(m_device);
    if(comm && isSetTTFilter)
    {
        if (m_histograms.m_bUTIOn->text() == "OFF")
        {
            if(comm->cEnabledTTThr(true))
                m_histograms.m_bUTIOn->setText("ON");
        }
        else
        {
            if(comm->cEnabledTTThr(false))
                m_histograms.m_bUTIOn->setText("OFF");
        }
    }
}
void histograms::setFilterTT(void)
{
    std::shared_ptr<serialCommunication> comm = std::dynamic_pointer_cast<serialCommunication>(m_device);
    if(comm)
    {
        isSetTTFilter = comm->cSetTTThr(m_histograms.m_vLTThreshold->toPlainText().toInt(),
                                        m_histograms.m_vUTThreshold->toPlainText().toInt());
    }
}
void histograms::enableFilterPeak(void)
{
    std::shared_ptr<serialCommunication> comm = std::dynamic_pointer_cast<serialCommunication>(m_device);
    if(comm && isSetPeakFilter)
    {
        if (m_histograms.m_bUPIOn->text() == "OFF")
        {
            if(comm->cEnabledPeakIntensityThr(true))
                m_histograms.m_bUPIOn->setText("ON");
        }
        else
        {
            if(comm->cEnabledPeakIntensityThr(false))
                m_histograms.m_bUPIOn->setText("OFF");
        }
    }
}
void histograms::setFilterPeak(void)
{
    std::shared_ptr<serialCommunication> comm = std::dynamic_pointer_cast<serialCommunication>(m_device);
    if(comm)
    {
        isSetPeakFilter = comm->cSetPeakIntensityThr(m_histograms.m_vLPIThreshold->toPlainText().toInt(),
                                                     m_histograms.m_vUPIThreshold->toPlainText().toInt());
    }
}
void histograms::enableFilterAblation(void)
{
    std::shared_ptr<serialCommunication> comm = std::dynamic_pointer_cast<serialCommunication>(m_device);
    if(comm && isSetAblationFilter)
    {
        if (m_histograms.m_bSumOfIntTTOn->text() == "OFF")
        {
            if(comm->cEnabledAblationThr(true))
                m_histograms.m_bSumOfIntTTOn->setText("ON");
        }
        else
        {
            if(comm->cEnabledAblationThr(false))
                m_histograms.m_bSumOfIntTTOn->setText("OFF");
        }
    }
}
void histograms::setFilterAblation(void)
{
    std::shared_ptr<serialCommunication> comm = std::dynamic_pointer_cast<serialCommunication>(m_device);
    if(comm)
    {
        isSetAblationFilter = comm->cSetAblationThr(m_histograms.m_vSomTTThreshold->toPlainText().toInt());
    }
}

void histograms::channleChanged(void)
{
    std::shared_ptr<serialCommunication> comm = std::dynamic_pointer_cast<serialCommunication>(m_device);
    if(comm)
    {
        uint16_t channel;
        if(m_histograms.m_channel_1->isChecked())
            channel = 0xab01;
        else if(m_histograms.m_channel_2->isChecked())
            channel = 0xab02;

        comm->setCurrentChannel(channel);
    }
}

std::tuple<double, double> histograms::calculateStdDeviation(QVector<double> &data)
{
    QVector<double> tmp;
    double val = 0;
    double mean = 0;
    double Maiden = data[m_updateFreq/2];

    for(auto item : data)
    {
         val += item;
    }
    mean = val/data.size();

    val = 0;
    for(auto item : data)
    {
        auto a = mean - item;
        if(a < 0) a = a * (-1);
        val += a*a;
    }

    return make_tuple( val/data.size(), Maiden);
}

bool histograms::updateValueInFile(std::string filename, std::string str, std::string derivative)
{
}

void histograms::closeFile(void)
{
    if(m_reportFile.is_open())
    {
        m_reportFile << m_histoParameter << std::endl;
        m_reportFile << "\nEvent Threshold:" + m_histograms.m_vEvtThrs->toPlainText().toStdString() << std::endl;

        m_reportFile << m_fileterParameter << std::endl;
        m_reportFile << "\nUpper Transit Time Threshold: " + m_histograms.m_vUTThreshold->toPlainText().toStdString();
        m_reportFile << "\nLower Transit Time Threshold: " + m_histograms.m_vLTThreshold->toPlainText().toStdString();
        m_reportFile << "\nUpper Peak Intensity Threshold: " + m_histograms.m_vUPIThreshold->toPlainText().toStdString();
        m_reportFile << "\nLower Peak Intensity Threshold: " + m_histograms.m_vLPIThreshold->toPlainText().toStdString() << std::endl;

        m_reportFile << m_cellDataCounters << std::endl;
        m_reportFile <<  "\nEvents elapsed:" + to_string(m_totalEvents);
        m_reportFile <<  "\nX Cell Count:" + to_string(m_xCellCount);
        m_reportFile <<  "\nY Cell Count:" + to_string(m_yCellCount);
        m_reportFile <<  "\nMultiple Cell Count:" + to_string(m_multipleCellCount);
        m_reportFile <<  "\nTotal Cell Count:" + to_string(m_totalCellCount);
        m_reportFile <<  "\nAblation Cell Count:" + to_string(m_ablationFireCount) << std::endl;

        m_reportFile << m_expRunDetail << std::endl;
        m_reportFile << "Experiment Run Time:" + QDateTime::fromTime_t(expStopTime - expStartTime).toUTC().toString("hh:mm:ss").toStdString() << std::endl;
        m_reportFile << m_headerEndOfRecord << std::endl;
        m_reportFile.flush();
        m_reportFile.close();
    }
}
