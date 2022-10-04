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

using namespace std;

const int SOLEIL = 0;
const int LUNE = 1;
const int MERCURE = 2;
const int VENUS = 3;
const int MARS = 4;
const int JUPITER = 5;
const int SATURN = 6;
const int URANUS = 7;
const int NEPTUNE = 8;
const int PLUTON = 9;
const int NOEUD_LUNAIRE = 10;

// les nombres de cet enum sont pour la libraiaire Swe
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
    static string nom(Astres a);
    static string* sign_name_and_svg(CalcUt calcul_ut);
};

#endif //ASTRONUMEROLOGIE_GENERATE_ASTRE_H
