#include <iostream>
#include "LoggerFactory.h"

int main() {

    Logger logger = LoggerFactory::getLogger();

    logger.logMessage("test massage");

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
