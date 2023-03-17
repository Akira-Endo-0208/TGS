#include "DxLib.h"
#include "Enemy.h"


// 初期化
void Enemy::enemyInitialize()
{

}

// 更新
void Enemy::enemyUpdate()
{
	enemyMove();
	enemyBorn();
}

// 描画
void Enemy::enemyDraw()
{
	for (int i = 0; i < 1; i++)
	{
		if (enemy1Flag[i] == 1)
		{
			DrawCircle(enemy1X[i], enemy1Y[i], enemy1R, GetColor(255, 0, 0));
		}
	}
}

// 動作
void Enemy::enemyMove()
{
	for (int i = 0; i < 1; i++)
	{
		if (enemy1Flag[i] == 1)
		{
			enemy1X[i] -= 1.5;
		}
		if (enemy1X[i] <= 0)
		{
			enemy1Flag[i] = 0;
		}
	}
}

// リスポーン
void Enemy::enemyBorn()
{
	for (int i = 0; i < 1; i++)
	{
		if (enemy1Flag[i] == 0)
		{
			enemy1Flag[i] = 1;
			enemy1X[i] = 1300;
			float y = rand() % 2;
			if (y == 0)
			{
				enemy1Y[i] = 500;
			} else {
				enemy1Y[i] = 470;
			}
		}
	}
}

// リセット
void Enemy::enemyReset()
{

}