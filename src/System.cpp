#include "System.h"

#include <DxLib.h>
#include "ErrorProc.h"
#include "Fps.h"
#include "Keyboard.h"
#include "SceneManager.h"

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
		//画面をクリア
		ClearDrawScreen();

		_fps->update();
		_comp.keyboard->update();

		_comp.sceneMgr->update();
		_comp.sceneMgr->draw();

		//裏画面を反映させる
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