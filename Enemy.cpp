#include "DxLib.h"
#include "Enemy.h"


// 初期化
void Enemy::enemyInitialize()
{

}

// 更新
void Enemy::enemyUpdate()
{
	for (int i = 0; i < 5; i++)
	{
		if (enemy1Flag[i] == 1)
		{
			enemyMove();
			enemyBorn();
		}
	}
}

// 描画
void Enemy::enemyDraw()
{
	for (int i = 0; i < 5; i++)
	{
		if (enemy1Flag[i] == 1)
		{
			DrawCircle(enemy1X[i], enemy1Y[i], enemy1R, GetColor(255, 255, 255));
		}
	}
}

// 動作
void Enemy::enemyMove()
{

}

// リスポーン
void Enemy::enemyBorn()
{

}

// リセット
void Enemy::enemyReset()
{

}