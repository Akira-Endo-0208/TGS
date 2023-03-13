#pragma once


class Player
{
public:
	void playerInitialize();
	void playerUpdate();
	void playerDraw();
	void playerMove();
	void playerReset();
private:
	int playerGraph = LoadGraph("Resources/Player1.png");
	int playerX;
	int playerY;
	int playerR = 15;
	int playerSpeed = 7;
	int playerFlag = 0;
};