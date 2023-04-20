#include "Map.h"
#include "DxLib.h"


int mapStage1[length][width] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,2},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void Map::Initialize(Player* player_)
{
	this->player_ = player_;

	for (int y = 0; y < length; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (mapStage1[y][x] == 1)
			{
				mapData[y][x] = 1;
			}
			if (mapStage1[y][x] == 2)
			{
				mapData[y][x] = 2;
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
			if (mapData[y][x] == 1)
			{
				//DrawBox(
				//	x * 128 - player_->GetScrollX(),
				//	y * 72,
				//	(x + 1) * 128 - player_->GetScrollX(),
				//	(y + 1) * 72,
				//	GetColor(255, 0, 255),
				//	true
				//);
				DrawRectGraph(x * 64 - player_->GetScrollX(), y * 64, 0, 0, 64, 64, blockGraph, TRUE, FALSE);
			}
			if (mapData[y][x] == 2)
			{
				DrawBox(
					x * 64 - player_->GetScrollX(),
					y * 64,
					(x + 1) * 64 - player_->GetScrollX(),
					(y + 1) * 64,
					GetColor(0, 255, 0),
					true
				);
			}
		}
	}
}