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
	void enemyMoveGraph();	// グラフィック
	void enemyReset();		// リセット
	int GetenemyX(int i) { return enemy1X[i]; }
	int GetenemyY(int i) { return enemy1Y[i];  }
	int GetenemyFlag(int i) {  return enemy1Flag[i]; }
	int GetenemyReset(int i) { return enemy1Flag[i] = 0;  }
private: // メンバ変数
	int enemy1X[10];		// X軸
	int enemy1Y[10];		// Y軸
	int enemy1R = 25;	// 半径
	int enemy1Speed[10];	// スピード値
	int enemy1Born[10];	// リスポーン
	int enemy1Flag[10];	// 生存フラグ
	int enemy1GraphTime[10];
	int enemy1Time[10];

	// 画像
	int enemy1Graph = LoadGraph("Resources/suraimu-kari.png");

	// ポインタ
	Player* player;
};