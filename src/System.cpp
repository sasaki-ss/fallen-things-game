#include "System.h"

#include <DxLib.h>

bool System::init() {
	//FreeConsole();

	SetOutApplicationLogValidFlag(FALSE);					//���O���o�͂��Ȃ�
	SetAlwaysRunFlag(FALSE);								//Window���A�N�e�B�u�łȂ��ꍇ�͎��s���Ȃ�
	SetUseDXArchiveFlag(FALSE);								//DX�A�[�J�C�u���g�p���Ȃ�
	SetUse3DFlag(TRUE);										//3D�@�\���g�p����
	SetWaitVSyncFlag(FALSE);								//���������҂������Ȃ�
	SetMainWindowText(_windowTitle.c_str());				//�E�B���h�E�^�C�g����ύX
	SetWindowStyleMode(0);									//�E�B���h�E�X�^�C�����f�t�H���g��
	SetGraphMode((int)_windowPos.x, (int)_windowPos.y, 32);	//�摜�𑜓x��ύX
	ChangeWindowMode(TRUE);									//�E�B���h�E���[�h�ɕύX
	SetDrawMode(DX_DRAWMODE_NEAREST);						//�l�A���X�g�l�C�o�[�@�ŕ`�悷��
	if (DxLib_Init())return false;							//DX���C�u������������
	SetDrawScreen(DX_SCREEN_BACK);							//����ʏ�����ݒ�

	return true;
}

void System::run() {
	while (!ProcessMessage()) {
		//��ʂ��N���A
		ClearDrawScreen();

		//����ʂ𔽉f������
		ScreenFlip();
	}
}

void System::end() {
	DxLib_End();
}