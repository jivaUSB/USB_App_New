#ifndef HISTOGRAMS_H
#define HISTOGRAMS_H

#include "serialcommunication.h"
#include "ui_histograms.h"
#include "qcustomplot.h"
#include <QObject>

#define DEFAULT_HEIGHT 300
#define DEFAULT_WIDTH 620
#define DEFAULT_SCROLL_HEIGHT 340
#define DEFAULT_SCROLL_WIDTH 640
#define FULL_SCREEN_WIDTH 1320
#define FULL_SCREEN_HEIGHT 690
#define ZOOM_SCALE 150


class histograms : public QWidget
{
    Q_OBJECT
    QWidget *m_wHistograms;
    Ui::histograms m_histograms;
    CommunicationIF::Ptr m_device;
    std::thread displayThread;
    int m_intADCValue;

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
        int height;
        int width;
        int x_pos;
        int y_pos;
        int current_width;
        int default_plot_height;
        int default_plot_width;
        int default_scroll_height;
        int default_scroll_width;
        int default_full_screen_height;
        int default_full_screen_width;

        void updateSize(QSize mainwindowsize )
        {
            m_customPlot->setFixedSize(scrollArea->width(),scrollArea->height());
            default_plot_height = m_customPlot->height();
            default_plot_width = m_customPlot->width();
            default_scroll_height = scrollArea->height();
            default_scroll_width = scrollArea->width();
            default_full_screen_height = mainwindowsize.height();
            default_full_screen_width = mainwindowsize.width();
            x_pos = m_customPlot->x();
            y_pos = m_customPlot->y();
            current_width = m_customPlot->width();
        }

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
            current_width = m_customPlot->width();
        }
        bool fullscreen(void)
        {
            bool is_show = false;
            if(scrollArea->height() != default_full_screen_height)
            {
                //std::cout << "full screen" << std::endl;
                scrollArea->setGeometry(10,10,default_full_screen_width, default_full_screen_height);

                show();
                default_full_screen_height = scrollArea->height();
                default_full_screen_width = scrollArea->width();
                auto area_width = (current_width > default_full_screen_width) ? current_width : default_full_screen_width;
                m_customPlot->move(10,10);

                 m_customPlot->setFixedSize(area_width, default_full_screen_height - 25);
                 //scrollArea->setGeometry(10,10,default_full_screen_width, default_full_screen_height);
            }
            else
            {
                  std::cout << default_scroll_width << ":" << default_scroll_height << std::endl;
                  std::cout << default_scroll_width << ":" << default_scroll_height << std::endl;

                scrollArea->setGeometry(x_pos,y_pos,default_scroll_width, default_scroll_height);
                m_customPlot->move(x_pos,y_pos);
                m_customPlot->setFixedSize(current_width, default_plot_height);

                is_show = true;
            }
            return is_show;
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
        Draw(QScrollArea *scrollArea, QString chart_name) : scrollArea(scrollArea),height(scrollArea->geometry().size().height()),
            width(scrollArea->geometry().size().width()), current_width(scrollArea->width()), name(chart_name)

        {
            m_customPlot = new QCustomPlot;
            m_customPlot->setFixedSize(width,height);

            m_bar = new QCPBars(m_customPlot->xAxis, m_customPlot->yAxis);
            scrollArea->setWidget(m_customPlot);
            scrollArea->setWidgetResizable(true);

            m_bar->setWidth(0.2);
            m_bar->setBrush(QColor("Blue"));
            m_customPlot->yAxis->setVisible(true);
            m_customPlot->xAxis->setVisible(true);
            m_customPlot->setBackground(QBrush(QColor("white")));
            m_bar->setAntialiased(false);
            m_customPlot->xAxis->setTickLabelRotation(60);
            m_customPlot->yAxis->setLabel(name);

            x_pos = scrollArea->x();
            y_pos = scrollArea->y();

            m_customPlot->setDisabled(true);
        }
    };
    Draw *areaDraw;
    Draw *intencityDraw;
    Draw *peakDraw;
    Draw *transitTimeDraw;
public:
    void displayArea(QVector<double> data = {});
    void displayPeak( QVector<double> data = {});
    void displayTransitTime(QVector<double> data ={});
    void displayIntencity( QVector<double> data = {});
    void processData(QSize mainwindow_size);
    void prepareShow(QSize mainwindow_size);
private:
    void draw_histogram(Draw *draw_histo, QVector<double> &data);
    void displayCounter(void);
public slots:
    void mouseWheel(QWheelEvent *event);
    void mouseDoubleClickEvent( QMouseEvent * e );
    void counterCheckBox(int status);
    void counterRst(void);
    void InstADCVal(void);
    void eventThreshold(void);
    void enableHisto(void);

};

#endif // HISTOGRAMS_H
