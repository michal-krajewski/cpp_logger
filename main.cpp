#include "logger/LoggerFactory.h"

int main() {

    auto config = LoggerFactory::config();
    auto console = config.getPropertyFor(CONSOLE_LOGGER);
    console->enable();
    console->addSupport(INFO);

    auto http = config.getPropertyFor(HTTP_LOGGER);
    http->enable();
    http->addSupport(DEBUG);
    http->addSupport(INFO);
    http->setProperty(URL, "http://localhost:3000/test");

    Logger *logger = LoggerFactory::getLogger();

    logger->info("test info message");
    logger->debug("debug message");
    logger->warn("warn message");
    logger->error("error message");


    return 0;
}
