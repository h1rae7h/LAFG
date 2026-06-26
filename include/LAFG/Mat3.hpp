#ifndef MAT3_HPP
#define MAT3_HPP

#include "Vec3.hpp"


namespace LAFG {

	/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
	// Class body
	
	template<Number T>
	class Mat3Template {
	public:
		/*------------------------------------------------------------------------*/
		// Constructors

		Mat3Template() = default;
		
		Mat3Template(
			const Vec3Template<T>& dataFirst,
			const Vec3Template<T>& dataSecond,
			const Vec3Template<T>& dataThird)
			: data { dataFirst, dataSecond, dataThird } {}
		
		explicit Mat3Template(T init)
			: data {
				Vec3Template<T>(init, {}, {}),
				Vec3Template<T>({}, init, {}),
				Vec3Template<T>({}, {}, init) } {}
		
		Mat3Template(
			T xFirst, T yFirst, T zFirst,
			T xSecond, T ySecond, T zSecond,
			T xThird, T yThird, T zThird)
			: data {
				Vec3Template<T>(xFirst, yFirst, zFirst),
				Vec3Template<T>(xSecond, ySecond, zSecond),
				Vec3Template<T>(xThird, yThird, zThird) } {}

		Mat3Template(const Mat3Template& mat)
			: data { mat.data[0], mat.data[1], mat.data[2] } {}
		
		/*------------------------------------------------------------------------*/
		// Conversion operators
		
		template<Number U>
		operator Mat3Template<U>() const {
			return Mat3Template<U>(data[0], data[2], data[3]);
		}

		explicit operator bool() const { return data[0] || data[1] || data[2]; }

		/*------------------------------------------------------------------------*/
		// Class-member operators

		Vec3Template<T>& operator[](size_t i) {
			assert(i >= 0 && i < 3);
			return data[i];
		}

		const Vec3Template<T>& operator[](size_t i) const {
			assert(i >= 0 && i < 3);
			return data[i];
		}
		
		const Mat3Template& operator+() const { return *this; }
		
		Mat3Template operator-() const {
			return Mat3Template(-data[0], -data[1], -data[2]);
		}
		
		template<Number U> Mat3Template& operator=(const Mat3Template<U>& right) {
			data[0] = right.data[0];
			data[1] = right.data[1];
			data[2] = right.data[2];
			return *this;
		}
		
		Mat3Template& operator=(Number auto right) {
			data[0] = right;
			data[1] = right;
			data[2] = right;
			return *this;
		}
		
		template<Number U> Mat3Template& operator+=(const Mat3Template<U>& right) {
			data[0] += right.data[0];
			data[1] += right.data[1];
			data[2] += right.data[2];
			return *this;
		}
		
		Mat3Template& operator+=(Number auto right) {
			data[0] += right;
			data[1] += right;
			data[2] += right;
			return *this;
		}
		
		template<Number U> Mat3Template& operator-=(const Mat3Template<U>& right) {
			data[0] -= right.data[0];
			data[1] -= right.data[1];
			data[2] -= right.data[2];
			return *this;
		}

		Mat3Template& operator-=(Number auto right) {
			data[0] -= right;
			data[1] -= right;
			data[2] -= right;
			return *this;
		}

		template<Number U> Mat3Template& operator*=(const Mat3Template<U>& right) {
			data[0] *= right.data[0];
			data[1] *= right.data[1];
			data[2] *= right.data[2];
			return *this;
		}
		
		Mat3Template& operator*=(Number auto right) {
			data[0] *= right;
			data[1] *= right;
			data[2] *= right;
			return *this;
		}
		
		template<Number U> Mat3Template& operator/=(const Mat3Template<U>& right) {
			data[0] /= right.data[0];
			data[1] /= right.data[1];
			data[2] /= right.data[2];
			return *this;
		}

		Mat3Template& operator/=(Number auto right) {
			data[0] /= right;
			data[1] /= right;
			data[2] /= right;
			return *this;
		}

		Vec3Template<T> getRow(size_t i);
		Vec3Template<T> getCol(size_t i);

	private:
		/*------------------------------------------------------------------------*/
		// Data
		
		Vec3Template<T> data[3];

	};

	/*------------------------------------------------------------------------*/
	// Global opeartors

	template<Number T, Number U>
	inline auto operator+(const Mat3Template<T>& left, const Mat3Template<U>& right) {
		return Mat3Template(left[0] + right[0], left[1] + right[1], left[2] + right[2]);
	}
	
	template<Number T>
	inline auto operator+(const Mat3Template<T>& left, Number auto right) {
		return Mat3Template(left[0] + right, left[1] + right, left[2] + right);
	}

	template<Number T>
	inline auto operator+(Number auto left, const Mat3Template<T>& right) {
		return Mat3Template(left + right[0], left + right[1], left + right[2]);
	}

	template<Number T, Number U>
	inline auto operator-(const Mat3Template<T>& left, const Mat3Template<U>& right) {
		return Mat3Template(left[0] - right[0], left[1] - right[1], left[2] - right[2]);
	}

	template<Number T>
	inline auto operator-(const Mat3Template<T>& left, Number auto right) {
		return Mat3Template(left[0] - right, left[1] - right, left[2] - right);
	}

	template<Number T>
	inline auto operator-(Number auto left, const Mat3Template<T>& right) {
		return Mat3Template(left - right[0], left - right[1], left - right[2]);
	}

	template<Number T, Number U>
	inline auto operator*(const Mat3Template<T>& left, const Mat3Template<U>& right) {
		return Mat3Template(left[0] * right[0], left[1] * right[1], left[2] * right[2]);
	}

	template<Number T>
	inline auto operator*(const Mat3Template<T>& left, Number auto right) {
		return Mat3Template(left[0] * right, left[1] * right, left[2] * right);
	}

	template<Number T>
	inline auto operator*(Number auto left, const Mat3Template<T>& right) {
		return Mat3Template(left * right[0], left * right[1], left * right[2]);
	}

	template<Number T, Number U>
	inline auto operator/(const Mat3Template<T>& left, const Mat3Template<U>& right) {
		return Mat3Template(left[0] / right[0], left[1] / right[1], left[2] / right[2]);
	}

	template<Number T>
	inline auto operator/(const Mat3Template<T>& left, Number auto right) {
		return Mat3Template(left[0] / right, left[1] / right, left[2] / right);
	}

	template<Number T>
	inline auto operator/(Number auto left, const Mat3Template<T>& right) {
		return Mat3Template(left / right[0], left / right[1], left / right[2]);
	}
	
	template<Number U, Number T>
	inline bool operator==(const Mat3Template<T>& left, const Mat3Template<U>& right) {
		return left[0] == right[0] && left[1] == right[1] && left[2] == right[2];
	}

	template<Number T, Number U>
	inline bool operator!=(const Mat3Template<T>& left, const Mat3Template<U>& right) {
		return left[0] != right[0] || left[1] != right[1] || left[2] != right[2];
	}

	/*------------------------------------------------------------------------*/
	// Methods

	template<Number T>
	inline Vec3Template<T> Mat3Template<T>::getRow(size_t i) {
		assert(i >= 0 && i < 3);
#ifdef LAFG_USE_ROW_LAYOUT
		return data[i];
#else
		return Vec3Template<T>(data[0][i], data[1][i], data[2][i]);
#endif
	}

	template<Number T>
	inline Vec3Template<T> Mat3Template<T>::getCol(size_t i) {
		assert(i >= 0 && i < 3);
#ifdef LAFG_USE_ROW_LAYOUT
		return Vec3Template<T>(data[0][i], data[1][i], data[2][i]);
#else
		return data[i];
#endif
	}

	/*------------------------------------------------------------------------*/
	// Functions
	
	template<Number T, Number U>
	inline auto mul(const Mat3Template<T>& left, const Mat3Template<U>& right) {
#ifdef LAFG_USE_ROW_LAYOUT
		return Mat3Template(
				left[0].x * right[0] + left[0].y * right[1] + left[0].z * right[2],
				left[1].x * right[0] + left[1].y * right[1] + left[1].z * right[2],
				left[2].x * right[0] + left[2].y * right[1] + left[2].z * right[2]);
#else
		return Mat3Template(
				left[0] * right[0].x + left[1] * right[0].y + left[2] * right[0].z,
				left[0] * right[1].x + left[1] * right[1].y + left[2] * right[1].z,
				left[0] * right[2].x + left[1] * right[2].y + left[2] * right[2].z);
#endif
	}

	template<Number T, Number U>
	inline auto mul(const Mat3Template<T>& left, const Vec3Template<U>& right) {
#ifdef LAFG_USE_ROW_LAYOUT
		return Vec3Template(
				dot(left[0], right),
				dot(left[1], right),
				dot(left[2], right));
#else
		return left[0] * right.x + left[1] * right.y + left[2] * right.z;
#endif
	}

	template<Number T, Number U>
	inline auto mul(const Vec3Template<T>& left, const Mat3Template<U>& right) {
#ifdef LAFG_USE_ROW_LAYOUT
		return left.x * right[0] + left.y * right[1] + left.z * right[2];
#else
		return Vec3Template(
				dot(left, right[0]),
				dot(left, right[1]),
				dot(left, right[2]));
#endif
	}

	template<Number T>
	inline Mat3Template<T> transpose(const Mat3Template<T>& mat) {
		return Mat3Template<T>(
			mat[0].x, mat[1].x, mat[2].x,
			mat[0].y, mat[1].y, mat[2].y,
			mat[0].z, mat[1].z, mat[2].z);
	}
	
	template<typename T>
	inline T det(const Mat3Template<T>& mat) {
		return 
			mat[0][0] * mat[1][1] * mat[2][2] + mat[1][0] * mat[2][1] * mat[0][2] + mat[2][0] * mat[0][1] * mat[1][2] -
			mat[2][0] * mat[1][1] * mat[0][2] - mat[1][0] * mat[0][1] * mat[2][2] - mat[0][0] * mat[2][1] * mat[1][2];
	}

	using Mat3 = Mat3Template<float>;
	using Mat3D = Mat3Template<double>;

}

#endif // MAT3_HPP
