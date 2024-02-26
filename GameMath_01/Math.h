#pragma once

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
};

const Vector2 Vector2::left{ -1.0f, 0.0f };
const Vector2 Vector2::right{ 1.0f, 0.0f };
const Vector2 Vector2::up{ 0.0f, -1.0f };
const Vector2 Vector2::down{ 0.0f, 1.0f };

inline const Vector2 Vector2::operator+(const Vector2& v) const
{
	// TODO: ∫§≈Õ¿« µ°º¿¿ª ¿€º∫«œΩ√ø¿
}

inline const Vector2 Vector2::operator-(const Vector2& v) const
{
	// TODO: ∫§≈Õ¿« ª¨º¿¿ª ¿€º∫«œΩ√ø¿
}

inline const Vector2 Vector2::operator*(float s) const
{
	// TODO: ∫§≈Õ¿« ∞ˆº¿¿ª ¿€º∫«œΩ√ø¿
}

inline Vector2& Vector2::operator+=(const Vector2& v)
{
	// TODO: ∫§≈Õ¿« µ°º¿¿ª ¿€º∫«œΩ√ø¿
}

inline Vector2& Vector2::operator-=(const Vector2& v)
{
	// TODO: ∫§≈Õ¿« ª¨º¿¿ª ¿€º∫«œΩ√ø¿
}

inline Vector2& Vector2::operator*=(float s)
{
	// TODO: ∫§≈Õ¿« ∞ˆº¿¿ª ¿€º∫«œΩ√ø¿
}
