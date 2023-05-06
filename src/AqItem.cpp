#include "AqItem.h"

#include <DxLib.h>

AqItem::AqItem(Vector2 pos, int score, Component* comp) :
	Item(pos, comp),
	_score(score) {

}

AqItem::~AqItem() {

}

bool AqItem::init() {
	_width = 32;
	_height = 32;
	_fallSpped = 5.0f;
	return true;
}

void AqItem::end() {

}

void AqItem::update() {
	if (_pos.y < 600) {
		_pos.y += _fallSpped;
	}
	else {
		_isActive = false;
	}
}

void AqItem::draw() {
	DrawBoxAA(_pos.x - (_width / 2), _pos.y - (_height / 2),
		_pos.x + (_width / 2), _pos.y + (_height / 2), GetColor(125, 125, 125), TRUE);
	DrawCircle(_pos.x, _pos.y, 2, GetColor(255, 0, 0), TRUE);

	Vector2 v = getLeftTopPos();

	DrawBoxAA(v.x, v.y,
		v.x + _width, v.y + _height, GetColor(255, 0, 0), FALSE);
}