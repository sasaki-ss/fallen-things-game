#ifndef G_VECTOR2_H
#define G_VECTOR2_H

#include <cmath>

//2�����x�N�g���\����
struct Vector2 {
	float x;	//�������̐���
	float y;	//�c�����̐���

	//�f�t�H���g�R���X�g���N�^
	Vector2() {
		x = 0;
		y = 0;
	}

	//�����t���R���X�g���N�^
	Vector2(float _x, float _y) {
		x = _x;
		y = _y;
	}

#pragma region ���Z�q�̃I�[�o�[���[�h�֘A
	void operator+=(const Vector2& _vec);
	void operator-=(const Vector2& _vec);
	void operator*=(const Vector2& _vec);
	void operator*=(const float _s);
	friend Vector2 operator-(const Vector2& _vec);
	friend Vector2 operator-(const Vector2& _vec, const Vector2& _vec2);
	friend Vector2 operator+(const Vector2& _vec, const Vector2& _vec2);
	friend Vector2 operator+(const Vector2& _vec, const float _s);
	friend Vector2 operator*(const Vector2& _vec, const Vector2& _vec2);
	friend Vector2 operator*(const Vector2& _vec, const float _s);
	friend Vector2 operator*(const float _s, const Vector2& _vec);
	friend Vector2 operator/(const Vector2& _vec, const float _s);
#pragma endregion

	//�h�b�g��
	float Dot(const Vector2& _vec)const {
		return x * _vec.x + y * _vec.y;
	}

	//����
	float Length()const {
		return std::sqrtf(Dot(*this));
	}

	//�P�ʃx�N�g��
	Vector2 Unit()const {
		return *this / Length();
	}

	//���˃x�N�g��
	Vector2 Reflection(const Vector2& _vec)const {
		return *this + (-2.0f * Dot(_vec)) * _vec;
	}
};


#endif // !G_VECTOR2_H
