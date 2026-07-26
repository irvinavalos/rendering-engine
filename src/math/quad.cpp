#include "quad.h"

Quad::Quad(double x, double y, double z, double w) noexcept
    : m_x(x), m_y(y), m_z(z), m_w(w) {}

double Quad::x() const noexcept {
    return m_x;
}

double Quad::y() const noexcept { 
    return m_y;
}

double Quad::z() const noexcept {
    return m_z;
}

double Quad::w() const noexcept {
    return m_w;
}

bool Quad::isPoint() const noexcept {
    return m_w == 1.0;
}

bool Quad::isVector() const noexcept {
    return m_w == 0.0;
}

bool Quad::operator==(const Quad& other) const {
    return (m_x == other.m_x)
        && (m_y == other.m_y)
        && (m_z == other.m_z)
        && (m_w == other.m_w);
}

Quad& Quad::operator+=(const Quad& other) {
    m_x += other.m_x;
    m_y += other.m_y;
    m_z += other.m_z;
    m_w += other.m_w;
    return *this;
}

Quad& Quad::operator-=(const Quad& other) {
    m_x -= other.m_x;
    m_y -= other.m_y;
    m_z -= other.m_z;
    m_w -= other.m_w;
    return *this;
}

Quad& Quad::operator*=(double a) {
    m_x *= a;
    m_y *= a;
    m_z *= a;
    m_w *= a;
    return *this;
}

Quad& Quad::operator/=(double a) {
    m_x /= a;
    m_y /= a;
    m_z /= a;
    m_w /= a;
    return *this;
}

Quad operator+(Quad q1, const Quad& q2) {
    return q1 += q2;
}

Quad operator-(Quad q1, const Quad& q2) {
    return q1 -= q2;
}

Quad operator-(const Quad& q) {
    return Quad(-q.x(), -q.y(), -q.z(), -q.w());
}

Quad operator*(Quad q, double a) {
    return q *= a;
}

Quad operator*(double a, Quad q) {
    return q * a;
}

Quad operator/(Quad q, double a) {
    return q /= a;
}
