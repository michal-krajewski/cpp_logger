//
// Created by Atreses on 21/03/2020.
//

#include "Logger.h"


void Logger::info(string message) {
    ILogMessage *msg = new RawLogMessage(message, INFO);
    log(msg); //TODO: fix memory leak?
}

void Logger::log(ILogMessage *message) {
    cout << "Logger: [" << message->getType() << "] " << message->getMessage() << endl; //TODO: create getType toString method
}
