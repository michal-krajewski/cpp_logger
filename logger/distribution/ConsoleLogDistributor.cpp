//
// Created by Atreses on 22/03/2020.
//

#include "ConsoleLogDistributor.h"

#include <iostream>

using namespace std;

bool ConsoleLogDistributor::supports(LogType logType) {
    for (auto it = supportedTypes->begin(); it != supportedTypes->end(); it++) {
        if (*it.base() == logType) {
            return true;
        }
    }
}

void ConsoleLogDistributor::persistLog(ILogMessage *message) {
    cout << message->getMessage() << endl;
}

ConsoleLogDistributor::ConsoleLogDistributor(vector<LogType> *supportedTypes) {
    this->supportedTypes = supportedTypes;
}

