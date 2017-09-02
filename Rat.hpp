#ifndef _RAT_HPP_
#define _RAT_HPP_

#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include "SFML/Graphics.hpp"

class Rat{
    public:
        sf::Vector2f Pos;
        double Speed;

        // deprecated variables
        int hit;
        int d;
        int delay;
        int count1;

    private:
        const double HeadRadius = 6;
        double step; // take x steps? will probably need this variable
        int dir;

    Rat(double x, double y, double speed);
    void ChooseDirection();
    void Move();

    // deprecated functions - please rewrite
    int checkhit(sf::Vector2f s_pos, const int s_r, std::deque<float> x, std::deque<float> y, const int t_r);
    void draw(sf::RenderWindow& window, sf::CircleShape& shape);
    void rmove();
};

#endif
