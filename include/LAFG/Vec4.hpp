#ifndef VEC4_H
#define VEC4_H

#include <cmath>


namespace LAFG {

	/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	// class body
	template<typename T>
	class Vec4Template {
	public:
		// constructors
		Vec4Template();
		Vec4Template(T x, T y, T z, T w);
		Vec4Template(T init);
		Vec4Template(const Vec4Template& init);

		T& operator[](int i);
		const T& operator[](int i) const;
		const Vec4Template& operator+() const;
		Vec4Template operator-() const;
		Vec4Template& operator=(const Vec4Template& right);
		Vec4Template& operator=(T right);
		Vec4Template& operator+=(const Vec4Template& right);
		Vec4Template& operator+=(T right);
		Vec4Template& operator-=(const Vec4Template& right);
		Vec4Template& operator-=(T right);
		Vec4Template& operator*=(const Vec4Template& right);
		Vec4Template& operator*=(T right);
		Vec4Template& operator/=(const Vec4Template& right);
		Vec4Template& operator/=(T right);

		/*------------------------------------------------------------------------*/
		// data			
		T x, y, z, w;
		
	};

	/*------------------------------------------------------------------------*/
	// constructors
	template<typename T>
	inline Vec4Template<T>::Vec4Template()
		: x(0.0), y(0.0), z(0.0), w(0.0) {}
	
	template<typename T>
	inline Vec4Template<T>::Vec4Template(T x, T y, T z, T w)
		: x(x), y(y), z(z), w(w) {}
	
	template<typename T>
	inline Vec4Template<T>::Vec4Template(T init)
		: x(init), y(init), z(init), w(init) {}

	template<typename T>
	inline Vec4Template<T>::Vec4Template(const Vec4Template& init)
		: x(init.x), y(init.y), z(init.z), w(init.w) {}


	/*------------------------------------------------------------------------*/
	// class member operators
	template<typename T>
	inline T& Vec4Template<T>::operator[](int i) {
		switch (i) {
		case 1:
			return y;
		case 2:
			return z;
		case 3:
			return w;
		default:
			break;
		}
		return x;
	}
	template<typename T>
	inline const T& Vec4Template<T>::operator[](int i) const {
		switch (i) {
		case 1:
			return y;
		case 2:
			return z;
		case 3:
			return w;
		default:
			break;
		}
		return x;
	}

	template<typename T>
	inline const Vec4Template<T>& Vec4Template<T>::operator+() const {
		return *this;
	}

	template<typename T>
	inline Vec4Template<T> Vec4Template<T>::operator-() const {
		return Vec4Template(-x, -y, -z, -w);
	}

	template<typename T>
	inline Vec4Template<T>& Vec4Template<T>::operator=(const Vec4Template& right) {
		x = right.x;
		y = right.y;
		z = right.z;
		w = right.w;
		return *this;
	}

	template<typename T>
	inline Vec4Template<T>& Vec4Template<T>::operator=(T right) {
		x = right;
		y = right;
		z = right;
		w = right;
		return *this;
	}

	template<typename T>
	inline Vec4Template<T>& Vec4Template<T>::operator+=(const Vec4Template& right) {
		x += right.x;
		y += right.y;
		z += right.z;
		w += right.w;
		return *this;
	}

	template<typename T>
	inline Vec4Template<T>& Vec4Template<T>::operator+=(T right) {
		x += right;
		y += right;
		z += right;
		w += right;
		return *this;
	}

	template<typename T>
	inline Vec4Template<T>& Vec4Template<T>::operator-=(const Vec4Template& right) {
		x -= right.x;
		y -= right.y;
		z -= right.z;
		w -= right.w;
		return *this;
	}

	template<typename T>
	inline Vec4Template<T>& Vec4Template<T>::operator-=(T right) {
		x -= right;
		y -= right;
		z -= right;
		w -= right;
		return *this;
	}

	template<typename T>
	inline Vec4Template<T>& Vec4Template<T>::operator*=(const Vec4Template& right) {
		x *= right.x;
		y *= right.y;
		z *= right.z;
		w *= right.w;
		return *this;
	}

	template<typename T>
	inline Vec4Template<T>& Vec4Template<T>::operator*=(T right) {
		x *= right;
		y *= right;
		z *= right;
		w *= right;
		return *this;
	}

	template<typename T>
	inline Vec4Template<T>& Vec4Template<T>::operator/=(const Vec4Template& right) {
		x /= right.x;
		y /= right.y;
		z /= right.z;
		w /= right.w;
		return *this;
	}

	template<typename T>
	inline Vec4Template<T>& Vec4Template<T>::operator/=(T right) {
		x /= right;
		y /= right;
		z /= right;
		w /= right;
		return *this;
	}

	/*------------------------------------------------------------------------*/
	// global operators
	template<typename T>
	inline Vec4Template<T> operator+(const Vec4Template<T>& left, const Vec4Template<T>& right) {
		return Vec4Template(left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w);
	}

	template<typename T>
	inline Vec4Template<T> operator+(const Vec4Template<T>& left, T right) {
		return Vec4Template(left.x + right, left.y + right, left.z + right, left.w + right);
	}

	template<typename T>
	inline Vec4Template<T> operator+(T left, const Vec4Template<T>& right) {
		return Vec4Template(left + right.x, left + right.y, left + right.z, left + right.w);
	}

	template<typename T>
	inline Vec4Template<T> operator-(const Vec4Template<T>& left, const Vec4Template<T>& right) {
		return Vec4Template(left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w);
	}

	template<typename T>
	inline Vec4Template<T> operator-(const Vec4Template<T>& left, T right) {
		return Vec4Template(left.x - right, left.y - right, left.z - right, left.w - right);
	}

	template<typename T>
	inline Vec4Template<T> operator-(T left, const Vec4Template<T>& right) {
		return Vec4Template(left - right.x, left - right.y, left - right.z, left - right.w);
	}

	template<typename T>
	inline Vec4Template<T> operator*(const Vec4Template<T>& left, const Vec4Template<T>& right) {
		return Vec4Template(left.x * right.x, left.y * right.y, left.z * right.z, left.w * right.w);
	}

	template<typename T>
	inline Vec4Template<T> operator*(const Vec4Template<T>& left, T right) {
		return Vec4Template(left.x * right, left.y * right, left.z * right, left.w * right);
	}

	template<typename T>
	inline Vec4Template<T> operator*(T left, const Vec4Template<T>& right) {
		return Vec4Template(left * right.x, left * right.y, left * right.z, left * right.w);
	}

	template<typename T>
	inline Vec4Template<T> operator/(const Vec4Template<T>& left, const Vec4Template<T>& right) {
		return Vec4Template(left.x / right.x, left.y / right.y, left.z / right.z, left.w / right.w);
	}

	template<typename T>
	inline Vec4Template<T> operator/(const Vec4Template<T>& left, T right) {
		return Vec4Template(left.x + right, left.y + right, left.z + right, left.w + right);
	}

	template<typename T>
	inline Vec4Template<T> operator/(T left, const Vec4Template<T>& right) {
		return Vec4Template(left / right.x, left / right.y, left / right.z, left / right.w);
	}

	template<typename T>
	inline bool operator==(const Vec4Template<T>& left, const Vec4Template<T>& right) {
		return left.x == right.x && left.y == right.y && left.z == right.z && left.w == right.w;
	}

	template<typename T>
	inline bool operator!=(const Vec4Template<T>& left, const Vec4Template<T>& right) {
		return left.x != right.x || left.y != right.y || left.z != right.z || left.w != right.w;
	}

	/*------------------------------------------------------------------------*/
	// functions
	template<typename T>
	inline T dot(const Vec4Template<T>& left, const Vec4Template<T>& right) {
		return left.x * right.x + left.y * right.y + left.z * right.z + left.w * right.w;
	}

	template<typename T>
	inline double length(const Vec4Template<T>& vec) {
		return sqrt(dot(vec, vec));
	}

	template<typename T>
	inline double squaredLength(const Vec4Template<T>& vec) {
		return dot(vec, vec);
	}

	inline float length(const Vec4Template<float>& vec) {
		return sqrtf(dot(vec, vec));
	}

	inline float squaredLength(const Vec4Template<float>& vec) {
		return dot(vec, vec);
	}

	template<typename T>
	inline Vec4Template<T> normalize(const Vec4Template<T>& Vec) {
		if (Vec.x == 0.0f && Vec.y == 0.0f && Vec.z == 0.0f && Vec.w == 0.0f)
			return Vec4Template(0.0f);
		return Vec / length(Vec);
	}

	inline Vec4Template<float> normalize(const Vec4Template<float>& vec) {
		if (vec.x == 0.0f && vec.y == 0.0f && vec.z == 0.0f && vec.w == 0.0f)
			return Vec4Template(0.0f);
		return vec / length(vec);
	}

	template<typename T>
	inline bool parallel(const Vec4Template<T>& left, const Vec4Template<T>& right) {
		return	((left.y == 0.0f && right.y == 0.0f) && (left.z == 0.0f && right.z == 0.0f) && (left.w == 0.0f && right.w == 0.0f)) ||
				((left.x == 0.0f && right.x == 0.0f) && (left.z == 0.0f && right.z == 0.0f) && (left.w == 0.0f && right.w == 0.0f)) ||
				((left.x == 0.0f && right.x == 0.0f) && (left.y == 0.0f && right.y == 0.0f) && (left.w == 0.0f && right.w == 0.0f)) ||
				((left.x == 0.0f && right.x == 0.0f) && (left.y == 0.0f && right.y == 0.0f) && (left.z == 0.0f && right.z == 0.0f)) ||
				((left.x / right.x) == (left.y / right.y) == (left.z / right.z) == (left.w / right.w));
	}

	/*------------------------------------------------------------------------*/

	using BVec4 = Vec4Template<bool>;
	using CVec4 = Vec4Template<char>;
	using IVec4 = Vec4Template<int>;
	using UVec4 = Vec4Template<unsigned>;
	using Vec4 = Vec4Template<float>;
	using DVec4 = Vec4Template<double>;

}

#endif // VEC4_H
