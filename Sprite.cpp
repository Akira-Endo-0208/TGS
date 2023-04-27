#include "Sprite.h"


// ������
void Sprite::spriteInitialize(Player* player_)
{
	player = player_;
}

// �X�V
void Sprite::spriteUpdate()
{
	scrollUpdate();
}

// �`��
void Sprite::spriteDraw()
{
	DrawGraph(scrollX, 0, backGroundGraph, TRUE);
	DrawGraph(scrollX + 1280, 0, backGroundGraph, TRUE);
	DrawFormatString(0, 60, GetColor(255, 255, 255), "%d", scrollScreenX);
	DrawFormatString(0, 80, GetColor(255, 255, 255), "%d", scrollX);
}

// �X�N���[��
void Sprite::scrollUpdate()
{
	if (scrollScreenX >= 1280 / 2 && player->GetplayerX() <= maxWidth)
	{
		scrollX += player->GetplayerSpeed();
	}

	if (player->GetplayerX() >= maxWidth + 640)
	{
		roundTripFlag = 1;
	}

	if (roundTripFlag == 1)
	{
		player->GetplayerSpeed() == -5;
	}

	//if (player->GetplayerX() > maxWidth)
	//{
	//	scrollX = maxWidth - 640;
	//}

	//if (player->GetplayerX() < 650)
	//{
	//	scrollX = 0;
	//}

	//scrollScreenX = player->GetplayerX() - scrollX;
}

// ���Z�b�g
void Sprite::spriteReset()
{
	scrollScreenX = 0;
	scrollX = 0;
}