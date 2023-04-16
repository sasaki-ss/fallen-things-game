#include "Vector2.h"

//‹tƒxƒNƒgƒ‹
Vector2 operator-(const Vector2& _vec) {
	return Vector2(-_vec.x, -_vec.y);
}

//Vector2 - Vector2
Vector2 operator-(const Vector2& _vec, const Vector2& _vec2) {
	Vector2 returnVec;

	returnVec.x = _vec.x - _vec2.x;
	returnVec.y = _vec.y - _vec2.y;

	return returnVec;
}

void Vector2::operator +=(const Vector2& _vec) {
	this->x += _vec.x;
	this->y += _vec.y;
}

//Vector2 + Vector2
Vector2 operator+(const Vector2& _vec, const Vector2& _vec2) {
	Vector2 returnVec;

	returnVec.x = _vec.x + _vec2.x;
	returnVec.y = _vec.y + _vec2.y;

	return returnVec;
}

//Vector2 + float
Vector2 operator+(const Vector2& _vec, const float _s) {
	Vector2 returnVec;

	returnVec.x = _vec.x + _s;
	returnVec.y = _vec.y + _s;

	return returnVec;
}

void Vector2::operator-=(const Vector2& _vec) {
	this->x -= _vec.x;
	this->y -= _vec.y;
}

//Vector2 / float
Vector2 operator/(const Vector2& _vec, const float _s) {
	Vector2 returnVec;

	returnVec.x = _vec.x / _s;
	returnVec.y = _vec.y / _s;

	return returnVec;
}

void Vector2::operator*=(const Vector2& _vec) {
	this->x *= _vec.x;
	this->y *= _vec.y;
}

void Vector2::operator*=(const float _s) {
	this->x *= _s;
	this->y *= _s;
}

Vector2 operator*(const Vector2& _vec, const Vector2& _vec2) {
	Vector2 returnVec;

	returnVec.x = _vec.x * _vec2.x;
	returnVec.y = _vec.y * _vec2.y;

	return returnVec;
}

//Vector2 * float
Vector2 operator*(const Vector2& _vec, const float _s) {
	Vector2 returnVec;

	returnVec.x = _s * _vec.x;
	returnVec.y = _s * _vec.y;

	return returnVec;
}

//float * Vector2
Vector2 operator*(const float _s, const Vector2& _vec) {
	Vector2 returnVec;

	returnVec.x = _s * _vec.x;
	returnVec.y = _s * _vec.y;

	return returnVec;
}
