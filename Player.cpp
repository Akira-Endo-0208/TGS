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
	if (playerX >= 32 && key[KEY_INPUT_A] == 1)
	{
		playerX--;
	}
}

// リセット
void Player::playerReset()
{

}