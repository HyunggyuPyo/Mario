#include "Round03.h"

Round03::Round03()
{
    clear = false;
    flagPosY = 0;
}

Round03::~Round03()
{
    delete _flag;
    delete _castle;
}

void Round03::Map(short mpos, short rmpos)
{
    DrawMap01(0, 0, mpos);
    DrawPipe(0, 0, mpos);
    DrawPyramid(0, 0, mpos);

    DrawMap02(0, 0, rmpos, mpos);

    _flag->FlagDraw(rmpos, mpos - 52);

    if (flagPosY <= -32)
    {
        flagPosY = -32;
    }
    if (clear)
    {
        _castle->DrawCastleFlag(flagPosY);
    }

    // 성 x좌표 한칸만 떙기고 y좌표 내리기
    _castle->DrawCastle(rmpos, mpos -96);

}

void Round03::DrawMap01(int arrx, int arry, int cutArr)
{
    short k = 0;
    for (int i = cutArr; i < 240; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            switch (mapTile[arrx + j][arry + i])
            {
            case 0:
                _print.DrawChar(k * 2, j + 208, 0, 0);
                break;
            case 5:
                _print.DrawChar(k * 2, j + 208, 5, 0);
                break;
            case 13:
                _print.DrawChar(k * 2, j + 208, 13, 0);
                break;
            }
        }
        k++;
    }
}

void Round03::DrawMap02(int arrx, int arry, int startposx, int cutArr)
{
    for (int i = 0; i < cutArr; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            switch (mapTile[arrx + j][arry + i])
            {
            case 0:
                _print.DrawChar(i * 2 + startposx, j + 208, 0, 0);
                break;
            case 5:
                _print.DrawChar(i * 2 + startposx, j + 208, 5, 0);
                break;
            case 13:
                _print.DrawChar(i * 2 + startposx, j + 208, 13, 0);
                break;
            }
        }
    }
}

void Round03::DrawPipe(int arrx, int arry, int cutArr)
{
    short p = 0;
    for (int i = cutArr; i < 32; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            switch (pipe[arrx + j][arry + i])
            {
            case 0:
                _print.DrawChar(p * 2, j + 176, 0, 0);
                break;
            case 2:
                _print.DrawChar(p * 2, j + 176, 2, 0);
                break;
            case 10:
                _print.DrawChar(p * 2, j + 176, 10, 0);
                break;
            case  20:
                break;
            }
        }
        p++;
    }
}

void Round03::DrawPyramid(int arrx, int arry, int cutArr)
{
    // 걍 앞에 20/16*16 달아서 피라미드 이후 파이프 출력 
    short p = 0;
    for (int i = cutArr; i < 160; i++)
    {
        for (int j = 0; j < 128; j++)
        {
            switch (pyramid[arrx + j][arry + i])
            {
            case 0:
                _print.DrawChar(  p * 2, j + 80 , 0, 0);
                break;                                
            case 5:                                   
                _print.DrawChar(  p * 2, j + 80, 5, 0);
                break;                                
            case 13:                                  
                _print.DrawChar(  p * 2, j + 80, 13, 0);
                break;
            case  20:
                break;
            }
        }
        p++;
    }
}

bool Round03::SetFlagPosY(short value)
{
    if (_flag->SetFlagPosY(value))
    {
        return true;
    }
    return false;
}

void Round03::RoundClear()
{
    clear = true;
}

void Round03::FlagAni()
{
    flagPosY -= 8;
}


