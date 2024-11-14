#pragma once
#include "Round02.h"
#include "Ui.h"

class Play02
{
private:
	Round02 _round02;
	Print _print;
	Mario _mario;

public:
	void Game();

	Play02();
	~Play02();
};

