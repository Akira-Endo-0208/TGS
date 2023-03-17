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
	float playerX = 500;		// X軸
	float playerY = 300;		// Y軸
	int playerR = 20;			// 半径
	float playerFallSpeed = 1;	// 落下スピード値
	float playerJumpSpeed = 10;	// ジャンプスピード値
	int playerJumpTime = 60;	// ジャンプ時間
	int playerJumpFlag = 1;		// ジャンプフラグ
	int playerFlag = 1;			// 生存フラグ
	int playerGraph = LoadGraph("Resources/Player1.png"); // 画像

	// キーボード変数
	char key[256] = { 0 }; //最新のキーボード情報用
	char oldkey[256] = { 0 };//1ループ（フレーム）前のキーボード情報

	Input* input;
};