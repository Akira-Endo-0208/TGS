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
	DrawGraph(scrollX, 0, backGroundGraph, TRUE);

	if (playerFlag == 1)
	{
		DrawCircle(playerScreenX, playerY, playerR, GetColor(255, 255, 255));
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", playerScreenX);
	DrawFormatString(0, 20, GetColor(255, 255, 255), "%d", scrollX);
	DrawFormatString(0, 40, GetColor(255, 255, 255), "%d", playerX);
	
}

// 動作
void Player::playerMove()
{
#pragma region スクロール移動(動作確認の為)

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