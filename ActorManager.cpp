#include "ActorManager.h"

void ActorManager::BeginPlay()
{
	for (Shared<Actor> _actor : allActors)
	{
		_actor->BeginPlay();
	}
}

void ActorManager::Tick(const float _deltaTime)
{
	vector<Shared<Actor>> _garbage;

	for (Shared<Actor> _actor : allActors)
	{
		_actor->Tick(_deltaTime);

		if (_actor->IsToDelete())
		{
			_garbage.push_back(_actor);
		}
	}

	for (Shared<Actor> _actor : _garbage)
	{
		_actor->Deconstruct();
	}
}

void ActorManager::BeginDestroy()
{
	for (Shared<Actor> _actor : allActors)
	{
		_actor->BeginDestroy();
	}
}