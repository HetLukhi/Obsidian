#include "Vec2.h"

namespace obsidian {
	namespace math {
		vec2::vec2() {
			x = 0.0f;
			y = 0.0f;
		}

		vec2::vec2(float scalar) {
			x = scalar;
			y = scalar;
		}

		vec2::vec2(float x, float y) {
			this->x = x;
			this->y = y;
		}

		vec2& vec2::add(const vec2& other) {
			x += other.x;
			y += other.y;
			return *this;
		}

		vec2& vec2::subtract(const vec2& other) {
			x -= other.x;
			y -= other.y;
			return *this;
		}

		vec2& vec2::multiply(const vec2& other) {
			x *= other.x;
			y *= other.y;
			return *this;
		}

		vec2& vec2::divide(const vec2& other) {
			x /= other.x;
			y /= other.y;
			return *this;
		}

		vec2 vec2::operator+(const vec2& other) const{
			return vec2(this->x + other.x, this->y + other.y);
		}

		vec2 vec2::operator-(const vec2& other) const {
			return vec2(this->x - other.x, this->y - other.y);
		}

		vec2 vec2::operator*(const vec2& other) const {
			return vec2(this->x * other.x, this->y * other.y);
		}

		vec2 vec2::operator/(const vec2& other) const {
			return vec2(x / other.x, y / other.y);
		}

		vec2& vec2::operator+=(const vec2& other) {
			return add(other);
		}

		vec2& vec2::operator-=(const vec2& other) {
			return subtract(other);
		}
		
		vec2& vec2::operator*=(const vec2& other) {
			return multiply(other);
		}

		vec2& vec2::operator/=(const vec2& other) {
			return divide(other);
		}

		bool vec2::operator==(const vec2& other) const{
			return ((x == other.x) && (y == other.y));
		}

		bool vec2::operator!=(const vec2& other) const {
			return !(*this == other);
		}

		vec2 vec2::operator*(float scalar) const {
			return vec2(x * scalar, y * scalar);
		}

		vec2& vec2::operator*=(float scalar) {
			x *= scalar;
			y *= scalar;
			return *this;
		}

		vec2 vec2::operator/(float scalar) const {
			return vec2(x / scalar, y / scalar);
		}

		vec2& vec2::operator/=(float scalar) {
			x /= scalar;
			y /= scalar;
			return *this;
		}

		float vec2::length() const {
			return std::sqrt(x * x + y * y);
		}

		float vec2::lengthSquared() const {
			return (x * x + y * y);
		}

		float vec2::angle() const {
			return std::atan2(y, x);
		}

		vec2& vec2::rotate(float radians) {
			float cosA = std::cos(radians);
			float sinA = std::sin(radians);
			float newX = x * cosA - y * sinA;
			float newY = x * sinA + y * cosA;
			x = newX;
			y = newY;
			return *this;
		}

		vec2 vec2::rotated(float radians) const {
			float cosA = std::cos(radians);
			float sinA = std::sin(radians);
			return vec2(
				x * cosA - y * sinA,
				x * sinA + y * cosA
			);
		}


		vec2& vec2::normalize() {
			float len = length();
			if (len != 0.0f) {
				x /= len;
				y /= len;
			}
			return *this;
		}

		vec2 vec2::normalized() const {
			float len = length();
			if (len != 0.0f)
				return vec2(x / len, y / len);
			return vec2(0.0f, 0.0f);
		}

		float vec2::dot(const vec2& other) const {
			return x * other.x + y * other.y;
		}

		float vec2::distance(const vec2& a, const vec2& b) {
			return (b - a).length();
		}

		float vec2::distanceSquared(const vec2& a, const vec2& b) {
			return (b - a).lengthSquared();
		}
	}
}