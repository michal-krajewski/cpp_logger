//
// Created by Atreses on 21/03/2020.
//

#ifndef LOGS_LOGGER_H
#define LOGS_LOGGER_H

#include <iostream>
#include <vector>

#include "message/ILogMessage.h"
#include "distribution/ILogDistributor.h"

using namespace std;


class Logger {
public:
    static Logger *getInstance();
    void addDistributor(ILogDistributor *distributor);
    void info(string message);
    void debug(string message);
    void error(string message);
    void warn(string message);
    bool isConfigured();
private:
    Logger();
    bool configured;
    void log(ILogMessage *message);
    vector<ILogDistributor*> distributors;
    ILogMessage* prepareMessage(string message, LogType type);
};


#endif //LOGS_LOGGER_H
