//
// Created by Atreses on 22/03/2020.
//

#ifndef LOGS_CONSOLELOGDISTRIBUTOR_H
#define LOGS_CONSOLELOGDISTRIBUTOR_H

#include "ILogDistributor.h"

class ConsoleLogDistributor : public ILogDistributor {
public:
    bool supports(LogType logType) override;
    void persistLog(ILogMessage *message) override;
//    ConsoleLogDistributor(LogType *supportedTypes);
//private:
//    LogType *supportedTypes;
};


#endif //LOGS_CONSOLELOGDISTRIBUTOR_H
