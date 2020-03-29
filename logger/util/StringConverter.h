//
// Created by Atreses on 24/03/2020.
//

#ifndef LOGS_STRINGCONVERTER_H
#define LOGS_STRINGCONVERTER_H

#include <iostream>

using namespace std;

class StringConverter {
public:
    /// Converts provided std::string to char array
    /// @param std::string value
    /// @return char* (char array)
    static char* convertToCharArray(const string& value);
};


#endif //LOGS_STRINGCONVERTER_H
