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
		Snake(double x, double y, double speed = 4, int tailLength = 6);

    private:
        std::deque<sf::Vector2f> TailPos;
        const double HeadRadius = 8;
        const double TailRadius = 8;
        sf::Vector2f LastPos;

	public: 
		void UpdateTail();
		void Lengthen(int length);
		bool TailHitByHead();

};

#endif

