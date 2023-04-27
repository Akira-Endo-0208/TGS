#pragma once
#include "Player.h"


class Sprite
{
public:	// �����o�֐�
	void spriteInitialize(Player* player_); // ������
	void spriteUpdate();	// �X�V
	void spriteDraw();		// �`��
	void scrollUpdate();	// �X�N���[��
	void spriteReset();		// ���Z�b�g
	void SetMaxWidth(int _maxWidth) { this->maxWidth = _maxWidth; }
	int GetScrollX() { return scrollX; }
	int GetRoundTripFlag() { return roundTripFlag; }
private: // �����o�ϐ�
	// �X�N���[���ϐ�
	int scrollScreenX;		//�v���C���[�̃��j�^�[���W
	int scrollScreenY = 0;	//���݂͎g�p���Ă��Ȃ�
	int scrollX;			//�ړ��ʂ̋L��
	int scrollY = 0;		//���݂͎g�p���Ă��Ȃ�
	int roundTripFlag = 0;
	int maxWidth = 0;

	// �摜
	int backGroundGraph = LoadGraph("Resources/haikei2.png");

	// �|�C���^
	Player* player;
};