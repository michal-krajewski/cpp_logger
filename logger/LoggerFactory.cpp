//
// Created by Atreses on 21/03/2020.
//

#include "LoggerFactory.h"
#include "distribution/ConsoleLogDistributor.h"

Logger LoggerFactory::getLogger() {
    Logger logger;
    ILogDistributor *consoleLogDistributor = new ConsoleLogDistributor();
    logger.addDistributor(consoleLogDistributor);

    return logger;
}
