//
// Created by Atreses on 21/03/2020.
//

#include "RawLogMessage.h"

#include <utility>

RawLogMessage::RawLogMessage(string message, LogType messageType) {
    this->message = std::move(message);
    this->messageType = messageType;
}

string RawLogMessage::getMessage() {
    string fullMessage = "[" + ILogMessage::getTextForEnum(this->messageType) + "] " + this->message;
    return fullMessage;
}

LogType RawLogMessage::getType() {
    return this->messageType;
}

RawLogMessage::~RawLogMessage() {
    cout << "deleting RawLogMessage" << endl;
}
