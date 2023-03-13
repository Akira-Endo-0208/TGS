#pragma once
#include "Input.h"


class Player
{
public:	// メンバ関数
	void playerInitialize();	// 初期化
	void playerUpdate();		// 更新
	void playerDraw();			// 描画
	void playerMove();			// 動作
	void playerReset();			// リセット
private: // メンバ変数
	// プレイヤー変数
	int playerX = 500;		// X軸
	int playerY = 300;		// Y軸
	int playerR = 15;		// 半径
	int playerSpeed = 7;	// スピード値
	int playerFlag = 1;		// 生存フラグ
	int playerGraph = LoadGraph("Resources/Player1.png"); // 画像

	// キーボード変数
	char key[256] = { 0 }; //最新のキーボード情報用
	char oldkey[256] = { 0 };//1ループ（フレーム）前のキーボード情報

	Input* input;
};