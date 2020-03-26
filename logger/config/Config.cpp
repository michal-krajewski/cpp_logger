//
// Created by Atreses on 26/03/2020.
//

//#include <mach-o/dyld.h>

#include <vector>
#include "Config.h"

Config::Config() {
    cout << "creating new config" << endl;
    this->properties = new List<Property*>();
    properties->add(new Property(getName(CONSOLE_LOGGER)));
    properties->add(new Property(getName(HTTP_LOGGER)));
    properties->add(new Property(getName(FILE_LOGGER)));
}

string Config::getName(LoggerType loggerType) {
    if (loggerType == HTTP_LOGGER) {
        return "HTTP_LOGGER";
    }
    if (loggerType == CONSOLE_LOGGER) {
        return "CONSOLE_LOGGER";
    }
    if (loggerType == FILE_LOGGER) {
        return "FILE_LOGGER";
    }
}

Property* Config::getPropertyFor(LoggerType loggerType) {
    string requestedType = getName(loggerType);
    for (int i = 0; i < properties->size(); ++i) {
        if (properties->get(i)->getName() == requestedType) {
            return properties->get(i);
        }
    }
    return nullptr;
}

Config::~Config() {
    cout << "deleting config (general message)" << endl;
    for (int i = 0; i < this->properties->size(); ++i) {
        cout << "deleting property " << endl;
        delete this->properties->get(i);
    }
    if (this->properties) {
        cout << "deleting properties as list " << endl;
        delete this->properties;
    }
}

//string Config::defaultPropertyFilePath() {
//    char path[1024];
//    uint32_t size = sizeof(path);
//    _NSGetExecutablePath(path, &size);
//
//    string propertyFilePath = StringConverter::convertToCharArray(path);
//
//    return propertyFilePath + "/config/configuration.properties";
//}
