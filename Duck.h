#pragma once
#include "MeshActor.h"
#include "MovementComponent.h"
#include "AnimationComponent.h"

class Duck : public MeshActor
{
	Shared<MovementComponent> movement;
	Shared<AnimationComponent> animation;

public:
	FORCEINLINE Shared<MovementComponent> GetMovement() const
	{
		return movement;
	}

public:
	Duck(const Vector2f& _size, const string& _path = "", const IntRect& _rect = {});

protected:
	virtual void BeginPlay() override;

public:
	virtual void Construct() override;
	virtual void Deconstruct() override;
};