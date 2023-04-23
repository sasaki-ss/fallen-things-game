#ifndef G_SCENEMANAGER_H
#define G_SCENEMANAGER_H

#include <unordered_map>
#include <stack>
#include <string>
#include "ISceneCreate.h"

class Scene;
struct Component;

class SceneManager final {
private:
	std::unordered_map<std::string, ISceneCreate*> _sceneCreate;
	std::stack<Scene*> _scenes;
	Component* _comp;

	void allSceneClear();
public:
	bool init();
	void end();
	void update();
	void draw();

	void changeScene(std::string sceneName, bool isBack = false, bool isStack = false);
	
	void setSceneCreate(std::string sceneName, ISceneCreate* sceneCreate) {
		_sceneCreate[sceneName] = sceneCreate;
	}

	void setComponent(Component* comp) { _comp = comp; }
};

#endif // !G_SCENEMANAGER_H
