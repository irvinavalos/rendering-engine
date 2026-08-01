#include "point.h"

Point::Point(double x, double y, double z) noexcept
    : Quad(x, y, z, 1.0) {}

Point operator*(const Point& v, double a) {
    Quad q{static_cast<const Quad&>(v) * a};
    return Point(q.x(), q.y(), q.z());
}

Point operator*(double a, const Point& v) {
    Quad q{static_cast<const Quad&>(v) * a};
    return Point(q.x(), q.y(), q.z());
}
