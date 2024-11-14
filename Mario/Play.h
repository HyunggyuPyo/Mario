#pragma once
#include "Round01.h"
#include "Ui.h"

class Play
{
private:
	Mario _mario;
	Print _print;
	
	short MaxPosY;
	short mapPosX;
	short rmapPosX;
	short mapHalf;
	bool gameOver;

	void resetValue();
public:
	void Game();
	bool GameOver();

	Play();
	~Play();
};

