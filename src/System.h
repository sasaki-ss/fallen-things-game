#ifndef G_SYSTEM_H
#define G_SYSTEM_H

#include <memory>
#include <string>
#include "Component.h"
#include "Image.h"
#include "ISceneCreate.h"
#include "Keyboard.h"
#include "SceneManager.h"
#include "Vector2.h"


class Fps;

class System final {
private:
	Vector2		_windowPos;
	std::string _windowTitle;
	Fps*		_fps;

	Component		_comp;

	//std::unique_ptr<Image>						_image;
	//std::unique_ptr<Keyboard>					_keyboard;
	//std::unique_ptr<SceneManager>				_sceneMgr;

	std::unique_ptr<Image>			_image;
	std::unique_ptr<Keyboard>		_keyboard;
	std::unique_ptr<SceneManager>	_sceneMgr;
public:
	System();
	bool init();
	void run();
	void end();

	void loadImage(std::string filePath);

	void setWindowPos(Vector2 pos) { _windowPos = pos; }
	void setWindowTitle(std::string name) { _windowTitle = name; }
	void setSceneSystem(std::string defSceneName,
		std::unique_ptr<ISceneCreate> defSceneCreate);
	void setSceneCreate(std::string sceneName,
		std::unique_ptr<ISceneCreate> sceneCreate);
};

#endif // !G_SYSTEM_H
