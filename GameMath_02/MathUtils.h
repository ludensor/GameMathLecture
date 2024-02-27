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
	// TODO: ������ ������ ���ϴ� �ڵ带 �ۼ��Ͻÿ�
}

inline constexpr Vector2 Vector2::Normalize(const Vector2& v)
{
	// TODO: ������ ����ȭ�� ���ϴ� �ڵ带 �ۼ��Ͻÿ�(������ �Լ�(sqrtf)�� ����� ��)
}

inline constexpr Vector2 Vector2::Reflect(const Vector2& v, const Vector2& n)
{
	// TODO: �Ի纤�� v, �������� n�� �־����� �� �ݻ纤�͸� ���ϴ� �ڵ带 �ۼ��Ͻÿ�
}
