//
// Created by Atreses on 26/03/2020.
//

#ifndef LOGS_PROPERTY_H
#define LOGS_PROPERTY_H

#include <iostream>
#include <map>
#include "../util/List.h"
#include "../message/ILogMessage.h"

using namespace std;

enum AdditionalProperty {URL, FILE_PATH};

class Property {
public:
    Property(string name);
    ~Property();

    string getName();
    bool isEnabled();
    List<LogType> *getSupportedTypes();
    void addSupport(LogType logType);
    void enable();
    void setProperty(AdditionalProperty additionalProperty, string value);
    string getProperty(AdditionalProperty property);
private:
    string name;
    bool enabled;
    List<LogType> *supportedTypes;
    map<AdditionalProperty, string> additionalProperties;
};


#endif //LOGS_PROPERTY_H
