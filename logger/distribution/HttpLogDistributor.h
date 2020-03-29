//
// Created by Atreses on 24/03/2020.
//

#ifndef LOGS_HTTPLOGDISTRIBUTOR_H
#define LOGS_HTTPLOGDISTRIBUTOR_H

#include "ILogDistributor.h"
#include <vector>
#include <curl/curl.h>

class HttpLogDistributor : public ILogDistributor {
public:

    /// Returns information if provided message log type is supported by the Logger
    /// @param [in] message logType
    /// @return bool
    bool supports(LogType logType) override;

    /// Sends provided message via POST method to the configured address
    /// @param pointer to message (ILogMessage implementation)
    void persistLog(ILogMessage *message) override;
    HttpLogDistributor(List<LogType> *supportedTypes, const string& url);
    ~HttpLogDistributor();
private:
    List<LogType> *supportedTypes;
    CURL *curl;
    string prepareJsonMessage(ILogMessage *message);
};


#endif //LOGS_HTTPLOGDISTRIBUTOR_H
