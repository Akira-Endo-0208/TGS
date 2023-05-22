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
	DrawGraph(graphscrollX, 0, backGroundGraph, TRUE);
	DrawGraph(graphscrollX + 1280, 0, backGroundGraph, TRUE);
	if (playerFlag == 1)
	{
		//DrawBox(playerScreenX, playerY, playerScreenX + 32, playerY + playerSizeY, GetColor(255, 255, 255), true);
		if (roundTripFlag == 0)
		{
			DrawRectGraph(playerScreenX, playerY + playerSizeY, 38 * playerGraphTime, 0, 38, 56, playerGraph, TRUE, FALSE);
		} else {
			DrawRectGraph(playerScreenX, playerY + playerSizeY, 38 * playerGraphTime, 56, 38, 56, playerGraph, TRUE, FALSE);
		}
	}
	//DrawFormatString(0, 60, GetColor(255, 255, 255), "playerScreenX %d", playerScreenX);
	//DrawFormatString(0, 80, GetColor(255, 255, 255), "scrollX %d", scrollX);
	//DrawFormatString(0, 100, GetColor(255, 255, 255), "playerX %d", playerX);
}

// 動作
void Player::playerMove()
{
	// ジャンプ
	if (playerY <= 512 && key[KEY_INPUT_SPACE] == 1 && oldkey[KEY_INPUT_SPACE] == 0 && playerCanJump < 2)
	{
		playerCanJump++;
		playerGravity = -20;
	}

	if (playerCanJump < 3)
	{
		playerGravity += playerAccel;
		playerY += playerGravity;
	}

	if (playerY >= 512)
	{
		playerY = 512;
		playerGravity = 0;
		playerCanJump = 0;
	}
	
	//// スライディング
	//if (playerY >= 500 && key[KEY_INPUT_S] == 1)
	//{
	//	playerSizeY = -5;
/*	} else*/ {
		playerSizeY = -56;
	}
}

// スクロール
void Player::playerMoveScroll()
{
	playerX += playerSpeed;

	if (playerScreenX > 1280 / 2 && playerX <= maxWidth)
	{
		scrollX += playerSpeed;
		graphscrollX -= playerSpeed;
		if (graphscrollX <= -1280 && roundTripFlag == 0)
		{
			graphscrollX = 0;
		}
		else if (graphscrollX >= 0 && roundTripFlag == 1)
		{
			graphscrollX = -1280;
		}
	}

	if (playerX >= maxWidth + 640)
	{
		roundTripFlag = 1;
	}

	if (roundTripFlag == 1)
	{
		playerSpeed = -5;
	}

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
	playerY = 512;
	playerSpeed = 5;
	playerFlag = 1;
	playerLife = 3;
	playerScreenX = 0;
	scrollX = 0;
	graphscrollX = 0;
	playerGraphTime = 0;
	playerTime = 0;
	roundTripFlag = 0;
}