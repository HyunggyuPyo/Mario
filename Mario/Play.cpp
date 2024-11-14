#include "Play.h"

#define BACKGROUND_BLACK 0x0000
#define BACKGROUND_COLOR 0x0030

Play::Play()
{
    resetValue();
}

Play::~Play()
{
}

void Play::resetValue()
{
    gameOver = false;
    MaxPosY = 200;
    mapPosX = 0;
    rmapPosX = 480;
    mapHalf = 224;
}

void Play::Game()
{
    _print.DrawSize();
    _print.init();
    _print.CustomConsoleColor();

    Round01* _round01 = new Round01;
    Ui* _ui = new Ui;

    short walking = 0;
    //ȭ���� ����� ���ϰ� 
    short MinPosX = 10;
    short MaxPosX = 512;

    // ���� �浹�� ������ ����
    short moveRigth = 1;
    short moveLeft = 1;

    _print.ClearBuffer(BACKGROUND_BLACK);
    _ui->RoundInfoDraw();
    _print.swapBuffer();
    Sleep(2000);

    while (true)
    {
        _round01->CheckMushroom();
        // �ʱ�ȭ�� ���ۿ� ui, map ���
        _print.ClearBuffer(BACKGROUND_COLOR);
        _round01->Map(mapPosX, rmapPosX);
        _ui->UiDraw();

        // ���� �浹 (����)
        if (_mario.CheackMarioPosition(0, 15, '1') ||
            _mario.CheackMarioPosition(32, 16, '1'))
        {
            _mario.SetMarioPosY(1, 16);
            _print.ClearBuffer(BACKGROUND_COLOR);
            _round01->Map(mapPosX, rmapPosX);
            _ui->UiDraw();
            _mario.DrawMario(1);
            _print.swapBuffer();
            _round01->EnemyDie();
        }

        //���� �浹 (����)
        if (_mario.CheackMarioPosition(25, 1, '1') ||
            _mario.CheackMarioPosition(20, 13, '1'))
        {
            _print.ClearBuffer(BACKGROUND_COLOR);
            _round01->Map(mapPosX, rmapPosX);
            _ui->UiDraw();
            // ������ ���¿� ���� ��� ����
            if (!(_mario.IsBig()))
            {
                _mario.MarioHit();
                _mario.DrawMario(7);
                _print.swapBuffer();
                
                PlaySound(NULL, 0, 0);
                PlaySound(TEXT("MarioHit.wav"), 0, SND_FILENAME | SND_ASYNC);
                Sleep(3000);
                if (_mario.GetLife() != 0)
                {
                    delete _round01;
                    delete _ui;

                    _mario.SetMarioPosX(2, 64);
                    PlaySound(TEXT("MarioBGM.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
                    resetValue();
                    Game();
                    
                }
                else if (_mario.GetLife() == 0)
                {
                    PlaySound(TEXT("GameOver.wav"), 0, SND_FILENAME | SND_ASYNC);
                    Sleep(1000);
                    _print.ClearBuffer(BACKGROUND_BLACK);
                    _ui->GameOver();
                    _print.swapBuffer();
                    gameOver = true;
                    Sleep(3000);
                    break;
                }
            }
            else
            {
                _mario.MarioHit();
                _mario.DrawMario(1);
                _print.swapBuffer();
            }  
        }

        // ���� �浹
        if (_mario.CheackMarioPosition(34, 1, '3') ||
            _mario.CheackMarioPosition(34, 5, '3'))
        {
            _mario.MarioSizeUp();
            _mario.SetMarioPosY(1, 16);
            _round01->EatMushroom();
        }

        //������ ������ �� �浹 (�̵��Ұ�)
        if (_mario.CheackMarioPosition2(36, 1, ' ') ||
            _mario.CheackMarioPosition2(36, 15, ' '))
        {
            moveRigth = 0;
        }
        else
        {
            moveRigth = 1;
        }
        //������ ���� �� �浹 (�̵��Ұ�)
        if (_mario.CheackMarioPosition2(2, 1, ' ') ||
            _mario.CheackMarioPosition2(2, 15, ' '))
        {
            moveLeft = 0;
        }
        else
        {
            moveLeft = 1;
        }

        //���� �� �浹
        if (_mario.CheackMarioPosition(2, -1, '2') ||
            _mario.CheackMarioPosition(30, -1, '2'))
        {
            _mario.SetJumping(0);
            if (!(_round01->CheckRandBlock()))
            {
                _round01->TouchRandomBlock();
            }
        }

        //���� �浹
        if (_round01->BrickGetposY() < 144)
        {
            _round01->BlockAniDown();
        }

        if (_mario.CheackMarioPosition(2, -1, '6') ||
            _mario.CheackMarioPosition(30, -1, '6'))
        {
            _mario.SetJumping(0);

            if (!(_mario.IsBig()))
            {
                _round01->BlockAniUp();
            }
            else
            {
                _round01->TouchBrickBlock();
            }  
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
                _round01->Map(mapPosX, rmapPosX);
                _ui->UiDraw();
                walking++;
                // ������ �̵� �ִϸ��̼�
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
            // ���� ������ �̵����� �ʾ��� ��� �������� �� ���� ���ݿ����� �������� ����
            if (_mario.GetMarioPosX() >= mapHalf)
            {
                if (mapPosX == 240)
                {
                    mapPosX = 240;
                }
                else
                {
                    // �� �̵�
                    _mario.SetMarioPosX(2, mapHalf);
                    mapPosX += 15;
                    rmapPosX -= 30;
                }
            }
            // ���� ����� ���ϰ�
            if (_mario.GetMarioPosX() >= MaxPosX)
            {
                _mario.SetMarioPosX(2, MaxPosX - 32);

            }
            else
            {
                _print.ClearBuffer(BACKGROUND_COLOR);
                _round01->Map(mapPosX, rmapPosX);
                _ui->UiDraw();
                walking++;
                // ������ �̵� �ִϸ��̼�
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
            // pipe������ Ŭ�� �� �� �̵�
            if (_mario.CheackMarioPosition(4, 17, '5'))
            {
                _mario.TestCoin();
                _print.ClearBuffer(BACKGROUND_BLACK);
                _mario.SetMarioPosX(2, 40);
                _mario.SetMarioPosY(2, 192);
                break;
            }
        }

        // ������ ���� ����
        if (!(_mario.IsBig()))
        {
            if (_mario.IsJumpingBool())
            {
                _print.ClearBuffer(BACKGROUND_COLOR);
                _round01->Map(mapPosX, rmapPosX);
                _ui->UiDraw();
                _mario.DrawMario(1);
                _mario.SetMarioPosY(1, 16);
                _mario.JumpingCountUp();
            }
            else if (!(_mario.IsBottomBool()))
            {
                _print.ClearBuffer(BACKGROUND_COLOR);
                _round01->Map(mapPosX, rmapPosX);
                _ui->UiDraw();
                _mario.DrawMario(1);
                _mario.SetMarioPosY(0, 16);
                _mario.FixBottom();
            }
        }
        else
        {
            if (_mario.IsJumpingBool())
            {
                _print.ClearBuffer(BACKGROUND_COLOR);
                _round01->Map(mapPosX, rmapPosX);
                _ui->UiDraw();
                _mario.DrawMario(1);
                _mario.SetMarioPosY(1, 16);
                _mario.JumpingCountUp();
            }
            else if (!(_mario.IsBottomBool()))
            {
                _print.ClearBuffer(BACKGROUND_COLOR);
                _round01->Map(mapPosX, rmapPosX);
                _ui->UiDraw();
                _mario.DrawMario(1);
                _mario.SetMarioPosY(0, 16);
                _mario.FixBottom();
            }
        }

        _mario.JumpCountCheck();
        _print.swapBuffer();
    }

    delete _round01;
    delete _ui;
}

bool Play::GameOver()
{
    return gameOver;
}



