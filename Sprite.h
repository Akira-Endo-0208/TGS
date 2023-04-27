#pragma once
#include "Player.h"


class Sprite
{
public:	// メンバ関数
	void spriteInitialize(Player* player_); // 初期化
	void spriteUpdate();	// 更新
	void spriteDraw();		// 描画
	void scrollUpdate();	// スクロール
	void spriteReset();		// リセット
	void SetMaxWidth(int _maxWidth) { this->maxWidth = _maxWidth; }
	int GetScrollX() { return scrollX; }
	int GetRoundTripFlag() { return roundTripFlag; }
private: // メンバ変数
	// スクロール変数
	int scrollScreenX;		//プレイヤーのモニター座標
	int scrollScreenY = 0;	//現在は使用していない
	int scrollX;			//移動量の記憶
	int scrollY = 0;		//現在は使用していない
	int roundTripFlag = 0;
	int maxWidth = 0;

	// 画像
	int backGroundGraph = LoadGraph("Resources/haikei2.png");

	// ポインタ
	Player* player;
};