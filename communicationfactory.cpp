#include "communicationfactory.h"
#include "usbcommunication.h"
#include "serialcommunication.h"
#include <memory>
#include <iostream>
#include "logger.h"
CommunicationIF::Ptr CommunicationFactory::create(CommunicationDevices device)
{
    CommunicationIF::Ptr retPtr = nullptr;
    switch(device)
    {
    default:
          std::cout << "Requested Device Not available" << std::endl;
          break;
    case CommunicationDevices::COMM_USB:
         retPtr = std::make_shared <USBCommunication>();
        break;
    case CommunicationDevices::COMM_SERIAL:
        retPtr = std::make_shared <serialCommunication>();
         break;
    case CommunicationDevices::COMM_MAX_DEVICE:
         std::cout << "Requested Device Not available" << std::endl;
         break;

    }
    return (retPtr);
}
