#pragma once
#include "Rat.hpp"

Rat::Rat(sf::RenderWindow *renderWindow, double x, double y)
{
	Window = renderWindow;

	Pos.x = x;
	Pos.y = y;
	Speed = 3;

	/* Initialise Graphics */
	Head = sf::CircleShape(HeadRadius);
	Head.setFillColor(sf::Color::White);
	Head.setPosition(Pos.x, Pos.y);
}

Rat::Rat(sf::RenderWindow *renderWindow, double x, double y, double speed)
{
	Window = renderWindow;

    Pos.x = x;
    Pos.y = y;
    Speed = speed;

	/* Initialise Graphics */
	Head = sf::CircleShape(HeadRadius);
	Head.setFillColor(sf::Color::White);
	Head.setPosition(Pos.x, Pos.y);
}

void Rat::ChooseDirection() 
{
    dir = rand() % 5;
	step = rand() % 10 + 1;
}

void Rat::Move() 
{
    switch(dir) 
	{
        case 0: //STOP
            break;
        case 1: //UP
            Pos.y -= Speed;
			break;
        case 2: //LEFT
            Pos.x -= Speed;
			break;
        case 3: //DOWN
            Pos.y += Speed;
			break;
        case 4: //RIGHT
            Pos.x += Speed;
			break;
		default:
			break;
    } 
	step--;
}

void Rat::PlayTurn()
{
	if (step <= 0) ChooseDirection();
	Move();
}

void Rat::Draw()
{
	Head.setPosition(Pos.x, Pos.y);
	Window->draw(Head);
}

int Rat::checkhit(sf::Vector2f s_pos, const int s_r, std::deque<float> x, std::deque<float> y, const int t_r)
{
    hit = false;

    d = sqrt( pow(s_pos.x - Pos.x, 2) + pow(s_pos.y - Pos.y, 2)); //check relative distance between snake and rat
    if (d <= (s_r + HeadRadius))
    {
        hit = true;
        return 1;
    }

    for (int i = 0; i < x.size(); i++)
    {
        d = sqrt( pow(x.at(i) - Pos.x, 2) + pow(y.at(i) - Pos.y, 2) ); //check relative distance between tail segment and rat
        if (d <= (t_r + HeadRadius))
        {
            hit = true;
            return 2;
        }
    }
    if(hit == false)
        return 0;
}


