
#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <stdarg.h>
#include <iostream>
#include <memory.h>
#include <thread>
#include <mutex>
#include <QString>
#include <QFile>
#include <QTextEdit>

class logger
{
    std::mutex m_mutex;
    static logger *m_instant;
    QFile logFile;
    QTextEdit *m_logger_window;
    logger();
    ~logger();
    logger(const logger &) = delete;
    logger& operator = (const  logger &) = delete;
public:
    static logger* getInstance(void);

    void setLoggerWindow(QTextEdit *txt);
    void log(std::string str,...);
};

#endif
