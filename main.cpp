#include "logger/LoggerFactory.h"

using namespace std;

int main() {

    Logger logger = LoggerFactory::getLogger();

    logger.info("test info message");
    logger.debug("debug message");
    logger.warn("warn message");
    logger.error("error message");

    return 0;
}
