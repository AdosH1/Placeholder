#pragma once

#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include "SFML/Graphics.hpp"
#include "IDrawable.hpp"
#include "IGameObject.hpp"
#include "GraphicsFactory.hpp"

class Snake : public IDrawable, public IGameObject, public IObject
{
    public:
		/* The window this object belongs to */
		sf::RenderWindow *Window;

        sf::Vector2<float> Pos;
		std::deque<sf::Vector2<float>> TailPos;
        double Speed;
        int TailLength;

		sf::CircleShape Head;

		Snake(sf::RenderWindow *renderWindow, double x, double y);
		Snake(sf::RenderWindow *renderWindow, double x, double y, double speed, int tailLength);
		~Snake() {};

		void Draw() override;
		void Lengthen(int length);
		bool TailHitByHead();
		void UpdateTail();

    private:
        const double HeadRadius = 8;
        const double TailRadius = 8;
        sf::Vector2<double> LastPos;


};


