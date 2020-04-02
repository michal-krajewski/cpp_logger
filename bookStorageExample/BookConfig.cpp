//
// Created by Atreses on 29/03/2020.
//

#include "BookConfig.h"
#include "../logger/LoggerConfigurer.h"
#include "../logger/Logger.h"
#include "../logger/config/Config.h"
#include "../logger/config/Property.h"

void BookConfig::applyLoggerConfig() {
    auto config = LoggerConfigurer::config();
    auto console = config->getPropertyFor(CONSOLE_LOGGER);
    console->enable();
    console->addSupport(ERROR);

    auto http = config->getPropertyFor(HTTP_LOGGER);
    http->enable();
    http->addSupport(ERROR);
    http->addSupport(INFO);
    http->setProperty(URL, "http://localhost:3000/test");
    LoggerConfigurer::configureLogger();
}
