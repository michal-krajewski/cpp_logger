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
    bool supports(LogType logType) override;
    void persistLog(ILogMessage *message) override;
    HttpLogDistributor(List<LogType> *supportedTypes, const string& url);
private:
    List<LogType> *supportedTypes;
    CURL *curl;
    string prepareJsonMessage(ILogMessage *message);
};


#endif //LOGS_HTTPLOGDISTRIBUTOR_H
