#include <cmath>
#include "operations.h"

Point operator+(const Point& p, const Vec3& v) {
    Quad q{static_cast<const Quad&>(p) + static_cast<const Quad&>(v)};
    return Point(q.x(), q.y(), q.z());
}

Point operator+(const Vec3& v, const Point& p) {
    Quad q{static_cast<const Quad&>(p) + static_cast<const Quad&>(v)};
    return Point(q.x(), q.y(), q.z());
}

Vec3 operator+(const Vec3& v1, const Vec3& v2) {
    Quad q{static_cast<const Quad&>(v1) + static_cast<const Quad&>(v2)};
    return Vec3(q.x(), q.y(), q.z());
}

Vec3 operator-(const Point& p1, const Point& p2) {
    Quad q{static_cast<const Quad&>(p1) - static_cast<const Quad&>(p2)};
    return Vec3(q.x(), q.y(), q.z());
}

Point operator-(const Point& p, const Vec3& v) {
    Quad q{static_cast<const Quad&>(p) - static_cast<const Vec3&>(v)};
    return Point(q.x(), q.y(), q.z());
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

double magnitude(const Quad& q) {
    return std::sqrt(q.x() * q.x() + q.y() * q.y() + q.z() * q.z() + q.w() * q.w());
}

Vec3 normalize(Quad q) {
    q /= magnitude(q);
    return Vec3(q.x(), q.y(), q.z());
}

double dot(const Quad& a, const Quad& b) {
    return (a.x() * b.x() +
            a.y() * b.y() +
            a.z() * b.z() +
            a.w() * b.w());
}

Vec3 cross(const Quad& a, const Quad& b) {
    return Vec3(a.y() * b.z() - a.z() * b.y(),
                a.z() * b.x() - b.z() * a.x(),
                a.x() * b.y() - a.y() * b.x());
}
