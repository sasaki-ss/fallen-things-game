#ifndef G_VECTOR2_H
#define G_VECTOR2_H

#include <cmath>

//2次元ベクトル構造体
struct Vector2 {
	float x;	//横方向の成分
	float y;	//縦方向の成分

	//デフォルトコンストラクタ
	Vector2() {
		x = 0;
		y = 0;
	}

	//引数付きコンストラクタ
	Vector2(float _x, float _y) {
		x = _x;
		y = _y;
	}

#pragma region 演算子のオーバーロード関連
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

	//ドット積
	float Dot(const Vector2& _vec)const {
		return x * _vec.x + y * _vec.y;
	}

	//長さ
	float Length()const {
		return std::sqrtf(Dot(*this));
	}

	//単位ベクトル
	Vector2 Unit()const {
		return *this / Length();
	}

	//反射ベクトル
	Vector2 Reflection(const Vector2& _vec)const {
		return *this + (-2.0f * Dot(_vec)) * _vec;
	}
};


#endif // !G_VECTOR2_H
