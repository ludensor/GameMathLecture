#pragma once

struct Vector2
{
	float x, y;

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
};

inline constexpr Vector2 Vector2::operator+(const Vector2& v) const
{
	// TODO: ∫§≈Õ¿« µ°º¿¿ª ¿€º∫«œΩ√ø¿
}

inline constexpr Vector2 Vector2::operator-(const Vector2& v) const
{
	// TODO: ∫§≈Õ¿« ª¨º¿¿ª ¿€º∫«œΩ√ø¿
}

inline constexpr Vector2 Vector2::operator*(float s) const
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
