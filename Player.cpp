#include "DxLib.h"
#include "Player.h"


// ������
void Player::playerInitialize(Input* input_)
{
	input = input_;
}

// �X�V
void Player::playerUpdate()
{
	for (int i = 0; i < 256; ++i)
	{
		oldkey[i] = key[i];
	}
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
	if (playerY <= 500 && key[KEY_INPUT_SPACE] == 1 && oldkey[KEY_INPUT_SPACE] == 0 && playerCanJump < 2)
	{
		playerCanJump++;
		playerGravity = -20;
	}

	if (playerCanJump < 3)
	{
		playerGravity += playerAccel;
		playerY += playerGravity;
	}

	if (playerY >= 500)
	{
		playerY = 500;
		playerGravity = 0;
		playerCanJump = 0;
	}
	
	// �X���C�f�B���O
	if (playerY >= 500 && key[KEY_INPUT_S] == 1)
	{
		playerR = 5;
	} else {
		playerR = 20;
	}
}

// ���Z�b�g
void Player::playerReset()
{

}