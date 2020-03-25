//
// Created by Atreses on 21/03/2020.
//

#ifndef LOGS_LOGGERFACTORY_H
#define LOGS_LOGGERFACTORY_H

#include "Logger.h"

class LoggerFactory {
public:
    static Logger* getLogger();

private:
    static void configureConsoleLogDistributor(Logger *logger);
    static void configureFileLogDistributor(Logger *logger);
    static void configureHttpLogDistributor(Logger *logger);
};


#endif //LOGS_LOGGERFACTORY_H
