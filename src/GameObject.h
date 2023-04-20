#ifndef G_GAMEOBJECT_H
#define G_GAMEOBJECT_H

#include "Vector2.h"

class GameObject {
protected:
	Vector2 _pos;
	float	_width;
	float	_height;
	bool	_isActive;
public:
	GameObject();
	GameObject(Vector2 pos);
	virtual ~GameObject(){}
	virtual bool init() = 0;
	virtual void end() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
};

#endif // !G_GAMEOBJECT_H