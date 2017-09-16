#ifndef _BOARD_HPP_
#define _BOARD_HPP_

#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include "SFML/Graphics.hpp"

// deprecated class
class Board
{
public:
//variables
    //menu screen
    sf::Sprite menu;
    sf::Texture menu_texture;
    sf::Sprite play;
    sf::Texture play_texture;
    sf::Sprite exit;
    sf::Texture exit_texture;
    sf::Sprite selector;
    sf::Texture selector_texture;

    //border
    int border_width;
    sf::Vector2f border;
    sf::RectangleShape top;
    sf::RectangleShape left;
    sf::RectangleShape bottom;
    sf::RectangleShape right;
    sf::Texture border_texture;
    sf::Texture *pborder_texture = &border_texture;
    sf::Texture floor;
    sf::Sprite background;

    //scoring
    std::ostringstream ss;
    sf::Text score;
    sf::Font font;


//constructor
    Board(sf::RenderWindow& window, int window_render_x, int window_render_y)
    {
    //menu variables
    if (!menu_texture.loadFromFile("Resources/Graphics/Scoundrel_menu.png"))
        std::cout << "Error loading menu texture." << std::endl;
    menu.setTexture(menu_texture);

    if (!play_texture.loadFromFile("Resources/Graphics/Play.png"))
        std::cout << "Error loading play button texture." << std::endl;
    play.setTexture(play_texture);
    play.setPosition(80,320);

    if (!exit_texture.loadFromFile("Resources/Graphics/Exit.png"))
        std::cout << "Error loading exit button texture." << std::endl;
    exit.setTexture(exit_texture);
    exit.setPosition(80,400);

    if (!selector_texture.loadFromFile("Resources/Graphics/Selector.png"))
        std::cout << "Error loading selector texture." << std::endl;
    selector.setTexture(selector_texture);
    selector.setPosition(60,332);

    //border variables
    border_width = 12;
    border.x = window_render_x;
    border.y = border_width;

    if (!border_texture.loadFromFile("Resources/Graphics/wood_border.png"))
        std::cout << "Error loading border texture." << std::endl;
    if (!floor.loadFromFile("Resources/Graphics/wood_floor.png"))
        std::cout << "Error loading border texture." << std::endl;

    background.setTexture(floor);

    top.setSize(border);
    top.setTexture(pborder_texture);
//    top.setFillColor(sf::Color(139,69,13));

    left.setSize(border);
    left.setTexture(pborder_texture);
//    left.setFillColor(sf::Color(139,69,13));
    left.setPosition(border_width,0);
    left.rotate(90);

    bottom.setSize(border);
    bottom.setTexture(pborder_texture);
//    bottom.setFillColor(sf::Color(139,69,13));
    bottom.setPosition(0,window_render_x - border_width);

    right.setSize(border);
    right.setTexture(pborder_texture);
//    right.setFillColor(sf::Color(139,69,13));
    right.setPosition(window_render_x,0);
    right.rotate(90);

    //scoring variables
    score.setFont(font);
    score.setColor(sf::Color(255,255,255));
    score.setCharacterSize(20);
    score.setPosition(495,560);
    if (!font.loadFromFile("Resources/Fonts/Tahoma.ttf"))
        std::cout << "Failed to load font." << std::endl;
    };
// constructor end

//functions
    void draw(sf::RenderWindow& window, int current_score);
    void draw_menu(sf::RenderWindow& window, int current_score);



};

void Board::draw(sf::RenderWindow& window, int current_score)
{
    window.draw(background);
    window.draw(top);
    window.draw(left);
    window.draw(bottom);
    window.draw(right);

    ss << "Score: " << current_score;
    score.setString(ss.str());
    window.draw(score);
    ss.str(std::string());
}

void Board::draw_menu(sf::RenderWindow& window, int current_score)
{
    window.draw(menu);
    window.draw(play);
    window.draw(exit);
    window.draw(selector);


    ss << "Score: " << current_score;
    score.setString(ss.str());
    window.draw(score);
    ss.str(std::string());
}



#endif // _BOARD_HPP_
