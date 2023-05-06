#include "Player.h"

#include <DxLib.h>
#include "Component.h"
#include "Keyboard.h"

Player::Player(Component* comp) :
	GameObject(comp),
	_kb(nullptr) {

}

Player::~Player() {

}

bool Player::init() {
	_pos = Vector2(600, 600-16);
	_width = 48;
	_height = 64;

	_kb = _comp->getKeyboard();

	return true;
}

void Player::end() {

}

void Player::update() {
	if (_kb->getInputKey(KEY_INPUT_A) != 0) {
		_pos.x -= 5.0f;
	}

	if (_kb->getInputKey(KEY_INPUT_D) != 0) {
		_pos.x += 5.0f;
	}
}

void Player::draw() {
	DrawBoxAA(_pos.x - (_width / 2), _pos.y - (_height / 2),
		_pos.x + (_width / 2), _pos.y + (_height / 2), GetColor(125, 125, 125), TRUE);
	DrawCircle(_pos.x, _pos.y, 2, GetColor(255, 0, 0), TRUE);

	Vector2 v = getLeftTopPos();

	DrawBoxAA(v.x, v.y,
		v.x + _width, v.y + _height, GetColor(255, 0, 0), FALSE);
}