//
// Created by Atreses on 21/03/2020.
//

#include "LoggerFactory.h"
#include "distribution/ConsoleLogDistributor.h"
#include "distribution/FileLogDistributor.h"
#include "distribution/HttpLogDistributor.h"

Logger LoggerFactory::getLogger() {
    auto *supportedTypes = new vector<LogType>;
    supportedTypes->push_back(INFO);
    supportedTypes->push_back(WARN);

    Logger logger;
    logger.addDistributor(new ConsoleLogDistributor(supportedTypes));

    auto *supportedFileLogDistributorTypes = new vector<LogType>;
    supportedFileLogDistributorTypes->push_back(INFO);
    supportedFileLogDistributorTypes->push_back(DEBUG);

    logger.addDistributor(
            new FileLogDistributor(
                    supportedFileLogDistributorTypes,
                    "/Users/atreses/Documents/Uczelnia/pw/Cpp/logs/resources/log.txt"
            )
    );

    auto *supportedHttpLogDistributorTypes = new vector<LogType>;
    supportedFileLogDistributorTypes->push_back(INFO);
    supportedFileLogDistributorTypes->push_back(ERROR);


    logger.addDistributor(
            new HttpLogDistributor(
                    supportedFileLogDistributorTypes,
                    "http://localhost:3000/test"
            )
    );

    return logger;
}
