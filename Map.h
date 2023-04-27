#pragma once
#include "Sprite.h"

const int width = 150;
const int length = 12;

class Map
{
public:
	void Initialize(Player* _player);	// 初期化
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
	int mapStageCount = 1;

	int blockGraph = LoadGraph("Resources/block2.png");
	
	Player* player_ = nullptr;
};