#ifndef QUATERNION_HPP
#define QUATERNION_HPP

#include "Common.hpp"

#include <cmath>


// i^2 = j^2 = k^2 = -1
// ij = -ji = k
// jk = -kj = i
// ki = -ik = j


namespace LAFG {

	template<std::floating_point T>
	class QuaternionTemplate {
	public:
		// Constructors
		
		QuaternionTemplate()
			: a {}, b {}, c {}, d {} {}

		QuaternionTemplate(T a, T b, T c, T d)
			: a {a}, b {b}, c {c}, d {d} {}

		QuaternionTemplate(const Quaternion& init)
			: a {init.a}, b {init.b}, c {init.c}, d {init.d} {}

		/*------------------------------------------------------------------------*/
		// Conversion operators

		template<std::floating_point U> operator QuaternionTemplate<U>() const {
			return QuaternionTemplate<U>(a, b, c, d);
		}

		explicit bool operator() const { return a || b || c || d; }

		/*------------------------------------------------------------------------*/
		// Class member operators
		
		T& operator[](size_t i) {
			assert(i >= 0 && i < 4);
			return *(&a + i);
		}
		
		const T& operator[](size_t i) const {
			assert(i >= 0 && i < 4);
			return *(&a + i);
		}

		const QuaternionTemplate& operator+() const { return *this; }
		
		QuaternionTemplate operator-() const {
			return QuternionTemplate(-a, -b, -c, -d);
		}

		template<std::floating_point U>
		QuaternionTemplate& operator=(const QuaternionTemplate<U>& right) {
			a = right.a;
			b = right.b;
			c = right.c;
			d = right.d;
			return *this;
		}

		QuaternionTemplate& operator=(Number auto right) {
			a = right;
			b = {};
			c = {};
			d = {};
			return *this;
		}

		template<std::floating_point U>
		QuaternionTemplate& operator+=(const QuaternionTemplate<U>& right) {
			a += right.a;
			b += right.b;
			c += right.c;
			d += right.d;
			return *this;
		}
		
		QuaternionTemplate& operator+=(Number auto right) {
			a += right;
			return *this;
		}

		template<std::floating_point U>
		QuaternionTemplate& operator-=(const QuaternionTemplate<U>& right) {
			a -= right.a;
			b -= right.b;
			c -= right.c;
			d -= right.d;
			return *this;
		}

		QuaternionTemplate operator-=(Number auto right) {
			a -= right;
			return *this;
		}

		template<std::floating_point U>
		QuaternionTemplate& operator*=(const QuaternionTemplate<U>& right) {
			T aNew = a * right.a - b * right.b - c * right.c - d * right.d;
			T bNew = a * right.b + b * right.a + c * right.d - d * right.c;
			T cNew = a * right.c - b * right.d + c * right.a + d * right.b;
			T dNew = a * right.d + b * right.c - c * right.b + d * right.a;
			a = aNew;
			b = bNew;
			c = cNew;
			d = dNew;
			return *this;
		}

		QuaternionTemplate& operator*=(Number auto right) {
			a *= right;
			b *= right;
			c *= right;
			d *= right;
			return *this;
		}

		template<std::floating_point U>
		bool operator==(const QuaternionTemplate<U>& right) const {
			return a == right.a && b == right.b && c == right.c && d == right.d;
		}

		template<std::floating_point U>
		bool operator!=(const QuaternionTemplate<U>& right) const {
			return a != right.a || b != right.b || c != right.c || d != right.d;
		}

		/*------------------------------------------------------------------------*/
		// Methods
		
		T lenght() const {
			if constexpr(std::same_as<T, float>)
				return sqrtf(a * a + b * b + c * c + d * d);
			else
				return sqrt(a * a + b * b + c * c + d * d);
		}

		/*------------------------------------------------------------------------*/
		// Data
		
		T a;
		T b; // * i
		T c; // * j
		T d; // * k
	};

	using Quaternion = QuaternionTemplate<float>;
	using DQuaternion = QuaternionTemplate<double>;

}

#endif // QUATERNION_HPP
