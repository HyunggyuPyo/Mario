#include "Flag.h"

Flag::Flag()
{
    posY = 48;
}

Flag::~Flag()
{
}

void Flag::DrawFlagHead(short posx, short posy, short startpPosX, short cutArr)
{
    for (int i = 0; i < cutArr; i++)
    {
        if (cutArr > 8)
        {
            cutArr = 8;
        }
        for (int j = 0; j < 8; j++)
        {
            switch (flagHead[j][i])
            {
            case 0:
                _print.DrawChar(posx + i * 2 + startpPosX, posy + j, 0, 7);
                break;
            case 2:
                _print.DrawChar(posx + i * 2 + startpPosX, posy + j, 2, 7);
                break;
            case 15:
                _print.DrawChar(posx + i * 2 + startpPosX, posy + j, 15, 7);
                break;
            case 20:
                break;
            }
        }
    }
}

void Flag::DrawFlagBody(short posx, short posy, short startpPosX, short cutArr)
{
    for (int i = 0; i < cutArr; i++)
    {
        if (cutArr > 8)
        {
            cutArr = 8;
        }
        for (int j = 0; j < 16; j++)
        {
            switch (flagBody[j][i])
            {
            case 10:
                _print.DrawChar(posx + i * 2 + startpPosX, posy + j, 10, 8);
                break;
            case 20:
                break;
            }
        }
    }
}

void Flag::DrawFlagTail(short posx, short posy, short startpPosX, short cutArr)
{
    for (int i = 0; i < cutArr; i++)
    {
        if (cutArr > 16)
        {
            cutArr = 16;
        }
        for (int j = 0; j < 16; j++)
        {
            switch (flagTail[j][i])
            {
            case 2:
                _print.DrawChar(posx + i * 2 + startpPosX, posy + j, 2, 7);
                break;
            case 15:
                _print.DrawChar(posx + i * 2 + startpPosX, posy + j, 15, 7);
                break;
            case 20:
                break;
            }
        }
    }
}

void Flag::DrawBlock(short posx, short posy, short startpPosX, short cutArr)
{
    for (int i = 0; i < cutArr; i++)
    {
        if (cutArr > 16)
        {
            cutArr = 16;
        }
        for (int j = 0; j < 16; j++)
        {
            switch (block[j][i])
            {
            case 0:
                _print.DrawChar(posx + i * 2 + startpPosX, posy + j, 0, 0);
                break;
            case 5:
                _print.DrawChar(posx + i * 2 + startpPosX, posy + j, 5, 0);
                break;
            case 13:
                _print.DrawChar(posx + i * 2 + startpPosX, posy + j, 13, 0);
                break;
            case 20:
                break;
            }
        }
    }
}

void Flag::FlagDraw(short startpPosX, short cutArr)
{
    DrawBlock(96, 192, startpPosX, cutArr);

    short posy = 176;
    for (int i = 0; i < 9; i++)
    {
        DrawFlagBody(104, posy, startpPosX, cutArr);
        posy -= 16;
    }

    DrawFlagHead(104, 40, startpPosX, cutArr);
    DrawFlagTail(80, posY, startpPosX, cutArr);
}

bool Flag::SetFlagPosY(short value)
{
    posY += value;

    if (posY >= 176)
    {
        posY = 176;
        return true;
    }
    return false;
}


