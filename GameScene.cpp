#include "DxLib.h"
#include "GameScene.h"
#include <time.h>


// 初期化
void GameScene::Initialize()
{
	player = new Player();
	enemy = new Enemy();
	collision = new Collision();
	input = new Input();
	otherScene = new OtherScene();

	player->playerInitialize(input);
	enemy->enemyInitialize();
	collision->collisionInitialize(player, enemy, otherScene);
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
		break;
	case 5:	// ゲーム画面
		player->playerUpdate();
		enemy->enemyUpdate();
		collision->collisionUpdate();
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
		break;
	case 5:	// ゲーム画面
		player->playerDraw();
		enemy->enemyDraw();
		break;
	}
}