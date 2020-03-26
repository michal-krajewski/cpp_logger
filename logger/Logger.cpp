//
// Created by Atreses on 21/03/2020.
//

#include "Logger.h"

#include <utility>
#include "message/DateTimeLogMessage.h"
#include "LoggerConfigurer.h"

Logger& Logger::getInstance() {
    static Logger logger;

    return logger;
}

Logger::Logger() {
    this->configured = false;
}

void Logger::info(string message) {
    ILogMessage *msg = this->prepareMessage(std::move(message), INFO);
    log(msg);
}

void Logger::debug(string message) {
    ILogMessage *msg = this->prepareMessage(std::move(message), DEBUG);
    log(msg);
}

void Logger::error(string message) {
    ILogMessage *msg = this->prepareMessage(std::move(message), ERROR);
    log(msg);
}

void Logger::warn(string message) {
    ILogMessage *msg = this->prepareMessage(std::move(message), WARN);
    log(msg);
}

void Logger::log(ILogMessage *message) {
    for_each(distributors.begin(), distributors.end(), [&message](ILogDistributor *dist) {
        if (dist->supports(message->getType())) {
            dist->persistLog(message);
        }
    });
    delete message;
}

void Logger::addDistributor(ILogDistributor *distributor) {
    this->distributors.push_back(distributor);
    this->configured = true;
}

ILogMessage *Logger::prepareMessage(string message, LogType type) {
    return new DateTimeLogMessage(std::move(message), type);
}

bool Logger::isConfigured() {
    return configured;
}

Logger::~Logger() = default;
