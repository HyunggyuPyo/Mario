#include "BrickBlock.h"

BrickBlock::BrickBlock()
{
    posY = 144;
    breakBlock = false;
}

BrickBlock::~BrickBlock()
{
}

void BrickBlock::DrawBlock(short posX, short startpPosX, short cutArr)
{
    for (int i = 0; i < cutArr; i++)
    {
        if (cutArr > 16)
        {
            cutArr = 16;
        }
        for (int j = 0; j < 16; j++)
        {
            switch (brickBlock[j][i])
            {
            case 0:
                _print.DrawChar(posX + i * 2 + startpPosX, posY + j, 0, 6);
                break;
            case 5:
                _print.DrawChar(posX + i * 2 + startpPosX, posY + j, 5, 6);
                break;
            case 6:
                _print.DrawChar(posX + i * 2 + startpPosX, posY + j, 6, 6);
                break;
            case 12:
                _print.DrawChar(posX + i * 2 + startpPosX, posY + j, 12, 6);
                break;
            case 13:
                _print.DrawChar(posX + i * 2 + startpPosX, posY + j, 13, 6);
                break;
            case 14:
                _print.DrawChar(posX + i * 2 + startpPosX, posY + j, 14, 6);
                break;
            case 20:
                break;
            }
        }
    }
}

void BrickBlock::TouchBlock()
{
    posY -= 4;
}

void BrickBlock::BlockAni()
{
    posY += 4;
}

void BrickBlock::BreakBlock()
{
    posY -= 4;
    breakBlock = true;
}

bool BrickBlock::BreakCheck()
{
    return breakBlock;
}

short BrickBlock::GetposY()
{
    return posY;
}




