#include "DxLib.h"
#include "GameScene.h"
#include <time.h>


// 初期化
void GameScene::Initialize()
{
	// 乱数の初期化
	srand(time(NULL));
}

// 更新
void GameScene::Update()
{
	switch (scene)
	{
	case 0:	// タイトル
		break;
	case 1:	// ゲーム画面
		break;
	case 2:	// チュートリアル
		break;
	case 3:	// ゲームオーバー
		break;
	case 4:	// ゲームクリア
		break;
	}
}

// 描画
void GameScene::Draw()
{
	switch (scene)
	{
	case 0:	// タイトル
		break;
	case 1:	// ゲーム画面
		break;
	case 2:	// チュートリアル
		break;
	case 3:	// ゲームオーバー
		break;
	case 4:	// ゲームクリア
		break;
	}
}