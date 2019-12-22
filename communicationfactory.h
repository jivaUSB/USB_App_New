#ifndef COMMUNICATIONFACTORY_H
#define COMMUNICATIONFACTORY_H

#include "communicationif.h"

class CommunicationFactory
{
public:

    CommunicationFactory() = default;

    ~CommunicationFactory() = default;

    static CommunicationIF::Ptr create(CommunicationDevices device = CommunicationDevices::COMM_USB);

};

#endif // COMMUNICATIONFACTORY_H
