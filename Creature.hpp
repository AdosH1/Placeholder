//#ifndef _CREATURE_HPP_
//#define _CREATURE_HPP_
//
//#include <iostream>
//#include <deque>
//#include <vector>
//#include <cmath>
//#include "SFML/Graphics.hpp"
//
//class Creature
//{
//public:
//    // variables
//    sf::CircleShape shape;
//    sf::Vector2f pos;
//    float spd;
//    float rad;
//    int dir; //dir 0 = STOP, 1 = UP, 2 = LEFT, 3 = DOWN, 4 = RIGHT
//    float d; //distance between rat and snake
//    int count1; //counts towards delay
//    int delay = 0; //the delay of changing rat directions
//    bool hit;
//
//    //*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_
//
//    //funtions
//    void draw(sf::RenderWindow& window)
//    {
//    shape.setPosition(pos.x - rad, pos.y - rad);
//    window.draw(shape);
//    }
//
//void move()
//{
//    count1++;
//    if (count1 >= delay)
//    {
//    dir = rand() % 5;
//    delay = rand() % 60 + 10;
//    count1 = 0;
//    }
//
//        switch(dir)
//        {
//            case 0: //STOP
//                break;
//            case 1: //UP
//                if ((pos.y - rad) >= 12)
//                {
//                    pos.y -= spd;
//                }
//                break;
//            case 2: //LEFT
//                if ((pos.x - rad) >= 12)
//                {
//                    pos.x -= spd;
//                }
//                break;
//            case 3: //DOWN
//                if ((pos.y + rad) <= 588)
//                {
//                    pos.y += spd;
//                }
//                break;
//            case 4: //RIGHT
//                if ((pos.x + rad) <= 588)
//                {
//                    pos.x += spd;
//                }
//        } //switch bracket
//}
//    // requires (snake vector2f, snake radius, tail x vector, tail y vector, tail radius)
//
//}; //creature class bracket
//
//class Rat: public Creature
//{
//    public:
//    //variables
//    sf::Texture rat_head_down;
//    sf::Texture *prat_head_down;
//    sf::Texture rat_head_up;
//    sf::Texture *prat_head_up;
//    sf::Texture rat_head_left;
//    sf::Texture *prat_head_left;
//    sf::Texture rat_head_right;
//    sf::Texture *prat_head_right;
//
//    //*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_
//
//    //constructor and deconstructor
//    Rat(sf::Vector2f vect){
//    rad = 8;
//    spd = 3.2;
//    dir = rand() % 5;
//    pos.x = vect.x;
//    pos.y = vect.y;
//
//    if (!rat_head_down.loadFromFile("Resources/Graphics/rat_head_down.png"))
//        std::cout << "Error loading rat_head_down.png" << std::endl;
//    prat_head_down = &rat_head_down;
//
//    if (!rat_head_up.loadFromFile("Resources/Graphics/rat_head_up.png"))
//        std::cout << "Error loading rat_head_up.png" << std::endl;
//    prat_head_up = &rat_head_up;
//
//    if (!rat_head_right.loadFromFile("Resources/Graphics/rat_head_right.png"))
//        std::cout << "Error loading rat_head_right.png" << std::endl;
//    prat_head_right = &rat_head_right;
//
//    if (!rat_head_left.loadFromFile("Resources/Graphics/rat_head_left.png"))
//        std::cout << "Error loading rat_head_left.png" << std::endl;
//    prat_head_left = &rat_head_left;
//
//
//    rat_head_down.setSmooth(1);
//    rat_head_up.setSmooth(1);
//    rat_head_left.setSmooth(1);
//    rat_head_right.setSmooth(1);
//
//    shape.setRadius(rad);
//    shape.setTexture(prat_head_down);
//    shape.setPointCount(100);
//    };
//    ~Rat(){};
//
//    //*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_
//
//    //functions
//    void randompos(sf::Vector2f snake, const int s_r, std::vector<float> x, std::vector<float> y, const int t_r);
//    void draw(sf::RenderWindow& window, sf::CircleShape& shape);
//    int checkhit(sf::Vector2f s_pos, const int s_r, std::deque<float> x, std::deque<float> y, const int t_r);
//    void rmove();
//
//}; //class rat bracket
//
//class Snake: public Creature
//{
//public:
//    // variables
//    sf::CircleShape tail;
//    int t_rad; //tail radius
//    int t_seg; //tail segment split frequency
//    int t_length; //length of tail array
//    std::deque<float> t_x;
//    std::deque<float> t_y;
//    sf::Vector2f last_pos;
//
//    sf::Texture snake_head_down;
//    sf::Texture *psnake_head_down;
//    sf::Texture snake_head_up;
//    sf::Texture *psnake_head_up;
//    sf::Texture snake_head_left;
//    sf::Texture *psnake_head_left;
//    sf::Texture snake_head_right;
//    sf::Texture *psnake_head_right;
//    sf::Texture snake_body;
//    sf::Texture *psnake_body;
//    sf::Texture snake_head_nw;
//    sf::Texture *psnake_head_nw;
//    sf::Texture snake_head_ne;
//    sf::Texture *psnake_head_ne;
//    sf::Texture snake_head_sw;
//    sf::Texture *psnake_head_sw;
//    sf::Texture snake_head_se;
//    sf::Texture *psnake_head_se;
//
//
//
////*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_
//
////Constructor and destructor
//Snake(){
//    rad = 8; //head radius for drawing
//    t_rad = 5; //tail radius for drawing
//    t_seg = 2; //increment per draw for tail
//    t_length = 6; //actual length of tail array
//    spd = 4; //speed in pixels per frame
//
//    for(int i = 0; i < t_length; i++)
//    {
//        t_x.push_back(-10);
//        t_y.push_back(-10);
//    }
//
//    pos.x = rad + 12;
//    pos.y = rad + 12;
//
//    last_pos.x = 0; //stores previous head pos for self-collision
//    last_pos.y = 0;
//
//        //snake graphics
//    if (!snake_head_down.loadFromFile("Resources/Graphics/snake_head_down.png"))
//        std::cout << "Error loading snake_head_down.png" << std::endl;
//    psnake_head_down = &snake_head_down;
//
//    if (!snake_head_up.loadFromFile("Resources/Graphics/snake_head_up.png"))
//        std::cout << "Error loading snake_head_up.png" << std::endl;
//    psnake_head_up = &snake_head_up;
//
//    if (!snake_head_right.loadFromFile("Resources/Graphics/snake_head_right.png"))
//        std::cout << "Error loading snake_head_right.png" << std::endl;
//    psnake_head_right = &snake_head_right;
//
//    if (!snake_head_left.loadFromFile("Resources/Graphics/snake_head_left.png"))
//        std::cout << "Error loading snake_head_left.png" << std::endl;
//    psnake_head_left = &snake_head_left;
//
//    if (!snake_body.loadFromFile("Resources/Graphics/snake_body.png"))
//        std::cout << "Error loading snake_body.png" << std::endl;
//    psnake_body = &snake_body;
//
//    if (!snake_head_nw.loadFromFile("Resources/Graphics/snake_head_nw.png"))
//        std::cout << "Error loading snake_head_nw.png" << std::endl;
//    psnake_head_nw = &snake_head_nw;
//
//    if (!snake_head_ne.loadFromFile("Resources/Graphics/snake_head_ne.png"))
//        std::cout << "Error loading snake_head_ne.png" << std::endl;
//    psnake_head_ne = &snake_head_ne;
//
//    if (!snake_head_sw.loadFromFile("Resources/Graphics/snake_head_sw.png"))
//        std::cout << "Error loading snake_head_sw.png" << std::endl;
//    psnake_head_sw = &snake_head_sw;
//
//    if (!snake_head_se.loadFromFile("Resources/Graphics/snake_head_se.png"))
//        std::cout << "Error loading snake_head_se.png" << std::endl;
//    psnake_head_se = &snake_head_se;
//
//    snake_head_down.setSmooth(1);
//    snake_head_up.setSmooth(1);
//    snake_head_left.setSmooth(1);
//    snake_head_right.setSmooth(1);
//    snake_body.setSmooth(1);
//    snake_head_nw.setSmooth(1);
//    snake_head_ne.setSmooth(1);
//    snake_head_sw.setSmooth(1);
//    snake_head_se.setSmooth(1);
//
//    shape.setRadius(rad);
//    shape.setTexture(psnake_head_down);
//    shape.setPosition(12,12);
//
//    tail.setRadius(t_rad);
//    tail.setTexture(psnake_body);
//    tail.setPosition(12,12);
//    tail.setPointCount(60);
//};
//~Snake(){};
//
////*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_
//
////functions
//void mktail();
//void drawtail(sf::RenderWindow& window);
//void lengthen();
//bool tailhit();
//static void snakeGraphics();
//
//}; // snake class bracket
//
//#endif // _CREATURE_HPP_
