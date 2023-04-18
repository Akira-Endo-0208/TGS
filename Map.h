#pragma once
#include "Player.h"
const int width = 150;
const int length = 12;

class Map
{
public:
	void Initialize(Player* _player);	// ‰Šú‰»
	void Update();		// XV
	void Draw();		// •`‰æ
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
	Player* player_ = nullptr;
	
};