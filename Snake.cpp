#pragma once

#include "Snake.hpp"

Snake::Snake(sf::RenderWindow *renderWindow, double x, double y)
{
	Window = renderWindow;

	Pos.x = x + HeadRadius;
	Pos.y = y + HeadRadius;
	Speed = 4;
	TailLength = 6;

	for (int i = 0; i < TailLength; ++i) {
		TailPos.push_back(sf::Vector2<float>(0, 0));
	}

	LastPos.x = -10;
	LastPos.y = -10;

	/* Initialise Graphics */
	Head = sf::CircleShape(HeadRadius);
	Head.setFillColor(sf::Color::Green);
	Head.setPosition(Pos.x, Pos.y);
};

Snake::Snake(sf::RenderWindow *renderWindow, double x, double y, double speed, int tailLength)
{
	Window = renderWindow;

    Pos.x = x + HeadRadius;
    Pos.y = y + HeadRadius;
    Speed = speed;
    TailLength = tailLength;

    for (int i = 0; i < TailLength; ++i) 
	{
        TailPos.push_back(sf::Vector2<float>(0,0));
    }

    LastPos.x = -10;
    LastPos.y = -10;

	/* Initialise Graphics */
	Head = sf::CircleShape(HeadRadius);
	Head.setFillColor(sf::Color::Green);
	Head.setPosition(Pos.x, Pos.y);
};

void Snake::Draw()
{
	Head.setPosition(Pos.x, Pos.y);
	Window->draw(Head);
}

void Snake::Lengthen(int length) 
{
    sf::Vector2<float> pos(-10,-10);

    for (int i = 0; i < length; ++i) {
        TailPos.push_back(pos);
    }
}

bool Snake::TailHitByHead()
{
    for (int i = 18; i < TailPos.size(); i++)
    {
        float distance = sqrt(pow(TailPos.at(i).x - Pos.x, 2) + pow(TailPos.at(i).y - Pos.y, 2));
        if (distance < (HeadRadius + TailRadius)) return true;
    }
    return false;
}

void Snake::UpdateTail() 
{
	TailPos.pop_back();
	TailPos.push_front(Pos);
}
