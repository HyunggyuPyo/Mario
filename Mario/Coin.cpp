#include "Coin.h"

Coin::Coin()
{
    collect = false;
}

Coin::~Coin()
{
}

void Coin::DrawCoin(short posx, short posy)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            switch (coin[j][i])
            {
            case 1:
                _print.DrawChar(i * 2 + posx, j + posy, 1, 9);
                break;
            case 5:
                _print.DrawChar(i * 2 + posx, j + posy, 5, 9);
                break;
            case 12:
                _print.DrawChar(i * 2 + posx, j + posy, 12, 9);
                break;
            case 20:
                break;
            }
        }
    }
}

void Coin::CheckCollect(short posx, short posy)
{
    if (!collect)
    {
        DrawCoin(posx, posy);
    }
}

void Coin::CheckCoin(short posx, short posy)
{
    if (_print.checkPosition(posx-4 , posy + 7) == '4')
    {
        if (!collect)
        {
            _mario.CollectCoin();
            _mario.ScoreUp(2);
            collect = true;
        }
    }
}


