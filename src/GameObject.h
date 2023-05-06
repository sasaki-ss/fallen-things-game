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

	Vector2 getPos() { return _pos; }
	Vector2 getLeftTopPos() { return Vector2(_pos.x - (_width / 2), _pos.y - (_height / 2)); }
	float getWidth() { return _width; }
	float getHeight() { return _height; }
	bool getIsActive() { return _isActive; }
};

#endif // !G_GAMEOBJECT_H
