#ifndef VEC3_HPP
#define VEC3_HPP

#include "Common.hpp"

#include <cmath>


namespace LAFG {

	/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	// Class body
	
	template<Number T>
	class Vec3Template {
	public:
		/*------------------------------------------------------------------------*/
		// Constructors
		
		Vec3Template() = default;
		
		Vec3Template(T x, T y, T z)
			: x(x), y(y), z(z) {}
		
		Vec3Template(T init)
			: x(x), y(y), z(z) {}
		
		Vec3Template(const Vec3Template& init)
			: x(init.x), y(init.y), z(init.z) {}

		/*------------------------------------------------------------------------*/
		// Conversion operators

		template<Number U>
		operator Vec3Template<U>() const { return Vec3Template<U>(x, y, z); }

		explicit operator bool() const { return x || y || z; }

		/*------------------------------------------------------------------------*/
		// Class-member operators

		T& operator[](size_t i) {
			assert(i >= 0 && i < 3);
			return *(&x + i);
		}

		const T& operator[](size_t i) const {
			assert(i >= 0 && i < 3);
			return *(&x + i);
		}

		const Vec3Template& operator+() const { return *this; }
		
		Vec3Template operator-() const { return Vec3Template(-x, -y, -z); }
		
		template<Number U> Vec3Template& operator=(const Vec3Template<U>& right) {
			x = right.x;
			y = right.y;
			z = right.z;
			return *this;
		}
		
		Vec3Template& operator=(Number auto right) {
			x = right;
			y = right;
			z = right;
			return *this;
		}

		template<Number U> Vec3Template& operator+=(const Vec3Template<U>& right) {
			x += right.x;
			y += right.y;
			z += right.z;
			return *this;
		}
		
		Vec3Template& operator+=(Number auto right) {
			x += right;
			y += right;
			z += right;
			return *this;
		}
		
		template<Number U> Vec3Template& operator-=(const Vec3Template<U>& right) {
			x -= right.x;
			y -= right.y;
			z -= right.z;
			return *this;
		}
		
		Vec3Template& operator-=(Number auto right) {
			x *= right;
			y *= right;
			z *= right;
			return *this;
		}
		
		template<Number U> Vec3Template& operator*=(const Vec3Template<U>& right) {
			x *= right.x;
			y *= right.y;
			z *= right.z;
			return *this;
		}
		
		Vec3Template& operator*=(Number auto right) {
			x *= right;
			y *= right;
			z *= right;
			return *this;
		}
		
		template<Number U> Vec3Template& operator/=(const Vec3Template<U>& right) {
			x /= right.x;
			y /= right.y;
			z /= right.z;
			return *this;
		}
		
		Vec3Template& operator/=(Number auto right) {
			x /= right;
			y /= right;
			z /= right;
			return *this;
		}

		/*------------------------------------------------------------------------*/
		// Data

		T x, y, z;
		
	};

	/*------------------------------------------------------------------------*/
	// Global operators
	
	template<Number T, Number U>
	inline auto operator+(const Vec3Template<T>& left, const Vec3Template<U>& right) {
		return Vec3Template(left.x + right.x, left.y + right.y, left.z + right.z);
	}

	template<Number T>
	inline auto operator+(const Vec3Template<T>& left, Number auto right) {
		return Vec3Template(left.x + right, left.y + right, left.z + right);
	}

	template<Number T>
	inline auto operator+(Number auto left, const Vec3Template<T>& right) {
		return Vec3Template(left + right.x, left + right.y, left + right.x);
	}

	template<Number T, Number U>
	inline auto operator-(const Vec3Template<T>& left, const Vec3Template<U>& right) {
		return Vec3Template(left.x - right.x, left.y - right.y, left.z - right.z);
	}

	template<Number T>
	inline auto operator-(const Vec3Template<T>& left, Number auto right) {
		return Vec3Template(left.x - right, left.y - right, left.z - right);
	}

	template<Number T>
	inline auto operator-(Number auto left, const Vec3Template<T> right) {
		return Vec3Template(left - right, left - right, left - right.z);
	}

	template<Number T, Number U>
	inline auto operator*(const Vec3Template<T>& left, const Vec3Template<U>& right) {
		return Vec3Template(left.x * right.x, left.y * right.y, left.z * right.z);
	}

	template<Number T>
	inline auto operator*(const Vec3Template<T>& left, Number auto right) {
		return Vec3Template(left.x * right, left.y * right, left.z * right);
	}

	template<Number T>
	inline auto operator*(Number auto left, const Vec3Template<T>& right) {
		return Vec3Template(left * right.x, left * right.y, left * right.z);
	}

	template<Number T, Number U>
	inline auto operator/(const Vec3Template<T>& left, const Vec3Template<U>& right) {
		return Vec3Template(left.x / right.x, left.y / right.y, left.z / right.z);
	}

	template<Number T>
	inline auto operator/(const Vec3Template<T>& left, Number auto right) {
		return Vec3Template(left.x / right, left.y / right, left.z / right);
	}

	template<Number T>
	inline auto operator/(Number auto left, const Vec3Template<T>& right) {
		return Vec3Template(left / right.x, left / right.y, left / right.z);
	}

	template<Number T, Number U>
	inline bool operator==(const Vec3Template<T>& left, const Vec3Template<U>& right) {
		return left.x == right.x && left.y == right.y && left.z == right.z;
	}
	
	template<Number T, Number U>
	inline bool operator!=(const Vec3Template<T>& left, const Vec3Template<U>& right) {
		return left.x != right.x || left.y != right.y || left.z != right.z;
	}

	/*------------------------------------------------------------------------*/
	// Functions
	
	template<Number T, Number U>
	inline auto dot(const Vec3Template<T>& left, const Vec3Template<U>& right) {
		return left.x * right.x + left.y * right.y + left.z * right.z;
	}

	template<Number T>
	inline double length(const Vec3Template<T>& vec) {
		return sqrt(dot(vec, vec));
	}

	template<Number T>
	inline float lengthf(const Vec3Template<T>& vec) {
		return sqrtf(dot(vec, vec));
	}

	template<Number T>
	inline T squaredLength(const Vec3Template<T>& vec) {
		return dot(vec, vec);
	}

	template<Number T>
	inline Vec3Template<double> normalize(const Vec3Template<T>& vec) {
		return !vec.x && !vec.y && !vec.z ?
			Vec3Template<double>() : vec / length(vec);
	}

	template<Number T>
	inline Vec3Template<float> normalizef(const Vec3Template<T>& vec) {
		return !vec.x && !vec.y && !vec.z ?
			Vec3Template<float>() : vec / lengthf(vec);
	}

	template<Number T, Number U>
	inline bool parallel(const Vec3Template<T>& left, const Vec3Template<U>& right) {
		return
			((!left.y && !right.y) && (!left.z && !right.z)) ||
			((!left.x && !right.x) && (!left.z && !right.z)) ||
			((!left.x && !right.x) && (!left.y && !right.y)) ||
			((left.x * right.y == left.y * right.x) &&
			 (left.x * right.z == left.z * right.x) &&
			 (left.y * right.z == left.z * right.y));
	}

	template<Number T, Number U>
	inline auto cross(const Vec3Template<T>& left, const Vec3Template<U>& right) {
		return Vec3Template(
			left.y * right.z - left.z * right.y,
			left.x * right.z - left.z * right.x,
			left.x * right.y - left.y * right.x);
	}
	
	/*------------------------------------------------------------------------*/

	using Vec3 = Vec3Template<float>;
	using DVec3 = Vec3Template<double>;
	using CVec3 = Vec3Template<char>;
	using IVec3 = Vec3Template<int>;
	using UVec3 = Vec3Template<unsigned>;

}

#endif // VEC3_HPP
