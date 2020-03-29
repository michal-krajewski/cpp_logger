//
// Created by Atreses on 22/03/2020.
//

#ifndef LOGS_CONSOLELOGDISTRIBUTOR_H
#define LOGS_CONSOLELOGDISTRIBUTOR_H

#include "ILogDistributor.h"
#include <vector>

class ConsoleLogDistributor : public ILogDistributor {
public:

    /// Returns information if provided message log type is supported by the Logger
    /// @param [in] message logType
    /// @return bool
    bool supports(LogType logType) override;

    /// Prints provided message into the console
    /// @param pointer to message (ILogMessage implementation)
    void persistLog(ILogMessage *message) override;
    ConsoleLogDistributor(List<LogType> *supportedTypes);
    ~ConsoleLogDistributor();
private:
    List<LogType> *supportedTypes;
};


#endif //LOGS_CONSOLELOGDISTRIBUTOR_H
