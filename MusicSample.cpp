#include "MusicSample.h"
#include "AudioManager.h"

MusicSample::MusicSample(const string& _path) : Sample(_path)
{
	const string& _finalPath = "Assets/Musics/" + _path;
	music = MakeShared<Music>();

	if (!music->openFromFile(_finalPath))
	{
		LOG(Error, "Invalid path : " + _finalPath);
		music = nullptr;
		return;
	}

	M_AUDIO.RegisterSample(this);
}


void MusicSample::Play(const Time& _time)
{
	if (!music) return;

	Super::Play(_time);
	music->play();
	music->setPlayingOffset(_time);
}

void MusicSample::Pause()
{
	if (!music) return;
	music->pause();
}

void MusicSample::Stop()
{
	if (!music) return;
	music->stop();
}