#ifndef G_COMPONENT_H
#define G_COMPONENT_H

#include <memory>
#include <random>
#include <unordered_map>

#include "Image.h"
#include "Keyboard.h"
#include "SceneManager.h"

class Component final {
private:
	std::mt19937 _rand;
	std::unordered_map<std::string, Object*>	_objs;
public:
	Component();
	~Component();
	bool init();

	void releaseObj(std::string objName) { _objs[objName] = nullptr; }
	void allReleaseObj() { _objs.clear(); }

	void setObj(std::string objName, Object* obj) { _objs[objName] = obj; }
	
	unsigned int getRand() { return _rand(); }

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
