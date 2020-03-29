//
// Created by Atreses on 24/03/2020.
//

#ifndef LOGS_DATETIMELOGMESSAGE_H
#define LOGS_DATETIMELOGMESSAGE_H

#include "ILogMessage.h"
#include <iostream>

using namespace std;

class DateTimeLogMessage : public ILogMessage {
public:
    /// Returns formatted message prefixed with creation date as std::string
    /// @return std::string
    string getMessage() override;

    /// Returns type of the message
    /// @return LogType
    LogType getType() override;
    DateTimeLogMessage(string message, LogType messageType);
    ~DateTimeLogMessage() override;

private:
    string message;
    string loggedDate;
    LogType messageType;
};


#endif //LOGS_DATETIMELOGMESSAGE_H
