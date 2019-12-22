#ifndef SETTINGSIF_H
#define SETTINGSIF_H

#include <iostream>
#include <memory>

class settingsIF
{
public:
    typedef  std::shared_ptr <settingsIF> Ptr;
    settingsIF(){}

    virtual ~settingsIF(){}
};


#endif // SETTINGSIF_H
