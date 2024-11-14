#include "Mario.h"

class Mushroom
{
private:
	Print _print;
	Mario _mario;

	short mushroomPosX;
	short mushroomPosY;
	bool turnNegative;

	bool eatMushroom;
	bool outSreen;

	short posX;
	short posY;

	int mushroom[16][16] =
	{
		{20,20,20,20,20,20,12,12,12,12,20,20,20,20,20,20},
		{20,20,20,20,20,12,12,12,12, 4, 4,20,20,20,20,20},
		{20,20,20,20,12,12,12,12, 4, 4, 4, 4,20,20,20,20},
		{20,20,20,12,12,12,12,12, 4, 4, 4, 4, 4,20,20,20},
		{20,20,12,12,12,12,12,12,12, 4, 4, 4,12,12,20,20},
		{20,12,12,12, 4, 4, 4,12,12,12,12,12,12,12,12,20},
		{20,12,12, 4, 4, 4, 4, 4,12,12,12,12,12,12,12,20},
		{12,12,12, 4, 4, 4, 4, 4,12,12,12,12, 4, 4,12,12},
		{12,12,12, 4, 4, 4, 4, 4,12,12,12,12, 4, 4, 4,12},
		{12,12,12,12, 4, 4, 4,12,12,12,12,12,12, 4, 4,12},
		{12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12},
		{20,12,12, 4, 4, 4,15,15,15,15,15, 4, 4, 4,12,20},
		{20,20,20,20,15,15,15,15,15,15,15,15,20,20,20,20},
		{20,20,20,20,15,15,15,15,15,15,12,15,20,20,20,20},
		{20,20,20,20,15,15,15,15,15,15,12,15,20,20,20,20},
		{20,20,20,20,20,15,15,15,15,12,15,20,20,20,20,20},

	};

public:
	void DrawMushroom(short startPos);
	void MushroomMove();
	void CheckMushroom();
	void EatMushroom();
	bool GetEatMushroom();
	bool DeleteMushroom();

	Mushroom();
	~Mushroom();
};
