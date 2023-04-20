#pragma once
#include "Player.h"

const int width = 20;
const int length = 11;

class Map
{
public:
	void Initialize(Player* player_);	// 初期化
	void Update();		// 更新
	void Draw();		// 描画
	int GetBlock(int y,int x) { return mapData[y][x]; }
private:
	enum MAPBLOCK
	{
		NONE,
		BLOCK,
		CLAER
	};

	int mapData[length][width] = {};

	int blockGraph = LoadGraph("Resources/block2.png");
	
	Player* player_ = nullptr;
};