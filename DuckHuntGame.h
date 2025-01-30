#pragma once
#include "Game.h"
#include "MeshActor.h"
#include "MusicSample.h"
#include "Duck.h"
#include "Ball.h"
#include "Label.h"

using namespace UI;

class DuckHuntGame : public Game
{
	MeshActor* background;
	MusicSample* music;

	// Ball
	Shared<Ball> ball;
	Shared<MeshActor> floor;
	Shared<MeshActor> wall1;
	Shared<MeshActor> wall2;
	Shared<Label> label;

public:
	DuckHuntGame();

public:
	virtual void Start() override;
	virtual bool Update() override;
	virtual void Stop() override;
};