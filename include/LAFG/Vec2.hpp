#ifndef VEC2_HPP
#define VEC2_HPP

#include <cmath>


namespace LAFG {

	/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	// class body
	template<typename T>
	class Vec2Template {
	public:
		Vec2Template();
		Vec2Template(T x, T y);
		Vec2Template(T init);
		Vec2Template(const Vec2Template& init);

		T& operator[](int i);
		const T& operator[](int i) const;
		const Vec2Template& operator+() const;
		Vec2Template operator-() const;
		Vec2Template& operator=(const Vec2Template& right);
		Vec2Template& operator=(T right);
		Vec2Template& operator+=(const Vec2Template& right);
		Vec2Template& operator+=(T right);
		Vec2Template& operator-=(const Vec2Template& right);
		Vec2Template& operator-=(T right);
		Vec2Template& operator*=(const Vec2Template& right);
		Vec2Template& operator*=(T right);
		Vec2Template& operator/=(const Vec2Template& right);
		Vec2Template& operator/=(T right);

		/*------------------------------------------------------------------------*/
		// data
		T x, y;
	
	};

	/*------------------------------------------------------------------------*/
	// constructors
	template<typename T>
	inline Vec2Template<T>::Vec2Template()
		: x(0.0f), y(0.0f) {}

	template<typename T>
	inline Vec2Template<T>::Vec2Template(T x, T y)
		: x(x), y(y) {}
	
	template<typename T>
	inline Vec2Template<T>::Vec2Template(T init)
		: x(init), y(init) {}
	
	template<typename T>
	inline Vec2Template<T>::Vec2Template(const Vec2Template& init)
		: x(init.x), y(init.y) {}

	/*------------------------------------------------------------------------*/
	// class member operators
	template<typename T>
	inline T& Vec2Template<T>::operator[](int i) {
		if (i == 1)
			return y;
		return x;
	}

	template<typename T>
	inline const T& Vec2Template<T>::operator[](int i) const {
		if (i == 1)
			return y;
		return x;
	}
	
	template<typename T>
	inline const Vec2Template<T>& Vec2Template<T>::operator+() const {
		return *this;
	}

	template<typename T>
	inline Vec2Template<T> Vec2Template<T>::operator-() const {
		return Vec2Template(-x, -y);
	}

	template<typename T>
	inline Vec2Template<T>& Vec2Template<T>::operator=(const Vec2Template& right) {
		x = right.x;
		y = right.y;
		return *this;
	}

	template<typename T>
	inline Vec2Template<T>& Vec2Template<T>::operator=(T right) {
		x = right;
		y = right;
		return *this;
	}
		
	template<typename T>
	inline Vec2Template<T>& Vec2Template<T>::operator+=(const Vec2Template& right) {
		x += right.x;
		y += right.y;
		return *this;
	}

	template<typename T>
	inline Vec2Template<T>& Vec2Template<T>::operator+=(T right) {
		x += right;
		y += right;
		return *this;
	}

	template<typename T>
	inline Vec2Template<T>& Vec2Template<T>::operator-=(const Vec2Template<T>& right) {
		x -= right.x;
		y -= right.y;
		return *this;
	}

	template<typename T>
	inline Vec2Template<T>& Vec2Template<T>::operator-=(T right) {
		x -= right;
		y -= right;
		return *this;
	}

	template<typename T>
	Vec2Template<T>& Vec2Template<T>::operator*=(const Vec2Template& right) {
		x *= right.x;
		y *= right.y;
		return *this; 
	}

	template<typename T>
	inline Vec2Template<T>& Vec2Template<T>::operator*=(T right) {
		x *= right;
		y *= right;
		return *this;
	}

	template<typename T>
	inline Vec2Template<T>& Vec2Template<T>::operator/=(const Vec2Template& right) {
		x /= right.x;
		y /= right.x;
		return *this;
	}

	template<typename T>
	inline Vec2Template<T>& Vec2Template<T>::operator/=(T right) {
		x /= right;
		y /= right;
		return *this;
	}

	/*------------------------------------------------------------------------*/
	// global operators
	template<typename T>
	inline Vec2Template<T> operator+(const Vec2Template<T>& left, const Vec2Template<T>& right) {
		return Vec2Template(left.x + right.x, left.y + right.y);
	}

	template<typename T>
	inline Vec2Template<T> operator+(const Vec2Template<T>& left, T right) {
		return Vec2Template(left.x + right, left.y + right);
	}

	template<typename T>
	inline Vec2Template<T> operator+(T left, const Vec2Template<T>& right) {
		return Vec2Template(left + right.x, left + right.y);
	}

	template<typename T>
	inline Vec2Template<T> operator-(const Vec2Template<T>& left, const Vec2Template<T>& right) {
		return Vec2Template(left.x - right.x, left.y - right.y);
	}

	template<typename T>
	inline Vec2Template<T> operator-(const Vec2Template<T>& left, T right) {
		return Vec2Template(left.x - right, left.y - right);
	}

	template<typename T>
	inline Vec2Template<T> operator-(T left, const Vec2Template<T>& right) {
		return Vec2Template(left - right.x, left - right.y);;
	}

	template<typename T>
	inline Vec2Template<T> operator*(const Vec2Template<T>& left, const Vec2Template<T>& right) {
		return Vec2Template(left.x * right.x, left.y * right.y);
	}

	template<typename T>
	inline Vec2Template<T> operator*(const Vec2Template<T>& left, T right) {
		return Vec2Template(left.x * right, left.y * right);
	}

	template<typename T>
	inline Vec2Template<T> operator*(T left, const Vec2Template<T>& right) {
		return Vec2Template(left * right.x, left * right.y);
	}

	template<typename T>
	inline Vec2Template<T> operator/(const Vec2Template<T>& left, const Vec2Template<T>& right) {
		return Vec2Template(left.x / right.x, left.y / right.y);
	}

	template<typename T>
	inline Vec2Template<T> operator/(const Vec2Template<T>& left, T right) {
		return Vec2Template(left.x / right, left.y / right);
	}

	template<typename T>
	inline Vec2Template<T> operator/(T left, const Vec2Template<T>& right) {
		return Vec2Template(left / right.x, left / right.y);
	}

	template<typename T>
	inline bool operator==(const Vec2Template<T>& left, const Vec2Template<T>& right) {
		return left.x == right.x && left.y == right.y;
	}

	/*------------------------------------------------------------------------*/
	// functions
	template<typename T>
	inline double length(const Vec2Template<T>& vec) {
		return sqrt(vec.x * vec.x + vec.y * vec.y);
	}


	inline float length(const Vec2Template<float>& vec) {
		return sqrtf(vec.x * vec.x + vec.y * vec.y);
	}

	template<typename T>
	inline Vec2Template<T> rot(const Vec2Template<T>& vec, double angle) {
		double s = sin(angle);
		double c = cos(angle);
		return Vec2Template(vec.x * c + vec.y * -s, vec.x * s + vec.y * c);
	}

	inline Vec2Template<float> rot(const Vec2Template<float>& vec, float angle) {
		float s = sinf(angle);
		float c = cosf(angle);
		return Vec2Template(vec.x * c + vec.y * -s, vec.x * s + vec.y * c);
	}

	template<typename T>
	inline Vec2Template<T> scale(const Vec2Template<T>& vec, T xScale, T yScale) {
		return Vec2Template(vec.x * xScale, vec.y * yScale);
	}
	
	template<typename T>
	inline Vec2Template<T> transfer(const Vec2Template<T>& vec, const Vec2Template<T>& transfer) {
		return vec + transfer;
	}
	
	template<typename T>
	inline Vec2Template<T> transform(const Vec2Template<T>& vec, double angle, double xScale, double yScale, const Vec2Template<T>& transfer) {
		double s = sin(angle);
		double c = cos(angle);
		double scaledX = vec.x * xScale;
		double scaledY = vec.y * yScale;
		return Vec2Template((scaledX * c + scaledY * -s) + transfer.x, (scaledX * s + scaledY * c) + transfer.y);
	}

	inline Vec2Template<float> transform(const Vec2Template<float>& vec, float angle, float xScale, float yScale, const Vec2Template<float>& transfer) {
		float s = sinf(angle);
		float c = cosf(angle);
		float scaledX = vec.x * xScale;
		float scaledY = vec.y * yScale;
		return Vec2Template((scaledX * c + scaledY * -s) + transfer.x, (scaledX * s + scaledY * c) + transfer.y);
	}

	template<typename T>
	inline Vec2Template<T> perp(const Vec2Template<T>& vec) {
		return Vec2Template(-vec.y, vec.x);
	}

	template<typename T>
	inline T dot(const Vec2Template<T>& left, const Vec2Template<T>& right) {
		return left.x * right.x + left.y * right.y;
	}

	template<typename T>
	inline T perpDot(const Vec2Template<T>& left, const Vec2Template<T>& right) {
		return -left.x * right.y + left.y * right.x;
	}
	
	template<typename T>
	inline Vec2Template<T> normalize(const Vec2Template<T>& vec) {
		if (vec.x == 0.0f && vec.y == 0.0f)
			return Vec2Template(0.0f);
		return vec / length(vec);
	}

	template<typename T>
	inline bool parallel(const Vec2Template<T>& left, const Vec2Template<T>& right) {
		if ((left.x == 0.0f && right.x == 0.0f) || (left.y == 0.0f && right.y == 0.0f) || (left.x / right.x == left.y / right.y))
			return true;
		return false;
	}

	/*------------------------------------------------------------------------*/

	using BVec2 = Vec2Template<bool>;
	using IVec2 = Vec2Template<int>;
	using UVec2 = Vec2Template<unsigned>;
	using Vec2 = Vec2Template<float>;
	using DVec2 = Vec2Template<double>;

}

#endif // VEC2_HPP
