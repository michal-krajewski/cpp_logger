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

    /// Returns logger type of the property
    /// @return logger type as std::string
    string getName();

    /// Returns information about logger status - if enabled returns true
    /// @return bool
    bool isEnabled();

    /// Returns list of supported messages LogTypes
    /// @return pointer to List<LogType>
    List<LogType> *getSupportedTypes();

    /// Adds support for given message LogType, if already supports - omits operation
    /// @param [in] message LogType
    void addSupport(LogType logType);

    /// Changes logger status to enabled
    void enable();

    /// Adds additional properties for the logger
    /// @param [in] additionalProperty name
    /// @param [in] value of the additional property
    void setProperty(AdditionalProperty additionalProperty, string value);

    /// Returns additional property value
    /// @param [in] additional property name
    /// @return property value as std::string
    string getProperty(AdditionalProperty property);
private:
    string name;
    bool enabled;
    List<LogType> *supportedTypes;
    map<AdditionalProperty, string> additionalProperties;
};


#endif //LOGS_PROPERTY_H
