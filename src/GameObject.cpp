#include "GameObject.h"

GameObject::GameObject() :
	_pos(),
	_width(),
	_height(),
	_isActive(true) {

}

GameObject::GameObject(Vector2 pos) :
	_pos(pos),
	_width(),
	_height(),
	_isActive(true) {

}