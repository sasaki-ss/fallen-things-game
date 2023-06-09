#ifndef G_SYSTEM_H
#define G_SYSTEM_H

#include <string>
#include "ISceneCreate.h"
#include "Vector2.h"
#include "Component.h"

class Fps;

class System final {
private:
	Vector2		_windowPos;
	std::string _windowTitle;
	Fps*		_fps;

	Component		_comp;
	Keyboard*		_keyboard;
	SceneManager*	_sceneMgr;
public:
	bool init();
	void run();
	void end();

	void setWindowPos(Vector2 pos) { _windowPos = pos; }
	void setWindowTitle(std::string name) { _windowTitle = name; }
	void setSceneSystem(std::string defSceneName, ISceneCreate* defSceneCreate);
	void setSceneCreate(std::string sceneName, ISceneCreate* sceneCreate);
};

#endif // !G_SYSTEM_H
