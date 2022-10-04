//
// Created by Stéphane on 04.10.22.
//

#ifndef ANTOOLS_EXE_CIRCLE_H
#define ANTOOLS_EXE_CIRCLE_H

#include <fstream>
#include <iostream>
#include "../../include/antools.h"
#include "svg.h"

using namespace std;

class Circle
{
private:
    SvgProperties properties;
public:
    Circle(Fill fill, Stroke stroke);
    string generate(float x, float y, float r);
};


#endif //ANTOOLS_EXE_CIRCLE_H
