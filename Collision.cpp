#include "DxLib.h"
#include "Collision.h"


void Collision::collisionInitialize(Player* player_, Enemy* enemy_, OtherScene* otherScene_, Map* map_)
{
	player = player_;
	enemy = enemy_;
	otherScene = otherScene_;
	map = map_;
}

void Collision::collisionUpdate()
{
	collisionPlayerEnemy();
	collisionPlayerBlock();
	collisionPlayerClaer();
}

void Collision::collisionPlayerEnemy()
{
	for (int i = 0; i < 10; i++)
	{
		if (enemy->GetenemyFlag(i) == 1 && player->GetplayerFlag() == 1)
		{
			float dX = abs(enemy->GetenemyX(i) - player->GetplayerX());
			float dY = abs(enemy->GetenemyY(i) - player->GetplayerY());
			float dX2 = abs(enemy->GetenemyX(i) - (player->GetplayerX() + 32));
			float dY2 = abs(enemy->GetenemyY(i) - (player->GetplayerY() + player->GetplayerSizeY()));
			// プレイヤーと敵が当たったら
			if (dX < 32 && dY < 56 && dX2 < 32 && dY2 < 56)
			{
				PlaySoundMem(damageSoundHandle, DX_PLAYTYPE_BACK, true);
				if (map->GetMapStageCount() == 4)
				{
					player->playerTutorialReset();
				} else {
					player->HitLife();
					// ゲームオーバー
					if (player->GetLife() == 0)
					{
						otherScene->GameOverScene();
					}
				}
				enemy->GetenemyReset(i);
			}
		}
	}
}

void Collision::collisionPlayerBlock()
{
	for (int y = 0; y < length; y++)
	{
		for (int x = 0; x < width; x++)
		{
			//if (map->GetBlock(player->GetplayerY() / 64,
			//	player->GetplayerX() + 1 / 64) == 1 &&
			//	map->GetBlock(player->GetplayerY() / 64,
			//		player->GetplayerX() - 1 / 64) == 1 &&
			//	map->GetBlock((player->GetplayerY() + player->GetplayerSizeY()) / 64,
			//		(player->GetplayerX() + 32) + 1 / 64) == 1 &&
			//	map->GetBlock((player->GetplayerY() + player->GetplayerSizeY()) / 64,
			//		(player->GetplayerX() + 32) - 1 / 64) == 1)
			//{
			//	player->HitLife();
			//}
		}
	}
}

void Collision::collisionPlayerClaer()
{
	if (player->GetplayerFlag() == 1 && player->GetplayerX() <= 0 && player->GetRoundTripFlag() == 1)
	{
		if (map->GetMapStageCount() == 4)
		{
			otherScene->SelectScene();
		} else {
			otherScene->GameClaerScene();
		}
	}
}