//
// Created by Stéphane on 22.09.22.
//

#ifndef ASTRONUMEROLOGIE_GENERATE_TIMEZONE_H
#define ASTRONUMEROLOGIE_GENERATE_TIMEZONE_H

#include <iostream>
#include <fstream>
#include "../Swe/Swe.h"

using namespace std;

struct TimeZone {
    int year;
    int month;
    int day;
    int hour;
    int min;
    double sec;
};

class TZ
{
public:
    static TimeZone utc_time_zone(TimeZone time_zone, double timezone);
};

#endif //ASTRONUMEROLOGIE_GENERATE_TIMEZONE_H
