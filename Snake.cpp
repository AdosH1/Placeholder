#include "Snake.hpp"

Snake::Snake(double x, double y, double speed, int tailLength)
    {
        Pos.x = x + HeadRadius;
        Pos.y = y + HeadRadius;
        Speed = speed;
        TailLength = tailLength;

        for (int i = 0; i < TailLength; ++i) {
            TailPos.push_back(sf::Vector2f(0,0));
        }

        LastPos.x = -10;
        LastPos.y = -10;
    };

void Snake::UpdateTail() {
        TailPos.pop_back();
        TailPos.push_front(Pos);
    }

void Snake::Lengthen(int length) {
        sf::Vector2f fillVector(-10,-10);

        for (int i = 0; i < length; ++i) {
            TailPos.push_back(fillVector);
        }
    }

bool Snake::TailHitByHead()
{
    for (int i = 18; i < TailPos.size(); i++)
    {
        float d = sqrt(pow(TailPos.at(i).x - Pos.x, 2) + pow(TailPos.at(i).y - Pos.y, 2));
        if (d < (HeadRadius + TailRadius))
        {
            return true;
        }
    }
    return false;
}
