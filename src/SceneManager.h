#ifndef G_SCENEMANAGER_H
#define G_SCENEMANAGER_H

#include <unordered_map>
#include <stack>
#include <string>
#include "Object.h"
#include "ISceneCreate.h"

class Scene;

class SceneManager final : public Object {
private:
	std::unordered_map<std::string, ISceneCreate*> _sceneCreate;
	std::stack<Scene*> _scenes;

	void allSceneClear();
public:
	SceneManager(Component* comp) :Object(comp){}
	~SceneManager(){}
	bool init();
	void end();
	void update();
	void draw();

	void changeScene(std::string sceneName, bool isBack = false, bool isStack = false);

	void setSceneCreate(std::string sceneName, ISceneCreate* sceneCreate) {
		_sceneCreate[sceneName] = sceneCreate;
	}
};

#endif // !G_SCENEMANAGER_H
