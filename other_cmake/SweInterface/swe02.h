//
// Created by Stéphane on 22.09.22.
//

#ifndef ASTRONUMEROLOGIE_GENERATE_SWE02_H
#define ASTRONUMEROLOGIE_GENERATE_SWE02_H

#include <iostream>
#include <fstream>
#include <string>

#include "../Swe/Swe.h"

using namespace std;

class Swe02
{
public:
    static void set_ephe_path(string path);
    void close();
    string version();
    string get_library_path();
};

#endif //ASTRONUMEROLOGIE_GENERATE_SWE02_H
