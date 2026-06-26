#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "Mat3.hpp"
#include "Mat4.hpp"


namespace LAFG {

	/*------------------------------------------------------------------------*/
	// Mat2

	// Returns rotation matrix, double precision
	template<Number T>
	inline DMat2 rotMat2(T angle) {
		double s = sin(angle);
		double c = cos(angle);
#ifdef LAFG_USE_COLUMN_LAYOUT
		return Mat2Template<double>(c, s, -s, c);
#else
		return Mat2Template<double>(c, -s, s, c);
#endif
	}

	// Returns rotation matrix, single precision
	template<Number T>
	inline Mat2 rotMat2f(T angle) {
		float s = sinf(angle);
		float c = cosf(angle);
#ifdef LAFG_USE_COLUMN_LAYOUT
		return Mat2Template<float>(c, s, -s, c);
#else
		return Mat2Template<float>(c, -s, s, c);
#endif
	}

	/*------------------------------------------------------------------------*/
	// Mat3

	/*------------------------------------------------------------------------*/
    // Mat4

    inline DMat4 scaleMat4(double s) {
        return DMat4(
            s,  0., 0., 0.,
            0., s,  0., 0.,
            0., 0., s,  0.,
            0., 0., 0., 1.);
    }

	inline Mat4 scaleMat4f(float s) {
        return Mat4(
            s,   0.f, 0.f, 0.f,
            0.f, s,   0.f, 0.f,
            0.f, 0.f, s,   0.f,
            0.f, 0.f, 0.f, 1.f);
    }

    inline DMat4 translateMat4(DVec3 dest) {
        return DMat4(
            1.,     0.,     0.,     0.,
            0.,     1.,     0.,     0.,
            0.,     0.,     1.,     0.,
            dest.x, dest.y, dest.z, 1.);
    }

    inline Mat4 translateMat4f(Vec3 dest) {
        return Mat4(
            1.f,    0.f,    0.f,    0.f,
            0.f,    1.f,    0.f,    0.f,
            0.f,    0.f,    1.f,    0.f,
            dest.x, dest.y, dest.z, 1.f);
	}

    inline DMat4 xRotateMat4(double angle) {
        double s = sin(angle);
        double c = cos(angle);
        return DMat4(
            1., 0., 0., 0.,
            0., c,  s,  0.,
            0., -s, c,  0.,
            0., 0., 0., 1.);
    }

    inline Mat4 xRotateMat4f(float angle) {
        float s = sinf(angle);
        float c = cosf(angle);
        return Mat4(
            1.f, 0.f, 0.f, 0.f,
            0.f, c,   s,   0.f,
            0.f, -s,  c,   0.f,
            0.f, 0.f, 0.f, 1.f);
    }

    inline DMat4 yRotateMat4(double angle) {
        double s = sin(angle);
        double c = cos(angle);
        return DMat4(
            c,  0., s,  0.,
            0., 1., 0., 0.,
            s,  0., c,  0.,
            0., 0., 0., 1.); 
    }

    inline Mat4 yRotateMat4f(float angle) {
        float s = sinf(angle);
        float c = cosf(angle);
        return Mat4(
            c,   0.f, s,   0.f,
            0.f, 1.f, 0.f, 0.f,
            s,   0.f, c,   0.f,
            0.f, 0.f, 0.f, 1.f); 
    }

    inline DMat4 yRotate(double angle) {
        double s = sin(angle);
        double c = cos(angle);
        return DMat4(
            c,  -s, 0., 0.,
            s,  c,  0., 0.,
            0., 0., 1., 0.,
            0., 0., 0., 1.); 
    }

    inline Mat4 zRotateMat4f(float angle) {
        float s = sinf(angle);
        float c = cosf(angle);
        return Mat4(
            c,   -s,  0.f, 0.f,
            s,   c,   0.f, 0.f,
            0.f, 0.f, 1.f, 0.f,
            0.f, 0.f, 0.f, 1.f); 
    }

    inline DMat4 rotateMat4(DVec3 axis, double angle) {
        double s = sin(angle);
        double c = cos(angle);
        return DMat4(
            c + (1. - c) * axis.x * axis.x,          (1. - c) * axis.y * axis.x + s * axis.z, (1. - c) * axis.z * axis.x - s * axis.y, 0.,
            (1. - c) * axis.x * axis.y - s * axis.z, c + (1. - c) * axis.y * axis.y,          (1. - c) * axis.z * axis.y + s * axis.x, 0.,
            (1. - c) * axis.x * axis.z + s * axis.y, (1. - c) * axis.y * axis.z - s * axis.x, c + (1. - c) * axis.z * axis.z,          0.,
            0.,                                      0.,                                      0.,                                      1.);
    }

    inline Mat4 rotateMat4f(Vec3 axis, float angle) {
        float s = sinf(angle);
        float c = cosf(angle);
        return Mat4(
            c + (1.f - c) * axis.x * axis.x,		  (1.f - c) * axis.y * axis.x + s * axis.z, (1.f - c) * axis.z * axis.x - s * axis.y, 0.f,
            (1.f - c) * axis.x * axis.y - s * axis.z, c + (1.f - c) * axis.y * axis.y,			(1.f - c) * axis.z * axis.y + s * axis.x, 0.f,
            (1.f - c) * axis.x * axis.z + s * axis.y, (1.f - c) * axis.y * axis.z - s * axis.x, c + (1.f - c) * axis.z * axis.z,		  0.f,
            0.f,									  0.f,										0.f,									  1.f);
    }

    inline DMat4 projectionMat4(double near, double far, double width, double height) {
        return DMat4(
            2. * near / width, 0.,                 0.,                              0.,
            0.,                2. * near / height, 0.,                              0.,
            0.,                0.,                 -(far + near) / (far - near),    -1.,
            0.,                0.,                 -2. * far * near / (far + near), 0.);
    }

    inline Mat4 projectionMat4f(float near, float far, float width, float height) {
        return Mat4(
            2.f * near / width, 0.f,                 0.f,                                   0.f,
            0.f,                2.f * near / height, 0.f,                                   0.f,
            0.f,                0.f,                      -(far + near) / (far - near),     -1.f,
            0.f,                0.f,                      -2.f * far * near / (far + near), 0.f);
    }

}

#endif // TRANSFORM_HPP
