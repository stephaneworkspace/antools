//
// Created by Stéphane on 27.09.22.
//

#ifndef ASTRONUMEROLOGIE_GENERATE_ASPECT_H
#define ASTRONUMEROLOGIE_GENERATE_ASPECT_H

enum Aspects {
    conjunction = 0,
    opposition = 1,
    trine = 2,
    square = 3,
    sextile = 4,
    inconjunction = 5,
    sequisquare = 6,
    semisquare = 7,
    semisextile = 8
};

class Aspect
{
public:
    static int* angle(Aspects a);
};

#endif //ASTRONUMEROLOGIE_GENERATE_ASPECT_H
