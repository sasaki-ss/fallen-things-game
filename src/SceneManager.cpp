#include "SceneManager.h"

#include "ErrorProc.h"
#include "Scene.h"

bool SceneManager::init() {
	return true;
}

void SceneManager::end() {
	allSceneClear();
}

void SceneManager::update() {
	_scenes.top()->update();
}

void SceneManager::draw() {
	_scenes.top()->draw();
}

void SceneManager::allSceneClear() {
	while (!_scenes.empty()) {
		_scenes.top()->end();
		_scenes.pop();
	}
}

void SceneManager::changeScene(std::string sceneName, bool isBack, bool isStack) {
	if (isBack) {
		_scenes.top()->end();
		_scenes.pop();
	}

	if (!isStack) {
		allSceneClear();
	}

	auto it = _sceneCreate.find(sceneName);
	if (_sceneCreate.end() == it) {
		ErrorProc::ErrorExit("Scene generation class is not registered.");
	}

	_scenes.push(_sceneCreate[sceneName]->createScene(_comp));

	if (!_scenes.top()->init()) {
		ErrorProc::ErrorExit("error scene exist.");
	}
}