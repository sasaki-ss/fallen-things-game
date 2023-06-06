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

	SetOutApplicationLogValidFlag(FALSE);					//ログを出力しない
	SetAlwaysRunFlag(TRUE);								//Windowがアクティブでない場合は実行しない
	SetUseDXArchiveFlag(FALSE);								//DXアーカイブを使用しない
	SetUse3DFlag(TRUE);										//3D機能を使用する
	SetWaitVSyncFlag(FALSE);								//垂直同期待ちをしない
	SetMainWindowText(_windowTitle.c_str());				//ウィンドウタイトルを変更
	SetWindowStyleMode(0);									//ウィンドウスタイルをデフォルトに
	SetGraphMode((int)_windowPos.x, (int)_windowPos.y, 32);	//画像解像度を変更
	ChangeWindowMode(TRUE);									//ウィンドウモードに変更
	SetDrawMode(DX_DRAWMODE_NEAREST);						//ネアレストネイバー法で描画する
	if (DxLib_Init())return false;							//DXライブラリを初期化
	SetDrawScreen(DX_SCREEN_BACK);							//裏画面処理を設定

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
		//画面をクリア
		ClearDrawScreen();

		_fps->update();
		_keyboard->update();

		_sceneMgr->update();
		_sceneMgr->draw();

		//裏画面を反映させる
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