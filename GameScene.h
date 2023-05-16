#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Collision.h"
#include "Input.h"
#include "Map.h"
#include "OtherScene.h"


class GameScene
{
public:	// メンバ関数
	void Initialize();	// 初期化
	void Update();		// 更新
	void Draw();		// 描画
private: // メンバ変数
	// ポインタ
	Player* player;
	Enemy* enemy;
	Collision* collision;
	Input* input;
	Map* map;
	OtherScene* otherScene;
};