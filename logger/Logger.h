//
// Created by Atreses on 21/03/2020.
//

#ifndef LOGS_LOGGER_H
#define LOGS_LOGGER_H

#include <iostream>
#include <vector>

#include "message/ILogMessage.h"
#include "message/RawLogMessage.h"
#include "distribution/ILogDistributor.h"

using namespace std;


class Logger {
public:
    Logger();
    void addDistributor(ILogDistributor *distributor);
    void info(string message);

private:
    void log(ILogMessage *message);
    vector<ILogDistributor*> distributors;
};


#endif //LOGS_LOGGER_H
