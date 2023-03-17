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
	DrawGraph(scrollX, 0, backGroundGraph, TRUE);

	if (playerFlag == 1)
	{
		DrawCircle(playerScreenX, playerY, playerR, GetColor(255, 255, 255));
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", playerScreenX);
	DrawFormatString(0, 20, GetColor(255, 255, 255), "%d", scrollX);
	DrawFormatString(0, 40, GetColor(255, 255, 255), "%d", playerX);
	
}

// ����
void Player::playerMove()
{
	
#pragma region �X�N���[���ړ�(����m�F�̈�)

	if (key[KEY_INPUT_D])
	{
		
			playerX += playerSpeed;

		if (playerX > 1280 / 2 && playerX <= 1920)
		{
			scrollX += playerSpeed;

		}

		

	}

	if (key[KEY_INPUT_A])
	{
		
			playerX -= playerSpeed;

		if (playerX < 1920 && playerX >= 640)
		{
			scrollX -= playerSpeed;
			
		}
	}

	if (playerX < 640)
	{
		scrollX = 0;
	}
	if (playerX > 1920)
	{
		scrollX = 1280;
	}

	playerScreenX = playerX - scrollX;

#pragma endregion

	if (playerY <= 500 && key[KEY_INPUT_SPACE] == 1 && oldkey[KEY_INPUT_SPACE] == 0 && canJump < 2)
	{
		canJump++;
		gravity_ = -20;
	}

	if (canJump < 3)
	{
		gravity_ += accel_;
		playerY += gravity_;
	}

	if (playerY >= 500)
	{
		playerY = 500;
		gravity_ = 0;
		canJump = 0;
	}
	
}

// ���Z�b�g
void Player::playerReset()
{

}