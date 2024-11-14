#pragma once
#include "Print.h"

class Block
{
protected:
	Print _print;
	short posY;

public:
	void DrawBlock(short posX, short startpPosX, short cutArr) {};
	void TouchBlock() {};
	void BlockAni() {};
};
