//
// Created by Atreses on 21/03/2020.
//

#include "Logger.h"

Logger::Logger() {

}

void Logger::info(string message) {
    ILogMessage *msg = new RawLogMessage(message, INFO);
    log(msg); //TODO: fix memory leak?
}

void Logger::log(ILogMessage *message) {
    for_each(distributors.begin(), distributors.end(), [&message](ILogDistributor *dist) {
        if (dist->supports(message->getType())) {
            dist->persistLog(message);
        }
    });
}

void Logger::addDistributor(ILogDistributor *distributor) {
    this->distributors.push_back(distributor);
}
