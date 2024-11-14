#include "Round02.h"

Round02::Round02()
{
    _vcoin.push_back(new Coin);
    _vcoin.push_back(new Coin);
    _vcoin.push_back(new Coin);
    _vcoin.push_back(new Coin);
}

Round02::~Round02()
{
    _vcoin.clear();
}

void Round02::Map()
{
    DrawMap();
    short posX = 32;

    for (int i = 0; i < _vcoin.size(); ++i)
    {
        _vcoin[i]->CheckCollect(160 + i * posX, 160);
    }
    
}

void Round02::DrawMap()
{
    for (int i = 0; i < 240; i++)
    {
        for (int j = 0; j < 48; j++)
        {
            switch (round02[j][i])
            {
            case 0:
                _print.DrawChar(i * 2, j + 176, 0, 0);
                break;
            case 1:
                _print.DrawChar(i * 2, j + 176, 1, 0);
                break;
            case 2:
                _print.DrawChar(i * 2, j + 176, 2, 5);
                break;
            case 9:
                _print.DrawChar(i * 2, j + 176, 9, 0);
                break;
            case 10:
                _print.DrawChar(i * 2, j + 176, 10, 5);
                break;
            case 20:
                break;
            }
        }
    }
}

void Round02::CheckCoin()
{
    short posX = 32;
    for (int i = 0; i < _vcoin.size(); ++i)
    {
        _vcoin[i]->CheckCoin(160 + i * posX, 160);
    }
}
