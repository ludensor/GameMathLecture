#pragma once

#include <math.h>

struct Vector2
{
	float x, y;

	Vector2() = default;
	constexpr Vector2(float _x, float _y);

	static const Vector2 left;
	static const Vector2 right;
	static const Vector2 up;
	static const Vector2 down;

	constexpr Vector2 operator+(const Vector2& v) const;
	constexpr Vector2 operator-(const Vector2& v) const;
	constexpr Vector2 operator*(float s) const;

	Vector2& operator+=(const Vector2& v);
	Vector2& operator-=(const Vector2& v);
	Vector2& operator*=(float s);

	static constexpr float DotProduct(const Vector2& v1, const Vector2& v2);
	static constexpr Vector2 Normalize(const Vector2& v);
	static constexpr Vector2 Reflect(const Vector2& v, const Vector2& n);
};

struct Box
{
	Vector2 min;
	Vector2 max;
	Vector2 normal;
};

inline constexpr Vector2::Vector2(float _x, float _y)
	: x(_x), y(_y)
{

}

inline constexpr Vector2 Vector2::operator+(const Vector2& v) const
{
	return Vector2(x + v.x, y + v.y);
}

inline constexpr Vector2 Vector2::operator-(const Vector2& v) const
{
	return Vector2(x - v.x, y - v.y);
}

inline constexpr Vector2 Vector2::operator*(float s) const
{
	return Vector2(x * s, y * s);
}

inline Vector2& Vector2::operator+=(const Vector2& v)
{
	x += v.x;
	y += v.y;
	return *this;
}

inline Vector2& Vector2::operator-=(const Vector2& v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}

inline Vector2& Vector2::operator*=(float s)
{
	x *= s;
	y *= s;
	return *this;
}

inline constexpr float Vector2::DotProduct(const Vector2& v1, const Vector2& v2)
{
	// TODO: 벡터의 내적을 구하는 코드를 작성하시오
}

inline constexpr Vector2 Vector2::Normalize(const Vector2& v)
{
	// TODO: 벡터의 정규화를 구하는 코드를 작성하시오(제곱근 함수(sqrtf)를 사용할 것)
}

inline constexpr Vector2 Vector2::Reflect(const Vector2& v, const Vector2& n)
{
	// TODO: 입사벡터 v, 법선벡터 n이 주어졌을 때 반사벡터를 구하는 코드를 작성하시오
}
