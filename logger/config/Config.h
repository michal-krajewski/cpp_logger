//
// Created by Atreses on 26/03/2020.
//

#ifndef LOGS_CONFIG_H
#define LOGS_CONFIG_H

#include <iostream>
#include "Property.h"
#include "../Logger.h"

using namespace std;

class Config {
public:
    Config();

    /// Returns available in the system properties for given logger type
    /// @param [in] loggerType for which configured properties are being requested
    /// @return pointer to Property for requested logger type
    Property *getPropertyFor(LoggerType loggerType);

    ~Config();
private:
    List<Property*> *properties;
    static string getName(LoggerType loggerType);
};


#endif //LOGS_CONFIG_H
