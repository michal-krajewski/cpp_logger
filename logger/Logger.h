//
// Created by Atreses on 21/03/2020.
//

#ifndef LOGS_LOGGER_H
#define LOGS_LOGGER_H

#include <iostream>

#include "message/ILogMessage.h"
#include "message/RawLogMessage.h"

using namespace std;


class Logger {
public:
    void info(string message);

private:
    void log(ILogMessage *message);
};


#endif //LOGS_LOGGER_H
