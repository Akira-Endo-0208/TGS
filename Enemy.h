#pragma once
#include "Player.h"


class Enemy
{
public:	// メンバ関数
	void enemyInitialize(Player* player_);	// 初期化
	void enemyUpdate();		// 更新
	void enemyDraw();		// 描画
	void enemyMove();		// 動作
	void enemyBorn();		// リスポーン
	void enemyReset();		// リセット
	int GetenemyX() { for (int i = 0; i < 1; i++) { return enemy1X[i]; } }
	int GetenemyY() { for (int i = 0; i < 1; i++) { return enemy1Y[i]; } }
	int GetenemyFlag() { for (int i = 0; i < 1; i++) { return enemy1Flag[i]; } }
	int GetenemyReset() { for (int i = 0; i < 1; i++) { return enemy1Flag[i] = 0; } }
private: // メンバ変数
	int enemy1X[5];		// X軸
	int enemy1Y[5];		// Y軸
	int enemy1R = 25;	// 半径
	int enemy1Speed[5];	// スピード値
	int enemy1Born[5];	// リスポーン
	int enemy1Flag[5];	// 生存フラグ

	// 画像
	int enemy1Graph = LoadGraph("Resources/Enemy1.png");

	// ポインタ
	Player* player;
};