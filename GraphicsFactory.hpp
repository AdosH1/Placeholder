#ifndef _GRAPHICSFACTORY_HPP_
#define _GRAPHICSFACTORY_HPP_

#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include "SFML/Graphics.hpp"

class GraphicsFactory
{
    public:

    sf::Vector2f WindowSize;
    sf::Vector2f BorderSize;

    // Menu Screen
    sf::Sprite MenuSprite;
    sf::Texture MenuTexture;
    sf::Sprite PlaySprite;
    sf::Texture PlayTexture;
    sf::Sprite ExitSprite;
    sf::Texture ExitTexture;
    sf::Sprite SelectorSprite;
    sf::Texture SelectorTexture;

    // Board
    sf::RectangleShape BorderTop;
    sf::RectangleShape BorderLeft;
    sf::RectangleShape BorderBottom;
    sf::RectangleShape BorderRight;
    sf::Texture BorderTexture;
    sf::Texture *pBorderTexture;
    sf::Sprite FloorSprite;
    sf::Texture FloorTexture;

    // Snake
    sf::CircleShape SnakeHead;
    sf::CircleShape SnakeTail;

    sf::Texture SnakeHeadN;
    sf::Texture *pSnakeHeadN;
    sf::Texture SnakeHeadE;
    sf::Texture *pSnakeHeadE;
    sf::Texture SnakeHeadS;
    sf::Texture *pSnakeHeadS;
    sf::Texture SnakeHeadW;
    sf::Texture *pSnakeHeadW;
    sf::Texture SnakeHeadNE;
    sf::Texture *pSnakeHeadNE;
    sf::Texture SnakeHeadNW;
    sf::Texture *pSnakeHeadNW;
    sf::Texture SnakeHeadSE;
    sf::Texture *pSnakeHeadSE;
    sf::Texture SnakeHeadSW;
    sf::Texture *pSnakeHeadSW;
    sf::Texture SnakeBody;
    sf::Texture *pSnakeBody;


    // Rat
    sf::CircleShape RatHead;

    GraphicsFactory(int WindowX, int WindowY, int borderWidth);
    void LoadMenu();
    void LoadBoard();
    void LoadSnake();
    void LoadRat();
};

#endif // _GRAPHICSFACTORY_HPP_
