#ifndef POINT_H
#define POINT_H

#include "quad.h"

class Point : public Quad {
public:
    explicit Point(double x, double y, double z) noexcept;
};

#endif // !POINT_H
