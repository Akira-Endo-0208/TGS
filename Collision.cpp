#include "DxLib.h"
#include "Collision.h"


void Collision::collisionInitialize(Player* player_, Enemy* enemy_, OtherScene* otherScene_)
{
	player = player_;
	enemy = enemy_;
	otherScene = otherScene_;
}

void Collision::collisionUpdate()
{
	collisionPlayerEnemy();
}

void Collision::collisionPlayerEnemy()
{
	for (int i = 0; i < 5; i++)
	{
		if (enemy->GetenemyFlag() == 1 && player->GetplayerFlag() == 1)
		{
			float dX = abs(player->GetplayerX() - enemy->GetenemyX());
			float dY = abs(player->GetplayerY() - enemy->GetenemyY());
			// プレイヤーと敵が当たったら
			if (dX < player->GetplayerR() * 2 && dY < player->GetplayerR() * 2)
			{
				player->HitLife();
				enemy->GetenemyReset();
				// ゲームオーバー
				if (player->GetLife() == 0)
				{
					otherScene->GameOverScene();
				}
			}
		}
	}
}