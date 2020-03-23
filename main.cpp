#include "logger/LoggerFactory.h"

#include "logger/distribution/ConsoleLogDistributor.h"
#include "logger/message/ILogMessage.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {

    Logger logger = LoggerFactory::getLogger();

    logger.info("test info message");
    logger.debug("debug message");
    logger.warn("warn message");
    logger.error("error message");


//    auto *types = new vector<LogType>;
//    types->push_back(INFO);
//    types->push_back(WARN);
//    ConsoleLogDistributor *consoleLogDistributor = new ConsoleLogDistributor(types);
//
//    cout << consoleLogDistributor->supports(WARN) << endl;

    return 0;
}
