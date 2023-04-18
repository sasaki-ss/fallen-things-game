#ifndef G_OBJECT_H
#define G_OBJECT_H

#include <string>
#include <unordered_map>

class Object {
protected:
	std::unordered_map<std::string, Object*> objs;
public:
	virtual ~Object() {}
	virtual bool init() = 0;
	virtual void end() = 0;
	virtual void update() = 0;
	virtual void draw() {}
};

#endif // !G_OBJECT_H
