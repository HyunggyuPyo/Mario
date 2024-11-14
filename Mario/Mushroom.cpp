#include "Mushroom.h"

Mushroom::Mushroom()
{
    mushroomPosX = 0;
    mushroomPosY = 128;
    posX = 0;
    posY = 0;
    turnNegative = false;
    eatMushroom = false;
    outSreen = false;
}

Mushroom::~Mushroom()
{
}

void Mushroom::DrawMushroom(short startPos)
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            switch (mushroom[j][i])
            {
            case 4:
                _print.DrawChar(mushroomPosX + i * 2 + startPos, mushroomPosY + j, 4, 3);
                break;
            case 12:
                _print.DrawChar(mushroomPosX + i * 2 + startPos, mushroomPosY + j, 12, 3);
                break;
            case 15:
                _print.DrawChar(mushroomPosX + i * 2 + startPos, mushroomPosY + j, 15, 3);
                break;
            case 20:
                break;
            }
        }
    }
    posX = mushroomPosX + startPos;
    posY = mushroomPosY;
}

void Mushroom::MushroomMove()
{
    if (turnNegative)
    {
        mushroomPosX -= 16;
    }
    else
    {
        mushroomPosX += 16;
    }
}

void Mushroom::CheckMushroom()
{
    if (mushroomPosX >= 64)
    {
        mushroomPosY += 8;
    }

    if (mushroomPosY >= 192)
    {
        mushroomPosY = 192;
    }

    if (mushroomPosY >= 160 && _print.checkPosition(posX + 64, posY - 16) != ' ')
    {
        turnNegative = true;
    }

    if (mushroomPosX < 8)
    {
        outSreen = true;
    }
}

void Mushroom::EatMushroom()
{
    eatMushroom = true;
    _mario.ScoreUp(10);
}

bool Mushroom::GetEatMushroom()
{
    return eatMushroom;
}

bool Mushroom::DeleteMushroom()
{
    return outSreen;
}
