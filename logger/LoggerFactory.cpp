//
// Created by Atreses on 21/03/2020.
//

#include "LoggerFactory.h"
#include "distribution/ConsoleLogDistributor.h"
#include "distribution/FileLogDistributor.h"
#include "distribution/HttpLogDistributor.h"

Logger* LoggerFactory::getLogger() {
    static Logger *logger = Logger::getInstatnce();

    if (!logger->isConfigured()) {
        configureConsoleLogDistributor(logger);
        configureFileLogDistributor(logger);
        configureHttpLogDistributor(logger);
    }

    return logger;
}

void LoggerFactory::configureConsoleLogDistributor(Logger *logger) {
    auto *supportedTypes = new List<LogType>;
    supportedTypes->add(INFO);
    supportedTypes->add(WARN);

    logger->addDistributor(new ConsoleLogDistributor(supportedTypes));
}

void LoggerFactory::configureFileLogDistributor(Logger *logger) {
    auto *supportedTypes = new List<LogType>;
    supportedTypes->add(INFO);
    supportedTypes->add(DEBUG);

    logger->addDistributor(
            new FileLogDistributor(
                    supportedTypes,
                    "/Users/atreses/Documents/Uczelnia/pw/Cpp/logs/resources/log.txt"
            )
    );
}

void LoggerFactory::configureHttpLogDistributor(Logger *logger) {
    auto *supportedTypes = new List<LogType>;
    supportedTypes->add(WARN);
    supportedTypes->add(DEBUG);
    supportedTypes->add(ERROR);

    logger->addDistributor(
            new HttpLogDistributor(
                    supportedTypes,
                    "http://localhost:3000/test"
            )
    );
}
