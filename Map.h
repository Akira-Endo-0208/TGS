#pragma once
#include "Player.h"

const int width = 20;
const int length = 10;

class Map
{
public:
	void Initialize(Player* _player);	// ������
	void Update();		// �X�V
	void Draw();		// �`��


public:

	
private:

	
	enum MAPBLOCK
	{
		NONE,
		BLOCK
	};
	
	Player* player_ = nullptr;
};

