#ifndef MAT3_HPP
#define MAT3_HPP

#include <array>
#include "Vec3.hpp"


namespace LAFG {

	/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	// class body
	template<typename T>
	class Mat3Template {
	public:
		Mat3Template();
		Mat3Template(const Mat3Template& mat);
		Mat3Template(
			const Vec3Template<T>& firstVec,
			const Vec3Template<T>& secondVec,
			const Vec3Template<T>& thirdVec);
		Mat3Template(T init);
		Mat3Template(
			T firstX, T firstY, T firstZ,
			T secondX, T secondY, T secondZ,
			T thirdX, T thirdY, T thirdZ);

		Vec3Template<T>& operator[](int i);
		const Vec3Template<T>& operator[](int i) const;
		const Mat3Template& operator+() const;
		Mat3Template operator-() const;
		Mat3Template& operator=(const Mat3Template& right);
		Mat3Template& operator=(T right);
		Mat3Template& operator+=(const Mat3Template& right);
		Mat3Template& operator+=(T right);
		Mat3Template& operator-=(const Mat3Template& right);
		Mat3Template& operator-=(T right);
		Mat3Template& operator*=(const Mat3Template& right);
		Mat3Template& operator*=(T right);
		Mat3Template& operator/=(T right);

		friend Vec3Template<T> operator*(const Mat3Template& left, const Vec3Template<T>& right);
		friend Vec3Template<T> operator*(const Vec3Template<T>& left, const Mat3Template& right);

		friend Mat3Template operator+(const Mat3Template& left, const Mat3Template& right);
		friend Mat3Template operator-(const Mat3Template& left, const Mat3Template& right);
		friend Mat3Template operator*(const Mat3Template& left, const Mat3Template& right);
		friend Mat3Template operator+(const Mat3Template& left, T right);
		friend Mat3Template operator-(const Mat3Template& left, T right);
		friend Mat3Template operator*(const Mat3Template& left, T right);
		friend Mat3Template operator*(T left, const Mat3Template& right);
		friend Mat3Template operator/(const Mat3Template& left, T right);
		friend bool operator==(const Mat3Template& left, const Mat3Template& right);
		friend bool operator!=(const Mat3Template& left, const Mat3Template& right);

		friend Mat3Template transpose(const Mat3Template& mat);
		friend T det(const Mat3Template& mat);

		Vec3Template<T> row(const int& i);
		Vec3Template<T> col(const int& i);

	private:
		/*------------------------------------------------------------------------*/
		// data
		std::array<Vec3Template<T>, 3> data;

	};

	/*------------------------------------------------------------------------*/
	// constructors
	template<typename T>
	inline Mat3Template<T>::Mat3Template() {}

	template<typename T>
	inline Mat3Template<T>::Mat3Template(const Mat3Template& mat) 
		: data(mat.data) {}

	template<typename T>
	inline Mat3Template<T>::Mat3Template(
		const Vec3Template<T>& firstVec,
		const Vec3Template<T>& secondVec,
		const Vec3Template<T>& thirdVec)
		: data{firstVec, secondVec, thirdVec} {}

	template<typename T>
	inline Mat3Template<T>::Mat3Template(T init)
		: data{
			Vec3Template(init, 0., 0.),
			Vec3Template(0., init, 0.),
			Vec3Template(0., 0., init)
		} {}

	template<typename T>
	inline Mat3Template<T>::Mat3Template(
		T firstX, T firstY, T firstZ,
		T secondX, T secondY, T secondZ,
		T thirdX, T thirdY, T thirdZ)
		: data{
			Vec3Template(firstX, firstY, firstZ),
			Vec3Template(secondX, secondY, secondZ),
			Vec3Template(thirdX, thirdY, thirdZ)
		} {}

	/*------------------------------------------------------------------------*/
	// class member operators
	template<typename T>
	inline Vec3Template<T>& Mat3Template<T>::operator[](int i) {
		switch (i) {
		case 1:
			return data[1];
		case 2:
			return data[2];
		default:
			break;
		}
		return data[0];
	}

	template<typename T>
	inline const Vec3Template<T>& Mat3Template<T>::operator[](int i) const {
		switch (i) {
		case 1:
			return data[1];
		case 2:
			return data[2];
		default:
			break;
		}
		return data[0];
	}

	template<typename T>
	inline const Mat3Template<T>& Mat3Template<T>::operator+() const {
		return *this;
	}

	template<typename T>
	inline Mat3Template<T> Mat3Template<T>::operator-() const {
		return Mat3Template(-data[0], -data[1], -data[2]);
	}

	template<typename T>
	inline Mat3Template<T>& Mat3Template<T>::operator=(const Mat3Template& right) {
		data = right.data;
		return *this;
	}

	template<typename T>
	inline Mat3Template<T>& Mat3Template<T>::operator=(T right) {
		data.fill(right);
		return *this;
	}

	template<typename T>
	inline Mat3Template<T>& Mat3Template<T>::operator+=(const Mat3Template& right) {
		data[0] += right.data[0];
		data[1] += right.data[1];
		data[2] += right.data[2];
		return *this;
	}

	template<typename T>
	inline Mat3Template<T>& Mat3Template<T>::operator+=(T right) {
		data[0] += right;
		data[1] += right;
		data[2] += right;
		return *this;
	}

	template<typename T>
	inline Mat3Template<T>& Mat3Template<T>::operator-=(const Mat3Template& right) {
		data[0] -= right.data[0];
		data[1] -= right.data[1];
		data[2] -= right.data[2];
		return *this;
	}

	template<typename T>
	inline Mat3Template<T>& Mat3Template<T>::operator-=(T right) {
		data[0] -= right;
		data[1] -= right;
		data[2] -= right;
		return *this;
	}

	template<typename T>
	Mat3Template<T>& Mat3Template<T>::operator*=(const Mat3Template& right) {
		T tempFirstX = data[0].x * right.data[0].x + data[1].x * right.data[0].y + data[2].x * right.data[0].z;
		T tempFirstY = data[0].y * right.data[0].x + data[1].y * right.data[0].y + data[2].y * right.data[0].z;
		T tempFirstZ = data[0].z * right.data[0].x + data[1].z * right.data[0].y + data[2].z * right.data[0].z;
		T tempSecondX = data[0].x * right.data[1].x + data[1].x * right.data[1].y + data[2].x * right.data[1].z;
		T tempSecondY = data[0].y * right.data[1].x + data[1].y * right.data[1].y + data[2].y * right.data[1].z;
		T tempSecondZ = data[0].z * right.data[1].x + data[1].z * right.data[1].y + data[2].z * right.data[1].z;
		T tempThirdX = data[0].x * right.data[2].x + data[1].x * right.data[2].y + data[2].x * right.data[2].z;
		T tempThirdY = data[0].y * right.data[2].x + data[1].y * right.data[2].y + data[2].y * right.data[2].z;
		T tempThirdZ = data[0].z * right.data[2].x + data[1].z * right.data[2].y + data[2].z * right.data[2].z;
		data[0].x = tempFirstX;
		data[0].y = tempFirstY;
		data[0].z = tempFirstZ;
		data[1].x = tempSecondZ;
		data[1].y = tempSecondZ;
		data[1].z = tempSecondZ;
		data[2].x = tempThirdX;
		data[2].y = tempThirdY;
		data[2].z = tempThirdZ;
		return *this;
	}

	template<typename T>
	inline Mat3Template<T>& Mat3Template<T>::operator*=(T right) {
		data[0] *= right;
		data[1] *= right;
		data[2] *= right;
		return *this;
	}

	template<typename T>
	inline Mat3Template<T>& Mat3Template<T>::operator/=(T right) {
		data[0] /= right;
		data[1] /= right;
		data[2] /= right;
		return *this;
	}

	/*------------------------------------------------------------------------*/
	// Vec3/Mat3Template operators
	template<typename T>
	inline Vec3Template<T> operator*(const Mat3Template<T>& left, const Vec3Template<T>& right) {
		return Vec3Template(
			left.data[0].x * right.x + left.data[1].x * right.y + left.data[2].x * right.z,
			left.data[0].y * right.x + left.data[1].y * right.y + left.data[2].y * right.z,
			left.data[0].z * right.x + left.data[1].z * right.y + left.data[2].z * right.z);
	}

	template<typename T>
	inline Vec3Template<T> operator*(const Vec3Template<T>& left, const Mat3Template<T>& right) {
		return Vec3Template(
			left.x * right.data[0].x + left.y * right.data[0].y + left.z * right.data[0].z,
			left.x * right.data[1].x + left.y * right.data[1].y + left.z * right.data[1].z,
			left.x * right.data[2].x + left.y * right.data[2].y + left.z * right.data[2].z);
	}

	/*------------------------------------------------------------------------*/
	// global opeartors
	template<typename T>
	inline Mat3Template<T> operator+(const Mat3Template<T>& left, const Mat3Template<T>& right) {
		return Mat3Template(left.data[0] + right.data[0], left.data[1] + right.data[1], left.data[2] + right.data[2]);
	}
	
	template<typename T>
	inline Mat3Template<T> operator-(const Mat3Template<T>& left, const Mat3Template<T>& right) {
		return Mat3Template(left.data[0] - right.data[0], left.data[1] - right.data[1], left.data[2] - right.data[2]);
	}

	template<typename T>
	inline Mat3Template<T> operator*(const Mat3Template<T>& left, const Mat3Template<T>& right) {
		return Mat3Template(
		left.data[0].x * right.data[0].x + left.data[1].x * right.data[0].y + left.data[2].x * right.data[0].z,
		left.data[0].y * right.data[0].x + left.data[1].y * right.data[0].y + left.data[2].y * right.data[0].z,
		left.data[0].z * right.data[0].x + left.data[1].z * right.data[0].y + left.data[2].z * right.data[0].z,
		left.data[0].x * right.data[1].x + left.data[1].x * right.data[1].y + left.data[2].x * right.data[1].z,
		left.data[0].y * right.data[1].x + left.data[1].y * right.data[1].y + left.data[2].y * right.data[1].z,
		left.data[0].z * right.data[1].x + left.data[1].z * right.data[1].y + left.data[2].z * right.data[1].z,
		left.data[0].x * right.data[2].x + left.data[1].x * right.data[2].y + left.data[2].x * right.data[2].z,
		left.data[0].y * right.data[2].x + left.data[1].y * right.data[2].y + left.data[2].y * right.data[2].z,
		left.data[0].z * right.data[2].x + left.data[1].z * right.data[2].y + left.data[2].z * right.data[2].z);
	}

	template<typename T>
	inline Mat3Template<T> operator+(const Mat3Template<T>& left, T right) {
		return Mat3Template(left.data[0] + right, left.data[1] + right, left.data[2] + right);
	}

	template<typename T>
	inline Mat3Template<T> operator-(const Mat3Template<T>& left, T right) {
		return Mat3Template(left.data[0] - right, left.data[1] - right, left.data[2] - right);
	}

	template<typename T>
	inline Mat3Template<T> operator*(const Mat3Template<T>& left, T right) {
		return Mat3Template(left.data[0] * right, left.data[1] * right, left.data[2] * right);
	}

	template<typename T>
	inline Mat3Template<T> operator*(T left, const Mat3Template<T>& right) {
		return mat3tempalte(left * right.data[0], left * right.data[1], left * right.data[2]);
	}

	template<typename T>
	inline Mat3Template<T> operator/(const Mat3Template<T>& left, T right) {
		return Mat3Template(left.data[0] / right, left.data[1] / right, left.data[2] / right);
	}
	
	template<typename T>
	inline bool operator==(const Mat3Template<T>& left, const Mat3Template<T>& right) {
		return left.data[0] == right.data[0] && left.data[1] == right.data[1] && left.data[2] == right.data[2];
	}

	template<typename T>
	inline bool operator!=(const Mat3Template<T>& left, const Mat3Template<T>& right) {
		return left.data[0] != right.data[0] || left.data[1] != right.data[1] || left.data[2] != right.data[2];
	}

	/*------------------------------------------------------------------------*/
	// methods
	template<typename T>
	inline Vec3Template<T> Mat3Template<T>::row(const int& i) {
		switch (i) {
		case 1:
			return Vec3Template(data[0].y, data[1].y, data[2].y);
		case 2:
			return Vec3Template(data[0].z, data[1].z, data[2].z);
		default:
			break;
		}
		return Vec3Template(data[0].x, data[1].x, data[2].x);;
	}

	template<typename T>
	inline Vec3Template<T> Mat3Template<T>::col(const int& i) {
		switch (i) {
		case 1:
			return data[1];
		case 2:
			return data[2];
		default:
			break;
		}
		return data[0];
	}

	/*------------------------------------------------------------------------*/
	// functions
	template<typename T>
	inline Mat3Template<T> matrixCompMult(const Mat3Template<T>& left, const Mat3Template<T>& right) {
		return Mat3Template(left.data[0] * right.data[0], left.data[1] * right.data[1], left.data[2] * right.data[2]);
	}
	//Mat3Template transpose(const Mat3Template& Mat);
	template<typename T>
	inline T det(const Mat3Template<T> &mat) {
		return mat[0][0] * mat[1][1] * mat[2][2] + mat[1][0] * mat[2][1] * mat[0][2] + mat[2][0] * mat[0][1] * mat[1][2] -
			   mat[2][0] * mat[1][1] * mat[0][2] - mat[1][0] * mat[0][1] * mat[2][2] - mat[0][0] * mat[2][1] * mat[1][2];
	}

	using Mat3 = Mat3Template<float>;
	using Mat3D = Mat3Template<double>;

}

#endif // MAT3_HPP
