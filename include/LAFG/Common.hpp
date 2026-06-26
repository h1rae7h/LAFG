#ifndef LAFG_COMMON_HPP
#define LAFG_COMMON_HPP

#include <concepts>
#include <numbers>
#include <cassert>
#include <algorithm>


namespace LAFG {

	template<class T> concept Number = std::integral<T> || std::floating_point<T>;
	
	template<class T> concept SignedInteger =
		std::same_as<T, char> ||
		std::same_as<T, short> ||
		std::same_as<T, int> ||
		std::same_as<T, long> ||
		std::same_as<T, long long>;
	
	template<class T> concept UnsignedInteger =
		std::same_as<T, unsigned char> ||
		std::same_as<T, unsigned short> ||
		std::same_as<T, unsigned int> ||
		std::same_as<T, unsigned long> ||
		std::same_as<T, unsigned long long>;

	template<class T, class U> concept AddConvertsToFirst = requires (T a, U b) { {a + b} -> std::same_as<T>; };

	inline float toDegf(float angle) {
		return angle / std::numbers::pi_v<float> * 180.f;
	}

	inline double toDeg(double angle) {
		return angle / std::numbers::pi * 180.;
	}

	inline float toRadf(float angle) {
		return angle / 180.f * std::numbers::pi_v<float>;
	}

	inline double toRad(double angle) {
		return angle / 180. * std::numbers::pi;
	}


}

#endif // LAFG_COMMON_HPP
