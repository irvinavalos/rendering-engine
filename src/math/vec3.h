#ifndef VEC3_H
#define VEC3_H

#include "quad.h"

class Vec3 : public Quad {
public:
    explicit Vec3(double x, double y, double z) noexcept;
};

Vec3 operator+(const Vec3& v1, const Vec3& v2);

Vec3 operator-(const Vec3& v1, const Vec3& v2);

Vec3 operator*(const Vec3& v, double a);

Vec3 operator*(double a, const Vec3& v);

#endif // !VEC3_H
