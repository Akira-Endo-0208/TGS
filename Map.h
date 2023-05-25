#pragma once
#include "Player.h"
#include "OtherScene.h"

const int width = 150;
const int length = 12;

class Map
{
public:
	void Initialize(Player* _player, OtherScene* _otherScene);	// 初期化
	void Update();		// 更新
	void Draw();		// 描画
	int GetBlock(int y,int x) { return mapData[y][x]; }
	int GetMapStageCount() { return mapStageCount; }
private:
	enum MAPBLOCK
	{
		NONE,
		BLOCK,
		CLAER
	};

	int mapData[length][width] = {};
	int mapStageCount = 0;

	int blockGraph = LoadGraph("Resources/Block_1.png");
	int lifeGraph = LoadGraph("Resources/Life.png");
	
	Player* player_ = nullptr;
	OtherScene* otherScene_ = nullptr;
};