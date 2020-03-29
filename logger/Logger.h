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

enum LoggerType {CONSOLE_LOGGER, HTTP_LOGGER, FILE_LOGGER};

class Logger {
public:
    /// Returns instance of Logger
    /// @return Logger
    static Logger &getInstance();

    /// Adds additional LogDistributor to Logger, changes logger status to configured
    /// @param pointer to ILogDistributor
    void addDistributor(ILogDistributor *distributor);

    /// Logs provided message as INFO in all available distributors for INFO type
    /// @param message to log
    void info(string message);

    /// Logs provided message as DEBUG in all available distributors for DEBUG type
    /// @param message to log
    void debug(string message);

    /// Logs provided message as ERROR in all available distributors for ERROR type
    /// @param message to log
    void error(string message);

    /// Logs provided message as WARN in all available distributors for WARN type
    /// @param message to log
    void warn(string message);

    /// Returns information if logger was configured - has at least one distributor added
    /// @return bool
    bool isConfigured();
private:
    Logger();
    ~Logger();
    Logger& operator=(const Logger&);
    Logger(const Logger&);
    bool configured;
    void log(ILogMessage *message);
    vector<ILogDistributor*> distributors;
    ILogMessage* prepareMessage(string message, LogType type);
};


#endif //LOGS_LOGGER_H
