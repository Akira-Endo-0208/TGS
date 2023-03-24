#pragma once
#include "Input.h"
#include "DxLib.h"


class Player
{
public:	// メンバ関数
	void playerInitialize(Input* input_);	// 初期化
	void playerUpdate();		// 更新
	void playerDraw();			// 描画
	void playerMove();			// 動作
	void playerReset();			// リセット

	int GetScrollX() { return scrollX; }

	
private: // メンバ変数
	// プレイヤー変数
	int playerX = 0;		// X軸
	int playerY = 500;		// Y軸
	int playerR = 15;		// 半径

	int playerSpeed = 10;	// スピード値


	int playerGravity = 0;
	int playerAccel = 1;
	int playerCanJump = 0;

	int playerFlag = 1;		// 生存フラグ
	int playerGraph = LoadGraph("Resources/Player1.png"); // 画像
	int backGroundGraph = LoadGraph("Resources/backGround.png");

	int playerScreenX = 0;	//プレイヤーのモニター座標
	int playerScreenY = 0;	//現在は使用していない


	int scrollX = 0;	//移動量の記憶
	int scrollY = 0;	//現在は使用していない

	// キーボード変数
	char key[256] = { 0 }; //最新のキーボード情報用
	char oldkey[256] = { 0 };//1ループ（フレーム）前のキーボード情報

	Input* input;
};