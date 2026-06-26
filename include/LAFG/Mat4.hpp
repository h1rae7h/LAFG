#ifndef MAT4_HPP
#define MAT4_HPP

#include "Vec4.hpp"
#include "Mat2.hpp"
#include "Mat3.hpp"


namespace LAFG {

	/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	// class body

	template<Number T>
	class Mat4Template {
	public:
		/*------------------------------------------------------------------------*/
		// Constructors

		Mat4Template() = default;

		Mat4Template(
			const Vec4Template<T>& first,
			const Vec4Template<T>& second,
			const Vec4Template<T>& third,
			const Vec4Template<T>& fourth)
			: data { first, second, third, fourth } {}
		
		explicit Mat4Template(T init)
			: data {
				Vec4Template<T>(init, {}, {}, {}),
				Vec4Template<T>({}, init, {}, {}),
				Vec4Template<T>({}, {}, init, {}),
				Vec4Template<T>({}, {}, {}, init) } {}
		
		Mat4Template(
			T xFirst,  T yFirst,  T zFirst, T wFirst,
			T xSecond, T ySecond, T zSecond, T wSecond,
			T xThird,  T yThird,  T zThird, T wThird,
			T xFourth, T yFourth, T zFourth, T wFourth)
			: data {
				Vec4Template<T>(xFirst, yFirst, zFirst, wFirst),
				Vec4Template<T>(xSecond, ySecond, zSecond, wSecond),
				Vec4Template<T>(xThird, yThird, zThird, wThird),
				Vec4Template<T>(xFourth, yFourth, zFourth, wFourth) } {}
		
		Mat4Template(
			const Mat2Template<T>& first, const Mat2Template<T>& second,
			const Mat2Template<T>& third, const Mat2Template<T>& fourth)
			: data {
				Vec4Template<T>(first[0], second[0]),
				Vec4Template<T>(first[1], second[1]),
				Vec4Template<T>(third[0], fourth[0]),
				Vec4Template<T>(third[1], fourth[1]) } {}

		Mat4Template(const Mat4Template& mat)
			: data { mat.data[0], mat.data[1], mat.data[2], mat.data[3] } {}
		

		/*------------------------------------------------------------------------*/
		// Conversion operators
		
		// Convert to another subtype Mat2
		template<Number U>
		operator Mat4Template<U>() const { 
			return Mat4Template<U>(data[0], data[1], data[2], data[3]);
		}

		// True if at least one of components is not 0
		explicit operator bool() const {
			return data[0] || data[1] || data[2] || data[3];
		}

		/*------------------------------------------------------------------------*/
		// Class-member operators

		Vec4Template<T>& operator[](size_t i) {
			assert(i >= 0 && i < 4);
			return data[i];
		}

		const Vec4Template<T>& operator[](size_t i) const {
			assert(i >= 0 && i < 4);
			return data[i];
		}

		const Mat4Template& operator+() const {
			return *this;
		}

		Mat4Template operator-() const {
			return Mat4Template(-data[0], -data[1], -data[2], -data[3]);
		}
		
		template<Number U> Mat4Template& operator=(const Mat4Template<U>& right)  {
			data[0] = right.data[0];
			return *this;
		}
		
		Mat4Template& operator=(Number auto right) {
			data[0] = right;
			data[1] = right;
			data[2] = right;
			data[3] = right;
			return *this;
		}
		
		template<Number U> Mat4Template& operator+=(const Mat4Template<U>& right) {
			data[0] += right.data[0];
			data[1] += right.data[1];
			data[2] += right.data[2];
			data[3] += right.data[3];
			return *this;
		}
		
		Mat4Template& operator+=(Number auto right) {
			data[0] += right;
			data[1] += right;
			data[2] += right;
			data[3] += right;
			return *this;
		}
		
		template<Number U> Mat4Template& operator-=(const Mat4Template<U>& right) {
			data[0] -= right.data[0];
			data[1] -= right.data[1];
			data[2] -= right.data[2];
			data[3] -= right.data[3];
			return *this;
		}
		
		Mat4Template& operator-=(Number auto right) {
			data[0] -= right;
			data[1] -= right;
			data[2] -= right;
			data[3] -= right;
			return *this;
		}

		template<Number U> Mat4Template& operator*=(const Mat4Template<U>& right) {
			data[0] *= right[0];
			data[1] *= right[1];
			data[2] *= right[2];
			data[3] *= right[3];
			return *this;	
		}
		
		Mat4Template& operator*=(Number auto right) {
			data[0] *= right;
			data[1] *= right;
			data[2] *= right;
			data[3] *= right;
			return *this;
		}

		template<Number U> Mat4Template& operator/=(const Mat4Template<U>& right) {
			data[0] /= right[0];
			data[1] /= right[1];
			data[2] /= right[2];
			data[3] /= right[3];
			return *this;
		}
		
		Mat4Template& operator/=(Number auto right) {
			data[0] /= right;
			data[1] /= right;
			data[2] /= right;
			data[3] /= right;
			return *this;
		}

		// Methods
		Vec4Template<T> getRow(size_t i);
		Vec4Template<T> getCol(size_t i);

	private:
		/*------------------------------------------------------------------------*/
		// Data

		Vec4Template<T> data[4];

	};

	/*------------------------------------------------------------------------*/
	// Global opeartors
	
	template<Number T, Number U>
	inline auto operator+(const Mat4Template<T>& left, const Mat4Template<U>& right) {
		return Mat4Template(left[0] + right[0], left[1] + right[1], left[2] + right[2], left[3] + right[3]);
	}

	template<Number T>
	inline auto operator+(const Mat4Template<T>& left, Number auto right) {
		return Mat4Template(left[0] + right, left[1] + right, left[2] + right, left[3] + right);
	}

	template<Number T>
	inline auto operator+(Number auto left, const Mat4Template<T>& right) {
		return Mat4Template(left + right[0], left + right[1], left + right[2], left + right[3]);
	}
	
	template<Number T, Number U>
	inline auto operator-(const Mat4Template<T>& left, const Mat4Template<U>& right) {
		return Mat4Template(left[0] - right[0], left[1] - right[1], left[2] - right[2], left[3] - right[3]);
	}

	template<Number T>
	inline auto operator-(const Mat4Template<T>& left, Number auto right) {
		return Mat4Template(left[0] - right, left[1] - right, left[2] - right, left[3] - right);
	}

	template<Number T>
	inline auto operator-(Number auto left, const Mat4Template<T>& right) {
		return Mat4Template(left - right[0], left - right[1], left - right[2], left - right[3]);
	}

	template<Number T, Number U>
	inline auto operator*(const Mat4Template<T>& left, const Mat4Template<U>& right) {
		return Mat4Template(
				left[0] * right[0], left[1] * right[1],
				left[2] * right[2], left[3] * right[3]);
	}

	template<Number T>
	inline auto operator*(const Mat4Template<T>& left, Number auto right) {
		return Mat4Template(left[0] * right, left[1] * right, left[2] * right, left[3] * right);
	}

	template<Number T>
	inline auto operator*(Number auto left, const Mat4Template<T>& right) {
		return Mat4tempalte(left * right[0], left * right[1], left * right[2], left * right[3]);
	}

	template<Number T, Number U>
	inline auto operator/(const Mat4Template<T>& left, const Mat4Template<U>& right) {
		return Mat4Template(
				left[0] / right[0], left[1] / right[1],
				left[2] / right[2], left[3] / right[3]);
	}

	template<Number T>
	inline auto operator/(const Mat4Template<T>& left, Number auto right) {
		return Mat4Template(left[0] / right, left[1] / right, left[2] / right, left[3] / right);
	}
	
	template<Number T>
	inline auto operator/(Number auto left, const Mat4Template<T>& right) {
		return Mat4tempalte(left / right[0], left / right[1], left / right[2], left / right[3]);
	}

	template<Number T, Number U>
	inline bool operator==(const Mat4Template<T>& left, const Mat4Template<U>& right) {
		return left[0] == right[0] && left[1] == right[1] && left[2] == right[2] && left[3] == right[3];
	}

	template<Number T, Number U>
	inline bool operator!=(const Mat4Template<T>& left, const Mat4Template<U>& right) {
		return left[0] != right[0] || left[1] != right[1] || left[2] != right[2] || left[3] != right[3];
	}

	/*------------------------------------------------------------------------*/
	// Methods
	
	template<Number T>
	inline Vec4Template<T> Mat4Template<T>::getRow(size_t i) {
		assert(i >= 0 && i < 4);
#ifdef LAFG_USE_ROW_LAYOUT
		return data[i];
#else
		return Vec4Template<T>(data[0][i], data[1][i], data[2][i], data[3][i]);
#endif
	}

	template<Number T>
	inline Vec4Template<T> Mat4Template<T>::getCol(size_t i) {
		assert(i >= 0 && i < 4);
#ifdef LAFG_USE_ROW_LAYOUT
		return Vec4Template<T>(data[0][i], data[1][i], data[2][i], data[3][i]);
#else
		return data[i];
#endif
	}

	/*------------------------------------------------------------------------*/
	// Functions
	
	template<Number T, Number U>
	inline auto mul(const Mat4Template<T>& left, const Mat4Template<U>& right) {
#ifdef LAFG_USE_ROW_LAYOUT
		return Mat4Template(
				left[0].x * right[0] + left[0].y * right[1] + left[0].z * right[2] + left[0].w * right[3],
				left[1].x * right[0] + left[1].y * right[1] + left[1].z * right[2] + left[1].w * right[3],
				left[2].x * right[0] + left[2].y * right[1] + left[2].z * right[2] + left[2].w * right[3],
				left[3].x * right[0] + left[3].y * right[1] + left[3].z * right[2] + left[3].w * right[3]);
#else
		return Mat4Template(
				left[0] * right[0].x + left[1] * right[0].y + left[2] * right[0].z + left[3] * right[0].w,
				left[0] * right[1].x + left[1] * right[1].y + left[2] * right[1].z + left[3] * right[1].w,
				left[0] * right[2].x + left[1] * right[2].y + left[2] * right[2].z + left[3] * right[2].w,
				left[0] * right[3].x + left[1] * right[3].y + left[2] * right[3].z + left[3] * right[3].w);
#endif
	}

	template<Number T, Number U>
	inline auto mul(const Mat4Template<T>& left, const Vec4Template<U>& right) {
#ifdef LAFG_USE_ROW_LAYOUT
		return Vec4Template(
				dot(left[0], right),
				dot(left[1], right),
				dot(left[2], right),
				dot(left[3], right));
#else
		return Vec4Template(
				left[0] * right.x +
				left[1] * right.y +
				left[2] * right.z +
				left[3] * right.w);
#endif
	}

	template<Number T, Number U>
	inline auto mul(const Vec4Template<T>& left, const Mat4Template<U>& right) {
#ifdef LAFG_USE_ROW_LAYOUT
		return Vec4Template(
				left.x * right[0] +
				left.y * right[1] +
				left.z * right[2] +
				left.w * right[3]);
#else
		return Vec4Template(
				dot(left, right[0]),
				dot(left, right[1]),
				dot(left, right[2]),
				dot(left, right[3]));
#endif
	}

	template<Number T>
	inline Mat4Template<T> transpose(const Mat4Template<T>& mat) {
		return Mat3Template<T>(
				mat[0].x, mat[1].x, mat[2].x, mat[3].x,
				mat[0].y, mat[1].y, mat[2].y, mat[3].y,
				mat[0].z, mat[1].z, mat[2].z, mat[3].z,
				mat[0].w, mat[1].w, mat[2].w, mat[3].w);
	}
	
	template<Number T>
	inline T det(const Mat4Template<T>& mat) {
		return 
			mat[0].x *
			(mat[1].y * mat[2].z * mat[3].w +
			 mat[1].z * mat[2].w * mat[3].y +
			 mat[1].w * mat[2].y * mat[3].z -
			 mat[1].w * mat[2].z * mat[3].y -
			 mat[1].y * mat[2].w * mat[3].z -
			 mat[1].z * mat[2].y * mat[3].w) -
			mat[1].x * 
			(mat[0].y * mat[2].z * mat[3].w +
			 mat[0].z * mat[2].w * mat[3].y +
			 mat[0].w * mat[2].y * mat[3].z -
			 mat[0].w * mat[2].z * mat[3].y -
			 mat[0].y * mat[2].w * mat[3].z -
			 mat[0].z * mat[2].y * mat[3].w) +
			mat[2].x *
			(mat[0].y * mat[1].z * mat[3].w +
			 mat[0].z * mat[1].w * mat[3].y +
			 mat[0].w * mat[1].y * mat[3].z -
			 mat[0].w * mat[1].z * mat[3].y -
			 mat[0].y * mat[1].w * mat[3].z -
			 mat[0].z * mat[1].y * mat[3].w) -
			mat[3].x *
			(mat[0].y * mat[1].z * mat[2].w +
			 mat[0].z * mat[1].w * mat[2].y +
			 mat[0].w * mat[1].y * mat[2].z -
			 mat[0].w * mat[1].z * mat[2].y -
			 mat[0].y * mat[1].w * mat[2].z -
			 mat[0].z * mat[1].y * mat[2].w);
	}

	inline Mat4Template<double> inv(const Mat4Template<double>& mat) {
		assert(det(mat));
		Mat2Template<double> A(mat[0].x, mat[0].y, mat[1].x, mat[1].y);
		Mat2Template<double> D(mat[2].z, mat[2].w, mat[3].z, mat[3].w);
		Mat2Template<double> invA = inv(A);
		Mat2Template<double> invD = inv(D);
#ifdef LAFG_USE_ROW_LAYOUT
		Mat2Template<double> B(mat[0].z, mat[0].w, mat[1].z, mat[1].w);
		Mat2Template<double> C(mat[2].x, mat[2].y, mat[3].x, mat[3].y);
#else
		Mat2Template<double> B(mat[2].x, mat[2].y, mat[3].x, mat[3].y);
		Mat2Template<double> C(mat[0].z, mat[0].w, mat[1].z, mat[1].w);
#endif
		Mat2Template<double> invH = inv(A - B * invD * C);
		Mat2Template<double> invG = inv(D - C * invA * B);
#ifdef LAFG_USE_ROW_LAYOUT
		return Mat4Template<double>(invH, -invH * B * invD, -invG * C * invA, invG);
#else
		return Mat4Template<double>(invH, -invG * C * invA, -invH * B * invD, invG);
#endif
	}
	
	inline Mat4Template<float> invf(const Mat4Template<float>& mat) {
		assert(det(mat));
		Mat2Template<float> A(mat[0].x, mat[0].y, mat[1].x, mat[1].y);
		Mat2Template<float> D(mat[2].z, mat[2].w, mat[3].z, mat[3].w);
		Mat2Template<float> invA = invf(A);
		Mat2Template<float> invD = invf(D);
#ifdef LAFG_USE_ROW_LAYOUT
		Mat2Template<float> B(mat[0].z, mat[0].w, mat[1].z, mat[1].w);
		Mat2Template<float> C(mat[2].x, mat[2].y, mat[3].x, mat[3].y);
#else
		Mat2Template<float> B(mat[2].x, mat[2].y, mat[3].x, mat[3].y);
		Mat2Template<float> C(mat[0].z, mat[0].w, mat[1].z, mat[1].w);
#endif
		Mat2Template<float> invH = invf(A - B * invD * C);
		Mat2Template<float> invG = invf(D - C * invA * B);
#ifdef LAFG_USE_ROW_LAYOUT
		return Mat4Template<float>(invH, -invH * B * invD, -invG * C * invA, invG);
#else
		return Mat4Template<float>(invH, -invG * C * invA, -invH * B * invD, invG);
#endif
	}

	using Mat4 = Mat4Template<float>;
	using DMat4 = Mat4Template<double>;

}

#endif // MAT4_HPP
