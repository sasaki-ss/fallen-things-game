#ifndef G_SCENEMANAGER_H
#define G_SCENEMANAGER_H

#include <unordered_map>
#include <stack>
#include <string>
#include "ISceneCreate.h"

class Scene;

class SceneManager final {
private:
	std::unordered_map<std::string, ISceneCreate*> _sceneCreate;
	std::stack<Scene*> _scenes;

	void allSceneClear();
public:
	bool init();
	void end();
	void update();
	void draw();

	void changeScene(std::string sceneName);
	

	void setSceneCreate(std::string sceneName, ISceneCreate* sceneCreate) {
		_sceneCreate[sceneName] = sceneCreate;
	}
};

#endif // !G_SCENEMANAGER_H
