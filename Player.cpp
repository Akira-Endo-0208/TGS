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
		playerMoveScroll();
		playerMoveGraph();
	}
}

// 描画
void Player::playerDraw()
{
	DrawGraph(scrollX, 0, backGroundGraph, TRUE);
	DrawGraph(scrollX - 1280, 0, backGroundGraph, TRUE);
	if (playerFlag == 1)
	{
		DrawBox(playerScreenX, playerY, playerScreenX + 32, playerY + playerSizeY, GetColor(255, 255, 255), true);
		DrawRectGraph(playerScreenX, playerY + playerSizeY, 38 * playerGraphTime, 0, 38, 56, playerGraph, TRUE, FALSE);
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "SPACE   JUMP,2JUMP");
	DrawFormatString(0, 20, GetColor(255, 255, 255), "S       SLIDING");
	DrawFormatString(0, 40, GetColor(255, 255, 255), "LIFE    %d", playerLife);
	DrawFormatString(0, 60, GetColor(255, 255, 255), "%d", playerScreenX);
	DrawFormatString(0, 80, GetColor(255, 255, 255), "%d", scrollX);
	DrawFormatString(0, 100, GetColor(255, 255, 255), "%d", playerX);
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
		playerSizeY = -5;
	} else {
		playerSizeY = -56;
	}
}

// スクロール
void Player::playerMoveScroll()
{
	//if (key[KEY_INPUT_D])
	//{
	
	
		playerX += playerSpeed;

		if (playerScreenX > 1280 / 2 && playerX <= maxWidth)
		{
			scrollX += playerSpeed;
		}


		if(playerX >= maxWidth + 640)
		{
			roundTripFlag = 1;
		}

		if (roundTripFlag == 1)
		{
			playerSpeed = -10;
		}

		
	//}

	//if (key[KEY_INPUT_A])
	//{
	//	playerX -= playerSpeed;
		//if (playerX < 1920 && playerX >= 640)
		//{
		//	scrollX -= playerSpeed;
		//}
	//}
	if (playerX > maxWidth)
	{
		scrollX = maxWidth - 640;
	}

	if (playerX < 650)
	{
		scrollX = 0;
	}

	playerScreenX = playerX - scrollX;
}

// グラフィック
void Player::playerMoveGraph()
{
	playerTime++;
	if (playerGraphTime != 15 && playerTime == 5)
	{
		playerGraphTime++;
		playerTime = 0;
	} else if (playerGraphTime == 15 && playerTime == 5) {
		playerGraphTime = 0;
		playerTime = 0;
	}
}

// リセット
void Player::playerReset()
{
	playerX = 200;
	playerY = 500;
	playerFlag = 1;
	playerLife = 3;
	playerScreenX = 0;
	scrollX = 0;
	playerGraphTime = 0;
	playerTime = 0;
} 