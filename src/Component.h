#ifndef G_COMPONENT_H
#define G_COMPONENT_H

#include <memory>
#include <random>
#include <unordered_map>

#include "Keyboard.h"
#include "SceneManager.h"

class Component {
private:
	std::mt19937 _rand;
	std::unique_ptr<Keyboard> _keyboard;
	std::unique_ptr<SceneManager> _sceneMgr;
	std::unordered_map<std::string, Object*> _objs;
public:
	Component();
	~Component();
	bool init();

	void releaseObj() { _objs.clear(); }

	void setObj(std::string objName, Object* obj) { _objs[objName] = obj; }
	
	unsigned int getRand() { return _rand(); }
	Keyboard* getKeyboard() { return _keyboard.get(); }
	SceneManager* getSceneMgr() { return _sceneMgr.get(); }

	template <class T>
	T* getObj(std::string objName) {
		auto it = _objs.find(objName);
		if (_objs.end() == it) {
			return nullptr;
		}
		else {
			return static_cast<T*>(it->second);
		}
	}
};

#endif // !G_COMPONENT_H
