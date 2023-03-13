#include "DxLib.h"
#include "GameScene.h"


const char TITLE[] = "test";

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

	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���


	//�Q�[�����[�v�Ŏg���ϐ��̐錾
	char key[256] = { 0 }; //�ŐV�̃L�[�{�[�h���p
	char oldkey[256] = { 0 };//1���[�v�i�t���[���j�O�̃L�[�{�[�h���

	GameScene* gameScene = nullptr;
	gameScene = new GameScene();

	// ������
	gameScene->Initialize();

	// �Q�[�����[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//�ŐV�̃L�[�{�[�h��񂾂������̂͂P�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		for (int i = 0; i < 256; i++)
		{
			oldkey[i] = key[i];
		}

		//�ŐV�̃L�[�{�[�h�����擾
		GetHitKeyStateAll(key);

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