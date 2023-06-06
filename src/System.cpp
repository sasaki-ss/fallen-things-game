#include "System.h"

#include <DxLib.h>
#include "Define.h"
#include "ErrorProc.h"
#include "Fps.h"
#include "Keyboard.h"
#include "SceneManager.h"

System::System() :
	_fps(nullptr) {

}

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

	_comp.init();
	
	_fps = new Fps();
	_image = std::make_unique<Image>();
	_keyboard = std::make_unique<Keyboard>(&_comp);
	_sceneMgr = std::make_unique<SceneManager>(&_comp);

	_comp.setObj(OBJ_IMAGE, _image.get());
	_comp.setObj(OBJ_KEYBOARD, _keyboard.get());
	_comp.setObj(OBJ_SCENEMANGER, _sceneMgr.get());

	_image->init();
	_keyboard->init();
	_sceneMgr->init();

	_fps->init();

	return true;
}

void System::run() {
	while (!ProcessMessage()) {
		//��ʂ��N���A
		ClearDrawScreen();

		_fps->update();
		_keyboard->update();

		_sceneMgr->update();
		_sceneMgr->draw();

		//����ʂ𔽉f������
		ScreenFlip();

		_fps->wait();
	}
}

void System::end() {
	_image->end();
	_keyboard->end();
	_sceneMgr->end();
	delete _fps;
	DxLib_End();
}

void System::loadImage(std::string filePath) {
	_image->setFilePath(filePath);
	_image->load();
}

void System::setSceneSystem(std::string defSceneName,
	std::unique_ptr<ISceneCreate> defSceneCreate) {
	setSceneCreate(defSceneName, move(defSceneCreate));
	_sceneMgr->changeScene(defSceneName);

	if (!_sceneMgr->init()) {
		ErrorProc::ErrorExit("Initialization of SceneManager failed.");
	}
}

void System::setSceneCreate(std::string sceneName,
	std::unique_ptr<ISceneCreate> sceneCreate) {
	_sceneMgr->setSceneCreate(sceneName, move(sceneCreate));
}