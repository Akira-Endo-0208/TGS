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

	int titleBGMHandle = LoadSoundMem("Resources/Sounds/TitleBGM.wav");
	int playBGMHandle = LoadSoundMem("Resources/Sounds/PlayBGM.wav");
	int gameClearHandle = LoadSoundMem("Resources/Sounds/GameClear.wav");
	int gameOverHandle = LoadSoundMem("Resources/Sounds/GameOver.wav");

	int playOnlyFlag = 0;
};