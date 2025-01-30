#pragma once
#include "Component.h"
#include "Animation.h"

class AnimationComponent : public Component
{
	Shared<Animation> current;
	map<string, Shared<Animation>> allAnimations;

	// AnimationPose -> only
	// StateMachine -> auto switch

public:
	FORCEINLINE void SetCurrentAnimation(const string& _name)
	{
		if (!allAnimations.contains(_name)) return;
		current = allAnimations[_name];
	}
	FORCEINLINE void StartAnimation()
	{
		if (!current) return;
		current->Start();
	}
	FORCEINLINE void StopAnimation()
	{
		if (!current) return;
		current->Stop();
	}

public:
	AnimationComponent(Actor* _owner);

	void AddAnimation(Animation* _animation);
	void AddAnimations(const vector<Animation*>& _animations);
};