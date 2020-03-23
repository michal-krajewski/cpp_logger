//
// Created by Atreses on 23/03/2020.
//

#ifndef LOGS_FILELOGDISTRIBUTOR_H
#define LOGS_FILELOGDISTRIBUTOR_H


#include "ILogDistributor.h"
#include <vector>

class FileLogDistributor : public ILogDistributor {
public:
    bool supports(LogType logType) override;
    void persistLog(ILogMessage *message) override;
    FileLogDistributor(vector<LogType> *supportedTypes, string logFilePath);
private:
    vector<LogType> *supportedTypes;
    string logFilePath;
};


#endif //LOGS_FILELOGDISTRIBUTOR_H