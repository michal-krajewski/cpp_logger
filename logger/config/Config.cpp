//
// Created by Atreses on 26/03/2020.
//

#include <vector>
#include "Config.h"

Config::Config() {
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
    for (int i = 0; i < this->properties->size(); ++i) {
        delete this->properties->get(i);
    }
    if (this->properties) {
        delete this->properties;
    }
}
