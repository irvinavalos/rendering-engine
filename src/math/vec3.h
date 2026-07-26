#ifndef VEC3_H
#define VEC3_H

#include "quad.h"

class Vec3 : public Quad {
public:
    explicit Vec3(double x, double y, double z) noexcept;
};

#endif // !VEC3_H
