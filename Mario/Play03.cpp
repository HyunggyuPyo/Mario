#include "Play03.h"

#define BACKGROUND_COLOR 0x0030

Play03::Play03()
{
    mapPosX = 0;
    rmapPosX = 480;
    mapHalf = 224;
}

Play03::~Play03()
{
}

void Play03::Game()
{
    _print.DrawSize();
    _print.init();
    _print.CustomConsoleColor();

    Round03* _round03 = new Round03;
    Ui* _ui = new Ui;

    short walking = 0;
    //화면을 벗어나지 못하게 
    short MinPosX = 10;
    short MaxPosX = 512;

    // 블럭과 충돌시 움직임 제한
    short moveRigth = 1;
    short moveLeft = 1;

    // 게임 엔딩 애니메이션
    short tempPosY = 0;
    bool checkend = false;
    
    // 마리오 좌표 이동
    _mario.SetMarioPosX(2, 16);
    _mario.SetMarioPosY(2, 160);

    while (true)
    {
        // 마리오 깃발 도착
        if (rmapPosX == 150)
        {
            Sleep(500);
            tempPosY = _mario.GetMarioPosY();
            _mario.GoalScore(tempPosY);
            break;
        }

        _print.ClearBuffer(BACKGROUND_COLOR);
        _round03->Map(mapPosX, rmapPosX);
        _ui->UiDraw();

        //마리오 오른쪽 블럭 충돌 (이동불가)
        if (_mario.CheackMarioPosition2(36, 1, ' ') ||
            _mario.CheackMarioPosition2(36, 15, ' '))
        {
            moveRigth = 0;
        }
        else
        {
            moveRigth = 1;
        }
        //마리오 왼쪽 블럭 충돌 (이동불가)
        if (_mario.CheackMarioPosition2(2, 1, ' ') ||
            _mario.CheackMarioPosition2(2, 15, ' '))
        {
            moveLeft = 0;
        }
        else
        {
            moveLeft = 1;
        }

        _mario.BottomCheck();

        if (_mario.IsBottomBool())
        {
            _mario.DrawMario(0);
        }

        if (GetAsyncKeyState(VK_LEFT) & 0x8000) { 
            if (_mario.GetMarioPosX() <= MinPosX)
            {
                _mario.SetMarioPosX(2, MinPosX);
            }
            else
            {
                _print.ClearBuffer(BACKGROUND_COLOR);
                _round03->Map(mapPosX, rmapPosX);
                _ui->UiDraw();
                walking++;
                // 마리오 이동 애니메이션
                switch (walking % 3)
                {
                case 0:
                    _mario.SetMarioPosX(1, 16 * moveLeft);
                    _mario.DrawMario(2);
                    break;
                case 1:
                    _mario.SetMarioPosX(1, 16 * moveLeft);
                    _mario.DrawMario(3);
                    break;
                case 2:
                    _mario.SetMarioPosX(1, 16 * moveLeft);
                    _mario.DrawMario(4);
                    break;
                }
            }
        }

        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
            // 맵이 끝까지 이동하지 않았을 경우 마리오는 맵 왼쪽 절반에서만 움직임이 가능
            if (_mario.GetMarioPosX() >= mapHalf)
            {
                if (mapPosX == 240)
                {
                    mapPosX = 240;
                }
                else
                {
                    // 맵 이동
                    _mario.SetMarioPosX(2, mapHalf);
                    mapPosX += 15;
                    rmapPosX -= 30;
                }
            }

            if (_mario.GetMarioPosX() >= MaxPosX)
            {
                _mario.SetMarioPosX(2, MaxPosX - 32);

            }
            else
            {
                _print.ClearBuffer(BACKGROUND_COLOR);
                _round03->Map(mapPosX, rmapPosX);
                _ui->UiDraw();
                walking++;
                // 마리오 이동 애니메이션
                switch (walking % 3)
                {
                case 0:
                    _mario.SetMarioPosX(0, 16 * moveRigth);
                    _mario.DrawMario(2);
                    break;
                case 1:
                    _mario.SetMarioPosX(0, 16 * moveRigth);
                    _mario.DrawMario(3);
                    break;
                case 2:
                    _mario.SetMarioPosX(0, 16 * moveRigth);
                    _mario.DrawMario(4);
                    break;
                }
            }
        }
        if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
            if (_mario.IsBottomBool())
            {
                _mario.SetJumping(1);
                _mario.SetBottom(0);
            }
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
        }

        // 마리오 점프 관리
        if (!(_mario.IsBig()))
        {
            if (_mario.IsJumpingBool())
            {
                _print.ClearBuffer(BACKGROUND_COLOR);
                _round03->Map(mapPosX, rmapPosX);
                _ui->UiDraw();
                _mario.SetMarioPosY(1, 16);
                _mario.DrawMario(1);
                _mario.JumpingCountUp();
            }
            else if (!(_mario.IsBottomBool()))
            {
                _print.ClearBuffer(BACKGROUND_COLOR);
                _round03->Map(mapPosX, rmapPosX);
                _ui->UiDraw();
                _mario.SetMarioPosY(0, 16);
                _mario.DrawMario(1);
                _mario.FixBottom();
            }
        }
        else
        {
            if (_mario.IsJumpingBool())
            {
                _print.ClearBuffer(BACKGROUND_COLOR);
                _round03->Map(mapPosX, rmapPosX);
                _ui->UiDraw();
                _mario.SetMarioPosY(1, 16);
                _mario.DrawMario(1);
                _mario.JumpingCountUp();
            }
            else if (!(_mario.IsBottomBool()))
            {
                _print.ClearBuffer(BACKGROUND_COLOR);
                _round03->Map(mapPosX, rmapPosX);
                _ui->UiDraw();
                _mario.SetMarioPosY(0, 16);
                _mario.DrawMario(1);
                _mario.FixBottom();
            }
        }

        _mario.JumpCountCheck();
        _print.swapBuffer();
    }
    PlaySound(NULL, 0, 0);
    // 엔딩 깃발 애니메이션
    while (true)
    {
        // 화면 출력
        _print.ClearBuffer(BACKGROUND_COLOR);
        _round03->Map(mapPosX, rmapPosX);
        _ui->UiDraw();
        _mario.SetMarioPosY(2, tempPosY);
        
        if (checkend)
        {
            _mario.SetMarioPosX(2, 272);
            _mario.SetMarioPosY(2, 192);
            PlaySound(TEXT("RoundClear.wav"), 0, SND_FILENAME | SND_ASYNC);
            break;
        }
        // 깃발 내려가는 애니메이션
        if (_round03->SetFlagPosY(8))
        {
            _mario.SetMarioPosX(2, 252);
            _mario.DrawMario(6);
            
            checkend = true;
        }
        else
        {
            _mario.DrawMario(5);
        }
        // 마리오 내려가는 애니메이션
        tempPosY += 8;

        if (tempPosY >= 176)
        {
            tempPosY = 176;
        }

        _print.swapBuffer();
    }
    walking = 0;

    // 엔딩 성 애니메이션
    short end = 0;
    while (true)
    {
        _print.ClearBuffer(BACKGROUND_COLOR);
        _round03->Map(mapPosX, rmapPosX);
        _ui->UiDraw();

        _mario.SetMarioPosX(0, 16);

        walking++;

        if (walking <= 8)
        {
            switch (walking % 3)
            {
            case 0:
                _mario.DrawMario(2);
                break;
            case 1:
                _mario.DrawMario(3);
                break;
            case 2:
                _mario.DrawMario(4);
                break;
            }
        }
        else
        {
            // 성 깃발 애니메이션
            end++;
            _round03->RoundClear();
            _round03->FlagAni();
            if (end == 9)
            {
                _mario.GameSet(0);
                break;
            }
        }
        _print.swapBuffer();
    }

    delete _round03;
    delete _ui;
}