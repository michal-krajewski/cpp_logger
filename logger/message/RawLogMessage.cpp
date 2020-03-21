//
// Created by Atreses on 21/03/2020.
//

#include "RawLogMessage.h"

#include <utility>

RawLogMessage::RawLogMessage(string message, MessageType messageType) {
    this->message = std::move(message);
    this->messageType = messageType;
}

string RawLogMessage::getMessage() {
    return this->message;
}

MessageType RawLogMessage::getType() {
    return this->messageType;
}
