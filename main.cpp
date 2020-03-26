#include "logger/LoggerConfigurer.h"

int main() {

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

    cout << "That's all folks!" << endl;

    return 0;
}


//TODO: Documentation
//TODO: All strings as pointers
//TODO: [Optional] LoggerWithClass facade