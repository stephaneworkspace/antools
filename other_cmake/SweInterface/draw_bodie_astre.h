//
// Created by Stéphane on 24.09.22.
//

#ifndef ASTRONUMEROLOGIE_GENERATE_DRAW_BODIE_ASTRE_H
#define ASTRONUMEROLOGIE_GENERATE_DRAW_BODIE_ASTRE_H

#include "draw.h"
#include "astre.h"
#include "house.h"
#include "swe03.h"

class DrawBodieAstre
{
private:
public:
    static double astre_size();
    static Offset bodie_astre(H house_asc, CalcUt calcul_ut, bool sw_transit);
};

#endif //ASTRONUMEROLOGIE_GENERATE_DRAW_BODIE_ASTRE_H
