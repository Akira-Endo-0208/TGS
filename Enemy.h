#pragma once


class Enemy
{
public:	// �����o�֐�
	void enemyInitialize();	// ������
	void enemyUpdate();		// �X�V
	void enemyDraw();		// �`��
	void enemyMove();		// ����
	void enemyBorn();		// ���X�|�[��
	void enemyReset();		// ���Z�b�g
private: // �����o�ϐ�
	int enemy1X[5];		// X��
	int enemy1Y[5];		// Y��
	int enemy1R = 25;	// ���a
	int enemy1Speed[5];	// �X�s�[�h�l
	int enemy1Born[5];	// ���X�|�[��
	int enemy1Flag[5];	// �����t���O
	int enemy1Graph = LoadGraph("Resources/Enemy1.png"); // �摜
};