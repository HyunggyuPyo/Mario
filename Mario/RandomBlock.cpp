#include "RandomBlock.h"

RandomBlock::RandomBlock()
{
    posY = 144;
    touchBlock = false;
    useBlock = false;
}

RandomBlock::~RandomBlock()
{
}

void RandomBlock::DrawBlock(short posX, short startpPosX, short cutArr)
{
    for (int i = 0; i < cutArr; i++)
    {
        if (cutArr > 16)
        {
            cutArr = 16;
        }
        for (int j = 0; j < 16; j++)
        {
            switch (randomBlock[j][i])
            {
            case 0:
                _print.DrawChar(posX + i * 2 + startpPosX, posY + j, 0, 2);
                break;
            case 5:
                _print.DrawChar(posX + i * 2 + startpPosX, posY + j, 5, 2);
                break;
            case 6:
                _print.DrawChar(posX + i * 2 + startpPosX, posY + j, 6, 2);
                break;
            case 12:
                _print.DrawChar(posX + i * 2 + startpPosX, posY + j, 12, 2);
                break;
            case 13:
                _print.DrawChar(posX + i * 2 + startpPosX, posY + j, 13, 2);
                break;
            case 14:
                _print.DrawChar(posX + i * 2 + startpPosX, posY + j, 14, 2);
                break;
            case 20:
                break;
            }
        }
    }
}

void RandomBlock::DrawTouchRandomBlock(short posX, short startpPosX, short cutArr)
{
    for (int i = 0; i < cutArr; i++)
    {
        if (cutArr > 16)
        {
            cutArr = 16;
        }
        for (int j = 0; j < 16; j++)
        {
            switch (touchRandomBlock[j][i])
            {
            case 0:
                _print.DrawChar(posX + i * 2 + startpPosX, posY + j, 0, 2);
                break;
            case 5:
                _print.DrawChar(posX + i * 2 + startpPosX, posY + j, 5, 2);
                break;
            case 6:
                _print.DrawChar(posX + i * 2 + startpPosX, posY + j, 6, 2);
                break;
            case 12:
                _print.DrawChar(posX + i * 2 + startpPosX, posY + j, 12, 2);
                break;
            case 13:
                _print.DrawChar(posX + i * 2 + startpPosX, posY + j, 13, 2);
                break;
            case 14:
                _print.DrawChar(posX + i * 2 + startpPosX, posY + j, 14, 2);
                break;
            case 20:
                break;
            }
        }
    }
}

void RandomBlock::TouchBlock()
{
    posY -= 4;
    touchBlock = true;
}

void RandomBlock::BlockAni()
{
    posY += 4;
    useBlock = true;
}

bool RandomBlock::CheckBlock()
{
    return touchBlock;
}

bool RandomBlock::UseCheckBlock()
{
    return useBlock;
}
