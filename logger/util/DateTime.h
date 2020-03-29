//
// Created by Atreses on 24/03/2020.
//

#ifndef LOGS_DATETIME_H
#define LOGS_DATETIME_H

#include <iostream>

using namespace std;

class DateTime {
public:
    /// Returns current date in default format as std::string
    /// @return date as std::string
    static string now();

    /// Returns current date in specified format as std::string
    /// @param formatter (std::string)
    /// @return date as std::string
    static string now(const string& formatter);

    /// Returns default formatter as std::string
    /// @return default formatter (std::string)
    static string defaultFormatter();
};


#endif //LOGS_DATETIME_H
