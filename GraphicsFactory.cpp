#include "GraphicsFactory.hpp"

GraphicsFactory::GraphicsFactory(int WindowX, int WindowY, int borderWidth = 12){
        WindowSize.x = WindowX;
        WindowSize.y = WindowY;
        BorderSize.x = WindowX;
        BorderSize.y = borderWidth;
    }

void GraphicsFactory::LoadMenu() {
        if (!MenuTexture.loadFromFile("Resources/Graphics/Scoundrel_menu.png"))
            std::cout << "Error loading menu texture." << std::endl;
        MenuSprite.setTexture(MenuTexture);

        if (!PlayTexture.loadFromFile("Resources/Graphics/Play.png"))
            std::cout << "Error loading play button texture." << std::endl;
        PlaySprite.setTexture(PlayTexture);
        PlaySprite.setPosition(80,320);

        if (!ExitTexture.loadFromFile("Resources/Graphics/Exit.png"))
            std::cout << "Error loading exit button texture." << std::endl;
        ExitSprite.setTexture(ExitTexture);
        ExitSprite.setPosition(80,400);

        if (!SelectorTexture.loadFromFile("Resources/Graphics/Selector.png"))
            std::cout << "Error loading selector texture." << std::endl;
        SelectorSprite.setTexture(SelectorTexture);
        SelectorSprite.setPosition(60,332);
    }

void GraphicsFactory::LoadBoard()
    {
    //Border Texture
    if (!BorderTexture.loadFromFile("Resources/Graphics/wood_border.png"))
        std::cout << "Error loading border texture." << std::endl;
    //Floor Texture
    if (!FloorTexture.loadFromFile("Resources/Graphics/wood_floor.png"))
        std::cout << "Error loading border texture." << std::endl;

    pBorderTexture = &BorderTexture;
    FloorSprite.setTexture(FloorTexture);

    //Please note:
    //The border texture is simply rotated to fit the screen size

    BorderTop.setSize(BorderSize);
    BorderTop.setTexture(pBorderTexture);

    BorderLeft.setSize(BorderSize);
    BorderLeft.setTexture(pBorderTexture);
    BorderLeft.setPosition(WindowSize.x,0);
    BorderLeft.rotate(90);

    BorderBottom.setSize(BorderSize);
    BorderBottom.setTexture(pBorderTexture);
    BorderBottom.setPosition(0,WindowSize.y - BorderSize.y);

    BorderRight.setSize(BorderSize);
    BorderRight.setTexture(pBorderTexture);
    BorderRight.setPosition(WindowSize.x,0);
    BorderRight.rotate(90);
    }
