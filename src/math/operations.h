#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "vec3.h"
#include "point.h"
#include "matrix.h"

Point operator+(const Point&, const Vec3&);

Point operator+(const Vec3&, const Point&);

Vec3 operator-(const Point&, const Point&);

Point operator-(const Point&, const Vec3&);

double magnitude(const Quad&);

Vec3 normalize(Quad);

double dot(const Quad&, const Quad&);

Vec3 cross(const Quad&, const Quad&);

#endif // !OPERATIONS_H
