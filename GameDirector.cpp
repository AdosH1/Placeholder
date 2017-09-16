#include "GameDirector.hpp"
GameDirector::GameDirector()
{

}

void GameDirector::AddDrawObject(IDrawable object)
{
	currentDrawObjects.push_back(object);
}

void GameDirector::AddGameObject(IGameObject object)
{
	currentGameObjects.push_back(object);
}

Rat GameDirector::CreateRat(double x, double y)
{
	Rat *r = new Rat(x, y);
	currentGameObjects.push_back(*r);
	currentDrawObjects.push_back(*r);

	return *r;
}

Snake GameDirector::CreateSnake(double x, double y)
{
	Snake *s = new Snake(x, y);
	currentGameObjects.push_back(*s);
	currentDrawObjects.push_back(*s);

	return *s;
}



void GameDirector::DrawGameObjects()
{
	for (IDrawable object : currentDrawObjects)
	{
		object.Draw();
	}
}

void GameDirector::RemoveGameObject(IGameObject object)
{
	currentGameObjects.remove(object);
	object.Dispose();
}

void GameDirector::RemoveDrawObject(IDrawable object)
{
	currentDrawObjects.remove(object);
}

void GameDirector::Reset()
{
	for (IGameObject object : currentGameObjects)
	{
		currentGameObjects.remove(object);
		object.Dispose();
	}
	currentDrawObjects.clear();
}




