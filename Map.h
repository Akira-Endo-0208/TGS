#pragma once
#include "Player.h"

const int width = 20;
const int length = 10;

class Map
{
public:
	void Initialize(Player* player_);	// ‰Šú‰»
	void Update();		// XV
	void Draw();		// •`‰æ
	int GetBlock(int y,int x) { return mapData[y][x]; }
private:
	enum MAPBLOCK
	{
		NONE,
		BLOCK,
		CLAER
	};

	int mapData[length][width] = {};
	
	Player* player_ = nullptr;
};