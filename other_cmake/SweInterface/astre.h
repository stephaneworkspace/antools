//
// Created by Stéphane on 21.09.22.
//

#ifndef ASTRONUMEROLOGIE_GENERATE_ASTRE_H
#define ASTRONUMEROLOGIE_GENERATE_ASTRE_H

#include <iostream>
#include <fstream>
#include <string>
#include "house.h"
#include "sign.h"
#include "calcul_ut.h"
#include "simple_svg_1.0.0.hpp"

using namespace svg;
using namespace std;

enum Astres {
    soleil = 0,
    lune = 1,
    mercure = 2,
    venus = 3,
    mars = 4,
    jupiter = 5,
    saturn = 6,
    uranus = 7,
    neptune = 8,
    pluto = 9,
    noeud_lunaire = 11,
    chiron = 15,
    ceres = 17,
    noeud_lunaire_sud = 24,
};

class Astre
{
public:
    static string read_svg(Astres astre);
    Image generer(Astres astre, double x, double y, double width, double height);
    static string nom(Astres a);
    static string* sign_name_and_svg(CalcUt calcul_ut);
};

#endif //ASTRONUMEROLOGIE_GENERATE_ASTRE_H
