//
// Created by Atreses on 21/03/2020.
//

#ifndef LOGS_ILOGMESSAGE_H
#define LOGS_ILOGMESSAGE_H

#include <iostream>

using namespace std;

enum MessageType {INFO, ERROR, WARN, DEBUG};

class ILogMessage {
public:
    virtual string getMessage() = 0;
    virtual MessageType getType() = 0;
};


#endif //LOGS_ILOGMESSAGE_H
