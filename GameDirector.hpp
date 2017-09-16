#pragma once
#include <list>
#include "IGameObject.hpp"
#include "IDrawable.hpp"
#include "Snake.hpp"
#include "Rat.hpp"
#include <vector>

class GameDirector
{
public:
	std::list<IGameObject> currentGameObjects;
	std::list<IDrawable> currentDrawObjects;

	GameDirector();

	void AddGameObject(IGameObject *object);
	void AddDrawObject(IDrawable *object);

	Rat CreateRat(double x, double y);
	Snake CreateSnake(double x, double y);
	void DrawGameObjects();

	void Reset();
	void RemoveGameObject(IGameObject *object);
	void RemoveDrawObject(IDrawable *object);

	
};
