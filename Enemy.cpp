#include "DxLib.h"
#include "Enemy.h"


// ������
void Enemy::enemyInitialize(Player* player_)
{
	player = player_;
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
			DrawBox(enemy1X[i] - player->GetScrollX(), enemy1Y[i], enemy1X[i] - player->GetScrollX() + 32, enemy1Y[i] + 32, GetColor(255, 0, 0), true);
		}
		//DrawFormatString(0, 120, GetColor(255, 255, 255), "%d", enemy1X[i]);
	}
}

// ����
void Enemy::enemyMove()
{
	for (int i = 0; i < 1; i++)
	{
		if (enemy1Flag[i] == 1)
		{
			enemy1X[i] -= 4.0;
		}
		if (enemy1X[i] <= 0 + player->GetScrollX())
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
			enemy1X[i] = 1300 + player->GetScrollX();
			float y = rand() % 2;
			if (y == 0)
			{
				enemy1Y[i] = 470;
			} else {
				enemy1Y[i] = 450;
			}
		}
	}
}

// ���Z�b�g
void Enemy::enemyReset()
{
	for (int i = 0; i < 1; i++)
	{
		enemy1Flag[i] = 0;
	}
}