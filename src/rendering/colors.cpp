#include "utils.h"
#include "colors.h"

Color::Color()
    noexcept : m_red{0}, m_green{0}, m_blue{0} {}

Color::Color(double r, double g, double b)
    noexcept : m_red{r}, m_green{g}, m_blue{b} {}

double Color::red() const noexcept {
    return m_red;
}

double Color::green() const noexcept {
    return m_green;
}

double Color::blue() const noexcept {
    return m_blue;
}

bool Color::operator==(const Color& other) {
    return equalf(m_red, other.m_red)
        && equalf(m_green, other.m_green)
        && equalf(m_blue, other.m_blue);
}

Color& Color::operator+=(const Color& c) {
    m_red += c.m_red;
    m_green += c.m_green;
    m_blue += c.m_blue;
    return *this;
}

Color& Color::operator-=(const Color& c) {
    m_red -= c.m_red;
    m_green -= c.m_green;
    m_blue -= c.m_blue;
    return *this;
}

Color& Color::operator*=(double a) {
    m_red *= a;
    m_green *= a;
    m_blue *= a;
    return *this;
}

Color operator+(Color c1, const Color& c2) {
    return c1 += c2;
}

Color operator-(Color c1, const Color& c2) {
    return c1 -= c2;
}

Color operator*(Color c, double a) {
    return c *= a;
}

Color operator*(double a, Color c) {
    return c * a;
}

Color operator*(const Color& c1, const Color& c2) {
    return Color(c1.red() * c2.red(),
                c1.green() * c2.green(),
                c1.blue() * c2.blue());
}
