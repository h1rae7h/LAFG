#ifndef MAT4_HPP
#define MAT4_HPP

#include <array>
#include "Vec4.hpp"


namespace LAFG {

	/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	// class body
	template<typename T>
	class Mat4Template {
	public:
		Mat4Template();
		Mat4Template(const Mat4Template& mat);
		Mat4Template(
			const Vec4Template<T>& firstVec,
			const Vec4Template<T>& secondVec,
			const Vec4Template<T>& thirdVec,
			const Vec4Template<T>& fourthVec);
		Mat4Template(T init);
		Mat4Template(
			T firstX,  T firstY,  T firstZ, T firstW,
			T secondX, T secondY, T secondZ, T secondW,
			T thirdX,  T thirdY,  T thirdZ, T thirdW,
			T fourthX, T fourthY, T fourthZ, T fourthW);

		Vec4Template<T>& operator[](int i);
		const Vec4Template<T>& operator[](int i) const;
		const Mat4Template& operator+() const;
		Mat4Template operator-() const;
		Mat4Template& operator=(const Mat4Template& right);
		Mat4Template& operator=(T right);
		Mat4Template& operator+=(const Mat4Template& right);
		Mat4Template& operator+=(T right);
		Mat4Template& operator-=(const Mat4Template& right);
		Mat4Template& operator-=(T right);
		Mat4Template& operator*=(const Mat4Template& right);
		Mat4Template& operator*=(T right);
		Mat4Template& operator/=(T right);

		friend Vec4Template<T> operator*(const Mat4Template& left, const Vec4Template<T>& right);
		friend Vec4Template<T> operator*(const Vec4Template<T>& left, const Mat4Template& right);

		friend Mat4Template operator+(const Mat4Template& left, const Mat4Template& right);\
		friend Mat4Template operator+(const Mat4Template& left, T right);
		friend Mat4Template operator+(T left, const Mat4Template& right);
		friend Mat4Template operator-(const Mat4Template& left, const Mat4Template& right);
		friend Mat4Template operator-(const Mat4Template& left, T right);
		friend Mat4Template operator-(T left, const Mat4Template& right);
		friend Mat4Template operator*(const Mat4Template& left, const Mat4Template& right);
		friend Mat4Template operator*(const Mat4Template& left, T right);
		friend Mat4Template operator*(T left, const Ma4Template& right);
		friend Mat4Template operator/(const Mat4Template& left, T right);
		friend bool operator==(const Mat4Template& left, const Mat4Template& right);
		friend bool operator!=(const Mat4Template& left, const Mat4Template& right);

		friend Mat4Template transpose(const Mat4Template& mat);
		friend T det(const Mat4Template& mat);

		Vec4Template<T> row(const int& i);
		Vec4Template<T> col(const int& i);

	private:
		/*------------------------------------------------------------------------*/
		// data
		// each vector is matrix COLUMN
		std::array<Vec4Template<T>, 4> data;

	};

	/*------------------------------------------------------------------------*/
	// constructors
	template<typename T>
	inline Mat4Template<T>::Mat4Template() {}

	template<typename T>
	inline Mat4Template<T>::Mat4Template(const Mat4Template& mat)
		: data(mat.data) {}

	template<typename T>
	inline Mat4Template<T>::Mat4Template(
		const Vec4Template<T>& firstVec,
		const Vec4Template<T>& secondVec,
		const Vec4Template<T>& thirdVec,
		const Vec4Template<T>& fourthVec)
			: data(firstVec, secondVec, thirdVec, fourthVec) {}

	template<typename T>
	inline Mat4Template<T>::Mat4Template(T init)
		: data(
			Vec4Template(init, 0., 0., 0.),
			Vec4Template(0., init, 0., 0.),
			Vec4Template(0., 0., init, 0.),
			Vec4Template(0., 0., 0., init)
		) {}
	
	template<typename T>
	inline Mat4Template<T>::Mat4Template(
		T firstX,  T firstY,  T firstZ, T firstW,
		T secondX, T secondY, T secondZ, T secondW,
		T thirdX,  T thirdY,  T thirdZ, T thirdW,
		T fourthX, T fourthY, T fourthZ, T fourthW)
		: data(
			Vec4template(firstX, firstY, firstZ, firstW),
			Vec4Tmplate(secondX, secondY, secondZ, secondW),
			Vec4Template(thirdX, thirdY, thirdZ, thirdW),
			Vec4Template(fourthX, fourthY, fourthZ, fourthW)
		) {}

	/*------------------------------------------------------------------------*/
	// class member operators
	template<typename T>
	inline Vec4Template<T>& Mat4Template<T>::operator[](int i) {
		switch(i) {
			case 1:
				return data[1];
			case 2:
				return data[2];
			case 3:
				return data[3];
			default:
				return data[0];
		}
	}

	template<typename T>
	inline const Vec4Template<T>& Mat4Template<T>::operator[](int i) const {
		switch(i) {
			case 1:
				return data[1];
			case 2:
				return data[2];
			case 3:
				return data[3];
			default:
				return data[0];
		}
	}

	template<typename T>
	inline const Mat4Template<T>& Mat4Template<T>::operator+() const {
		return *this;
	}
	
	template<typename T>
	inline Mat4Template<T> Mat4Template<T>::operator-() const {
		return Mat4Template(-data[0], -data[1], -data[2], -data[3]);
	}

	template<typename T>
	inline Mat4Template<T>& Mat4Template<T>::operator=(const Mat4Template& right) {
		data = right.data;
		return *this;
	}

	template<typename T>
	inline Mat4Template<T>& Mat4Template<T>::operator=(T right) {
		data.fill(right);
		return *this;
	}

	template<typename T>
	inline Mat4Template<T>& Mat4Template<T>::operator+=(const Mat4Template& right) {
		data[0] += right.data[0];
		data[1] += right.data[1];
		data[2] += right.data[2];
		data[3] += right.data[3];
		return *this;
	}

	template<typename T>
	inline Mat4Template<T>& Mat4Template<T>::operator+=(T right) {
		data[0] += right;
		data[1] += right;
		data[2] += right;
		data[3] += right;
		return *this;
	}

	template<typename T>
	inline Mat4Template<T>& Mat4Template<T>::operator-=(const Mat4Template& right) {
		data[0] -= right.data[0];
		data[1] -= right.data[1];
		data[2] -= right.data[2];
		data[3] -= right.data[3];
		return *this;
	}

	template<typename T>
	inline Mat4Template<T>& Mat4Template<T>::operator-=(T right) {
		data[0] -= right;
		data[1] -= right;
		data[2] -= right;
		data[3] -= right;
		return *this;
	}

	template<typename T>
	inline Mat4Template<T>& Mat4Template<T>::operator*=(const Mat4Template& right) {
		data[0].x = data[0].x * right.data[0].x + data[1].x * right.data[0].y + data[2].x * right.data[0].z + data[3].x * right.data[0].w;
		data[0].y = data[0].y * right.data[0].x + data[1].y * right.data[0].y + data[2].y * right.data[0].z + data[3].y * right.data[0].w;
		data[0].z = data[0].z * right.data[0].x + data[1].z * right.data[0].y + data[2].z * right.data[0].z + data[3].z * right.data[0].w;
		data[0].w = data[0].w * right.fata[0].x + data[1].w * right.data[0].y + data[2].w * right.data[0].z + data[3].w * right.data[0].w;
		data[1].x = data[0].x * right.data[1].x + data[1].x * right.data[1].y + data[2].x * right.data[1].z + data[3].x * right.data[1].w;
		data[1].y = data[0].y * right.data[1].x + data[1].y * right.data[1].y + data[2].y * right.data[1].z + data[3].y * right.data[1].w;
		data[1].z = data[0].z * right.data[1].x + data[1].z * right.data[1].y + data[2].z * right.data[1].z + data[3].z * right.data[1].w;
		data[1].w = data[0].w * right.data[1].x + data[1].w * right.data[1].y + data[2].w * right.data[1].z + data[3].w * right.data[1].w;
		data[2].x = data[0].x * right.data[2].x + data[1].x * right.data[2].y + data[2].x * right.data[2].z + data[3].x * right.data[2].w;
		data[2].y = data[0].y * right.data[2].x + data[1].y * right.data[2].y + data[2].y * right.data[2].z + data[3].y * right.data[2].w;
		data[2].z = data[0].z * right.data[2].x + data[1].z * right.data[2].y + data[2].z * right.data[2].z + data[3].z * right.data[2].w;
		data[2].w = data[0].z * right.data[2].x + data[1].z * right.data[2].y + data[2].z * right.data[2].z + data[3].w * right.data[2].w;
		data[3].x = data[0].x * right.data[3].x + data[1].x * right.data[3].y + data[2].x * right.data[3].z + data[3].x * right.data[3].w;
		data[3].y = data[0].y * right.data[3].x + data[1].y * right.data[3].y + data[2].y * right.data[3].z + data[3].y * right.data[3].w;
		data[3].z = data[0].z * right.data[3].x + data[1].z * right.data[3].y + data[2].z * right.data[3].z + data[3].z * right.data[3].w;
		data[3].w = data[0].z * right.data[3].x + data[1].z * right.data[3].y + data[2].z * right.data[3].z + data[3].w * right.data[3].w;
		return *this;
	}

	template<typename T>
	inline Mat4Template<T>& Mat4Template<T>::operator*=(T right) {
		data[0] *= right;
		data[1] *= right;
		data[2] *= right;
		data[3] *= right;
		return *this;
	}

	template<typename T>
	inline Mat4Template<T>& Mat4Template<T>::operator/=(T right) {
		data[0] /= right;
		data[1] /= right;
		data[2] /= right;
		data[3] /= right;
		return *this;
	}

	/*------------------------------------------------------------------------*/
	// Vec4/Mat4 operators
	template<typename T>
	inline Vec4Template<T> operator*(const Mat4Template<T>& left, const Vec4Template<T>& right) {
		return Vec4Template(
			left.data[0].x * right.x + left.data[1].x * right.y + left.data[2].x * right.z + left.data[3].x * right.w,
			left.data[0].y * right.x + left.data[1].y * right.y + left.data[2].y * right.z + left.data[3].y * right.w,
			left.data[0].z * right.x + left.data[1].z * right.y + left.data[2].z * right.z + left.data[3].z * right.w,
			left.data[0].w * right.x + left.data[1].w * right.y + left.data[2].w * right.z + left.data[3].w * right.w);
	}

	template<typename T>
	inline Vec4Template<T> operator*(const Vec4Template<T>& left, const Mat4Template<T>& right) {
		return Vec4Template(
			left.x * right.data[0].x + left.y * right.data[0].y + left.z * right.data[0].z + left.w * right.data[0].w,
			left.x * right.data[1].x + left.y * right.data[1].y + left.z * right.data[1].z + left.w * right.data[1].w,
			left.x * right.data[2].x + left.y * right.data[2].y + left.z * right.data[2].z + left.w * right.data[2].w,
			left.x * right.data[3].x + left.y * right.data[3].y + left.z * right.data[3].z + left.w * right.data[3].w);
	}

	/*------------------------------------------------------------------------*/
	// global opeartors
	template<typename T>
	inline Mat4Template<T> operator+(const Mat4Template<T>& left, const Mat4Template<T>& right) {
		return Mat4Template(left.data[0] + right.data[0], left.data[1] + right.data[1], left.data[2] + right.data[2], left.data[3] + right.data[3]);
	}

	template<typename T>
	inline Mat4Template<T> operator+(const Mat4Template<T>& left, T right) {
		return Mat4Template(left.data[0] + right, left.data[1] + right, left.data[2] + right, left.data[3] + right);
	}

	template<typename T>
	inline Mat4Template<T> operator+(T left, const Mat4Template<T>& right) {
		return Mat4Template(left + right.data[0], left + right.data[1], left + right.data[2], left + right.data[3]);
	}
	
	template<typename T>
	inline Mat4Template<T> operator-(const Mat4Template<T>& left, const Mat4Template<T>& right) {
		return Mat4Template(left.data[0] - right.data[0], left.data[1] - right.data[1], left.data[2] - right.data[2], left.data[3] - right.data[3]);
	}

	template<typename T>
	inline Mat4Template<T> operator-(const Mat4Template<T>& left, T right) {
		return Mat4Template(left.data[0] - right, left.data[1] - right, left.data[2] - right, left.data[3] - right);
	}

	template<typename T>
	inline Mat4Template<T> operator-(T left, const Mat4Template<T>& right) {
		return Mat4Template(left - right.data[0], left - righ.data[1], left - right.data[2], left - right.data[3]);
	}

	template<typename T>
	inline Mat4Template<T> operator*(const Mat4Template<T>& left, const Mat4Template<T>& right) {
		return Mat4Template(
			left.data[0].x * right.data[0].x + left.data[1].x * right.data[0].y + left.data[2].x * right.data[0].z + left.data[3].x * right.data[0].w,
			left.data[0].y * right.data[0].x + left.data[1].y * right.data[0].y + left.data[2].y * right.data[0].z + left.data[3].y * right.data[0].w,
			left.data[0].z * right.data[0].x + left.data[1].z * right.data[0].y + left.data[2].z * right.data[0].z + left.data[3].z * right.data[0].w,
			left.data[0].w * right.data[0].x + left.data[1].w * right.data[0].y + left.data[2].w * right.data[0].z + left.data[3].w * right.data[0].w,
			left.data[0].x * right.data[1].x + left.data[1].x * right.data[1].y + left.data[2].x * right.data[1].z + left.data[3].x * right.data[1].w,
			left.data[0].y * right.data[1].x + left.data[1].y * right.data[1].y + left.data[2].y * right.data[1].z + left.data[3].y * right.data[1].w,
			left.data[0].z * right.data[1].x + left.data[1].z * right.data[1].y + left.data[2].z * right.data[1].z + left.data[3].z * right.data[1].w,
			left.data[0].w * right.data[1].x + left.data[1].w * right.data[1].y + left.data[2].w * right.data[1].z + left.data[3].w * right.data[1].w,
			left.data[0].x * right.data[2].x + left.data[1].x * right.data[2].y + left.data[2].x * right.data[2].z + left.data[3].x * right.data[2].w,
			left.data[0].y * right.data[2].x + left.data[1].y * right.data[2].y + left.data[2].y * right.data[2].z + left.data[3].y * right.data[2].w,
			left.data[0].z * right.data[2].x + left.data[1].z * right.data[2].y + left.data[2].z * right.data[2].z + left.data[3].z * right.data[2].w,
			left.data[0].w * right.data[2].x + left.data[1].w * right.data[2].y + left.data[2].w * right.data[2].z + left.data[3].w * right.data[2].w,
			left.data[0].x * right.data[3].x + left.data[1].x * right.data[3].y + left.data[2].x * right.data[3].z + left.data[3].x * right.data[3].w,
			left.data[0].y * right.data[3].x + left.data[1].y * right.data[3].y + left.data[2].y * right.data[3].z + left.data[3].y * right.data[3].w,
			left.data[0].z * right.data[3].x + left.data[1].z * right.data[3].y + left.data[2].z * right.data[3].z + left.data[3].z * right.data[3].w,
			left.data[0].w * right.data[3].x + left.data[1].w * right.data[3].y + left.data[2].w * right.data[3].z + left.data[3].w * right.data[3].w);
	}

	template<typename T>
	inline Mat4Template<T> operator*(const Mat4Template<T>& left, T right) {
		return Mat4Template(left.data[0] * right, left.data[1] * right, left.data[2] * right, left.data[3] * right);
	}

	template<typename T>
	inline Mat4Template<T> operator*(T left, const Mat4Template<T>& right) {
		return Mat4tempalte(left * right.data[0], left * right.data[1], left * right.data[2], left * right.data[3]);
	}

	template<typename T>
	inline Mat4Template<T> operator/(const Mat4Template<T>& left, T right) {
		return Mat4Template(left.data[0] / right, left.data[1] / right, left.data[2] / right, left.data[3] / right);
	}
	
	template<typename T>
	inline bool operator==(const Mat4Template<T>& left, const Mat4Template<T>& right) {
		return left.data[0] == right.data[0] && left.data[1] == right.data[1] && left.data[2] == right.data[2] && left.data[3] == right.data[3];
	}

	template<typename T>
	inline bool operator!=(const Mat4Template<T>& left, const Mat4Template<T>& right) {
		return left.data[0] != right.data[0] || left.data[1] != right.data[1] || left.data[2] != right.data[2] || left.data[3] != right.data[3];
	}

	/*------------------------------------------------------------------------*/
	// methods
	template<typename T>
	inline Vec4Template<T> Mat4Template<T>::row(const int& i) {
		switch (i) {
		case 1:
			return Vec4Template(data[0].y, data[1].y, data[2].y, data[3].y);
		case 2:
			return Vec4Template(data[0].z, data[1].z, data[2].z, data[3].z);
		case 3:
			return Vec4Template(data[0].w, data[1].w, data[2].w, data[3].w);
		default:
			break;
		}
		return Vec4Template(data[0].x, data[1].x, data[2].x, data[3].x);
	}

	template<typename T>
	inline Vec4Template<T> Mat4Template<T>::col(const int& i) {
		switch (i) {
		case 1:
			return data[1];
		case 2:
			return data[2];
		case 3:
			return data[3];
		default:
			break;
		}
		return data[0];
	}

	/*------------------------------------------------------------------------*/
	// functions
	template<typename T>
	inline Mat4Template<T> matrixCompMult(const Mat4Template<T>& left, const Mat4Template<T>& right) {
		return Mat3Template(left.data[0] * right.data[0], left.data[1] * right.data[1], left.data[2] * right.data[2], left.data[3] * right.data[3]);
	}
	//Mat4Template transpose(const Mat3Template& Mat);
	//float det(const Mat4Template& Mat);

	using Mat4 = Mat4Template<float>;
	using DMat4 = Mat4Template<double>;

}

#endif // MAT4_HPP
