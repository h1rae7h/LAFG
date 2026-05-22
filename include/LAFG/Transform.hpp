#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "Mat3.hpp"
#include "Mat4.hpp"


namespace LAFG {

    inline Mat4 scale(float s) {
        return Mat4(
            s,   0.f, 0.f, 0.f,
            0.f, s,   0.f, 0.f,
            0.f, 0.f, s,   0.f,
            0.f, 0.f, 0.f, 1.f);
    }

    inline DMat4 scale(double s) {
        return DMat4(
            s,  0., 0., 0.,
            0., s,  0., 0.,
            0., 0., s,  0.,
            0., 0., 0., 1.);
    }

    inline Mat4 translate(Vec3 dest) {
        return Mat4(
            1.f,    0.f,    0.f,    0.f,
            0.f,    1.f,    0.f,    0.f,
            0.f,    0.f,    1.f,    0.f,
            dest.x, dest.y, dest.z, 1.f);
    }

    inline DMat4 translate(DVec3 dest) {
        return DMat4(
            1.,     0.,     0.,     0.,
            0.,     1.,     0.,     0.,
            0.,     0.,     1.,     0.,
            dest.x, dest.y, dest.z, 1.);
    }

    inline Mat4 xRotate(float angle) {
        float s = sinf(angle);
        float c = cosf(angle);
        return Mat4(
            1.f, 0.f, 0.f, 0.f,
            0.f, c,   s,   0.f,
            0.f, -s,  c,   0.f,
            0.f, 0.f, 0.f, 1.f);
    }

    inline DMat4 xRotate(double angle) {
        double s = sin(angle);
        double c = cos(angle);
        return DMat4(
            1., 0., 0., 0.,
            0., c,  s,  0.,
            0., -s, c,  0.,
            0., 0., 0., 1.);
    }

    inline Mat4 yRotate(float angle) {
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
            c,  0., s,  0.,
            0., 1., 0., 0.,
            s,  0., c,  0.,
            0., 0., 0., 1.); 
    }

    inline Mat4 zRotate(float angle) {
        float s = sinf(angle);
        float c = cosf(angle);
        return Mat4(
            c,   -s,  0.f, 0.f,
            s,   c,   0.f, 0.f,
            0.f, 0.f, 1.f, 0.f,
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

    inline Mat4 rotate(Vec3 axis, float angle) {
        float s = sinf(angle);
        float c = cosf(angle);
        return Mat4(
            c + (1.f - c) * axis.x * axis.x, (1.f - c) * axis.y * axis.x + s * axis.z, (1.f - c) * axis.z * axis.x - s * axis.y, 0.f,
            (1.f - c) * axis.x * axis.y - s * axis.z, c + (1.f - c) * axis.y * axis.y, (1.f - c) * axis.z * axis.y + s * axis.x, 0.f,
            (1.f - c) * axis.x * axis.z + s * axis.y, (1.f - c) * axis.y * axis.z - s * axis.x, c + (1.f - c) * axis.z * axis.z, 0.f,
            0.f, 0.f, 0.f, 1.f);
    }

    inline DMat4 rotate(DVec3 axis, double angle) {
        double s = sin(angle);
        double c = cos(angle);
        return DMat4(
            c + (1. - c) * axis.x * axis.x,          (1. - c) * axis.y * axis.x + s * axis.z, (1. - c) * axis.z * axis.x - s * axis.y, 0.,
            (1. - c) * axis.x * axis.y - s * axis.z, c + (1. - c) * axis.y * axis.y,          (1. - c) * axis.z * axis.y + s * axis.x, 0.,
            (1. - c) * axis.x * axis.z + s * axis.y, (1. - c) * axis.y * axis.z - s * axis.x, c + (1. - c) * axis.z * axis.z,          0.,
            0.,                                      0.,                                      0.,                                      1.);
    }


    inline Mat4 projection(float near, float far, float width, float height) {
        return Mat4(
            2.f * near / width, 0.f,                 0.f,                                   0.f,
            0.f,                2.f * near / height, 0.f,                                   0.f,
            0.f,                0.f,                      -(far + near) / (far - near),     -1.f,
            0.f,                0.f,                      -2.f * far * near / (far + near), 0.f);
    }

    inline DMat4 projection(double near, double far, double width, double height) {
        return DMat4(
            2. * near / width, 0.,                 0.,                              0.,
            0.,                2. * near / height, 0.,                              0.,
            0.,                0.,                 -(far + near) / (far - near),    -1.,
            0.,                0.,                 -2. * far * near / (far + near), 0.);
    }

}

#endif // TRANSFORM_HPP
