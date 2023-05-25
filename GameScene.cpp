#include "DxLib.h"
#include "GameScene.h"
#include <time.h>


// 初期化
void GameScene::Initialize()
{
	player = new Player();
	enemy = new Enemy();
	map = new Map();
	collision = new Collision();
	input = new Input();  
	otherScene = new OtherScene();

	player->playerInitialize(input);
	enemy->enemyInitialize(player);
	map->Initialize(player, otherScene);
	collision->collisionInitialize(player, enemy, otherScene, map);
	otherScene->OtherSceneInitialize();

	// 乱数の初期化
	srand(time(NULL));
}

// 更新
void GameScene::Update()
{
	switch (otherScene->GetScene())
	{
	case 0:	// タイトル
		if (CheckSoundMem(playBGMHandle) == 1)
		{
			StopSoundMem(playBGMHandle);
		}

		playOnlyFlag = 0;

		if (CheckSoundMem(titleBGMHandle) == 0)
		{
			PlaySoundMem(titleBGMHandle, DX_PLAYTYPE_BACK, true);
		}

		otherScene->OtherSceneUpdate();
		break;
	case 1:	// ステージセレクト
		if (CheckSoundMem(gameClearHandle) == 1)
		{
			StopSoundMem(gameClearHandle);
		}

		if (CheckSoundMem(gameOverHandle) == 1)
		{
			StopSoundMem(gameOverHandle);
		}

		if (CheckSoundMem(titleBGMHandle) == 0)
		{
			PlaySoundMem(titleBGMHandle, DX_PLAYTYPE_BACK, true);
		}

		player->playerReset();
		enemy->enemyReset();
		otherScene->OtherSceneUpdate();
		break;
	case 2:	// ゲームオーバー
		if (CheckSoundMem(playBGMHandle) == 1)
		{
			StopSoundMem(playBGMHandle);
		}
		if (playOnlyFlag == 0)
		{
			PlaySoundMem(gameOverHandle, DX_PLAYTYPE_BACK, true);
			playOnlyFlag = 1;
		}
		otherScene->OtherSceneUpdate();
		break;
	case 3:	// ゲームクリア
		if (CheckSoundMem(playBGMHandle) == 1)
		{
			StopSoundMem(playBGMHandle);
		}
		if (playOnlyFlag == 0)
		{
			PlaySoundMem(gameClearHandle, DX_PLAYTYPE_BACK, true);
			playOnlyFlag = 1;
		}
		otherScene->OtherSceneUpdate();
		break;
	case 4:	// チュートリアル
		player->playerTutorialUpdate();
		enemy->enemyUpdate();
		collision->collisionUpdate();
		map->Update();
		break;
	case 5:	// ゲーム画面1
		if (CheckSoundMem(titleBGMHandle) == 1)
		{
			StopSoundMem(titleBGMHandle);
		}
		if (CheckSoundMem(playBGMHandle) == 0)
		{
			PlaySoundMem(playBGMHandle, DX_PLAYTYPE_BACK, true);
		}
		player->playerUpdate();
		enemy->enemyUpdate();
		collision->collisionUpdate();
		map->Update();
		break;
	case 6:	// ゲーム画面2
		if (CheckSoundMem(titleBGMHandle) == 1)
		{
			StopSoundMem(titleBGMHandle);
		}
		if (CheckSoundMem(playBGMHandle) == 0)
		{
			PlaySoundMem(playBGMHandle, DX_PLAYTYPE_BACK, true);
		}

		player->playerUpdate();
		enemy->enemyUpdate();
		collision->collisionUpdate();
		map->Update();
		break;
	case 7:	// ゲーム画面
		if (CheckSoundMem(titleBGMHandle) == 1)
		{
			StopSoundMem(titleBGMHandle);
		}
		if (CheckSoundMem(playBGMHandle) == 0)
		{
			PlaySoundMem(playBGMHandle, DX_PLAYTYPE_BACK, true);
		}
		player->playerUpdate();
		enemy->enemyUpdate();
		collision->collisionUpdate();
		map->Update();
		break;
	}
}

// 描画
void GameScene::Draw()
{
	switch (otherScene->GetScene())
	{
	case 0:	// タイトル
		otherScene->OtherSceneDraw();
		break;
	case 1:	// ステージセレクト
		otherScene->OtherSceneDraw();
		break;
	case 2:	// ゲームオーバー
		otherScene->OtherSceneDraw();
		break;
	case 3:	// ゲームクリア
		otherScene->OtherSceneDraw();
		break;
	case 4:	// チュートリアル
		player->playerTutorialDraw();
		enemy->enemyDraw();
		map->Draw();
		break;
	case 5:	// ゲーム画面1
		player->playerDraw();
		enemy->enemyDraw();
		map->Draw();
		break;
	case 6:	// ゲーム画面2
		player->playerDraw();
		enemy->enemyDraw();
		map->Draw();
		break;
	case 7:	// ゲーム画面3
		player->playerDraw();
		enemy->enemyDraw();
		map->Draw();
		break;
	}
}