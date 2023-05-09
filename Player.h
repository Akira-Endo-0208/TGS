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
	void playerMoveGraph();		// グラフィック
	void playerMoveScroll();	// スクロール
	void playerReset();			// リセット
	int GetplayerX() { return playerX; }
	int GetplayerY() { return playerY; }

	void SetplayerX(int _playerX) { this->playerX = _playerX; }
	void SetplayerY(int _playerY) { this->playerY = _playerY; }

	int GetOldPlayerX() { return oldPlayerX; }
	int GetOldPlayerY() { return oldPlayerY; }

	int GetplayerSizeY() { return playerSizeY; }
	int GetplayerFlag() { return playerFlag; }
	int GetLife() { return playerLife; }
	int HitLife() { return playerLife -= 1; }
	int GetScrollX() { return scrollX; }
	int GetRoundTripFlag() { return roundTripFlag; }
	void SetMaxWidth(int _maxWidth) { this->maxWidth = _maxWidth; }
	int GetSlideFlag() { return slideFlag; }
private: // メンバ変数
	// プレイヤー変数
	int playerX;			// X軸
	int playerY;			// Y軸
	int oldPlayerX;			// X軸
	int oldPlayerY;			// Y軸
	int playerSizeY = 56;
	int playerSpeed = 10;	// スピード値
	int playerGravity = 0;	// 重力
	int playerAccel = 1;	// 加速度
	int playerCanJump = 0;	// 2段ジャンプ判定
	int playerFlag;			// 生存フラグ
	int playerLife;			// ライフ
	int playerScreenX;		//プレイヤーのモニター座標
	int playerScreenY = 0;	//現在は使用していない
	int scrollX;			//移動量の記憶
	int scrollY = 0;		//現在は使用していない
	int playerGraphTime;
	int playerTime;
	int roundTripFlag = 0;
	int maxWidth = 0;
	int slideFlag = 0;
	// 画像
	int playerGraph = LoadGraph("Resources/Player.kari.png");
	

	// キーボード変数
	char key[256] = { 0 }; //最新のキーボード情報用
	char oldkey[256] = { 0 };//1ループ（フレーム）前のキーボード情報

	// ポインタ
	Input* input;
};