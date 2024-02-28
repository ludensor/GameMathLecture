#pragma once

#include <math.h>

struct Vector2
{
	float x, y;

	static const Vector2 left;
	static const Vector2 right;
	static const Vector2 up;
	static const Vector2 down;

	const Vector2 operator+(const Vector2& v) const;
	const Vector2 operator-(const Vector2& v) const;
	const Vector2 operator*(float s) const;

	Vector2& operator+=(const Vector2& v);
	Vector2& operator-=(const Vector2& v);
	Vector2& operator*=(float s);

	static float DotProduct(const Vector2& v1, const Vector2& v2);
	static const Vector2 Normalize(const Vector2& v);
	static const Vector2 Reflect(const Vector2& v, const Vector2& n);
};

struct Box
{
	Vector2 min;
	Vector2 max;
	Vector2 normal;
};

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

inline float Vector2::DotProduct(const Vector2& v1, const Vector2& v2)
{
	// TODO: ������ ������ ���ϴ� �ڵ带 �ۼ��Ͻÿ�
	return 0.0f;
}

inline const Vector2 Vector2::Normalize(const Vector2& v)
{
	// TODO: ������ ����ȭ�� ���ϴ� �ڵ带 �ۼ��Ͻÿ�(������ �Լ�(sqrtf)�� ����� ��)
	return Vector2();
}

inline const Vector2 Vector2::Reflect(const Vector2& v, const Vector2& n)
{
	// TODO: �Ի纤�� v, �������� n�� �־����� �� �ݻ纤�͸� ���ϴ� �ڵ带 �ۼ��Ͻÿ�
	return Vector2();
}
