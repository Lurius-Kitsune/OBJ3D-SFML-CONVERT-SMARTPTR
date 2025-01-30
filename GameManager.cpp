#include "GameManager.h"

void GameManager::Launch(Game* _currentGame)
{
	if (!(currentGame = Shared<Game>(_currentGame))) return;

	currentGame->Start();
	while (!currentGame->Update());
	currentGame->Stop();
}