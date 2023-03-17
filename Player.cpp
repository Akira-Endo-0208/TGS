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
	// 重力
	if (playerY < 500)
	{
		playerY += playerFallSpeed;
		playerFallSpeed += 0.1;
	} else {
		playerFallSpeed = 1;
		playerJumpFlag = 1;
	}
	// スライディング
	if (playerY >= 500 && key[KEY_INPUT_S] == 1)
	{
		playerR = 5;
	} else {
		playerR = 20;
	}
	// ジャンプ
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

// リセット
void Player::playerReset()
{

}