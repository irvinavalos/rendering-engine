#include "vec3.h"

Vec3::Vec3(double x, double y, double z) noexcept
    : Quad(x, y, z, 0.0) {}

Vec3 operator+(const Vec3& v1, const Vec3& v2) {
    Quad q{static_cast<const Quad&>(v1) + static_cast<const Quad&>(v2)};
    return Vec3(q.x(), q.y(), q.z());
}
Vec3 operator-(const Vec3& v1, const Vec3& v2) {

    Quad q{static_cast<const Quad&>(v1) - static_cast<const Vec3&>(v2)};
    return Vec3(q.x(), q.y(), q.z());
}

Vec3 operator*(const Vec3& v, double a) {
    Quad q{static_cast<const Quad&>(v) * a};
    return Vec3(q.x(), q.y(), q.z());
}

Vec3 operator*(double a, const Vec3& v) {
    Quad q{static_cast<const Quad&>(v) * a};
    return Vec3(q.x(), q.y(), q.z());
}
