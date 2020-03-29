//
// Created by Atreses on 22/03/2020.
//

#include "ConsoleLogDistributor.h"

#include <iostream>

using namespace std;

bool ConsoleLogDistributor::supports(LogType logType) {
    return supportedTypes->contains(logType);
}

void ConsoleLogDistributor::persistLog(ILogMessage *message) {
    cout << message->getMessage() << endl;
}

ConsoleLogDistributor::ConsoleLogDistributor(List<LogType> *supportedTypes) {
    this->supportedTypes = supportedTypes;
}

ConsoleLogDistributor::~ConsoleLogDistributor() {
    delete this->supportedTypes;
}

