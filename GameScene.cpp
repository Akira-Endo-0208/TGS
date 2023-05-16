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
		otherScene->OtherSceneUpdate();
		break;
	case 1:	// ステージセレクト
		player->playerReset();
		enemy->enemyReset();
		otherScene->OtherSceneUpdate();
		break;
	case 2:	// ゲームオーバー
		otherScene->OtherSceneUpdate();
		break;
	case 3:	// ゲームクリア
		otherScene->OtherSceneUpdate();
		break;
	case 4:	// チュートリアル
		player->playerUpdate();
		enemy->enemyUpdate();
		collision->collisionUpdate();
		map->Update();
		break;
	case 5:	// ゲーム画面1
		player->playerUpdate();
		enemy->enemyUpdate();
		collision->collisionUpdate();
		map->Update();
		break;
	case 6:	// ゲーム画面2
		player->playerUpdate();
		enemy->enemyUpdate();
		collision->collisionUpdate();
		map->Update();
		break;
	case 7:	// ゲーム画面3
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
		player->playerDraw();
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