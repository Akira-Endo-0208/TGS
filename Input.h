#pragma once


class Input
{
public:	// �����o�֐�
	//�ŐV�̃L�[�{�[�h��񂾂������̂͂P�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
	void SaveoldKey(){
		for (int i = 0; i < 256; i++)
		{
			oldkey[i] = key[i];
		}
	};
private: // �����o�ϐ�
	//�Q�[�����[�v�Ŏg���ϐ��̐錾
	char key[256] = { 0 }; //�ŐV�̃L�[�{�[�h���p
	char oldkey[256] = { 0 };//1���[�v�i�t���[���j�O�̃L�[�{�[�h���
};