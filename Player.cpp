#include "DxLib.h"
#include "Player.h"


// ������
void Player::playerInitialize()
{
	input = new Input();
}

// �X�V
void Player::playerUpdate()
{
	GetHitKeyStateAll(key);

	if (playerFlag == 1)
	{
		playerMove();
	}
}

// �`��
void Player::playerDraw()
{
	if (playerFlag == 1)
	{
		DrawCircle(playerX, playerY, playerR, GetColor(255, 255, 255));
	}
}

// ����
void Player::playerMove()
{
	if (playerX >= 32 && key[KEY_INPUT_A] == 1)
	{
		playerX--;
	}
}

// ���Z�b�g
void Player::playerReset()
{

}