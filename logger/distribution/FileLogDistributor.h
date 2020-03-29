//
// Created by Atreses on 23/03/2020.
//

#ifndef LOGS_FILELOGDISTRIBUTOR_H
#define LOGS_FILELOGDISTRIBUTOR_H


#include "ILogDistributor.h"
#include <vector>

class FileLogDistributor : public ILogDistributor {
public:
    /// Returns information if provided message log type is supported by the Logger
    /// @param [in] message logType
    /// @return bool
    bool supports(LogType logType) override;

    /// Persists provided message in the configured log file
    /// @param pointer to message (ILogMessage implementation)
    void persistLog(ILogMessage *message) override;
    FileLogDistributor(List<LogType> *supportedTypes, string logFilePath);
    ~FileLogDistributor();
private:
    List<LogType> *supportedTypes;
    string logFilePath;
};


#endif //LOGS_FILELOGDISTRIBUTOR_H
