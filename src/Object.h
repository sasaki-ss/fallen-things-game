#ifndef G_OBJECT_H
#define G_OBJECT_H

#include <string>
#include <unordered_map>

class Component;

class Object {
protected:
	Component* _comp;
public:
	Object() :
		_comp(nullptr) {

	}

	Object(Component* comp) :
		_comp(comp) {

	}
	virtual ~Object() {}
	virtual bool init() = 0;
	virtual void end() = 0;
	virtual void update(){}
	virtual void draw() {}
};

#endif // !G_OBJECT_H
