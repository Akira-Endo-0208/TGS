#pragma once
#include "Player.h"


class Enemy
{
public:	// �����o�֐�
	void enemyInitialize(Player* player_);	// ������
	void enemyUpdate();		// �X�V
	void enemyDraw();		// �`��
	void enemyMove();		// ����
	void enemyBorn();		// ���X�|�[��
	void enemyReset();		// ���Z�b�g
	int GetenemyX() { for (int i = 0; i < 1; i++) { return enemy1X[i]; } }
	int GetenemyY() { for (int i = 0; i < 1; i++) { return enemy1Y[i]; } }
	int GetenemyFlag() { for (int i = 0; i < 1; i++) { return enemy1Flag[i]; } }
	int GetenemyReset() { for (int i = 0; i < 1; i++) { return enemy1Flag[i] = 0; } }
private: // �����o�ϐ�
	int enemy1X[5];		// X��
	int enemy1Y[5];		// Y��
	int enemy1R = 25;	// ���a
	int enemy1Speed[5];	// �X�s�[�h�l
	int enemy1Born[5];	// ���X�|�[��
	int enemy1Flag[5];	// �����t���O

	// �摜
	int enemy1Graph = LoadGraph("Resources/Enemy1.png");

	// �|�C���^
	Player* player;
};