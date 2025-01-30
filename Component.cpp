#include "Component.h"
#include "Actor.h"

Component::Component(Actor* _owner)
{
	//owner = Shared<Actor>(_owner); // ca fait crash
}