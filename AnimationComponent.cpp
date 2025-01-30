#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(Actor* _owner) : Component(_owner)
{
	current = nullptr;
	allAnimations = map<string, Shared<Animation>>();
}


void AnimationComponent::AddAnimation(Animation* _animation)
{
	const string& _animationName = _animation->GetName();
	if (allAnimations.contains(_animationName)) return;

	allAnimations[_animationName] = Shared<Animation>(_animation);
}

void AnimationComponent::AddAnimations(const vector<Animation*>& _animations)
{
	const u_int& _animationsCount = CAST(u_int, _animations.size());
	for (u_int _index = 0; _index < _animationsCount; _index++)
	{
		AddAnimation(_animations[_index]);
	}
}