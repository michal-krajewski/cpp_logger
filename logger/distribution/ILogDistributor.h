//
// Created by Atreses on 22/03/2020.
//

#ifndef LOGS_ILOGDISTRIBUTOR_H
#define LOGS_ILOGDISTRIBUTOR_H

#include "../message/ILogMessage.h"

class ILogDistributor {
public:
    virtual bool supports(LogType logType) = 0;
    virtual void persistLog(ILogMessage *message) = 0;
};


#endif //LOGS_ILOGDISTRIBUTOR_H
