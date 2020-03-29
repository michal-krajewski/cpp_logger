//
// Created by Atreses on 21/03/2020.
//

#include "LoggerConfigurer.h"
#include "distribution/ConsoleLogDistributor.h"
#include "distribution/FileLogDistributor.h"
#include "distribution/HttpLogDistributor.h"

void LoggerConfigurer::configureLogger() {
    configureConsoleLogDistributor();
    configureFileLogDistributor();
    configureHttpLogDistributor();
}

void LoggerConfigurer::configureConsoleLogDistributor() {
    auto distributorConfig = config()->getPropertyFor(CONSOLE_LOGGER);
    if (distributorConfig->isEnabled()) {
        Logger::getInstance().addDistributor(new ConsoleLogDistributor(distributorConfig->getSupportedTypes()));
    }
}

void LoggerConfigurer::configureFileLogDistributor() {
    auto distributorConfig = config()->getPropertyFor(FILE_LOGGER);
    if (distributorConfig->isEnabled()) {
        Logger::getInstance().addDistributor(
                new FileLogDistributor(
                        distributorConfig->getSupportedTypes(),
                        distributorConfig->getProperty(FILE_PATH)
                )
        );
    }
}

void LoggerConfigurer::configureHttpLogDistributor() {
    auto distributorConfig = config()->getPropertyFor(HTTP_LOGGER);
    if (distributorConfig->isEnabled()) {
        Logger::getInstance().addDistributor(
                new HttpLogDistributor(
                        distributorConfig->getSupportedTypes(),
                        distributorConfig->getProperty(URL)
                )
        );
    }
}

Config *LoggerConfigurer::config() {
    static Config loggerConfiguration = Config();
    return &loggerConfiguration;
}
