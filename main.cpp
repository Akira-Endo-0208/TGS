#include "DxLib.h"
#include "GameScene.h"


const char TITLE[] = "ROBOT RUN";

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	const int WindowWidth = 1280;
	const int WindowHeight = 720;

	ChangeWindowMode(true);							// ウインドウモードにする
	SetGraphMode(WindowWidth, WindowHeight, 32);	// 画面モードのセット
	SetMainWindowText(TITLE);					// タイトルを変更
	SetBackgroundColor(0, 0, 64);					// 背景色 RGB
	if (DxLib_Init() == -1)return -1;				// DxLib 初期化処理
	SetDrawScreen(DX_SCREEN_BACK);					// 描画先画面を裏画面にセット

	GameScene* gameScene = nullptr;
	gameScene = new GameScene();

	// 初期化
	gameScene->Initialize();

	// ゲームループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// 更新
		gameScene->Update();

		// 描画
		ClearDrawScreen();	// 画面を消去
		gameScene->Draw();

		// フリップする
		ScreenFlip();
	}
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}