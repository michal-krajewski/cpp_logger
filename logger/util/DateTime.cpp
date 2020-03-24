//
// Created by Atreses on 24/03/2020.
//

#include "DateTime.h"
#include "StringConverter.h"

string DateTime::now() {
    return DateTime::now(DateTime::defaultFormatter());
}

string DateTime::now(const string& formatter) {
    time_t now = time(nullptr);
    char buf[80];
    auto time = *localtime(&now);
    strftime(buf, sizeof(buf), StringConverter::convertToCharArray(formatter), &time);

    return buf;
}

string DateTime::defaultFormatter() {
    return "%d-%m-%Y %X";
}
