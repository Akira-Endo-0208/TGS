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
	enemyMoveGraph();
}

// �`��
void Enemy::enemyDraw()
{
	for (int i = 0; i < 1; i++)
	{
		if (enemy1Flag[i] == 1)
		{
			//DrawBox(enemy1X[i] - player->GetScrollX(), enemy1Y[i], enemy1X[i] - player->GetScrollX() + 32, enemy1Y[i] + 32, GetColor(255, 0, 0), true);
			if (player->GetRoundTripFlag() == 0)
			{
				DrawRectGraph(enemy1X[i] - player->GetScrollX(), enemy1Y[i], 32 * enemy1GraphTime[i], 0, 32, 32, enemy1Graph, TRUE, FALSE);
			} else {
				DrawRectGraph(enemy1X[i] - player->GetScrollX(), enemy1Y[i], 32 * enemy1GraphTime[i], 32, 32, 32, enemy1Graph, TRUE, FALSE);
			}
		}
		//DrawFormatString(0, 120, GetColor(255, 255, 255), "enemy %d", enemy1X[i]);
	}
}

// ����
void Enemy::enemyMove()
{
	for (int i = 0; i < 1; i++)
	{
		if (enemy1Flag[i] == 1)
		{
			enemy1X[i] -= player->GetplayerSpeed();
		}
		if (enemy1X[i] <= player->GetScrollX() - 100 && player->GetRoundTripFlag() == 0)
		{
			enemy1Flag[i] = 0;
		}
		if (enemy1X[i] >= player->GetScrollX() + 1300 && player->GetRoundTripFlag() == 1)
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
			enemy1GraphTime[i] = 0;
			enemy1Time[i] = 0;
			enemy1Y[i] = 480;
			if (player->GetRoundTripFlag() == 0)
			{
				enemy1X[i] = player->GetScrollX() + 1400;
			}
			else
			{
				enemy1X[i] = player->GetScrollX() - 300;
			}
		}
	}
}

void Enemy::enemyMoveGraph()
{
	for (int i = 0; i < 1; i++)
	{
		enemy1Time[i]++;
		if (enemy1GraphTime[i] != 11 && enemy1Time[i] == 5)
		{
			enemy1GraphTime[i]++;
			enemy1Time[i] = 0;
		}
		else if (enemy1GraphTime[i] == 11 && enemy1Time[i] == 5) {
			enemy1GraphTime[i] = 0;
			enemy1Time[i] = 0;
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