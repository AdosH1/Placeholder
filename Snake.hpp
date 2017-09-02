#ifndef _SNAKE_HPP_
#define _SNAKE_HPP_

#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include "SFML/Graphics.hpp"

class Snake
{
    public:
        sf::Vector2f Pos;
        double Speed;
        int TailLength;

    private:
        std::deque<sf::Vector2f> TailPos;
        const double HeadRadius = 8;
        const double TailRadius = 8;
        sf::Vector2f LastPos;

    Snake(double x, double y, double speed, int tailLength);
    void UpdateTail();
    void Lengthen(int length);
    bool TailHitByHead();

};

#endif

