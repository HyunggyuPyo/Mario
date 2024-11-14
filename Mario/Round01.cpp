#include "Round01.h"

Round01::Round01()
{
}
    
Round01::~Round01()
{
    delete _mushroom;
    delete _enemy;
    delete _randomBlock;
    delete _brickBlock; 
}

void Round01::Map(short mpos, short rmpos)
{
    DrawMap01(0, 0, mpos);
    DrawMap02(0, 0, rmpos, mpos);

    _enemy->EnemyMove();
    _enemy->EnemyMoveAni();

    if (!(_randomBlock->CheckBlock()))
    {
        _randomBlock->DrawBlock(0, rmpos, mpos);
    }
    else
    {
        if (!(_mushroom->GetEatMushroom()))
        {
            _randomBlock->DrawTouchRandomBlock(0, rmpos, mpos);
            _mushroom->DrawMushroom(rmpos);
            _mushroom->CheckMushroom();
            _mushroom->MushroomMove();
            if (!(_randomBlock->UseCheckBlock()))
            {
                _randomBlock->BlockAni();
            }
            
        }
        else
        {
            _randomBlock->DrawTouchRandomBlock(0, rmpos, mpos);
        }
    }

    if (!(_brickBlock->BreakCheck()))
    {
        _brickBlock->DrawBlock(32, rmpos, mpos - 16);
    }
}

void Round01::TouchRandomBlock()
{
    _randomBlock->TouchBlock();
}

void Round01::RandomBlockAni()
{
    _randomBlock->BlockAni();
}

bool Round01::CheckRandBlock()
{
    return _randomBlock->CheckBlock();
}


void Round01::DrawMap01(int arrx, int arry, int cutArr)
{
    short k = 0;
    for (int i = cutArr; i < 240; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            switch (round01Test[arrx + j][arry + i])
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

void Round01::DrawMap02(int arrx, int arry, int startposx, int cutArr)
{
    for (int i = 0; i < cutArr; i++)
    {
        for (int j = 0; j < 48; j++)
        {
            switch (round02Test[arrx + j][arry + i])
            {
            case 0:
                _print.DrawChar(i * 2 + startposx, j + 176, 0, 0);
                break;
            case 2:
                _print.DrawChar(i * 2 + startposx, j + 176, 2, 0);
                break;
            case 5:
                _print.DrawChar(i * 2 + startposx, j + 176, 5, 0);
                break;
            case 7:
                _print.DrawChar(i * 2 + startposx, j + 176, 7, 1);
                break;
            case 8:
                _print.DrawChar(i * 2 + startposx, j + 176, 8, 1);
                break;
            case 10:
                _print.DrawChar(i * 2 + startposx, j + 176, 10, 5);
                break;
            case 13:
                _print.DrawChar(i * 2 + startposx, j + 176, 13, 0);
                break;
            }
        }
    }
}


void Round01::EnemyDie()
{
    _enemy->EnemyDie();
}

void Round01::CheckMushroom()
{
    _mushroom->CheckMushroom();
}

void Round01::EatMushroom()
{
    _mushroom->EatMushroom();
}

void Round01::TouchBrickBlock()
{
    _brickBlock->BreakBlock();
}

void Round01::BlockAniUp()
{
    _brickBlock->TouchBlock();
}

void Round01::BlockAniDown()
{
    _brickBlock->BlockAni();
}

short Round01::BrickGetposY()
{
    return _brickBlock->GetposY();
}
