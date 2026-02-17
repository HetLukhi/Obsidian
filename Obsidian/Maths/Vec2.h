#pragma once
#include <iostream>
#include <cmath>

namespace obsidian {
	namespace math {
		struct vec2 {
			float x, y;

			vec2();
			vec2(float scalar);
			vec2(float x, float y);

			vec2& add(const vec2& other);
			vec2& subtract(const vec2& other);
			vec2& multiply(const vec2& other);
			vec2& divide(const vec2& other);

			vec2 operator+(const vec2& other) const;
			vec2 operator-(const vec2& other) const;
			vec2 operator*(const vec2& other) const;
			vec2 operator/(const vec2& other) const;

			vec2& operator+=(const vec2& other);
			vec2& operator-=(const vec2& other);
			vec2& operator*=(const vec2& other);
			vec2& operator/=(const vec2& other);

			bool operator==(const vec2& other) const;
			bool operator!=(const vec2& other) const;

			vec2 operator*(float scalar) const;
			vec2 operator/(float scalar) const;

			vec2& operator*=(float scalar);
			vec2& operator/=(float scalar);

			float length() const;
			float lengthSquared() const;

			float angle() const;

			vec2& rotate(float radians);
			vec2 rotated(float radians) const;


			vec2& normalize();
			vec2 normalized() const;

			float dot(const vec2& other) const;

			static float distance(const vec2& a, const vec2& b);
			static float distanceSquared(const vec2& a, const vec2& b);
		};
	}
}