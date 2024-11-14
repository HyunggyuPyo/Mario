#pragma once
#include "Round03.h"
#include "Ui.h"

class Play03
{
private:
	Print _print;
	Mario _mario;

	short mapPosX;
	short rmapPosX;
	short mapHalf;

public:
	void Game();

	Play03();
	~Play03();
};

