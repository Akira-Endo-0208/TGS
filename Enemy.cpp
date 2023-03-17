#include "DxLib.h"
#include "Enemy.h"


// ������
void Enemy::enemyInitialize()
{

}

// �X�V
void Enemy::enemyUpdate()
{
	enemyMove();
	enemyBorn();
}

// �`��
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

// ����
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

// ���X�|�[��
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

// ���Z�b�g
void Enemy::enemyReset()
{

}