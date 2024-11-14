#include "Print.h"

int Print::g_nScreenIndex = 0;
HANDLE Print::g_hScreen[2] = { nullptr, nullptr };

Print::Print()
{
}

Print::~Print()
{
	CloseHandle(g_hScreen[0]);
	CloseHandle(g_hScreen[1]);
}

void Print::init()
{
	system("mode con cols=480 lines=224 | title MARIO 1985");
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = FALSE;
	ConsoleCursor.dwSize = 1;

	g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	SetConsoleCursorInfo(g_hScreen[0], &ConsoleCursor);
	SetConsoleCursorInfo(g_hScreen[1], &ConsoleCursor);

	g_nScreenIndex = 0;
}

void Print::swapBuffer()
{
	SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
	g_nScreenIndex = !g_nScreenIndex; 

}

void Print::ClearBuffer(WORD attribute)
{
	COORD coord = { 0, 0 };
	DWORD dwBytesWritten = 0;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;

	GetConsoleScreenBufferInfo(g_hScreen[g_nScreenIndex], &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	FillConsoleOutputAttribute(g_hScreen[g_nScreenIndex], attribute, dwConSize, coord, &dwBytesWritten);
	FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], (TCHAR)' ', dwConSize, coord, &dwBytesWritten);
	SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], coord);
}

void Print::ClearMarioB(WORD attribute, int startX, int startY, int endX, int endY)
{
	DWORD dwBytesWritten = 0;

	if (startX < 0 || startY < 0 || endX < 0 || endY < 0) {
		return;
	}

	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(g_hScreen[g_nScreenIndex], &csbi);

	startX = max(0, min(csbi.dwSize.X - 1, startX));
	startY = max(0, min(csbi.dwSize.Y - 1, startY));

	endX = max(0, min(csbi.dwSize.X - 1, endX));
	endY = max(0, min(csbi.dwSize.Y - 1, endY));

	position(startX, startY);

	for (int y = startY; y <= endY; ++y) {
		for (int x = startX; x <= endX; ++x) {
			COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
			FillConsoleOutputAttribute(g_hScreen[g_nScreenIndex], attribute, 1, coord, &dwBytesWritten);
			FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], (TCHAR)' ', 1, coord, &dwBytesWritten);
		}
	}

	position(startX, startY);
}

void Print::position(int posX, int posY)
{
	COORD coord = { static_cast<SHORT>(posX), static_cast<SHORT>(posY) };
	SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], coord);
}

void Print::TextColor(int font, int backGround)
{
	SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], font + backGround * 16);
}

void Print::CustomConsoleColor()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFOEX csbiex = { 0 };
	csbiex.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);

	if (GetConsoleScreenBufferInfoEx(hConsole, &csbiex))
	{
		csbiex.ColorTable[1] = RGB(0, 140, 140);
		csbiex.ColorTable[5] = RGB(228, 94, 16);
		csbiex.ColorTable[9] = RGB(0, 255, 255);
		csbiex.ColorTable[12] = RGB(255, 166, 66);
		csbiex.ColorTable[13] = RGB(240, 208, 176);

		SetConsoleScreenBufferInfoEx(hConsole, &csbiex);
	}
}

void Print::DrawSize()
{
	CONSOLE_FONT_INFOEX fontInfo;
	fontInfo.cbSize = sizeof(fontInfo);

	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hConsoleOutput, FALSE, &fontInfo);

	fontInfo.dwFontSize.X = 0;
	fontInfo.dwFontSize.Y = 4;

	SetCurrentConsoleFontEx(hConsoleOutput, FALSE, &fontInfo);
}

char Print::checkPosition(int posX, int posY)
{
	CHAR_INFO charInfo;
	COORD coord = { static_cast<SHORT>(posX), static_cast<SHORT>(posY) };
	SMALL_RECT rect = { coord.X, coord.Y, coord.X + 1, coord.Y + 1 };
	ReadConsoleOutput(g_hScreen[g_nScreenIndex], &charInfo, { 1, 1 }, { 0, 0 }, &rect);

	return charInfo.Char.AsciiChar;
	
}

void Print::DrawChar(int posX, int posY, int color, short num)
{
	DWORD dwBytesWritten = 0;

	position(posX, posY);
	TextColor(color, color);

	switch (num)
	{
	case 0:
		WriteConsole(g_hScreen[g_nScreenIndex], "бс", 1, &dwBytesWritten, NULL);
		break;
	case 1:
		WriteConsole(g_hScreen[g_nScreenIndex], "11", 1, &dwBytesWritten, NULL);
		break;
	case 2:
		WriteConsole(g_hScreen[g_nScreenIndex], "22", 1, &dwBytesWritten, NULL);
		break;
	case 3:
		WriteConsole(g_hScreen[g_nScreenIndex], "33", 1, &dwBytesWritten, NULL);
		break;
	case 4:
		WriteConsole(g_hScreen[g_nScreenIndex], "44", 1, &dwBytesWritten, NULL);
		break;
	case 5:
		WriteConsole(g_hScreen[g_nScreenIndex], "55", 1, &dwBytesWritten, NULL);
		break;
	case 6:
		WriteConsole(g_hScreen[g_nScreenIndex], "66", 1, &dwBytesWritten, NULL);
		break;
	case 7:
		WriteConsole(g_hScreen[g_nScreenIndex], "77", 1, &dwBytesWritten, NULL);
		break;
	case 8:
		WriteConsole(g_hScreen[g_nScreenIndex], "88", 1, &dwBytesWritten, NULL);
		break;
	case 9:
		WriteConsole(g_hScreen[g_nScreenIndex], "  ", 1, &dwBytesWritten, NULL);
		break;
	}
	
}
