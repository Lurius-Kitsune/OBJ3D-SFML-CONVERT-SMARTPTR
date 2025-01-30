#pragma once
#include "Singleton.h"
#include "Game.h"

class GameManager : public Singleton<GameManager>
{
	Shared<Game> currentGame;

public:
	FORCEINLINE Shared<Game> GetCurrent() const
	{
		return currentGame;
	}

public:
	virtual void Launch(Game* _currentGame);
};