#ifndef POINT_H
#define POINT_H

#include "quad.h"

class Point : public Quad {
public:
    explicit Point(double x, double y, double z) noexcept;
};

Point operator*(const Point& v, double a);

Point operator*(double a, const Point& v);

#endif // !POINT_H
