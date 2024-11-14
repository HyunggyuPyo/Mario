#include "Mario.h"

short Mario::life = 3;
short Mario::coinCount = 0;
short Mario::scoreCount = 0;
bool Mario::isBig = false;

Mario::Mario()
{
    posX = 64;
    posY = 192;

    isJumping = false;
    isBottom = true;
    jumpCount = 0;
}
Mario::~Mario()
{
}

void Mario::MarioSizeUp()
{
    isBig = true;
}

void Mario::MarioSizeDown()
{
    isBig = false;
}

void Mario::DrawMario(short dotnum)
{
    for (int i = 0; i < 16; i++)
    {
        if (!isBig)
        {
            switch (dotnum)
            {
            case 0:
                for (int j = 0; j < 16; j++)
                {
                    switch (MarioIdle[j][i])
                    {
                    case 4:
                        _print.DrawChar(posX + i * 2, j + posY, 4, 4);
                        break;
                    case 6:
                        _print.DrawChar(posX + i * 2, j + posY, 6, 4);
                        break;
                    case 14:
                        _print.DrawChar(posX + i * 2, j + posY, 14, 4);
                        break;
                    case 20:
                        break;
                    }
                }
                break;
            case 1:
                for (int j = 0; j < 16; j++)
                {
                    switch (MarioJump[j][i])
                    {
                    case 4:
                        _print.DrawChar(posX + i * 2, j + posY, 4, 4);
                        break;
                    case 6:
                        _print.DrawChar(posX + i * 2, j + posY, 6, 4);
                        break;
                    case 14:
                        _print.DrawChar(posX + i * 2, j + posY, 14, 4);
                        break;
                    case 20:
                        break;
                    }
                }
                break;
            case 2:
                for (int j = 0; j < 16; j++)
                {
                    switch (MarioRun01[j][i])
                    {
                    case 4:
                        _print.DrawChar(posX + i * 2, j + posY, 4, 4);
                        break;
                    case 6:
                        _print.DrawChar(posX + i * 2, j + posY, 6, 4);
                        break;
                    case 14:
                        _print.DrawChar(posX + i * 2, j + posY, 14, 4);
                        break;
                    case 20:
                        break;
                    }
                }
                break;
            case 3:
                for (int j = 0; j < 16; j++)
                {
                    switch (MarioRun02[j][i])
                    {
                    case 4:
                        _print.DrawChar(posX + i * 2, j + posY, 4, 4);
                        break;
                    case 6:
                        _print.DrawChar(posX + i * 2, j + posY, 6, 4);
                        break;
                    case 14:
                        _print.DrawChar(posX + i * 2, j + posY, 14, 4);
                        break;
                    case 20:
                        break;
                    }
                }
                break;
            case 4:
                for (int j = 0; j < 16; j++)
                {
                    switch (MarioRun03[j][i])
                    {
                    case 4:
                        _print.DrawChar(posX + i * 2, j + posY, 4, 4);
                        break;
                    case 6:
                        _print.DrawChar(posX + i * 2, j + posY, 6, 4);
                        break;
                    case 14:
                        _print.DrawChar(posX + i * 2, j + posY, 14, 4);
                        break;
                    case 20:
                        break;
                    }
                }
                break;
            case 5:
                for (int j = 0; j < 16; j++)
                {
                    switch (MarioGoalLeft[j][i])
                    {
                    case 4:
                        _print.DrawChar(posX + i * 2, j + posY, 4, 4);
                        break;
                    case 6:
                        _print.DrawChar(posX + i * 2, j + posY, 6, 4);
                        break;
                    case 14:
                        _print.DrawChar(posX + i * 2, j + posY, 14, 4);
                        break;
                    case 20:
                        break;
                    }
                }
                break;
            case 6:
                for (int j = 0; j < 16; j++)
                {
                    switch (MarioGoalRight[j][i])
                    {
                    case 4:
                        _print.DrawChar(posX + i * 2, j + posY, 4, 4);
                        break;
                    case 6:
                        _print.DrawChar(posX + i * 2, j + posY, 6, 4);
                        break;
                    case 14:
                        _print.DrawChar(posX + i * 2, j + posY, 14, 4);
                        break;
                    case 20:
                        break;
                    }
                }
                break;
            case 7:
                for (int j = 0; j < 16; j++)
                {
                    switch (MarioDie[j][i])
                    {
                    case 4:
                        _print.DrawChar(posX + i * 2, j + posY, 4, 4);
                        break;
                    case 6:
                        _print.DrawChar(posX + i * 2, j + posY, 6, 4);
                        break;
                    case 14:
                        _print.DrawChar(posX + i * 2, j + posY, 14, 4);
                        break;
                    case 20:
                        break;
                    }
                }
                break;
            }
        }
        else
        {
            switch (dotnum)
            {
            case 0:
                for (int j = 0; j < 32; j++)
                {
                    switch (bigMarioIdle[j][i])
                    {
                    case 4:
                        _print.DrawChar(posX + i * 2, j + posY, 4, 4);
                        break;
                    case 6:
                        _print.DrawChar(posX + i * 2, j + posY, 6, 4);
                        break;
                    case 14:
                        _print.DrawChar(posX + i * 2, j + posY, 14, 4);
                        break;
                    case 20:
                        break;
                    }
                }
                break;
            case 1:
                for (int j = 0; j < 32; j++)
                {
                    switch (bigMarioJump[j][i])
                    {
                    case 4:
                        _print.DrawChar(posX + i * 2, j + posY, 4, 4);
                        break;
                    case 6:
                        _print.DrawChar(posX + i * 2, j + posY, 6, 4);
                        break;
                    case 14:
                        _print.DrawChar(posX + i * 2, j + posY, 14, 4);
                        break;
                    case 20:
                        break;
                    }
                }
                break;
            case 2:
                for (int j = 0; j < 32; j++)
                {
                    switch (bigMarioRun01[j][i])
                    {
                    case 4:
                        _print.DrawChar(posX + i * 2, j + posY, 4, 4);
                        break;
                    case 6:
                        _print.DrawChar(posX + i * 2, j + posY, 6, 4);
                        break;
                    case 14:
                        _print.DrawChar(posX + i * 2, j + posY, 14, 4);
                        break;
                    case 20:
                        break;
                    }
                }
                break;
            case 3:
                for (int j = 0; j < 32; j++)
                {
                    switch (bigMarioRun02[j][i])
                    {
                    case 4:
                        _print.DrawChar(posX + i * 2, j + posY, 4, 4);
                        break;
                    case 6:
                        _print.DrawChar(posX + i * 2, j + posY, 6, 4);
                        break;
                    case 14:
                        _print.DrawChar(posX + i * 2, j + posY, 14, 4);
                        break;
                    case 20:
                        break;
                    }
                }
                break;
            case 4:
                for (int j = 0; j < 32; j++)
                {
                    switch (bigMarioRun03[j][i])
                    {
                    case 4:
                        _print.DrawChar(posX + i * 2, j + posY, 4, 4);
                        break;
                    case 6:
                        _print.DrawChar(posX + i * 2, j + posY, 6, 4);
                        break;
                    case 14:
                        _print.DrawChar(posX + i * 2, j + posY, 14, 4);
                        break;
                    case 20:
                        break;
                    }
                }
                break;
            }
        }
    }
}

void Mario::DrawMarioUi(short posx, short posy, short num)
{
    if (num == 0)
    {
        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                switch (MarioIdle[j][i])
                {
                case 4:
                    _print.DrawChar(posx + i * 2, j + posy, 4, 4);
                    break;
                case 6:
                    _print.DrawChar(posx + i * 2, j + posy, 6, 4);
                    break;
                case 14:
                    _print.DrawChar(posx + i * 2, j + posy, 14, 4);
                    break;
                case 20:
                    break;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                switch (MarioRun02[j][i])
                {
                case 4:
                    _print.DrawChar(posx + i * 2, j + posy, 4, 4);
                    break;
                case 6:
                    _print.DrawChar(posx + i * 2, j + posy, 6, 4);
                    break;
                case 14:
                    _print.DrawChar(posx + i * 2, j + posy, 14, 4);
                    break;
                case 20:
                    break;
                }
            }
        }
    }

}

short Mario::GetMarioPosX()
{
    return posX;
}

void Mario::SetMarioPosX(short sign, short num)
{
    if (sign == 0)
    {
        posX += num;
    }
    else if (sign == 1)
    {
        posX -= num;
    }
    else
    {
        posX = num;
    }
}

short Mario::GetMarioPosY()
{
    return posY;
}

void Mario::SetMarioPosY(short sign, short num)
{
    if (sign == 0)
    {
        posY += num;
    }
    else if (sign == 1)
    {
        posY -= num;
    }
    else
    {
        posY = num;
    }
}

bool Mario::CheackMarioPosition(short posx, short posy, char ch)
{
    if (!isBig)
    {
        if (_print.checkPosition(posX + posx, posY + posy) == ch)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (_print.checkPosition(posX + posx, posY + posy + 16) == ch ||
            _print.checkPosition(posX + posx, posY + posy) == ch)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}

bool Mario::CheackMarioPosition2(short posx, short posy, char ch)
{
    if (!isBig)
    {
        if (_print.checkPosition(posX + posx, posY + posy) != ch)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (_print.checkPosition(posX + posx, posY + posy + 16) != ch ||
            _print.checkPosition(posX + posx, posY + posy) != ch)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void Mario::MarioHit()
{
    if (!isBig)
    {
        life--;
        GameSet(1);
    }
    else
    {
        isBig = false;
        posX -= 32;
        posY -= 16;
    }
}

void Mario::JumpCountCheck()
{
    if (jumpCount >= 4)
    {
        isJumping = false;
    }
}

void Mario::JumpingCountUp()
{
    jumpCount++;
}

void Mario::SetJumping(short bnum)
{
    if (bnum == 0)
    {
        isJumping = false;
    }
    else
    {
        isJumping = true;
    }
}

void Mario::SetBottom(short bnum)
{
    if (bnum == 0)
    {
        isBottom = false;
    }
    else
    {
        isBottom = true;
    }
}

void Mario::BottomCheck()
{
    if (!isBig)
    {
        if (_print.checkPosition(posX + 17, posY + 16) != ' ')
        {
            isBottom = true;

            jumpCount = 0;
        }
        else
        {
            isBottom = false;
        }
    }
    else
    {
        if (_print.checkPosition(posX + 17, posY + 32) != ' ')
        {
            isBottom = true;

            jumpCount = 0;
        }
        else
        {
            isBottom = false;
        }
    }
}

void Mario::FixBottom()
{
    if (!isBig)
    {
        if (posY > 192)
        {
            posY = 192;
        }
    }
    else
    {
        if (posY > 176)
        {
            posY = 176;
        }
    }
}


bool Mario::IsBottomBool()
{
    return isBottom;
}

bool Mario::IsJumpingBool()
{
    return isJumping;
}

bool Mario::IsBig()
{
    return isBig;
}


void Mario::CollectCoin()
{
    coinCount++;
}

void Mario::TestCoin()
{
    coinCount = 97;
}

short Mario::GetCoinCount()
{
    return coinCount;
}

short Mario::GetLife()
{
    return life;
}

void Mario::ScoreUp(short sco)
{
    scoreCount += sco;
}

short Mario::GetScore()
{
    return scoreCount;
}

void Mario::LifeUp()
{
    coinCount = 0;
    life++;
}

void Mario::GoalScore(short posy)
{
    if (posy <= 32)
    {
        ScoreUp(20);
    }
    else if (posy <= 104)
    {
        ScoreUp(8);
    }
    else if (posy <= 140)
    {
        ScoreUp(4);
    }
    else
    {
        ScoreUp(1);
    }
}

void Mario::GameSet(short num)
{
    coinCount = 0;
    scoreCount = 0;
    if (num == 0)
    {
        life = 3;
    }
}
