#ifndef MAT2_HPP
#define MAT2_HPP

#include "Vec2.hpp"


namespace LAFG {
	
	/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	// Class body

	template<Number T>
	class Mat2Template {
	public:
		/*------------------------------------------------------------------------*/
		// Constructors

		Mat2Template() = default;

		Mat2Template(const Vec2Template<T>& dataFirst, const Vec2Template<T>& dataSecond)
			: data { dataFirst, dataSecond } {}
		
		explicit Mat2Template(T init)
			: data { Vec2Template<T>(init, {}), Vec2Template<T>({}, init) } {}
		
		Mat2Template(T xFirst, T yFirst, T xSecond, T ySecond)
			: data { Vec2Template<T>(xFirst, yFirst), Vec2Template<T>(xSecond, ySecond) } {}

		Mat2Template(const Mat2Template& mat)
			: data { mat.data[0], mat.data[1] } {}
		
		/*------------------------------------------------------------------------*/
		// Conversion operators

		// Convert to another subtype Mat2
		template<Number U>
		operator Mat2Template<U>() const { return Mat2Template<U>(data[0], data[1]); }

		// True if at least one of components is not 0
		explicit operator bool() const { return data[0] || data[1]; }

		/*------------------------------------------------------------------------*/
		// class member operators
		
		Vec2Template<T>& operator[](size_t i) {
			assert(i >= 0 && i < 2);
			return data[i];
		}

		const Vec2Template<T>& operator[](size_t i) const {
			assert(i >= 0 && i < 2);
			return data[i];
		}

		const Mat2Template& operator+() const { return *this; }
		
		Mat2Template operator-() const { return Mat2Template(-data[0], -data[1]); }
		
		Mat2Template& operator=(const Mat2Template& right) {
			data[0] = right.data[0];
			data[1] = right.data[1];
			return *this;
		}

		Mat2Template& operator=(Number auto right) {
			data[0].x = right;
			data[0].y = {};
			data[1].x = {};
			data[1].y = right;
			return *this;
		}

		template<Number U> Mat2Template& operator+=(const Mat2Template<U>& right) {
			data[0] += right.data[0];
			data[1] += right.data[1];
			return *this;
		}

		Mat2Template& operator+=(Number auto right) {
			data[0] += right;
			data[1] += right;
			return *this;
		}

		template<Number U> Mat2Template& operator-=(const Mat2Template<U>& right) {
			data[0] -= right.data[0];
			data[1] -= right.data[1];
			return *this;
		}

		Mat2Template& operator-=(Number auto right) {
			data[0] -= right;
			data[1] -= right;
			return *this;
		}

		template<Number U> Mat2Template& operator*=(const Mat2Template<U>& right) {
			data[0] *= right.data[0];
			data[1] *= right.data[1];
			return *this;
		}

		Mat2Template& operator*=(Number auto right) {
			data[0] *= right;
			data[1] *= right;
			return *this;
		}

		template<Number U> Mat2Template& operator/=(const Mat2Template<U>& right) {
			data[0] /= right.data[0];
			data[1] /= right.data[1];
			return *this;
		}

		Mat2Template& operator/=(Number auto right) {
			data[0] /= right;
			data[1] /= right;
			return *this;
		}
	
		/*------------------------------------------------------------------------*/
		// Methods

		Vec2Template<T> getRow(size_t i) const;
		Vec2Template<T> getCol(size_t i) const;

	protected:
		/*------------------------------------------------------------------------*/
		// Data

		Vec2Template<T> data[2];

	};

	/*------------------------------------------------------------------------*/
	// Global operators

	// Matrices per-component sum
	template<Number T, Number U>
	inline auto operator+(const Mat2Template<T>& left, const Mat2Template<U>& right) {
		return Mat2Template(left[0] + right[0], left[1] + right[1]);
	}

	// Sum of every left matrix component and right scalar
	template<Number T>
	inline auto operator+(const Mat2Template<T>& left, Number auto right) {
		return Mat2Template(left[0] + right, left[1] + right);
	}
	
	// Sum of left scalar and every right matrix component
	template<Number T>
	inline auto operator+(Number auto left, const Mat2Template<T>& right) {
		return Mat2Template(left + right[0], left + right[1]);
	}

	// 
	template<Number T, Number U>
	inline auto operator-(const Mat2Template<T>& left, const Mat2Template<U>& right) {
		return Mat2Template(left[0] - right[0], left[1] - right[1]);
	}

	template<Number T>
	inline auto operator-(const Mat2Template<T>& left, Number auto right) {
		return Mat2Template(left[0] - right, left[1] - right);
	}
	template<Number T>
	inline auto operator-(Number auto left, const Mat2Template<T>& right) {
		return Mat2Template(left - right[0], left - right[1]);
	}

	// Matrix-matrix per-component multiplication
	template<Number T, Number U>
	inline auto operator*(const Mat2Template<T>& left, const Mat2Template<U>& right) {
		return Mat2Template(left[0] * right[0], left[1] * right[1]);
	}
	
	template<Number T>
	inline auto operator*(const Mat2Template<T>& left, Number auto right) {
		return Mat2Template(left[0] * right, left[1] * right);
	}
	
	template<Number T>
	inline auto operator*(Number auto left, const Mat2Template<T>& right) {
		return Mat2Template(left * right[0], left * right[1]);
	}

	// Matrix-matrix per-component division
	template<Number T, Number U>
	inline auto operator/(const Mat2Template<T>& left, const Mat2Template<U>& right) {
		return Mat2Template(left[0] / right[0], left[1] / right[1]);
	}

	template<Number T>
	inline auto operator/(const Mat2Template<T>& left, Number auto right) {
		return Mat2Template<T>(left[0] / right, left[1] / right);
	}

	template<Number T>
	inline auto operator/(Number auto left, const Mat2Template<T>& right) {
		return Mat2Template<T>(left / right[0], left / right[1]);
	}
		 
	template<Number T, Number U>
	inline bool operator==(const Mat2Template<T>& left, const Mat2Template<U>& right) {
		return left[0] == right[0] && left[1] == right[1];
	}
	
	template<Number T, Number U>
	inline bool operator!=(const Mat2Template<T>& left, const Mat2Template<U>& right) {
		return left[0] != right[0] || left[1] != right[1];
	}

	/*------------------------------------------------------------------------*/
	// Methods

	// Returns matrix row (rvalue)
	template<Number T>
	inline Vec2Template<T> Mat2Template<T>::getRow(size_t i) const {
		assert(i >= 0 && i < 2);
#ifdef LAFG_USE_ROW_LAYOUT
		return data[i];
#else
		return Vec2Template<T>(data[0][i], data[1][i]);
#endif
	}

	// Returns matrix column (rvalue)
	template<Number T>
	inline Vec2Template<T> Mat2Template<T>::getCol(size_t i) const {
		assert(i >= 0 && i < 2);
#ifdef LAFG_USE_ROW_LAYOUT
		return Vec2Template<T>(data[0][i], data[1][i]);
#else
		return data[i];
#endif
	}

	/*------------------------------------------------------------------------*/
	// Functions

	// Matrix-matrix multiplication
	template<Number T, Number U>
	inline auto mul(const Mat2Template<T>& left, const Mat2Template<U>& right) {
#ifdef LAFG_USE_ROW_LAYOUT
		return Mat2Template(
				left[0].x * right[0] + left[0].y * right[1],
				left[1].x * right[0] + left[1].y * right[1]);
#else
		return Mat2Template(
				left[0] * right[0].x + left[1] * right[0].y,
				left[0] * right[1].x + left[1] * right[1].y);
#endif
	}

	// Matrix-vector multiplication
	template<Number T, Number U>
	inline auto mul(const Mat2Template<T>& left, const Vec2Template<U>& right) {
#ifdef LAFG_USE_ROW_LAYOUT
		return Vec2Template(dot(left[0], right), dot(left[1], right));
#else
		return left[0] * right.x + left[1] * right.y;
#endif
	}
	
	// Vector-matrix multiplication
	template<Number T, Number U>
	inline auto mul(const Vec2Template<T>& left, const Mat2Template<U>& right) {
#ifdef LAFG_USE_ROW_LAYOUT
		return left.x * right[0] + left.y * right[1];
#else
		return Vec2Template(dot(left, right[0]), dot(left, right[1]));
#endif
	}

	// Returns transposed matrix
	template<Number T>
	inline Mat2Template<T> transpose(const Mat2Template<T>& mat) {
		return Mat2Template<T>(mat[0].x, mat[1].x, mat[0].y, mat[1].y);
	}

	// Returns matrix determinant
	template<Number T>
	inline T det(const Mat2Template<T>& mat) {
		return mat[0].x * mat[1].y - mat[0].y * mat[1].x;
	}

	// Returns right inverse matrix, double precision
	template<Number T>
	inline Mat2Template<double> inv(const Mat2Template<T>& mat) {
		double invDet = det(mat);
		assert(invDet);
		invDet = 1. / invDet;
		return Mat2Template<double>(mat[1].y, -mat[0].y, -mat[1].x, mat[0].x) * invDet;
	}

	// Returns right inverse matrix, single precision
	template<Number T>
	inline Mat2Template<float> invf(const Mat2Template<T>& mat) {
		float invDet = det(mat);
		assert(invDet);
		invDet = 1.f / invDet;
		return Mat2Template<float>(mat[1].y, -mat[0].y, -mat[1].x, mat[0].x) * invDet;
	}

	using Mat2 = Mat2Template<float>;
	using DMat2 = Mat2Template<double>;
	using CMat2 = Mat2Template<char>;
	using IMat2 = Mat2Template<int>;
	using UMat2 = Mat2Template<unsigned>;

}

#endif // MAT2_HPP

