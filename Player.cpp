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
	// �d��
	if (playerY < 500)
	{
		playerY += playerFallSpeed;
		playerFallSpeed += 0.1;
	} else {
		playerFallSpeed = 1;
		playerJumpFlag = 1;
	}
	// �X���C�f�B���O
	if (playerY >= 500 && key[KEY_INPUT_S] == 1)
	{
		playerR = 5;
	} else {
		playerR = 20;
	}
	// �W�����v
	if (playerJumpFlag == 1 && key[KEY_INPUT_SPACE] == 1 && playerJumpTime >= 0)
	{
		playerY -= playerJumpSpeed;
		playerJumpSpeed -= 0.1;
		playerJumpTime--;
	}
	else if (playerJumpTime == 0 || key[KEY_INPUT_SPACE] == 0)
	{
		playerJumpSpeed = 10;
		playerJumpFlag = 0;
		playerJumpTime = 60;
	}
}

// ���Z�b�g
void Player::playerReset()
{

}