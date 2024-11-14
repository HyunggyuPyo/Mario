#include "Enemy.h"

Enemy::Enemy()
{
    posX = 400;
    enemyAni = true;
    enemyDie = false;
}

Enemy::~Enemy()
{
}

void Enemy::DrawEnemy(short posX, short cutArr, int arr[4][16])
{
    for (int i = cutArr; i < 16; i++)
    {
        if (cutArr > 16)
        {
            cutArr = 16;
        }
        for (int j = 0; j < 16; j++)
        {
            if (j <= 11)
            {
                switch (enemyBody[j][i])
                {
                case 0:
                    _print.DrawChar(posX + i * 2, 192 + j, 0, 1);
                    break;
                case 5:
                    _print.DrawChar(posX + i * 2, 192 + j, 5, 1);
                    break;
                case 14:
                    _print.DrawChar(posX + i * 2, 192 + j, 14, 1);
                    break;
                case 20:
                    break;
                }
            }
            else
            {
                switch (arr[j - 12][i])
                {
                case 0:
                    _print.DrawChar(posX + i * 2, 192 + j, 0, 1);
                    break;
                case 14:
                    _print.DrawChar(posX + i * 2, 192 + j, 14, 1);
                    break;
                case 20:
                    break;
                }
            }

        }
    }
}

void Enemy::EnemyMove()
{
    posX -= 8;
}

void Enemy::EnemyMoveAni()
{
    if (!enemyDie && posX >= 0)
    {
        if (enemyAni)
        {
            DrawEnemy(posX, 0, enemyLegR);
            enemyAni = false;
        }
        else
        {
            DrawEnemy(posX, 0, enemyLegL);
            enemyAni = true;
        }

    }
}

void Enemy::EnemyDie()
{
    enemyDie = true;
    _mario.ScoreUp(1);
}
