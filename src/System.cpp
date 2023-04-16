#include "System.h"

#include <DxLib.h>
#include "ErrorProc.h"
#include "SceneManager.h"

bool System::init() {
	//FreeConsole();

	SetOutApplicationLogValidFlag(FALSE);					//ログを出力しない
	SetAlwaysRunFlag(FALSE);								//Windowがアクティブでない場合は実行しない
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

	return true;
}

void System::run() {
	while (!ProcessMessage()) {
		//画面をクリア
		ClearDrawScreen();

		_sceneMgr->update();
		_sceneMgr->draw();

		//裏画面を反映させる
		ScreenFlip();
	}
}

void System::end() {
	DxLib_End();
}

void System::setSceneSystem(std::string defSceneName, ISceneCreate* defSceneCreate) {
	_sceneMgr = new SceneManager();
	setSceneCreate(defSceneName, defSceneCreate);
	_sceneMgr->changeScene(defSceneName);
	if (!_sceneMgr->init())ErrorProc::ErrorExit("Initialization of SceneManager failed.");
}

void System::setSceneCreate(std::string sceneName, ISceneCreate* sceneCreate) {
	_sceneMgr->setSceneCreate(sceneName, sceneCreate);
}