#pragma once
#include "Core.h"

class Component : public Core
{
protected:
	Weak<class Actor> owner;

public:
	FORCEINLINE Weak<Actor> GetOwner() const
	{
		return owner;
	}

public:
	Component(Actor* _owner);

public:
	virtual void BeginPlay() override {};
	virtual void Tick(const float _deltaTime) override {};
	virtual void BeginDestroy() override {};
};