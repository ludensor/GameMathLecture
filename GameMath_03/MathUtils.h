#pragma once

#include <math.h>

constexpr float PI = 3.1415926536f;

struct Vector2
{
	float x, y;

	static const Vector2 zero;
	static const Vector2 left;
	static const Vector2 right;
	static const Vector2 up;
	static const Vector2 down;

	const Vector2 operator-() const;
	const Vector2 operator+(const Vector2& v) const;
	const Vector2 operator-(const Vector2& v) const;
	const Vector2 operator*(float s) const;

	Vector2& operator+=(const Vector2& v);
	Vector2& operator-=(const Vector2& v);
	Vector2& operator*=(float s);

	static float Length(const Vector2& v);
	static float DotProduct(const Vector2& v1, const Vector2& v2);
	static const Vector2 Normalize(const Vector2& v);
	static const Vector2 Reflect(const Vector2& v, const Vector2& n);
	static const Vector2 Rotate(const Vector2& v, float angle);
};

inline const Vector2 Vector2::operator-() const
{
	return Vector2{ -x, -y };
}

inline const Vector2 Vector2::operator+(const Vector2& v) const
{
	return Vector2{ x + v.x, y + v.y };
}

inline const Vector2 Vector2::operator-(const Vector2& v) const
{
	return Vector2{ x - v.x, y - v.y };
}

inline const Vector2 Vector2::operator*(float s) const
{
	return Vector2{ x * s, y * s };
}

inline const Vector2 operator*(float s, const Vector2& v)
{
	return Vector2{ v.x * s, v.y * s };
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

inline float Vector2::Length(const Vector2& v)
{
	return sqrtf(v.x * v.x + v.y * v.y);
}

inline float Vector2::DotProduct(const Vector2& v1, const Vector2& v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

inline const Vector2 Vector2::Normalize(const Vector2& v)
{
	const float length_squared = v.x * v.x + v.y * v.y;

	if (length_squared <= 0.0f)
	{
		return Vector2::zero;
	}

	const float length = sqrtf(length_squared);
	const float inv_length = 1.0f / length;
	return Vector2{ v.x * inv_length, v.y * inv_length };
}

inline const Vector2 Vector2::Reflect(const Vector2& v, const Vector2& n)
{
	return v - 2.0f * n * DotProduct(v, n);
}

inline const Vector2 Vector2::Rotate(const Vector2& v, float angle)
{
	// TODO: v 벡터를 angle 값만큼 회전하도록 코드를 작성하시오(단 angle 값은 degrees로 값으로 간주합니다.)
	// angle을 radians 값으로 변환하여 코드를 작성합니다
}
