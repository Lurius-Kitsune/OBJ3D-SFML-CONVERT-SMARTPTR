#pragma once
#include "MeshActor.h"

class Ball : public MeshActor
{
	bool canMove;
	VertexArray line;
	Vector2f startPosition;
	Vector2f velocity;
	float mass;
	float gravity;
	float restitution;
	float friction;
	float groundLevel;

public:
	Ball(const float _radius);
	virtual void BeginPlay() override;
	virtual void Tick(const float _deltaTime) override;

protected:
	virtual void RenderMesh(RenderWindow& _window) override;

public:
	void ApplyBounce(const Vector2f& _normal);
	void AddForce(const Vector2f _velocity);
};