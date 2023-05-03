#include "System.h"

#include <DxLib.h>
#include "ErrorProc.h"
#include "Fps.h"
#include "Keyboard.h"
#include "SceneManager.h"

bool System::init() {
	//FreeConsole();

	SetOutApplicationLogValidFlag(FALSE);					//���O���o�͂��Ȃ�
	SetAlwaysRunFlag(TRUE);								//Window���A�N�e�B�u�łȂ��ꍇ�͎��s���Ȃ�
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
	
	std::random_device rnd;
	_comp.rand.seed(rnd());
	_comp.keyboard = std::make_unique<Keyboard>(&_comp);
	_fps = new Fps();

	_fps->init();
	_comp.keyboard->init();

	return true;
}

void System::run() {
	while (!ProcessMessage()) {
		//��ʂ��N���A
		ClearDrawScreen();

		_fps->update();
		_comp.keyboard->update();

		_comp.sceneMgr->update();
		_comp.sceneMgr->draw();

		//����ʂ𔽉f������
		ScreenFlip();

		_fps->wait();
	}
}

void System::end() {
	delete _fps;
	delete _sceneMgr;
	DxLib_End();
}

void System::setSceneSystem(std::string defSceneName, ISceneCreate* defSceneCreate) {
	_comp.sceneMgr = std::make_unique<SceneManager>(&_comp);
	setSceneCreate(defSceneName, defSceneCreate);
	_comp.sceneMgr->changeScene(defSceneName);

	if (!_comp.sceneMgr->init()) {
		ErrorProc::ErrorExit("Initialization of SceneManager failed.");
	}
}

void System::setSceneCreate(std::string sceneName, ISceneCreate* sceneCreate) {
	_comp.sceneMgr->setSceneCreate(sceneName, sceneCreate);
}