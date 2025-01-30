#pragma once
#include "CoreMinimal.h"
#include "Actor.h"

class Level
{
public:
	template <typename Type = Actor, IS_BASE_OF(Actor, Type)>
	static Shared<Type> SpawnActor()
	{
		const SubclassOf<Type>& _ref = SubclassOf(Type());
		return SpawnActor(_ref);
	}

	template <typename Type = Actor, IS_BASE_OF(Actor, Type)>
	static Shared<Type> SpawnActor(const SubclassOf<Type>& _ref)
	{
		Shared<Type> _actor = MakeShared<Type>(_ref.GetObject());
		_actor->Construct();
		return _actor;
	}

	template <typename Type = Actor, IS_BASE_OF(Actor, Type)>
	static Shared<Type> SpawnActor(const Type& _ref)
	{
		Shared<Type> _actor = MakeShared<Type>(_ref);
		_actor->Construct();
		return _actor;
	}

	// TODO move to PlayerController
	//static void SetViewTarget()
};