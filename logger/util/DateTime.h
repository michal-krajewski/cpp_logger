//
// Created by Atreses on 24/03/2020.
//

#ifndef LOGS_DATETIME_H
#define LOGS_DATETIME_H

#include <iostream>

using namespace std;

class DateTime {
public:
    static string now();
    static string now(const string& formatter);
    static string defaultFormatter();
};


#endif //LOGS_DATETIME_H
