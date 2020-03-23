//
// Created by Atreses on 23/03/2020.
//

#include "FileLogDistributor.h"
#include <fstream>
#include <utility>

using namespace std;

bool FileLogDistributor::supports(LogType logType) {
    for (auto it = supportedTypes->begin(); it != supportedTypes->end(); it++) {
        if (*it.base() == logType) {
            return true;
        }
    }
}

void FileLogDistributor::persistLog(ILogMessage *message) {
    ofstream logFile;

    logFile.open(this->logFilePath, ios_base::app);
    logFile << message->getMessage() << endl;
}

FileLogDistributor::FileLogDistributor(vector<LogType> *supportedTypes, string logFilePath) {
    this->supportedTypes = supportedTypes;
    this->logFilePath = std::move(logFilePath);
}
