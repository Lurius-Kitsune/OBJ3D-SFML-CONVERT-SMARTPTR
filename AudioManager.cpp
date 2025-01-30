#include "AudioManager.h"

AudioManager::AudioManager()
{
	isMuted = false;
	volume = 100.0f;
	allSamples = multimap<string, Shared<Sample>>();
}


void AudioManager::ToggleMute()
{
	isMuted = !isMuted;

	for (pair<string, Shared<Sample>> _samplePair : allSamples)
	{
		_samplePair.second->SetMuteStatus(isMuted);
	}
}