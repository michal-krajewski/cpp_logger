//
// Created by Atreses on 24/03/2020.
//

#include "HttpLogDistributor.h"
#include "../util/StringConverter.h"

bool HttpLogDistributor::supports(LogType logType) {
    return supportedTypes->contains(logType);
}

void HttpLogDistributor::persistLog(ILogMessage *message) {
    char* simpleMessage = StringConverter::convertToCharArray(prepareJsonMessage(message));
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, simpleMessage);
    curl_easy_perform(curl);

    delete[] simpleMessage;
}

HttpLogDistributor::HttpLogDistributor(List<LogType> *supportedTypes, const string& url) {
    this->curl = curl_easy_init();
    char* simpleUrl = StringConverter::convertToCharArray(url);
    curl_easy_setopt(curl, CURLOPT_URL, simpleUrl);

    this->supportedTypes = supportedTypes;

    delete[] simpleUrl;
}

string HttpLogDistributor::prepareJsonMessage(ILogMessage *message) {
    return R"({"message": ")" + message->getMessage() + "\"}";
}

HttpLogDistributor::~HttpLogDistributor() {
    delete this->supportedTypes;
    delete this->curl;
}
