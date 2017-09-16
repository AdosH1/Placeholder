#ifndef _SNAKE_HPP_
#define _SNAKE_HPP_

#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include "SFML/Graphics.hpp"
#include "IDrawable.hpp"
#include "IGameObject.hpp"

class Snake : public IDrawable, public IGameObject
{
    public:
        sf::Vector2<double> Pos;
        double Speed;
        int TailLength;
		Snake(double x, double y);
		Snake(double x, double y, double speed, int tailLength);
		~Snake() {};

		void Dispose() override;
		void Draw() override;
		void Lengthen(int length);
		bool TailHitByHead();
		void UpdateTail();

    private:
        std::deque<sf::Vector2<double>> TailPos;
        const double HeadRadius = 8;
        const double TailRadius = 8;
        sf::Vector2<double> LastPos;


};

#endif

