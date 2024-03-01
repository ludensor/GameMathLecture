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

	constexpr Vector2 operator-() const;
	constexpr Vector2 operator+(const Vector2& v) const;
	constexpr Vector2 operator-(const Vector2& v) const;
	constexpr Vector2 operator*(float s) const;

	Vector2& operator+=(const Vector2& v);
	Vector2& operator-=(const Vector2& v);
	Vector2& operator*=(float s);

	static float Length(const Vector2& v);
	static constexpr float LengthSquared(const Vector2& v);
	static constexpr float DotProduct(const Vector2& v1, const Vector2& v2);
	static Vector2 Normalize(const Vector2& v);
	static constexpr Vector2 Reflect(const Vector2& v, const Vector2& n);
	static Vector2 Rotate(const Vector2& v, float angle);
};

inline constexpr Vector2 Vector2::operator-() const
{
	return Vector2{ -x, -y };
}

inline constexpr Vector2 Vector2::operator+(const Vector2& v) const
{
	return Vector2{ x + v.x, y + v.y };
}

inline constexpr Vector2 Vector2::operator-(const Vector2& v) const
{
	return Vector2{ x - v.x, y - v.y };
}

inline constexpr Vector2 Vector2::operator*(float s) const
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
	return sqrtf(LengthSquared(v));
}

inline constexpr float Vector2::LengthSquared(const Vector2& v)
{
	return v.x * v.x + v.y * v.y;
}

inline constexpr float Vector2::DotProduct(const Vector2& v1, const Vector2& v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

inline Vector2 Vector2::Normalize(const Vector2& v)
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

inline constexpr Vector2 Vector2::Reflect(const Vector2& v, const Vector2& n)
{
	return v - 2.0f * n * DotProduct(v, n);
}

inline Vector2 Vector2::Rotate(const Vector2& v, float angle)
{
	// TODO: v 벡터를 angle 값만큼 회전하도록 코드를 작성하시오(단 angle 값은 degrees 값으로 간주합니다.)
	// angle을 radians 값으로 변환하여 코드를 작성합니다
}
