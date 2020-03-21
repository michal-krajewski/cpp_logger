#include <iostream>
#include "logger/LoggerFactory.h"

int main() {

    Logger logger = LoggerFactory::getLogger();

    logger.info("test info message");

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
