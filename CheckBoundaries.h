#include "Ball.h"
#ifndef HELLOSFML_CHECKBOUNDARIES_H
#define HELLOSFML_CHECKBOUNDARIES_H
#include <SFML/Graphics.hpp>
#pragma once
using namespace sf;

class CheckBoundaries {
public:
    CheckBoundaries() = default;
    ~CheckBoundaries() = default;
    void checkOut(Ball ball);
    int getLeftBound();
    int getRightBound();
    int getTopBound();
    int getBottomBound();


private:
    const int leftBound = 83;
    const int rightBound = 2467;
    const int topBound = 150;
    const int bottomBound = 1416;
};

// bramka 110,780 lewa srodek   920 650 min w bramce 83- za linia 55 min w osi x
// bramka prawa 2467 min gol 2495 max w osi y 920 650 w osi x
// pilka srodek 1275 - 780
// granice
// 780 srodek
// gora 150 wyszla calym obwodem
// dol  1416 wyszla calym obwodem
// lewa  83 wyszla calym obwodem
// prawa 2467 wyszla calym obwodem
#endif //HELLOSFML_CHECKBOUNDARIES_H
