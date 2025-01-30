#pragma once
#include "MeshActor.h"

class Bird : public MeshActor
{


public:
	Bird();

public:
	virtual void BeginPlay() override;
	virtual void Tick(const float _deltaTime) override;
};