//
// Created by Atreses on 21/03/2020.
//

#include "LoggerFactory.h"
#include "distribution/ConsoleLogDistributor.h"

Logger LoggerFactory::getLogger() {
    auto *supportedTypes = new vector<LogType>;
    supportedTypes->push_back(INFO);
    supportedTypes->push_back(WARN);

    Logger logger;
    logger.addDistributor(new ConsoleLogDistributor(supportedTypes));

    return logger;
}
