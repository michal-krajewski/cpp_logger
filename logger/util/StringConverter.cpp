//
// Created by Atreses on 24/03/2020.
//

#include "StringConverter.h"

char *StringConverter::convertToCharArray(const string& value) {
    char *charArray = new char[value.size() + 1]();
    strcpy(charArray, value.c_str());
    return charArray;
}
