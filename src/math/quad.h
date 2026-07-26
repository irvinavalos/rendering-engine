#ifndef QUAD_H
#define QUAD_H

class Quad {
public:
    explicit Quad(double x, double y, double z, double w) noexcept;

    double x() const noexcept;
    double y() const noexcept;
    double z() const noexcept;
    double w() const noexcept;

    bool isPoint() const noexcept;
    bool isVector() const noexcept;

    bool operator==(const Quad&) const;

    Quad& operator+=(const Quad&);
    Quad& operator-=(const Quad&);

    Quad& operator*=(double a);
    Quad& operator/=(double a);

private:
    double m_x, m_y, m_z ,m_w;
};

Quad operator+(Quad, const Quad&);

Quad operator-(Quad, const Quad&);

Quad operator-(const Quad&);

Quad operator*(Quad, double);

Quad operator*(double, Quad);

Quad operator/(Quad, double);

#endif // !QUAD_H
