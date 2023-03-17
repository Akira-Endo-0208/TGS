#include "DxLib.h"
#include "Player.h"


// 初期化
void Player::playerInitialize(Input* input_)
{
	input = input_;
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
	
	// スライディング
	if (playerY >= 500 && key[KEY_INPUT_S] == 1)
	{
		playerR = 5;
	} else {
		playerR = 20;
	}
}

// リセット
void Player::playerReset()
{

}