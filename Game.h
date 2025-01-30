#pragma once
#include "CoreMinimal.h"

class Game
{
protected:
	RenderWindow window;

public:
	FORCEINLINE virtual bool IsOver() const
	{
		return !window.isOpen();
	}
	FORCEINLINE Vector2f GetWindowSize() const
	{
		return CAST(Vector2f, window.getSize());
	}

public:
	Game();

public:
	virtual void Start();
	virtual bool Update();
	void UpdateWindow();
	virtual void Stop();
};