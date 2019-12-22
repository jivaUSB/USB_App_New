#include "usbcommunication.h"
#include "DRV_DriverInterface.h"
#include <iostream>
#include <memory>
#include <list>
#include <chrono>
#include <logger.h>
#include <memory>
USBCommunication::USBCommunication()
{
   bufferNum = m_DataCounter = 0;
   m_stopParseThread = false;
   //m_stopParseThread = true;
}

USBCommunication::~USBCommunication()
{
    if(m_device)
    {
        m_device->Cleanup();
    }
}

void USBCommunication::registerForDisconnect(closeCallback_t callback)
{
    m_closeCallback = callback;
}

bool USBCommunication::Initialization(void)
{
    logger::getInstance()->log("USB Init ...");

    m_usb_settings = std::static_pointer_cast<settings_usb>(m_settings->getDeviceSettings(USB));

    if(!m_device)
    {
        m_device = std::make_shared<CDriverInterface>();
        unsigned char key[strlen(DEFAULT_VALUE_OPENBY_SERIAL)] = {0};
        memcpy(key,m_usb_settings->getOpenKey().data(), m_usb_settings->getOpenKey().size());
        m_isRunning = m_device->Initialize(m_usb_settings->getOpenType(), static_cast<void *>(key));

        uint8_t numReadEP = 1;
        uint8_t numWriteEP = 0;
        uint8_t readEP[4] = {0x82};
        uint8_t writeEP[4] = {0};
        //m_isRunning = true;//HG
        if(m_isRunning)
        {
            m_isRunning = m_device->GetEP(&numReadEP, &numWriteEP, readEP, writeEP);
            if(m_isRunning)
            {
                for(int i = 0;i < numReadEP;i++)
                {
                    if(readEP[i] == 0x82)
                    {
                        if(readThr)
                        {
                            logger::getInstance()->log("Stop Running Thread");
                            readThr->join();
                            readThr.reset();
                        }
                        logger::getInstance()->log("Starting Read Thread");
                        auto ptr = new USB_read_meta_data();
                        ptr->endPoint = readEP[i];
                        m_ptrReadMetaData.push_back(ptr);
                        readThr = std::make_shared<std::thread>(std::bind(&USBCommunication::readData, this, ptr));
                        readThr->detach();
                        m_stopParseThread = true;

                    }
                }

            }
        }
    }
    else {
        //cv.notify_all();
        m_stopParseThread = true;
    }

    if(m_stopParseThread == true && m_isRunning == true)
    {
        m_stopParseThread = false;
        logger::getInstance()->log("Starting Parser Thread");
        parseThread = std::make_shared<std::thread>(std::bind(&USBCommunication::ParseData, this));
        m_ProcessedData = 0;
        bufferContainer.clear();
    }

    QString str = (m_isRunning) ? "USB Init Success": "USB Init failed";
    logger::getInstance()->log("%s", str.toStdString().c_str());
    return m_isRunning;
}

void USBCommunication::ParseData()
{
    logger::getInstance()->log("Parsing Thread Enter");
    std::vector <uint8_t> ChannelData;

    while(m_stopParseThread == false)
    {
        if(bufferContainer.empty() == true)
        {

            std::unique_lock<std::mutex> lck(cv_mtx);
            cv.wait(lck);
        }
        else
        {
            std::shared_ptr<std::vector<uint8_t> > data = bufferContainer.front();
            bufferContainer.pop_front();
            do
            {

                ChannelData.clear();
                if(data->size() >= 4)
                {

                    uint8_t tag = *data->begin();
                    uint8_t channel = *(data->begin() + 1);
                    uint16_t len = *(data->begin() + 2);
                    len = (len << 8)  | *(data->begin() + 3);

                    data->erase(data->begin(), data->begin() + 4);

                    //std::cout << "len : " << len << " data_size : " << data->size() << " Channel : "  <<
                                  //channel << " tag : " << tag << std::endl;

                    if((tag == 0x53) && (channel >= 1) && (channel <= 4) && (len <= data->size()))
                    {
                        //ChannelData.push_back(channel);
                        ChannelData.insert(ChannelData.end(), data->begin(), data->begin() + len);
                        data->erase(data->begin(), data->begin() + len);

                        if(data->size() >= 2)
                        {

                            uint16_t footer = *data->begin();
                            footer = (footer << 8) | *(data->begin() + 1);
                            if(footer == 0xffff)
                            {
                                 m_dataCallback(this->shared_from_this(), ChannelData, channel);
                                 data->erase(data->begin(), data->begin() + 2);
                                 continue;
                            }
                        }
                    }
                }
                data->clear();
            }
            while(data->size());
        }
    }
    logger::getInstance()->log("Parsing Thread Exit");
}
#include "shape.h"
void USBCommunication::readData(read_metaData *read_data)
{
    USB_read_meta_data *ptr_data = dynamic_cast<USB_read_meta_data *>(read_data);
    logger::getInstance()->log("Start read thread...");
    const uint32_t packetSize = m_usb_settings->getPacketSize() * 1024;
    std::vector<std::vector<uint8_t>> acBuf;
    acBuf.resize(m_usb_settings->getBufferSize());
    std::for_each(acBuf.begin(), acBuf.end(),[packetSize]( std::vector<uint8_t> &item){item.resize(packetSize);});


#if 0

    std::vector<uint64_t> actualBytesRead(m_usb_settings->getBufferSize(), 1024*16);
    auto bufferSize = 1;
    int k = 1000;
    while(1)
    {
        for (int i = 0; i < bufferSize;i++)
        {
            auto vec = std::make_shared< std::vector<uint8_t> >((1024*16));
            std::copy((const char *)&(dummyBuff[0]), (const char *)&(dummyBuff[actualBytesRead[i]]), vec->data() );
            bufferContainer.push_back(vec);
            cv.notify_all();
            Sleep(10);
        }
        k--;
        if(!k)
        {
            std::cout << "stop" << std::endl;
            m_closeCallback(this->shared_from_this());

            std::unique_lock<std::mutex> lck(cv_mtx);
            cv.wait(lck);
            k = 1000;
        }
    }



#endif
#if 1
     std::vector<uint64_t> actualBytesRead(m_usb_settings->getBufferSize(), 0);
    FT_STATUS ftStatus = FT_OTHER_ERROR;
    std::vector<OVERLAPPED> oOverlapped(m_usb_settings->getBufferSize(), {0});
    try
    {
        int i = 0;

        for(i = 0;i < m_usb_settings->getBufferSize();++i)
        {
            if ( m_device->InitializeOverlapped(&oOverlapped[i])  == false)
            {
                throw ftStatus;
            }
        }

        if( m_device->StartStreamPipe(ptr_data->endPoint, packetSize) == false)
        {
            throw ftStatus;
        }

        for(i = 0; i < m_usb_settings->getBufferSize();++i)
        {
            ftStatus = m_device->ReadPipeEx(ptr_data->endPoint, acBuf[i].data(), packetSize, (unsigned long *)&actualBytesRead[i], &oOverlapped[i]);
            if(ftStatus != FT_IO_PENDING)
            {
                throw ftStatus;
            }
        }

        i = 0;
        // Infinite transfer loop
        while (m_isRunning)
        {
            // Wait for transfer to finish
            ftStatus = m_device->GetOverlappedResult(&oOverlapped[i], (unsigned long *)&actualBytesRead[i], TRUE);
            if(FT_FAILED(ftStatus))
            {
                throw ftStatus;
            }


            if(m_stopParseThread == false)
            {
                auto vec = std::make_shared< std::vector<uint8_t> >(actualBytesRead[i]);
                std::copy((const char *)acBuf[i].data(), (const char *)&(acBuf[i][actualBytesRead[i]]), vec->data() );
                bufferContainer.push_back(vec);
                cv.notify_all();
            }

            m_DataCounter += actualBytesRead[i];
            m_ProcessedData += actualBytesRead[i];

            actualBytesRead[i] = 0;

            // Re-submit to keep request full
            ftStatus = m_device->ReadPipeEx(ptr_data->endPoint, acBuf[i].data(), packetSize, (unsigned long *)&actualBytesRead[i], &oOverlapped[i]);
            if(ftStatus != FT_IO_PENDING)
            {
                throw ftStatus;
            }

            // Roll-over
            if (++i >= m_usb_settings->getBufferSize()) i = 0;


            if((m_usb_settings->getReadLimit()) && (m_ProcessedData >= m_usb_settings->getReadLimit()) && m_stopParseThread == false )
            {
                m_stopParseThread = true;
                cv.notify_all();
                parseThread->join();
                parseThread.reset();
                m_closeCallback(this->shared_from_this());

                //std::unique_lock<std::mutex> lck(cv_mtx);
                //cv.wait(lck);
            }
        }
    }
    catch(...)
    {
        m_isRunning = false;
        std::cout << "Error : Exception Received in Read::: FT_STATUS-" << ftStatus << std::endl;
    }

    m_device->StopStreamPipe(ptr_data->endPoint);
    for(int i = 0;i < m_usb_settings->getBufferSize();++i)
    {
        m_device->ReleaseOverlapped(&oOverlapped[i]);
    }
    m_DataCounter = 0;
    m_device->AbortPipe(ptr_data->endPoint);

#endif
    logger::getInstance()->log("Reading Thread End");
}

void USBCommunication::writeData(std::vector<uint8_t> data)
{
}

void USBCommunication::clean(bool isInternal)
{
    logger::getInstance()->log("Clean Enter");
    m_stopParseThread = true;
    cv.notify_all();
    parseThread->join();
    parseThread.reset();
    bufferContainer.clear();
}

uint64_t USBCommunication::getTransferedByte(void)
{
    uint64_t ret = m_DataCounter;
    m_DataCounter = 0;
    return ret;
}

void USBCommunication::registerForData(dataCallback_t callback)
{
    m_dataCallback = callback;
    logger::getInstance()->log("Callback Registered");
}

void USBCommunication::setSettingIntf(SettingsPtr settingsIntf)
{
    m_settings = settingsIntf;
}
