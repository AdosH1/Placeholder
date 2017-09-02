#include "Rat.hpp"

Rat::Rat(double x, double y, double speed = 3){
        Pos.x = x;
        Pos.y = y;
        Speed = speed;
    }

void Rat::ChooseDirection() {
        dir = rand() % 5;
    }

void Rat::Move() {
        switch(dir) {
            case 0: //STOP
                break;
            case 1: //UP
                Pos.y -= Speed;
            case 2: //LEFT
                Pos.x -= Speed;
            case 3: //DOWN
                Pos.y += Speed;
            case 4: //RIGHT
                Pos.x += Speed;
        } //switch bracket
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

void Rat::draw(sf::RenderWindow& window, sf::CircleShape& shape)
{
    shape.setPosition(Pos.x - HeadRadius, Pos.y - HeadRadius);
    window.draw(shape);
}

void Rat::rmove()
{
    count1++;
    if (count1 >= delay)
    {
    dir = rand() % 5;
    delay = rand() % 60 + 10;
    count1 = 0;
    }

        switch(dir)
        {
            case 0: //STOP
                break;
            case 1: //UP
                if ((Pos.y - HeadRadius) >= 12)
                {
                    Pos.y -= Speed;
                }
                break;
            case 2: //LEFT
                if ((Pos.x - HeadRadius) >= 12)
                {
                    Pos.x -= Speed;
                }
                break;
            case 3: //DOWN
                if ((Pos.y + HeadRadius) <= 588)
                {
                    Pos.y += Speed;
                }
                break;
            case 4: //RIGHT
                if ((Pos.x + HeadRadius) <= 588)
                {
                    Pos.x += Speed;
                }
        } //switch bracket
}


