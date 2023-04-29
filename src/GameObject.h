#ifndef G_GAMEOBJECT_H
#define G_GAMEOBJECT_H

#include "Vector2.h"

#include "Object.h"

class GameObject :public Object {
protected:
	Vector2 _pos;
	float	_width;
	float	_height;
	bool	_isActive;
public:
	GameObject(Component* comp);
	GameObject(Vector2 pos, Component* comp);
	virtual ~GameObject() {}
	virtual bool init() = 0;
	virtual void end() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

	bool getIsActive() { return _isActive; }
	Vector2 getPos() { return _pos; }
};

#endif // !G_GAMEOBJECT_H
