#include "CameraActor.h"
#include "GameManager.h"
#include "Duck.h"
#include "DuckHuntGame.h"

CameraActor::CameraActor(const string& _name) : Actor(_name)
{
	camera = CreateComponent<CameraComponent>();
	target = nullptr;
}

CameraActor::CameraActor(const Vector2f& _center, const Vector2f& _size, const string& _name) : Actor(_name)
{
	camera = CreateComponent<CameraComponent>(_center, _size);
	target = nullptr;
}

CameraActor::CameraActor(const FloatRect& _rect, const string& _name) : Actor(_name)
{
	camera = CreateComponent<CameraComponent>(_rect);
	target = nullptr;
}


void CameraActor::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);

	if (!target) return;
	//SetPosition(target->GetPosition());
}