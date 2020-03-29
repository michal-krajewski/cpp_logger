//
// Created by Atreses on 21/03/2020.
//

#ifndef LOGS_LOGGERCONFIGURER_H
#define LOGS_LOGGERCONFIGURER_H

#include "Logger.h"
#include "config/Config.h"


class LoggerConfigurer {
public:
    static Config* config();
    static void configureLogger();
private:
    static void configureConsoleLogDistributor();
    static void configureFileLogDistributor();
    static void configureHttpLogDistributor();
};


#endif //LOGS_LOGGERCONFIGURER_H
