#include "SceneManager.h"

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

void SceneManager::changeScene(std::string sceneName) {
	_scenes.push(_sceneCreate[sceneName]->createScene());

	printf("Create Scene");
}