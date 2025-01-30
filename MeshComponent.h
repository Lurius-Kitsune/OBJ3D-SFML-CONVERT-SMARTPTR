#pragma once
#include "Component.h"
#include "ShapeObject.h"

class Actor;

class MeshComponent : public Component
{
	Shared<ShapeObject> shape;

public:
	FORCEINLINE Shared<ShapeObject> GetShape() const
	{
		return shape;
	}
	FORCEINLINE void SetShape(ShapeObject* _shape)
	{
		shape = Shared<ShapeObject>(_shape);
	}

public:
	MeshComponent(Actor* _owner, const float _radius, const size_t& _pointCount = 30, const string& _path = "", const IntRect& _rect = {});
	MeshComponent(Actor* _owner, const RectangleShapeData& _data);
};