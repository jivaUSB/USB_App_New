#include "histograms.h"
#include <QtAlgorithms>
#include <iostream>
#include "types.h"

extern histoData h_data;

#define ACTUAL_DEVICE(device) \
    std::dynamic_pointer_cast<serialCommunication>(device)

histograms::histograms(QWidget *parent) :
    QWidget(parent)
{
    m_histograms.setupUi(this);
    m_histograms.m_bRstCounter->setEnabled(false);

    areaDraw = new Draw(m_histograms.scrollArea, "Area");
    peakDraw = new Draw(m_histograms.scrollArea_2, "Peak");
    intencityDraw = new Draw(m_histograms.scrollArea_3, "Intencity");
    transitTimeDraw = new Draw(m_histograms.scrollArea_4, "TransitTime");
    m_histograms.m_vUpdateFreq->setText("1000");

    connect(m_histograms.m_cbStartCounter, SIGNAL(stateChanged(int)), this, SLOT(counterCheckBox(int)));    //processData();
    connect(m_histograms.m_bRstCounter, SIGNAL(released()), this, SLOT(counterRst()));

    connect(m_histograms.m_bGetInstADCVal, SIGNAL(released()), this, SLOT(InstADCVal()));
    connect(m_histograms.m_bSetEventThr, SIGNAL(released()), this, SLOT(eventThreshold()));

    m_histograms.m_bSetEventThr->setDisabled(true);
    m_histograms.m_bEnableHisto->setDisabled(true);
    m_histograms.m_vEvtThrs->setDisabled(true);
    m_histograms.m_vInstADCVal->setDisabled(true);
    m_histograms.m_cbStartCounter->setDisabled(true);
    m_histograms.m_cbTextFileSave->setDisabled(true);
    m_histograms.m_vUpdateFreq->setDisabled(true);

    m_intADCValue = 0;
}

histograms::~histograms()
{

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
    bool ret = false;

    //intencityDraw->hide();
    //transitTimeDraw->hide();
    //peakDraw->hide();
    //areaDraw->hide();

    if ( areaDraw->m_customPlot == QObject::sender() )
    {
        ret = areaDraw->fullscreen();
    }
    else if ( peakDraw->m_customPlot == QObject::sender() )
    {
        ret = peakDraw->fullscreen();
    }
    else if ( intencityDraw->m_customPlot == QObject::sender() )
    {
        ret = intencityDraw->fullscreen();
    }
    else if ( transitTimeDraw->m_customPlot == QObject::sender() )
    {
        ret = transitTimeDraw->fullscreen();
    }

    if( ret )
    {
        intencityDraw->show();
        transitTimeDraw->show();
        peakDraw->show();
        areaDraw->show();
    }
}

#include<functional>
void histograms::displayArea( QVector<double> data)
{
    if(data.empty())
        draw_histogram(areaDraw, h_data.m_area);
    else
        draw_histogram(areaDraw,data);

#if 0
   int tmp = labels.size();
   int calculate_fix_size = ( (tmp*area->width()) / 500 );
   if( calculate_fix_size > area->width() )
   {
        area->setFixedWidth(calculate_fix_size );
        default_area_width = calculate_fix_size;
   }
#endif
}

void histograms::displayPeak(QVector<double> data)
{
    if(data.empty())
        draw_histogram(peakDraw,h_data.m_peak);
    else
        draw_histogram(peakDraw,data);

}

void histograms::displayTransitTime( QVector<double> data)
{
    if(data.empty())
        draw_histogram(transitTimeDraw, h_data.m_transmitTime);
    else
        draw_histogram(transitTimeDraw,data);
}

void histograms::displayIntencity(QVector<double> data)
{
    if(data.empty())
        draw_histogram(intencityDraw,h_data.m_intencity);
    else
        draw_histogram(intencityDraw,data);

}

void histograms::draw_histogram(Draw *draw_histo, QVector<double> &data)
{
    if(draw_histo == nullptr)
        return;

    if(draw_histo->m_customPlot == nullptr || draw_histo->m_bar == nullptr || draw_histo->scrollArea == nullptr || !data.size())
        return;

    std::cout << "Drawing Histogram " << std::endl;
    std::cout << "Data Size : " << data.size() << std::endl;

    std::map<double, double> valMap;
    for( int i = 0; i < data.size(); i++)
    {
        valMap[data[i]]++;
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

    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(val, labels);
    draw_histo->m_customPlot->xAxis->setTicker(textTicker);
    draw_histo->m_bar->setData(val, count);

    connect(draw_histo->m_customPlot, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheel(QWheelEvent*)));
    connect(draw_histo->m_customPlot, SIGNAL(mouseDoubleClick(QMouseEvent* )), this, SLOT(mouseDoubleClickEvent(QMouseEvent*)));

    draw_histo->m_customPlot->rescaleAxes();
    draw_histo->m_customPlot->replot();
}

void histograms::insertDevice(CommunicationIF::Ptr device)
{
     m_device = device;
}

void histograms::prepareShow(QSize mainwindow_size)
{
  displayThread = std::thread(std::bind(&histograms::processData,this,mainwindow_size));
  displayThread.detach();
}


void histograms::processData(QSize mainwindow_size)
{
    Sleep(250);

    areaDraw->updateSize(mainwindow_size);
    peakDraw->updateSize(mainwindow_size);
    intencityDraw->updateSize(mainwindow_size);
    transitTimeDraw->updateSize(mainwindow_size);

    {
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
#else
        displayArea();
        displayPeak();
        displayTransitTime();
        displayIntencity();
        displayCounter();
#endif
        //m_histo_ui->displayPeak(m_peak);
        //m_histo_ui->displayTransitTime(m_transmitTime);
        //m_histo_ui->displayIntencity(m_intencity);
    }
}

void histograms::counterCheckBox(int status)
{
    if(status == Qt::Checked)
    {
        h_data.isCounterOn = true;
        m_histograms.m_bRstCounter->setEnabled(true);
    }
    else
    {
        h_data.isCounterOn = false;
        m_histograms.m_bRstCounter->setEnabled(false);
    }
}

void histograms::displayCounter(void)
{
    int x_count = (h_data.isCounterOn) ? h_data.m_xCellCount : 0;
    int y_count = (h_data.isCounterOn) ? h_data.m_yCellCount : 0;
    int multi_count = (h_data.isCounterOn) ? h_data.m_multiCellCount : 0;
    int total_count = (h_data.isCounterOn) ? h_data.m_totalCellCount : 0;

    m_histograms.m_vTotalCount->setNum(total_count);
    m_histograms.m_vXCellCount->setNum(x_count);
    m_histograms.m_vYCell_Count->setNum(y_count);
    m_histograms.m_vMultiCellCount->setNum(multi_count);
}

void histograms::counterRst(void)
{
    h_data.m_xCellCount = 0;
    h_data.m_yCellCount = 0;
    h_data.m_multiCellCount = 0;
    h_data.m_totalCellCount = 0;

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

void histograms::enableHisto(void)
{

}


