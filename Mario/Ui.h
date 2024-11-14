#pragma once
#include "Mario.h"

class Ui
{
private:
	Print _print;
	Mario _mario;

#pragma region 도트
	short char7[7][6] =
	{
		{20,15,15,15,15,15},
		{20,20,20,20,15,15},
		{20,20,20,20,15,15},
		{20,20,20,15,15,20},
		{20,20,15,15,20,20},
		{20,15,15,20,20,20},
		{20,15,15,20,20,20}
	};

	short char8[7][6] =
	{
		{20,20,15,15,15,20},
		{20,15,15,20,15,15},
		{20,15,15,20,15,15},
		{20,20,15,15,15,20},
		{20,15,15,20,15,15},
		{20,15,15,20,15,15},
		{20,20,15,15,15,20}
	};

	short char9[7][6] =
	{
		{20,20,15,15,15,20},
		{20,15,15,20,15,15},
		{20,15,15,20,15,15},
		{20,15,15,20,15,15},
		{20,20,15,15,15,15},
		{20,20,20,20,15,15},
		{20,20,15,15,15,20}
	};

	short char0[7][6] =
	{
		{20,20,20,15,20,20},
		{20,15,15,20,15,15},
		{20,15,15,20,15,15},
		{20,15,15,20,15,15},
		{20,15,15,20,15,15},
		{20,15,15,20,15,15},
		{20,20,20,15,20,20},
	};

	short char1[7][6] =
	{
		{20,20,20,15,15,20},
		{20,20,15,15,15,20},
		{20,20,20,15,15,20},
		{20,20,20,15,15,20},
		{20,20,20,15,15,20},
		{20,20,20,15,15,20},
		{20,20,15,15,15,15}
	};

	short char2[7][6] =
	{
		{20,20,15,15,15,20},
		{20,15,15,20,15,15},
		{20,20,20,20,15,15},
		{20,20,20,15,15,20},
		{20,20,15,15,20,20},
		{20,15,15,20,20,20},
		{20,15,15,15,15,15}
	};

	short char3[7][6] =
	{
		{20,20,15,15,15,20},
		{20,15,15,20,15,15},
		{20,20,20,20,15,15},
		{20,20,20,15,15,20},
		{20,20,20,20,15,15},
		{20,15,15,20,15,15},
		{20,20,15,15,15,20}
	};

	short char4[7][6] =
	{
		{20,20,20,15,15,15},
		{20,20,15,15,15,15},
		{20,15,15,20,15,15},
		{20,15,15,15,15,15},
		{20,20,20,20,15,15},
		{20,20,20,20,15,15},
		{20,20,20,20,15,15}
	};

	short char5[7][6] =
	{
		{20,15,15,15,15,15},
		{20,15,15,20,20,20},
		{20,15,15,15,15,20},
		{20,20,20,20,15,15},
		{20,20,20,20,15,15},
		{20,15,15,20,15,15},
		{20,20,15,15,15,20}
	};

	short char6[7][6] =
	{
		{20,20,15,15,15,20},
		{20,15,15,20,20,20},
		{20,15,15,15,15,20},
		{20,15,15,20,15,15},
		{20,15,15,20,15,15},
		{20,15,15,20,15,15},
		{20,20,15,15,15,20}
	};

	short charMario[7][30] =
	{
		{15,15,20,20,15,15,20,20,15,15,15,20,20,15,15,15,15,20,20,20,15,15,15,15,20,20,15,15,15,20},
		{15,15,15,15,15,15,20,15,15,20,15,15,20,15,15,20,15,15,20,20,20,15,15,20,20,15,15,20,15,15},
		{15,15,15,15,15,15,20,15,15,20,15,15,20,15,15,20,15,15,20,20,20,15,15,20,20,15,15,20,15,15},
		{15,15,20,20,15,15,20,15,15,15,15,15,20,15,15,15,15,20,20,20,20,15,15,20,20,15,15,20,15,15},
		{15,15,20,20,15,15,20,15,15,20,15,15,20,15,15,20,15,15,20,20,20,15,15,20,20,15,15,20,15,15},
		{15,15,20,20,15,15,20,15,15,20,15,15,20,15,15,20,15,15,20,20,20,15,15,20,20,15,15,20,15,15},
		{15,15,20,20,15,15,20,15,15,20,15,15,20,15,15,20,15,15,20,20,15,15,15,15,20,20,15,15,15,20}
	};

	short charX[7][6] =
	{
		{20,20,20,20,20,20},
		{15,20,20,20,15,20},
		{20,15,20,15,20,20},
		{20,20,15,20,20,20},
		{20,15,20,15,20,20},
		{15,20,20,20,15,20},
		{20,20,20,20,20,20}

	};

	short round[7][54] =
	{
		{15,15,15,15,20,20,20,15,15,15,20 ,20,15,15,20,15,15,20,15,15,20,20,15,15,20,15,15,15,15,20 ,20,20,20,20,20,20, 20,20,20,15,15,20 ,20,20,20,20,20,20 ,20,20,20,15,15,20},
		{15,15,20,15,15,20,15,15,20,15,15 ,20,15,15,20,15,15,20,15,15,20,20,15,15,20,15,15,20,15,15 ,20,20,20,20,20,20, 20,20,15,15,15,20 ,20,20,20,20,20,20 ,20,20,15,15,15,20},
		{15,15,20,15,15,20,15,15,20,15,15 ,20,15,15,20,15,15,20,15,15,15,20,15,15,20,15,15,20,15,15 ,20,20,20,20,20,20, 20,20,20,15,15,20 ,20,20,20,20,20,20 ,20,20,20,15,15,20},
		{15,15,15,15,20,20,15,15,20,15,15 ,20,15,15,20,15,15,20,15,15,15,15,15,15,20,15,15,20,15,15 ,20,20,20,20,20,20, 20,20,20,15,15,20 ,20,15,15,15,15,20 ,20,20,20,15,15,20},
		{15,15,20,15,15,20,15,15,20,15,15 ,20,15,15,20,15,15,20,15,15,20,15,15,15,20,15,15,20,15,15 ,20,20,20,20,20,20, 20,20,20,15,15,20 ,20,15,15,15,15,20 ,20,20,20,15,15,20},
		{15,15,20,15,15,20,15,15,20,15,15 ,20,15,15,20,15,15,20,15,15,20,15,15,15,20,15,15,20,15,15 ,20,20,20,20,20,20, 20,20,20,15,15,20 ,20,20,20,20,20,20 ,20,20,20,15,15,20},
		{15,15,20,15,15,20,20,15,15,15,20 ,20,20,15,15,15,20,20,15,15,20,20,15,15,20,15,15,15,15,20 ,20,20,20,20,20,20, 20,20,15,15,15,15 ,20,20,20,20,20,20 ,20,20,15,15,15,15}
	};

	short gameOver[7][55] =
	{
		{20,20,15,15,15,20 ,20,20,15,15,15,20, 20,15,15,20,20,15,15, 20,15,15,15,15,15, 20,20,20,20,20,20, 20,20,15,15,15,20 ,15,15,20,20,15,15,20,15,15,15,15,15,20,15,15,15,15,20},
		{20,15,15,20,15,15 ,20,15,15,20,15,15, 20,15,15,15,15,15,15, 20,15,15,20,20,20, 20,20,20,20,20,20, 20,15,15,20,15,15 ,15,15,20,20,15,15,20,15,15,20,20,20,20,15,15,20,15,15},
		{20,15,15,20,20,20 ,20,15,15,20,15,15, 20,15,15,15,15,15,15, 20,15,15,20,20,20, 20,20,20,20,20,20, 20,15,15,20,15,15 ,15,15,20,20,15,15,20,15,15,20,20,20,20,15,15,20,15,15},
		{20,15,15,20,15,15 ,20,15,15,15,15,15, 20,15,15,20,20,15,15, 20,15,15,15,15,20, 20,20,20,20,20,20, 20,15,15,20,15,15 ,15,15,20,20,15,15,20,15,15,15,15,20,20,15,15,15,15,20},
		{20,15,15,20,15,15 ,20,15,15,20,15,15, 20,15,15,20,20,15,15, 20,15,15,20,20,20, 20,20,20,20,20,20, 20,15,15,20,15,15 ,20,15,15,15,15,20,20,15,15,20,20,20,20,15,15,20,15,15},
		{20,15,15,20,15,15 ,20,15,15,20,15,15, 20,15,15,20,20,15,15, 20,15,15,20,20,20, 20,20,20,20,20,20, 20,15,15,20,15,15 ,20,15,15,15,15,20,20,15,15,20,20,20,20,15,15,20,15,15},
		{20,20,15,15,15,15 ,20,15,15,20,15,15, 20,15,15,20,20,15,15, 20,15,15,15,15,15, 20,20,20,20,20,20, 20,20,15,15,15,20 ,20,20,15,15,20,20,20,15,15,15,15,15,20,15,15,20,15,15},
	};

#pragma endregion


public:
	// 문자 도트 출력
	void UiDrawChar(short posx, short posy, short arr[7][6]);
	// 점수, 코인 출력
	void UiDraw();
	// 라운드 출력
	void RoundInfoDraw();
	// 남은 목숨 출력
	void LifeDraw(short posx, short posy);
	// 도트 출력
	void ScoreDraw();
	
	void GameOver();

	Ui();
	~Ui();
};

