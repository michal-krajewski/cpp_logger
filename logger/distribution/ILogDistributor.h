//
// Created by Atreses on 22/03/2020.
//

#ifndef LOGS_ILOGDISTRIBUTOR_H
#define LOGS_ILOGDISTRIBUTOR_H

#include "../message/ILogMessage.h"
#include "../util/List.h"

class ILogDistributor {
public:

    /// Returns information if provided message log type is supported by the Logger
    /// @param [in] message logType
    /// @return bool
    virtual bool supports(LogType logType) = 0;

    /// Persists provided message - depends on specific implementation (save, send, print)
    /// @param [in] (*ILogMessage) message to persist
    virtual void persistLog(ILogMessage *message) = 0;
    virtual ~ILogDistributor() = default;
};


#endif //LOGS_ILOGDISTRIBUTOR_H
