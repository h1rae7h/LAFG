#ifndef MAT2_HPP
#define MAT2_HPP

#include "Vec2.hpp"


namespace LAFG {

	/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	// class body
	template<typename T>
	class Mat2Template {
	public:
		Mat2Template();
		Mat2Template(const Mat2Template& mat);
		Mat2Template(const Vec2Template<T>& firstVec, const Vec2Template<T>& secondVec);
		Mat2Template(T init);
		Mat2Template(T firstX, T firstY, T secondX, T secondY);

		Vec2Template<T>& operator[](int i);
		const Vec2Template<T>& operator[](int i) const;
		const Mat2Template& operator+() const;
		Mat2Template operator-() const;
		Mat2Template& operator=(const Mat2Template& right);
		Mat2Template& operator=(T right);
		Mat2Template& operator+=(const Mat2Template& right);
		Mat2Template& operator+=(T right);
		Mat2Template& operator-=(const Mat2Template& right);
		Mat2Template& operator-=(T right);
		Mat2Template& operator*=(const Mat2Template& right);
		Mat2Template& operator*=(T right);
		Mat2Template& operator/=(T right);

		friend Vec2Template<T> operator*(const Mat2Template& left, const Vec2Template<T>& right);
		friend Vec2Template<T> operator*(const Vec2Template<T>& left, const Mat2Template& right);

		friend Mat2Template operator+(const Mat2Template& left, const Mat2Template& right);
		friend Mat2Template operator-(const Mat2Template& left, const Mat2Template& right);
		friend Mat2Template operator*(const Mat2Template& left, const Mat2Template& right);
		friend Mat2Template operator+(const Mat2Template& left, T right);
		friend Mat2Template operator-(const Mat2Template& left, T right);
		friend Mat2Template operator*(const Mat2Template& left, T right);
		friend Mat2Template operator*(T left, const Mat2Template& right);
		friend Mat2Template operator/(const Mat2Template& left, T right);
		friend bool operator==(const Mat2Template& left, const Mat2Template& right);
		friend bool operator!=(const Mat2Template& left, const Mat2Template& right);

		Vec2Template<T> row(int i) const;
		Vec2Template<T> col(int i) const;

		friend Mat2Template transpose(const Mat2Template& mat);
		friend T det(const Mat2Template& mat);

	private:
		/*------------------------------------------------------------------------*/
		// data
		Vec2Template<T> firstCol, secondCol;

	};

	/*------------------------------------------------------------------------*/
	// constructors
	template<typename T>
	inline Mat2Template<T>::Mat2Template() {}
	
	template<typename T>
	inline Mat2Template<T>::Mat2Template(const Mat2Template& mat)
		: firstCol(mat.firstCol), secondCol(mat.secondCol) {}

	template<typename T>
	inline Mat2Template<T>::Mat2Template(const Vec2Template<T>& firstVec, const Vec2Template<T>& secondVec)
		: firstCol(firstVec), secondCol(secondVec) {}

	template<typename T>
	inline Mat2Template<T>::Mat2Template(T init)
		: firstCol(init, 0.f), secondCol(0.f, init) {}

	template<typename T>
	inline Mat2Template<T>::Mat2Template(T firstX, T firstY, T secondX, T secondY)
		: firstCol(firstX, firstY), secondCol(secondX, secondY) {}

	/*------------------------------------------------------------------------*/
	// class member operators
	template<typename T>
	inline Vec2Template<T>& Mat2Template<T>::operator[](int i) {
		if (i == 1)
			return secondCol;
		return firstCol;
	}

	template<typename T>
	inline const Vec2Template<T>& Mat2Template<T>::operator[](int i) const {
		if (i == 1)
			return secondCol;
		return firstCol;
	}

	template<typename T>
	inline const Mat2Template<T>& Mat2Template<T>::operator+() const {
		return *this;
	}

	template<typename T>
	inline Mat2Template<T> Mat2Template<T>::operator-() const {
		return Mat2Template(-firstCol, -secondCol);
	}

	template<typename T>
	inline Mat2Template<T>& Mat2Template<T>::operator=(const Mat2Template& right) {
		firstCol = right.firstCol;
		secondCol = right.secondCol;
		return *this;
	}

	template<typename T>
	inline Mat2Template<T>& Mat2Template<T>::operator=(T right) {
		firstCol = right;
		secondCol = right;
		return *this;
	}

	template<typename T>
	inline Mat2Template<T>& Mat2Template<T>::operator+=(const Mat2Template& right) {
		firstCol += right.firstCol;
		secondCol += right.secondCol;
		return *this;
	}

	template<typename T>
	inline Mat2Template<T>& Mat2Template<T>::operator+=(T right) {
		firstCol += right;
		secondCol += right;
		return *this;
	}

	template<typename T>
	inline Mat2Template<T>& Mat2Template<T>::operator-=(const Mat2Template& right) {
		firstCol -= right.firstCol;
		secondCol -= right.secondCol;
		return *this;
	}

	template<typename T>
	inline Mat2Template<T>& Mat2Template<T>::operator-=(T right) {
		firstCol -= right;
		secondCol -= right;
		return *this;
	}

	template<typename T>
	inline Mat2Template<T>& Mat2Template<T>::operator*=(const Mat2Template& right) {
		T tempFirstX = firstCol.x * right.firstCol.x + secondCol.x * right.firstCol.y;
		T tempFirstY = firstCol.y * right.firstCol.x + secondCol.y * right.firstCol.y;
		T tempSecondX = firstCol.x * right.secondCol.x + secondCol.x * right.secondCol.y;
		T tempSecondY = firstCol.y * right.secondCol.x + secondCol.y * right.secondCol.y;
		firstCol.x = tempFirstX;
		firstCol.y = tempFirstY;
		secondCol.x = tempSecondX;
		secondCol.y = tempSecondY;
		return *this;
	}

	template<typename T>
	inline Mat2Template<T>& Mat2Template<T>::operator*=(T right) {
		firstCol *= right;
		secondCol *= right;
		return *this;
	}

	template<typename T>
	inline Mat2Template<T>& Mat2Template<T>::operator/=(T right) {
		firstCol /= right;
		secondCol /= right;
		return *this;
	}

	//                                             T
	// |a1 a2 a3|   |b1|                 |a1 a2 a3|                |a1 a4 a7|
	// |a4 a5 a6| * |b2| =  |b1 b2 b3| * |a4 a5 a6| = |b1 b2 b3| * |a2 a5 a8|
	// |a7 a8 a9|   |b3|                 |a7 a8 a9|                |a3 a6 a9|

	/*------------------------------------------------------------------------*/
	// Vec2/mat2 operators
	template<typename T>
	inline Vec2Template<T> operator*(const Mat2Template<T>& left, const Vec2Template<T>& right) {
		return Vec2Template(
			left.firstCol.x * right.x + left.secondCol.x * right.y,
			left.firstCol.y * right.x + left.secondCol.y * right.y);
	}

	template<typename T>
	inline Vec2Template<T> operator*(const Vec2Template<T>& left, const Mat2Template<T>& right) {
		return Vec2Template(
			left.x * right.firstCol.x + left.y * right.firstCol.y,
			left.x * right.secondCol.x + left.y * right.secondCol.y);
	}

	/*------------------------------------------------------------------------*/
	// global operators
	template<typename T>
	inline Mat2Template<T> operator+(const Mat2Template<T>& left, const Mat2Template<T>& right) {
		return Mat2Template(left.firstCol + right.firstCol, left.secondCol + right.secondcol);
	}

	template<typename T>
	inline Mat2Template<T> operator-(const Mat2Template<T>& left, const Mat2Template<T>& right) {
		return Mat2Template(left.firstCol - right.firstCol, left.secondcol - right.secondCol);
	}

	template<typename T>
	inline Mat2Template<T> operator*(const Mat2Template<T>& left, const Mat2Template<T>& right) {
		return Mat2Template(			
			left.firstCol.x * right.firstCol.x + left.secondCol.x * right.firstCol.y;
			left.firstCol.y * right.firstCol.x + left.secondCol.y * right.firstCol.y;
			left.firstCol.x * right.secondCol.x + left.secondCol.x * right.secondCol.y;
			left.firstCol.y * right.secondCol.x + left.secondCol.y * right.secondCol.y);
	}

	template<typename T>
	inline Mat2Template<T> operator+(const Mat2Template<T>& left, T right) {
		return Mat2Template(left.firstCol + right, left.secondCol + right);
	}

	template<typename T>
	inline Mat2Template<T> operator-(const Mat2Template<T>& left, T right) {
		return Mat2Template(left.firstCol - right, left.secondCol - right);
	}

	template<typename T>
	inline Mat2Template<T> operator*(const Mat2Template<T>& left, T right) {
		return Mat2Template(left.firstCol * right, left.secondCol * right);
	}

	template<typename T>
	inline Mat2Template<T> operator*(T left, const Mat2Template<T>& right) {
		return Mat2Template(
			left * right.firstCol.x, left * right.firstCol.y,
			left * right.secondCol.x, left * right.secondCol.y);
	}

	template<typename T>
	inline Mat2Template<T> operator/(const Mat2Template<T>& left, T right) {
		return Mat2Template(
			left.firstCol.x / right, left.firstCol.y / right,
			left.secondCol.x / right, left.secondCol.y / right);
	}

	template<typename T>
	inline bool operator==(const Mat2Template<T>& left, const Mat2Template<T>& right) {
		return
			left.firstCol.x == right.firstCol.x && left.fisrtCol.y == right.firstCol.y &&
			left.secondCol.x == right.secondCol.x && left.secondCol.y == right.secondCol.y;
	}

	template<typename T>
	inline bool operator!=(const Mat2Template<T> &left, const Mat2Template<T> &right) {
		return
			left.firstCol.x != right.firstCol.x || left.firstCol.y != right.firstCol.y ||
			left.secondCol.x != right.secondCol.x || left.secondCol.y != right.secondCol.y;
	}

	/*------------------------------------------------------------------------*/
	// methods
	template<typename T>
	inline Vec2Template<T> Mat2Template<T>::row(int i) const {
		if (i == 1)
			return Vec2Template(firstCol.y, secondCol.y);
		return Vec2Template(firstCol.x, secondCol.x);
	}

	template<typename T>
	inline Vec2Template<T> Mat2Template<T>::col(int i) const {
		if (i == 1)
			return secondCol;
		return firstCol;
	}

	/*------------------------------------------------------------------------*/
	// functions
	// sin(-a) = -sin(a), so transposed Mat2Template(Angle) = Mat2Template(-Angle)
	template<typename T>
	inline Mat2Template<T> matrixCompMult(const Mat2Template<T>& left, const Mat2Template<T>& right) {
		return Mat2Template(left.firstCol * right.firstCol, left.secondCol * right.secondCol);
	}

	inline Mat2Template<float> rotmat2(float angle) {
		float s = sinf(angle);
		float c = cosf(angle);
		return Mat2Template(c, s, -s, c);
	}

	inline Mat2Template<double> rotmat2(double angle) {
		double s = sin(angle);
		double c = cos(angle);
		return Mat2Template(c, s, -s, c);
	}

	template<typename T>
	inline Mat2Template<T> transpose(const Mat2Template<T>& mat) {
		return Mat2Template(mat.firstCol.x, mat.secondCol.x, mat.firstCol.y, mat.secondCol.y);
	}

	template<typename T>
	inline T det(const Mat2Template<T>& mat) {
		return mat.firstCol.x * mat.secondCol.y - mat.firstCol.y * mat.secondCol.x;
	}

	using Mat2 = Mat2Template<float>;
	using Mat2D = Mat2Template<double>;

}

#endif // MAT2_HPP
