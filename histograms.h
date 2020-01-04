#ifndef HISTOGRAMS_H
#define HISTOGRAMS_H

#include "serialcommunication.h"
#include "ui_histograms.h"
#include "qcustomplot.h"
#include <QObject>
#include <QTimer>
#include <fstream>

#define DEFAULT_HEIGHT 300
#define DEFAULT_WIDTH 620
#define DEFAULT_SCROLL_HEIGHT 340
#define DEFAULT_SCROLL_WIDTH 640
#define FULL_SCREEN_WIDTH 1320
#define FULL_SCREEN_HEIGHT 690
#define ZOOM_SCALE 150

enum filterStatus
{
    FILTER_STATUS_NONE,
    FILTER_STATUS_YES,
    FILTER_STATUS_NO,
    FILTER_STATUS_X,
    FILTER_STATUS_Y,
    FILTER_STATUS_MULTIPLE,
    FILTER_STATUS_OUTLIER,
    FILTER_STATUS_VALID
};


class histograms : public QWidget
{
    Q_OBJECT
    QWidget *m_wHistograms;
    Ui::histograms m_histograms;
    CommunicationIF::Ptr m_device;
    std::thread displayThread;
    int m_intADCValue;
    QTimer *m_tmp_timer;
    bool isEnableHisto;
    std::ofstream m_reportFile;
    uint32_t m_point;
    int32_t m_totalEvents;
    uint32_t m_updateFreq;
    uint32_t m_containerCount;
    uint32_t expStartTime;
    uint32_t expStopTime;

    string m_headerStartOfRecodrd;
    string m_expDetail;
    string m_histoParameter;
    string m_expDataDetail;
    string m_fileterParameter;
    string m_cellDataCounters;
    string m_expStatic;
    string m_expRunDetail;
    string m_headerEndOfRecord;
    string m_strReadings;

    filterStatus m_transitTimeFilter;
    filterStatus m_peakIntensityFilter;
    filterStatus m_cellType;
    filterStatus m_ablation_triggered;

    QVector<uint32_t>  m_peak;
    QVector<uint32_t>  m_transmitTime;
    QVector<uint32_t>  m_area;
    QVector<uint32_t>  m_intencity;
    QVector<uint8_t>  m_status;

    uint32_t m_xCellCount;
    uint32_t m_yCellCount;
    uint32_t m_multipleCellCount;
    uint32_t m_totalCellCount;
    uint32_t m_ablationFireCount;
    bool isCounterOn;
    bool isSetTTFilter;
    bool isSetAblationFilter;
    bool isSetPeakFilter;
    bool updateSize;
    QSize mainWindow_size;

    void prepareFile(void);
    void UpdateFile(void);
    void UpdateReadingToFile(serialReadData *data);
    void closeFile(void);



public:
    explicit histograms(QWidget *parent = nullptr);
    virtual ~histograms();
    QWidget *getWidget(void);

    void insertDevice(CommunicationIF::Ptr device);

    class Draw
    {
        friend class histograms;
        Draw & operator=(const Draw&) = delete;
        Draw(const Draw&) = delete;

        QCustomPlot *m_customPlot;
        QCPBars *m_bar;
        QScrollArea *scrollArea;
        QString name;
        QLineEdit *m_Dev;
        QLineEdit *m_Median;


        bool once;

        void zoom(int delta)
        {
            if(delta <= 0)
            {
                if(m_customPlot->width() > scrollArea->width())
                {
                    m_customPlot->setFixedWidth(m_customPlot->width() - ZOOM_SCALE );
                }
            }
            else
            {
                m_customPlot->setFixedWidth(m_customPlot->width() + ZOOM_SCALE );
            }
        }

        void hide (void)
        {
            m_customPlot->hide();
            scrollArea->hide();
        }

        void show (void)
        {
            m_customPlot->show();
            scrollArea->show();
        }

public:
        Draw(QScrollArea *scrollArea, QCustomPlot *customPlot,QLineEdit *dev, QLineEdit *median, QString chart_name) : scrollArea(scrollArea),
            name(chart_name), m_customPlot(customPlot), m_Dev(dev), m_Median(median)

        {
            m_bar = new QCPBars(m_customPlot->xAxis, m_customPlot->yAxis);
            m_bar->setWidth(0.2);
            m_bar->setBrush(QColor("Blue"));
            m_customPlot->yAxis->setVisible(true);
            m_customPlot->xAxis->setVisible(true);
            m_customPlot->setBackground(QBrush(QColor("white")));
            m_bar->setAntialiased(false);
            m_customPlot->xAxis->setTickLabelRotation(60);
            m_customPlot->yAxis->setLabel(name);
            once = true;
        }
    };
    Draw *areaDraw;
    Draw *intencityDraw;
    Draw *peakDraw;
    Draw *transitTimeDraw;
private:
    void draw_histogram(Draw *draw_histo, QVector<uint32_t> &data);
    void displayCounter(void);
    void updateHistogram(serialReadData *data);
    void clear_histogram(Draw *draw_histo);

    /**
     * @brief parseStatus
     * @param status
     */
    void parseStatus(uint8_t status);

    /**
     * @brief calculateStdDeviation
     * @param data
     * @return
     */
    std::tuple<double, double> calculateStdDeviation(QVector<double> &data);

    bool updateValueInFile(std::string filename, std::string str, std::string derivative = ":");

public slots:
    void mouseWheel(QWheelEvent *event);
    void mouseDoubleClickEvent( QMouseEvent * e );
    void counterCheckBox(int status);
    void counterRst(void);
    void InstADCVal(void);
    void eventThreshold(void);
    void enableHisto(void);
    void getUpdateFreq(int val);
    void tmp_timer_expired(void);
    void enableFilterTT(void);
    void setFilterTT(void);
    void enableFilterPeak(void);
    void setFilterPeak(void);
    void enableFilterAblation(void);
    void setFilterAblation(void);
    void channleChanged(void);
};

#endif // HISTOGRAMS_H
