#pragma once

#include "Player.h"
#include "Enemy.h"
#include "Collision.h"
#include "Input.h"


class GameScene
{
public:	// メンバ関数
	void Initialize();	// 初期化
	void Update();		// 更新
	void Draw();		// 描画
	int GetScene() { return scene; }
private: // メンバ変数
	// シーン切り替え
	int scene = 4;

	Player* player;
	Enemy* enemy;
	Collision* collision;
	Input* input;
};