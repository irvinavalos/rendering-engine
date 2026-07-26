#ifndef UTILS_H
#define UTILS_H

constexpr double EPS{1e-9};

[[nodiscard]] inline bool equalf(double a, double b) noexcept {
    double diff = a - b;
    return (diff < EPS) && (diff > -EPS);
}

#endif // !UTILS_H
