#include "DxLib.h"
#include "Enemy.h"


// ������
void Enemy::enemyInitialize()
{

}

// �X�V
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

// �`��
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

// ����
void Enemy::enemyMove()
{

}

// ���X�|�[��
void Enemy::enemyBorn()
{

}

// ���Z�b�g
void Enemy::enemyReset()
{

}