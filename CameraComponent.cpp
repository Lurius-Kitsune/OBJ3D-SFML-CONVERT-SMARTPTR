#include "CameraComponent.h"
#include "GameManager.h"

CameraComponent::CameraComponent(Actor* _owner) : Component(_owner)
{
	const Vector2f& _windowSize = CAST(Vector2f, M_GAME.GetCurrent()->GetWindowSize());
	view = MakeShared<View>(_windowSize / 2.0f, _windowSize);
}

CameraComponent::CameraComponent(Actor* _owner, const Vector2f& _center, const Vector2f& _size) : Component(_owner)
{
	view = MakeShared<View>(_center, _size);
}

CameraComponent::CameraComponent(Actor* _owner, const FloatRect& _rect) : Component(_owner)
{
	view = MakeShared<View>(_rect);
}