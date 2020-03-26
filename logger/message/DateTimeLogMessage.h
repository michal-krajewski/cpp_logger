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
    string getMessage() override;
    LogType getType() override;
    DateTimeLogMessage(string message, LogType messageType);
    ~DateTimeLogMessage() override;

private:
    string message;
    string loggedDate;
    LogType messageType;
};


#endif //LOGS_DATETIMELOGMESSAGE_H
