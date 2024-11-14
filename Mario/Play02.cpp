#include "Play02.h"

#define BACKGROUND_COLOR 0x0000

Play02::Play02()
{
}

Play02::~Play02()
{
}

void Play02::Game()
{
    _print.DrawSize();
    _print.init();
    _print.CustomConsoleColor();

    Ui* _ui = new Ui;

    short walking = 0;
    //화면을 벗어나지 못하게 
    short MinPosX = 10;
    short MaxPosX = 512;

    // 블럭과 충돌 체크
    short moveRigth = 1;
    short moveLeft = 1;

    bool blockDown = false;
    short bdcount = 0;

    while (true)
    {
        _print.ClearBuffer(BACKGROUND_COLOR);
        _round02.Map();
        _ui->UiDraw();

        //마리오 오른쪽 블럭 충돌 (이동불가)
        if (_mario.CheackMarioPosition2(34, 1, ' ') ||
            _mario.CheackMarioPosition2(34, 15, ' '))
        {
            moveRigth = 0;
        }
        else
        {
            moveRigth = 1;
        }

        //마리오 왼쪽 블럭 충돌 (이동불가)
        if (_mario.CheackMarioPosition2(-4, 1, ' ') ||
            _mario.CheackMarioPosition2(-4, 15, ' '))
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
                _print.ClearMarioB(BACKGROUND_COLOR, _mario.GetMarioPosX(), _mario.GetMarioPosY(), _mario.GetMarioPosX() + 32, _mario.GetMarioPosY() + 15);
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
            if (_mario.GetMarioPosX() >= MaxPosX)
            {
                _mario.SetMarioPosX(2, MaxPosX - 32);

            }
            else
            {
                _print.ClearMarioB(BACKGROUND_COLOR, _mario.GetMarioPosX(), _mario.GetMarioPosY(), _mario.GetMarioPosX() + 32, _mario.GetMarioPosY() + 15);
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
            // 파이프가 앞에 있을대 클릭 시 맵 이동
            if (_mario.CheackMarioPosition(40, 1, '5') ||
                _mario.CheackMarioPosition(40, 15, '5'))
            {
                break;
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
                _round02.Map();
                _mario.DrawMario(1);
                _ui->UiDraw();
                _mario.SetMarioPosY(1, 16);
                _mario.JumpingCountUp();
            }
            else if (!(_mario.IsBottomBool()))
            {
                _print.ClearBuffer(BACKGROUND_COLOR);
                _round02.Map();
                _ui->UiDraw();
                _mario.DrawMario(1);
                if (_mario.CheackMarioPosition2(16, 20, ' '))
                {
                    _mario.SetMarioPosY(0, 4);
                }
                else
                {
                    _mario.SetMarioPosY(0, 16);
                }
            }
        }
        else
        {
            if (_mario.IsJumpingBool())
            {
                _print.ClearBuffer(BACKGROUND_COLOR);
                _round02.Map();
                _ui->UiDraw();
                _mario.DrawMario(1);
                _mario.SetMarioPosY(1, 16);
                _mario.JumpingCountUp();
            }
            else if (!(_mario.IsBottomBool()))
            {
                _print.ClearBuffer(BACKGROUND_COLOR);
                _round02.Map();
                _ui->UiDraw();
                _mario.DrawMario(1);
                if (_mario.CheackMarioPosition2(16, 36, ' '))
                {
                    _mario.SetMarioPosY(0, 8);
                }
                else
                {
                    _mario.SetMarioPosY(0, 16);
                }
            }
        }
        // 코인 100개를 넘기면 목숨 += 1, 코인 초기화 
        if (_mario.GetCoinCount() == 100)
        {
            _mario.LifeUp();
        }

        _round02.CheckCoin();
        _mario.JumpCountCheck();
        _print.swapBuffer();
    }
    delete _ui;
}
