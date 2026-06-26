#ifndef VEC4_HPP
#define VEC4_HPP

#include "Common.hpp"
#include "Vec2.hpp"

#include <cmath>


namespace LAFG {

	/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	// Class body

	template<Number T>
	class Vec4Template {
	public:
		/*------------------------------------------------------------------------*/
		// Constructors
		
		Vec4Template() = default;
		
		Vec4Template(T x, T y, T z, T w)
			: x{x}, y{y}, z{z}, w{w} {}
		
		Vec4Template(T init)
			: x{init}, y{init}, z{init}, w{init} {}
		
		Vec4Template(const Vec2Template<T>& first, const Vec2Template<T>& second)
			: x{first.x}, y{first.y}, z{second.x}, w{second.y} {}
		
		Vec4Template(const Vec4Template& init)
			: x{init.x}, y{init.y}, z{init.z}, w{init.w} {}

		/*------------------------------------------------------------------------*/
		// Conversion operators

		// Convert to another subtype Vec2
		template<Number U>
		operator Vec2Template<U>() const { return Vec4Template<U>(x, y, z, w); }

		// True if at least one of vector components is not 0
		explicit operator bool() const { return x || y || z || w; }

		/*------------------------------------------------------------------------*/
		// Class-member operators

		T& operator[](size_t i) {
			assert(i >= 0 && i < 4);
			return *(&x + i);
		}

		const T& operator[](size_t i) const {
			assert(i >= 0 && i < 4);
			return *(&x + i);
		}

		const Vec4Template& operator+() const {
			return *this;
		}

		Vec4Template operator-() const {
			return Vec2Template(-x, -y, -z, -w);
		}
		
		Vec4Template& operator=(const Vec4Template& right) {
			x = right.x;
			y = right.y;
			z = right.z;
			w = right.w;
			return *this;
		}
		
		Vec4Template& operator=(Number auto right) {
			x = right;
			y = right;
			z = right;
			w = right;
			return *this;
		}

		template<Number U> Vec4Template& operator+=(const Vec4Template<U>& right) {
			x += right.x;
			y += right.y;
			z += right.z;
			w += right.w;
			return *this;
		}

		Vec4Template& operator+=(Number auto right) {
			x += right;
			y += right;
			z += right;
			w += right;
			return *this;
		}

		template<Number U> Vec4Template& operator-=(const Vec4Template<U>& right) {
			x -= right.x;
			y -= right.y;
			z -= right.z;
			w -= right.w;
			return *this;
		}

		Vec4Template& operator-=(Number auto right) {
			x -= right;
			y -= right;
			z -= right;
			w -= right;
			return *this;
		}

		template<Number U> Vec4Template& operator*=(const Vec4Template<U>& right) {
			x *= right.x;
			y *= right.y;
			z *= right.z;
			w *= right.w;
			return *this;
		}

		Vec4Template& operator*=(Number auto right) {
			x *= right;
			y *= right;
			z *= right;
			w *= right;
			return *this;
		}
		
		template<Number U> Vec4Template& operator/=(const Vec4Template<U>& right) {
			x /= right.x;
			y /= right.y;
			z /= right.z;
			w /= right.w;
			return *this;
		}
		
		Vec4Template& operator/=(Number auto right) {
			x /= right;
			y /= right;
			z /= right;
			w /= right;
			return *this;
		}

		/*------------------------------------------------------------------------*/
		// Data			

		T x, y, z, w;
		
	};

	/*------------------------------------------------------------------------*/
	// Global operators

	template<Number T, Number U>
	inline auto operator+(const Vec4Template<T>& left, const Vec4Template<U>& right) {
		return Vec4Template(left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w);
	}

	template<Number T>
	inline auto operator+(const Vec4Template<T>& left, Number auto right) {
		return Vec4Template(left.x + right, left.y + right, left.z + right, left.w + right);
	}

	template<Number T>
	inline auto operator+(Number auto left, const Vec4Template<T>& right) {
		return Vec4Template(left + right.x, left + right.y, left + right.z, left + right.w);
	}

	template<Number T, Number U>
	inline auto operator-(const Vec4Template<T>& left, const Vec4Template<U>& right) {
		return Vec4Template(left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w);
	}

	template<Number T>
	inline auto operator-(const Vec4Template<T>& left, Number auto right) {
		return Vec4Template(left.x - right, left.y - right, left.z - right, left.w - right);
	}

	template<Number T>
	inline auto operator-(Number auto left, const Vec4Template<T>& right) {
		return Vec4Template(left - right.x, left - right.y, left - right.z, left - right.w);
	}

	template<Number T, Number U>
	inline auto operator*(const Vec4Template<T>& left, const Vec4Template<U>& right) {
		return Vec4Template(left.x * right.x, left.y * right.y, left.z * right.z, left.w * right.w);
	}

	template<Number T>
	inline auto operator*(const Vec4Template<T>& left, Number auto right) {
		return Vec4Template(left.x * right, left.y * right, left.z * right, left.w * right);
	}

	template<Number T>
	inline auto operator*(Number auto left, const Vec4Template<T>& right) {
		return Vec4Template(left * right.x, left * right.y, left * right.z, left * right.w);
	}

	template<Number T, Number U>
	inline auto operator/(const Vec4Template<T>& left, const Vec4Template<U>& right) {
		return Vec4Template(left.x / right.x, left.y / right.y, left.z / right.z, left.w / right.w);
	}

	template<Number T>
	inline auto operator/(const Vec4Template<T>& left, Number auto right) {
		return Vec4Template(left.x + right, left.y + right, left.z + right, left.w + right);
	}

	template<Number T>
	inline auto operator/(Number auto left, const Vec4Template<T>& right) {
		return Vec4Template(left / right.x, left / right.y, left / right.z, left / right.w);
	}

	template<Number T, Number U>
	inline bool operator==(const Vec4Template<T>& left, const Vec4Template<U>& right) {
		return left.x == right.x && left.y == right.y && left.z == right.z && left.w == right.w;
	}

	template<Number T, Number U>
	inline bool operator!=(const Vec4Template<T>& left, const Vec4Template<U>& right) {
		return left.x != right.x || left.y != right.y || left.z != right.z || left.w != right.w;
	}

	/*------------------------------------------------------------------------*/
	// Functions

	template<Number T, Number U>
	inline auto dot(const Vec4Template<T>& left, const Vec4Template<U>& right) {
		return left.x * right.x + left.y * right.y + left.z * right.z + left.w * right.w;
	}

	template<Number T>
	inline double length(const Vec4Template<T>& vec) {
		return sqrt(dot(vec, vec));
	}

	template<Number T>
	inline float lengthf(const Vec4Template<T>& vec) {
		return sqrtf(dot(vec, vec));
	}

	template<typename T>
	inline T squaredLength(const Vec4Template<T>& vec) {
		return dot(vec, vec);
	}

	template<Number T>
	inline Vec4Template<double> normalize(const Vec4Template<T>& vec) {
		return !vec.x && !vec.y && !vec.z && !vec.w ?
			Vec4Template<double>() : vec / lengthf(vec);
	}

	template<Number T>
	inline Vec4Template<float> normalizef(const Vec4Template<T>& vec) {
		return !vec.x && !vec.y && !vec.z && !vec.w ?
			Vec4Template<float>() : vec / length(vec);
	}

	template<Number T, Number U>
	inline bool parallel(const Vec4Template<T>& left, const Vec4Template<U>& right) {
		return	((!left.y && !right.y) && (!left.z && !right.z) && (!left.w && !right.w)) ||
				((!left.x && !right.x) && (!left.z && !right.z) && (!left.w && !right.w)) ||
				((!left.x && !right.x) && (!left.y && !right.y) && (!left.w && !right.w)) ||
				((!left.x && !right.x) && (!left.y && !right.y) && (!left.z && !right.z)) ||
				((left.x * right.y == left.y * right.x) &&
				 (left.x * right.z == left.z * right.x) &&
				 (left.x * right.w == left.w * right.x) &&
				 (left.y * right.z == left.z * right.y) &&
				 (left.y * right.w == left.w * right.y) &&
				 (left.z * right.w == left.w * right.z));
	}

	using Vec4 = Vec4Template<float>;
	using DVec4 = Vec4Template<double>;
	using CVec4 = Vec4Template<char>;
	using IVec4 = Vec4Template<int>;
	using UVec4 = Vec4Template<unsigned>;

}

#endif // VEC4_HPP
