//
// Created by Stéphane on 22.09.22.
//

#ifndef ASTRONUMEROLOGIE_GENERATE_SIGN_H
#define ASTRONUMEROLOGIE_GENERATE_SIGN_H

#include <iostream>
#include <fstream>
#include "./simple_svg_1.0.0.hpp"

using namespace svg;
using namespace std;

enum Signs {
    belier = 1,
    taureau = 2,
    gemaux = 3,
    cancer = 4,
    lion = 5,
    vierge = 6,
    balance = 7,
    scorpion = 8,
    sagittaire = 9,
    capricorne = 10,
    verseau = 11,
    poisson = 12,
};

class Sign
{
public:
    static string read_svg(Signs sign);
    Image generer(Signs sign, double x, double y, double width, double height);
    static string nom(Signs sign);
};

#endif //ASTRONUMEROLOGIE_GENERATE_SIGN_H
