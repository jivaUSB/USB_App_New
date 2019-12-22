#include "logger.h"
#include <string>
#include <sstream>

logger * logger::m_instant = nullptr;

logger::logger() : logFile("App.log")
{
    logFile.open(QIODevice::ReadWrite);
}

logger::~logger()
{
    logFile.close();
}

logger *logger::getInstance()
{
    if(m_instant == nullptr)
    {
        m_instant = new logger();
    }

    return m_instant;
}

void logger::setLoggerWindow(QTextEdit *txt)
{
    m_logger_window = txt;
}

void logger::log(std::string str,...)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    va_list arg;
    va_start(arg, str.data() );
    std::stringstream ss;

    auto find_pos = str.find_first_of("%");

    while(find_pos != std::string::npos)
    {
        ss << str.substr(0,find_pos);

        if(str[find_pos + 1] == 'd')
            ss << va_arg(arg,int);
        else if(str[find_pos + 1] == 'c')
            ss << (char)va_arg(arg,int);
        else if(str[find_pos + 1] == 's')
            ss << va_arg(arg,char *);
        else if(str[find_pos + 1] == 'f')
            ss << va_arg(arg,double);
        else if(str[find_pos + 1] == 'p' || str[find_pos + 1] == 'x')
            ss << std::hex << va_arg(arg,int);

        ss << std::dec;
        find_pos+=2;
        str.erase(0, find_pos);
        find_pos = str.find_first_of("%");
    }
    va_end(arg);
    ss << str;
    m_logger_window->append(QString::fromUtf8(ss.str().c_str()));
}

