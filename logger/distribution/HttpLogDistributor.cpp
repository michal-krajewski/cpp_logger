//
// Created by Atreses on 24/03/2020.
//

#include "HttpLogDistributor.h"

bool HttpLogDistributor::supports(LogType logType) {
    for (auto it = supportedTypes->begin(); it != supportedTypes->end(); it++) {
        if (*it.base() == logType) {
            return true;
        }
    }
}

void HttpLogDistributor::persistLog(ILogMessage *message) {
    char* simpleMessage = asCharArray(prepareJsonMessage(message));
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, simpleMessage);
    curl_easy_perform(curl);

    delete[] simpleMessage;
}

HttpLogDistributor::HttpLogDistributor(vector<LogType> *supportedTypes, string url) {
    this->curl = curl_easy_init();
    char* simpleUrl = asCharArray(std::move(url));
    curl_easy_setopt(curl, CURLOPT_URL, simpleUrl);

    this->supportedTypes = supportedTypes;

    delete[] simpleUrl;
}

string HttpLogDistributor::prepareJsonMessage(ILogMessage *message) {
    return R"({"message": ")" + message->getMessage() + "\"}";
}

char *HttpLogDistributor::asCharArray(string value) {
    char *charArray = new char[value.size() + 1]();
    strcpy(charArray, value.c_str());
    return charArray;
}
