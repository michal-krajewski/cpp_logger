//
// Created by Atreses on 21/03/2020.
//

#ifndef LOGS_ILOGMESSAGE_H
#define LOGS_ILOGMESSAGE_H

#include <iostream>

using namespace std;

enum LogType {INFO, ERROR, WARN, DEBUG};
static char *enumStrings[] = {"INFO", "ERROR", "WARN", "DEBUG"};

class ILogMessage {
public:
    /// Returns formatted message as std::string
    /// @return std::string
    virtual string getMessage() = 0;

    /// Returns type of the message
    /// @return LogType
    virtual LogType getType() = 0;
    virtual ~ILogMessage() = default;

protected:
    static string getTextForEnum(int enumValue) {
        return enumStrings[enumValue];
    };
};


#endif //LOGS_ILOGMESSAGE_H
