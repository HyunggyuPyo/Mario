#include "Ui.h"

Ui::Ui()
{
}

Ui::~Ui()
{
}

void Ui::UiDrawChar(short posx, short posy, short arr[7][6])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            switch (arr[j][i])
            {
            case 15:
                _print.DrawChar(i * 2 + posx, j + posy, 15, 9);
                break;
            case 20:
                break;
            }
        }
    }
}

void Ui::UiDraw()
{
    short numA, numB, scoreA, scoreB;
    ScoreDraw();
    UiDrawChar(62, 16, char0);
    UiDrawChar(74, 16, char0);
    UiDrawChar(110, 16, char0);
    UiDrawChar(122, 16, char0);

    scoreA = _mario.GetScore() / 10;
    scoreB = _mario.GetScore() % 10;

    switch (scoreA)
    {
    case 0:
        UiDrawChar(86, 16, char0);
        break;
    case 1:
        UiDrawChar(86, 16, char1);
        break;
    case 2:
        UiDrawChar(86, 16, char2);
        break;
    case 3:
        UiDrawChar(86, 16, char3);
        break;
    case 4:
        UiDrawChar(86, 16, char4);
        break;
    case 5:
        UiDrawChar(86, 16, char5);
        break;
    case 6:
        UiDrawChar(86, 16, char6);
        break;
    case 7:
        UiDrawChar(86, 16, char7);
        break;
    case 8:
        UiDrawChar(86, 16, char8);
        break;
    case 9:
        UiDrawChar(86, 16, char9);
        break;
    }

    switch (scoreB)
    {
    case 0:
        UiDrawChar(98, 16, char0);
        break;
    case 1:
        UiDrawChar(98, 16, char1);
        break;
    case 2:
        UiDrawChar(98, 16, char2);
        break;
    case 3:
        UiDrawChar(98, 16, char3);
        break;
    case 4:
        UiDrawChar(98, 16, char4);
        break;
    case 5:
        UiDrawChar(98, 16, char5);
        break;
    case 6:
        UiDrawChar(98, 16, char6);
        break;
    case 7:
        UiDrawChar(98, 16, char7);
        break;
    case 8:
        UiDrawChar(98, 16, char8);
        break;
    case 9:
        UiDrawChar(98, 16, char9);
        break;
    }

    UiDrawChar(208, 16, charX);

    numA = _mario.GetCoinCount() / 10;
    numB = _mario.GetCoinCount() % 10;

    switch (numA)
    {
    case 0:
        UiDrawChar(220, 16, char0);
        break;
    case 9:
        UiDrawChar(220, 16, char9);
        break;
    case 10:
        UiDrawChar(220, 16, char0);
        break;
    }

    switch (numB)
    {
    case 0:
        UiDrawChar(232, 16, char0);
        break;
    case 1:
        UiDrawChar(232, 16, char1);
        break;
    case 7:
        UiDrawChar(232, 16, char7);
        break;
    case 8:
        UiDrawChar(232, 16, char8);
        break;
    case 9:
        UiDrawChar(232, 16, char9);
        break;
    }

    _mario.DrawMarioUi(320, 15, 1);
    LifeDraw(352, 16);
}

void Ui::RoundInfoDraw()
{
    LifeDraw(240, 105);
    _mario.DrawMarioUi(200, 98, 0);
    for (int i = 0; i < 54; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            switch (round[j][i])
            {
            case 15:
                _print.DrawChar(i * 2 + 180, j + 80, 15, 9);
                break;
            case 20:
                break;
            }
        }
    }
}

void Ui::LifeDraw(short posx, short posy)
{
    short life = _mario.GetLife();
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            switch (charX[j][i])
            {
            case 15:
                _print.DrawChar(i * 2 + posx, j + posy, 15, 9);
                break;
            case 20:
                break;
            }
        }
    }

    switch (life)
    {
    case 0:
        UiDrawChar(posx+ 10, posy, char0);
        break;
    case 1:
        UiDrawChar(posx + 10, posy, char1);
        break;
    case 2:
        UiDrawChar(posx + 10, posy, char2);
        break;
    case 3:
        UiDrawChar(posx + 10, posy, char3);
        break;
    case 4:
        UiDrawChar(posx + 10, posy, char4);
        break;
    }
}

void Ui::ScoreDraw()
{
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            switch (charMario[j][i])
            {
            case 15:
                _print.DrawChar(i * 2 + 64, j + 8, 15, 9);
                break;
            case 20:
                break;
            }
        }
    }
}

void Ui::GameOver()
{
    for (int i = 0; i < 55; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            switch (gameOver[j][i])
            {
            case 15:
                _print.DrawChar(i * 2 + 185, j + 114, 15, 9);
                break;
            case 20:
                break;
            }
        }
    }
}
