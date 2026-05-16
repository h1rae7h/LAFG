#ifndef QUATERNION_HPP
#define QUATERNION_HPP

#include <cmath>


// i^2 = j^2 = k^2 = -1
// ij = -ji = k
// jk = -kj = i
// ki = -ik = j


namespace LAFG {

	class Quaternion {
	public:
		// constructors
		Quaternion()
			: a(0.0f), b(0.0f), c(0.0f), d(0.0f) {}

		Quaternion(const float& a, const float& b, const float& c, const float& d)
			: a(a), b(b), c(c), d(d) {}

		/*------------------------------------------------------------------------*/
		// class member operators
		Quaternion operator+(const Quaternion& right) const {
			return Quaternion(a + right.a, b + right.b, c + right.c, d + right.d);
		}

		Quaternion operator-(const Quaternion& right) const {
			return Quaternion(a - right.a, b - right.b, c - right.c, d - right.d);
		}

		Quaternion operator*(const Quaternion& right) const {
			return Quaternion(
				a * right.a - b * right.b - c * right.c - d * right.d,
				a * right.b + b * right.a + c * right.d - d * right.c,
				a * right.c - b * right.d + c * right.a + d * right.b,
				a * right.d + b * right.c - c * right.b + d * right.a);
		}

		bool operator==(const Quaternion& right) const {
			return a == right.a && b == right.b && c == right.c && d == right.d;
		}

		Quaternion& operator=(const Quaternion& right) {
			a = right.a;
			b = right.b;
			c = right.c;
			d = right.d;
			return *this;
		}

		Quaternion operator+(const float& right) const {
			return Quaternion(
				a + right, b, c, d);
		}

		Quaternion operator*(const float& right) const {
			return Quaternion(
				a * right,
				b * right,
				c * right,
				d * right);
		}

		/*------------------------------------------------------------------------*/
		// class member functions
		float lenght() {
			return sqrtf(a * a + b * b + c * c + d * d);
		}

		/*------------------------------------------------------------------------*/
		// data
		float a;
		float b; // * i
		float c; // * j
		float d; // * k
	};

}

#endif // QUATERNION_HPP
