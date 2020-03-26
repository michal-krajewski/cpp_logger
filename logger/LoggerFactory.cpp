//
// Created by Atreses on 21/03/2020.
//

#include "LoggerFactory.h"
#include "distribution/ConsoleLogDistributor.h"
#include "distribution/FileLogDistributor.h"
#include "distribution/HttpLogDistributor.h"

Logger* LoggerFactory::getLogger() {
    static Logger *logger = Logger::getInstance();

    if (!logger->isConfigured()) {
        configureConsoleLogDistributor(logger);
        configureFileLogDistributor(logger);
        configureHttpLogDistributor(logger);
    }

    return logger;
}

void LoggerFactory::configureConsoleLogDistributor(Logger *logger) {
    auto distributorConfig = config().getPropertyFor(CONSOLE_LOGGER);
    if (distributorConfig->isEnabled()) {
        logger->addDistributor(new ConsoleLogDistributor(distributorConfig->getSupportedTypes()));
    }
}

void LoggerFactory::configureFileLogDistributor(Logger *logger) {
    auto distributorConfig = config().getPropertyFor(FILE_LOGGER);
    if (distributorConfig->isEnabled()) {
        logger->addDistributor(
                new FileLogDistributor(
                        distributorConfig->getSupportedTypes(),
                        distributorConfig->getProperty(FILE_PATH)
                )
        );
    }
}

void LoggerFactory::configureHttpLogDistributor(Logger *logger) {
    auto distributorConfig = config().getPropertyFor(HTTP_LOGGER);
    if (distributorConfig->isEnabled()) {
        logger->addDistributor(
                new HttpLogDistributor(
                        distributorConfig->getSupportedTypes(),
                        distributorConfig->getProperty(URL)
                )
        );
    }
}

Config LoggerFactory::config() {
    static Config loggerConfiguration = Config();
    return loggerConfiguration;
}
