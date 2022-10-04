//
// Created by Stéphane on 22.09.22.
//

#ifndef ASTRONUMEROLOGIE_GENERATE_SIGN_H
#define ASTRONUMEROLOGIE_GENERATE_SIGN_H

#include <iostream>
#include <fstream>

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
    static string nom(Signs sign);
};

#endif //ASTRONUMEROLOGIE_GENERATE_SIGN_H
