//
// Created by Atreses on 26/03/2020.
//

#ifndef LOGS_CONFIG_H
#define LOGS_CONFIG_H

#include <iostream>
#include "Property.h"

using namespace std;

enum LoggerType {CONSOLE_LOGGER, HTTP_LOGGER, FILE_LOGGER};

class Config {
public:
    Config();
    Property *getPropertyFor(LoggerType loggerType);
    ~Config();
private:
    List<Property*> *properties;
    static string getName(LoggerType loggerType);
};


#endif //LOGS_CONFIG_H
