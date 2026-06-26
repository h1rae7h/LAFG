#ifndef VEC2_HPP
#define VEC2_HPP

#include "Common.hpp"

#include <cmath>


namespace LAFG {

	/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	// Class body

	template<Number T>
	class Vec2Template {
	public:
		/*------------------------------------------------------------------------*/
		// Constructors

		Vec2Template() = default;

		Vec2Template(T x, T y)
			: x{x}, y{y} {}
		
		Vec2Template(T init)
			: x{init}, y{init} {}
		
		Vec2Template(const Vec2Template& init)
			: x{init.x}, y{init.y} {}

		/*------------------------------------------------------------------------*/
		// Conversion operators

		// Convert to another subtype Vec2
		template<Number U>
		operator Vec2Template<U>() const { return Vec2Template<U>(x, y); }

		// True if at least one of vector components is not 0
		explicit operator bool() const { return x || y; }

		/*------------------------------------------------------------------------*/
		// Class member operators

		T& operator[](size_t i) {
			assert(i >= 0 && i < 2);
			return *(&x + i);
		}

		const T& operator[](size_t i) const {
			assert(i >= 0 && i < 2);
			return *(&x + i);
		}

		const Vec2Template& operator+() const { return *this; }
		Vec2Template operator-() const { return Vec2Template(-x, -y); }
		Vec2Template& operator=(const Vec2Template& right) {
			x = right.x;
			y = right.y;
			return *this;
		}

		template<Number U> Vec2Template& operator+=(const Vec2Template<U>& right) {
			x += right.x;
			y += right.y;
			return *this;
		}

		Vec2Template& operator+=(Number auto right) {
			x += right;
			y += right;
			return *this;
		}

		template<Number U>Vec2Template& operator-=(const Vec2Template<U>& right) {
			x -= right.x;
			y -= right.y;
			return *this;
		}

		Vec2Template& operator-=(Number auto right) {
			x -= right;
			y -= right;
			return *this;
		}

		template<Number U> Vec2Template& operator*=(const Vec2Template<U>& right) {
			x *= right.x;
			y *= right.y;
			return *this;
		}

		Vec2Template& operator*=(Number auto right) {
			x *= right;
			y *= right;
			return *this;
		}

		template<Number U> Vec2Template& operator/=(const Vec2Template<U>& right) {
			x /= right.x;
			y /= right.y;
			return *this;
		}

		Vec2Template& operator/=(Number auto right) {
			x /= right;
			y /= right;
			return *this;
		}

		/*------------------------------------------------------------------------*/
		// Data

		T x, y;
	
	};

	/*------------------------------------------------------------------------*/
	// Global operators
	
	// Two vectors per-component sum
	template<Number T, Number U>
	inline auto operator+(const Vec2Template<T>& left, const Vec2Template<U>& right) {
		return Vec2Template(left.x + right.x, left.y + right.y);
	}

	// Vector of every left vector component sum with right number
	template<Number T>
	inline auto operator+(const Vec2Template<T>& left, Number auto right) {
		return Vec2Template(left.x + right, left.y + right);
	}

	template<Number T>
	inline auto operator+(Number auto left, const Vec2Template<T>& right) {
		return Vec2Template(left.x + right, left.y + right);
	}

	// sub
	template<Number T, Number U>
	inline auto operator-(const Vec2Template<T>& left, const Vec2Template<U>& right) {
		return Vec2Template(left.x - right.x, left.y - right.y);
	}

	template<Number T>
	inline auto operator-(const Vec2Template<T>& left, Number auto right) {
		return Vec2Template(left.x - right, left.y - right);
	}

	template<Number T>
	inline auto operator-(Number auto left, const Vec2Template<T>& right) {
		return Vec2Template(left - right.x, left - right.y);
	}

	// mul
	template<Number T, Number U>
	inline auto operator*(const Vec2Template<T>& left, const Vec2Template<U>& right) {
		return Vec2Template(left.x * right.x, left.y * right.y);
	}

	template<Number T>
	inline auto operator*(const Vec2Template<T>& left, Number auto right) {
		return Vec2Template(left.x * right, left.y * right);
	}

	template<Number T>
	inline auto operator*(Number auto left, const Vec2Template<T>& right) {
		return Vec2Template(left * right.x, left * right.y);
	}

	// Two vectors per-component division
	template<Number T, Number U>
	inline auto operator/(const Vec2Template<T>& left, const Vec2Template<U>& right) {
		return Vec2Template(left.x / right.x, left.y / right.y);
	}

	// Vector of every left vector component divided by right number
	template<Number T>
	inline auto operator/(const Vec2Template<T>& left, Number auto right) {
		return Vec2Template(left.x / right, left.y / right);
	}

	// Vector of left number divided by every right vector component
	template<Number T>
	inline auto operator/(Number auto left, const Vec2Template<T>& right) {
		return Vec2Template(left / right.x, left / right.y);
	}

	// Two vectors equality
	template<Number T, Number U>
	inline bool operator==(const Vec2Template<T>& left, const Vec2Template<U>& right) {
		return left.x == right.x && left.y == right.y;
	}

	// Two vectors inequality
	template<Number T, Number U>
	inline bool operator!=(const Vec2Template<T>& left, const Vec2Template<U>& right) {
		return left.x != right.x || left.y != right.y;
	}

	/*------------------------------------------------------------------------*/
	// Functions
	
	// Dot product
	template<Number T, Number U>
	inline auto dot(const Vec2Template<T>& left, const Vec2Template<U>& right) {
		return left.x * right.x + left.y * right.y;
	}

	// Dot product of left vector and vector of right scalar
	template<Number T>
	inline auto dot(const Vec2Template<T>& left, Number auto right) {
		return left.x * right + left.y * right;
	}

	// Dot product of vector of left scalar and right vector
	template<Number T>
	inline auto dot(Number auto left, const Vec2Template<T>& right) {
		return left * right.x + left * right.y;
	}

	// Dot product of first vector and right perpendicular vector to second vector
	template<Number T, Number U>
	inline auto perpDot(const Vec2Template<T>& left, const Vec2Template<U>& right) {
		return -left.x * right.y + left.y * right.x;
	}

	// Single precision vector length
	template<Number T>
	inline double length(const Vec2Template<T>& vec) {
		return sqrt(vec.x * vec.x + vec.y * vec.y);
	}

	// Double precision vector length
	template<Number T>
	inline float lengthf(const Vec2Template<T>& vec) {
		return sqrtf(vec.x * vec.x + vec.y * vec.y);
	}

	// Vector squared length
	template<Number T>
	inline T squaredLength(const Vec2Template<T>& vec) {
		return dot(vec, vec);
	}

	// Rotate this vector by angle, double precision
	template<Number T>
	inline Vec2Template<double> rot(const Vec2Template<T>& vec, double angle) {
		double s = sin(angle);
		double c = cos(angle);
		return Vec2Template(vec.x * c + vec.y * -s, vec.x * s + vec.y * c);
	}

	// Rotate this vector by angle, single precision
	template<Number T>
	inline Vec2Template<float> rotf(const Vec2Template<T>& vec, float angle) {
		float s = sinf(angle);
		float c = cosf(angle);
		return Vec2Template(vec.x * c + vec.y * -s, vec.x * s + vec.y * c);
	}


	template<Number T>
	inline Vec2Template<T> scale(const Vec2Template<T>& vec, T xScale, T yScale) {
		return Vec2Template(vec.x * xScale, vec.y * yScale);
	}
	
	template<Number T, Number U>
	inline auto transfer(const Vec2Template<T>& vec, const Vec2Template<U>& transfer) {
		return vec + transfer;
	}
	
	template<Number T>
	inline Vec2Template<double> transform(const Vec2Template<T>& vec, double angle, double xScale, double yScale, const Vec2Template<T>& transfer) {
		double s = sin(angle);
		double c = cos(angle);
		double scaledX = vec.x * xScale;
		double scaledY = vec.y * yScale;
		return Vec2Template<double>((scaledX * c + scaledY * -s) + transfer.x, (scaledX * s + scaledY * c) + transfer.y);
	}

	template<Number T>
	inline Vec2Template<float> transformf(const Vec2Template<T>& vec, float angle, float xScale, float yScale, const Vec2Template<T>& transfer) {
		float s = sinf(angle);
		float c = cosf(angle);
		float scaledX = vec.x * xScale;
		float scaledY = vec.y * yScale;
		return Vec2Template<float>((scaledX * c + scaledY * -s) + transfer.x, (scaledX * s + scaledY * c) + transfer.y);
	}

	// Right perpendicular vector to this vector
	template<Number T>
	inline Vec2Template<T> perp(const Vec2Template<T>& vec) {
		return Vec2Template<T>(-vec.y, vec.x);
	}
	
	// Returns normalized vector, double precision
	template<Number T>
	inline Vec2Template<double> normalize(const Vec2Template<T>& vec) {
		return !vec.x && !vec.y ? Vec2Template<double>() : vec / lengthd(vec);
	}

	// Returns normalized vector, single precision
	template<Number T>
	inline Vec2Template<float> normalizef(const Vec2Template<T>& vec) {
		return !vec.x && !vec.y ? Vec2Template<float>() : vec / length(vec);
	}

	// Returns true if two vectors are parallel
	template<Number T, Number U>
	inline bool parallel(const Vec2Template<T>& left, const Vec2Template<U>& right) {
		return
			(!left.x && !right.x) ||
			(!left.y && !right.y) ||
			(left.x * right.y == left.y * right.x);
	}

	/*------------------------------------------------------------------------*/

	using Vec2 = Vec2Template<float>;
	using DVec2 = Vec2Template<double>;
	using CVec2 = Vec2Template<char>;
	using IVec2 = Vec2Template<int>;
	using UVec2 = Vec2Template<unsigned>;

}

#endif // VEC2_HPP
