#include "Map.h"
#include "DxLib.h"

int mapData[length][width] = {};

int mapStage1[length][width] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void Map::Initialize(Player* _player)
{
	this->player_ = _player;

	for (int y = 0; y < length; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (mapStage1[y][x] == 1)
			{
				mapData[y][x] = 1;
			}
		}
	}
}

void Map::Update()
{
}

void Map::Draw()
{
	for (int y = 0; y < length; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if(mapData[y][x] == 1)
			
				DrawBox(
					x * 128 - player_->GetScrollX(),
					y * 72,
					(x + 1) * 128 - player_->GetScrollX(),
					(y + 1) * 72,
					GetColor(255, 255, 255),
					true
				);
		}
	}
}
