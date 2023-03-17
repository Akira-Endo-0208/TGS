#include "DxLib.h"
#include "Player.h"


// 初期化
void Player::playerInitialize()
{
	input = new Input();
}

// 更新
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

// 描画
void Player::playerDraw()
{
	if (playerFlag == 1)
	{
		DrawCircle(playerX, playerY, playerR, GetColor(255, 255, 255));
	}
}

// 動作
void Player::playerMove()
{
	
		
	if (playerX >= 32 && key[KEY_INPUT_A] == 1)
	{
		playerX--;
	}

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

// リセット
void Player::playerReset()
{

}