#ifndef VEC3_H
#define VEC3_H

#include <cmath>


namespace LAFG {

	/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	// class body
	template<typename T>
	class Vec3Template {
	public:
		Vec3Template();
		Vec3Template(T x, T y, T z);
		Vec3Template(T init);
		Vec3Template(const Vec3Template& init);

		T& operator[](int i);
		const T& operator[](int i) const;
		const Vec3Template& operator+() const;
		Vec3Template operator-() const;
		Vec3Template& operator=(const Vec3Template& right);
		Vec3Template& operator=(T right);
		Vec3Template& operator+=(const Vec3Template& right);
		Vec3Template& operator+=(T right);
		Vec3Template& operator-=(const Vec3Template& right);
		Vec3Template& operator-=(T right);
		Vec3Template& operator*=(const Vec3Template& right);
		Vec3Template& operator*=(T right);
		Vec3Template& operator/=(const Vec3Template& right);
		Vec3Template& operator/=(T right);

		/*------------------------------------------------------------------------*/
		// data
		T x, y, z;
		
	};

	/*------------------------------------------------------------------------*/
	// constructors
	template<typename T>
	inline Vec3Template<T>::Vec3Template()
		: x(0.0f), y(0.0f), z(0.0f) {}

	template<typename T>
	inline Vec3Template<T>::Vec3Template(T x, T y, T z)
		: x(x), y(y), z(z)  {}

	template<typename T>
	inline Vec3Template<T>::Vec3Template(T init)
		: x(init), y(init), z(init) {}

	template<typename T>
	inline Vec3Template<T>::Vec3Template(const Vec3Template& init)
		: x(init.x), y(init.y), z(init.z) {}

	/*------------------------------------------------------------------------*/
	// class member operators
	template<typename T>
	inline T& Vec3Template<T>::operator[](int i) {
		switch (i) {
		case 1:
			return y;
		case 2:
			return z;
		default:
			break;
		}
		return x;
	}

	template<typename T>
	inline const T& Vec3Template<T>::operator[](int i) const {
		switch (i) {
		case 1:
			return y;
		case 2:
			return z;
		default:
			break;
		}
		return x;
	}

	template<typename T>
	inline const Vec3Template<T>& Vec3Template<T>::operator+() const {
		return *this;
	}

	template<typename T>
	inline Vec3Template<T> Vec3Template<T>::operator-() const {
		return Vec3Template(-x, -y, -z);
	}

	template<typename T>
	inline Vec3Template<T>& Vec3Template<T>::operator=(const Vec3Template<T>& right) {
		x = right.x;
		y = right.y;
		z = right.z;
		return *this;
	}

	template<typename T>
	inline Vec3Template<T>& Vec3Template<T>::operator=(T right) {
		x = right;
		y = right;
		z = right;
		return *this;
	}

	template<typename T>
	inline Vec3Template<T>& Vec3Template<T>::operator+=(const Vec3Template& right) {
		x += right.x;
		y += right.y;
		z += right.z;
		return *this;
	}

	template<typename T>
	inline Vec3Template<T>& Vec3Template<T>::operator+=(T right) {
		x += right;
		y += right;
		z += right;
		return *this;
	}

	template<typename T>
	inline Vec3Template<T>& Vec3Template<T>::operator-=(const Vec3Template& right) {
		x -= right.x;
		y -= right.y;
		z -= right.z;
		return *this;
	}

	template<typename T>
	inline Vec3Template<T>& Vec3Template<T>::operator-=(T right) {
		x -= right;
		y -= right;
		z -= right;
		return *this;
	}

	template<typename T>
	inline Vec3Template<T>& Vec3Template<T>::operator*=(const Vec3Template& right) {
		x *= right.x;
		y *= right.y;
		z *= right.z;
		return *this;
	}

	template<typename T>
	inline Vec3Template<T>& Vec3Template<T>::operator*=(T right) {
		x *= right;
		y *= right;
		z *= right;
		return *this;
	}

	template<typename T>
	inline Vec3Template<T>& Vec3Template<T>::operator/=(const Vec3Template& right) {
		x /= right.x;
		y /= right.y;
		z /= right.z;
		return *this;
	}

	template<typename T>
	inline Vec3Template<T>& Vec3Template<T>::operator/=(T val) {
		x /= val;
		y /= val;
		z /= val;
		return *this;
	}

	/*------------------------------------------------------------------------*/
	// global operators
	template<typename T>
	inline Vec3Template<T> operator+(const Vec3Template<T>& left, const Vec3Template<T>& right) {
		return Vec3Template(left.x + right.x, left.y + right.y, left.z + right.z);
	}

	template<typename T>
	inline Vec3Template<T> operator+(const Vec3Template<T>& left, T right) {
		return Vec3Template(left.x + right, left.y + right, left.z + right);
	}

	template<typename T>
	inline Vec3Template<T> operator+(T left, const Vec3Template<T>& right) {
		return Vec3Template(left + right.x, left + right.y, left + right.x);
	}

	template<typename T>
	inline Vec3Template<T> operator-(const Vec3Template<T>& left, const Vec3Template<T>& right) {
		return Vec3Template(left.x - right.x, left.y - right.y, left.z - right.z);
	}

	template<typename T>
	inline Vec3Template<T> operator-(const Vec3Template<T>& left, T right) {
		return Vec3Template(left.x - right, left.y - right, left.z - right);
	}

	template<typename T>
	inline Vec3Template<T> operator-(T left, const Vec3Template<T> right) {
		return Vec3Template(left - right, left - right, left - right.z);
	}

	template<typename T>
	inline Vec3Template<T> operator*(const Vec3Template<T>& left, const Vec3Template<T>& right) {
		return Vec3Template(left.x * right.x, left.y * right.y, left.z * right.z);
	}

	template<typename T>
	inline Vec3Template<T> operator*(const Vec3Template<T>& left, T right) {
		return Vec3Template(left.x * right, left.y * right, left.z * right);
	}

	template<typename T>
	inline Vec3Template<T> operator*(T left, const Vec3Template<T>& right) {
		return Vec3Template(left * right.x, left * right.y, left * right.z);
	}

	template<typename T>
	inline Vec3Template<T> operator/(const Vec3Template<T>& left, const Vec3Template<T>& right) {
		return Vec3Template(left.x / right.x, left.y / right.y, left.z / right.z);
	}

	template<typename T>
	inline Vec3Template<T> operator/(const Vec3Template<T>& left, T right) {
		return Vec3Template(left.x / right, left.y / right, left.z / right);
	}

	template<typename T>
	inline Vec3Template<T> operator/(T left, const Vec3Template<T>& right) {
		return Vec3Template(left / right.x, left / right.y, left / right.z);
	}

	template<typename T>
	inline bool operator==(const Vec3Template<T>& left, const Vec3Template<T>& right) {
		return left.x == right.x && left.y == right.y && left.z == right.z;
	}

	/*------------------------------------------------------------------------*/
	// functions
	template<typename T>
	inline T dot(const Vec3Template<T>& left, const Vec3Template<T>& right) {
		return left.x * right.x + left.y * right.y + left.z * right.z;
	}

	template<typename T>
	inline double length(const Vec3Template<T>& vec) {
		return sqrt(dot(vec, vec));
	}

	template<typename T>
	inline double squaredLength(const Vec3Template<T>& vec) {
		return dot(vec, vec);
	}

	inline float length(const Vec3Template<float>& vec) {
		return sqrtf(dot(vec, vec));
	}

	inline float squaredLength(const Vec3Template<float>& vec) {
		return dot(vec, vec);
	}

	template<typename T>
	inline Vec3Template<T> normalize(const Vec3Template<T>& vec) {
		if (vec.x == 0. && vec.y == 0. && vec.z == 0.)
			return Vec3Template(0.);
		return vec / length(vec);
	}

	inline Vec3Template<float> normalize(const Vec3Template<float>& vec) {
		if (vec.x == 0.f && vec.y == 0.f && vec.z == 0.f)
			return Vec3Template(0.f);
		return vec / length(vec);
	}

	template<typename T>
	inline bool parallel(const Vec3Template<T>& left, const Vec3Template<T>& right) {
		return	((left.y == 0.0f && right.y == 0.0f) && (left.z == 0.0f && right.z == 0.0f)) ||
				((left.x == 0.0f && right.x == 0.0f) && (left.z == 0.0f && right.z == 0.0f)) ||
				((left.x == 0.0f && right.x == 0.0f) && (left.y == 0.0f && right.y == 0.0f)) ||
				((left.x / right.x) == (left.y / right.y) == (left.z / right.z));
	}

	template<typename T>
	inline Vec3Template<T> cross(const Vec3Template<T>& left, const Vec3Template<T>& right) {
		return Vec3Template(
			left.y * right.z - left.z * right.y,
			left.x * right.z - left.z * right.x,
			left.x * right.y - left.y * right.x);
	}
	
	/*------------------------------------------------------------------------*/

	using BVec3 = Vec3Template<bool>;
	using CVec3 = Vec3Template<char>;
	using IVec3 = Vec3Template<int>;
	using UVec3 = Vec3Template<unsigned>;
	using Vec3 = Vec3Template<float>;
	using DVec3 = Vec3Template<double>;

}

#endif // VEC3_H
