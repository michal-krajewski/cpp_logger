//
// Created by Atreses on 21/03/2020.
//

#ifndef LOGS_RAWLOGMESSAGE_H
#define LOGS_RAWLOGMESSAGE_H


#include "ILogMessage.h"
#include <iostream>

using namespace std;

class RawLogMessage : public ILogMessage {
public:
    /// Returns formatted message as std::string
    /// @return std::string
    string getMessage() override;

    /// Returns type of the message
    /// @return LogType
    LogType getType() override;
    RawLogMessage(string message, LogType messageType);
    ~RawLogMessage() override;

private:
    string message;
    LogType messageType;
};


#endif //LOGS_RAWLOGMESSAGE_H
