//
// Created by Stéphane on 04.10.22.
//

#ifndef ANTOOLS_EXE_CIRCLE_H
#define ANTOOLS_EXE_CIRCLE_H

#include <iostream>
#include "../../include/antools.h"
#include "svg.h"

using namespace std;

class SCircle
{
private:
    SvgProperties properties;
public:
    SCircle(SFill fill, SStroke stroke);
    string generate(float x, float y, float r);
};

#endif //ANTOOLS_EXE_CIRCLE_H
