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
	//otherScene = new OtherScene();

	player->playerInitialize(input);
	enemy->enemyInitialize();
	collision->collisionInitialize(player, enemy);
	//otherScene->OtherSceneInitialize();

	// 乱数の初期化
	srand(time(NULL));
}

// 更新
void GameScene::Update()
{
	switch (scene)
	{
	case 0:	// タイトル
		//otherScene->OtherSceneUpdate();
		break;
	case 1:	// ゲームオーバー
		//otherScene->OtherSceneUpdate();
		break;
	case 2:	// ゲームクリア
		//otherScene->OtherSceneUpdate();
		break;
	case 3:	// チュートリアル
		player->playerUpdate();
		enemy->enemyUpdate();
		collision->collisionUpdate();
		break;
	case 4:	// ゲーム画面
		player->playerUpdate();
		enemy->enemyUpdate();
		collision->collisionUpdate();
		break;
	}
}

// 描画
void GameScene::Draw()
{
	switch (scene)
	{
	case 0:	// タイトル
		//otherScene->OtherSceneDraw();
		DrawFormatString(0, 0, GetColor(255, 255, 255), "タイトル   SPACE->ゲーム画面");
		break;
	case 1:	// ゲームオーバー
		//otherScene->OtherSceneDraw();
		DrawFormatString(0, 0, GetColor(255, 255, 255), "ゲームオーバー   SPACE->タイトル");
		break;
	case 2:	// ゲームクリア
		//otherScene->OtherSceneDraw();
		DrawFormatString(0, 0, GetColor(255, 255, 255), "ゲームクリア  SPACE->タイトル");
		break;
	case 3:	// チュートリアル
		player->playerDraw();
		enemy->enemyDraw();
		DrawFormatString(0, 0, GetColor(255, 255, 255), "チュートリアル   SPACE->ゲーム画面");
		break;
	case 4:	// ゲーム画面
		player->playerDraw();
		enemy->enemyDraw();
		DrawFormatString(0, 0, GetColor(255, 255, 255), "SPACE             ジャンプ");
		DrawFormatString(0, 20, GetColor(255, 255, 255), "ジャンプ中にSPACE  2段ジャンプ");
		DrawFormatString(0, 40, GetColor(255, 255, 255), "S                 スライディング");
		break;
	}
}