//
// Created by Stéphane on 22.09.22.
//

#ifndef ASTRONUMEROLOGIE_GENERATE_SWE08_H
#define ASTRONUMEROLOGIE_GENERATE_SWE08_H

#include <iostream>
#include <fstream>
#include <string>
#include "../Swe/Swe.h"
#include "astre.h"
#include "calandar.h"
#include "option_flag.h"
#include "swe17.h"
#include "timezone.h"

using namespace std;

struct UtcToJd {
    double julian_day_et;
    double julian_day_ut;
    string err;
    int result;
};

class Swe08
{
public:
    static UtcToJd utc_to_jd(TimeZone tz, Calandar calandar);
};

#endif //ASTRONUMEROLOGIE_GENERATE_SWE08_H
