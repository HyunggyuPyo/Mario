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
	// ���� ���� �� ���� (�ʱ�ȭ)
	void init();
	// ���� ��ȯ
	void swapBuffer();
	// ���� ä���
	void ClearBuffer(WORD attribute);
	// ������ ũ�� ��ŭ�� ���� ä���
	void ClearMarioB(WORD attribute, int startX, int startY, int endX, int endY);
	// Ŀ���� ���ϴ� ��ǥ�� �̵�
	void position(int posX, int posY);
	// ��Ʈ ���� ����
	void TextColor(int font, int backGround);
	// 16���� ���� rgb�� �ٲٱ� 
	void CustomConsoleColor();
	// ��Ʈ ũ�� ���� ����
	void DrawSize();
	//��ǥ�� ��µ� ���� Ȯ��
	char checkPosition(int posX, int posY);

	// ������Ʈ�� ���� ��� �Լ�
	void DrawChar(int posX, int posY, int color, short num);

	Print();
	~Print();
};

