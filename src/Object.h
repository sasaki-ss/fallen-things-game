#ifndef G_OBJECT_H
#define G_OBJECT_H

#include <string>
#include <unordered_map>

struct Component;

class Object {
protected:
	std::unordered_map<std::string, Object*> _objs;
	Component* _comp;
public:
	Object(Component* comp) :
		_comp(comp) {

	}
	virtual ~Object() {}
	virtual bool init() = 0;
	virtual void end() = 0;
	virtual void update() = 0;
	virtual void draw() {}
};

#endif // !G_OBJECT_H
