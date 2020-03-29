#include "logger/LoggerConfigurer.h"

int run() {

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

    Logger::getInstance().info("test");
    Logger::getInstance().error("test");

    return 0;
}

