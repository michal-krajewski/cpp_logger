//
// Created by Atreses on 24/03/2020.
//

#include "DateTimeLogMessage.h"

#include <utility>
#include "../util/DateTime.h"

string DateTimeLogMessage::getMessage() {
    string fullMessage = "[" + ILogMessage::getTextForEnum(this->messageType) + "] " +
            "[" + this->loggedDate + "] "
            + this->message;
    return fullMessage;
}

LogType DateTimeLogMessage::getType() {
    return this->messageType;
}

DateTimeLogMessage::DateTimeLogMessage(string message, LogType messageType) {
    this->message = std::move(message);
    this->loggedDate = DateTime::now();
    this->messageType = messageType;
}
