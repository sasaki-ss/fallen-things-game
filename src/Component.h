#ifndef G_COMPONENT_H
#define G_COMPONENT_H

#include <memory>
#include <random>

#include "Keyboard.h"
#include "SceneManager.h"

class Component {
private:
	std::mt19937 _rand;
	std::unique_ptr<Keyboard> _keyboard;
	std::unique_ptr<SceneManager> _sceneMgr;
public:
	Component();
	~Component();
	bool init();
	
	Keyboard* getKeyboard() { return _keyboard.get(); }
	SceneManager* getSceneMgr() { return _sceneMgr.get(); }
	unsigned int getRand() { return _rand(); }
};

#endif // !G_COMPONENT_H
