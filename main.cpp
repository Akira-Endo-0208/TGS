#include "DxLib.h"
#include "GameScene.h"


const char TITLE[] = "ROBOT RUN";

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	const int WindowWidth = 1280;
	const int WindowHeight = 720;

	ChangeWindowMode(true);							// �E�C���h�E���[�h�ɂ���
	SetGraphMode(WindowWidth, WindowHeight, 32);	// ��ʃ��[�h�̃Z�b�g
	SetMainWindowText(TITLE);					// �^�C�g����ύX
	SetBackgroundColor(0, 0, 64);					// �w�i�F RGB
	if (DxLib_Init() == -1)return -1;				// DxLib ����������
	SetDrawScreen(DX_SCREEN_BACK);					// �`����ʂ𗠉�ʂɃZ�b�g

	GameScene* gameScene = nullptr;
	gameScene = new GameScene();

	// ������
	gameScene->Initialize();

	// �Q�[�����[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// �X�V
		gameScene->Update();

		// �`��
		ClearDrawScreen();	// ��ʂ�����
		gameScene->Draw();

		// �t���b�v����
		ScreenFlip();
	}
	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}