#include "RootComponent.h"

RootComponent::RootComponent(Actor* _owner, const TransformData& _transform) : Component(_owner)
{
	transform = _transform;
}