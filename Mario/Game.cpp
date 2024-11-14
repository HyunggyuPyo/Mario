#include "Game.h"

Game::Game()
{	
	while (true)
	{
	restart:
		Title* _title = new Title;
		_title->GameTitle();
		delete _title;

		Play* _play = new Play;
		PlaySound(TEXT("MarioBGM.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
		_play->Game();

		if (_play->GameOver())
		{
			delete _play;
			goto restart;
		}
		delete _play;

		Play02* _play02 = new Play02;
		_play02->Game();
		delete _play02;

		Play03* _play03 = new Play03;
		_play03->Game();
		delete _play03;

		PlaySound(NULL, 0, 0);
	}
}

Game::~Game()
{

}
