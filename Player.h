#pragma once
#include "Input.h"


class Player
{
public:	// メンバ関数
	void playerInitialize(Input* input_);	// 初期化
	void playerUpdate();		// 更新
	void playerDraw();			// 描画
	void playerMove();			// 動作
	void playerReset();			// リセット
	int GetplayerX() { return playerX; }
	int GetplayerY() { return playerY; }
	int GetplayerR() { return playerR; }
	int GetplayerFlag() { return playerFlag; }
	int ResetplayerFlag() { return playerY = 0; }
private: // メンバ変数
	// プレイヤー変数
	int playerX = 500;		// X軸
	int playerY = 500;		// Y軸
	int playerR = 15;		// 半径
	int playerSpeed = 7;	// スピード値
	int playerGravity = 0;
	int playerAccel = 1;
	int playerCanJump = 0;
	int playerFlag = 1;		// 生存フラグ
	int playerGraph = LoadGraph("Resources/Player1.png"); // 画像

	// キーボード変数
	char key[256] = { 0 }; //最新のキーボード情報用
	char oldkey[256] = { 0 };//1ループ（フレーム）前のキーボード情報

	Input* input;
};