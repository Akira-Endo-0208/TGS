#pragma once


class Enemy
{
public:
	void enemyInitialize();
	void enemyUpdate();
	void enemyDraw();
	void enemyMove();
	void enemyBorn();
	void enemyReset();
private:
	int enemy1Graph = LoadGraph("Resources/Enemy1.png");
	int enemy1X[5];
	int enemy1Y[5];
	int enemy1R = 25;
	int enemy1Speed[5];
	int enemy1Born[5];
	int enemy1Flag[5];
};