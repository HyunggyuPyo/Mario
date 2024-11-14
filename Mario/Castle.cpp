#include "Castle.h"

Castle::Castle()
{
}

Castle::~Castle()
{
}

void Castle::DrawCastle(short startpPosX, short cutArr)
{
    for (int i = 0; i < cutArr; i++)
    {
        if (cutArr > 80)
        {
            cutArr = 80;
        }
        for (int j = 0; j < 80; j++)
        {
            switch (castle[j][i])
            {
            case 0:
                _print.DrawChar(192 + i * 2 + startpPosX, 128 + j, 0, 2);
                break;
            case 5:
                _print.DrawChar(192 + i * 2 + startpPosX, 128 + j, 5, 2);
                break;
            case 13:
                _print.DrawChar(192 + i * 2 + startpPosX, 128 + j, 13, 2);
                break;
            case 20:
                break;
            }
        }
    }
}

void Castle::DrawCastleFlag(short posy)
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            switch (castleFlag[j][i])
            {
            case 4:
                _print.DrawChar(i * 2 + 406, j + 144 + posy, 4, 9);
                break;
            case 14:
                _print.DrawChar(i * 2 + 406, j + 144 + posy, 14, 9);
                break;
            case 15:
                _print.DrawChar(i * 2 + 406, j + 144 + posy, 15, 9);
                break;
            case 20:
                break;
            }
        }
    }
}



