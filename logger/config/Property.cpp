//
// Created by Atreses on 26/03/2020.
//

#include <vector>
#include "Property.h"


Property::Property(string name) {
    this->name = std::move(name);
    this->enabled = false;
    this->supportedTypes = new List<LogType>();
    this->additionalProperties = map<AdditionalProperty, string>();
}

string Property::getName() {
    return this->name;
}

bool Property::isEnabled() {
    return this->enabled;
}

List<LogType> *Property::getSupportedTypes() {
    return this->supportedTypes;
}

Property::~Property() {
    delete[] this->supportedTypes;
}

void Property::addSupport(LogType supportedType) {
    if (!this->supportedTypes->contains(supportedType)) {
        this->getSupportedTypes()->add(supportedType);
    }
}

void Property::enable() {
    this->enabled = true;
}

void Property::setProperty(AdditionalProperty additionalProperty, string value) {
    this->additionalProperties.insert(pair<AdditionalProperty, string>(additionalProperty, value));
}

string Property::getProperty(AdditionalProperty property) {
    return this->additionalProperties.at(property);
}
