#include "DropItem.h"

#include <DxLib.h>

DropItem::DropItem(Vector2 pos) :
	GameObject(pos),
	_dropSpeed() {

}

DropItem::~DropItem() {

}

bool DropItem::init() {
	_width = 32;
	_height = 32;
	_dropSpeed = 5.0f;
	return true;
}

void DropItem::end() {

}

void DropItem::update() {
	if (_pos.y < 600) {
		_pos.y += _dropSpeed;
	}
}

void DropItem::draw() {
	DrawBoxAA(_pos.x - (_width / 2), _pos.y - (_height / 2),
		_pos.x + (_width / 2), _pos.y + (_height / 2), GetColor(125, 125, 125), TRUE);
	DrawCircle(_pos.x, _pos.y, 2, GetColor(255, 0, 0), TRUE);

}