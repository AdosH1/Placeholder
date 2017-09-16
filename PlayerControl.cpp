#include "PlayerControl.hpp"

PlayerControl::Input PlayerControl::currInput = noAction;
PlayerControl::Input PlayerControl::prevInput = noAction;

PlayerControl::PlayerControl()
{

}

void PlayerControl::playerAction(Snake *snake)
{
	prevInput = currInput;
	currInput = getPlayerInput(prevInput);
	processInput(currInput, snake);
}


PlayerControl::Input PlayerControl::getPlayerInput(Input &prevInput)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		return prevInput = Exit;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && 
		sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		return prevInput = moveNE;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && 
		sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		return prevInput = moveNW;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && 
		sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		return prevInput = moveSW;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && 
		sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		return prevInput = moveSE;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		return prevInput = moveN;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		return prevInput = moveE;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		prevInput = moveS;
		return prevInput;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		return prevInput = moveW;

	return prevInput;
}

void PlayerControl::processInput(Input input, Snake *snake)
{
	if (input == noAction)
		return;

	if (input == moveN)
		snake->Pos.y -= snake->Speed;

	if (input == moveE)
		snake->Pos.x += snake->Speed;

	if (input == moveS)
		snake->Pos.y += snake->Speed;

	if (input == moveW)
		snake->Pos.x -= snake->Speed;

	if (input == moveNE)
	{
		snake->Pos.y -= 0.71*snake->Speed;
		snake->Pos.x += 0.71*snake->Speed;
	}

	if (input == moveSE)
	{
		snake->Pos.y += 0.71*snake->Speed;
		snake->Pos.x += 0.71*snake->Speed;
	}

	if (input == moveSW)
	{
		snake->Pos.y += 0.71*snake->Speed;
		snake->Pos.x -= 0.71*snake->Speed;
	}

	if (input == moveNW)
	{
		snake->Pos.y -= 0.71*snake->Speed;
		snake->Pos.x -= 0.71*snake->Speed;
	}

	/* TODO: Remember to add GameOver mechanic */
}
