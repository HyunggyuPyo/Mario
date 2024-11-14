#pragma once
#include<Windows.h>
#include<iostream>
#include<stdio.h>
#include <algorithm>

class Print
{
private:
	static int g_nScreenIndex;
	static HANDLE g_hScreen[2];

public:
	// 버퍼 생성 및 설정 (초기화)
	void init();
	// 버퍼 전환
	void swapBuffer();
	// 버퍼 채우기
	void ClearBuffer(WORD attribute);
	// 마리오 크기 만큼만 버퍼 채우기
	void ClearMarioB(WORD attribute, int startX, int startY, int endX, int endY);
	// 커서를 원하는 좌표로 이동
	void position(int posX, int posY);
	// 폰트 색상 변경
	void TextColor(int font, int backGround);
	// 16진수 색상 rgb값 바꾸기 
	void CustomConsoleColor();
	// 폰트 크기 비율 조정
	void DrawSize();
	//좌표에 출력된 문자 확인
	char checkPosition(int posX, int posY);

	// 오브젝트별 문자 출력 함수
	void DrawChar(int posX, int posY, int color, short num);

	Print();
	~Print();
};

