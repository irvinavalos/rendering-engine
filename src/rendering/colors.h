#ifndef COLORS_H
#define COLORS_H

class Color {
public:
    Color() noexcept;
    explicit Color(double r, double g, double b) noexcept;

    double red() const noexcept;
    double green() const noexcept;
    double blue() const noexcept;

    bool operator==(const Color&);

    Color& operator+=(const Color&);
    Color& operator-=(const Color&);
    Color& operator*=(double);

private:
    double m_red, m_green, m_blue;
};

Color operator+(Color, const Color&);

Color operator-(Color, const Color&);

Color operator*(Color, double);

Color operator*(double, Color);

Color operator*(const Color&, const Color&);

#endif // !COLORS_H
