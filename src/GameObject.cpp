#include "GameObject.h"

GameObject::GameObject(Component* comp) :
	Object(comp),
	_pos(),
	_width(),
	_height(),
	_isActive(true) {

}

GameObject::GameObject(Vector2 pos, Component* comp) :
	Object(comp),
	_pos(pos),
	_width(),
	_height(),
	_isActive(true) {

}