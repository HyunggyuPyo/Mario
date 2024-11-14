#include "Title.h"

#define KEY_UP	0
#define KEY_DOWN	1
#define KEY_SPACEBAR	4
#define BACKGROUND_COLOR 0x0030

Title::Title()
{

}

Title::~Title()
{

}

void Title::GameTitle()
{
	Ui* _ui = new Ui;
	short y = 0;

	_print.DrawSize();
	_print.init();
	_print.CustomConsoleColor();
	
	while (true)
	{
		_print.ClearBuffer(BACKGROUND_COLOR);
		_ui->UiDraw();
		DrawImage();
		DrawTitle();
		DrawMenu();

		if (GetAsyncKeyState(VK_UP) & 0x8000) 
		{
			y -= 15;
			if (y < 0)
			{
				y = 0;
			}
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			y += 15;
			if (y > 15)
			{
				y = 15;
			}
		}
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			break;
		}

		DrawCursor(y);
		_print.swapBuffer();
	}
	delete _ui;
}

void Title::DrawTitle()
{
	for (int i = 0; i < 74; i++)
	{
		for (int j = 0; j < 27; j++)
		{
			switch (super[j][i])
			{
			case 0:
				_print.DrawChar(i * 2 + 80, j + 30, 0, 9);
				break;
			case 13:
				_print.DrawChar(i * 2 + 80, j + 30, 13, 9);
				break;
			case 20:
				break;
			}
		}
	}
	for (int i = 0; i < 139; i++)
	{
		for (int j = 0; j < 45; j++)
		{
			switch (marioBros[j][i])
			{
			case 0:
				_print.DrawChar(i * 2 + 80, j + 60, 0, 9);
				break;
			case 13:
				_print.DrawChar(i * 2 + 80, j + 60, 13, 9);
				break;
			case 20:
				break;
			}
		}
	}
}

void Title::DrawMenu()
{
	for (int i = 0; i < 56; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			switch (playerGame[j][i])
			{
			case 15:
				_print.DrawChar(i * 2 + 188, j + 130, 15, 9);
				break;
			case 20:
				break;
			}
		}
	}
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			switch (exitGame[j][i])
			{
			case 15:
				_print.DrawChar(i * 2 + 188, j + 145, 15, 9);
				break;
			case 20:
				break;
			}
		}
	}
}

void Title::DrawCursor(short posy)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			switch (cursor[j][i])
			{
			case 5:
				_print.DrawChar(i * 2 + 156, j + 130 + posy, 5, 9);
				break;
			case 14:
				_print.DrawChar(i * 2 + 156, j + 130 + posy, 15, 9);
				break;
			case 20:
				break;
			}
		}
	}
}

void Title::DrawImage()
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			switch (MarioIdle[j][i])
			{
			case 4:
				_print.DrawChar(i * 2 + 64, j + 192, 4, 4);
				break;
			case 6:
				_print.DrawChar(i * 2 + 64, j + 192, 6, 4);
				break;
			case 14:
				_print.DrawChar(i * 2 + 64, j + 192, 14, 4);
				break;
			case 20:
				break;
			}
		}
	}
	for (int i = 0; i < 240; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			switch (round01Test[j][i])
			{
			case 0:
				_print.DrawChar(i * 2, j + 208, 0, 0);
				break;
			case 5:
				_print.DrawChar(i * 2, j + 208, 5, 0);
				break;
			case 13:
				_print.DrawChar(i * 2, j + 208, 13, 0);
				break;
			}
		}
	}
}
